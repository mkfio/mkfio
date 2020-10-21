// Copyright (c) 2019-2020 The Bigbang developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "core.h"

#include "../common/template/dexmatch.h"
#include "../common/template/dexorder.h"
#include "../common/template/exchange.h"
#include "../common/template/mint.h"
#include "../common/template/payment.h"
#include "address.h"
#include "crypto.h"
#include "wallet.h"

using namespace std;
using namespace xengine;

#define DEBUG(err, ...) Debug((err), __FUNCTION__, __VA_ARGS__)

static const int64 MAX_CLOCK_DRIFT = 80;

static const int PROOF_OF_WORK_BITS_LOWER_LIMIT = 8;
static const int PROOF_OF_WORK_BITS_UPPER_LIMIT = 200;
#ifdef BIGBANG_TESTNET
static const int PROOF_OF_WORK_BITS_INIT_MAINNET = 10;
#else
static const int PROOF_OF_WORK_BITS_INIT_MAINNET = 34;
#endif
static const int PROOF_OF_WORK_BITS_INIT_TESTNET = 10;
static const uint32 PROOF_OF_WORK_DIFFICULTY_INTERVAL_MAINNET = 10000;
static const uint32 PROOF_OF_WORK_DIFFICULTY_INTERVAL_TESTNET = 30;

static const int64 BBCP_TOKEN_INIT = 1000000000;
static const int64 BBCP_YEAR_INC_REWARD_TOKEN = 50;
static const int64 BBCP_INIT_REWARD_TOKEN = BBCP_TOKEN_INIT;

namespace bigbang
{
///////////////////////////////
// CCoreProtocol

CCoreProtocol::CCoreProtocol()
{
    nProofOfWorkLowerLimit = (~uint256(uint64(0)) >> PROOF_OF_WORK_BITS_LOWER_LIMIT);
    nProofOfWorkLowerLimit.SetCompact(nProofOfWorkLowerLimit.GetCompact());
    nProofOfWorkUpperLimit = (~uint256(uint64(0)) >> PROOF_OF_WORK_BITS_UPPER_LIMIT);
    nProofOfWorkUpperLimit.SetCompact(nProofOfWorkUpperLimit.GetCompact());
    nProofOfWorkInit = (~uint256(uint64(0)) >> PROOF_OF_WORK_BITS_INIT_MAINNET);
    nProofOfWorkDifficultyInterval = PROOF_OF_WORK_DIFFICULTY_INTERVAL_MAINNET;
    pBlockChain = nullptr;
}

CCoreProtocol::~CCoreProtocol()
{
}

bool CCoreProtocol::HandleInitialize()
{
    CBlock block;
    GetGenesisBlock(block);
    hashGenesisBlock = block.GetHash();
    if (!GetObject("blockchain", pBlockChain))
    {
        return false;
    }
    return true;
}

Errno CCoreProtocol::Debug(const Errno& err, const char* pszFunc, const char* pszFormat, ...)
{
    string strFormat(pszFunc);
    strFormat += string(", ") + string(ErrorString(err)) + string(" : ") + string(pszFormat);
    va_list ap;
    va_start(ap, pszFormat);
    VDebug(strFormat.c_str(), ap);
    va_end(ap);
    return err;
}

const uint256& CCoreProtocol::GetGenesisBlockHash()
{
    return hashGenesisBlock;
}

/*
Address : 1vszb4dxexw3bry2d2hvd87e8f964r834pr6f1xywdcp7ekcqpsmv08h3
PubKey : 69b6974d772c6bdcf7f00cb664204c4c7ac81dd476144d78bc06efae37b27ede
Secret : f19c86f39741fe57cb2e0d5b9051787a1672437678c394ee2002979f6c247411
*/

void CCoreProtocol::GetGenesisBlock(CBlock& block)
{
#ifdef BIGBANG_TESTNET
    const CDestination destOwner = CDestination(bigbang::crypto::CPubKey(uint256("69b6974d772c6bdcf7f00cb664204c4c7ac81dd476144d78bc06efae37b27ede")));
#else
    const CDestination destOwner = CAddress("20804jmmhvgdq550rwfgwfrww16mbbvqx8zzdav1mpppdzg5b30n93cjd");
#endif

    block.SetNull();

    block.nVersion = CBlock::BLOCK_VERSION;
    block.nType = CBlock::BLOCK_GENESIS;
    block.nTimeStamp = 1598943600;
    block.hashPrev = 0;

    CTransaction& tx = block.txMint;
    tx.nType = CTransaction::TX_GENESIS;
    tx.nTimeStamp = block.nTimeStamp;
    tx.sendTo = destOwner;
    tx.nAmount = BBCP_INIT_REWARD_TOKEN * COIN;

    CProfile profile;
    profile.strName = "Market Finance";
    profile.strSymbol = "MKF";
    profile.destOwner = destOwner;
    profile.nAmount = tx.nAmount;
    profile.nMintReward = BBCP_INIT_REWARD_TOKEN * COIN;
    profile.nMinTxFee = MIN_TX_FEE;
    profile.nHalveCycle = 0;
    profile.SetFlag(true, false, false);

    profile.Save(block.vchProof);
}

Errno CCoreProtocol::ValidateTransaction(const CTransaction& tx, int nHeight)
{
    if (tx.vInput.empty() && tx.nType != CTransaction::TX_GENESIS && tx.nType != CTransaction::TX_WORK)
    {
        return DEBUG(ERR_TRANSACTION_INVALID, "tx vin is empty\n");
    }
    if (!tx.vInput.empty() && (tx.nType == CTransaction::TX_GENESIS || tx.nType == CTransaction::TX_WORK))
    {
        return DEBUG(ERR_TRANSACTION_INVALID, "tx vin is not empty for genesis or work tx\n");
    }
    if (!tx.vchSig.empty() && tx.IsMintTx())
    {
        return DEBUG(ERR_TRANSACTION_INVALID, "invalid signature\n");
    }
    if (tx.sendTo.IsNull())
    {
        return DEBUG(ERR_TRANSACTION_OUTPUT_INVALID, "send to null address\n");
    }
    if (!MoneyRange(tx.nAmount))
    {
        return DEBUG(ERR_TRANSACTION_OUTPUT_INVALID, "amount overflow %ld\n", tx.nAmount);
    }

    /*if (!MoneyRange(tx.nTxFee)
        || (tx.nType != CTransaction::TX_TOKEN && tx.nTxFee != 0)
        || (tx.nType == CTransaction::TX_TOKEN
            && (tx.nTxFee < CalcMinTxFee(tx, MIN_TX_FEE))))
    {
        return DEBUG(ERR_TRANSACTION_OUTPUT_INVALID, "txfee invalid %ld", tx.nTxFee);
    }*/

    if (tx.sendTo.IsTemplate())
    {
        CTemplateId tid;
        if (!tx.sendTo.GetTemplateId(tid))
        {
            return DEBUG(ERR_TRANSACTION_OUTPUT_INVALID, "send to address invalid 1");
        }
    }

    set<CTxOutPoint> setInOutPoints;
    for (const CTxIn& txin : tx.vInput)
    {
        if (txin.prevout.IsNull() || txin.prevout.n > 1)
        {
            return DEBUG(ERR_TRANSACTION_INPUT_INVALID, "prevout invalid\n");
        }
        if (!setInOutPoints.insert(txin.prevout).second)
        {
            return DEBUG(ERR_TRANSACTION_INPUT_INVALID, "duplicate inputs\n");
        }
    }

    if (GetSerializeSize(tx) > MAX_TX_SIZE)
    {
        return DEBUG(ERR_TRANSACTION_OVERSIZE, "%u\n", GetSerializeSize(tx));
    }

    return OK;
}

Errno CCoreProtocol::ValidateBlock(const CBlock& block)
{
    // These are checks that are independent of context
    // Only allow CBlock::BLOCK_PRIMARY type in v1.0.0
    /*if (block.nType != CBlock::BLOCK_PRIMARY)
    {
        return DEBUG(ERR_BLOCK_TYPE_INVALID, "Block type error\n");
    }*/
    // Check timestamp
    if (block.GetBlockTime() > GetNetTime() + MAX_CLOCK_DRIFT)
    {
        return DEBUG(ERR_BLOCK_TIMESTAMP_OUT_OF_RANGE, "%ld\n", block.GetBlockTime());
    }

    // Validate mint tx
    if (!block.txMint.IsMintTx() || ValidateTransaction(block.txMint, block.GetBlockHeight()) != OK)
    {
        return DEBUG(ERR_BLOCK_TRANSACTIONS_INVALID, "invalid mint tx\n");
    }

    size_t nBlockSize = GetSerializeSize(block);
    if (nBlockSize > MAX_BLOCK_SIZE)
    {
        return DEBUG(ERR_BLOCK_OVERSIZE, "size overflow size=%u vtx=%u\n", nBlockSize, block.vtx.size());
    }

    if (block.nType == CBlock::BLOCK_ORIGIN && !block.vtx.empty())
    {
        return DEBUG(ERR_BLOCK_TRANSACTIONS_INVALID, "origin block vtx is not empty\n");
    }

    vector<uint256> vMerkleTree;
    if (block.hashMerkle != block.BuildMerkleTree(vMerkleTree))
    {
        return DEBUG(ERR_BLOCK_TXHASH_MISMATCH, "tx merkeroot mismatched\n");
    }

    set<uint256> setTx;
    setTx.insert(vMerkleTree.begin(), vMerkleTree.begin() + block.vtx.size());
    if (setTx.size() != block.vtx.size())
    {
        return DEBUG(ERR_BLOCK_DUPLICATED_TRANSACTION, "duplicate tx\n");
    }

    for (const CTransaction& tx : block.vtx)
    {
        if (tx.IsMintTx() || ValidateTransaction(tx, block.GetBlockHeight()) != OK)
        {
            return DEBUG(ERR_BLOCK_TRANSACTIONS_INVALID, "invalid tx %s\n", tx.GetHash().GetHex().c_str());
        }
    }

    if (!CheckBlockSignature(block))
    {
        return DEBUG(ERR_BLOCK_SIGNATURE_INVALID, "\n");
    }
    return OK;
}

Errno CCoreProtocol::ValidateOrigin(const CBlock& block, const CProfile& parentProfile, CProfile& forkProfile)
{
    if (!forkProfile.Load(block.vchProof))
    {
        return DEBUG(ERR_BLOCK_INVALID_FORK, "load profile error\n");
    }
    if (forkProfile.IsNull())
    {
        return DEBUG(ERR_BLOCK_INVALID_FORK, "invalid profile");
    }
    if (!MoneyRange(forkProfile.nAmount))
    {
        return DEBUG(ERR_BLOCK_INVALID_FORK, "invalid fork amount");
    }
    if (!RewardRange(forkProfile.nMintReward))
    {
        return DEBUG(ERR_BLOCK_INVALID_FORK, "invalid fork reward");
    }
    if (parentProfile.IsPrivate())
    {
        if (!forkProfile.IsPrivate() || parentProfile.destOwner != forkProfile.destOwner)
        {
            return DEBUG(ERR_BLOCK_INVALID_FORK, "permission denied");
        }
    }
    return OK;
}

Errno CCoreProtocol::VerifyProofOfWork(const CBlock& block, const CBlockIndex* pIndexPrev)
{
    if (block.vchProof.size() < CProofOfHashWorkCompact::PROOFHASHWORK_SIZE)
    {
        return DEBUG(ERR_BLOCK_PROOF_OF_WORK_INVALID, "vchProof size error.");
    }

    if (block.GetBlockTime() < pIndexPrev->GetBlockTime())
    {
        return DEBUG(ERR_BLOCK_TIMESTAMP_OUT_OF_RANGE, "Timestamp out of range 1, height: %d, block time: %d, prev time: %d, block: %s.",
                     block.GetBlockHeight(), block.GetBlockTime(),
                     pIndexPrev->GetBlockTime(), block.GetHash().GetHex().c_str());
    }

    CProofOfHashWorkCompact proof;
    proof.Load(block.vchProof);

    uint32 nBits = 0;
    int64 nReward = 0;
    uint8 nAlgo = 0;
    if (!GetProofOfWorkTarget(pIndexPrev, nAlgo, nBits, nReward))
    {
        return DEBUG(ERR_BLOCK_PROOF_OF_WORK_INVALID, "get target fail.");
    }

    if (nBits != proof.nBits)
    {
        return DEBUG(ERR_BLOCK_PROOF_OF_WORK_INVALID, "algo or bits error, nAlgo: %d, nBits: %d, vchProof size: %ld.", nAlgo, proof.nBits, block.vchProof.size());
    }

    bool fNegative;
    bool fOverflow;
    uint256 hashTarget;
    hashTarget.SetCompact(nBits, &fNegative, &fOverflow);

    if (fNegative || hashTarget == 0 || fOverflow || hashTarget < nProofOfWorkUpperLimit || hashTarget > nProofOfWorkLowerLimit)
    {
        return DEBUG(ERR_BLOCK_PROOF_OF_WORK_INVALID, "nBits error, nBits: %u, hashTarget: %s, negative: %d, overflow: %d, upper: %s, lower: %s",
                     nBits, hashTarget.ToString().c_str(), fNegative, fOverflow, nProofOfWorkUpperLimit.ToString().c_str(), nProofOfWorkLowerLimit.ToString().c_str());
    }

    vector<unsigned char> vchProofOfWork;
    block.GetSerializedProofOfWorkData(vchProofOfWork);
    uint256 hash = crypto::CryptoPowHash(&vchProofOfWork[0], vchProofOfWork.size());
    if (hash > hashTarget)
    {
        return DEBUG(ERR_BLOCK_PROOF_OF_WORK_INVALID, "hash error: proof[%s] vs. target[%s] with bits[%d]",
                     hash.ToString().c_str(), hashTarget.ToString().c_str(), nBits);
    }

    return OK;
}

Errno CCoreProtocol::VerifyBlockTx(const CTransaction& tx, const CTxContxt& txContxt, CBlockIndex* pIndexPrev, int nForkHeight, const uint256& fork)
{
    const CDestination& destIn = txContxt.destIn;
    int64 nValueIn = 0;
    for (const CTxInContxt& inctxt : txContxt.vin)
    {
        if (inctxt.nTxTime > tx.nTimeStamp)
        {
            return DEBUG(ERR_TRANSACTION_INPUT_INVALID, "tx time is ahead of input tx\n");
        }
        if (inctxt.IsLocked(pIndexPrev->GetBlockHeight()))
        {
            return DEBUG(ERR_TRANSACTION_INPUT_INVALID, "input is still locked\n");
        }
        nValueIn += inctxt.nAmount;
    }

    if (!MoneyRange(nValueIn))
    {
        return DEBUG(ERR_TRANSACTION_INPUT_INVALID, "valuein invalid %ld\n", nValueIn);
    }
    if (!MoneyRange(tx.nTxFee)
        || (tx.nType != CTransaction::TX_TOKEN && tx.nTxFee != 0)
        || (tx.nType == CTransaction::TX_TOKEN
            && (tx.nTxFee < CalcMinTxFee(tx, nForkHeight, MIN_TX_FEE))))
    {
        return DEBUG(ERR_TRANSACTION_OUTPUT_INVALID, "txfee invalid %ld", tx.nTxFee);
    }
    if (nValueIn < tx.nAmount + tx.nTxFee)
    {
        return DEBUG(ERR_TRANSACTION_INPUT_INVALID, "valuein is not enough (%ld : %ld)\n", nValueIn, tx.nAmount + tx.nTxFee);
    }

    if (destIn.IsTemplate())
    {
        switch (destIn.GetTemplateId().GetType())
        {
        case TEMPLATE_DEXORDER:
        {
            Errno err = VerifyDexOrderTx(tx, destIn, nValueIn, nForkHeight);
            if (err != OK)
            {
                return DEBUG(err, "invalid dex order tx");
            }
            break;
        }
        case TEMPLATE_DEXMATCH:
        {
            Errno err = VerifyDexMatchTx(tx, nValueIn, nForkHeight);
            if (err != OK)
            {
                return DEBUG(err, "invalid dex match tx");
            }
            break;
        }
        }
    }

    vector<uint8> vchSig;
    if (!CTemplate::VerifyDestRecorded(tx, vchSig))
    {
        return DEBUG(ERR_TRANSACTION_SIGNATURE_INVALID, "invalid recoreded destination");
    }

    if (destIn.IsTemplate() && destIn.GetTemplateId().GetType() == TEMPLATE_PAYMENT)
    {
        auto templatePtr = CTemplate::CreateTemplatePtr(TEMPLATE_PAYMENT, vchSig);
        if (templatePtr == nullptr)
        {
            return DEBUG(ERR_TRANSACTION_SIGNATURE_INVALID, "invalid signature vchSig err\n");
        }
        auto payment = boost::dynamic_pointer_cast<CTemplatePayment>(templatePtr);
        if (nForkHeight >= (payment->m_height_exec + payment->SafeHeight))
        {
            return DEBUG(ERR_TRANSACTION_SIGNATURE_INVALID, "invalid signature\n");
        }
        else
        {
            return DEBUG(ERR_TRANSACTION_SIGNATURE_INVALID, "invalid signature\n");
        }
    }

    if (!destIn.VerifyTxSignature(tx.GetSignatureHash(), tx.nType, /*tx.hashAnchor*/ GetGenesisBlockHash(), tx.sendTo, vchSig, nForkHeight, fork))
    {
        return DEBUG(ERR_TRANSACTION_SIGNATURE_INVALID, "invalid signature\n");
    }

    return OK;
}

Errno CCoreProtocol::VerifyTransaction(const CTransaction& tx, const vector<CTxOut>& vPrevOutput,
                                       int nForkHeight, const uint256& fork)
{
    CDestination destIn = vPrevOutput[0].destTo;
    int64 nValueIn = 0;
    for (const CTxOut& output : vPrevOutput)
    {
        if (destIn != output.destTo)
        {
            return DEBUG(ERR_TRANSACTION_INPUT_INVALID, "input destination mismatched\n");
        }
        if (output.nTxTime > tx.nTimeStamp)
        {
            return DEBUG(ERR_TRANSACTION_INPUT_INVALID, "tx time is ahead of input tx\n");
        }
        if (output.IsLocked(nForkHeight))
        {
            return DEBUG(ERR_TRANSACTION_INPUT_INVALID, "input is still locked\n");
        }
        nValueIn += output.nAmount;
    }
    if (!MoneyRange(nValueIn))
    {
        return DEBUG(ERR_TRANSACTION_INPUT_INVALID, "valuein invalid %ld\n", nValueIn);
    }
    if (!MoneyRange(tx.nTxFee)
        || (tx.nType != CTransaction::TX_TOKEN && tx.nTxFee != 0)
        || (tx.nType == CTransaction::TX_TOKEN
            && (tx.nTxFee < CalcMinTxFee(tx, nForkHeight + 1, MIN_TX_FEE))))
    {
        return DEBUG(ERR_TRANSACTION_OUTPUT_INVALID, "txfee invalid %ld", tx.nTxFee);
    }
    if (nValueIn < tx.nAmount + tx.nTxFee)
    {
        return DEBUG(ERR_TRANSACTION_INPUT_INVALID, "valuein is not enough (%ld : %ld)\n", nValueIn, tx.nAmount + tx.nTxFee);
    }

    if (destIn.IsTemplate())
    {
        switch (destIn.GetTemplateId().GetType())
        {
        case TEMPLATE_DEXORDER:
        {
            Errno err = VerifyDexOrderTx(tx, destIn, nValueIn, nForkHeight + 1);
            if (err != OK)
            {
                return DEBUG(err, "invalid dex order tx");
            }
            break;
        }
        case TEMPLATE_DEXMATCH:
        {
            Errno err = VerifyDexMatchTx(tx, nValueIn, nForkHeight + 1);
            if (err != OK)
            {
                return DEBUG(err, "invalid dex match tx");
            }
            break;
        }
        }
    }

    // record destIn in vchSig
    vector<uint8> vchSig;
    if (!CTemplate::VerifyDestRecorded(tx, vchSig))
    {
        return DEBUG(ERR_TRANSACTION_SIGNATURE_INVALID, "invalid recoreded destination");
    }

    if (!destIn.VerifyTxSignature(tx.GetSignatureHash(), tx.nType, /*tx.hashAnchor*/ GetGenesisBlockHash(), tx.sendTo, vchSig, nForkHeight, fork))
    {
        return DEBUG(ERR_TRANSACTION_SIGNATURE_INVALID, "invalid signature\n");
    }

    if (destIn.IsTemplate() && destIn.GetTemplateId().GetType() == TEMPLATE_PAYMENT)
    {
        auto templatePtr = CTemplate::CreateTemplatePtr(TEMPLATE_PAYMENT, vchSig);
        if (templatePtr == nullptr)
        {
            return DEBUG(ERR_TRANSACTION_SIGNATURE_INVALID, "invalid signature vchSig err\n");
        }
        auto payment = boost::dynamic_pointer_cast<CTemplatePayment>(templatePtr);
        if (nForkHeight >= (payment->m_height_exec + payment->SafeHeight))
        {
            CBlock block;
            std::multimap<int64, CDestination> mapVotes;
            CProofOfSecretShare dpos;
            // if (!pBlockChain->ListDelegatePayment(payment->m_height_exec, block, mapVotes) || !dpos.Load(block.vchProof))
            // {
            //     return DEBUG(ERR_TRANSACTION_SIGNATURE_INVALID, "invalid signature vote err\n");
            // }
            if (!payment->VerifyTransaction(tx, nForkHeight, mapVotes, dpos.nAgreement, nValueIn))
            {
                return DEBUG(ERR_TRANSACTION_SIGNATURE_INVALID, "invalid signature\n");
            }
        }
        else
        {
            return DEBUG(ERR_TRANSACTION_SIGNATURE_INVALID, "invalid signature\n");
        }
    }

    return OK;
}

bool CCoreProtocol::GetBlockTrust(const CBlock& block, uint256& nChainTrust)
{
    if (!block.IsPrimary())
    {
        StdError("CCoreProtocol", "GetBlockTrust: block type error");
        return false;
    }

    if (!block.IsProofOfWork())
    {
        StdError("CCoreProtocol", "GetBlockTrust: IsProofOfWork fail");
        return false;
    }

    CProofOfHashWorkCompact proof;
    proof.Load(block.vchProof);
    uint256 nTarget;
    nTarget.SetCompact(proof.nBits);
    // nChainTrust = 2**256 / (nTarget+1) = ~nTarget / (nTarget+1) + 1
    nChainTrust = (~nTarget / (nTarget + 1)) + 1;
    return true;
}

bool CCoreProtocol::GetProofOfWorkTarget(const CBlockIndex* pIndexPrev, int nAlgo, uint32_t& nBits, int64& nReward)
{
    nReward = GetPrimaryMintWorkReward(pIndexPrev);

    if (pIndexPrev->GetBlockHeight() == 0)
    {
        nBits = nProofOfWorkInit.GetCompact();
    }
    else if ((pIndexPrev->nHeight + 1) % nProofOfWorkDifficultyInterval != 0)
    {
        nBits = pIndexPrev->nProofBits;
    }
    else
    {
        // statistic the sum of nProofOfWorkDifficultyInterval blocks time
        const CBlockIndex* pIndexFirst = pIndexPrev;
        for (int i = 1; i < nProofOfWorkDifficultyInterval && pIndexFirst; i++)
        {
            pIndexFirst = pIndexFirst->pPrev;
        }

        if (!pIndexFirst || pIndexFirst->GetBlockHeight() != (pIndexPrev->GetBlockHeight() - (nProofOfWorkDifficultyInterval - 1)))
        {
            StdError("CCoreProtocol", "GetProofOfWorkTarget: first block of difficulty interval height is error");
            return false;
        }

        if (pIndexPrev == pIndexFirst)
        {
            StdError("CCoreProtocol", "GetProofOfWorkTarget: difficulty interval must be large than 1");
            return false;
        }

        // Limit adjustment step
        if (pIndexPrev->GetBlockTime() < pIndexFirst->GetBlockTime())
        {
            StdError("CCoreProtocol", "GetProofOfWorkTarget: prev block time [%ld] < first block time [%ld]", pIndexPrev->GetBlockTime(), pIndexFirst->GetBlockTime());
            return false;
        }
        uint64 nActualTimespan = pIndexPrev->GetBlockTime() - pIndexFirst->GetBlockTime();
        uint64 nTargetTimespan = (uint64)nProofOfWorkDifficultyInterval * BLOCK_TARGET_SPACING;
        if (nActualTimespan < nTargetTimespan / 4)
        {
            nActualTimespan = nTargetTimespan / 4;
        }
        if (nActualTimespan > nTargetTimespan * 4)
        {
            nActualTimespan = nTargetTimespan * 4;
        }

        uint256 newBits;
        newBits.SetCompact(pIndexPrev->nProofBits);
        // StdLog("CCoreProtocol", "newBits *= nActualTimespan, newBits: %s, nActualTimespan: %lu", newBits.ToString().c_str(), nActualTimespan);
        //newBits /= uint256(nTargetTimespan);
        // StdLog("CCoreProtocol", "newBits: %s", newBits.ToString().c_str());
        //newBits *= nActualTimespan;
        // StdLog("CCoreProtocol", "newBits /= nTargetTimespan, newBits: %s, nTargetTimespan: %lu", newBits.ToString().c_str(), nTargetTimespan);
        if (newBits >= uint256(nTargetTimespan))
        {
            newBits /= uint256(nTargetTimespan);
            newBits *= nActualTimespan;
        }
        else
        {
            newBits *= nActualTimespan;
            newBits /= uint256(nTargetTimespan);
        }
        if (newBits < nProofOfWorkUpperLimit)
        {
            newBits = nProofOfWorkUpperLimit;
        }
        if (newBits > nProofOfWorkLowerLimit)
        {
            newBits = nProofOfWorkLowerLimit;
        }
        nBits = newBits.GetCompact();
        // StdLog("CCoreProtocol", "newBits.GetCompact(), newBits: %s, nBits: %x", newBits.ToString().c_str(), nBits);
    }

    return true;
}

int64 CCoreProtocol::GetPrimaryMintWorkReward(const CBlockIndex* pIndexPrev)
{
    return BBCP_YEAR_INC_REWARD_TOKEN * COIN;
}

bool CCoreProtocol::CheckBlockSignature(const CBlock& block)
{
    if (block.GetHash() != GetGenesisBlockHash())
    {
        return block.txMint.sendTo.VerifyBlockSignature(block.GetHash(), block.vchSig);
    }
    return true;
}

Errno CCoreProtocol::VerifyDexOrderTx(const CTransaction& tx, const CDestination& destIn, int64 nValueIn, int nHeight)
{
    uint16 nSendToTemplateType = 0;
    if (tx.sendTo.IsTemplate())
    {
        nSendToTemplateType = tx.sendTo.GetTemplateId().GetType();
    }

    vector<uint8> vchSig;
    if (!CTemplate::VerifyDestRecorded(tx, vchSig))
    {
        return ERR_TRANSACTION_SIGNATURE_INVALID;
    }

    auto ptrOrder = CTemplate::CreateTemplatePtr(TEMPLATE_DEXORDER, vchSig);
    if (ptrOrder == nullptr)
    {
        Log("Verify dexorder tx: Create order template fail, tx: %s", tx.GetHash().GetHex().c_str());
        return ERR_TRANSACTION_SIGNATURE_INVALID;
    }
    auto objOrder = boost::dynamic_pointer_cast<CTemplateDexOrder>(ptrOrder);
    if (nSendToTemplateType == TEMPLATE_DEXMATCH)
    {
        CTemplatePtr ptrMatch = CTemplate::CreateTemplatePtr(nSendToTemplateType, tx.vchSig);
        if (!ptrMatch)
        {
            Log("Verify dexorder tx: Create match template fail, tx: %s", tx.GetHash().GetHex().c_str());
            return ERR_TRANSACTION_SIGNATURE_INVALID;
        }
        auto objMatch = boost::dynamic_pointer_cast<CTemplateDexMatch>(ptrMatch);

        set<CDestination> setSubDest;
        vector<uint8> vchSubSig;
        if (!objOrder->GetSignDestination(tx, uint256(), nHeight, tx.vchSig, setSubDest, vchSubSig))
        {
            Log("Verify dexorder tx: GetSignDestination fail, tx: %s", tx.GetHash().GetHex().c_str());
            return ERR_TRANSACTION_SIGNATURE_INVALID;
        }
        if (setSubDest.empty() || objMatch->destMatch != *setSubDest.begin())
        {
            Log("Verify dexorder tx: destMatch error, tx: %s", tx.GetHash().GetHex().c_str());
            return ERR_TRANSACTION_SIGNATURE_INVALID;
        }

        if (objMatch->destSellerOrder != destIn)
        {
            Log("Verify dexorder tx: destSellerOrder error, tx: %s", tx.GetHash().GetHex().c_str());
            return ERR_TRANSACTION_SIGNATURE_INVALID;
        }
        if (objMatch->destSeller != objOrder->destSeller)
        {
            Log("Verify dexorder tx: destSeller error, tx: %s", tx.GetHash().GetHex().c_str());
            return ERR_TRANSACTION_SIGNATURE_INVALID;
        }
        /*if (objMatch->nSellerValidHeight != objOrder->nValidHeight)
        {
            Log("Verify dexorder tx: nSellerValidHeight error, match nSellerValidHeight: %d, order nValidHeight: %d, tx: %s",
                objMatch->nSellerValidHeight, objOrder->nValidHeight, tx.GetHash().GetHex().c_str());
            return ERR_TRANSACTION_SIGNATURE_INVALID;
        }*/
        if ((tx.nAmount != objMatch->nMatchAmount) || (tx.nAmount < (TNS_DEX_MIN_TX_FEE * 3 + TNS_DEX_MIN_MATCH_AMOUNT)))
        {
            Log("Verify dexorder tx: nAmount error, match nMatchAmount: %lu, tx amount: %lu, tx: %s",
                objMatch->nMatchAmount, tx.nAmount, tx.GetHash().GetHex().c_str());
            return ERR_TRANSACTION_SIGNATURE_INVALID;
        }
        if (objMatch->nFee != objOrder->nFee)
        {
            Log("Verify dexorder tx: nFee error, match fee: %ld, order fee: %ld, tx: %s",
                objMatch->nFee, objMatch->nFee, tx.GetHash().GetHex().c_str());
            return ERR_TRANSACTION_SIGNATURE_INVALID;
        }
    }
    return OK;
}

Errno CCoreProtocol::VerifyDexMatchTx(const CTransaction& tx, int64 nValueIn, int nHeight)
{
    vector<uint8> vchSig;
    if (!CTemplate::VerifyDestRecorded(tx, vchSig))
    {
        return ERR_TRANSACTION_SIGNATURE_INVALID;
    }

    auto ptrMatch = CTemplate::CreateTemplatePtr(TEMPLATE_DEXMATCH, vchSig);
    if (ptrMatch == nullptr)
    {
        Log("Verify dex match tx: Create match template fail, tx: %s", tx.GetHash().GetHex().c_str());
        return ERR_TRANSACTION_SIGNATURE_INVALID;
    }
    auto objMatch = boost::dynamic_pointer_cast<CTemplateDexMatch>(ptrMatch);
    if (nHeight <= objMatch->nSellerValidHeight)
    {
        if (tx.sendTo == objMatch->destBuyer)
        {
            int64 nBuyerAmount = ((uint64)(objMatch->nMatchAmount - TNS_DEX_MIN_TX_FEE * 3) * (FEE_PRECISION - objMatch->nFee)) / FEE_PRECISION;
            if (nValueIn != objMatch->nMatchAmount)
            {
                Log("Verify dex match tx: Send buyer nValueIn error, nValueIn: %lu, nMatchAmount: %lu, tx: %s",
                    nValueIn, objMatch->nMatchAmount, tx.GetHash().GetHex().c_str());
                return ERR_TRANSACTION_SIGNATURE_INVALID;
            }
            if (tx.nAmount != nBuyerAmount)
            {
                Log("Verify dex match tx: Send buyer tx nAmount error, nAmount: %lu, need amount: %lu, nMatchAmount: %lu, nFee: %ld, nTxFee: %lu, tx: %s",
                    tx.nAmount, nBuyerAmount, objMatch->nMatchAmount, objMatch->nFee, tx.nTxFee, tx.GetHash().GetHex().c_str());
                return ERR_TRANSACTION_SIGNATURE_INVALID;
            }
            if (tx.nTxFee != TNS_DEX_MIN_TX_FEE)
            {
                Log("Verify dex match tx: Send buyer tx nTxFee error, nAmount: %lu, need amount: %lu, nMatchAmount: %lu, nFee: %ld, nTxFee: %lu, tx: %s",
                    tx.nAmount, nBuyerAmount, objMatch->nMatchAmount, objMatch->nFee, tx.nTxFee, tx.GetHash().GetHex().c_str());
                return ERR_TRANSACTION_SIGNATURE_INVALID;
            }
        }
        else if (tx.sendTo == objMatch->destMatch)
        {
            int64 nBuyerAmount = ((uint64)(objMatch->nMatchAmount - TNS_DEX_MIN_TX_FEE * 3) * (FEE_PRECISION - objMatch->nFee)) / FEE_PRECISION;
            int64 nRewardAmount = ((uint64)(objMatch->nMatchAmount - TNS_DEX_MIN_TX_FEE * 3) * (objMatch->nFee / 2)) / FEE_PRECISION;
            if (nValueIn != (objMatch->nMatchAmount - nBuyerAmount - TNS_DEX_MIN_TX_FEE))
            {
                Log("Verify dex match tx: Send match nValueIn error, nValueIn: %lu, need amount: %lu, nMatchAmount: %lu, nFee: %ld, nTxFee: %lu, tx: %s",
                    nValueIn, objMatch->nMatchAmount - nBuyerAmount, objMatch->nMatchAmount, objMatch->nFee, tx.nTxFee, tx.GetHash().GetHex().c_str());
                return ERR_TRANSACTION_SIGNATURE_INVALID;
            }
            if (tx.nAmount != nRewardAmount)
            {
                Log("Verify dex match tx: Send match tx nAmount error, nAmount: %lu, need amount: %lu, nMatchAmount: %lu, nRewardAmount: %lu, nFee: %ld, nTxFee: %lu, tx: %s",
                    tx.nAmount, nRewardAmount, objMatch->nMatchAmount, nRewardAmount, objMatch->nFee, tx.nTxFee, tx.GetHash().GetHex().c_str());
                return ERR_TRANSACTION_SIGNATURE_INVALID;
            }
            if (tx.nTxFee != TNS_DEX_MIN_TX_FEE)
            {
                Log("Verify dex match tx: Send match tx nTxFee error, nAmount: %lu, need amount: %lu, nMatchAmount: %lu, nRewardAmount: %lu, nFee: %ld, nTxFee: %lu, tx: %s",
                    tx.nAmount, nRewardAmount, objMatch->nMatchAmount, nRewardAmount, objMatch->nFee, tx.nTxFee, tx.GetHash().GetHex().c_str());
                return ERR_TRANSACTION_SIGNATURE_INVALID;
            }
        }
        else
        {
            set<CDestination> setSubDest;
            vector<uint8> vchSubSig;
            if (!objMatch->GetSignDestination(tx, uint256(), nHeight, tx.vchSig, setSubDest, vchSubSig))
            {
                Log("Verify dex match tx: GetSignDestination fail, tx: %s", tx.GetHash().GetHex().c_str());
                return ERR_TRANSACTION_SIGNATURE_INVALID;
            }
            if (tx.sendTo == *setSubDest.begin())
            {
                int64 nBuyerAmount = ((uint64)(objMatch->nMatchAmount - TNS_DEX_MIN_TX_FEE * 3) * (FEE_PRECISION - objMatch->nFee)) / FEE_PRECISION;
                int64 nRewardAmount = ((uint64)(objMatch->nMatchAmount - TNS_DEX_MIN_TX_FEE * 3) * (objMatch->nFee / 2)) / FEE_PRECISION;
                if (nValueIn != (objMatch->nMatchAmount - nBuyerAmount - nRewardAmount - TNS_DEX_MIN_TX_FEE * 2))
                {
                    Log("Verify dex match tx: Send deal nValueIn error, nValueIn: %lu, need amount: %lu, nMatchAmount: %lu, nRewardAmount: %lu, nFee: %ld, nTxFee: %lu, tx: %s",
                        nValueIn, objMatch->nMatchAmount - nBuyerAmount - nRewardAmount, objMatch->nMatchAmount, nRewardAmount, objMatch->nFee, tx.nTxFee, tx.GetHash().GetHex().c_str());
                    return ERR_TRANSACTION_SIGNATURE_INVALID;
                }
                if (tx.nAmount != (nValueIn - TNS_DEX_MIN_TX_FEE))
                {
                    Log("Verify dex match tx: Send deal tx nAmount error, nAmount: %lu, need amount: %lu, nMatchAmount: %lu, nRewardAmount: %lu, nFee: %ld, nTxFee: %lu, tx: %s",
                        tx.nAmount, nValueIn - TNS_DEX_MIN_TX_FEE, objMatch->nMatchAmount, nRewardAmount, objMatch->nFee, tx.nTxFee, tx.GetHash().GetHex().c_str());
                    return ERR_TRANSACTION_SIGNATURE_INVALID;
                }
                if (tx.nTxFee != TNS_DEX_MIN_TX_FEE)
                {
                    Log("Verify dex match tx: Send deal tx nTxFee error, nAmount: %lu, need amount: %lu, nMatchAmount: %lu, nRewardAmount: %lu, nFee: %ld, nTxFee: %lu, tx: %s",
                        tx.nAmount, nValueIn - TNS_DEX_MIN_TX_FEE, objMatch->nMatchAmount, nRewardAmount, objMatch->nFee, tx.nTxFee, tx.GetHash().GetHex().c_str());
                    return ERR_TRANSACTION_SIGNATURE_INVALID;
                }
            }
            else
            {
                Log("Verify dex match tx: sendTo error, tx: %s", tx.GetHash().GetHex().c_str());
                return ERR_TRANSACTION_SIGNATURE_INVALID;
            }
        }

        set<CDestination> setSubDest;
        vector<uint8> vchSigOut;
        if (!ptrMatch->GetSignDestination(tx, uint256(), 0, vchSig, setSubDest, vchSigOut))
        {
            Log("Verify dex match tx: get sign data fail, tx: %s", tx.GetHash().GetHex().c_str());
            return ERR_TRANSACTION_SIGNATURE_INVALID;
        }

        vector<uint8> vms;
        vector<uint8> vss;
        vector<uint8> vchSigSub;
        try
        {
            vector<uint8> head;
            xengine::CIDataStream is(vchSigOut);
            is >> vms >> vss >> vchSigSub;
        }
        catch (std::exception& e)
        {
            Log("Verify dex match tx: get vms and vss fail, tx: %s", tx.GetHash().GetHex().c_str());
            return ERR_TRANSACTION_SIGNATURE_INVALID;
        }

        if (crypto::CryptoSHA256(&(vss[0]), vss.size()) != objMatch->hashBuyerSecret)
        {
            Log("Verify dex match tx: hashBuyerSecret error, vss: %s, secret: %s, tx: %s",
                ToHexString(vss).c_str(), objMatch->hashBuyerSecret.GetHex().c_str(), tx.GetHash().GetHex().c_str());
            return ERR_TRANSACTION_SIGNATURE_INVALID;
        }
    }
    return OK;
}

///////////////////////////////
// CTestNetCoreProtocol

CTestNetCoreProtocol::CTestNetCoreProtocol()
{
    nProofOfWorkInit = (~uint256(uint64(0)) >> PROOF_OF_WORK_BITS_INIT_TESTNET);
    nProofOfWorkDifficultyInterval = PROOF_OF_WORK_DIFFICULTY_INTERVAL_TESTNET;
}

/*

PubKey : 68e4dca5989876ca64f16537e82d05c103e5695dfaf009a01632cb33639cc530
Secret : ab14e1de9a0e805df0c79d50e1b065304814a247e7d52fc51fd0782e0eec27d6

PubKey : 310be18f947a56f92541adbad67374facad61ab814c53fa5541488bea62fb47d
Secret : 14e1abd0802f7065b55f5076d0d2cfbea159abd540a977e8d3afd4b3061bf47f

Secret1="f1547396c4ec9f50a646b6ac791ee11f0493adc04940289752c2dc0494e040f5"
PubKey1="579792c544d6a6c198498250c1fa1467a5e5eeb59435a6cdeb06085fb8c7b091"

Secret2="43368761015b9de09dce66826188a22d1cb9d98a2b6e599c56bc384f839d67ff"
PubKey2="6d9657d15cb91e074f98fdcbbcf311325beb1d8c2c0f6d65d8362c15c213a2f1"

Secret3="be590f4db119efcff0247e5e08c7e840454b948e7a5c2993f84c12db9770fd8a"
PubKey3="efd6b29ad69ea477c4f0ac859cdd00039b83c5b074c8b2f4f9038a781b9d63d5"

addnewtemplate multisig '{"required": 2, "pubkeys": ["579792c544d6a6c198498250c1fa1467a5e5eeb59435a6cdeb06085fb8c7b091", "6d9657d15cb91e074f98fdcbbcf311325beb1d8c2c0f6d65d8362c15c213a2f1", "efd6b29ad69ea477c4f0ac859cdd00039b83c5b074c8b2f4f9038a781b9d63d5"]}'
2080fczk6yq3e44t7dpgbtef7zwfkc96b4670yj3wyvex5pv898hc6yr5

sendfrom 2080fczk6yq3e44t7dpgbtef7zwfkc96b4670yj3wyvex5pv898hc6yr5 1965p604xzdrffvg90ax9bk0q3xyqn5zz2vc9zpbe3wdswzazj7d144mm 6000 1
*/
void CTestNetCoreProtocol::GetGenesisBlock(CBlock& block)
{
    using namespace boost::posix_time;
    using namespace boost::gregorian;

    const CDestination destOwner = CAddress("2080fczk6yq3e44t7dpgbtef7zwfkc96b4670yj3wyvex5pv898hc6yr5");

    block.SetNull();

    block.nVersion = CBlock::BLOCK_VERSION;
    block.nType = CBlock::BLOCK_GENESIS;
    block.nTimeStamp = 1598943600;
    block.hashPrev = 0;

    CTransaction& tx = block.txMint;
    tx.nType = CTransaction::TX_GENESIS;
    tx.nTimeStamp = block.nTimeStamp;
    tx.sendTo = destOwner;
    tx.nAmount = BBCP_INIT_REWARD_TOKEN * COIN; // initial number of token

    CProfile profile;
    profile.strName = "Market Finance Test";
    profile.strSymbol = "MKFTest";
    profile.destOwner = destOwner;
    profile.nAmount = tx.nAmount;
    profile.nMintReward = BBCP_INIT_REWARD_TOKEN * COIN;
    profile.nMinTxFee = MIN_TX_FEE;
    profile.nHalveCycle = 0;
    profile.SetFlag(true, false, false);

    profile.Save(block.vchProof);
}

///////////////////////////////
// CProofOfWorkParam

CProofOfWorkParam::CProofOfWorkParam(bool fTestnet)
{
    if (fTestnet)
    {
        CBlock block;
        CTestNetCoreProtocol core;
        core.GetGenesisBlock(block);
        hashGenesisBlock = block.GetHash();
    }
    else
    {
        CBlock block;
        CCoreProtocol core;
        core.GetGenesisBlock(block);
        hashGenesisBlock = block.GetHash();
    }

    nProofOfWorkLowerLimit = (~uint256(uint64(0)) >> PROOF_OF_WORK_BITS_LOWER_LIMIT);
    nProofOfWorkLowerLimit.SetCompact(nProofOfWorkLowerLimit.GetCompact());
    nProofOfWorkUpperLimit = (~uint256(uint64(0)) >> PROOF_OF_WORK_BITS_UPPER_LIMIT);
    nProofOfWorkUpperLimit.SetCompact(nProofOfWorkUpperLimit.GetCompact());
    if (fTestnet)
    {
        nProofOfWorkInit = (~uint256(uint64(0)) >> PROOF_OF_WORK_BITS_INIT_TESTNET);
        nProofOfWorkDifficultyInterval = PROOF_OF_WORK_DIFFICULTY_INTERVAL_TESTNET;
    }
    else
    {
        nProofOfWorkInit = (~uint256(uint64(0)) >> PROOF_OF_WORK_BITS_INIT_MAINNET);
        nProofOfWorkDifficultyInterval = PROOF_OF_WORK_DIFFICULTY_INTERVAL_MAINNET;
    }
}

bool CProofOfWorkParam::IsDposHeight(int height)
{
    return false;
}

} // namespace bigbang
