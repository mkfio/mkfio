// Copyright (c) 2019-2020 The Bigbang developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BIGBANG_RPC_AUTO_PROTOCOL_H
#define BIGBANG_RPC_AUTO_PROTOCOL_H

#include <cfloat>
#include <climits>

#include "json/json_spirit_utils.h"

#include "rpc/rpc_type.h"
#include "rpc/rpc_req.h"
#include "rpc/rpc_resp.h"

namespace bigbang
{
namespace rpc
{

#ifdef __required__
#pragma push_macro("__required__")
#define PUSHED_MACRO_REQUIRED
#undef __required__
#endif
#define __required__

#ifdef __optional__
#pragma push_macro("__optional__")
#define PUSHED_MACRO_OPTIONAL
#undef __optional__
#endif
#define __optional__

class CUnspentData;
class CTemplatePubKeyWeight;
class CTemplateRequest;
class CTemplateResponse;
class CTransactionData;
class CWalletTxData;
class CBlockData;
class Cblockdatadetail;

// class CUnspentData
class CUnspentData
{
public:
	__required__ CRPCString strTxid;
	__required__ CRPCUint64 nOut;
	__required__ CRPCDouble dAmount;
	__required__ CRPCUint64 nTime;
	__required__ CRPCUint64 nLockuntil;
public:
	CUnspentData();
	CUnspentData(const CRPCString& strTxid, const CRPCUint64& nOut, const CRPCDouble& dAmount, const CRPCUint64& nTime, const CRPCUint64& nLockuntil);
	CUnspentData(const CRPCType& type);
	json_spirit::Value ToJSON() const;
	CUnspentData& FromJSON(const json_spirit::Value& v);
	bool IsValid() const;
};

// class CTemplatePubKeyWeight
class CTemplatePubKeyWeight
{
public:
	__required__ CRPCString strKey;
	__required__ CRPCInt64 nWeight;
public:
	CTemplatePubKeyWeight();
	CTemplatePubKeyWeight(const CRPCString& strKey, const CRPCInt64& nWeight);
	CTemplatePubKeyWeight(const CRPCType& type);
	json_spirit::Value ToJSON() const;
	CTemplatePubKeyWeight& FromJSON(const json_spirit::Value& v);
	bool IsValid() const;
};

// class CTemplateRequest
class CTemplateRequest
{
public:
	// class CPayment
	class CPayment
	{
	public:
		__required__ CRPCString strBusiness;
		__required__ CRPCString strCustomer;
		__required__ CRPCInt64 nHeight_Exec;
		__required__ CRPCInt64 nHeight_End;
		__required__ CRPCInt64 nAmount;
		__required__ CRPCInt64 nPledge;
	public:
		CPayment();
		CPayment(const CRPCString& strBusiness, const CRPCString& strCustomer, const CRPCInt64& nHeight_Exec, const CRPCInt64& nHeight_End, const CRPCInt64& nAmount, const CRPCInt64& nPledge);
		CPayment(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CPayment& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
	// class CWeighted
	class CWeighted
	{
	public:
		__required__ CRPCInt64 nRequired;
		__required__ CRPCVector<CTemplatePubKeyWeight> vecPubkeys = RPCValid;
	public:
		CWeighted();
		CWeighted(const CRPCInt64& nRequired, const CRPCVector<CTemplatePubKeyWeight>& vecPubkeys);
		CWeighted(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CWeighted& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
	// class CMint
	class CMint
	{
	public:
		__required__ CRPCString strMint;
		__required__ CRPCString strSpent;
	public:
		CMint();
		CMint(const CRPCString& strMint, const CRPCString& strSpent);
		CMint(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CMint& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
	// class CExchange
	class CExchange
	{
	public:
		__required__ CRPCString strAddr_M;
		__required__ CRPCString strAddr_S;
		__required__ CRPCInt64 nHeight_M;
		__required__ CRPCInt64 nHeight_S;
		__required__ CRPCString strFork_M;
		__required__ CRPCString strFork_S;
	public:
		CExchange();
		CExchange(const CRPCString& strAddr_M, const CRPCString& strAddr_S, const CRPCInt64& nHeight_M, const CRPCInt64& nHeight_S, const CRPCString& strFork_M, const CRPCString& strFork_S);
		CExchange(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CExchange& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
	// class CMultisig
	class CMultisig
	{
	public:
		__required__ CRPCInt64 nRequired;
		__required__ CRPCVector<std::string> vecPubkeys = RPCValid;
	public:
		CMultisig();
		CMultisig(const CRPCInt64& nRequired, const CRPCVector<std::string>& vecPubkeys);
		CMultisig(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CMultisig& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
	// class CVote
	class CVote
	{
	public:
		__required__ CRPCString strDelegate;
		__required__ CRPCString strOwner;
	public:
		CVote();
		CVote(const CRPCString& strDelegate, const CRPCString& strOwner);
		CVote(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CVote& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
	// class CFork
	class CFork
	{
	public:
		__required__ CRPCString strRedeem;
		__required__ CRPCString strFork;
	public:
		CFork();
		CFork(const CRPCString& strRedeem, const CRPCString& strFork);
		CFork(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CFork& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
	// class CDelegate
	class CDelegate
	{
	public:
		__required__ CRPCString strDelegate;
		__required__ CRPCString strOwner;
	public:
		CDelegate();
		CDelegate(const CRPCString& strDelegate, const CRPCString& strOwner);
		CDelegate(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CDelegate& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
public:
	__required__ CRPCString strType;
	__required__ CDelegate delegate;
	__required__ CVote vote;
	__required__ CFork fork;
	__required__ CMint mint;
	__required__ CMultisig multisig;
	__required__ CWeighted weighted;
	__required__ CExchange exchange;
	__required__ CPayment payment;
	__optional__ CRPCBool fSynctx = true;
public:
	CTemplateRequest();
	CTemplateRequest(const CRPCString& strType, const CDelegate& delegate, const CVote& vote, const CFork& fork, const CMint& mint, const CMultisig& multisig, const CWeighted& weighted, const CExchange& exchange, const CPayment& payment, const CRPCBool& fSynctx);
	CTemplateRequest(const CRPCType& type);
	json_spirit::Value ToJSON() const;
	CTemplateRequest& FromJSON(const json_spirit::Value& v);
	bool IsValid() const;
};

// class CTemplateResponse
class CTemplateResponse
{
public:
	// class CPayment
	class CPayment
	{
	public:
		__required__ CRPCString strBusiness;
		__required__ CRPCString strCustomer;
		__required__ CRPCInt64 nHeight_Exec;
		__required__ CRPCInt64 nHeight_End;
		__required__ CRPCInt64 nAmount;
		__required__ CRPCInt64 nPledge;
	public:
		CPayment();
		CPayment(const CRPCString& strBusiness, const CRPCString& strCustomer, const CRPCInt64& nHeight_Exec, const CRPCInt64& nHeight_End, const CRPCInt64& nAmount, const CRPCInt64& nPledge);
		CPayment(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CPayment& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
	// class CDelegate
	class CDelegate
	{
	public:
		__required__ CRPCString strDelegate;
		__required__ CRPCString strOwner;
	public:
		CDelegate();
		CDelegate(const CRPCString& strDelegate, const CRPCString& strOwner);
		CDelegate(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CDelegate& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
	// class CVote
	class CVote
	{
	public:
		__required__ CRPCString strDelegate;
		__required__ CRPCString strOwner;
	public:
		CVote();
		CVote(const CRPCString& strDelegate, const CRPCString& strOwner);
		CVote(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CVote& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
	// class CMint
	class CMint
	{
	public:
		__required__ CRPCString strMint;
		__required__ CRPCString strSpent;
	public:
		CMint();
		CMint(const CRPCString& strMint, const CRPCString& strSpent);
		CMint(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CMint& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
	// class CMultisig
	class CMultisig
	{
	public:
		__required__ CRPCInt64 nRequired;
		__required__ CRPCVector<std::string> vecAddresses = RPCValid;
	public:
		CMultisig();
		CMultisig(const CRPCInt64& nRequired, const CRPCVector<std::string>& vecAddresses);
		CMultisig(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CMultisig& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
	// class CFork
	class CFork
	{
	public:
		__required__ CRPCString strRedeem;
		__required__ CRPCString strFork;
	public:
		CFork();
		CFork(const CRPCString& strRedeem, const CRPCString& strFork);
		CFork(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CFork& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
	// class CWeighted
	class CWeighted
	{
	public:
		__required__ CRPCInt64 nRequired;
		__required__ CRPCVector<CTemplatePubKeyWeight> vecAddresses = RPCValid;
	public:
		CWeighted();
		CWeighted(const CRPCInt64& nRequired, const CRPCVector<CTemplatePubKeyWeight>& vecAddresses);
		CWeighted(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CWeighted& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
	// class CExchange
	class CExchange
	{
	public:
		__required__ CRPCString strSpend_M;
		__required__ CRPCString strSpend_S;
		__required__ CRPCInt64 nHeight_M;
		__required__ CRPCInt64 nHeight_S;
		__required__ CRPCString strFork_M;
		__required__ CRPCString strFork_S;
	public:
		CExchange();
		CExchange(const CRPCString& strSpend_M, const CRPCString& strSpend_S, const CRPCInt64& nHeight_M, const CRPCInt64& nHeight_S, const CRPCString& strFork_M, const CRPCString& strFork_S);
		CExchange(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CExchange& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
public:
	__required__ CRPCString strType;
	__required__ CRPCString strHex;
	__required__ CDelegate delegate;
	__required__ CVote vote;
	__required__ CFork fork;
	__required__ CMint mint;
	__required__ CMultisig multisig;
	__required__ CExchange exchange;
	__required__ CPayment payment;
	__required__ CWeighted weighted;
public:
	CTemplateResponse();
	CTemplateResponse(const CRPCString& strType, const CRPCString& strHex, const CDelegate& delegate, const CVote& vote, const CFork& fork, const CMint& mint, const CMultisig& multisig, const CExchange& exchange, const CPayment& payment, const CWeighted& weighted);
	CTemplateResponse(const CRPCType& type);
	json_spirit::Value ToJSON() const;
	CTemplateResponse& FromJSON(const json_spirit::Value& v);
	bool IsValid() const;
};

// class CTransactionData
class CTransactionData
{
public:
	// class CVin
	class CVin
	{
	public:
		__required__ CRPCString strTxid;
		__required__ CRPCUint64 nVout;
	public:
		CVin();
		CVin(const CRPCString& strTxid, const CRPCUint64& nVout);
		CVin(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CVin& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
public:
	__required__ CRPCString strTxid;
	__required__ CRPCUint64 nVersion;
	__required__ CRPCString strType;
	__required__ CRPCUint64 nTime;
	__required__ CRPCUint64 nLockuntil;
	__required__ CRPCString strBlockhash;
	__required__ CRPCVector<CVin> vecVin = RPCValid;
	__required__ CRPCString strSendfrom;
	__required__ CRPCString strSendto;
	__required__ CRPCDouble dAmount;
	__required__ CRPCDouble dTxfee;
	__required__ CRPCString strData;
	__required__ CRPCString strSig;
	__required__ CRPCString strFork;
	__optional__ CRPCInt64 nConfirmations;
public:
	CTransactionData();
	CTransactionData(const CRPCString& strTxid, const CRPCUint64& nVersion, const CRPCString& strType, const CRPCUint64& nTime, const CRPCUint64& nLockuntil, const CRPCString& strBlockhash, const CRPCVector<CVin>& vecVin, const CRPCString& strSendfrom, const CRPCString& strSendto, const CRPCDouble& dAmount, const CRPCDouble& dTxfee, const CRPCString& strData, const CRPCString& strSig, const CRPCString& strFork, const CRPCInt64& nConfirmations);
	CTransactionData(const CRPCType& type);
	json_spirit::Value ToJSON() const;
	CTransactionData& FromJSON(const json_spirit::Value& v);
	bool IsValid() const;
};

// class CWalletTxData
class CWalletTxData
{
public:
	__required__ CRPCString strTxid;
	__required__ CRPCString strFork;
	__required__ CRPCString strType;
	__required__ CRPCUint64 nTime;
	__required__ CRPCBool fSend;
	__required__ CRPCString strTo;
	__required__ CRPCDouble dAmount;
	__required__ CRPCDouble dFee;
	__required__ CRPCUint64 nLockuntil;
	__optional__ CRPCInt64 nBlockheight;
	__optional__ CRPCString strFrom;
public:
	CWalletTxData();
	CWalletTxData(const CRPCString& strTxid, const CRPCString& strFork, const CRPCString& strType, const CRPCUint64& nTime, const CRPCBool& fSend, const CRPCString& strTo, const CRPCDouble& dAmount, const CRPCDouble& dFee, const CRPCUint64& nLockuntil, const CRPCInt64& nBlockheight, const CRPCString& strFrom);
	CWalletTxData(const CRPCType& type);
	json_spirit::Value ToJSON() const;
	CWalletTxData& FromJSON(const json_spirit::Value& v);
	bool IsValid() const;
};

// class CBlockData
class CBlockData
{
public:
	__required__ CRPCString strHash;
	__required__ CRPCString strHashprev;
	__required__ CRPCUint64 nVersion;
	__required__ CRPCString strType;
	__required__ CRPCUint64 nTime;
	__required__ CRPCString strFork;
	__required__ CRPCUint64 nHeight;
	__required__ CRPCString strTxmint;
	__required__ CRPCVector<std::string> vecTx = RPCValid;
	__optional__ CRPCString strPrev;
public:
	CBlockData();
	CBlockData(const CRPCString& strHash, const CRPCString& strHashprev, const CRPCUint64& nVersion, const CRPCString& strType, const CRPCUint64& nTime, const CRPCString& strFork, const CRPCUint64& nHeight, const CRPCString& strTxmint, const CRPCVector<std::string>& vecTx, const CRPCString& strPrev);
	CBlockData(const CRPCType& type);
	json_spirit::Value ToJSON() const;
	CBlockData& FromJSON(const json_spirit::Value& v);
	bool IsValid() const;
};

// class Cblockdatadetail
class Cblockdatadetail
{
public:
	__required__ CRPCString strHash;
	__required__ CRPCString strHashprev;
	__required__ CRPCUint64 nVersion;
	__required__ CRPCString strType;
	__required__ CRPCUint64 nTime;
	__required__ CRPCUint64 nBits;
	__required__ CRPCString strFork;
	__required__ CRPCUint64 nHeight;
	__required__ CTransactionData txmint;
	__required__ CRPCVector<CTransactionData> vecTx = RPCValid;
	__optional__ CRPCString strPrev;
public:
	Cblockdatadetail();
	Cblockdatadetail(const CRPCString& strHash, const CRPCString& strHashprev, const CRPCUint64& nVersion, const CRPCString& strType, const CRPCUint64& nTime, const CRPCUint64& nBits, const CRPCString& strFork, const CRPCUint64& nHeight, const CTransactionData& txmint, const CRPCVector<CTransactionData>& vecTx, const CRPCString& strPrev);
	Cblockdatadetail(const CRPCType& type);
	json_spirit::Value ToJSON() const;
	Cblockdatadetail& FromJSON(const json_spirit::Value& v);
	bool IsValid() const;
};

/////////////////////////////////////////////////////
// help

// CHelpParam
class CHelpParam : public CRPCParam
{
public:
	__optional__ CRPCString strCommand;
public:
	CHelpParam();
	CHelpParam(const CRPCString& strCommand);
	virtual ~CHelpParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CHelpParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CHelpParam> MakeCHelpParamPtr(Args&&... args)
{
	return std::make_shared<CHelpParam>(std::forward<Args>(args)...);
}

// CHelpResult
class CHelpResult : public CRPCResult
{
public:
	__required__ CRPCString strHelp;
public:
	CHelpResult();
	CHelpResult(const CRPCString& strHelp);
	virtual ~CHelpResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CHelpResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CHelpResult> MakeCHelpResultPtr(Args&&... args)
{
	return std::make_shared<CHelpResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// stop

// CStopParam
class CStopParam : public CRPCParam
{
public:
	CStopParam();
	virtual ~CStopParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CStopParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CStopParam> MakeCStopParamPtr(Args&&... args)
{
	return std::make_shared<CStopParam>(std::forward<Args>(args)...);
}

// CStopResult
class CStopResult : public CRPCResult
{
public:
	__required__ CRPCString strResult;
public:
	CStopResult();
	CStopResult(const CRPCString& strResult);
	virtual ~CStopResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CStopResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CStopResult> MakeCStopResultPtr(Args&&... args)
{
	return std::make_shared<CStopResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// version

// CVersionParam
class CVersionParam : public CRPCParam
{
public:
	CVersionParam();
	virtual ~CVersionParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CVersionParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CVersionParam> MakeCVersionParamPtr(Args&&... args)
{
	return std::make_shared<CVersionParam>(std::forward<Args>(args)...);
}

// CVersionResult
class CVersionResult : public CRPCResult
{
public:
	__required__ CRPCString strVersion;
public:
	CVersionResult();
	CVersionResult(const CRPCString& strVersion);
	virtual ~CVersionResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CVersionResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CVersionResult> MakeCVersionResultPtr(Args&&... args)
{
	return std::make_shared<CVersionResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// getpeercount

// CGetPeerCountParam
class CGetPeerCountParam : public CRPCParam
{
public:
	CGetPeerCountParam();
	virtual ~CGetPeerCountParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetPeerCountParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetPeerCountParam> MakeCGetPeerCountParamPtr(Args&&... args)
{
	return std::make_shared<CGetPeerCountParam>(std::forward<Args>(args)...);
}

// CGetPeerCountResult
class CGetPeerCountResult : public CRPCResult
{
public:
	__required__ CRPCInt64 nCount;
public:
	CGetPeerCountResult();
	CGetPeerCountResult(const CRPCInt64& nCount);
	virtual ~CGetPeerCountResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetPeerCountResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetPeerCountResult> MakeCGetPeerCountResultPtr(Args&&... args)
{
	return std::make_shared<CGetPeerCountResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// listpeer

// CListPeerParam
class CListPeerParam : public CRPCParam
{
public:
	CListPeerParam();
	virtual ~CListPeerParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CListPeerParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CListPeerParam> MakeCListPeerParamPtr(Args&&... args)
{
	return std::make_shared<CListPeerParam>(std::forward<Args>(args)...);
}

// CListPeerResult
class CListPeerResult : public CRPCResult
{
public:
	// class CPeer
	class CPeer
	{
	public:
		__required__ CRPCString strAddress;
		__required__ CRPCString strServices;
		__required__ CRPCString strLastsend;
		__required__ CRPCString strLastrecv;
		__required__ CRPCString strConntime;
		__required__ CRPCInt64 nPingtime;
		__required__ CRPCString strVersion;
		__required__ CRPCString strSubver;
		__required__ CRPCBool fInbound;
		__required__ CRPCInt64 nHeight;
		__required__ CRPCInt64 nBanscore;
	public:
		CPeer();
		CPeer(const CRPCString& strAddress, const CRPCString& strServices, const CRPCString& strLastsend, const CRPCString& strLastrecv, const CRPCString& strConntime, const CRPCInt64& nPingtime, const CRPCString& strVersion, const CRPCString& strSubver, const CRPCBool& fInbound, const CRPCInt64& nHeight, const CRPCInt64& nBanscore);
		CPeer(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CPeer& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
public:
	__required__ CRPCVector<CPeer> vecPeer = RPCValid;
public:
	CListPeerResult();
	CListPeerResult(const CRPCVector<CPeer>& vecPeer);
	virtual ~CListPeerResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CListPeerResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CListPeerResult> MakeCListPeerResultPtr(Args&&... args)
{
	return std::make_shared<CListPeerResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// addnode

// CAddNodeParam
class CAddNodeParam : public CRPCParam
{
public:
	__required__ CRPCString strNode;
public:
	CAddNodeParam();
	CAddNodeParam(const CRPCString& strNode);
	virtual ~CAddNodeParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CAddNodeParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CAddNodeParam> MakeCAddNodeParamPtr(Args&&... args)
{
	return std::make_shared<CAddNodeParam>(std::forward<Args>(args)...);
}

// CAddNodeResult
class CAddNodeResult : public CRPCResult
{
public:
	__required__ CRPCString strResult;
public:
	CAddNodeResult();
	CAddNodeResult(const CRPCString& strResult);
	virtual ~CAddNodeResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CAddNodeResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CAddNodeResult> MakeCAddNodeResultPtr(Args&&... args)
{
	return std::make_shared<CAddNodeResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// removenode

// CRemoveNodeParam
class CRemoveNodeParam : public CRPCParam
{
public:
	__required__ CRPCString strNode;
public:
	CRemoveNodeParam();
	CRemoveNodeParam(const CRPCString& strNode);
	virtual ~CRemoveNodeParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CRemoveNodeParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CRemoveNodeParam> MakeCRemoveNodeParamPtr(Args&&... args)
{
	return std::make_shared<CRemoveNodeParam>(std::forward<Args>(args)...);
}

// CRemoveNodeResult
class CRemoveNodeResult : public CRPCResult
{
public:
	__required__ CRPCString strResult;
public:
	CRemoveNodeResult();
	CRemoveNodeResult(const CRPCString& strResult);
	virtual ~CRemoveNodeResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CRemoveNodeResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CRemoveNodeResult> MakeCRemoveNodeResultPtr(Args&&... args)
{
	return std::make_shared<CRemoveNodeResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// getforkcount

// CGetForkCountParam
class CGetForkCountParam : public CRPCParam
{
public:
	CGetForkCountParam();
	virtual ~CGetForkCountParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetForkCountParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetForkCountParam> MakeCGetForkCountParamPtr(Args&&... args)
{
	return std::make_shared<CGetForkCountParam>(std::forward<Args>(args)...);
}

// CGetForkCountResult
class CGetForkCountResult : public CRPCResult
{
public:
	__required__ CRPCInt64 nCount;
public:
	CGetForkCountResult();
	CGetForkCountResult(const CRPCInt64& nCount);
	virtual ~CGetForkCountResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetForkCountResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetForkCountResult> MakeCGetForkCountResultPtr(Args&&... args)
{
	return std::make_shared<CGetForkCountResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// listfork

// CListForkParam
class CListForkParam : public CRPCParam
{
public:
	__optional__ CRPCBool fAll = false;
public:
	CListForkParam();
	CListForkParam(const CRPCBool& fAll);
	virtual ~CListForkParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CListForkParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CListForkParam> MakeCListForkParamPtr(Args&&... args)
{
	return std::make_shared<CListForkParam>(std::forward<Args>(args)...);
}

// CListForkResult
class CListForkResult : public CRPCResult
{
public:
	// class CProfile
	class CProfile
	{
	public:
		__required__ CRPCString strFork;
		__required__ CRPCString strName;
		__required__ CRPCString strSymbol;
		__required__ CRPCDouble dAmount;
		__required__ CRPCDouble dReward;
		__required__ CRPCUint64 nHalvecycle;
		__required__ CRPCBool fIsolated;
		__required__ CRPCBool fPrivate;
		__required__ CRPCBool fEnclosed;
		__required__ CRPCString strOwner;
	public:
		CProfile();
		CProfile(const CRPCString& strFork, const CRPCString& strName, const CRPCString& strSymbol, const CRPCDouble& dAmount, const CRPCDouble& dReward, const CRPCUint64& nHalvecycle, const CRPCBool& fIsolated, const CRPCBool& fPrivate, const CRPCBool& fEnclosed, const CRPCString& strOwner);
		CProfile(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CProfile& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
public:
	__required__ CRPCVector<CProfile> vecProfile = RPCValid;
public:
	CListForkResult();
	CListForkResult(const CRPCVector<CProfile>& vecProfile);
	virtual ~CListForkResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CListForkResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CListForkResult> MakeCListForkResultPtr(Args&&... args)
{
	return std::make_shared<CListForkResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// getgenealogy

// CGetGenealogyParam
class CGetGenealogyParam : public CRPCParam
{
public:
	__optional__ CRPCString strFork;
public:
	CGetGenealogyParam();
	CGetGenealogyParam(const CRPCString& strFork);
	virtual ~CGetGenealogyParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetGenealogyParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetGenealogyParam> MakeCGetGenealogyParamPtr(Args&&... args)
{
	return std::make_shared<CGetGenealogyParam>(std::forward<Args>(args)...);
}

// CGetGenealogyResult
class CGetGenealogyResult : public CRPCResult
{
public:
	// class CSubline
	class CSubline
	{
	public:
		__required__ CRPCString strSub;
		__required__ CRPCInt64 nHeight;
	public:
		CSubline();
		CSubline(const CRPCString& strSub, const CRPCInt64& nHeight);
		CSubline(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CSubline& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
	// class CAncestry
	class CAncestry
	{
	public:
		__required__ CRPCString strParent;
		__required__ CRPCInt64 nHeight;
	public:
		CAncestry();
		CAncestry(const CRPCString& strParent, const CRPCInt64& nHeight);
		CAncestry(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CAncestry& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
public:
	__required__ CRPCVector<CAncestry> vecAncestry = RPCValid;
	__required__ CRPCVector<CSubline> vecSubline = RPCValid;
public:
	CGetGenealogyResult();
	CGetGenealogyResult(const CRPCVector<CAncestry>& vecAncestry, const CRPCVector<CSubline>& vecSubline);
	virtual ~CGetGenealogyResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetGenealogyResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetGenealogyResult> MakeCGetGenealogyResultPtr(Args&&... args)
{
	return std::make_shared<CGetGenealogyResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// getblocklocation

// CGetBlockLocationParam
class CGetBlockLocationParam : public CRPCParam
{
public:
	__required__ CRPCString strBlock;
public:
	CGetBlockLocationParam();
	CGetBlockLocationParam(const CRPCString& strBlock);
	virtual ~CGetBlockLocationParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetBlockLocationParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetBlockLocationParam> MakeCGetBlockLocationParamPtr(Args&&... args)
{
	return std::make_shared<CGetBlockLocationParam>(std::forward<Args>(args)...);
}

// CGetBlockLocationResult
class CGetBlockLocationResult : public CRPCResult
{
public:
	__required__ CRPCString strFork;
	__required__ CRPCInt64 nHeight;
public:
	CGetBlockLocationResult();
	CGetBlockLocationResult(const CRPCString& strFork, const CRPCInt64& nHeight);
	virtual ~CGetBlockLocationResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetBlockLocationResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetBlockLocationResult> MakeCGetBlockLocationResultPtr(Args&&... args)
{
	return std::make_shared<CGetBlockLocationResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// getblockcount

// CGetBlockCountParam
class CGetBlockCountParam : public CRPCParam
{
public:
	__optional__ CRPCString strFork;
public:
	CGetBlockCountParam();
	CGetBlockCountParam(const CRPCString& strFork);
	virtual ~CGetBlockCountParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetBlockCountParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetBlockCountParam> MakeCGetBlockCountParamPtr(Args&&... args)
{
	return std::make_shared<CGetBlockCountParam>(std::forward<Args>(args)...);
}

// CGetBlockCountResult
class CGetBlockCountResult : public CRPCResult
{
public:
	__required__ CRPCInt64 nCount;
public:
	CGetBlockCountResult();
	CGetBlockCountResult(const CRPCInt64& nCount);
	virtual ~CGetBlockCountResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetBlockCountResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetBlockCountResult> MakeCGetBlockCountResultPtr(Args&&... args)
{
	return std::make_shared<CGetBlockCountResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// getblockhash

// CGetBlockHashParam
class CGetBlockHashParam : public CRPCParam
{
public:
	__required__ CRPCInt64 nHeight;
	__optional__ CRPCString strFork;
public:
	CGetBlockHashParam();
	CGetBlockHashParam(const CRPCInt64& nHeight, const CRPCString& strFork);
	virtual ~CGetBlockHashParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetBlockHashParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetBlockHashParam> MakeCGetBlockHashParamPtr(Args&&... args)
{
	return std::make_shared<CGetBlockHashParam>(std::forward<Args>(args)...);
}

// CGetBlockHashResult
class CGetBlockHashResult : public CRPCResult
{
public:
	__required__ CRPCVector<std::string> vecHash = RPCValid;
public:
	CGetBlockHashResult();
	CGetBlockHashResult(const CRPCVector<std::string>& vecHash);
	virtual ~CGetBlockHashResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetBlockHashResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetBlockHashResult> MakeCGetBlockHashResultPtr(Args&&... args)
{
	return std::make_shared<CGetBlockHashResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// getblock

// CGetBlockParam
class CGetBlockParam : public CRPCParam
{
public:
	__required__ CRPCString strBlock;
public:
	CGetBlockParam();
	CGetBlockParam(const CRPCString& strBlock);
	virtual ~CGetBlockParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetBlockParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetBlockParam> MakeCGetBlockParamPtr(Args&&... args)
{
	return std::make_shared<CGetBlockParam>(std::forward<Args>(args)...);
}

// CGetBlockResult
class CGetBlockResult : public CRPCResult
{
public:
	__required__ CBlockData block;
public:
	CGetBlockResult();
	CGetBlockResult(const CBlockData& block);
	virtual ~CGetBlockResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetBlockResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetBlockResult> MakeCGetBlockResultPtr(Args&&... args)
{
	return std::make_shared<CGetBlockResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// getblockdetail

// CgetblockdetailParam
class CgetblockdetailParam : public CRPCParam
{
public:
	__required__ CRPCString strBlock;
public:
	CgetblockdetailParam();
	CgetblockdetailParam(const CRPCString& strBlock);
	virtual ~CgetblockdetailParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CgetblockdetailParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CgetblockdetailParam> MakeCgetblockdetailParamPtr(Args&&... args)
{
	return std::make_shared<CgetblockdetailParam>(std::forward<Args>(args)...);
}

// CgetblockdetailResult
class CgetblockdetailResult : public CRPCResult
{
public:
	__required__ Cblockdatadetail block;
public:
	CgetblockdetailResult();
	CgetblockdetailResult(const Cblockdatadetail& block);
	virtual ~CgetblockdetailResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CgetblockdetailResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CgetblockdetailResult> MakeCgetblockdetailResultPtr(Args&&... args)
{
	return std::make_shared<CgetblockdetailResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// gettxpool

// CGetTxPoolParam
class CGetTxPoolParam : public CRPCParam
{
public:
	__optional__ CRPCString strFork;
	__optional__ CRPCBool fDetail = false;
public:
	CGetTxPoolParam();
	CGetTxPoolParam(const CRPCString& strFork, const CRPCBool& fDetail);
	virtual ~CGetTxPoolParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetTxPoolParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetTxPoolParam> MakeCGetTxPoolParamPtr(Args&&... args)
{
	return std::make_shared<CGetTxPoolParam>(std::forward<Args>(args)...);
}

// CGetTxPoolResult
class CGetTxPoolResult : public CRPCResult
{
public:
	// class CList
	class CList
	{
	public:
		__required__ CRPCString strHex;
		__required__ CRPCUint64 nSize;
	public:
		CList();
		CList(const CRPCString& strHex, const CRPCUint64& nSize);
		CList(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CList& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
public:
	__optional__ CRPCUint64 nCount;
	__optional__ CRPCUint64 nSize;
	__optional__ CRPCVector<CList> vecList;
public:
	CGetTxPoolResult();
	CGetTxPoolResult(const CRPCUint64& nCount, const CRPCUint64& nSize, const CRPCVector<CList>& vecList);
	virtual ~CGetTxPoolResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetTxPoolResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetTxPoolResult> MakeCGetTxPoolResultPtr(Args&&... args)
{
	return std::make_shared<CGetTxPoolResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// gettransaction

// CGetTransactionParam
class CGetTransactionParam : public CRPCParam
{
public:
	__required__ CRPCString strTxid;
	__optional__ CRPCBool fSerialized = false;
public:
	CGetTransactionParam();
	CGetTransactionParam(const CRPCString& strTxid, const CRPCBool& fSerialized);
	virtual ~CGetTransactionParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetTransactionParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetTransactionParam> MakeCGetTransactionParamPtr(Args&&... args)
{
	return std::make_shared<CGetTransactionParam>(std::forward<Args>(args)...);
}

// CGetTransactionResult
class CGetTransactionResult : public CRPCResult
{
public:
	__optional__ CRPCString strSerialization;
	__optional__ CTransactionData transaction;
public:
	CGetTransactionResult();
	CGetTransactionResult(const CRPCString& strSerialization, const CTransactionData& transaction);
	virtual ~CGetTransactionResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetTransactionResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetTransactionResult> MakeCGetTransactionResultPtr(Args&&... args)
{
	return std::make_shared<CGetTransactionResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// sendtransaction

// CSendTransactionParam
class CSendTransactionParam : public CRPCParam
{
public:
	__required__ CRPCString strTxdata;
public:
	CSendTransactionParam();
	CSendTransactionParam(const CRPCString& strTxdata);
	virtual ~CSendTransactionParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CSendTransactionParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CSendTransactionParam> MakeCSendTransactionParamPtr(Args&&... args)
{
	return std::make_shared<CSendTransactionParam>(std::forward<Args>(args)...);
}

// CSendTransactionResult
class CSendTransactionResult : public CRPCResult
{
public:
	__required__ CRPCString strData;
public:
	CSendTransactionResult();
	CSendTransactionResult(const CRPCString& strData);
	virtual ~CSendTransactionResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CSendTransactionResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CSendTransactionResult> MakeCSendTransactionResultPtr(Args&&... args)
{
	return std::make_shared<CSendTransactionResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// getforkheight

// CGetForkHeightParam
class CGetForkHeightParam : public CRPCParam
{
public:
	__optional__ CRPCString strFork;
public:
	CGetForkHeightParam();
	CGetForkHeightParam(const CRPCString& strFork);
	virtual ~CGetForkHeightParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetForkHeightParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetForkHeightParam> MakeCGetForkHeightParamPtr(Args&&... args)
{
	return std::make_shared<CGetForkHeightParam>(std::forward<Args>(args)...);
}

// CGetForkHeightResult
class CGetForkHeightResult : public CRPCResult
{
public:
	__required__ CRPCInt64 nHeight;
public:
	CGetForkHeightResult();
	CGetForkHeightResult(const CRPCInt64& nHeight);
	virtual ~CGetForkHeightResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetForkHeightResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetForkHeightResult> MakeCGetForkHeightResultPtr(Args&&... args)
{
	return std::make_shared<CGetForkHeightResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// listkey

// CListKeyParam
class CListKeyParam : public CRPCParam
{
public:
	CListKeyParam();
	virtual ~CListKeyParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CListKeyParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CListKeyParam> MakeCListKeyParamPtr(Args&&... args)
{
	return std::make_shared<CListKeyParam>(std::forward<Args>(args)...);
}

// CListKeyResult
class CListKeyResult : public CRPCResult
{
public:
	// class CPubkey
	class CPubkey
	{
	public:
		__required__ CRPCString strKey;
		__required__ CRPCInt64 nVersion;
		__required__ CRPCBool fPublic;
		__required__ CRPCBool fLocked;
		__optional__ CRPCInt64 nTimeout;
	public:
		CPubkey();
		CPubkey(const CRPCString& strKey, const CRPCInt64& nVersion, const CRPCBool& fPublic, const CRPCBool& fLocked, const CRPCInt64& nTimeout);
		CPubkey(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CPubkey& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
public:
	__required__ CRPCVector<CPubkey> vecPubkey = RPCValid;
public:
	CListKeyResult();
	CListKeyResult(const CRPCVector<CPubkey>& vecPubkey);
	virtual ~CListKeyResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CListKeyResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CListKeyResult> MakeCListKeyResultPtr(Args&&... args)
{
	return std::make_shared<CListKeyResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// getnewkey

// CGetNewKeyParam
class CGetNewKeyParam : public CRPCParam
{
public:
	__required__ CRPCString strPassphrase;
public:
	CGetNewKeyParam();
	CGetNewKeyParam(const CRPCString& strPassphrase);
	virtual ~CGetNewKeyParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetNewKeyParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetNewKeyParam> MakeCGetNewKeyParamPtr(Args&&... args)
{
	return std::make_shared<CGetNewKeyParam>(std::forward<Args>(args)...);
}

// CGetNewKeyResult
class CGetNewKeyResult : public CRPCResult
{
public:
	__required__ CRPCString strPubkey;
public:
	CGetNewKeyResult();
	CGetNewKeyResult(const CRPCString& strPubkey);
	virtual ~CGetNewKeyResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetNewKeyResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetNewKeyResult> MakeCGetNewKeyResultPtr(Args&&... args)
{
	return std::make_shared<CGetNewKeyResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// encryptkey

// CEncryptKeyParam
class CEncryptKeyParam : public CRPCParam
{
public:
	__required__ CRPCString strPubkey;
	__required__ CRPCString strPassphrase;
	__required__ CRPCString strOldpassphrase;
public:
	CEncryptKeyParam();
	CEncryptKeyParam(const CRPCString& strPubkey, const CRPCString& strPassphrase, const CRPCString& strOldpassphrase);
	virtual ~CEncryptKeyParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CEncryptKeyParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CEncryptKeyParam> MakeCEncryptKeyParamPtr(Args&&... args)
{
	return std::make_shared<CEncryptKeyParam>(std::forward<Args>(args)...);
}

// CEncryptKeyResult
class CEncryptKeyResult : public CRPCResult
{
public:
	__required__ CRPCString strResult;
public:
	CEncryptKeyResult();
	CEncryptKeyResult(const CRPCString& strResult);
	virtual ~CEncryptKeyResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CEncryptKeyResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CEncryptKeyResult> MakeCEncryptKeyResultPtr(Args&&... args)
{
	return std::make_shared<CEncryptKeyResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// lockkey

// CLockKeyParam
class CLockKeyParam : public CRPCParam
{
public:
	__required__ CRPCString strPubkey;
public:
	CLockKeyParam();
	CLockKeyParam(const CRPCString& strPubkey);
	virtual ~CLockKeyParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CLockKeyParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CLockKeyParam> MakeCLockKeyParamPtr(Args&&... args)
{
	return std::make_shared<CLockKeyParam>(std::forward<Args>(args)...);
}

// CLockKeyResult
class CLockKeyResult : public CRPCResult
{
public:
	__required__ CRPCString strResult;
public:
	CLockKeyResult();
	CLockKeyResult(const CRPCString& strResult);
	virtual ~CLockKeyResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CLockKeyResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CLockKeyResult> MakeCLockKeyResultPtr(Args&&... args)
{
	return std::make_shared<CLockKeyResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// unlockkey

// CUnlockKeyParam
class CUnlockKeyParam : public CRPCParam
{
public:
	__required__ CRPCString strPubkey;
	__required__ CRPCString strPassphrase;
	__optional__ CRPCInt64 nTimeout;
public:
	CUnlockKeyParam();
	CUnlockKeyParam(const CRPCString& strPubkey, const CRPCString& strPassphrase, const CRPCInt64& nTimeout);
	virtual ~CUnlockKeyParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CUnlockKeyParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CUnlockKeyParam> MakeCUnlockKeyParamPtr(Args&&... args)
{
	return std::make_shared<CUnlockKeyParam>(std::forward<Args>(args)...);
}

// CUnlockKeyResult
class CUnlockKeyResult : public CRPCResult
{
public:
	__required__ CRPCString strResult;
public:
	CUnlockKeyResult();
	CUnlockKeyResult(const CRPCString& strResult);
	virtual ~CUnlockKeyResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CUnlockKeyResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CUnlockKeyResult> MakeCUnlockKeyResultPtr(Args&&... args)
{
	return std::make_shared<CUnlockKeyResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// importprivkey

// CImportPrivKeyParam
class CImportPrivKeyParam : public CRPCParam
{
public:
	__required__ CRPCString strPrivkey;
	__required__ CRPCString strPassphrase;
	__optional__ CRPCBool fSynctx = true;
public:
	CImportPrivKeyParam();
	CImportPrivKeyParam(const CRPCString& strPrivkey, const CRPCString& strPassphrase, const CRPCBool& fSynctx);
	virtual ~CImportPrivKeyParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CImportPrivKeyParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CImportPrivKeyParam> MakeCImportPrivKeyParamPtr(Args&&... args)
{
	return std::make_shared<CImportPrivKeyParam>(std::forward<Args>(args)...);
}

// CImportPrivKeyResult
class CImportPrivKeyResult : public CRPCResult
{
public:
	__required__ CRPCString strPubkey;
public:
	CImportPrivKeyResult();
	CImportPrivKeyResult(const CRPCString& strPubkey);
	virtual ~CImportPrivKeyResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CImportPrivKeyResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CImportPrivKeyResult> MakeCImportPrivKeyResultPtr(Args&&... args)
{
	return std::make_shared<CImportPrivKeyResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// importpubkey

// CImportPubKeyParam
class CImportPubKeyParam : public CRPCParam
{
public:
	__required__ CRPCString strPubkey;
public:
	CImportPubKeyParam();
	CImportPubKeyParam(const CRPCString& strPubkey);
	virtual ~CImportPubKeyParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CImportPubKeyParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CImportPubKeyParam> MakeCImportPubKeyParamPtr(Args&&... args)
{
	return std::make_shared<CImportPubKeyParam>(std::forward<Args>(args)...);
}

// CImportPubKeyResult
class CImportPubKeyResult : public CRPCResult
{
public:
	__required__ CRPCString strAddress;
public:
	CImportPubKeyResult();
	CImportPubKeyResult(const CRPCString& strAddress);
	virtual ~CImportPubKeyResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CImportPubKeyResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CImportPubKeyResult> MakeCImportPubKeyResultPtr(Args&&... args)
{
	return std::make_shared<CImportPubKeyResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// importkey

// CImportKeyParam
class CImportKeyParam : public CRPCParam
{
public:
	__required__ CRPCString strPubkey;
	__optional__ CRPCBool fSynctx = true;
public:
	CImportKeyParam();
	CImportKeyParam(const CRPCString& strPubkey, const CRPCBool& fSynctx);
	virtual ~CImportKeyParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CImportKeyParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CImportKeyParam> MakeCImportKeyParamPtr(Args&&... args)
{
	return std::make_shared<CImportKeyParam>(std::forward<Args>(args)...);
}

// CImportKeyResult
class CImportKeyResult : public CRPCResult
{
public:
	__required__ CRPCString strPubkey;
public:
	CImportKeyResult();
	CImportKeyResult(const CRPCString& strPubkey);
	virtual ~CImportKeyResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CImportKeyResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CImportKeyResult> MakeCImportKeyResultPtr(Args&&... args)
{
	return std::make_shared<CImportKeyResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// exportkey

// CExportKeyParam
class CExportKeyParam : public CRPCParam
{
public:
	__required__ CRPCString strPubkey;
public:
	CExportKeyParam();
	CExportKeyParam(const CRPCString& strPubkey);
	virtual ~CExportKeyParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CExportKeyParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CExportKeyParam> MakeCExportKeyParamPtr(Args&&... args)
{
	return std::make_shared<CExportKeyParam>(std::forward<Args>(args)...);
}

// CExportKeyResult
class CExportKeyResult : public CRPCResult
{
public:
	__required__ CRPCString strPubkey;
public:
	CExportKeyResult();
	CExportKeyResult(const CRPCString& strPubkey);
	virtual ~CExportKeyResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CExportKeyResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CExportKeyResult> MakeCExportKeyResultPtr(Args&&... args)
{
	return std::make_shared<CExportKeyResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// addnewtemplate

// CAddNewTemplateParam
class CAddNewTemplateParam : public CRPCParam
{
public:
	__required__ CTemplateRequest data;
public:
	CAddNewTemplateParam();
	CAddNewTemplateParam(const CTemplateRequest& data);
	virtual ~CAddNewTemplateParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CAddNewTemplateParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CAddNewTemplateParam> MakeCAddNewTemplateParamPtr(Args&&... args)
{
	return std::make_shared<CAddNewTemplateParam>(std::forward<Args>(args)...);
}

// CAddNewTemplateResult
class CAddNewTemplateResult : public CRPCResult
{
public:
	__required__ CRPCString strAddress;
public:
	CAddNewTemplateResult();
	CAddNewTemplateResult(const CRPCString& strAddress);
	virtual ~CAddNewTemplateResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CAddNewTemplateResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CAddNewTemplateResult> MakeCAddNewTemplateResultPtr(Args&&... args)
{
	return std::make_shared<CAddNewTemplateResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// importtemplate

// CImportTemplateParam
class CImportTemplateParam : public CRPCParam
{
public:
	__required__ CRPCString strData;
	__optional__ CRPCBool fSynctx = true;
public:
	CImportTemplateParam();
	CImportTemplateParam(const CRPCString& strData, const CRPCBool& fSynctx);
	virtual ~CImportTemplateParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CImportTemplateParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CImportTemplateParam> MakeCImportTemplateParamPtr(Args&&... args)
{
	return std::make_shared<CImportTemplateParam>(std::forward<Args>(args)...);
}

// CImportTemplateResult
class CImportTemplateResult : public CRPCResult
{
public:
	__required__ CRPCString strAddress;
public:
	CImportTemplateResult();
	CImportTemplateResult(const CRPCString& strAddress);
	virtual ~CImportTemplateResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CImportTemplateResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CImportTemplateResult> MakeCImportTemplateResultPtr(Args&&... args)
{
	return std::make_shared<CImportTemplateResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// exporttemplate

// CExportTemplateParam
class CExportTemplateParam : public CRPCParam
{
public:
	__required__ CRPCString strAddress;
public:
	CExportTemplateParam();
	CExportTemplateParam(const CRPCString& strAddress);
	virtual ~CExportTemplateParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CExportTemplateParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CExportTemplateParam> MakeCExportTemplateParamPtr(Args&&... args)
{
	return std::make_shared<CExportTemplateParam>(std::forward<Args>(args)...);
}

// CExportTemplateResult
class CExportTemplateResult : public CRPCResult
{
public:
	__required__ CRPCString strData;
public:
	CExportTemplateResult();
	CExportTemplateResult(const CRPCString& strData);
	virtual ~CExportTemplateResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CExportTemplateResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CExportTemplateResult> MakeCExportTemplateResultPtr(Args&&... args)
{
	return std::make_shared<CExportTemplateResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// validateaddress

// CValidateAddressParam
class CValidateAddressParam : public CRPCParam
{
public:
	__required__ CRPCString strAddress;
public:
	CValidateAddressParam();
	CValidateAddressParam(const CRPCString& strAddress);
	virtual ~CValidateAddressParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CValidateAddressParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CValidateAddressParam> MakeCValidateAddressParamPtr(Args&&... args)
{
	return std::make_shared<CValidateAddressParam>(std::forward<Args>(args)...);
}

// CValidateAddressResult
class CValidateAddressResult : public CRPCResult
{
public:
	// class CAddressdata
	class CAddressdata
	{
	public:
		__required__ CRPCString strAddress;
		__required__ CRPCBool fIsmine;
		__required__ CRPCString strType;
		__required__ CRPCString strPubkey;
		__required__ CRPCString strTemplate;
		__required__ CTemplateResponse templatedata;
	public:
		CAddressdata();
		CAddressdata(const CRPCString& strAddress, const CRPCBool& fIsmine, const CRPCString& strType, const CRPCString& strPubkey, const CRPCString& strTemplate, const CTemplateResponse& templatedata);
		CAddressdata(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CAddressdata& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
public:
	__required__ CRPCBool fIsvalid;
	__required__ CAddressdata addressdata;
public:
	CValidateAddressResult();
	CValidateAddressResult(const CRPCBool& fIsvalid, const CAddressdata& addressdata);
	virtual ~CValidateAddressResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CValidateAddressResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CValidateAddressResult> MakeCValidateAddressResultPtr(Args&&... args)
{
	return std::make_shared<CValidateAddressResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// resyncwallet

// CResyncWalletParam
class CResyncWalletParam : public CRPCParam
{
public:
	__optional__ CRPCString strAddress;
public:
	CResyncWalletParam();
	CResyncWalletParam(const CRPCString& strAddress);
	virtual ~CResyncWalletParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CResyncWalletParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CResyncWalletParam> MakeCResyncWalletParamPtr(Args&&... args)
{
	return std::make_shared<CResyncWalletParam>(std::forward<Args>(args)...);
}

// CResyncWalletResult
class CResyncWalletResult : public CRPCResult
{
public:
	__required__ CRPCString strResult;
public:
	CResyncWalletResult();
	CResyncWalletResult(const CRPCString& strResult);
	virtual ~CResyncWalletResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CResyncWalletResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CResyncWalletResult> MakeCResyncWalletResultPtr(Args&&... args)
{
	return std::make_shared<CResyncWalletResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// getbalance

// CGetBalanceParam
class CGetBalanceParam : public CRPCParam
{
public:
	__optional__ CRPCString strFork;
	__optional__ CRPCString strAddress;
public:
	CGetBalanceParam();
	CGetBalanceParam(const CRPCString& strFork, const CRPCString& strAddress);
	virtual ~CGetBalanceParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetBalanceParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetBalanceParam> MakeCGetBalanceParamPtr(Args&&... args)
{
	return std::make_shared<CGetBalanceParam>(std::forward<Args>(args)...);
}

// CGetBalanceResult
class CGetBalanceResult : public CRPCResult
{
public:
	// class CBalance
	class CBalance
	{
	public:
		__required__ CRPCString strAddress;
		__required__ CRPCDouble dAvail;
		__required__ CRPCDouble dLocked;
		__required__ CRPCDouble dUnconfirmed;
	public:
		CBalance();
		CBalance(const CRPCString& strAddress, const CRPCDouble& dAvail, const CRPCDouble& dLocked, const CRPCDouble& dUnconfirmed);
		CBalance(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CBalance& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
public:
	__required__ CRPCVector<CBalance> vecBalance = RPCValid;
public:
	CGetBalanceResult();
	CGetBalanceResult(const CRPCVector<CBalance>& vecBalance);
	virtual ~CGetBalanceResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetBalanceResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetBalanceResult> MakeCGetBalanceResultPtr(Args&&... args)
{
	return std::make_shared<CGetBalanceResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// listtransaction

// CListTransactionParam
class CListTransactionParam : public CRPCParam
{
public:
	__optional__ CRPCUint64 nCount;
	__optional__ CRPCInt64 nOffset;
	__optional__ CRPCString strFork;
	__optional__ CRPCString strAddress;
public:
	CListTransactionParam();
	CListTransactionParam(const CRPCUint64& nCount, const CRPCInt64& nOffset, const CRPCString& strFork, const CRPCString& strAddress);
	virtual ~CListTransactionParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CListTransactionParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CListTransactionParam> MakeCListTransactionParamPtr(Args&&... args)
{
	return std::make_shared<CListTransactionParam>(std::forward<Args>(args)...);
}

// CListTransactionResult
class CListTransactionResult : public CRPCResult
{
public:
	__required__ CRPCVector<CWalletTxData> vecTransaction = RPCValid;
public:
	CListTransactionResult();
	CListTransactionResult(const CRPCVector<CWalletTxData>& vecTransaction);
	virtual ~CListTransactionResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CListTransactionResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CListTransactionResult> MakeCListTransactionResultPtr(Args&&... args)
{
	return std::make_shared<CListTransactionResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// sendfrom

// CSendFromParam
class CSendFromParam : public CRPCParam
{
public:
	__required__ CRPCString strFrom;
	__required__ CRPCString strTo;
	__required__ CRPCDouble dAmount;
	__optional__ CRPCDouble dTxfee;
	__optional__ CRPCString strFork;
	__optional__ CRPCString strData;
	__optional__ CRPCString strSign_M;
	__optional__ CRPCString strSign_S;
	__optional__ CRPCString strSendtodata;
public:
	CSendFromParam();
	CSendFromParam(const CRPCString& strFrom, const CRPCString& strTo, const CRPCDouble& dAmount, const CRPCDouble& dTxfee, const CRPCString& strFork, const CRPCString& strData, const CRPCString& strSign_M, const CRPCString& strSign_S, const CRPCString& strSendtodata);
	virtual ~CSendFromParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CSendFromParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CSendFromParam> MakeCSendFromParamPtr(Args&&... args)
{
	return std::make_shared<CSendFromParam>(std::forward<Args>(args)...);
}

// CSendFromResult
class CSendFromResult : public CRPCResult
{
public:
	__required__ CRPCString strTransaction;
public:
	CSendFromResult();
	CSendFromResult(const CRPCString& strTransaction);
	virtual ~CSendFromResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CSendFromResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CSendFromResult> MakeCSendFromResultPtr(Args&&... args)
{
	return std::make_shared<CSendFromResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// createtransaction

// CCreateTransactionParam
class CCreateTransactionParam : public CRPCParam
{
public:
	__required__ CRPCString strFrom;
	__required__ CRPCString strTo;
	__required__ CRPCDouble dAmount;
	__optional__ CRPCDouble dTxfee;
	__optional__ CRPCString strFork;
	__optional__ CRPCString strData;
public:
	CCreateTransactionParam();
	CCreateTransactionParam(const CRPCString& strFrom, const CRPCString& strTo, const CRPCDouble& dAmount, const CRPCDouble& dTxfee, const CRPCString& strFork, const CRPCString& strData);
	virtual ~CCreateTransactionParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CCreateTransactionParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CCreateTransactionParam> MakeCCreateTransactionParamPtr(Args&&... args)
{
	return std::make_shared<CCreateTransactionParam>(std::forward<Args>(args)...);
}

// CCreateTransactionResult
class CCreateTransactionResult : public CRPCResult
{
public:
	__required__ CRPCString strTransaction;
public:
	CCreateTransactionResult();
	CCreateTransactionResult(const CRPCString& strTransaction);
	virtual ~CCreateTransactionResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CCreateTransactionResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CCreateTransactionResult> MakeCCreateTransactionResultPtr(Args&&... args)
{
	return std::make_shared<CCreateTransactionResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// signtransaction

// CSignTransactionParam
class CSignTransactionParam : public CRPCParam
{
public:
	__required__ CRPCString strTxdata;
	__optional__ CRPCString strSendtodata;
public:
	CSignTransactionParam();
	CSignTransactionParam(const CRPCString& strTxdata, const CRPCString& strSendtodata);
	virtual ~CSignTransactionParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CSignTransactionParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CSignTransactionParam> MakeCSignTransactionParamPtr(Args&&... args)
{
	return std::make_shared<CSignTransactionParam>(std::forward<Args>(args)...);
}

// CSignTransactionResult
class CSignTransactionResult : public CRPCResult
{
public:
	__required__ CRPCString strHex;
	__required__ CRPCBool fCompleted;
public:
	CSignTransactionResult();
	CSignTransactionResult(const CRPCString& strHex, const CRPCBool& fCompleted);
	virtual ~CSignTransactionResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CSignTransactionResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CSignTransactionResult> MakeCSignTransactionResultPtr(Args&&... args)
{
	return std::make_shared<CSignTransactionResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// signmessage

// CSignMessageParam
class CSignMessageParam : public CRPCParam
{
public:
	__required__ CRPCString strPubkey;
	__required__ CRPCString strMessage;
	__optional__ CRPCString strAddr;
public:
	CSignMessageParam();
	CSignMessageParam(const CRPCString& strPubkey, const CRPCString& strMessage, const CRPCString& strAddr);
	virtual ~CSignMessageParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CSignMessageParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CSignMessageParam> MakeCSignMessageParamPtr(Args&&... args)
{
	return std::make_shared<CSignMessageParam>(std::forward<Args>(args)...);
}

// CSignMessageResult
class CSignMessageResult : public CRPCResult
{
public:
	__required__ CRPCString strSignature;
public:
	CSignMessageResult();
	CSignMessageResult(const CRPCString& strSignature);
	virtual ~CSignMessageResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CSignMessageResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CSignMessageResult> MakeCSignMessageResultPtr(Args&&... args)
{
	return std::make_shared<CSignMessageResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// listaddress

// CListAddressParam
class CListAddressParam : public CRPCParam
{
public:
	CListAddressParam();
	virtual ~CListAddressParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CListAddressParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CListAddressParam> MakeCListAddressParamPtr(Args&&... args)
{
	return std::make_shared<CListAddressParam>(std::forward<Args>(args)...);
}

// CListAddressResult
class CListAddressResult : public CRPCResult
{
public:
	// class CAddressdata
	class CAddressdata
	{
	public:
		__required__ CRPCString strType;
		__required__ CRPCString strAddress;
		__required__ CRPCString strPubkey;
		__required__ CRPCString strTemplate;
		__required__ CTemplateResponse templatedata;
	public:
		CAddressdata();
		CAddressdata(const CRPCString& strType, const CRPCString& strAddress, const CRPCString& strPubkey, const CRPCString& strTemplate, const CTemplateResponse& templatedata);
		CAddressdata(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CAddressdata& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
public:
	__required__ CRPCVector<CAddressdata> vecAddressdata = RPCValid;
public:
	CListAddressResult();
	CListAddressResult(const CRPCVector<CAddressdata>& vecAddressdata);
	virtual ~CListAddressResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CListAddressResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CListAddressResult> MakeCListAddressResultPtr(Args&&... args)
{
	return std::make_shared<CListAddressResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// exportwallet

// CExportWalletParam
class CExportWalletParam : public CRPCParam
{
public:
	__required__ CRPCString strPath;
public:
	CExportWalletParam();
	CExportWalletParam(const CRPCString& strPath);
	virtual ~CExportWalletParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CExportWalletParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CExportWalletParam> MakeCExportWalletParamPtr(Args&&... args)
{
	return std::make_shared<CExportWalletParam>(std::forward<Args>(args)...);
}

// CExportWalletResult
class CExportWalletResult : public CRPCResult
{
public:
	__required__ CRPCString strResult;
public:
	CExportWalletResult();
	CExportWalletResult(const CRPCString& strResult);
	virtual ~CExportWalletResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CExportWalletResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CExportWalletResult> MakeCExportWalletResultPtr(Args&&... args)
{
	return std::make_shared<CExportWalletResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// importwallet

// CImportWalletParam
class CImportWalletParam : public CRPCParam
{
public:
	__required__ CRPCString strPath;
public:
	CImportWalletParam();
	CImportWalletParam(const CRPCString& strPath);
	virtual ~CImportWalletParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CImportWalletParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CImportWalletParam> MakeCImportWalletParamPtr(Args&&... args)
{
	return std::make_shared<CImportWalletParam>(std::forward<Args>(args)...);
}

// CImportWalletResult
class CImportWalletResult : public CRPCResult
{
public:
	__required__ CRPCString strResult;
public:
	CImportWalletResult();
	CImportWalletResult(const CRPCString& strResult);
	virtual ~CImportWalletResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CImportWalletResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CImportWalletResult> MakeCImportWalletResultPtr(Args&&... args)
{
	return std::make_shared<CImportWalletResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// verifymessage

// CVerifyMessageParam
class CVerifyMessageParam : public CRPCParam
{
public:
	__required__ CRPCString strPubkey;
	__required__ CRPCString strMessage;
	__required__ CRPCString strSig;
	__optional__ CRPCString strAddr;
public:
	CVerifyMessageParam();
	CVerifyMessageParam(const CRPCString& strPubkey, const CRPCString& strMessage, const CRPCString& strSig, const CRPCString& strAddr);
	virtual ~CVerifyMessageParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CVerifyMessageParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CVerifyMessageParam> MakeCVerifyMessageParamPtr(Args&&... args)
{
	return std::make_shared<CVerifyMessageParam>(std::forward<Args>(args)...);
}

// CVerifyMessageResult
class CVerifyMessageResult : public CRPCResult
{
public:
	__required__ CRPCBool fResult;
public:
	CVerifyMessageResult();
	CVerifyMessageResult(const CRPCBool& fResult);
	virtual ~CVerifyMessageResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CVerifyMessageResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CVerifyMessageResult> MakeCVerifyMessageResultPtr(Args&&... args)
{
	return std::make_shared<CVerifyMessageResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// makekeypair

// CMakeKeyPairParam
class CMakeKeyPairParam : public CRPCParam
{
public:
	CMakeKeyPairParam();
	virtual ~CMakeKeyPairParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CMakeKeyPairParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CMakeKeyPairParam> MakeCMakeKeyPairParamPtr(Args&&... args)
{
	return std::make_shared<CMakeKeyPairParam>(std::forward<Args>(args)...);
}

// CMakeKeyPairResult
class CMakeKeyPairResult : public CRPCResult
{
public:
	__required__ CRPCString strPrivkey;
	__required__ CRPCString strPubkey;
public:
	CMakeKeyPairResult();
	CMakeKeyPairResult(const CRPCString& strPrivkey, const CRPCString& strPubkey);
	virtual ~CMakeKeyPairResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CMakeKeyPairResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CMakeKeyPairResult> MakeCMakeKeyPairResultPtr(Args&&... args)
{
	return std::make_shared<CMakeKeyPairResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// getpubkeyaddress

// CGetPubkeyAddressParam
class CGetPubkeyAddressParam : public CRPCParam
{
public:
	__required__ CRPCString strPubkey;
	__optional__ CRPCString strReversal;
public:
	CGetPubkeyAddressParam();
	CGetPubkeyAddressParam(const CRPCString& strPubkey, const CRPCString& strReversal);
	virtual ~CGetPubkeyAddressParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetPubkeyAddressParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetPubkeyAddressParam> MakeCGetPubkeyAddressParamPtr(Args&&... args)
{
	return std::make_shared<CGetPubkeyAddressParam>(std::forward<Args>(args)...);
}

// CGetPubkeyAddressResult
class CGetPubkeyAddressResult : public CRPCResult
{
public:
	__required__ CRPCString strAddress;
public:
	CGetPubkeyAddressResult();
	CGetPubkeyAddressResult(const CRPCString& strAddress);
	virtual ~CGetPubkeyAddressResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetPubkeyAddressResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetPubkeyAddressResult> MakeCGetPubkeyAddressResultPtr(Args&&... args)
{
	return std::make_shared<CGetPubkeyAddressResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// gettemplateaddress

// CGetTemplateAddressParam
class CGetTemplateAddressParam : public CRPCParam
{
public:
	__required__ CRPCString strTid;
public:
	CGetTemplateAddressParam();
	CGetTemplateAddressParam(const CRPCString& strTid);
	virtual ~CGetTemplateAddressParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetTemplateAddressParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetTemplateAddressParam> MakeCGetTemplateAddressParamPtr(Args&&... args)
{
	return std::make_shared<CGetTemplateAddressParam>(std::forward<Args>(args)...);
}

// CGetTemplateAddressResult
class CGetTemplateAddressResult : public CRPCResult
{
public:
	__required__ CRPCString strAddress;
public:
	CGetTemplateAddressResult();
	CGetTemplateAddressResult(const CRPCString& strAddress);
	virtual ~CGetTemplateAddressResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetTemplateAddressResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetTemplateAddressResult> MakeCGetTemplateAddressResultPtr(Args&&... args)
{
	return std::make_shared<CGetTemplateAddressResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// maketemplate

// CMakeTemplateParam
class CMakeTemplateParam : public CRPCParam
{
public:
	__required__ CTemplateRequest data;
public:
	CMakeTemplateParam();
	CMakeTemplateParam(const CTemplateRequest& data);
	virtual ~CMakeTemplateParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CMakeTemplateParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CMakeTemplateParam> MakeCMakeTemplateParamPtr(Args&&... args)
{
	return std::make_shared<CMakeTemplateParam>(std::forward<Args>(args)...);
}

// CMakeTemplateResult
class CMakeTemplateResult : public CRPCResult
{
public:
	__required__ CRPCString strAddress;
	__required__ CRPCString strHex;
public:
	CMakeTemplateResult();
	CMakeTemplateResult(const CRPCString& strAddress, const CRPCString& strHex);
	virtual ~CMakeTemplateResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CMakeTemplateResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CMakeTemplateResult> MakeCMakeTemplateResultPtr(Args&&... args)
{
	return std::make_shared<CMakeTemplateResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// decodetransaction

// CDecodeTransactionParam
class CDecodeTransactionParam : public CRPCParam
{
public:
	__required__ CRPCString strTxdata;
public:
	CDecodeTransactionParam();
	CDecodeTransactionParam(const CRPCString& strTxdata);
	virtual ~CDecodeTransactionParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CDecodeTransactionParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CDecodeTransactionParam> MakeCDecodeTransactionParamPtr(Args&&... args)
{
	return std::make_shared<CDecodeTransactionParam>(std::forward<Args>(args)...);
}

// CDecodeTransactionResult
class CDecodeTransactionResult : public CRPCResult
{
public:
	__required__ CTransactionData transaction;
public:
	CDecodeTransactionResult();
	CDecodeTransactionResult(const CTransactionData& transaction);
	virtual ~CDecodeTransactionResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CDecodeTransactionResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CDecodeTransactionResult> MakeCDecodeTransactionResultPtr(Args&&... args)
{
	return std::make_shared<CDecodeTransactionResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// listunspent

// CListUnspentParam
class CListUnspentParam : public CRPCParam
{
public:
	__required__ CRPCString strAddress;
	__optional__ CRPCString strFork;
	__optional__ CRPCUint64 nMax = 10;
	__optional__ CRPCString strFile;
public:
	CListUnspentParam();
	CListUnspentParam(const CRPCString& strAddress, const CRPCString& strFork, const CRPCUint64& nMax, const CRPCString& strFile);
	virtual ~CListUnspentParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CListUnspentParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CListUnspentParam> MakeCListUnspentParamPtr(Args&&... args)
{
	return std::make_shared<CListUnspentParam>(std::forward<Args>(args)...);
}

// CListUnspentResult
class CListUnspentResult : public CRPCResult
{
public:
	// class CAddresses
	class CAddresses
	{
	public:
		__required__ CRPCString strAddress;
		__required__ CRPCVector<CUnspentData> vecUnspents = RPCValid;
		__required__ CRPCDouble dSum;
	public:
		CAddresses();
		CAddresses(const CRPCString& strAddress, const CRPCVector<CUnspentData>& vecUnspents, const CRPCDouble& dSum);
		CAddresses(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CAddresses& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
public:
	__required__ CRPCVector<CAddresses> vecAddresses = RPCValid;
	__required__ CRPCDouble dTotal;
public:
	CListUnspentResult();
	CListUnspentResult(const CRPCVector<CAddresses>& vecAddresses, const CRPCDouble& dTotal);
	virtual ~CListUnspentResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CListUnspentResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CListUnspentResult> MakeCListUnspentResultPtr(Args&&... args)
{
	return std::make_shared<CListUnspentResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// getwork

// CGetWorkParam
class CGetWorkParam : public CRPCParam
{
public:
	__required__ CRPCString strSpent;
	__required__ CRPCString strPrivkey;
	__optional__ CRPCString strPrev;
public:
	CGetWorkParam();
	CGetWorkParam(const CRPCString& strSpent, const CRPCString& strPrivkey, const CRPCString& strPrev);
	virtual ~CGetWorkParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetWorkParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetWorkParam> MakeCGetWorkParamPtr(Args&&... args)
{
	return std::make_shared<CGetWorkParam>(std::forward<Args>(args)...);
}

// CGetWorkResult
class CGetWorkResult : public CRPCResult
{
public:
	// class CWork
	class CWork
	{
	public:
		__required__ CRPCInt64 nPrevblockheight;
		__required__ CRPCString strPrevblockhash;
		__required__ CRPCUint64 nPrevblocktime;
		__required__ CRPCInt64 nAlgo;
		__required__ CRPCString strBits;
		__required__ CRPCString strData;
	public:
		CWork();
		CWork(const CRPCInt64& nPrevblockheight, const CRPCString& strPrevblockhash, const CRPCUint64& nPrevblocktime, const CRPCInt64& nAlgo, const CRPCString& strBits, const CRPCString& strData);
		CWork(const CRPCType& type);
		json_spirit::Value ToJSON() const;
		CWork& FromJSON(const json_spirit::Value& v);
		bool IsValid() const;
	};
public:
	__optional__ CRPCBool fResult;
	__optional__ CWork work;
public:
	CGetWorkResult();
	CGetWorkResult(const CRPCBool& fResult, const CWork& work);
	virtual ~CGetWorkResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CGetWorkResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CGetWorkResult> MakeCGetWorkResultPtr(Args&&... args)
{
	return std::make_shared<CGetWorkResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// submitwork

// CSubmitWorkParam
class CSubmitWorkParam : public CRPCParam
{
public:
	__required__ CRPCString strData;
	__required__ CRPCString strSpent;
	__required__ CRPCString strPrivkey;
public:
	CSubmitWorkParam();
	CSubmitWorkParam(const CRPCString& strData, const CRPCString& strSpent, const CRPCString& strPrivkey);
	virtual ~CSubmitWorkParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CSubmitWorkParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CSubmitWorkParam> MakeCSubmitWorkParamPtr(Args&&... args)
{
	return std::make_shared<CSubmitWorkParam>(std::forward<Args>(args)...);
}

// CSubmitWorkResult
class CSubmitWorkResult : public CRPCResult
{
public:
	__required__ CRPCString strHash;
public:
	CSubmitWorkResult();
	CSubmitWorkResult(const CRPCString& strHash);
	virtual ~CSubmitWorkResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CSubmitWorkResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CSubmitWorkResult> MakeCSubmitWorkResultPtr(Args&&... args)
{
	return std::make_shared<CSubmitWorkResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// querystat

// CQueryStatParam
class CQueryStatParam : public CRPCParam
{
public:
	__required__ CRPCString strType;
	__optional__ CRPCString strFork;
	__optional__ CRPCString strBegin;
	__optional__ CRPCUint64 nCount;
public:
	CQueryStatParam();
	CQueryStatParam(const CRPCString& strType, const CRPCString& strFork, const CRPCString& strBegin, const CRPCUint64& nCount);
	virtual ~CQueryStatParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CQueryStatParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CQueryStatParam> MakeCQueryStatParamPtr(Args&&... args)
{
	return std::make_shared<CQueryStatParam>(std::forward<Args>(args)...);
}

// CQueryStatResult
class CQueryStatResult : public CRPCResult
{
public:
	__required__ CRPCString strStattable;
public:
	CQueryStatResult();
	CQueryStatResult(const CRPCString& strStattable);
	virtual ~CQueryStatResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CQueryStatResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CQueryStatResult> MakeCQueryStatResultPtr(Args&&... args)
{
	return std::make_shared<CQueryStatResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// signrawtransactionwithwallet

// CSignRawTransactionWithWalletParam
class CSignRawTransactionWithWalletParam : public CRPCParam
{
public:
	__required__ CRPCString strAddrin;
	__required__ CRPCString strTxdata;
public:
	CSignRawTransactionWithWalletParam();
	CSignRawTransactionWithWalletParam(const CRPCString& strAddrin, const CRPCString& strTxdata);
	virtual ~CSignRawTransactionWithWalletParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CSignRawTransactionWithWalletParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CSignRawTransactionWithWalletParam> MakeCSignRawTransactionWithWalletParamPtr(Args&&... args)
{
	return std::make_shared<CSignRawTransactionWithWalletParam>(std::forward<Args>(args)...);
}

// CSignRawTransactionWithWalletResult
class CSignRawTransactionWithWalletResult : public CRPCResult
{
public:
	__required__ CRPCString strHex;
	__required__ CRPCBool fCompleted;
public:
	CSignRawTransactionWithWalletResult();
	CSignRawTransactionWithWalletResult(const CRPCString& strHex, const CRPCBool& fCompleted);
	virtual ~CSignRawTransactionWithWalletResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CSignRawTransactionWithWalletResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CSignRawTransactionWithWalletResult> MakeCSignRawTransactionWithWalletResultPtr(Args&&... args)
{
	return std::make_shared<CSignRawTransactionWithWalletResult>(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////
// sendrawtransaction

// CSendRawTransactionParam
class CSendRawTransactionParam : public CRPCParam
{
public:
	__required__ CRPCString strTxdata;
public:
	CSendRawTransactionParam();
	CSendRawTransactionParam(const CRPCString& strTxdata);
	virtual ~CSendRawTransactionParam() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CSendRawTransactionParam& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CSendRawTransactionParam> MakeCSendRawTransactionParamPtr(Args&&... args)
{
	return std::make_shared<CSendRawTransactionParam>(std::forward<Args>(args)...);
}

// CSendRawTransactionResult
class CSendRawTransactionResult : public CRPCResult
{
public:
	__required__ CRPCString strData;
public:
	CSendRawTransactionResult();
	CSendRawTransactionResult(const CRPCString& strData);
	virtual ~CSendRawTransactionResult() = default;
	virtual json_spirit::Value ToJSON() const;
	virtual CSendRawTransactionResult& FromJSON(const json_spirit::Value& v);
	virtual std::string Method() const;
};
template <typename... Args>
std::shared_ptr<CSendRawTransactionResult> MakeCSendRawTransactionResultPtr(Args&&... args)
{
	return std::make_shared<CSendRawTransactionResult>(std::forward<Args>(args)...);
}

// Create family class shared ptr of CRPCParam
CRPCParamPtr CreateCRPCParam(const std::string& cmd, const json_spirit::Value& valParam);

// Create family class shared ptr of CRPCResult
CRPCResultPtr CreateCRPCResult(const std::string& cmd, const json_spirit::Value& valResult);

// All rpc command list
const std::vector<std::string>& RPCCmdList();

// help tips used when error occured on client
static const std::string strClientHelpTips = "\nRun 'COMMAND -help' for more information on a command.\n";
// help tips used when error occured on server
static const std::string strServerHelpTips = "\nRun 'help COMMAND' for more information on a command.\n";

#undef __required__
#undef __optional__

#ifdef PUSHED_MACRO_REQUIRED
#pragma pop_macro("__required__")
#endif

#ifdef PUSHED_MACRO_OPTIONAL
#pragma pop_macro("__optional__")
#endif

}  // namespace rpc
}  // namespace bigbang

#endif  // BIGBANG_RPC_AUTO_PROTOCOL_H
