// Copyright (c) 2019-2020 The Bigbang developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef STORAGE_CHECKREPAIR_H
#define STORAGE_CHECKREPAIR_H

#include "address.h"
#include "block.h"
#include "blockindexdb.h"
#include "core.h"
#include "param.h"
#include "struct.h"
#include "timeseries.h"
#include "txindexdb.h"
#include "txpooldata.h"
#include "unspentdb.h"
#include "util.h"
#include "walletdb.h"

using namespace xengine;
using namespace bigbang::storage;
using namespace boost::filesystem;
using namespace std;

namespace bigbang
{

/////////////////////////////////////////////////////////////////////////
// CCheckBlockTx

class CCheckBlockTx
{
public:
    CCheckBlockTx(const CTransaction& txIn, const CTxContxt& contxtIn, int nHeight, const uint256& hashAtForkIn, uint32 nFileNoIn, uint32 nOffsetIn)
      : tx(txIn), txContxt(contxtIn), hashAtFork(hashAtForkIn), txIndex(nHeight, nFileNoIn, nOffsetIn)
    {
    }

public:
    const CTransaction& tx;
    CTxContxt txContxt;
    CTxIndex txIndex;
    uint256 hashAtFork;
};

class CCheckTxOut : public CTxOut
{
public:
    CCheckTxOut() {}
    CCheckTxOut(const CDestination destToIn, int64 nAmountIn, uint32 nTxTimeIn, uint32 nLockUntilIn)
      : CTxOut(destToIn, nAmountIn, nTxTimeIn, nLockUntilIn) {}
    CCheckTxOut(const CTransaction& tx)
      : CTxOut(tx) {}
    CCheckTxOut(const CTransaction& tx, const CDestination& destToIn, int64 nValueIn)
      : CTxOut(tx, destToIn, nValueIn) {}
    CCheckTxOut(const CTxOut& txOut)
      : CTxOut(txOut) {}

    friend bool operator==(const CCheckTxOut& a, const CCheckTxOut& b)
    {
        return (a.destTo == b.destTo && a.nAmount == b.nAmount && a.nTxTime == b.nTxTime && a.nLockUntil == b.nLockUntil);
    }
    friend bool operator!=(const CCheckTxOut& a, const CCheckTxOut& b)
    {
        return !(a == b);
    }
};

class CCheckForkUnspentWalker : public CForkUnspentDBWalker
{
public:
    CCheckForkUnspentWalker() {}

    bool Walk(const CTxOutPoint& txout, const CTxOut& output) override;
    bool CheckForkUnspent(map<CTxOutPoint, CCheckTxOut>& mapBlockForkUnspent);

public:
    map<CTxOutPoint, CCheckTxOut> mapForkUnspent;

    vector<CTxUnspent> vAddUpdate;
    vector<CTxOutPoint> vRemove;
};

/////////////////////////////////////////////////////////////////////////
// CCheckForkStatus & CCheckForkManager

class CCheckForkStatus
{
public:
    CCheckForkStatus() {}

    void InsertSubline(int nHeight, const uint256& hashSubline)
    {
        mapSubline.insert(std::make_pair(nHeight, hashSubline));
    }

public:
    CForkContext ctxt;
    uint256 hashLastBlock;
    std::multimap<int, uint256> mapSubline;
};

class CCheckForkManager
{
public:
    CCheckForkManager(const bool fTestnet)
      : objProofParam(fTestnet) {}

    bool FetchForkStatus(const string& strDataPath);
    void GetTxFork(const uint256& hashFork, int nHeight, vector<uint256>& vFork);
    bool UpdateForkLast(const string& strDataPath, const vector<pair<uint256, uint256>>& vForkLast);

public:
    CProofOfWorkParam objProofParam;
    map<uint256, CCheckForkStatus> mapForkStatus;
};

/////////////////////////////////////////////////////////////////////////
// CCheckWalletTxWalker

class CCheckWalletTx : public CWalletTx
{
public:
    uint64 nSequenceNumber;
    uint64 nNextSequenceNumber;

public:
    CCheckWalletTx()
      : nSequenceNumber(0), nNextSequenceNumber(0) {}
    CCheckWalletTx(const CWalletTx& wtx, uint64 nSeq)
      : CWalletTx(wtx), nSequenceNumber(nSeq), nNextSequenceNumber(0) {}
};

class CWalletTxLink
{
public:
    CWalletTxLink()
      : nSequenceNumber(0), ptx(nullptr) {}
    CWalletTxLink(CCheckWalletTx* ptxin)
      : ptx(ptxin)
    {
        hashTX = ptx->txid;
        nSequenceNumber = ptx->nSequenceNumber;
    }

public:
    uint256 hashTX;
    uint64 nSequenceNumber;
    CCheckWalletTx* ptx;
};

typedef boost::multi_index_container<
    CWalletTxLink,
    boost::multi_index::indexed_by<
        boost::multi_index::ordered_unique<boost::multi_index::member<CWalletTxLink, uint256, &CWalletTxLink::hashTX>>,
        boost::multi_index::ordered_non_unique<boost::multi_index::member<CWalletTxLink, uint64, &CWalletTxLink::nSequenceNumber>>>>
    CWalletTxLinkSet;
typedef CWalletTxLinkSet::nth_index<0>::type CWalletTxLinkSetByTxHash;
typedef CWalletTxLinkSet::nth_index<1>::type CWalletTxLinkSetBySequenceNumber;

class CCheckWalletForkUnspent
{
public:
    CCheckWalletForkUnspent(const uint256& hashForkIn)
      : nSeqCreate(0), hashFork(hashForkIn) {}

    bool LocalTxExist(const uint256& txid);
    CCheckWalletTx* GetLocalWalletTx(const uint256& txid);
    bool AddTx(const CWalletTx& wtx);
    void RemoveTx(const uint256& txid);

    bool UpdateUnspent();
    bool AddWalletSpent(const CTxOutPoint& txPoint, const uint256& txidSpent, const CDestination& sendTo);
    bool AddWalletUnspent(const CTxOutPoint& txPoint, const CTxOut& txOut);

    int GetTxAtBlockHeight(const uint256& txid);
    bool CheckWalletUnspent(const CTxOutPoint& point, const CCheckTxOut& out);

protected:
    uint256 hashFork;
    uint64 nSeqCreate;
    CWalletTxLinkSet setWalletTxLink;

public:
    map<uint256, CCheckWalletTx> mapWalletTx;
    map<CTxOutPoint, CCheckTxOut> mapWalletUnspent;
};

class CCheckWalletTxWalker : public CWalletDBTxWalker
{
public:
    CCheckWalletTxWalker()
      : nWalletTxCount(0), pForkManager(nullptr) {}

    void SetForkManager(CCheckForkManager* pFork)
    {
        pForkManager = pFork;
    }

    bool Walk(const CWalletTx& wtx) override;

    bool Exist(const uint256& hashFork, const uint256& txid);
    CCheckWalletTx* GetWalletTx(const uint256& hashFork, const uint256& txid);
    bool AddWalletTx(const CWalletTx& wtx);
    void RemoveWalletTx(const uint256& hashFork, int nHeight, const uint256& txid);
    bool UpdateUnspent();
    int GetTxAtBlockHeight(const uint256& hashFork, const uint256& txid);
    bool CheckWalletUnspent(const uint256& hashFork, const CTxOutPoint& point, const CCheckTxOut& out);

protected:
    CCheckForkManager* pForkManager;

public:
    int64 nWalletTxCount;
    map<uint256, CCheckWalletForkUnspent> mapWalletFork;
};

/////////////////////////////////////////////////////////////////////////
// CCheckDBAddrWalker

class CCheckDBAddrWalker : public storage::CWalletDBAddrWalker
{
public:
    CCheckDBAddrWalker() {}
    bool WalkPubkey(const crypto::CPubKey& pubkey, int version, const crypto::CCryptoCipher& cipher) override
    {
        return setAddress.insert(CDestination(pubkey)).second;
    }
    bool WalkTemplate(const CTemplateId& tid, const std::vector<unsigned char>& vchData) override
    {
        return setAddress.insert(CDestination(tid)).second;
    }
    bool CheckAddress(const CDestination& dest)
    {
        return (setAddress.find(dest) != setAddress.end());
    }

public:
    set<CDestination> setAddress;
};

/////////////////////////////////////////////////////////////////////////
// CCheckTsBlock

class CCheckTsBlock : public CTimeSeriesCached
{
public:
    CCheckTsBlock() {}
    ~CCheckTsBlock()
    {
        Deinitialize();
    }
};

/////////////////////////////////////////////////////////////////////////
// CCheckBlockIndexWalker

class CCheckBlockIndexWalker : public CBlockDBWalker
{
public:
    bool Walk(CBlockOutline& outline) override
    {
        mapBlockIndex.insert(make_pair(outline.hashBlock, outline));
        return true;
    }
    bool CheckBlock(const CBlockOutline& cacheBlock)
    {
        map<uint256, CBlockOutline>::iterator it = mapBlockIndex.find(cacheBlock.hashBlock);
        if (it == mapBlockIndex.end())
        {
            StdLog("check", "Find block index fail, hash: %s", cacheBlock.hashBlock.GetHex().c_str());
            return false;
        }
        const CBlockOutline& outline = it->second;
        if (!(outline.nFile == cacheBlock.nFile && outline.nOffset == cacheBlock.nOffset))
        {
            StdLog("check", "Check block index fail, hash: %s",
                   cacheBlock.hashBlock.GetHex().c_str());
            return false;
        }
        return true;
    }
    CBlockOutline* GetBlockOutline(const uint256& hashBlock)
    {
        map<uint256, CBlockOutline>::iterator it = mapBlockIndex.find(hashBlock);
        if (it == mapBlockIndex.end())
        {
            return nullptr;
        }
        return &(it->second);
    }

public:
    map<uint256, CBlockOutline> mapBlockIndex;
};

/////////////////////////////////////////////////////////////////////////
// CCheckDbTxPool
class CCheckForkTxPool
{
public:
    CCheckForkTxPool() {}

    bool AddTx(const uint256& txid, const CAssembledTx& tx);
    bool CheckTxExist(const uint256& txid);
    bool CheckTxPoolUnspent(const CTxOutPoint& point, const CCheckTxOut& out);
    bool GetWalletTx(const uint256& hashFork, const set<CDestination>& setAddress, vector<CWalletTx>& vWalletTx);

protected:
    bool Spent(const CTxOutPoint& point, const uint256& txidSpent, const CDestination& sendTo);
    bool Unspent(const CTxOutPoint& point, const CTxOut& out);

public:
    uint256 hashFork;
    vector<pair<uint256, CAssembledTx>> vTx;
    map<uint256, CAssembledTx> mapTxPoolTx;
    map<CTxOutPoint, CCheckTxOut> mapTxPoolUnspent;
};

class CCheckTxPoolData
{
public:
    CCheckTxPoolData() {}

    void AddForkUnspent(const uint256& hashFork, const map<CTxOutPoint, CCheckTxOut>& mapUnspent);
    bool FetchTxPool(const string& strPath);
    bool CheckTxExist(const uint256& hashFork, const uint256& txid);
    bool CheckTxPoolUnspent(const uint256& hashFork, const CTxOutPoint& point, const CCheckTxOut& out);
    bool GetTxPoolWalletTx(const set<CDestination>& setAddress, vector<CWalletTx>& vWalletTx);

public:
    map<uint256, CCheckForkTxPool> mapForkTxPool;
};

/////////////////////////////////////////////////////////////////////////
// CCheckBlockFork

class CCheckBlockFork
{
public:
    CCheckBlockFork()
      : pOrigin(nullptr), pLast(nullptr) {}

    void UpdateMaxTrust(CBlockIndex* pBlockIndex);
    bool AddBlockTx(const CTransaction& txIn, const CTxContxt& contxtIn, int nHeight, const uint256& hashAtForkIn, uint32 nFileNoIn, uint32 nOffsetIn);
    bool AddBlockSpent(const CTxOutPoint& txPoint, const uint256& txidSpent, const CDestination& sendTo);
    bool AddBlockUnspent(const CTxOutPoint& txPoint, const CTxOut& txOut);
    bool CheckTxExist(const uint256& txid, int& nHeight);

public:
    CBlockIndex* pOrigin;
    CBlockIndex* pLast;
    map<uint256, CCheckBlockTx> mapBlockTx;
    map<CTxOutPoint, CCheckTxOut> mapBlockUnspent;
};

/////////////////////////////////////////////////////////////////////////
// CCheckBlockWalker
class CCheckBlockWalker : public CTSWalker<CBlockEx>
{
public:
    CCheckBlockWalker(bool fTestnetIn, bool fOnlyCheckIn)
      : nBlockCount(0), nMainChainHeight(0), nMainChainTxCount(0), objProofParam(fTestnetIn), fOnlyCheck(fOnlyCheckIn) {}
    ~CCheckBlockWalker();

    bool Initialize(const string& strPath);

    bool Walk(const CBlockEx& block, uint32 nFile, uint32 nOffset) override;

    bool UpdateBlockNext();
    bool UpdateBlockTx(CCheckForkManager& objForkMn);
    bool AddBlockTx(const CTransaction& txIn, const CTxContxt& contxtIn, int nHeight, const uint256& hashAtForkIn, uint32 nFileNoIn, uint32 nOffsetIn, const vector<uint256>& vFork);
    CBlockIndex* AddNewIndex(const uint256& hash, const CBlock& block, uint32 nFile, uint32 nOffset, uint256 nChainTrust);
    CBlockIndex* AddNewIndex(const uint256& hash, const CBlockOutline& objBlockOutline);
    void ClearBlockIndex();
    bool CheckTxExist(const uint256& hashFork, const uint256& txid, int& nHeight);
    bool GetBlockWalletTx(const set<CDestination>& setAddress, vector<CWalletTx>& vWalletTx);
    bool CheckBlockIndex();

public:
    bool fOnlyCheck;
    int64 nBlockCount;
    uint32 nMainChainHeight;
    int64 nMainChainTxCount;
    uint256 hashGenesis;
    CProofOfWorkParam objProofParam;
    map<uint256, CCheckBlockFork> mapCheckFork;
    map<uint256, CBlockEx> mapBlock;
    map<uint256, CBlockIndex*> mapBlockIndex;
    CBlockIndexDB dbBlockIndex;
    CCheckBlockIndexWalker objBlockIndexWalker;
    CCheckTsBlock objTsBlock;
};

/////////////////////////////////////////////////////////////////////////
// CCheckRepairData

class CCheckRepairData
{
public:
    CCheckRepairData(const string& strPath, bool fTestnetIn, bool fOnlyCheckIn)
      : strDataPath(strPath), fTestnet(fTestnetIn), fOnlyCheck(fOnlyCheckIn), objForkManager(fTestnetIn), objBlockWalker(fTestnetIn, fOnlyCheckIn) {}

protected:
    bool FetchBlockData();
    bool FetchUnspent();
    bool FetchTxPool();
    bool FetchWalletAddress();
    bool FetchWalletTx();

    bool CheckRepairFork();
    bool CheckBlockUnspent();
    bool CheckWalletTx(vector<CWalletTx>& vAddTx, vector<uint256>& vRemoveTx);
    bool CheckBlockIndex();
    bool CheckTxIndex();

    bool RemoveTxPoolFile();
    bool RepairUnspent();
    bool RepairWalletTx(const vector<CWalletTx>& vAddTx, const vector<uint256>& vRemoveTx);
    bool RestructureWalletTx();

public:
    bool CheckRepairData();

protected:
    string strDataPath;
    bool fTestnet;
    bool fOnlyCheck;

    CCheckForkManager objForkManager;
    CCheckBlockWalker objBlockWalker;
    map<uint256, CCheckForkUnspentWalker> mapForkUnspentWalker;
    CCheckDBAddrWalker objWalletAddressWalker;
    CCheckWalletTxWalker objWalletTxWalker;
    CCheckTxPoolData objTxPoolData;
};

} // namespace bigbang

#endif //STORAGE_CHECKREPAIR_H
