// Copyright (c) 2019-2020 The Bigbang developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#include "auto_protocol.h"

#include <sstream>
#include <cmath>

#include "json/json_spirit_reader_template.h"
#include "json/json_spirit_utils.h"

using namespace std;
using namespace json_spirit;

namespace bigbang
{
namespace rpc
{
static void CheckJSONType(const Value& value, const string& type, const string& key)
{
	bool b;
	if (type == "int")
	{
		b = (value.type() == int_type);
	}
	else if (type == "uint")
	{
		b = ((value.type() == int_type) && (value.is_uint64() || value.get_int64() >= 0));
	}
	else if (type == "double")
	{
		b = ((value.type() == real_type) || (value.type() == int_type));
	}
	else if (type == "bool")
	{
		b = (value.type() == bool_type);
	}
	else if (type == "string")
	{
		b = (value.type() == str_type);
	}
	else if (type == "array")
	{
		b = (value.type() == array_type);
	}
	else if (type == "object")
	{
		b = (value.type() == obj_type);
	}
	else 
	{
		b = false;
	}
	if (!b)
	{
		throw CRPCException(RPC_INVALID_PARAMS, string("[") + key + "] type is not " + type);
	}
}
template <typename T>
static void CheckIsValid(const T& value, const string& key)
{
	if (!value.IsValid())
	{
		throw CRPCException(RPC_INVALID_PARAMS, string("required param [") + key + "] is not valid");
	}
}

// CUnspentData
CUnspentData::CUnspentData() {}
CUnspentData::CUnspentData(const CRPCString& strTxid, const CRPCUint64& nOut, const CRPCDouble& dAmount, const CRPCUint64& nTime, const CRPCUint64& nLockuntil)
	: strTxid(strTxid), nOut(nOut), dAmount(dAmount), nTime(nTime), nLockuntil(nLockuntil)
{
}
CUnspentData::CUnspentData(const CRPCType& null)
	: strTxid(null), nOut(null), dAmount(null), nTime(null), nLockuntil(null)
{
}
Value CUnspentData::ToJSON() const
{
	Object ret;
	CheckIsValid(strTxid, "strTxid");
	ret.push_back(Pair("txid", std::string(strTxid)));
	CheckIsValid(nOut, "nOut");
	ret.push_back(Pair("out", uint64(nOut)));
	CheckIsValid(dAmount, "dAmount");
	ret.push_back(Pair("amount", double(dAmount)));
	CheckIsValid(nTime, "nTime");
	ret.push_back(Pair("time", uint64(nTime)));
	CheckIsValid(nLockuntil, "nLockuntil");
	ret.push_back(Pair("lockuntil", uint64(nLockuntil)));

	return ret;
}
CUnspentData& CUnspentData::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CUnspentData");
	auto obj = v.get_obj();
	auto valTxid = find_value(obj, "txid");
	CheckJSONType(valTxid, "string", "txid");
	strTxid = valTxid.get_str();
	auto valOut = find_value(obj, "out");
	CheckJSONType(valOut, "uint", "out");
	nOut = valOut.get_uint64();
	auto valAmount = find_value(obj, "amount");
	CheckJSONType(valAmount, "double", "amount");
	dAmount = valAmount.get_real();
	auto valTime = find_value(obj, "time");
	CheckJSONType(valTime, "uint", "time");
	nTime = valTime.get_uint64();
	auto valLockuntil = find_value(obj, "lockuntil");
	CheckJSONType(valLockuntil, "uint", "lockuntil");
	nLockuntil = valLockuntil.get_uint64();
	return *this;
}
bool CUnspentData::IsValid() const
{
	if (!strTxid.IsValid()) { return false; }
	if (!nOut.IsValid()) { return false; }
	if (!dAmount.IsValid()) { return false; }
	if (!nTime.IsValid()) { return false; }
	if (!nLockuntil.IsValid()) { return false; }
	return true;
}

// CTemplatePubKeyWeight
CTemplatePubKeyWeight::CTemplatePubKeyWeight() {}
CTemplatePubKeyWeight::CTemplatePubKeyWeight(const CRPCString& strKey, const CRPCInt64& nWeight)
	: strKey(strKey), nWeight(nWeight)
{
}
CTemplatePubKeyWeight::CTemplatePubKeyWeight(const CRPCType& null)
	: strKey(null), nWeight(null)
{
}
Value CTemplatePubKeyWeight::ToJSON() const
{
	Object ret;
	CheckIsValid(strKey, "strKey");
	ret.push_back(Pair("key", std::string(strKey)));
	CheckIsValid(nWeight, "nWeight");
	ret.push_back(Pair("weight", int64(nWeight)));

	return ret;
}
CTemplatePubKeyWeight& CTemplatePubKeyWeight::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CTemplatePubKeyWeight");
	auto obj = v.get_obj();
	auto valKey = find_value(obj, "key");
	CheckJSONType(valKey, "string", "key");
	strKey = valKey.get_str();
	auto valWeight = find_value(obj, "weight");
	CheckJSONType(valWeight, "int", "weight");
	nWeight = valWeight.get_int64();
	return *this;
}
bool CTemplatePubKeyWeight::IsValid() const
{
	if (!strKey.IsValid()) { return false; }
	if (!nWeight.IsValid()) { return false; }
	return true;
}

// CTemplateRequest::CPayment
CTemplateRequest::CPayment::CPayment() {}
CTemplateRequest::CPayment::CPayment(const CRPCString& strBusiness, const CRPCString& strCustomer, const CRPCInt64& nHeight_Exec, const CRPCInt64& nHeight_End, const CRPCInt64& nAmount, const CRPCInt64& nPledge)
	: strBusiness(strBusiness), strCustomer(strCustomer), nHeight_Exec(nHeight_Exec), nHeight_End(nHeight_End), nAmount(nAmount), nPledge(nPledge)
{
}
CTemplateRequest::CPayment::CPayment(const CRPCType& null)
	: strBusiness(null), strCustomer(null), nHeight_Exec(null), nHeight_End(null), nAmount(null), nPledge(null)
{
}
Value CTemplateRequest::CPayment::ToJSON() const
{
	Object ret;
	CheckIsValid(strBusiness, "strBusiness");
	ret.push_back(Pair("business", std::string(strBusiness)));
	CheckIsValid(strCustomer, "strCustomer");
	ret.push_back(Pair("customer", std::string(strCustomer)));
	CheckIsValid(nHeight_Exec, "nHeight_Exec");
	ret.push_back(Pair("height_exec", int64(nHeight_Exec)));
	CheckIsValid(nHeight_End, "nHeight_End");
	ret.push_back(Pair("height_end", int64(nHeight_End)));
	CheckIsValid(nAmount, "nAmount");
	ret.push_back(Pair("amount", int64(nAmount)));
	CheckIsValid(nPledge, "nPledge");
	ret.push_back(Pair("pledge", int64(nPledge)));

	return ret;
}
CTemplateRequest::CPayment& CTemplateRequest::CPayment::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CTemplateRequest::CPayment");
	auto obj = v.get_obj();
	auto valBusiness = find_value(obj, "business");
	CheckJSONType(valBusiness, "string", "business");
	strBusiness = valBusiness.get_str();
	auto valCustomer = find_value(obj, "customer");
	CheckJSONType(valCustomer, "string", "customer");
	strCustomer = valCustomer.get_str();
	auto valHeight_Exec = find_value(obj, "height_exec");
	CheckJSONType(valHeight_Exec, "int", "height_exec");
	nHeight_Exec = valHeight_Exec.get_int64();
	auto valHeight_End = find_value(obj, "height_end");
	CheckJSONType(valHeight_End, "int", "height_end");
	nHeight_End = valHeight_End.get_int64();
	auto valAmount = find_value(obj, "amount");
	CheckJSONType(valAmount, "int", "amount");
	nAmount = valAmount.get_int64();
	auto valPledge = find_value(obj, "pledge");
	CheckJSONType(valPledge, "int", "pledge");
	nPledge = valPledge.get_int64();
	return *this;
}
bool CTemplateRequest::CPayment::IsValid() const
{
	if (!strBusiness.IsValid()) { return false; }
	if (!strCustomer.IsValid()) { return false; }
	if (!nHeight_Exec.IsValid()) { return false; }
	if (!nHeight_End.IsValid()) { return false; }
	if (!nAmount.IsValid()) { return false; }
	if (!nPledge.IsValid()) { return false; }
	return true;
}

// CTemplateRequest::CWeighted
CTemplateRequest::CWeighted::CWeighted() {}
CTemplateRequest::CWeighted::CWeighted(const CRPCInt64& nRequired, const CRPCVector<CTemplatePubKeyWeight>& vecPubkeys)
	: nRequired(nRequired), vecPubkeys(vecPubkeys)
{
}
CTemplateRequest::CWeighted::CWeighted(const CRPCType& null)
	: nRequired(null), vecPubkeys(null)
{
}
Value CTemplateRequest::CWeighted::ToJSON() const
{
	Object ret;
	CheckIsValid(nRequired, "nRequired");
	ret.push_back(Pair("required", int64(nRequired)));
	CheckIsValid(vecPubkeys, "vecPubkeys");
	Array vecPubkeysArray;
	for (auto& v : vecPubkeys)
	{
		vecPubkeysArray.push_back(v.ToJSON());
	}
	ret.push_back(Pair("pubkeys", vecPubkeysArray));

	return ret;
}
CTemplateRequest::CWeighted& CTemplateRequest::CWeighted::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CTemplateRequest::CWeighted");
	auto obj = v.get_obj();
	auto valRequired = find_value(obj, "required");
	CheckJSONType(valRequired, "int", "required");
	nRequired = valRequired.get_int64();
	auto valPubkeys = find_value(obj, "pubkeys");
	CheckJSONType(valPubkeys, "array", "pubkeys");
	auto vecPubkeysArray = valPubkeys.get_array();
	for (auto& v : vecPubkeysArray)
	{
		vecPubkeys.push_back(CRPCVector<CTemplatePubKeyWeight>::value_type().FromJSON(v));
	}
	return *this;
}
bool CTemplateRequest::CWeighted::IsValid() const
{
	if (!nRequired.IsValid()) { return false; }
	if (!vecPubkeys.IsValid()) { return false; }
	return true;
}

// CTemplateRequest::CMint
CTemplateRequest::CMint::CMint() {}
CTemplateRequest::CMint::CMint(const CRPCString& strMint, const CRPCString& strSpent)
	: strMint(strMint), strSpent(strSpent)
{
}
CTemplateRequest::CMint::CMint(const CRPCType& null)
	: strMint(null), strSpent(null)
{
}
Value CTemplateRequest::CMint::ToJSON() const
{
	Object ret;
	CheckIsValid(strMint, "strMint");
	ret.push_back(Pair("mint", std::string(strMint)));
	CheckIsValid(strSpent, "strSpent");
	ret.push_back(Pair("spent", std::string(strSpent)));

	return ret;
}
CTemplateRequest::CMint& CTemplateRequest::CMint::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CTemplateRequest::CMint");
	auto obj = v.get_obj();
	auto valMint = find_value(obj, "mint");
	CheckJSONType(valMint, "string", "mint");
	strMint = valMint.get_str();
	auto valSpent = find_value(obj, "spent");
	CheckJSONType(valSpent, "string", "spent");
	strSpent = valSpent.get_str();
	return *this;
}
bool CTemplateRequest::CMint::IsValid() const
{
	if (!strMint.IsValid()) { return false; }
	if (!strSpent.IsValid()) { return false; }
	return true;
}

// CTemplateRequest::CExchange
CTemplateRequest::CExchange::CExchange() {}
CTemplateRequest::CExchange::CExchange(const CRPCString& strAddr_M, const CRPCString& strAddr_S, const CRPCInt64& nHeight_M, const CRPCInt64& nHeight_S, const CRPCString& strFork_M, const CRPCString& strFork_S)
	: strAddr_M(strAddr_M), strAddr_S(strAddr_S), nHeight_M(nHeight_M), nHeight_S(nHeight_S), strFork_M(strFork_M), strFork_S(strFork_S)
{
}
CTemplateRequest::CExchange::CExchange(const CRPCType& null)
	: strAddr_M(null), strAddr_S(null), nHeight_M(null), nHeight_S(null), strFork_M(null), strFork_S(null)
{
}
Value CTemplateRequest::CExchange::ToJSON() const
{
	Object ret;
	CheckIsValid(strAddr_M, "strAddr_M");
	ret.push_back(Pair("addr_m", std::string(strAddr_M)));
	CheckIsValid(strAddr_S, "strAddr_S");
	ret.push_back(Pair("addr_s", std::string(strAddr_S)));
	CheckIsValid(nHeight_M, "nHeight_M");
	ret.push_back(Pair("height_m", int64(nHeight_M)));
	CheckIsValid(nHeight_S, "nHeight_S");
	ret.push_back(Pair("height_s", int64(nHeight_S)));
	CheckIsValid(strFork_M, "strFork_M");
	ret.push_back(Pair("fork_m", std::string(strFork_M)));
	CheckIsValid(strFork_S, "strFork_S");
	ret.push_back(Pair("fork_s", std::string(strFork_S)));

	return ret;
}
CTemplateRequest::CExchange& CTemplateRequest::CExchange::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CTemplateRequest::CExchange");
	auto obj = v.get_obj();
	auto valAddr_M = find_value(obj, "addr_m");
	CheckJSONType(valAddr_M, "string", "addr_m");
	strAddr_M = valAddr_M.get_str();
	auto valAddr_S = find_value(obj, "addr_s");
	CheckJSONType(valAddr_S, "string", "addr_s");
	strAddr_S = valAddr_S.get_str();
	auto valHeight_M = find_value(obj, "height_m");
	CheckJSONType(valHeight_M, "int", "height_m");
	nHeight_M = valHeight_M.get_int64();
	auto valHeight_S = find_value(obj, "height_s");
	CheckJSONType(valHeight_S, "int", "height_s");
	nHeight_S = valHeight_S.get_int64();
	auto valFork_M = find_value(obj, "fork_m");
	CheckJSONType(valFork_M, "string", "fork_m");
	strFork_M = valFork_M.get_str();
	auto valFork_S = find_value(obj, "fork_s");
	CheckJSONType(valFork_S, "string", "fork_s");
	strFork_S = valFork_S.get_str();
	return *this;
}
bool CTemplateRequest::CExchange::IsValid() const
{
	if (!strAddr_M.IsValid()) { return false; }
	if (!strAddr_S.IsValid()) { return false; }
	if (!nHeight_M.IsValid()) { return false; }
	if (!nHeight_S.IsValid()) { return false; }
	if (!strFork_M.IsValid()) { return false; }
	if (!strFork_S.IsValid()) { return false; }
	return true;
}

// CTemplateRequest::CMultisig
CTemplateRequest::CMultisig::CMultisig() {}
CTemplateRequest::CMultisig::CMultisig(const CRPCInt64& nRequired, const CRPCVector<std::string>& vecPubkeys)
	: nRequired(nRequired), vecPubkeys(vecPubkeys)
{
}
CTemplateRequest::CMultisig::CMultisig(const CRPCType& null)
	: nRequired(null), vecPubkeys(null)
{
}
Value CTemplateRequest::CMultisig::ToJSON() const
{
	Object ret;
	CheckIsValid(nRequired, "nRequired");
	ret.push_back(Pair("required", int64(nRequired)));
	CheckIsValid(vecPubkeys, "vecPubkeys");
	Array vecPubkeysArray;
	for (auto& v : vecPubkeys)
	{
		vecPubkeysArray.push_back(std::string(v));
	}
	ret.push_back(Pair("pubkeys", vecPubkeysArray));

	return ret;
}
CTemplateRequest::CMultisig& CTemplateRequest::CMultisig::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CTemplateRequest::CMultisig");
	auto obj = v.get_obj();
	auto valRequired = find_value(obj, "required");
	CheckJSONType(valRequired, "int", "required");
	nRequired = valRequired.get_int64();
	auto valPubkeys = find_value(obj, "pubkeys");
	CheckJSONType(valPubkeys, "array", "pubkeys");
	auto vecPubkeysArray = valPubkeys.get_array();
	for (auto& v : vecPubkeysArray)
	{
		vecPubkeys.push_back(v.get_str());
	}
	return *this;
}
bool CTemplateRequest::CMultisig::IsValid() const
{
	if (!nRequired.IsValid()) { return false; }
	if (!vecPubkeys.IsValid()) { return false; }
	return true;
}

// CTemplateRequest::CVote
CTemplateRequest::CVote::CVote() {}
CTemplateRequest::CVote::CVote(const CRPCString& strDelegate, const CRPCString& strOwner)
	: strDelegate(strDelegate), strOwner(strOwner)
{
}
CTemplateRequest::CVote::CVote(const CRPCType& null)
	: strDelegate(null), strOwner(null)
{
}
Value CTemplateRequest::CVote::ToJSON() const
{
	Object ret;
	CheckIsValid(strDelegate, "strDelegate");
	ret.push_back(Pair("delegate", std::string(strDelegate)));
	CheckIsValid(strOwner, "strOwner");
	ret.push_back(Pair("owner", std::string(strOwner)));

	return ret;
}
CTemplateRequest::CVote& CTemplateRequest::CVote::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CTemplateRequest::CVote");
	auto obj = v.get_obj();
	auto valDelegate = find_value(obj, "delegate");
	CheckJSONType(valDelegate, "string", "delegate");
	strDelegate = valDelegate.get_str();
	auto valOwner = find_value(obj, "owner");
	CheckJSONType(valOwner, "string", "owner");
	strOwner = valOwner.get_str();
	return *this;
}
bool CTemplateRequest::CVote::IsValid() const
{
	if (!strDelegate.IsValid()) { return false; }
	if (!strOwner.IsValid()) { return false; }
	return true;
}

// CTemplateRequest::CFork
CTemplateRequest::CFork::CFork() {}
CTemplateRequest::CFork::CFork(const CRPCString& strRedeem, const CRPCString& strFork)
	: strRedeem(strRedeem), strFork(strFork)
{
}
CTemplateRequest::CFork::CFork(const CRPCType& null)
	: strRedeem(null), strFork(null)
{
}
Value CTemplateRequest::CFork::ToJSON() const
{
	Object ret;
	CheckIsValid(strRedeem, "strRedeem");
	ret.push_back(Pair("redeem", std::string(strRedeem)));
	CheckIsValid(strFork, "strFork");
	ret.push_back(Pair("fork", std::string(strFork)));

	return ret;
}
CTemplateRequest::CFork& CTemplateRequest::CFork::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CTemplateRequest::CFork");
	auto obj = v.get_obj();
	auto valRedeem = find_value(obj, "redeem");
	CheckJSONType(valRedeem, "string", "redeem");
	strRedeem = valRedeem.get_str();
	auto valFork = find_value(obj, "fork");
	CheckJSONType(valFork, "string", "fork");
	strFork = valFork.get_str();
	return *this;
}
bool CTemplateRequest::CFork::IsValid() const
{
	if (!strRedeem.IsValid()) { return false; }
	if (!strFork.IsValid()) { return false; }
	return true;
}

// CTemplateRequest::CDelegate
CTemplateRequest::CDelegate::CDelegate() {}
CTemplateRequest::CDelegate::CDelegate(const CRPCString& strDelegate, const CRPCString& strOwner)
	: strDelegate(strDelegate), strOwner(strOwner)
{
}
CTemplateRequest::CDelegate::CDelegate(const CRPCType& null)
	: strDelegate(null), strOwner(null)
{
}
Value CTemplateRequest::CDelegate::ToJSON() const
{
	Object ret;
	CheckIsValid(strDelegate, "strDelegate");
	ret.push_back(Pair("delegate", std::string(strDelegate)));
	CheckIsValid(strOwner, "strOwner");
	ret.push_back(Pair("owner", std::string(strOwner)));

	return ret;
}
CTemplateRequest::CDelegate& CTemplateRequest::CDelegate::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CTemplateRequest::CDelegate");
	auto obj = v.get_obj();
	auto valDelegate = find_value(obj, "delegate");
	CheckJSONType(valDelegate, "string", "delegate");
	strDelegate = valDelegate.get_str();
	auto valOwner = find_value(obj, "owner");
	CheckJSONType(valOwner, "string", "owner");
	strOwner = valOwner.get_str();
	return *this;
}
bool CTemplateRequest::CDelegate::IsValid() const
{
	if (!strDelegate.IsValid()) { return false; }
	if (!strOwner.IsValid()) { return false; }
	return true;
}

// CTemplateRequest
CTemplateRequest::CTemplateRequest() {}
CTemplateRequest::CTemplateRequest(const CRPCString& strType, const CDelegate& delegate, const CVote& vote, const CFork& fork, const CMint& mint, const CMultisig& multisig, const CWeighted& weighted, const CExchange& exchange, const CPayment& payment, const CRPCBool& fSynctx)
	: strType(strType), delegate(delegate), vote(vote), fork(fork), mint(mint), multisig(multisig), weighted(weighted), exchange(exchange), payment(payment), fSynctx(fSynctx)
{
}
CTemplateRequest::CTemplateRequest(const CRPCType& null)
	: strType(null), delegate(null), vote(null), fork(null), mint(null), multisig(null), weighted(null), exchange(null), payment(null), fSynctx(null)
{
}
Value CTemplateRequest::ToJSON() const
{
	Object ret;
	CheckIsValid(strType, "strType");
	ret.push_back(Pair("type", std::string(strType)));
	if (strType == "delegate")
	{
		CheckIsValid(delegate, "delegate");
		ret.push_back(Pair("delegate", delegate.ToJSON()));
	}
	if (strType == "vote")
	{
		CheckIsValid(vote, "vote");
		ret.push_back(Pair("vote", vote.ToJSON()));
	}
	if (strType == "fork")
	{
		CheckIsValid(fork, "fork");
		ret.push_back(Pair("fork", fork.ToJSON()));
	}
	if (strType == "mint")
	{
		CheckIsValid(mint, "mint");
		ret.push_back(Pair("mint", mint.ToJSON()));
	}
	if (strType == "multisig")
	{
		CheckIsValid(multisig, "multisig");
		ret.push_back(Pair("multisig", multisig.ToJSON()));
	}
	if (strType == "weighted")
	{
		CheckIsValid(weighted, "weighted");
		ret.push_back(Pair("weighted", weighted.ToJSON()));
	}
	if (strType == "exchange")
	{
		CheckIsValid(exchange, "exchange");
		ret.push_back(Pair("exchange", exchange.ToJSON()));
	}
	if (strType == "payment")
	{
		CheckIsValid(payment, "payment");
		ret.push_back(Pair("payment", payment.ToJSON()));
	}
	if (fSynctx.IsValid())
	{
		ret.push_back(Pair("synctx", bool(fSynctx)));
	}

	return ret;
}
CTemplateRequest& CTemplateRequest::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CTemplateRequest");
	auto obj = v.get_obj();
	auto valType = find_value(obj, "type");
	CheckJSONType(valType, "string", "type");
	strType = valType.get_str();
	if (strType == "delegate")
	{
		auto valDelegate = find_value(obj, "delegate");
		CheckJSONType(valDelegate, "object", "delegate");
		delegate.FromJSON(valDelegate.get_obj());
	}
	if (strType == "vote")
	{
		auto valVote = find_value(obj, "vote");
		CheckJSONType(valVote, "object", "vote");
		vote.FromJSON(valVote.get_obj());
	}
	if (strType == "fork")
	{
		auto valFork = find_value(obj, "fork");
		CheckJSONType(valFork, "object", "fork");
		fork.FromJSON(valFork.get_obj());
	}
	if (strType == "mint")
	{
		auto valMint = find_value(obj, "mint");
		CheckJSONType(valMint, "object", "mint");
		mint.FromJSON(valMint.get_obj());
	}
	if (strType == "multisig")
	{
		auto valMultisig = find_value(obj, "multisig");
		CheckJSONType(valMultisig, "object", "multisig");
		multisig.FromJSON(valMultisig.get_obj());
	}
	if (strType == "weighted")
	{
		auto valWeighted = find_value(obj, "weighted");
		CheckJSONType(valWeighted, "object", "weighted");
		weighted.FromJSON(valWeighted.get_obj());
	}
	if (strType == "exchange")
	{
		auto valExchange = find_value(obj, "exchange");
		CheckJSONType(valExchange, "object", "exchange");
		exchange.FromJSON(valExchange.get_obj());
	}
	if (strType == "payment")
	{
		auto valPayment = find_value(obj, "payment");
		CheckJSONType(valPayment, "object", "payment");
		payment.FromJSON(valPayment.get_obj());
	}
	auto valSynctx = find_value(obj, "synctx");
	if (!valSynctx.is_null())
	{
		CheckJSONType(valSynctx, "bool", "synctx");
		fSynctx = valSynctx.get_bool();
	}
	return *this;
}
bool CTemplateRequest::IsValid() const
{
	if (!strType.IsValid()) { return false; }
	if (strType == "delegate")
	{
		if (!delegate.IsValid()) { return false; }
	}
	if (strType == "vote")
	{
		if (!vote.IsValid()) { return false; }
	}
	if (strType == "fork")
	{
		if (!fork.IsValid()) { return false; }
	}
	if (strType == "mint")
	{
		if (!mint.IsValid()) { return false; }
	}
	if (strType == "multisig")
	{
		if (!multisig.IsValid()) { return false; }
	}
	if (strType == "weighted")
	{
		if (!weighted.IsValid()) { return false; }
	}
	if (strType == "exchange")
	{
		if (!exchange.IsValid()) { return false; }
	}
	if (strType == "payment")
	{
		if (!payment.IsValid()) { return false; }
	}
	return true;
}

// CTemplateResponse::CPayment
CTemplateResponse::CPayment::CPayment() {}
CTemplateResponse::CPayment::CPayment(const CRPCString& strBusiness, const CRPCString& strCustomer, const CRPCInt64& nHeight_Exec, const CRPCInt64& nHeight_End, const CRPCInt64& nAmount, const CRPCInt64& nPledge)
	: strBusiness(strBusiness), strCustomer(strCustomer), nHeight_Exec(nHeight_Exec), nHeight_End(nHeight_End), nAmount(nAmount), nPledge(nPledge)
{
}
CTemplateResponse::CPayment::CPayment(const CRPCType& null)
	: strBusiness(null), strCustomer(null), nHeight_Exec(null), nHeight_End(null), nAmount(null), nPledge(null)
{
}
Value CTemplateResponse::CPayment::ToJSON() const
{
	Object ret;
	CheckIsValid(strBusiness, "strBusiness");
	ret.push_back(Pair("business", std::string(strBusiness)));
	CheckIsValid(strCustomer, "strCustomer");
	ret.push_back(Pair("customer", std::string(strCustomer)));
	CheckIsValid(nHeight_Exec, "nHeight_Exec");
	ret.push_back(Pair("height_exec", int64(nHeight_Exec)));
	CheckIsValid(nHeight_End, "nHeight_End");
	ret.push_back(Pair("height_end", int64(nHeight_End)));
	CheckIsValid(nAmount, "nAmount");
	ret.push_back(Pair("amount", int64(nAmount)));
	CheckIsValid(nPledge, "nPledge");
	ret.push_back(Pair("pledge", int64(nPledge)));

	return ret;
}
CTemplateResponse::CPayment& CTemplateResponse::CPayment::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CTemplateResponse::CPayment");
	auto obj = v.get_obj();
	auto valBusiness = find_value(obj, "business");
	CheckJSONType(valBusiness, "string", "business");
	strBusiness = valBusiness.get_str();
	auto valCustomer = find_value(obj, "customer");
	CheckJSONType(valCustomer, "string", "customer");
	strCustomer = valCustomer.get_str();
	auto valHeight_Exec = find_value(obj, "height_exec");
	CheckJSONType(valHeight_Exec, "int", "height_exec");
	nHeight_Exec = valHeight_Exec.get_int64();
	auto valHeight_End = find_value(obj, "height_end");
	CheckJSONType(valHeight_End, "int", "height_end");
	nHeight_End = valHeight_End.get_int64();
	auto valAmount = find_value(obj, "amount");
	CheckJSONType(valAmount, "int", "amount");
	nAmount = valAmount.get_int64();
	auto valPledge = find_value(obj, "pledge");
	CheckJSONType(valPledge, "int", "pledge");
	nPledge = valPledge.get_int64();
	return *this;
}
bool CTemplateResponse::CPayment::IsValid() const
{
	if (!strBusiness.IsValid()) { return false; }
	if (!strCustomer.IsValid()) { return false; }
	if (!nHeight_Exec.IsValid()) { return false; }
	if (!nHeight_End.IsValid()) { return false; }
	if (!nAmount.IsValid()) { return false; }
	if (!nPledge.IsValid()) { return false; }
	return true;
}

// CTemplateResponse::CDelegate
CTemplateResponse::CDelegate::CDelegate() {}
CTemplateResponse::CDelegate::CDelegate(const CRPCString& strDelegate, const CRPCString& strOwner)
	: strDelegate(strDelegate), strOwner(strOwner)
{
}
CTemplateResponse::CDelegate::CDelegate(const CRPCType& null)
	: strDelegate(null), strOwner(null)
{
}
Value CTemplateResponse::CDelegate::ToJSON() const
{
	Object ret;
	CheckIsValid(strDelegate, "strDelegate");
	ret.push_back(Pair("delegate", std::string(strDelegate)));
	CheckIsValid(strOwner, "strOwner");
	ret.push_back(Pair("owner", std::string(strOwner)));

	return ret;
}
CTemplateResponse::CDelegate& CTemplateResponse::CDelegate::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CTemplateResponse::CDelegate");
	auto obj = v.get_obj();
	auto valDelegate = find_value(obj, "delegate");
	CheckJSONType(valDelegate, "string", "delegate");
	strDelegate = valDelegate.get_str();
	auto valOwner = find_value(obj, "owner");
	CheckJSONType(valOwner, "string", "owner");
	strOwner = valOwner.get_str();
	return *this;
}
bool CTemplateResponse::CDelegate::IsValid() const
{
	if (!strDelegate.IsValid()) { return false; }
	if (!strOwner.IsValid()) { return false; }
	return true;
}

// CTemplateResponse::CVote
CTemplateResponse::CVote::CVote() {}
CTemplateResponse::CVote::CVote(const CRPCString& strDelegate, const CRPCString& strOwner)
	: strDelegate(strDelegate), strOwner(strOwner)
{
}
CTemplateResponse::CVote::CVote(const CRPCType& null)
	: strDelegate(null), strOwner(null)
{
}
Value CTemplateResponse::CVote::ToJSON() const
{
	Object ret;
	CheckIsValid(strDelegate, "strDelegate");
	ret.push_back(Pair("delegate", std::string(strDelegate)));
	CheckIsValid(strOwner, "strOwner");
	ret.push_back(Pair("owner", std::string(strOwner)));

	return ret;
}
CTemplateResponse::CVote& CTemplateResponse::CVote::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CTemplateResponse::CVote");
	auto obj = v.get_obj();
	auto valDelegate = find_value(obj, "delegate");
	CheckJSONType(valDelegate, "string", "delegate");
	strDelegate = valDelegate.get_str();
	auto valOwner = find_value(obj, "owner");
	CheckJSONType(valOwner, "string", "owner");
	strOwner = valOwner.get_str();
	return *this;
}
bool CTemplateResponse::CVote::IsValid() const
{
	if (!strDelegate.IsValid()) { return false; }
	if (!strOwner.IsValid()) { return false; }
	return true;
}

// CTemplateResponse::CMint
CTemplateResponse::CMint::CMint() {}
CTemplateResponse::CMint::CMint(const CRPCString& strMint, const CRPCString& strSpent)
	: strMint(strMint), strSpent(strSpent)
{
}
CTemplateResponse::CMint::CMint(const CRPCType& null)
	: strMint(null), strSpent(null)
{
}
Value CTemplateResponse::CMint::ToJSON() const
{
	Object ret;
	CheckIsValid(strMint, "strMint");
	ret.push_back(Pair("mint", std::string(strMint)));
	CheckIsValid(strSpent, "strSpent");
	ret.push_back(Pair("spent", std::string(strSpent)));

	return ret;
}
CTemplateResponse::CMint& CTemplateResponse::CMint::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CTemplateResponse::CMint");
	auto obj = v.get_obj();
	auto valMint = find_value(obj, "mint");
	CheckJSONType(valMint, "string", "mint");
	strMint = valMint.get_str();
	auto valSpent = find_value(obj, "spent");
	CheckJSONType(valSpent, "string", "spent");
	strSpent = valSpent.get_str();
	return *this;
}
bool CTemplateResponse::CMint::IsValid() const
{
	if (!strMint.IsValid()) { return false; }
	if (!strSpent.IsValid()) { return false; }
	return true;
}

// CTemplateResponse::CMultisig
CTemplateResponse::CMultisig::CMultisig() {}
CTemplateResponse::CMultisig::CMultisig(const CRPCInt64& nRequired, const CRPCVector<std::string>& vecAddresses)
	: nRequired(nRequired), vecAddresses(vecAddresses)
{
}
CTemplateResponse::CMultisig::CMultisig(const CRPCType& null)
	: nRequired(null), vecAddresses(null)
{
}
Value CTemplateResponse::CMultisig::ToJSON() const
{
	Object ret;
	CheckIsValid(nRequired, "nRequired");
	ret.push_back(Pair("required", int64(nRequired)));
	CheckIsValid(vecAddresses, "vecAddresses");
	Array vecAddressesArray;
	for (auto& v : vecAddresses)
	{
		vecAddressesArray.push_back(std::string(v));
	}
	ret.push_back(Pair("addresses", vecAddressesArray));

	return ret;
}
CTemplateResponse::CMultisig& CTemplateResponse::CMultisig::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CTemplateResponse::CMultisig");
	auto obj = v.get_obj();
	auto valRequired = find_value(obj, "required");
	CheckJSONType(valRequired, "int", "required");
	nRequired = valRequired.get_int64();
	auto valAddresses = find_value(obj, "addresses");
	CheckJSONType(valAddresses, "array", "addresses");
	auto vecAddressesArray = valAddresses.get_array();
	for (auto& v : vecAddressesArray)
	{
		vecAddresses.push_back(v.get_str());
	}
	return *this;
}
bool CTemplateResponse::CMultisig::IsValid() const
{
	if (!nRequired.IsValid()) { return false; }
	if (!vecAddresses.IsValid()) { return false; }
	return true;
}

// CTemplateResponse::CFork
CTemplateResponse::CFork::CFork() {}
CTemplateResponse::CFork::CFork(const CRPCString& strRedeem, const CRPCString& strFork)
	: strRedeem(strRedeem), strFork(strFork)
{
}
CTemplateResponse::CFork::CFork(const CRPCType& null)
	: strRedeem(null), strFork(null)
{
}
Value CTemplateResponse::CFork::ToJSON() const
{
	Object ret;
	CheckIsValid(strRedeem, "strRedeem");
	ret.push_back(Pair("redeem", std::string(strRedeem)));
	CheckIsValid(strFork, "strFork");
	ret.push_back(Pair("fork", std::string(strFork)));

	return ret;
}
CTemplateResponse::CFork& CTemplateResponse::CFork::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CTemplateResponse::CFork");
	auto obj = v.get_obj();
	auto valRedeem = find_value(obj, "redeem");
	CheckJSONType(valRedeem, "string", "redeem");
	strRedeem = valRedeem.get_str();
	auto valFork = find_value(obj, "fork");
	CheckJSONType(valFork, "string", "fork");
	strFork = valFork.get_str();
	return *this;
}
bool CTemplateResponse::CFork::IsValid() const
{
	if (!strRedeem.IsValid()) { return false; }
	if (!strFork.IsValid()) { return false; }
	return true;
}

// CTemplateResponse::CWeighted
CTemplateResponse::CWeighted::CWeighted() {}
CTemplateResponse::CWeighted::CWeighted(const CRPCInt64& nRequired, const CRPCVector<CTemplatePubKeyWeight>& vecAddresses)
	: nRequired(nRequired), vecAddresses(vecAddresses)
{
}
CTemplateResponse::CWeighted::CWeighted(const CRPCType& null)
	: nRequired(null), vecAddresses(null)
{
}
Value CTemplateResponse::CWeighted::ToJSON() const
{
	Object ret;
	CheckIsValid(nRequired, "nRequired");
	ret.push_back(Pair("required", int64(nRequired)));
	CheckIsValid(vecAddresses, "vecAddresses");
	Array vecAddressesArray;
	for (auto& v : vecAddresses)
	{
		vecAddressesArray.push_back(v.ToJSON());
	}
	ret.push_back(Pair("addresses", vecAddressesArray));

	return ret;
}
CTemplateResponse::CWeighted& CTemplateResponse::CWeighted::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CTemplateResponse::CWeighted");
	auto obj = v.get_obj();
	auto valRequired = find_value(obj, "required");
	CheckJSONType(valRequired, "int", "required");
	nRequired = valRequired.get_int64();
	auto valAddresses = find_value(obj, "addresses");
	CheckJSONType(valAddresses, "array", "addresses");
	auto vecAddressesArray = valAddresses.get_array();
	for (auto& v : vecAddressesArray)
	{
		vecAddresses.push_back(CRPCVector<CTemplatePubKeyWeight>::value_type().FromJSON(v));
	}
	return *this;
}
bool CTemplateResponse::CWeighted::IsValid() const
{
	if (!nRequired.IsValid()) { return false; }
	if (!vecAddresses.IsValid()) { return false; }
	return true;
}

// CTemplateResponse::CExchange
CTemplateResponse::CExchange::CExchange() {}
CTemplateResponse::CExchange::CExchange(const CRPCString& strSpend_M, const CRPCString& strSpend_S, const CRPCInt64& nHeight_M, const CRPCInt64& nHeight_S, const CRPCString& strFork_M, const CRPCString& strFork_S)
	: strSpend_M(strSpend_M), strSpend_S(strSpend_S), nHeight_M(nHeight_M), nHeight_S(nHeight_S), strFork_M(strFork_M), strFork_S(strFork_S)
{
}
CTemplateResponse::CExchange::CExchange(const CRPCType& null)
	: strSpend_M(null), strSpend_S(null), nHeight_M(null), nHeight_S(null), strFork_M(null), strFork_S(null)
{
}
Value CTemplateResponse::CExchange::ToJSON() const
{
	Object ret;
	CheckIsValid(strSpend_M, "strSpend_M");
	ret.push_back(Pair("spend_m", std::string(strSpend_M)));
	CheckIsValid(strSpend_S, "strSpend_S");
	ret.push_back(Pair("spend_s", std::string(strSpend_S)));
	CheckIsValid(nHeight_M, "nHeight_M");
	ret.push_back(Pair("height_m", int64(nHeight_M)));
	CheckIsValid(nHeight_S, "nHeight_S");
	ret.push_back(Pair("height_s", int64(nHeight_S)));
	CheckIsValid(strFork_M, "strFork_M");
	ret.push_back(Pair("fork_m", std::string(strFork_M)));
	CheckIsValid(strFork_S, "strFork_S");
	ret.push_back(Pair("fork_s", std::string(strFork_S)));

	return ret;
}
CTemplateResponse::CExchange& CTemplateResponse::CExchange::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CTemplateResponse::CExchange");
	auto obj = v.get_obj();
	auto valSpend_M = find_value(obj, "spend_m");
	CheckJSONType(valSpend_M, "string", "spend_m");
	strSpend_M = valSpend_M.get_str();
	auto valSpend_S = find_value(obj, "spend_s");
	CheckJSONType(valSpend_S, "string", "spend_s");
	strSpend_S = valSpend_S.get_str();
	auto valHeight_M = find_value(obj, "height_m");
	CheckJSONType(valHeight_M, "int", "height_m");
	nHeight_M = valHeight_M.get_int64();
	auto valHeight_S = find_value(obj, "height_s");
	CheckJSONType(valHeight_S, "int", "height_s");
	nHeight_S = valHeight_S.get_int64();
	auto valFork_M = find_value(obj, "fork_m");
	CheckJSONType(valFork_M, "string", "fork_m");
	strFork_M = valFork_M.get_str();
	auto valFork_S = find_value(obj, "fork_s");
	CheckJSONType(valFork_S, "string", "fork_s");
	strFork_S = valFork_S.get_str();
	return *this;
}
bool CTemplateResponse::CExchange::IsValid() const
{
	if (!strSpend_M.IsValid()) { return false; }
	if (!strSpend_S.IsValid()) { return false; }
	if (!nHeight_M.IsValid()) { return false; }
	if (!nHeight_S.IsValid()) { return false; }
	if (!strFork_M.IsValid()) { return false; }
	if (!strFork_S.IsValid()) { return false; }
	return true;
}

// CTemplateResponse
CTemplateResponse::CTemplateResponse() {}
CTemplateResponse::CTemplateResponse(const CRPCString& strType, const CRPCString& strHex, const CDelegate& delegate, const CVote& vote, const CFork& fork, const CMint& mint, const CMultisig& multisig, const CExchange& exchange, const CPayment& payment, const CWeighted& weighted)
	: strType(strType), strHex(strHex), delegate(delegate), vote(vote), fork(fork), mint(mint), multisig(multisig), exchange(exchange), payment(payment), weighted(weighted)
{
}
CTemplateResponse::CTemplateResponse(const CRPCType& null)
	: strType(null), strHex(null), delegate(null), vote(null), fork(null), mint(null), multisig(null), exchange(null), payment(null), weighted(null)
{
}
Value CTemplateResponse::ToJSON() const
{
	Object ret;
	CheckIsValid(strType, "strType");
	ret.push_back(Pair("type", std::string(strType)));
	CheckIsValid(strHex, "strHex");
	ret.push_back(Pair("hex", std::string(strHex)));
	if (strType == "delegate")
	{
		CheckIsValid(delegate, "delegate");
		ret.push_back(Pair("delegate", delegate.ToJSON()));
	}
	if (strType == "vote")
	{
		CheckIsValid(vote, "vote");
		ret.push_back(Pair("vote", vote.ToJSON()));
	}
	if (strType == "fork")
	{
		CheckIsValid(fork, "fork");
		ret.push_back(Pair("fork", fork.ToJSON()));
	}
	if (strType == "mint")
	{
		CheckIsValid(mint, "mint");
		ret.push_back(Pair("mint", mint.ToJSON()));
	}
	if (strType == "multisig")
	{
		CheckIsValid(multisig, "multisig");
		ret.push_back(Pair("multisig", multisig.ToJSON()));
	}
	if (strType == "exchange")
	{
		CheckIsValid(exchange, "exchange");
		ret.push_back(Pair("exchange", exchange.ToJSON()));
	}
	if (strType == "payment")
	{
		CheckIsValid(payment, "payment");
		ret.push_back(Pair("payment", payment.ToJSON()));
	}
	if (strType == "weighted")
	{
		CheckIsValid(weighted, "weighted");
		ret.push_back(Pair("weighted", weighted.ToJSON()));
	}

	return ret;
}
CTemplateResponse& CTemplateResponse::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CTemplateResponse");
	auto obj = v.get_obj();
	auto valType = find_value(obj, "type");
	CheckJSONType(valType, "string", "type");
	strType = valType.get_str();
	auto valHex = find_value(obj, "hex");
	CheckJSONType(valHex, "string", "hex");
	strHex = valHex.get_str();
	if (strType == "delegate")
	{
		auto valDelegate = find_value(obj, "delegate");
		CheckJSONType(valDelegate, "object", "delegate");
		delegate.FromJSON(valDelegate.get_obj());
	}
	if (strType == "vote")
	{
		auto valVote = find_value(obj, "vote");
		CheckJSONType(valVote, "object", "vote");
		vote.FromJSON(valVote.get_obj());
	}
	if (strType == "fork")
	{
		auto valFork = find_value(obj, "fork");
		CheckJSONType(valFork, "object", "fork");
		fork.FromJSON(valFork.get_obj());
	}
	if (strType == "mint")
	{
		auto valMint = find_value(obj, "mint");
		CheckJSONType(valMint, "object", "mint");
		mint.FromJSON(valMint.get_obj());
	}
	if (strType == "multisig")
	{
		auto valMultisig = find_value(obj, "multisig");
		CheckJSONType(valMultisig, "object", "multisig");
		multisig.FromJSON(valMultisig.get_obj());
	}
	if (strType == "exchange")
	{
		auto valExchange = find_value(obj, "exchange");
		CheckJSONType(valExchange, "object", "exchange");
		exchange.FromJSON(valExchange.get_obj());
	}
	if (strType == "payment")
	{
		auto valPayment = find_value(obj, "payment");
		CheckJSONType(valPayment, "object", "payment");
		payment.FromJSON(valPayment.get_obj());
	}
	if (strType == "weighted")
	{
		auto valWeighted = find_value(obj, "weighted");
		CheckJSONType(valWeighted, "object", "weighted");
		weighted.FromJSON(valWeighted.get_obj());
	}
	return *this;
}
bool CTemplateResponse::IsValid() const
{
	if (!strType.IsValid()) { return false; }
	if (!strHex.IsValid()) { return false; }
	if (strType == "delegate")
	{
		if (!delegate.IsValid()) { return false; }
	}
	if (strType == "vote")
	{
		if (!vote.IsValid()) { return false; }
	}
	if (strType == "fork")
	{
		if (!fork.IsValid()) { return false; }
	}
	if (strType == "mint")
	{
		if (!mint.IsValid()) { return false; }
	}
	if (strType == "multisig")
	{
		if (!multisig.IsValid()) { return false; }
	}
	if (strType == "exchange")
	{
		if (!exchange.IsValid()) { return false; }
	}
	if (strType == "payment")
	{
		if (!payment.IsValid()) { return false; }
	}
	if (strType == "weighted")
	{
		if (!weighted.IsValid()) { return false; }
	}
	return true;
}

// CTransactionData::CVin
CTransactionData::CVin::CVin() {}
CTransactionData::CVin::CVin(const CRPCString& strTxid, const CRPCUint64& nVout)
	: strTxid(strTxid), nVout(nVout)
{
}
CTransactionData::CVin::CVin(const CRPCType& null)
	: strTxid(null), nVout(null)
{
}
Value CTransactionData::CVin::ToJSON() const
{
	Object ret;
	CheckIsValid(strTxid, "strTxid");
	ret.push_back(Pair("txid", std::string(strTxid)));
	CheckIsValid(nVout, "nVout");
	ret.push_back(Pair("vout", uint64(nVout)));

	return ret;
}
CTransactionData::CVin& CTransactionData::CVin::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CTransactionData::CVin");
	auto obj = v.get_obj();
	auto valTxid = find_value(obj, "txid");
	CheckJSONType(valTxid, "string", "txid");
	strTxid = valTxid.get_str();
	auto valVout = find_value(obj, "vout");
	CheckJSONType(valVout, "uint", "vout");
	nVout = valVout.get_uint64();
	return *this;
}
bool CTransactionData::CVin::IsValid() const
{
	if (!strTxid.IsValid()) { return false; }
	if (!nVout.IsValid()) { return false; }
	return true;
}

// CTransactionData
CTransactionData::CTransactionData() {}
CTransactionData::CTransactionData(const CRPCString& strTxid, const CRPCUint64& nVersion, const CRPCString& strType, const CRPCUint64& nTime, const CRPCUint64& nLockuntil, const CRPCString& strBlockhash, const CRPCVector<CVin>& vecVin, const CRPCString& strSendfrom, const CRPCString& strSendto, const CRPCDouble& dAmount, const CRPCDouble& dTxfee, const CRPCString& strData, const CRPCString& strSig, const CRPCString& strFork, const CRPCInt64& nConfirmations)
	: strTxid(strTxid), nVersion(nVersion), strType(strType), nTime(nTime), nLockuntil(nLockuntil), strBlockhash(strBlockhash), vecVin(vecVin), strSendfrom(strSendfrom), strSendto(strSendto), dAmount(dAmount), dTxfee(dTxfee), strData(strData), strSig(strSig), strFork(strFork), nConfirmations(nConfirmations)
{
}
CTransactionData::CTransactionData(const CRPCType& null)
	: strTxid(null), nVersion(null), strType(null), nTime(null), nLockuntil(null), strBlockhash(null), vecVin(null), strSendfrom(null), strSendto(null), dAmount(null), dTxfee(null), strData(null), strSig(null), strFork(null), nConfirmations(null)
{
}
Value CTransactionData::ToJSON() const
{
	Object ret;
	CheckIsValid(strTxid, "strTxid");
	ret.push_back(Pair("txid", std::string(strTxid)));
	CheckIsValid(nVersion, "nVersion");
	ret.push_back(Pair("version", uint64(nVersion)));
	CheckIsValid(strType, "strType");
	ret.push_back(Pair("type", std::string(strType)));
	CheckIsValid(nTime, "nTime");
	ret.push_back(Pair("time", uint64(nTime)));
	CheckIsValid(nLockuntil, "nLockuntil");
	ret.push_back(Pair("lockuntil", uint64(nLockuntil)));
	CheckIsValid(strBlockhash, "strBlockhash");
	ret.push_back(Pair("blockhash", std::string(strBlockhash)));
	CheckIsValid(vecVin, "vecVin");
	Array vecVinArray;
	for (auto& v : vecVin)
	{
		vecVinArray.push_back(v.ToJSON());
	}
	ret.push_back(Pair("vin", vecVinArray));
	CheckIsValid(strSendfrom, "strSendfrom");
	ret.push_back(Pair("sendfrom", std::string(strSendfrom)));
	CheckIsValid(strSendto, "strSendto");
	ret.push_back(Pair("sendto", std::string(strSendto)));
	CheckIsValid(dAmount, "dAmount");
	ret.push_back(Pair("amount", double(dAmount)));
	CheckIsValid(dTxfee, "dTxfee");
	ret.push_back(Pair("txfee", double(dTxfee)));
	CheckIsValid(strData, "strData");
	ret.push_back(Pair("data", std::string(strData)));
	CheckIsValid(strSig, "strSig");
	ret.push_back(Pair("sig", std::string(strSig)));
	CheckIsValid(strFork, "strFork");
	ret.push_back(Pair("fork", std::string(strFork)));
	if (nConfirmations.IsValid())
	{
		ret.push_back(Pair("confirmations", int64(nConfirmations)));
	}

	return ret;
}
CTransactionData& CTransactionData::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CTransactionData");
	auto obj = v.get_obj();
	auto valTxid = find_value(obj, "txid");
	CheckJSONType(valTxid, "string", "txid");
	strTxid = valTxid.get_str();
	auto valVersion = find_value(obj, "version");
	CheckJSONType(valVersion, "uint", "version");
	nVersion = valVersion.get_uint64();
	auto valType = find_value(obj, "type");
	CheckJSONType(valType, "string", "type");
	strType = valType.get_str();
	auto valTime = find_value(obj, "time");
	CheckJSONType(valTime, "uint", "time");
	nTime = valTime.get_uint64();
	auto valLockuntil = find_value(obj, "lockuntil");
	CheckJSONType(valLockuntil, "uint", "lockuntil");
	nLockuntil = valLockuntil.get_uint64();
	auto valBlockhash = find_value(obj, "blockhash");
	CheckJSONType(valBlockhash, "string", "blockhash");
	strBlockhash = valBlockhash.get_str();
	auto valVin = find_value(obj, "vin");
	CheckJSONType(valVin, "array", "vin");
	auto vecVinArray = valVin.get_array();
	for (auto& v : vecVinArray)
	{
		vecVin.push_back(CRPCVector<CVin>::value_type().FromJSON(v));
	}
	auto valSendfrom = find_value(obj, "sendfrom");
	CheckJSONType(valSendfrom, "string", "sendfrom");
	strSendfrom = valSendfrom.get_str();
	auto valSendto = find_value(obj, "sendto");
	CheckJSONType(valSendto, "string", "sendto");
	strSendto = valSendto.get_str();
	auto valAmount = find_value(obj, "amount");
	CheckJSONType(valAmount, "double", "amount");
	dAmount = valAmount.get_real();
	auto valTxfee = find_value(obj, "txfee");
	CheckJSONType(valTxfee, "double", "txfee");
	dTxfee = valTxfee.get_real();
	auto valData = find_value(obj, "data");
	CheckJSONType(valData, "string", "data");
	strData = valData.get_str();
	auto valSig = find_value(obj, "sig");
	CheckJSONType(valSig, "string", "sig");
	strSig = valSig.get_str();
	auto valFork = find_value(obj, "fork");
	CheckJSONType(valFork, "string", "fork");
	strFork = valFork.get_str();
	auto valConfirmations = find_value(obj, "confirmations");
	if (!valConfirmations.is_null())
	{
		CheckJSONType(valConfirmations, "int", "confirmations");
		nConfirmations = valConfirmations.get_int64();
	}
	return *this;
}
bool CTransactionData::IsValid() const
{
	if (!strTxid.IsValid()) { return false; }
	if (!nVersion.IsValid()) { return false; }
	if (!strType.IsValid()) { return false; }
	if (!nTime.IsValid()) { return false; }
	if (!nLockuntil.IsValid()) { return false; }
	if (!strBlockhash.IsValid()) { return false; }
	if (!vecVin.IsValid()) { return false; }
	if (!strSendfrom.IsValid()) { return false; }
	if (!strSendto.IsValid()) { return false; }
	if (!dAmount.IsValid()) { return false; }
	if (!dTxfee.IsValid()) { return false; }
	if (!strData.IsValid()) { return false; }
	if (!strSig.IsValid()) { return false; }
	if (!strFork.IsValid()) { return false; }
	return true;
}

// CWalletTxData
CWalletTxData::CWalletTxData() {}
CWalletTxData::CWalletTxData(const CRPCString& strTxid, const CRPCString& strFork, const CRPCString& strType, const CRPCUint64& nTime, const CRPCBool& fSend, const CRPCString& strTo, const CRPCDouble& dAmount, const CRPCDouble& dFee, const CRPCUint64& nLockuntil, const CRPCInt64& nBlockheight, const CRPCString& strFrom)
	: strTxid(strTxid), strFork(strFork), strType(strType), nTime(nTime), fSend(fSend), strTo(strTo), dAmount(dAmount), dFee(dFee), nLockuntil(nLockuntil), nBlockheight(nBlockheight), strFrom(strFrom)
{
}
CWalletTxData::CWalletTxData(const CRPCType& null)
	: strTxid(null), strFork(null), strType(null), nTime(null), fSend(null), strTo(null), dAmount(null), dFee(null), nLockuntil(null), nBlockheight(null), strFrom(null)
{
}
Value CWalletTxData::ToJSON() const
{
	Object ret;
	CheckIsValid(strTxid, "strTxid");
	ret.push_back(Pair("txid", std::string(strTxid)));
	CheckIsValid(strFork, "strFork");
	ret.push_back(Pair("fork", std::string(strFork)));
	CheckIsValid(strType, "strType");
	ret.push_back(Pair("type", std::string(strType)));
	CheckIsValid(nTime, "nTime");
	ret.push_back(Pair("time", uint64(nTime)));
	CheckIsValid(fSend, "fSend");
	ret.push_back(Pair("send", bool(fSend)));
	CheckIsValid(strTo, "strTo");
	ret.push_back(Pair("to", std::string(strTo)));
	CheckIsValid(dAmount, "dAmount");
	ret.push_back(Pair("amount", double(dAmount)));
	CheckIsValid(dFee, "dFee");
	ret.push_back(Pair("fee", double(dFee)));
	CheckIsValid(nLockuntil, "nLockuntil");
	ret.push_back(Pair("lockuntil", uint64(nLockuntil)));
	if (nBlockheight.IsValid())
	{
		ret.push_back(Pair("blockheight", int64(nBlockheight)));
	}
	if (strFrom.IsValid())
	{
		ret.push_back(Pair("from", std::string(strFrom)));
	}

	return ret;
}
CWalletTxData& CWalletTxData::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CWalletTxData");
	auto obj = v.get_obj();
	auto valTxid = find_value(obj, "txid");
	CheckJSONType(valTxid, "string", "txid");
	strTxid = valTxid.get_str();
	auto valFork = find_value(obj, "fork");
	CheckJSONType(valFork, "string", "fork");
	strFork = valFork.get_str();
	auto valType = find_value(obj, "type");
	CheckJSONType(valType, "string", "type");
	strType = valType.get_str();
	auto valTime = find_value(obj, "time");
	CheckJSONType(valTime, "uint", "time");
	nTime = valTime.get_uint64();
	auto valSend = find_value(obj, "send");
	CheckJSONType(valSend, "bool", "send");
	fSend = valSend.get_bool();
	auto valTo = find_value(obj, "to");
	CheckJSONType(valTo, "string", "to");
	strTo = valTo.get_str();
	auto valAmount = find_value(obj, "amount");
	CheckJSONType(valAmount, "double", "amount");
	dAmount = valAmount.get_real();
	auto valFee = find_value(obj, "fee");
	CheckJSONType(valFee, "double", "fee");
	dFee = valFee.get_real();
	auto valLockuntil = find_value(obj, "lockuntil");
	CheckJSONType(valLockuntil, "uint", "lockuntil");
	nLockuntil = valLockuntil.get_uint64();
	auto valBlockheight = find_value(obj, "blockheight");
	if (!valBlockheight.is_null())
	{
		CheckJSONType(valBlockheight, "int", "blockheight");
		nBlockheight = valBlockheight.get_int64();
	}
	auto valFrom = find_value(obj, "from");
	if (!valFrom.is_null())
	{
		CheckJSONType(valFrom, "string", "from");
		strFrom = valFrom.get_str();
	}
	return *this;
}
bool CWalletTxData::IsValid() const
{
	if (!strTxid.IsValid()) { return false; }
	if (!strFork.IsValid()) { return false; }
	if (!strType.IsValid()) { return false; }
	if (!nTime.IsValid()) { return false; }
	if (!fSend.IsValid()) { return false; }
	if (!strTo.IsValid()) { return false; }
	if (!dAmount.IsValid()) { return false; }
	if (!dFee.IsValid()) { return false; }
	if (!nLockuntil.IsValid()) { return false; }
	return true;
}

// CBlockData
CBlockData::CBlockData() {}
CBlockData::CBlockData(const CRPCString& strHash, const CRPCString& strHashprev, const CRPCUint64& nVersion, const CRPCString& strType, const CRPCUint64& nTime, const CRPCString& strFork, const CRPCUint64& nHeight, const CRPCString& strTxmint, const CRPCVector<std::string>& vecTx, const CRPCString& strPrev)
	: strHash(strHash), strHashprev(strHashprev), nVersion(nVersion), strType(strType), nTime(nTime), strFork(strFork), nHeight(nHeight), strTxmint(strTxmint), vecTx(vecTx), strPrev(strPrev)
{
}
CBlockData::CBlockData(const CRPCType& null)
	: strHash(null), strHashprev(null), nVersion(null), strType(null), nTime(null), strFork(null), nHeight(null), strTxmint(null), vecTx(null), strPrev(null)
{
}
Value CBlockData::ToJSON() const
{
	Object ret;
	CheckIsValid(strHash, "strHash");
	ret.push_back(Pair("hash", std::string(strHash)));
	CheckIsValid(strHashprev, "strHashprev");
	ret.push_back(Pair("hashPrev", std::string(strHashprev)));
	CheckIsValid(nVersion, "nVersion");
	ret.push_back(Pair("version", uint64(nVersion)));
	CheckIsValid(strType, "strType");
	ret.push_back(Pair("type", std::string(strType)));
	CheckIsValid(nTime, "nTime");
	ret.push_back(Pair("time", uint64(nTime)));
	CheckIsValid(strFork, "strFork");
	ret.push_back(Pair("fork", std::string(strFork)));
	CheckIsValid(nHeight, "nHeight");
	ret.push_back(Pair("height", uint64(nHeight)));
	CheckIsValid(strTxmint, "strTxmint");
	ret.push_back(Pair("txmint", std::string(strTxmint)));
	CheckIsValid(vecTx, "vecTx");
	Array vecTxArray;
	for (auto& v : vecTx)
	{
		vecTxArray.push_back(std::string(v));
	}
	ret.push_back(Pair("tx", vecTxArray));
	if (strPrev.IsValid())
	{
		ret.push_back(Pair("prev", std::string(strPrev)));
	}

	return ret;
}
CBlockData& CBlockData::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CBlockData");
	auto obj = v.get_obj();
	auto valHash = find_value(obj, "hash");
	CheckJSONType(valHash, "string", "hash");
	strHash = valHash.get_str();
	auto valHashprev = find_value(obj, "hashPrev");
	CheckJSONType(valHashprev, "string", "hashPrev");
	strHashprev = valHashprev.get_str();
	auto valVersion = find_value(obj, "version");
	CheckJSONType(valVersion, "uint", "version");
	nVersion = valVersion.get_uint64();
	auto valType = find_value(obj, "type");
	CheckJSONType(valType, "string", "type");
	strType = valType.get_str();
	auto valTime = find_value(obj, "time");
	CheckJSONType(valTime, "uint", "time");
	nTime = valTime.get_uint64();
	auto valFork = find_value(obj, "fork");
	CheckJSONType(valFork, "string", "fork");
	strFork = valFork.get_str();
	auto valHeight = find_value(obj, "height");
	CheckJSONType(valHeight, "uint", "height");
	nHeight = valHeight.get_uint64();
	auto valTxmint = find_value(obj, "txmint");
	CheckJSONType(valTxmint, "string", "txmint");
	strTxmint = valTxmint.get_str();
	auto valTx = find_value(obj, "tx");
	CheckJSONType(valTx, "array", "tx");
	auto vecTxArray = valTx.get_array();
	for (auto& v : vecTxArray)
	{
		vecTx.push_back(v.get_str());
	}
	auto valPrev = find_value(obj, "prev");
	if (!valPrev.is_null())
	{
		CheckJSONType(valPrev, "string", "prev");
		strPrev = valPrev.get_str();
	}
	return *this;
}
bool CBlockData::IsValid() const
{
	if (!strHash.IsValid()) { return false; }
	if (!strHashprev.IsValid()) { return false; }
	if (!nVersion.IsValid()) { return false; }
	if (!strType.IsValid()) { return false; }
	if (!nTime.IsValid()) { return false; }
	if (!strFork.IsValid()) { return false; }
	if (!nHeight.IsValid()) { return false; }
	if (!strTxmint.IsValid()) { return false; }
	if (!vecTx.IsValid()) { return false; }
	return true;
}

// Cblockdatadetail
Cblockdatadetail::Cblockdatadetail() {}
Cblockdatadetail::Cblockdatadetail(const CRPCString& strHash, const CRPCString& strHashprev, const CRPCUint64& nVersion, const CRPCString& strType, const CRPCUint64& nTime, const CRPCUint64& nBits, const CRPCString& strFork, const CRPCUint64& nHeight, const CTransactionData& txmint, const CRPCVector<CTransactionData>& vecTx, const CRPCString& strPrev)
	: strHash(strHash), strHashprev(strHashprev), nVersion(nVersion), strType(strType), nTime(nTime), nBits(nBits), strFork(strFork), nHeight(nHeight), txmint(txmint), vecTx(vecTx), strPrev(strPrev)
{
}
Cblockdatadetail::Cblockdatadetail(const CRPCType& null)
	: strHash(null), strHashprev(null), nVersion(null), strType(null), nTime(null), nBits(null), strFork(null), nHeight(null), txmint(null), vecTx(null), strPrev(null)
{
}
Value Cblockdatadetail::ToJSON() const
{
	Object ret;
	CheckIsValid(strHash, "strHash");
	ret.push_back(Pair("hash", std::string(strHash)));
	CheckIsValid(strHashprev, "strHashprev");
	ret.push_back(Pair("hashPrev", std::string(strHashprev)));
	CheckIsValid(nVersion, "nVersion");
	ret.push_back(Pair("version", uint64(nVersion)));
	CheckIsValid(strType, "strType");
	ret.push_back(Pair("type", std::string(strType)));
	CheckIsValid(nTime, "nTime");
	ret.push_back(Pair("time", uint64(nTime)));
	CheckIsValid(nBits, "nBits");
	ret.push_back(Pair("bits", uint64(nBits)));
	CheckIsValid(strFork, "strFork");
	ret.push_back(Pair("fork", std::string(strFork)));
	CheckIsValid(nHeight, "nHeight");
	ret.push_back(Pair("height", uint64(nHeight)));
	CheckIsValid(txmint, "txmint");
	ret.push_back(Pair("txmint", txmint.ToJSON()));
	CheckIsValid(vecTx, "vecTx");
	Array vecTxArray;
	for (auto& v : vecTx)
	{
		vecTxArray.push_back(v.ToJSON());
	}
	ret.push_back(Pair("tx", vecTxArray));
	if (strPrev.IsValid())
	{
		ret.push_back(Pair("prev", std::string(strPrev)));
	}

	return ret;
}
Cblockdatadetail& Cblockdatadetail::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "Cblockdatadetail");
	auto obj = v.get_obj();
	auto valHash = find_value(obj, "hash");
	CheckJSONType(valHash, "string", "hash");
	strHash = valHash.get_str();
	auto valHashprev = find_value(obj, "hashPrev");
	CheckJSONType(valHashprev, "string", "hashPrev");
	strHashprev = valHashprev.get_str();
	auto valVersion = find_value(obj, "version");
	CheckJSONType(valVersion, "uint", "version");
	nVersion = valVersion.get_uint64();
	auto valType = find_value(obj, "type");
	CheckJSONType(valType, "string", "type");
	strType = valType.get_str();
	auto valTime = find_value(obj, "time");
	CheckJSONType(valTime, "uint", "time");
	nTime = valTime.get_uint64();
	auto valBits = find_value(obj, "bits");
	CheckJSONType(valBits, "uint", "bits");
	nBits = valBits.get_uint64();
	auto valFork = find_value(obj, "fork");
	CheckJSONType(valFork, "string", "fork");
	strFork = valFork.get_str();
	auto valHeight = find_value(obj, "height");
	CheckJSONType(valHeight, "uint", "height");
	nHeight = valHeight.get_uint64();
	auto valTxmint = find_value(obj, "txmint");
	CheckJSONType(valTxmint, "object", "txmint");
	txmint.FromJSON(valTxmint.get_obj());
	auto valTx = find_value(obj, "tx");
	CheckJSONType(valTx, "array", "tx");
	auto vecTxArray = valTx.get_array();
	for (auto& v : vecTxArray)
	{
		vecTx.push_back(CRPCVector<CTransactionData>::value_type().FromJSON(v));
	}
	auto valPrev = find_value(obj, "prev");
	if (!valPrev.is_null())
	{
		CheckJSONType(valPrev, "string", "prev");
		strPrev = valPrev.get_str();
	}
	return *this;
}
bool Cblockdatadetail::IsValid() const
{
	if (!strHash.IsValid()) { return false; }
	if (!strHashprev.IsValid()) { return false; }
	if (!nVersion.IsValid()) { return false; }
	if (!strType.IsValid()) { return false; }
	if (!nTime.IsValid()) { return false; }
	if (!nBits.IsValid()) { return false; }
	if (!strFork.IsValid()) { return false; }
	if (!nHeight.IsValid()) { return false; }
	if (!txmint.IsValid()) { return false; }
	if (!vecTx.IsValid()) { return false; }
	return true;
}

/////////////////////////////////////////////////////
// help

// CHelpParam
CHelpParam::CHelpParam() {}
CHelpParam::CHelpParam(const CRPCString& strCommand)
	: strCommand(strCommand)
{
}
Value CHelpParam::ToJSON() const
{
	Object ret;
	if (strCommand.IsValid())
	{
		ret.push_back(Pair("command", std::string(strCommand)));
	}

	return ret;
}
CHelpParam& CHelpParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "help");
	auto obj = v.get_obj();
	auto valCommand = find_value(obj, "command");
	if (!valCommand.is_null())
	{
		CheckJSONType(valCommand, "string", "command");
		strCommand = valCommand.get_str();
	}
	return *this;
}
string CHelpParam::Method() const
{
	return "help";
}

// CHelpResult
CHelpResult::CHelpResult() {}
CHelpResult::CHelpResult(const CRPCString& strHelp)
	: strHelp(strHelp)
{
}
Value CHelpResult::ToJSON() const
{
	CheckIsValid(strHelp, "strHelp");
	Value val;
	val = Value(strHelp);
	return val;
}
CHelpResult& CHelpResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "help");
	strHelp = v.get_str();
	return *this;
}
string CHelpResult::Method() const
{
	return "help";
}

/////////////////////////////////////////////////////
// stop

// CStopParam
CStopParam::CStopParam() {}
Value CStopParam::ToJSON() const
{
	Object ret;

	return ret;
}
CStopParam& CStopParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "stop");
	auto obj = v.get_obj();
	return *this;
}
string CStopParam::Method() const
{
	return "stop";
}

// CStopResult
CStopResult::CStopResult() {}
CStopResult::CStopResult(const CRPCString& strResult)
	: strResult(strResult)
{
}
Value CStopResult::ToJSON() const
{
	CheckIsValid(strResult, "strResult");
	Value val;
	val = Value(strResult);
	return val;
}
CStopResult& CStopResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "result");
	strResult = v.get_str();
	return *this;
}
string CStopResult::Method() const
{
	return "stop";
}

/////////////////////////////////////////////////////
// version

// CVersionParam
CVersionParam::CVersionParam() {}
Value CVersionParam::ToJSON() const
{
	Object ret;

	return ret;
}
CVersionParam& CVersionParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "version");
	auto obj = v.get_obj();
	return *this;
}
string CVersionParam::Method() const
{
	return "version";
}

// CVersionResult
CVersionResult::CVersionResult() {}
CVersionResult::CVersionResult(const CRPCString& strVersion)
	: strVersion(strVersion)
{
}
Value CVersionResult::ToJSON() const
{
	CheckIsValid(strVersion, "strVersion");
	Value val;
	val = Value(strVersion);
	return val;
}
CVersionResult& CVersionResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "version");
	strVersion = v.get_str();
	return *this;
}
string CVersionResult::Method() const
{
	return "version";
}

/////////////////////////////////////////////////////
// getpeercount

// CGetPeerCountParam
CGetPeerCountParam::CGetPeerCountParam() {}
Value CGetPeerCountParam::ToJSON() const
{
	Object ret;

	return ret;
}
CGetPeerCountParam& CGetPeerCountParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "getpeercount");
	auto obj = v.get_obj();
	return *this;
}
string CGetPeerCountParam::Method() const
{
	return "getpeercount";
}

// CGetPeerCountResult
CGetPeerCountResult::CGetPeerCountResult() {}
CGetPeerCountResult::CGetPeerCountResult(const CRPCInt64& nCount)
	: nCount(nCount)
{
}
Value CGetPeerCountResult::ToJSON() const
{
	CheckIsValid(nCount, "nCount");
	Value val;
	val = Value(nCount);
	return val;
}
CGetPeerCountResult& CGetPeerCountResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "int", "count");
	nCount = v.get_int64();
	return *this;
}
string CGetPeerCountResult::Method() const
{
	return "getpeercount";
}

/////////////////////////////////////////////////////
// listpeer

// CListPeerParam
CListPeerParam::CListPeerParam() {}
Value CListPeerParam::ToJSON() const
{
	Object ret;

	return ret;
}
CListPeerParam& CListPeerParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "listpeer");
	auto obj = v.get_obj();
	return *this;
}
string CListPeerParam::Method() const
{
	return "listpeer";
}

// CListPeerResult::CPeer
CListPeerResult::CPeer::CPeer() {}
CListPeerResult::CPeer::CPeer(const CRPCString& strAddress, const CRPCString& strServices, const CRPCString& strLastsend, const CRPCString& strLastrecv, const CRPCString& strConntime, const CRPCInt64& nPingtime, const CRPCString& strVersion, const CRPCString& strSubver, const CRPCBool& fInbound, const CRPCInt64& nHeight, const CRPCInt64& nBanscore)
	: strAddress(strAddress), strServices(strServices), strLastsend(strLastsend), strLastrecv(strLastrecv), strConntime(strConntime), nPingtime(nPingtime), strVersion(strVersion), strSubver(strSubver), fInbound(fInbound), nHeight(nHeight), nBanscore(nBanscore)
{
}
CListPeerResult::CPeer::CPeer(const CRPCType& null)
	: strAddress(null), strServices(null), strLastsend(null), strLastrecv(null), strConntime(null), nPingtime(null), strVersion(null), strSubver(null), fInbound(null), nHeight(null), nBanscore(null)
{
}
Value CListPeerResult::CPeer::ToJSON() const
{
	Object ret;
	CheckIsValid(strAddress, "strAddress");
	ret.push_back(Pair("address", std::string(strAddress)));
	CheckIsValid(strServices, "strServices");
	ret.push_back(Pair("services", std::string(strServices)));
	CheckIsValid(strLastsend, "strLastsend");
	ret.push_back(Pair("lastsend", std::string(strLastsend)));
	CheckIsValid(strLastrecv, "strLastrecv");
	ret.push_back(Pair("lastrecv", std::string(strLastrecv)));
	CheckIsValid(strConntime, "strConntime");
	ret.push_back(Pair("conntime", std::string(strConntime)));
	CheckIsValid(nPingtime, "nPingtime");
	ret.push_back(Pair("pingtime", int64(nPingtime)));
	CheckIsValid(strVersion, "strVersion");
	ret.push_back(Pair("version", std::string(strVersion)));
	CheckIsValid(strSubver, "strSubver");
	ret.push_back(Pair("subver", std::string(strSubver)));
	CheckIsValid(fInbound, "fInbound");
	ret.push_back(Pair("inbound", bool(fInbound)));
	CheckIsValid(nHeight, "nHeight");
	ret.push_back(Pair("height", int64(nHeight)));
	CheckIsValid(nBanscore, "nBanscore");
	ret.push_back(Pair("banscore", int64(nBanscore)));

	return ret;
}
CListPeerResult::CPeer& CListPeerResult::CPeer::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CListPeerResult::CPeer");
	auto obj = v.get_obj();
	auto valAddress = find_value(obj, "address");
	CheckJSONType(valAddress, "string", "address");
	strAddress = valAddress.get_str();
	auto valServices = find_value(obj, "services");
	CheckJSONType(valServices, "string", "services");
	strServices = valServices.get_str();
	auto valLastsend = find_value(obj, "lastsend");
	CheckJSONType(valLastsend, "string", "lastsend");
	strLastsend = valLastsend.get_str();
	auto valLastrecv = find_value(obj, "lastrecv");
	CheckJSONType(valLastrecv, "string", "lastrecv");
	strLastrecv = valLastrecv.get_str();
	auto valConntime = find_value(obj, "conntime");
	CheckJSONType(valConntime, "string", "conntime");
	strConntime = valConntime.get_str();
	auto valPingtime = find_value(obj, "pingtime");
	CheckJSONType(valPingtime, "int", "pingtime");
	nPingtime = valPingtime.get_int64();
	auto valVersion = find_value(obj, "version");
	CheckJSONType(valVersion, "string", "version");
	strVersion = valVersion.get_str();
	auto valSubver = find_value(obj, "subver");
	CheckJSONType(valSubver, "string", "subver");
	strSubver = valSubver.get_str();
	auto valInbound = find_value(obj, "inbound");
	CheckJSONType(valInbound, "bool", "inbound");
	fInbound = valInbound.get_bool();
	auto valHeight = find_value(obj, "height");
	CheckJSONType(valHeight, "int", "height");
	nHeight = valHeight.get_int64();
	auto valBanscore = find_value(obj, "banscore");
	CheckJSONType(valBanscore, "int", "banscore");
	nBanscore = valBanscore.get_int64();
	return *this;
}
bool CListPeerResult::CPeer::IsValid() const
{
	if (!strAddress.IsValid()) { return false; }
	if (!strServices.IsValid()) { return false; }
	if (!strLastsend.IsValid()) { return false; }
	if (!strLastrecv.IsValid()) { return false; }
	if (!strConntime.IsValid()) { return false; }
	if (!nPingtime.IsValid()) { return false; }
	if (!strVersion.IsValid()) { return false; }
	if (!strSubver.IsValid()) { return false; }
	if (!fInbound.IsValid()) { return false; }
	if (!nHeight.IsValid()) { return false; }
	if (!nBanscore.IsValid()) { return false; }
	return true;
}

// CListPeerResult
CListPeerResult::CListPeerResult() {}
CListPeerResult::CListPeerResult(const CRPCVector<CPeer>& vecPeer)
	: vecPeer(vecPeer)
{
}
Value CListPeerResult::ToJSON() const
{
	Array ret;
	for (auto& v : vecPeer)
	{
		ret.push_back(v.ToJSON());
	}
	return ret;
}
CListPeerResult& CListPeerResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "array", "peer");
	auto vecPeerArray = v.get_array();
	for (auto& v : vecPeerArray)
	{
		vecPeer.push_back(CRPCVector<CPeer>::value_type().FromJSON(v));
	}
	return *this;
}
string CListPeerResult::Method() const
{
	return "listpeer";
}

/////////////////////////////////////////////////////
// addnode

// CAddNodeParam
CAddNodeParam::CAddNodeParam() {}
CAddNodeParam::CAddNodeParam(const CRPCString& strNode)
	: strNode(strNode)
{
}
Value CAddNodeParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strNode, "strNode");
	ret.push_back(Pair("node", std::string(strNode)));

	return ret;
}
CAddNodeParam& CAddNodeParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "addnode");
	auto obj = v.get_obj();
	auto valNode = find_value(obj, "node");
	CheckJSONType(valNode, "string", "node");
	strNode = valNode.get_str();
	return *this;
}
string CAddNodeParam::Method() const
{
	return "addnode";
}

// CAddNodeResult
CAddNodeResult::CAddNodeResult() {}
CAddNodeResult::CAddNodeResult(const CRPCString& strResult)
	: strResult(strResult)
{
}
Value CAddNodeResult::ToJSON() const
{
	CheckIsValid(strResult, "strResult");
	Value val;
	val = Value(strResult);
	return val;
}
CAddNodeResult& CAddNodeResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "result");
	strResult = v.get_str();
	return *this;
}
string CAddNodeResult::Method() const
{
	return "addnode";
}

/////////////////////////////////////////////////////
// removenode

// CRemoveNodeParam
CRemoveNodeParam::CRemoveNodeParam() {}
CRemoveNodeParam::CRemoveNodeParam(const CRPCString& strNode)
	: strNode(strNode)
{
}
Value CRemoveNodeParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strNode, "strNode");
	ret.push_back(Pair("node", std::string(strNode)));

	return ret;
}
CRemoveNodeParam& CRemoveNodeParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "removenode");
	auto obj = v.get_obj();
	auto valNode = find_value(obj, "node");
	CheckJSONType(valNode, "string", "node");
	strNode = valNode.get_str();
	return *this;
}
string CRemoveNodeParam::Method() const
{
	return "removenode";
}

// CRemoveNodeResult
CRemoveNodeResult::CRemoveNodeResult() {}
CRemoveNodeResult::CRemoveNodeResult(const CRPCString& strResult)
	: strResult(strResult)
{
}
Value CRemoveNodeResult::ToJSON() const
{
	CheckIsValid(strResult, "strResult");
	Value val;
	val = Value(strResult);
	return val;
}
CRemoveNodeResult& CRemoveNodeResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "result");
	strResult = v.get_str();
	return *this;
}
string CRemoveNodeResult::Method() const
{
	return "removenode";
}

/////////////////////////////////////////////////////
// getforkcount

// CGetForkCountParam
CGetForkCountParam::CGetForkCountParam() {}
Value CGetForkCountParam::ToJSON() const
{
	Object ret;

	return ret;
}
CGetForkCountParam& CGetForkCountParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "getforkcount");
	auto obj = v.get_obj();
	return *this;
}
string CGetForkCountParam::Method() const
{
	return "getforkcount";
}

// CGetForkCountResult
CGetForkCountResult::CGetForkCountResult() {}
CGetForkCountResult::CGetForkCountResult(const CRPCInt64& nCount)
	: nCount(nCount)
{
}
Value CGetForkCountResult::ToJSON() const
{
	CheckIsValid(nCount, "nCount");
	Value val;
	val = Value(nCount);
	return val;
}
CGetForkCountResult& CGetForkCountResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "int", "count");
	nCount = v.get_int64();
	return *this;
}
string CGetForkCountResult::Method() const
{
	return "getforkcount";
}

/////////////////////////////////////////////////////
// listfork

// CListForkParam
CListForkParam::CListForkParam() {}
CListForkParam::CListForkParam(const CRPCBool& fAll)
	: fAll(fAll)
{
}
Value CListForkParam::ToJSON() const
{
	Object ret;
	if (fAll.IsValid())
	{
		ret.push_back(Pair("all", bool(fAll)));
	}

	return ret;
}
CListForkParam& CListForkParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "listfork");
	auto obj = v.get_obj();
	auto valAll = find_value(obj, "all");
	if (!valAll.is_null())
	{
		CheckJSONType(valAll, "bool", "all");
		fAll = valAll.get_bool();
	}
	return *this;
}
string CListForkParam::Method() const
{
	return "listfork";
}

// CListForkResult::CProfile
CListForkResult::CProfile::CProfile() {}
CListForkResult::CProfile::CProfile(const CRPCString& strFork, const CRPCString& strName, const CRPCString& strSymbol, const CRPCDouble& dAmount, const CRPCDouble& dReward, const CRPCUint64& nHalvecycle, const CRPCBool& fIsolated, const CRPCBool& fPrivate, const CRPCBool& fEnclosed, const CRPCString& strOwner)
	: strFork(strFork), strName(strName), strSymbol(strSymbol), dAmount(dAmount), dReward(dReward), nHalvecycle(nHalvecycle), fIsolated(fIsolated), fPrivate(fPrivate), fEnclosed(fEnclosed), strOwner(strOwner)
{
}
CListForkResult::CProfile::CProfile(const CRPCType& null)
	: strFork(null), strName(null), strSymbol(null), dAmount(null), dReward(null), nHalvecycle(null), fIsolated(null), fPrivate(null), fEnclosed(null), strOwner(null)
{
}
Value CListForkResult::CProfile::ToJSON() const
{
	Object ret;
	CheckIsValid(strFork, "strFork");
	ret.push_back(Pair("fork", std::string(strFork)));
	CheckIsValid(strName, "strName");
	ret.push_back(Pair("name", std::string(strName)));
	CheckIsValid(strSymbol, "strSymbol");
	ret.push_back(Pair("symbol", std::string(strSymbol)));
	CheckIsValid(dAmount, "dAmount");
	ret.push_back(Pair("amount", double(dAmount)));
	CheckIsValid(dReward, "dReward");
	ret.push_back(Pair("reward", double(dReward)));
	CheckIsValid(nHalvecycle, "nHalvecycle");
	ret.push_back(Pair("halvecycle", uint64(nHalvecycle)));
	CheckIsValid(fIsolated, "fIsolated");
	ret.push_back(Pair("isolated", bool(fIsolated)));
	CheckIsValid(fPrivate, "fPrivate");
	ret.push_back(Pair("private", bool(fPrivate)));
	CheckIsValid(fEnclosed, "fEnclosed");
	ret.push_back(Pair("enclosed", bool(fEnclosed)));
	CheckIsValid(strOwner, "strOwner");
	ret.push_back(Pair("owner", std::string(strOwner)));

	return ret;
}
CListForkResult::CProfile& CListForkResult::CProfile::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CListForkResult::CProfile");
	auto obj = v.get_obj();
	auto valFork = find_value(obj, "fork");
	CheckJSONType(valFork, "string", "fork");
	strFork = valFork.get_str();
	auto valName = find_value(obj, "name");
	CheckJSONType(valName, "string", "name");
	strName = valName.get_str();
	auto valSymbol = find_value(obj, "symbol");
	CheckJSONType(valSymbol, "string", "symbol");
	strSymbol = valSymbol.get_str();
	auto valAmount = find_value(obj, "amount");
	CheckJSONType(valAmount, "double", "amount");
	dAmount = valAmount.get_real();
	auto valReward = find_value(obj, "reward");
	CheckJSONType(valReward, "double", "reward");
	dReward = valReward.get_real();
	auto valHalvecycle = find_value(obj, "halvecycle");
	CheckJSONType(valHalvecycle, "uint", "halvecycle");
	nHalvecycle = valHalvecycle.get_uint64();
	auto valIsolated = find_value(obj, "isolated");
	CheckJSONType(valIsolated, "bool", "isolated");
	fIsolated = valIsolated.get_bool();
	auto valPrivate = find_value(obj, "private");
	CheckJSONType(valPrivate, "bool", "private");
	fPrivate = valPrivate.get_bool();
	auto valEnclosed = find_value(obj, "enclosed");
	CheckJSONType(valEnclosed, "bool", "enclosed");
	fEnclosed = valEnclosed.get_bool();
	auto valOwner = find_value(obj, "owner");
	CheckJSONType(valOwner, "string", "owner");
	strOwner = valOwner.get_str();
	return *this;
}
bool CListForkResult::CProfile::IsValid() const
{
	if (!strFork.IsValid()) { return false; }
	if (!strName.IsValid()) { return false; }
	if (!strSymbol.IsValid()) { return false; }
	if (!dAmount.IsValid()) { return false; }
	if (!dReward.IsValid()) { return false; }
	if (!nHalvecycle.IsValid()) { return false; }
	if (!fIsolated.IsValid()) { return false; }
	if (!fPrivate.IsValid()) { return false; }
	if (!fEnclosed.IsValid()) { return false; }
	if (!strOwner.IsValid()) { return false; }
	return true;
}

// CListForkResult
CListForkResult::CListForkResult() {}
CListForkResult::CListForkResult(const CRPCVector<CProfile>& vecProfile)
	: vecProfile(vecProfile)
{
}
Value CListForkResult::ToJSON() const
{
	Array ret;
	for (auto& v : vecProfile)
	{
		ret.push_back(v.ToJSON());
	}
	return ret;
}
CListForkResult& CListForkResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "array", "profile");
	auto vecProfileArray = v.get_array();
	for (auto& v : vecProfileArray)
	{
		vecProfile.push_back(CRPCVector<CProfile>::value_type().FromJSON(v));
	}
	return *this;
}
string CListForkResult::Method() const
{
	return "listfork";
}

/////////////////////////////////////////////////////
// getgenealogy

// CGetGenealogyParam
CGetGenealogyParam::CGetGenealogyParam() {}
CGetGenealogyParam::CGetGenealogyParam(const CRPCString& strFork)
	: strFork(strFork)
{
}
Value CGetGenealogyParam::ToJSON() const
{
	Object ret;
	if (strFork.IsValid())
	{
		ret.push_back(Pair("fork", std::string(strFork)));
	}

	return ret;
}
CGetGenealogyParam& CGetGenealogyParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "getgenealogy");
	auto obj = v.get_obj();
	auto valFork = find_value(obj, "fork");
	if (!valFork.is_null())
	{
		CheckJSONType(valFork, "string", "fork");
		strFork = valFork.get_str();
	}
	return *this;
}
string CGetGenealogyParam::Method() const
{
	return "getgenealogy";
}

// CGetGenealogyResult::CSubline
CGetGenealogyResult::CSubline::CSubline() {}
CGetGenealogyResult::CSubline::CSubline(const CRPCString& strSub, const CRPCInt64& nHeight)
	: strSub(strSub), nHeight(nHeight)
{
}
CGetGenealogyResult::CSubline::CSubline(const CRPCType& null)
	: strSub(null), nHeight(null)
{
}
Value CGetGenealogyResult::CSubline::ToJSON() const
{
	Object ret;
	CheckIsValid(strSub, "strSub");
	ret.push_back(Pair("sub", std::string(strSub)));
	CheckIsValid(nHeight, "nHeight");
	ret.push_back(Pair("height", int64(nHeight)));

	return ret;
}
CGetGenealogyResult::CSubline& CGetGenealogyResult::CSubline::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CGetGenealogyResult::CSubline");
	auto obj = v.get_obj();
	auto valSub = find_value(obj, "sub");
	CheckJSONType(valSub, "string", "sub");
	strSub = valSub.get_str();
	auto valHeight = find_value(obj, "height");
	CheckJSONType(valHeight, "int", "height");
	nHeight = valHeight.get_int64();
	return *this;
}
bool CGetGenealogyResult::CSubline::IsValid() const
{
	if (!strSub.IsValid()) { return false; }
	if (!nHeight.IsValid()) { return false; }
	return true;
}

// CGetGenealogyResult::CAncestry
CGetGenealogyResult::CAncestry::CAncestry() {}
CGetGenealogyResult::CAncestry::CAncestry(const CRPCString& strParent, const CRPCInt64& nHeight)
	: strParent(strParent), nHeight(nHeight)
{
}
CGetGenealogyResult::CAncestry::CAncestry(const CRPCType& null)
	: strParent(null), nHeight(null)
{
}
Value CGetGenealogyResult::CAncestry::ToJSON() const
{
	Object ret;
	CheckIsValid(strParent, "strParent");
	ret.push_back(Pair("parent", std::string(strParent)));
	CheckIsValid(nHeight, "nHeight");
	ret.push_back(Pair("height", int64(nHeight)));

	return ret;
}
CGetGenealogyResult::CAncestry& CGetGenealogyResult::CAncestry::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CGetGenealogyResult::CAncestry");
	auto obj = v.get_obj();
	auto valParent = find_value(obj, "parent");
	CheckJSONType(valParent, "string", "parent");
	strParent = valParent.get_str();
	auto valHeight = find_value(obj, "height");
	CheckJSONType(valHeight, "int", "height");
	nHeight = valHeight.get_int64();
	return *this;
}
bool CGetGenealogyResult::CAncestry::IsValid() const
{
	if (!strParent.IsValid()) { return false; }
	if (!nHeight.IsValid()) { return false; }
	return true;
}

// CGetGenealogyResult
CGetGenealogyResult::CGetGenealogyResult() {}
CGetGenealogyResult::CGetGenealogyResult(const CRPCVector<CAncestry>& vecAncestry, const CRPCVector<CSubline>& vecSubline)
	: vecAncestry(vecAncestry), vecSubline(vecSubline)
{
}
Value CGetGenealogyResult::ToJSON() const
{
	Object ret;
	CheckIsValid(vecAncestry, "vecAncestry");
	Array vecAncestryArray;
	for (auto& v : vecAncestry)
	{
		vecAncestryArray.push_back(v.ToJSON());
	}
	ret.push_back(Pair("ancestry", vecAncestryArray));
	CheckIsValid(vecSubline, "vecSubline");
	Array vecSublineArray;
	for (auto& v : vecSubline)
	{
		vecSublineArray.push_back(v.ToJSON());
	}
	ret.push_back(Pair("subline", vecSublineArray));

	return ret;
}
CGetGenealogyResult& CGetGenealogyResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "getgenealogy");
	auto obj = v.get_obj();
	auto valAncestry = find_value(obj, "ancestry");
	CheckJSONType(valAncestry, "array", "ancestry");
	auto vecAncestryArray = valAncestry.get_array();
	for (auto& v : vecAncestryArray)
	{
		vecAncestry.push_back(CRPCVector<CAncestry>::value_type().FromJSON(v));
	}
	auto valSubline = find_value(obj, "subline");
	CheckJSONType(valSubline, "array", "subline");
	auto vecSublineArray = valSubline.get_array();
	for (auto& v : vecSublineArray)
	{
		vecSubline.push_back(CRPCVector<CSubline>::value_type().FromJSON(v));
	}
	return *this;
}
string CGetGenealogyResult::Method() const
{
	return "getgenealogy";
}

/////////////////////////////////////////////////////
// getblocklocation

// CGetBlockLocationParam
CGetBlockLocationParam::CGetBlockLocationParam() {}
CGetBlockLocationParam::CGetBlockLocationParam(const CRPCString& strBlock)
	: strBlock(strBlock)
{
}
Value CGetBlockLocationParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strBlock, "strBlock");
	ret.push_back(Pair("block", std::string(strBlock)));

	return ret;
}
CGetBlockLocationParam& CGetBlockLocationParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "getblocklocation");
	auto obj = v.get_obj();
	auto valBlock = find_value(obj, "block");
	CheckJSONType(valBlock, "string", "block");
	strBlock = valBlock.get_str();
	return *this;
}
string CGetBlockLocationParam::Method() const
{
	return "getblocklocation";
}

// CGetBlockLocationResult
CGetBlockLocationResult::CGetBlockLocationResult() {}
CGetBlockLocationResult::CGetBlockLocationResult(const CRPCString& strFork, const CRPCInt64& nHeight)
	: strFork(strFork), nHeight(nHeight)
{
}
Value CGetBlockLocationResult::ToJSON() const
{
	Object ret;
	CheckIsValid(strFork, "strFork");
	ret.push_back(Pair("fork", std::string(strFork)));
	CheckIsValid(nHeight, "nHeight");
	ret.push_back(Pair("height", int64(nHeight)));

	return ret;
}
CGetBlockLocationResult& CGetBlockLocationResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "getblocklocation");
	auto obj = v.get_obj();
	auto valFork = find_value(obj, "fork");
	CheckJSONType(valFork, "string", "fork");
	strFork = valFork.get_str();
	auto valHeight = find_value(obj, "height");
	CheckJSONType(valHeight, "int", "height");
	nHeight = valHeight.get_int64();
	return *this;
}
string CGetBlockLocationResult::Method() const
{
	return "getblocklocation";
}

/////////////////////////////////////////////////////
// getblockcount

// CGetBlockCountParam
CGetBlockCountParam::CGetBlockCountParam() {}
CGetBlockCountParam::CGetBlockCountParam(const CRPCString& strFork)
	: strFork(strFork)
{
}
Value CGetBlockCountParam::ToJSON() const
{
	Object ret;
	if (strFork.IsValid())
	{
		ret.push_back(Pair("fork", std::string(strFork)));
	}

	return ret;
}
CGetBlockCountParam& CGetBlockCountParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "getblockcount");
	auto obj = v.get_obj();
	auto valFork = find_value(obj, "fork");
	if (!valFork.is_null())
	{
		CheckJSONType(valFork, "string", "fork");
		strFork = valFork.get_str();
	}
	return *this;
}
string CGetBlockCountParam::Method() const
{
	return "getblockcount";
}

// CGetBlockCountResult
CGetBlockCountResult::CGetBlockCountResult() {}
CGetBlockCountResult::CGetBlockCountResult(const CRPCInt64& nCount)
	: nCount(nCount)
{
}
Value CGetBlockCountResult::ToJSON() const
{
	CheckIsValid(nCount, "nCount");
	Value val;
	val = Value(nCount);
	return val;
}
CGetBlockCountResult& CGetBlockCountResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "int", "count");
	nCount = v.get_int64();
	return *this;
}
string CGetBlockCountResult::Method() const
{
	return "getblockcount";
}

/////////////////////////////////////////////////////
// getblockhash

// CGetBlockHashParam
CGetBlockHashParam::CGetBlockHashParam() {}
CGetBlockHashParam::CGetBlockHashParam(const CRPCInt64& nHeight, const CRPCString& strFork)
	: nHeight(nHeight), strFork(strFork)
{
}
Value CGetBlockHashParam::ToJSON() const
{
	Object ret;
	CheckIsValid(nHeight, "nHeight");
	ret.push_back(Pair("height", int64(nHeight)));
	if (strFork.IsValid())
	{
		ret.push_back(Pair("fork", std::string(strFork)));
	}

	return ret;
}
CGetBlockHashParam& CGetBlockHashParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "getblockhash");
	auto obj = v.get_obj();
	auto valHeight = find_value(obj, "height");
	CheckJSONType(valHeight, "int", "height");
	nHeight = valHeight.get_int64();
	auto valFork = find_value(obj, "fork");
	if (!valFork.is_null())
	{
		CheckJSONType(valFork, "string", "fork");
		strFork = valFork.get_str();
	}
	return *this;
}
string CGetBlockHashParam::Method() const
{
	return "getblockhash";
}

// CGetBlockHashResult
CGetBlockHashResult::CGetBlockHashResult() {}
CGetBlockHashResult::CGetBlockHashResult(const CRPCVector<std::string>& vecHash)
	: vecHash(vecHash)
{
}
Value CGetBlockHashResult::ToJSON() const
{
	Array ret;
	for (auto& v : vecHash)
	{
		ret.push_back(std::string(v));
	}
	return ret;
}
CGetBlockHashResult& CGetBlockHashResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "array", "hash");
	auto vecHashArray = v.get_array();
	for (auto& v : vecHashArray)
	{
		vecHash.push_back(v.get_str());
	}
	return *this;
}
string CGetBlockHashResult::Method() const
{
	return "getblockhash";
}

/////////////////////////////////////////////////////
// getblock

// CGetBlockParam
CGetBlockParam::CGetBlockParam() {}
CGetBlockParam::CGetBlockParam(const CRPCString& strBlock)
	: strBlock(strBlock)
{
}
Value CGetBlockParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strBlock, "strBlock");
	ret.push_back(Pair("block", std::string(strBlock)));

	return ret;
}
CGetBlockParam& CGetBlockParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "getblock");
	auto obj = v.get_obj();
	auto valBlock = find_value(obj, "block");
	CheckJSONType(valBlock, "string", "block");
	strBlock = valBlock.get_str();
	return *this;
}
string CGetBlockParam::Method() const
{
	return "getblock";
}

// CGetBlockResult
CGetBlockResult::CGetBlockResult() {}
CGetBlockResult::CGetBlockResult(const CBlockData& block)
	: block(block)
{
}
Value CGetBlockResult::ToJSON() const
{
	CheckIsValid(block, "block");
	return block.ToJSON();
}
CGetBlockResult& CGetBlockResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "block");
	block.FromJSON(v.get_obj());
	return *this;
}
string CGetBlockResult::Method() const
{
	return "getblock";
}

/////////////////////////////////////////////////////
// getblockdetail

// CgetblockdetailParam
CgetblockdetailParam::CgetblockdetailParam() {}
CgetblockdetailParam::CgetblockdetailParam(const CRPCString& strBlock)
	: strBlock(strBlock)
{
}
Value CgetblockdetailParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strBlock, "strBlock");
	ret.push_back(Pair("block", std::string(strBlock)));

	return ret;
}
CgetblockdetailParam& CgetblockdetailParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "getblockdetail");
	auto obj = v.get_obj();
	auto valBlock = find_value(obj, "block");
	CheckJSONType(valBlock, "string", "block");
	strBlock = valBlock.get_str();
	return *this;
}
string CgetblockdetailParam::Method() const
{
	return "getblockdetail";
}

// CgetblockdetailResult
CgetblockdetailResult::CgetblockdetailResult() {}
CgetblockdetailResult::CgetblockdetailResult(const Cblockdatadetail& block)
	: block(block)
{
}
Value CgetblockdetailResult::ToJSON() const
{
	CheckIsValid(block, "block");
	return block.ToJSON();
}
CgetblockdetailResult& CgetblockdetailResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "block");
	block.FromJSON(v.get_obj());
	return *this;
}
string CgetblockdetailResult::Method() const
{
	return "getblockdetail";
}

/////////////////////////////////////////////////////
// gettxpool

// CGetTxPoolParam
CGetTxPoolParam::CGetTxPoolParam() {}
CGetTxPoolParam::CGetTxPoolParam(const CRPCString& strFork, const CRPCBool& fDetail)
	: strFork(strFork), fDetail(fDetail)
{
}
Value CGetTxPoolParam::ToJSON() const
{
	Object ret;
	if (strFork.IsValid())
	{
		ret.push_back(Pair("fork", std::string(strFork)));
	}
	if (fDetail.IsValid())
	{
		ret.push_back(Pair("detail", bool(fDetail)));
	}

	return ret;
}
CGetTxPoolParam& CGetTxPoolParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "gettxpool");
	auto obj = v.get_obj();
	auto valFork = find_value(obj, "fork");
	if (!valFork.is_null())
	{
		CheckJSONType(valFork, "string", "fork");
		strFork = valFork.get_str();
	}
	auto valDetail = find_value(obj, "detail");
	if (!valDetail.is_null())
	{
		CheckJSONType(valDetail, "bool", "detail");
		fDetail = valDetail.get_bool();
	}
	return *this;
}
string CGetTxPoolParam::Method() const
{
	return "gettxpool";
}

// CGetTxPoolResult::CList
CGetTxPoolResult::CList::CList() {}
CGetTxPoolResult::CList::CList(const CRPCString& strHex, const CRPCUint64& nSize)
	: strHex(strHex), nSize(nSize)
{
}
CGetTxPoolResult::CList::CList(const CRPCType& null)
	: strHex(null), nSize(null)
{
}
Value CGetTxPoolResult::CList::ToJSON() const
{
	Object ret;
	CheckIsValid(strHex, "strHex");
	ret.push_back(Pair("hex", std::string(strHex)));
	CheckIsValid(nSize, "nSize");
	ret.push_back(Pair("size", uint64(nSize)));

	return ret;
}
CGetTxPoolResult::CList& CGetTxPoolResult::CList::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CGetTxPoolResult::CList");
	auto obj = v.get_obj();
	auto valHex = find_value(obj, "hex");
	CheckJSONType(valHex, "string", "hex");
	strHex = valHex.get_str();
	auto valSize = find_value(obj, "size");
	CheckJSONType(valSize, "uint", "size");
	nSize = valSize.get_uint64();
	return *this;
}
bool CGetTxPoolResult::CList::IsValid() const
{
	if (!strHex.IsValid()) { return false; }
	if (!nSize.IsValid()) { return false; }
	return true;
}

// CGetTxPoolResult
CGetTxPoolResult::CGetTxPoolResult() {}
CGetTxPoolResult::CGetTxPoolResult(const CRPCUint64& nCount, const CRPCUint64& nSize, const CRPCVector<CList>& vecList)
	: nCount(nCount), nSize(nSize), vecList(vecList)
{
}
Value CGetTxPoolResult::ToJSON() const
{
	Object ret;
	if (nCount.IsValid())
	{
		ret.push_back(Pair("count", uint64(nCount)));
	}
	if (nSize.IsValid())
	{
		ret.push_back(Pair("size", uint64(nSize)));
	}
	if (vecList.IsValid())
	{
		Array vecListArray;
		for (auto& v : vecList)
		{
			vecListArray.push_back(v.ToJSON());
		}
		ret.push_back(Pair("list", vecListArray));
	}

	return ret;
}
CGetTxPoolResult& CGetTxPoolResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "gettxpool");
	auto obj = v.get_obj();
	auto valCount = find_value(obj, "count");
	if (!valCount.is_null())
	{
		CheckJSONType(valCount, "uint", "count");
		nCount = valCount.get_uint64();
	}
	auto valSize = find_value(obj, "size");
	if (!valSize.is_null())
	{
		CheckJSONType(valSize, "uint", "size");
		nSize = valSize.get_uint64();
	}
	auto valList = find_value(obj, "list");
	if (!valList.is_null())
	{
		CheckJSONType(valList, "array", "list");
		auto vecListArray = valList.get_array();
		for (auto& v : vecListArray)
		{
			vecList.push_back(CRPCVector<CList>::value_type().FromJSON(v));
		}
	}
	return *this;
}
string CGetTxPoolResult::Method() const
{
	return "gettxpool";
}

/////////////////////////////////////////////////////
// gettransaction

// CGetTransactionParam
CGetTransactionParam::CGetTransactionParam() {}
CGetTransactionParam::CGetTransactionParam(const CRPCString& strTxid, const CRPCBool& fSerialized)
	: strTxid(strTxid), fSerialized(fSerialized)
{
}
Value CGetTransactionParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strTxid, "strTxid");
	ret.push_back(Pair("txid", std::string(strTxid)));
	if (fSerialized.IsValid())
	{
		ret.push_back(Pair("serialized", bool(fSerialized)));
	}

	return ret;
}
CGetTransactionParam& CGetTransactionParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "gettransaction");
	auto obj = v.get_obj();
	auto valTxid = find_value(obj, "txid");
	CheckJSONType(valTxid, "string", "txid");
	strTxid = valTxid.get_str();
	auto valSerialized = find_value(obj, "serialized");
	if (!valSerialized.is_null())
	{
		CheckJSONType(valSerialized, "bool", "serialized");
		fSerialized = valSerialized.get_bool();
	}
	return *this;
}
string CGetTransactionParam::Method() const
{
	return "gettransaction";
}

// CGetTransactionResult
CGetTransactionResult::CGetTransactionResult() {}
CGetTransactionResult::CGetTransactionResult(const CRPCString& strSerialization, const CTransactionData& transaction)
	: strSerialization(strSerialization), transaction(transaction)
{
}
Value CGetTransactionResult::ToJSON() const
{
	Object ret;
	if (strSerialization.IsValid())
	{
		ret.push_back(Pair("serialization", std::string(strSerialization)));
	}
	if (transaction.IsValid())
	{
		ret.push_back(Pair("transaction", transaction.ToJSON()));
	}

	return ret;
}
CGetTransactionResult& CGetTransactionResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "gettransaction");
	auto obj = v.get_obj();
	auto valSerialization = find_value(obj, "serialization");
	if (!valSerialization.is_null())
	{
		CheckJSONType(valSerialization, "string", "serialization");
		strSerialization = valSerialization.get_str();
	}
	auto valTransaction = find_value(obj, "transaction");
	if (!valTransaction.is_null())
	{
		CheckJSONType(valTransaction, "object", "transaction");
		transaction.FromJSON(valTransaction.get_obj());
	}
	return *this;
}
string CGetTransactionResult::Method() const
{
	return "gettransaction";
}

/////////////////////////////////////////////////////
// sendtransaction

// CSendTransactionParam
CSendTransactionParam::CSendTransactionParam() {}
CSendTransactionParam::CSendTransactionParam(const CRPCString& strTxdata)
	: strTxdata(strTxdata)
{
}
Value CSendTransactionParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strTxdata, "strTxdata");
	ret.push_back(Pair("txdata", std::string(strTxdata)));

	return ret;
}
CSendTransactionParam& CSendTransactionParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "sendtransaction");
	auto obj = v.get_obj();
	auto valTxdata = find_value(obj, "txdata");
	CheckJSONType(valTxdata, "string", "txdata");
	strTxdata = valTxdata.get_str();
	return *this;
}
string CSendTransactionParam::Method() const
{
	return "sendtransaction";
}

// CSendTransactionResult
CSendTransactionResult::CSendTransactionResult() {}
CSendTransactionResult::CSendTransactionResult(const CRPCString& strData)
	: strData(strData)
{
}
Value CSendTransactionResult::ToJSON() const
{
	CheckIsValid(strData, "strData");
	Value val;
	val = Value(strData);
	return val;
}
CSendTransactionResult& CSendTransactionResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "data");
	strData = v.get_str();
	return *this;
}
string CSendTransactionResult::Method() const
{
	return "sendtransaction";
}

/////////////////////////////////////////////////////
// getforkheight

// CGetForkHeightParam
CGetForkHeightParam::CGetForkHeightParam() {}
CGetForkHeightParam::CGetForkHeightParam(const CRPCString& strFork)
	: strFork(strFork)
{
}
Value CGetForkHeightParam::ToJSON() const
{
	Object ret;
	if (strFork.IsValid())
	{
		ret.push_back(Pair("fork", std::string(strFork)));
	}

	return ret;
}
CGetForkHeightParam& CGetForkHeightParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "getforkheight");
	auto obj = v.get_obj();
	auto valFork = find_value(obj, "fork");
	if (!valFork.is_null())
	{
		CheckJSONType(valFork, "string", "fork");
		strFork = valFork.get_str();
	}
	return *this;
}
string CGetForkHeightParam::Method() const
{
	return "getforkheight";
}

// CGetForkHeightResult
CGetForkHeightResult::CGetForkHeightResult() {}
CGetForkHeightResult::CGetForkHeightResult(const CRPCInt64& nHeight)
	: nHeight(nHeight)
{
}
Value CGetForkHeightResult::ToJSON() const
{
	CheckIsValid(nHeight, "nHeight");
	Value val;
	val = Value(nHeight);
	return val;
}
CGetForkHeightResult& CGetForkHeightResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "int", "height");
	nHeight = v.get_int64();
	return *this;
}
string CGetForkHeightResult::Method() const
{
	return "getforkheight";
}

/////////////////////////////////////////////////////
// listkey

// CListKeyParam
CListKeyParam::CListKeyParam() {}
Value CListKeyParam::ToJSON() const
{
	Object ret;

	return ret;
}
CListKeyParam& CListKeyParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "listkey");
	auto obj = v.get_obj();
	return *this;
}
string CListKeyParam::Method() const
{
	return "listkey";
}

// CListKeyResult::CPubkey
CListKeyResult::CPubkey::CPubkey() {}
CListKeyResult::CPubkey::CPubkey(const CRPCString& strKey, const CRPCInt64& nVersion, const CRPCBool& fPublic, const CRPCBool& fLocked, const CRPCInt64& nTimeout)
	: strKey(strKey), nVersion(nVersion), fPublic(fPublic), fLocked(fLocked), nTimeout(nTimeout)
{
}
CListKeyResult::CPubkey::CPubkey(const CRPCType& null)
	: strKey(null), nVersion(null), fPublic(null), fLocked(null), nTimeout(null)
{
}
Value CListKeyResult::CPubkey::ToJSON() const
{
	Object ret;
	CheckIsValid(strKey, "strKey");
	ret.push_back(Pair("key", std::string(strKey)));
	CheckIsValid(nVersion, "nVersion");
	ret.push_back(Pair("version", int64(nVersion)));
	CheckIsValid(fPublic, "fPublic");
	ret.push_back(Pair("public", bool(fPublic)));
	CheckIsValid(fLocked, "fLocked");
	ret.push_back(Pair("locked", bool(fLocked)));
	if (nTimeout.IsValid())
	{
		ret.push_back(Pair("timeout", int64(nTimeout)));
	}

	return ret;
}
CListKeyResult::CPubkey& CListKeyResult::CPubkey::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CListKeyResult::CPubkey");
	auto obj = v.get_obj();
	auto valKey = find_value(obj, "key");
	CheckJSONType(valKey, "string", "key");
	strKey = valKey.get_str();
	auto valVersion = find_value(obj, "version");
	CheckJSONType(valVersion, "int", "version");
	nVersion = valVersion.get_int64();
	auto valPublic = find_value(obj, "public");
	CheckJSONType(valPublic, "bool", "public");
	fPublic = valPublic.get_bool();
	auto valLocked = find_value(obj, "locked");
	CheckJSONType(valLocked, "bool", "locked");
	fLocked = valLocked.get_bool();
	auto valTimeout = find_value(obj, "timeout");
	if (!valTimeout.is_null())
	{
		CheckJSONType(valTimeout, "int", "timeout");
		nTimeout = valTimeout.get_int64();
	}
	return *this;
}
bool CListKeyResult::CPubkey::IsValid() const
{
	if (!strKey.IsValid()) { return false; }
	if (!nVersion.IsValid()) { return false; }
	if (!fPublic.IsValid()) { return false; }
	if (!fLocked.IsValid()) { return false; }
	return true;
}

// CListKeyResult
CListKeyResult::CListKeyResult() {}
CListKeyResult::CListKeyResult(const CRPCVector<CPubkey>& vecPubkey)
	: vecPubkey(vecPubkey)
{
}
Value CListKeyResult::ToJSON() const
{
	Array ret;
	for (auto& v : vecPubkey)
	{
		ret.push_back(v.ToJSON());
	}
	return ret;
}
CListKeyResult& CListKeyResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "array", "pubkey");
	auto vecPubkeyArray = v.get_array();
	for (auto& v : vecPubkeyArray)
	{
		vecPubkey.push_back(CRPCVector<CPubkey>::value_type().FromJSON(v));
	}
	return *this;
}
string CListKeyResult::Method() const
{
	return "listkey";
}

/////////////////////////////////////////////////////
// getnewkey

// CGetNewKeyParam
CGetNewKeyParam::CGetNewKeyParam() {}
CGetNewKeyParam::CGetNewKeyParam(const CRPCString& strPassphrase)
	: strPassphrase(strPassphrase)
{
}
Value CGetNewKeyParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strPassphrase, "strPassphrase");
	ret.push_back(Pair("passphrase", std::string(strPassphrase)));

	return ret;
}
CGetNewKeyParam& CGetNewKeyParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "getnewkey");
	auto obj = v.get_obj();
	auto valPassphrase = find_value(obj, "passphrase");
	CheckJSONType(valPassphrase, "string", "passphrase");
	strPassphrase = valPassphrase.get_str();
	return *this;
}
string CGetNewKeyParam::Method() const
{
	return "getnewkey";
}

// CGetNewKeyResult
CGetNewKeyResult::CGetNewKeyResult() {}
CGetNewKeyResult::CGetNewKeyResult(const CRPCString& strPubkey)
	: strPubkey(strPubkey)
{
}
Value CGetNewKeyResult::ToJSON() const
{
	CheckIsValid(strPubkey, "strPubkey");
	Value val;
	val = Value(strPubkey);
	return val;
}
CGetNewKeyResult& CGetNewKeyResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "pubkey");
	strPubkey = v.get_str();
	return *this;
}
string CGetNewKeyResult::Method() const
{
	return "getnewkey";
}

/////////////////////////////////////////////////////
// encryptkey

// CEncryptKeyParam
CEncryptKeyParam::CEncryptKeyParam() {}
CEncryptKeyParam::CEncryptKeyParam(const CRPCString& strPubkey, const CRPCString& strPassphrase, const CRPCString& strOldpassphrase)
	: strPubkey(strPubkey), strPassphrase(strPassphrase), strOldpassphrase(strOldpassphrase)
{
}
Value CEncryptKeyParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strPubkey, "strPubkey");
	ret.push_back(Pair("pubkey", std::string(strPubkey)));
	CheckIsValid(strPassphrase, "strPassphrase");
	ret.push_back(Pair("passphrase", std::string(strPassphrase)));
	CheckIsValid(strOldpassphrase, "strOldpassphrase");
	ret.push_back(Pair("oldpassphrase", std::string(strOldpassphrase)));

	return ret;
}
CEncryptKeyParam& CEncryptKeyParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "encryptkey");
	auto obj = v.get_obj();
	auto valPubkey = find_value(obj, "pubkey");
	CheckJSONType(valPubkey, "string", "pubkey");
	strPubkey = valPubkey.get_str();
	auto valPassphrase = find_value(obj, "passphrase");
	CheckJSONType(valPassphrase, "string", "passphrase");
	strPassphrase = valPassphrase.get_str();
	auto valOldpassphrase = find_value(obj, "oldpassphrase");
	CheckJSONType(valOldpassphrase, "string", "oldpassphrase");
	strOldpassphrase = valOldpassphrase.get_str();
	return *this;
}
string CEncryptKeyParam::Method() const
{
	return "encryptkey";
}

// CEncryptKeyResult
CEncryptKeyResult::CEncryptKeyResult() {}
CEncryptKeyResult::CEncryptKeyResult(const CRPCString& strResult)
	: strResult(strResult)
{
}
Value CEncryptKeyResult::ToJSON() const
{
	CheckIsValid(strResult, "strResult");
	Value val;
	val = Value(strResult);
	return val;
}
CEncryptKeyResult& CEncryptKeyResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "result");
	strResult = v.get_str();
	return *this;
}
string CEncryptKeyResult::Method() const
{
	return "encryptkey";
}

/////////////////////////////////////////////////////
// lockkey

// CLockKeyParam
CLockKeyParam::CLockKeyParam() {}
CLockKeyParam::CLockKeyParam(const CRPCString& strPubkey)
	: strPubkey(strPubkey)
{
}
Value CLockKeyParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strPubkey, "strPubkey");
	ret.push_back(Pair("pubkey", std::string(strPubkey)));

	return ret;
}
CLockKeyParam& CLockKeyParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "lockkey");
	auto obj = v.get_obj();
	auto valPubkey = find_value(obj, "pubkey");
	CheckJSONType(valPubkey, "string", "pubkey");
	strPubkey = valPubkey.get_str();
	return *this;
}
string CLockKeyParam::Method() const
{
	return "lockkey";
}

// CLockKeyResult
CLockKeyResult::CLockKeyResult() {}
CLockKeyResult::CLockKeyResult(const CRPCString& strResult)
	: strResult(strResult)
{
}
Value CLockKeyResult::ToJSON() const
{
	CheckIsValid(strResult, "strResult");
	Value val;
	val = Value(strResult);
	return val;
}
CLockKeyResult& CLockKeyResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "result");
	strResult = v.get_str();
	return *this;
}
string CLockKeyResult::Method() const
{
	return "lockkey";
}

/////////////////////////////////////////////////////
// unlockkey

// CUnlockKeyParam
CUnlockKeyParam::CUnlockKeyParam() {}
CUnlockKeyParam::CUnlockKeyParam(const CRPCString& strPubkey, const CRPCString& strPassphrase, const CRPCInt64& nTimeout)
	: strPubkey(strPubkey), strPassphrase(strPassphrase), nTimeout(nTimeout)
{
}
Value CUnlockKeyParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strPubkey, "strPubkey");
	ret.push_back(Pair("pubkey", std::string(strPubkey)));
	CheckIsValid(strPassphrase, "strPassphrase");
	ret.push_back(Pair("passphrase", std::string(strPassphrase)));
	if (nTimeout.IsValid())
	{
		ret.push_back(Pair("timeout", int64(nTimeout)));
	}

	return ret;
}
CUnlockKeyParam& CUnlockKeyParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "unlockkey");
	auto obj = v.get_obj();
	auto valPubkey = find_value(obj, "pubkey");
	CheckJSONType(valPubkey, "string", "pubkey");
	strPubkey = valPubkey.get_str();
	auto valPassphrase = find_value(obj, "passphrase");
	CheckJSONType(valPassphrase, "string", "passphrase");
	strPassphrase = valPassphrase.get_str();
	auto valTimeout = find_value(obj, "timeout");
	if (!valTimeout.is_null())
	{
		CheckJSONType(valTimeout, "int", "timeout");
		nTimeout = valTimeout.get_int64();
	}
	return *this;
}
string CUnlockKeyParam::Method() const
{
	return "unlockkey";
}

// CUnlockKeyResult
CUnlockKeyResult::CUnlockKeyResult() {}
CUnlockKeyResult::CUnlockKeyResult(const CRPCString& strResult)
	: strResult(strResult)
{
}
Value CUnlockKeyResult::ToJSON() const
{
	CheckIsValid(strResult, "strResult");
	Value val;
	val = Value(strResult);
	return val;
}
CUnlockKeyResult& CUnlockKeyResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "result");
	strResult = v.get_str();
	return *this;
}
string CUnlockKeyResult::Method() const
{
	return "unlockkey";
}

/////////////////////////////////////////////////////
// importprivkey

// CImportPrivKeyParam
CImportPrivKeyParam::CImportPrivKeyParam() {}
CImportPrivKeyParam::CImportPrivKeyParam(const CRPCString& strPrivkey, const CRPCString& strPassphrase, const CRPCBool& fSynctx)
	: strPrivkey(strPrivkey), strPassphrase(strPassphrase), fSynctx(fSynctx)
{
}
Value CImportPrivKeyParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strPrivkey, "strPrivkey");
	ret.push_back(Pair("privkey", std::string(strPrivkey)));
	CheckIsValid(strPassphrase, "strPassphrase");
	ret.push_back(Pair("passphrase", std::string(strPassphrase)));
	if (fSynctx.IsValid())
	{
		ret.push_back(Pair("synctx", bool(fSynctx)));
	}

	return ret;
}
CImportPrivKeyParam& CImportPrivKeyParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "importprivkey");
	auto obj = v.get_obj();
	auto valPrivkey = find_value(obj, "privkey");
	CheckJSONType(valPrivkey, "string", "privkey");
	strPrivkey = valPrivkey.get_str();
	auto valPassphrase = find_value(obj, "passphrase");
	CheckJSONType(valPassphrase, "string", "passphrase");
	strPassphrase = valPassphrase.get_str();
	auto valSynctx = find_value(obj, "synctx");
	if (!valSynctx.is_null())
	{
		CheckJSONType(valSynctx, "bool", "synctx");
		fSynctx = valSynctx.get_bool();
	}
	return *this;
}
string CImportPrivKeyParam::Method() const
{
	return "importprivkey";
}

// CImportPrivKeyResult
CImportPrivKeyResult::CImportPrivKeyResult() {}
CImportPrivKeyResult::CImportPrivKeyResult(const CRPCString& strPubkey)
	: strPubkey(strPubkey)
{
}
Value CImportPrivKeyResult::ToJSON() const
{
	CheckIsValid(strPubkey, "strPubkey");
	Value val;
	val = Value(strPubkey);
	return val;
}
CImportPrivKeyResult& CImportPrivKeyResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "pubkey");
	strPubkey = v.get_str();
	return *this;
}
string CImportPrivKeyResult::Method() const
{
	return "importprivkey";
}

/////////////////////////////////////////////////////
// importpubkey

// CImportPubKeyParam
CImportPubKeyParam::CImportPubKeyParam() {}
CImportPubKeyParam::CImportPubKeyParam(const CRPCString& strPubkey)
	: strPubkey(strPubkey)
{
}
Value CImportPubKeyParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strPubkey, "strPubkey");
	ret.push_back(Pair("pubkey", std::string(strPubkey)));

	return ret;
}
CImportPubKeyParam& CImportPubKeyParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "importpubkey");
	auto obj = v.get_obj();
	auto valPubkey = find_value(obj, "pubkey");
	CheckJSONType(valPubkey, "string", "pubkey");
	strPubkey = valPubkey.get_str();
	return *this;
}
string CImportPubKeyParam::Method() const
{
	return "importpubkey";
}

// CImportPubKeyResult
CImportPubKeyResult::CImportPubKeyResult() {}
CImportPubKeyResult::CImportPubKeyResult(const CRPCString& strAddress)
	: strAddress(strAddress)
{
}
Value CImportPubKeyResult::ToJSON() const
{
	CheckIsValid(strAddress, "strAddress");
	Value val;
	val = Value(strAddress);
	return val;
}
CImportPubKeyResult& CImportPubKeyResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "address");
	strAddress = v.get_str();
	return *this;
}
string CImportPubKeyResult::Method() const
{
	return "importpubkey";
}

/////////////////////////////////////////////////////
// importkey

// CImportKeyParam
CImportKeyParam::CImportKeyParam() {}
CImportKeyParam::CImportKeyParam(const CRPCString& strPubkey, const CRPCBool& fSynctx)
	: strPubkey(strPubkey), fSynctx(fSynctx)
{
}
Value CImportKeyParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strPubkey, "strPubkey");
	ret.push_back(Pair("pubkey", std::string(strPubkey)));
	if (fSynctx.IsValid())
	{
		ret.push_back(Pair("synctx", bool(fSynctx)));
	}

	return ret;
}
CImportKeyParam& CImportKeyParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "importkey");
	auto obj = v.get_obj();
	auto valPubkey = find_value(obj, "pubkey");
	CheckJSONType(valPubkey, "string", "pubkey");
	strPubkey = valPubkey.get_str();
	auto valSynctx = find_value(obj, "synctx");
	if (!valSynctx.is_null())
	{
		CheckJSONType(valSynctx, "bool", "synctx");
		fSynctx = valSynctx.get_bool();
	}
	return *this;
}
string CImportKeyParam::Method() const
{
	return "importkey";
}

// CImportKeyResult
CImportKeyResult::CImportKeyResult() {}
CImportKeyResult::CImportKeyResult(const CRPCString& strPubkey)
	: strPubkey(strPubkey)
{
}
Value CImportKeyResult::ToJSON() const
{
	CheckIsValid(strPubkey, "strPubkey");
	Value val;
	val = Value(strPubkey);
	return val;
}
CImportKeyResult& CImportKeyResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "pubkey");
	strPubkey = v.get_str();
	return *this;
}
string CImportKeyResult::Method() const
{
	return "importkey";
}

/////////////////////////////////////////////////////
// exportkey

// CExportKeyParam
CExportKeyParam::CExportKeyParam() {}
CExportKeyParam::CExportKeyParam(const CRPCString& strPubkey)
	: strPubkey(strPubkey)
{
}
Value CExportKeyParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strPubkey, "strPubkey");
	ret.push_back(Pair("pubkey", std::string(strPubkey)));

	return ret;
}
CExportKeyParam& CExportKeyParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "exportkey");
	auto obj = v.get_obj();
	auto valPubkey = find_value(obj, "pubkey");
	CheckJSONType(valPubkey, "string", "pubkey");
	strPubkey = valPubkey.get_str();
	return *this;
}
string CExportKeyParam::Method() const
{
	return "exportkey";
}

// CExportKeyResult
CExportKeyResult::CExportKeyResult() {}
CExportKeyResult::CExportKeyResult(const CRPCString& strPubkey)
	: strPubkey(strPubkey)
{
}
Value CExportKeyResult::ToJSON() const
{
	CheckIsValid(strPubkey, "strPubkey");
	Value val;
	val = Value(strPubkey);
	return val;
}
CExportKeyResult& CExportKeyResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "pubkey");
	strPubkey = v.get_str();
	return *this;
}
string CExportKeyResult::Method() const
{
	return "exportkey";
}

/////////////////////////////////////////////////////
// addnewtemplate

// CAddNewTemplateParam
CAddNewTemplateParam::CAddNewTemplateParam() {}
CAddNewTemplateParam::CAddNewTemplateParam(const CTemplateRequest& data)
	: data(data)
{
}
Value CAddNewTemplateParam::ToJSON() const
{
	CheckIsValid(data, "data");
	return data.ToJSON();
}
CAddNewTemplateParam& CAddNewTemplateParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "data");
	data.FromJSON(v.get_obj());
	return *this;
}
string CAddNewTemplateParam::Method() const
{
	return "addnewtemplate";
}

// CAddNewTemplateResult
CAddNewTemplateResult::CAddNewTemplateResult() {}
CAddNewTemplateResult::CAddNewTemplateResult(const CRPCString& strAddress)
	: strAddress(strAddress)
{
}
Value CAddNewTemplateResult::ToJSON() const
{
	CheckIsValid(strAddress, "strAddress");
	Value val;
	val = Value(strAddress);
	return val;
}
CAddNewTemplateResult& CAddNewTemplateResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "address");
	strAddress = v.get_str();
	return *this;
}
string CAddNewTemplateResult::Method() const
{
	return "addnewtemplate";
}

/////////////////////////////////////////////////////
// importtemplate

// CImportTemplateParam
CImportTemplateParam::CImportTemplateParam() {}
CImportTemplateParam::CImportTemplateParam(const CRPCString& strData, const CRPCBool& fSynctx)
	: strData(strData), fSynctx(fSynctx)
{
}
Value CImportTemplateParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strData, "strData");
	ret.push_back(Pair("data", std::string(strData)));
	if (fSynctx.IsValid())
	{
		ret.push_back(Pair("synctx", bool(fSynctx)));
	}

	return ret;
}
CImportTemplateParam& CImportTemplateParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "importtemplate");
	auto obj = v.get_obj();
	auto valData = find_value(obj, "data");
	CheckJSONType(valData, "string", "data");
	strData = valData.get_str();
	auto valSynctx = find_value(obj, "synctx");
	if (!valSynctx.is_null())
	{
		CheckJSONType(valSynctx, "bool", "synctx");
		fSynctx = valSynctx.get_bool();
	}
	return *this;
}
string CImportTemplateParam::Method() const
{
	return "importtemplate";
}

// CImportTemplateResult
CImportTemplateResult::CImportTemplateResult() {}
CImportTemplateResult::CImportTemplateResult(const CRPCString& strAddress)
	: strAddress(strAddress)
{
}
Value CImportTemplateResult::ToJSON() const
{
	CheckIsValid(strAddress, "strAddress");
	Value val;
	val = Value(strAddress);
	return val;
}
CImportTemplateResult& CImportTemplateResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "address");
	strAddress = v.get_str();
	return *this;
}
string CImportTemplateResult::Method() const
{
	return "importtemplate";
}

/////////////////////////////////////////////////////
// exporttemplate

// CExportTemplateParam
CExportTemplateParam::CExportTemplateParam() {}
CExportTemplateParam::CExportTemplateParam(const CRPCString& strAddress)
	: strAddress(strAddress)
{
}
Value CExportTemplateParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strAddress, "strAddress");
	ret.push_back(Pair("address", std::string(strAddress)));

	return ret;
}
CExportTemplateParam& CExportTemplateParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "exporttemplate");
	auto obj = v.get_obj();
	auto valAddress = find_value(obj, "address");
	CheckJSONType(valAddress, "string", "address");
	strAddress = valAddress.get_str();
	return *this;
}
string CExportTemplateParam::Method() const
{
	return "exporttemplate";
}

// CExportTemplateResult
CExportTemplateResult::CExportTemplateResult() {}
CExportTemplateResult::CExportTemplateResult(const CRPCString& strData)
	: strData(strData)
{
}
Value CExportTemplateResult::ToJSON() const
{
	CheckIsValid(strData, "strData");
	Value val;
	val = Value(strData);
	return val;
}
CExportTemplateResult& CExportTemplateResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "data");
	strData = v.get_str();
	return *this;
}
string CExportTemplateResult::Method() const
{
	return "exporttemplate";
}

/////////////////////////////////////////////////////
// validateaddress

// CValidateAddressParam
CValidateAddressParam::CValidateAddressParam() {}
CValidateAddressParam::CValidateAddressParam(const CRPCString& strAddress)
	: strAddress(strAddress)
{
}
Value CValidateAddressParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strAddress, "strAddress");
	ret.push_back(Pair("address", std::string(strAddress)));

	return ret;
}
CValidateAddressParam& CValidateAddressParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "validateaddress");
	auto obj = v.get_obj();
	auto valAddress = find_value(obj, "address");
	CheckJSONType(valAddress, "string", "address");
	strAddress = valAddress.get_str();
	return *this;
}
string CValidateAddressParam::Method() const
{
	return "validateaddress";
}

// CValidateAddressResult::CAddressdata
CValidateAddressResult::CAddressdata::CAddressdata() {}
CValidateAddressResult::CAddressdata::CAddressdata(const CRPCString& strAddress, const CRPCBool& fIsmine, const CRPCString& strType, const CRPCString& strPubkey, const CRPCString& strTemplate, const CTemplateResponse& templatedata)
	: strAddress(strAddress), fIsmine(fIsmine), strType(strType), strPubkey(strPubkey), strTemplate(strTemplate), templatedata(templatedata)
{
}
CValidateAddressResult::CAddressdata::CAddressdata(const CRPCType& null)
	: strAddress(null), fIsmine(null), strType(null), strPubkey(null), strTemplate(null), templatedata(null)
{
}
Value CValidateAddressResult::CAddressdata::ToJSON() const
{
	Object ret;
	CheckIsValid(strAddress, "strAddress");
	ret.push_back(Pair("address", std::string(strAddress)));
	CheckIsValid(fIsmine, "fIsmine");
	ret.push_back(Pair("ismine", bool(fIsmine)));
	CheckIsValid(strType, "strType");
	ret.push_back(Pair("type", std::string(strType)));
	if (strType == "pubkey")
	{
		CheckIsValid(strPubkey, "strPubkey");
		ret.push_back(Pair("pubkey", std::string(strPubkey)));
	}
	if (strType == "template")
	{
		CheckIsValid(strTemplate, "strTemplate");
		ret.push_back(Pair("template", std::string(strTemplate)));
	}
	if (strType == "template" && fIsmine == true)
	{
		CheckIsValid(templatedata, "templatedata");
		ret.push_back(Pair("templatedata", templatedata.ToJSON()));
	}

	return ret;
}
CValidateAddressResult::CAddressdata& CValidateAddressResult::CAddressdata::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CValidateAddressResult::CAddressdata");
	auto obj = v.get_obj();
	auto valAddress = find_value(obj, "address");
	CheckJSONType(valAddress, "string", "address");
	strAddress = valAddress.get_str();
	auto valIsmine = find_value(obj, "ismine");
	CheckJSONType(valIsmine, "bool", "ismine");
	fIsmine = valIsmine.get_bool();
	auto valType = find_value(obj, "type");
	CheckJSONType(valType, "string", "type");
	strType = valType.get_str();
	if (strType == "pubkey")
	{
		auto valPubkey = find_value(obj, "pubkey");
		CheckJSONType(valPubkey, "string", "pubkey");
		strPubkey = valPubkey.get_str();
	}
	if (strType == "template")
	{
		auto valTemplate = find_value(obj, "template");
		CheckJSONType(valTemplate, "string", "template");
		strTemplate = valTemplate.get_str();
	}
	if (strType == "template" && fIsmine == true)
	{
		auto valTemplatedata = find_value(obj, "templatedata");
		CheckJSONType(valTemplatedata, "object", "templatedata");
		templatedata.FromJSON(valTemplatedata.get_obj());
	}
	return *this;
}
bool CValidateAddressResult::CAddressdata::IsValid() const
{
	if (!strAddress.IsValid()) { return false; }
	if (!fIsmine.IsValid()) { return false; }
	if (!strType.IsValid()) { return false; }
	if (strType == "pubkey")
	{
		if (!strPubkey.IsValid()) { return false; }
	}
	if (strType == "template")
	{
		if (!strTemplate.IsValid()) { return false; }
	}
	if (strType == "template" && fIsmine == true)
	{
		if (!templatedata.IsValid()) { return false; }
	}
	return true;
}

// CValidateAddressResult
CValidateAddressResult::CValidateAddressResult() {}
CValidateAddressResult::CValidateAddressResult(const CRPCBool& fIsvalid, const CAddressdata& addressdata)
	: fIsvalid(fIsvalid), addressdata(addressdata)
{
}
Value CValidateAddressResult::ToJSON() const
{
	Object ret;
	CheckIsValid(fIsvalid, "fIsvalid");
	ret.push_back(Pair("isvalid", bool(fIsvalid)));
	if (fIsvalid == true)
	{
		CheckIsValid(addressdata, "addressdata");
		ret.push_back(Pair("addressdata", addressdata.ToJSON()));
	}

	return ret;
}
CValidateAddressResult& CValidateAddressResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "validateaddress");
	auto obj = v.get_obj();
	auto valIsvalid = find_value(obj, "isvalid");
	CheckJSONType(valIsvalid, "bool", "isvalid");
	fIsvalid = valIsvalid.get_bool();
	if (fIsvalid == true)
	{
		auto valAddressdata = find_value(obj, "addressdata");
		CheckJSONType(valAddressdata, "object", "addressdata");
		addressdata.FromJSON(valAddressdata.get_obj());
	}
	return *this;
}
string CValidateAddressResult::Method() const
{
	return "validateaddress";
}

/////////////////////////////////////////////////////
// resyncwallet

// CResyncWalletParam
CResyncWalletParam::CResyncWalletParam() {}
CResyncWalletParam::CResyncWalletParam(const CRPCString& strAddress)
	: strAddress(strAddress)
{
}
Value CResyncWalletParam::ToJSON() const
{
	Object ret;
	if (strAddress.IsValid())
	{
		ret.push_back(Pair("address", std::string(strAddress)));
	}

	return ret;
}
CResyncWalletParam& CResyncWalletParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "resyncwallet");
	auto obj = v.get_obj();
	auto valAddress = find_value(obj, "address");
	if (!valAddress.is_null())
	{
		CheckJSONType(valAddress, "string", "address");
		strAddress = valAddress.get_str();
	}
	return *this;
}
string CResyncWalletParam::Method() const
{
	return "resyncwallet";
}

// CResyncWalletResult
CResyncWalletResult::CResyncWalletResult() {}
CResyncWalletResult::CResyncWalletResult(const CRPCString& strResult)
	: strResult(strResult)
{
}
Value CResyncWalletResult::ToJSON() const
{
	CheckIsValid(strResult, "strResult");
	Value val;
	val = Value(strResult);
	return val;
}
CResyncWalletResult& CResyncWalletResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "result");
	strResult = v.get_str();
	return *this;
}
string CResyncWalletResult::Method() const
{
	return "resyncwallet";
}

/////////////////////////////////////////////////////
// getbalance

// CGetBalanceParam
CGetBalanceParam::CGetBalanceParam() {}
CGetBalanceParam::CGetBalanceParam(const CRPCString& strFork, const CRPCString& strAddress)
	: strFork(strFork), strAddress(strAddress)
{
}
Value CGetBalanceParam::ToJSON() const
{
	Object ret;
	if (strFork.IsValid())
	{
		ret.push_back(Pair("fork", std::string(strFork)));
	}
	if (strAddress.IsValid())
	{
		ret.push_back(Pair("address", std::string(strAddress)));
	}

	return ret;
}
CGetBalanceParam& CGetBalanceParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "getbalance");
	auto obj = v.get_obj();
	auto valFork = find_value(obj, "fork");
	if (!valFork.is_null())
	{
		CheckJSONType(valFork, "string", "fork");
		strFork = valFork.get_str();
	}
	auto valAddress = find_value(obj, "address");
	if (!valAddress.is_null())
	{
		CheckJSONType(valAddress, "string", "address");
		strAddress = valAddress.get_str();
	}
	return *this;
}
string CGetBalanceParam::Method() const
{
	return "getbalance";
}

// CGetBalanceResult::CBalance
CGetBalanceResult::CBalance::CBalance() {}
CGetBalanceResult::CBalance::CBalance(const CRPCString& strAddress, const CRPCDouble& dAvail, const CRPCDouble& dLocked, const CRPCDouble& dUnconfirmed)
	: strAddress(strAddress), dAvail(dAvail), dLocked(dLocked), dUnconfirmed(dUnconfirmed)
{
}
CGetBalanceResult::CBalance::CBalance(const CRPCType& null)
	: strAddress(null), dAvail(null), dLocked(null), dUnconfirmed(null)
{
}
Value CGetBalanceResult::CBalance::ToJSON() const
{
	Object ret;
	CheckIsValid(strAddress, "strAddress");
	ret.push_back(Pair("address", std::string(strAddress)));
	CheckIsValid(dAvail, "dAvail");
	ret.push_back(Pair("avail", double(dAvail)));
	CheckIsValid(dLocked, "dLocked");
	ret.push_back(Pair("locked", double(dLocked)));
	CheckIsValid(dUnconfirmed, "dUnconfirmed");
	ret.push_back(Pair("unconfirmed", double(dUnconfirmed)));

	return ret;
}
CGetBalanceResult::CBalance& CGetBalanceResult::CBalance::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CGetBalanceResult::CBalance");
	auto obj = v.get_obj();
	auto valAddress = find_value(obj, "address");
	CheckJSONType(valAddress, "string", "address");
	strAddress = valAddress.get_str();
	auto valAvail = find_value(obj, "avail");
	CheckJSONType(valAvail, "double", "avail");
	dAvail = valAvail.get_real();
	auto valLocked = find_value(obj, "locked");
	CheckJSONType(valLocked, "double", "locked");
	dLocked = valLocked.get_real();
	auto valUnconfirmed = find_value(obj, "unconfirmed");
	CheckJSONType(valUnconfirmed, "double", "unconfirmed");
	dUnconfirmed = valUnconfirmed.get_real();
	return *this;
}
bool CGetBalanceResult::CBalance::IsValid() const
{
	if (!strAddress.IsValid()) { return false; }
	if (!dAvail.IsValid()) { return false; }
	if (!dLocked.IsValid()) { return false; }
	if (!dUnconfirmed.IsValid()) { return false; }
	return true;
}

// CGetBalanceResult
CGetBalanceResult::CGetBalanceResult() {}
CGetBalanceResult::CGetBalanceResult(const CRPCVector<CBalance>& vecBalance)
	: vecBalance(vecBalance)
{
}
Value CGetBalanceResult::ToJSON() const
{
	Array ret;
	for (auto& v : vecBalance)
	{
		ret.push_back(v.ToJSON());
	}
	return ret;
}
CGetBalanceResult& CGetBalanceResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "array", "balance");
	auto vecBalanceArray = v.get_array();
	for (auto& v : vecBalanceArray)
	{
		vecBalance.push_back(CRPCVector<CBalance>::value_type().FromJSON(v));
	}
	return *this;
}
string CGetBalanceResult::Method() const
{
	return "getbalance";
}

/////////////////////////////////////////////////////
// listtransaction

// CListTransactionParam
CListTransactionParam::CListTransactionParam() {}
CListTransactionParam::CListTransactionParam(const CRPCUint64& nCount, const CRPCInt64& nOffset, const CRPCString& strFork, const CRPCString& strAddress)
	: nCount(nCount), nOffset(nOffset), strFork(strFork), strAddress(strAddress)
{
}
Value CListTransactionParam::ToJSON() const
{
	Object ret;
	if (nCount.IsValid())
	{
		ret.push_back(Pair("count", uint64(nCount)));
	}
	if (nOffset.IsValid())
	{
		ret.push_back(Pair("offset", int64(nOffset)));
	}
	if (strFork.IsValid())
	{
		ret.push_back(Pair("fork", std::string(strFork)));
	}
	if (strAddress.IsValid())
	{
		ret.push_back(Pair("address", std::string(strAddress)));
	}

	return ret;
}
CListTransactionParam& CListTransactionParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "listtransaction");
	auto obj = v.get_obj();
	auto valCount = find_value(obj, "count");
	if (!valCount.is_null())
	{
		CheckJSONType(valCount, "uint", "count");
		nCount = valCount.get_uint64();
	}
	auto valOffset = find_value(obj, "offset");
	if (!valOffset.is_null())
	{
		CheckJSONType(valOffset, "int", "offset");
		nOffset = valOffset.get_int64();
	}
	auto valFork = find_value(obj, "fork");
	if (!valFork.is_null())
	{
		CheckJSONType(valFork, "string", "fork");
		strFork = valFork.get_str();
	}
	auto valAddress = find_value(obj, "address");
	if (!valAddress.is_null())
	{
		CheckJSONType(valAddress, "string", "address");
		strAddress = valAddress.get_str();
	}
	return *this;
}
string CListTransactionParam::Method() const
{
	return "listtransaction";
}

// CListTransactionResult
CListTransactionResult::CListTransactionResult() {}
CListTransactionResult::CListTransactionResult(const CRPCVector<CWalletTxData>& vecTransaction)
	: vecTransaction(vecTransaction)
{
}
Value CListTransactionResult::ToJSON() const
{
	Array ret;
	for (auto& v : vecTransaction)
	{
		ret.push_back(v.ToJSON());
	}
	return ret;
}
CListTransactionResult& CListTransactionResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "array", "transaction");
	auto vecTransactionArray = v.get_array();
	for (auto& v : vecTransactionArray)
	{
		vecTransaction.push_back(CRPCVector<CWalletTxData>::value_type().FromJSON(v));
	}
	return *this;
}
string CListTransactionResult::Method() const
{
	return "listtransaction";
}

/////////////////////////////////////////////////////
// sendfrom

// CSendFromParam
CSendFromParam::CSendFromParam() {}
CSendFromParam::CSendFromParam(const CRPCString& strFrom, const CRPCString& strTo, const CRPCDouble& dAmount, const CRPCDouble& dTxfee, const CRPCString& strFork, const CRPCString& strData, const CRPCString& strSign_M, const CRPCString& strSign_S, const CRPCString& strSendtodata)
	: strFrom(strFrom), strTo(strTo), dAmount(dAmount), dTxfee(dTxfee), strFork(strFork), strData(strData), strSign_M(strSign_M), strSign_S(strSign_S), strSendtodata(strSendtodata)
{
}
Value CSendFromParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strFrom, "strFrom");
	ret.push_back(Pair("from", std::string(strFrom)));
	CheckIsValid(strTo, "strTo");
	ret.push_back(Pair("to", std::string(strTo)));
	CheckIsValid(dAmount, "dAmount");
	ret.push_back(Pair("amount", double(dAmount)));
	if (dTxfee.IsValid())
	{
		ret.push_back(Pair("txfee", double(dTxfee)));
	}
	if (strFork.IsValid())
	{
		ret.push_back(Pair("fork", std::string(strFork)));
	}
	if (strData.IsValid())
	{
		ret.push_back(Pair("data", std::string(strData)));
	}
	if (strSign_M.IsValid())
	{
		ret.push_back(Pair("sign_m", std::string(strSign_M)));
	}
	if (strSign_S.IsValid())
	{
		ret.push_back(Pair("sign_s", std::string(strSign_S)));
	}
	if (strSendtodata.IsValid())
	{
		ret.push_back(Pair("sendtodata", std::string(strSendtodata)));
	}

	return ret;
}
CSendFromParam& CSendFromParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "sendfrom");
	auto obj = v.get_obj();
	auto valFrom = find_value(obj, "from");
	CheckJSONType(valFrom, "string", "from");
	strFrom = valFrom.get_str();
	auto valTo = find_value(obj, "to");
	CheckJSONType(valTo, "string", "to");
	strTo = valTo.get_str();
	auto valAmount = find_value(obj, "amount");
	CheckJSONType(valAmount, "double", "amount");
	dAmount = valAmount.get_real();
	auto valTxfee = find_value(obj, "txfee");
	if (!valTxfee.is_null())
	{
		CheckJSONType(valTxfee, "double", "txfee");
		dTxfee = valTxfee.get_real();
	}
	auto valFork = find_value(obj, "fork");
	if (!valFork.is_null())
	{
		CheckJSONType(valFork, "string", "fork");
		strFork = valFork.get_str();
	}
	auto valData = find_value(obj, "data");
	if (!valData.is_null())
	{
		CheckJSONType(valData, "string", "data");
		strData = valData.get_str();
	}
	auto valSign_M = find_value(obj, "sign_m");
	if (!valSign_M.is_null())
	{
		CheckJSONType(valSign_M, "string", "sign_m");
		strSign_M = valSign_M.get_str();
	}
	auto valSign_S = find_value(obj, "sign_s");
	if (!valSign_S.is_null())
	{
		CheckJSONType(valSign_S, "string", "sign_s");
		strSign_S = valSign_S.get_str();
	}
	auto valSendtodata = find_value(obj, "sendtodata");
	if (!valSendtodata.is_null())
	{
		CheckJSONType(valSendtodata, "string", "sendtodata");
		strSendtodata = valSendtodata.get_str();
	}
	return *this;
}
string CSendFromParam::Method() const
{
	return "sendfrom";
}

// CSendFromResult
CSendFromResult::CSendFromResult() {}
CSendFromResult::CSendFromResult(const CRPCString& strTransaction)
	: strTransaction(strTransaction)
{
}
Value CSendFromResult::ToJSON() const
{
	CheckIsValid(strTransaction, "strTransaction");
	Value val;
	val = Value(strTransaction);
	return val;
}
CSendFromResult& CSendFromResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "transaction");
	strTransaction = v.get_str();
	return *this;
}
string CSendFromResult::Method() const
{
	return "sendfrom";
}

/////////////////////////////////////////////////////
// createtransaction

// CCreateTransactionParam
CCreateTransactionParam::CCreateTransactionParam() {}
CCreateTransactionParam::CCreateTransactionParam(const CRPCString& strFrom, const CRPCString& strTo, const CRPCDouble& dAmount, const CRPCDouble& dTxfee, const CRPCString& strFork, const CRPCString& strData)
	: strFrom(strFrom), strTo(strTo), dAmount(dAmount), dTxfee(dTxfee), strFork(strFork), strData(strData)
{
}
Value CCreateTransactionParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strFrom, "strFrom");
	ret.push_back(Pair("from", std::string(strFrom)));
	CheckIsValid(strTo, "strTo");
	ret.push_back(Pair("to", std::string(strTo)));
	CheckIsValid(dAmount, "dAmount");
	ret.push_back(Pair("amount", double(dAmount)));
	if (dTxfee.IsValid())
	{
		ret.push_back(Pair("txfee", double(dTxfee)));
	}
	if (strFork.IsValid())
	{
		ret.push_back(Pair("fork", std::string(strFork)));
	}
	if (strData.IsValid())
	{
		ret.push_back(Pair("data", std::string(strData)));
	}

	return ret;
}
CCreateTransactionParam& CCreateTransactionParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "createtransaction");
	auto obj = v.get_obj();
	auto valFrom = find_value(obj, "from");
	CheckJSONType(valFrom, "string", "from");
	strFrom = valFrom.get_str();
	auto valTo = find_value(obj, "to");
	CheckJSONType(valTo, "string", "to");
	strTo = valTo.get_str();
	auto valAmount = find_value(obj, "amount");
	CheckJSONType(valAmount, "double", "amount");
	dAmount = valAmount.get_real();
	auto valTxfee = find_value(obj, "txfee");
	if (!valTxfee.is_null())
	{
		CheckJSONType(valTxfee, "double", "txfee");
		dTxfee = valTxfee.get_real();
	}
	auto valFork = find_value(obj, "fork");
	if (!valFork.is_null())
	{
		CheckJSONType(valFork, "string", "fork");
		strFork = valFork.get_str();
	}
	auto valData = find_value(obj, "data");
	if (!valData.is_null())
	{
		CheckJSONType(valData, "string", "data");
		strData = valData.get_str();
	}
	return *this;
}
string CCreateTransactionParam::Method() const
{
	return "createtransaction";
}

// CCreateTransactionResult
CCreateTransactionResult::CCreateTransactionResult() {}
CCreateTransactionResult::CCreateTransactionResult(const CRPCString& strTransaction)
	: strTransaction(strTransaction)
{
}
Value CCreateTransactionResult::ToJSON() const
{
	CheckIsValid(strTransaction, "strTransaction");
	Value val;
	val = Value(strTransaction);
	return val;
}
CCreateTransactionResult& CCreateTransactionResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "transaction");
	strTransaction = v.get_str();
	return *this;
}
string CCreateTransactionResult::Method() const
{
	return "createtransaction";
}

/////////////////////////////////////////////////////
// signtransaction

// CSignTransactionParam
CSignTransactionParam::CSignTransactionParam() {}
CSignTransactionParam::CSignTransactionParam(const CRPCString& strTxdata, const CRPCString& strSendtodata)
	: strTxdata(strTxdata), strSendtodata(strSendtodata)
{
}
Value CSignTransactionParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strTxdata, "strTxdata");
	ret.push_back(Pair("txdata", std::string(strTxdata)));
	if (strSendtodata.IsValid())
	{
		ret.push_back(Pair("sendtodata", std::string(strSendtodata)));
	}

	return ret;
}
CSignTransactionParam& CSignTransactionParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "signtransaction");
	auto obj = v.get_obj();
	auto valTxdata = find_value(obj, "txdata");
	CheckJSONType(valTxdata, "string", "txdata");
	strTxdata = valTxdata.get_str();
	auto valSendtodata = find_value(obj, "sendtodata");
	if (!valSendtodata.is_null())
	{
		CheckJSONType(valSendtodata, "string", "sendtodata");
		strSendtodata = valSendtodata.get_str();
	}
	return *this;
}
string CSignTransactionParam::Method() const
{
	return "signtransaction";
}

// CSignTransactionResult
CSignTransactionResult::CSignTransactionResult() {}
CSignTransactionResult::CSignTransactionResult(const CRPCString& strHex, const CRPCBool& fCompleted)
	: strHex(strHex), fCompleted(fCompleted)
{
}
Value CSignTransactionResult::ToJSON() const
{
	Object ret;
	CheckIsValid(strHex, "strHex");
	ret.push_back(Pair("hex", std::string(strHex)));
	CheckIsValid(fCompleted, "fCompleted");
	ret.push_back(Pair("completed", bool(fCompleted)));

	return ret;
}
CSignTransactionResult& CSignTransactionResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "signtransaction");
	auto obj = v.get_obj();
	auto valHex = find_value(obj, "hex");
	CheckJSONType(valHex, "string", "hex");
	strHex = valHex.get_str();
	auto valCompleted = find_value(obj, "completed");
	CheckJSONType(valCompleted, "bool", "completed");
	fCompleted = valCompleted.get_bool();
	return *this;
}
string CSignTransactionResult::Method() const
{
	return "signtransaction";
}

/////////////////////////////////////////////////////
// signmessage

// CSignMessageParam
CSignMessageParam::CSignMessageParam() {}
CSignMessageParam::CSignMessageParam(const CRPCString& strPubkey, const CRPCString& strMessage, const CRPCString& strAddr)
	: strPubkey(strPubkey), strMessage(strMessage), strAddr(strAddr)
{
}
Value CSignMessageParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strPubkey, "strPubkey");
	ret.push_back(Pair("pubkey", std::string(strPubkey)));
	CheckIsValid(strMessage, "strMessage");
	ret.push_back(Pair("message", std::string(strMessage)));
	if (strAddr.IsValid())
	{
		ret.push_back(Pair("addr", std::string(strAddr)));
	}

	return ret;
}
CSignMessageParam& CSignMessageParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "signmessage");
	auto obj = v.get_obj();
	auto valPubkey = find_value(obj, "pubkey");
	CheckJSONType(valPubkey, "string", "pubkey");
	strPubkey = valPubkey.get_str();
	auto valMessage = find_value(obj, "message");
	CheckJSONType(valMessage, "string", "message");
	strMessage = valMessage.get_str();
	auto valAddr = find_value(obj, "addr");
	if (!valAddr.is_null())
	{
		CheckJSONType(valAddr, "string", "addr");
		strAddr = valAddr.get_str();
	}
	return *this;
}
string CSignMessageParam::Method() const
{
	return "signmessage";
}

// CSignMessageResult
CSignMessageResult::CSignMessageResult() {}
CSignMessageResult::CSignMessageResult(const CRPCString& strSignature)
	: strSignature(strSignature)
{
}
Value CSignMessageResult::ToJSON() const
{
	CheckIsValid(strSignature, "strSignature");
	Value val;
	val = Value(strSignature);
	return val;
}
CSignMessageResult& CSignMessageResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "signature");
	strSignature = v.get_str();
	return *this;
}
string CSignMessageResult::Method() const
{
	return "signmessage";
}

/////////////////////////////////////////////////////
// listaddress

// CListAddressParam
CListAddressParam::CListAddressParam() {}
Value CListAddressParam::ToJSON() const
{
	Object ret;

	return ret;
}
CListAddressParam& CListAddressParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "listaddress");
	auto obj = v.get_obj();
	return *this;
}
string CListAddressParam::Method() const
{
	return "listaddress";
}

// CListAddressResult::CAddressdata
CListAddressResult::CAddressdata::CAddressdata() {}
CListAddressResult::CAddressdata::CAddressdata(const CRPCString& strType, const CRPCString& strAddress, const CRPCString& strPubkey, const CRPCString& strTemplate, const CTemplateResponse& templatedata)
	: strType(strType), strAddress(strAddress), strPubkey(strPubkey), strTemplate(strTemplate), templatedata(templatedata)
{
}
CListAddressResult::CAddressdata::CAddressdata(const CRPCType& null)
	: strType(null), strAddress(null), strPubkey(null), strTemplate(null), templatedata(null)
{
}
Value CListAddressResult::CAddressdata::ToJSON() const
{
	Object ret;
	CheckIsValid(strType, "strType");
	ret.push_back(Pair("type", std::string(strType)));
	CheckIsValid(strAddress, "strAddress");
	ret.push_back(Pair("address", std::string(strAddress)));
	if (strType == "pubkey")
	{
		CheckIsValid(strPubkey, "strPubkey");
		ret.push_back(Pair("pubkey", std::string(strPubkey)));
	}
	if (strType == "template")
	{
		CheckIsValid(strTemplate, "strTemplate");
		ret.push_back(Pair("template", std::string(strTemplate)));
	}
	if (strType == "template")
	{
		CheckIsValid(templatedata, "templatedata");
		ret.push_back(Pair("templatedata", templatedata.ToJSON()));
	}

	return ret;
}
CListAddressResult::CAddressdata& CListAddressResult::CAddressdata::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CListAddressResult::CAddressdata");
	auto obj = v.get_obj();
	auto valType = find_value(obj, "type");
	CheckJSONType(valType, "string", "type");
	strType = valType.get_str();
	auto valAddress = find_value(obj, "address");
	CheckJSONType(valAddress, "string", "address");
	strAddress = valAddress.get_str();
	if (strType == "pubkey")
	{
		auto valPubkey = find_value(obj, "pubkey");
		CheckJSONType(valPubkey, "string", "pubkey");
		strPubkey = valPubkey.get_str();
	}
	if (strType == "template")
	{
		auto valTemplate = find_value(obj, "template");
		CheckJSONType(valTemplate, "string", "template");
		strTemplate = valTemplate.get_str();
	}
	if (strType == "template")
	{
		auto valTemplatedata = find_value(obj, "templatedata");
		CheckJSONType(valTemplatedata, "object", "templatedata");
		templatedata.FromJSON(valTemplatedata.get_obj());
	}
	return *this;
}
bool CListAddressResult::CAddressdata::IsValid() const
{
	if (!strType.IsValid()) { return false; }
	if (!strAddress.IsValid()) { return false; }
	if (strType == "pubkey")
	{
		if (!strPubkey.IsValid()) { return false; }
	}
	if (strType == "template")
	{
		if (!strTemplate.IsValid()) { return false; }
	}
	if (strType == "template")
	{
		if (!templatedata.IsValid()) { return false; }
	}
	return true;
}

// CListAddressResult
CListAddressResult::CListAddressResult() {}
CListAddressResult::CListAddressResult(const CRPCVector<CAddressdata>& vecAddressdata)
	: vecAddressdata(vecAddressdata)
{
}
Value CListAddressResult::ToJSON() const
{
	Array ret;
	for (auto& v : vecAddressdata)
	{
		ret.push_back(v.ToJSON());
	}
	return ret;
}
CListAddressResult& CListAddressResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "array", "addressdata");
	auto vecAddressdataArray = v.get_array();
	for (auto& v : vecAddressdataArray)
	{
		vecAddressdata.push_back(CRPCVector<CAddressdata>::value_type().FromJSON(v));
	}
	return *this;
}
string CListAddressResult::Method() const
{
	return "listaddress";
}

/////////////////////////////////////////////////////
// exportwallet

// CExportWalletParam
CExportWalletParam::CExportWalletParam() {}
CExportWalletParam::CExportWalletParam(const CRPCString& strPath)
	: strPath(strPath)
{
}
Value CExportWalletParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strPath, "strPath");
	ret.push_back(Pair("path", std::string(strPath)));

	return ret;
}
CExportWalletParam& CExportWalletParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "exportwallet");
	auto obj = v.get_obj();
	auto valPath = find_value(obj, "path");
	CheckJSONType(valPath, "string", "path");
	strPath = valPath.get_str();
	return *this;
}
string CExportWalletParam::Method() const
{
	return "exportwallet";
}

// CExportWalletResult
CExportWalletResult::CExportWalletResult() {}
CExportWalletResult::CExportWalletResult(const CRPCString& strResult)
	: strResult(strResult)
{
}
Value CExportWalletResult::ToJSON() const
{
	CheckIsValid(strResult, "strResult");
	Value val;
	val = Value(strResult);
	return val;
}
CExportWalletResult& CExportWalletResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "result");
	strResult = v.get_str();
	return *this;
}
string CExportWalletResult::Method() const
{
	return "exportwallet";
}

/////////////////////////////////////////////////////
// importwallet

// CImportWalletParam
CImportWalletParam::CImportWalletParam() {}
CImportWalletParam::CImportWalletParam(const CRPCString& strPath)
	: strPath(strPath)
{
}
Value CImportWalletParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strPath, "strPath");
	ret.push_back(Pair("path", std::string(strPath)));

	return ret;
}
CImportWalletParam& CImportWalletParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "importwallet");
	auto obj = v.get_obj();
	auto valPath = find_value(obj, "path");
	CheckJSONType(valPath, "string", "path");
	strPath = valPath.get_str();
	return *this;
}
string CImportWalletParam::Method() const
{
	return "importwallet";
}

// CImportWalletResult
CImportWalletResult::CImportWalletResult() {}
CImportWalletResult::CImportWalletResult(const CRPCString& strResult)
	: strResult(strResult)
{
}
Value CImportWalletResult::ToJSON() const
{
	CheckIsValid(strResult, "strResult");
	Value val;
	val = Value(strResult);
	return val;
}
CImportWalletResult& CImportWalletResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "result");
	strResult = v.get_str();
	return *this;
}
string CImportWalletResult::Method() const
{
	return "importwallet";
}

/////////////////////////////////////////////////////
// verifymessage

// CVerifyMessageParam
CVerifyMessageParam::CVerifyMessageParam() {}
CVerifyMessageParam::CVerifyMessageParam(const CRPCString& strPubkey, const CRPCString& strMessage, const CRPCString& strSig, const CRPCString& strAddr)
	: strPubkey(strPubkey), strMessage(strMessage), strSig(strSig), strAddr(strAddr)
{
}
Value CVerifyMessageParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strPubkey, "strPubkey");
	ret.push_back(Pair("pubkey", std::string(strPubkey)));
	CheckIsValid(strMessage, "strMessage");
	ret.push_back(Pair("message", std::string(strMessage)));
	CheckIsValid(strSig, "strSig");
	ret.push_back(Pair("sig", std::string(strSig)));
	if (strAddr.IsValid())
	{
		ret.push_back(Pair("addr", std::string(strAddr)));
	}

	return ret;
}
CVerifyMessageParam& CVerifyMessageParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "verifymessage");
	auto obj = v.get_obj();
	auto valPubkey = find_value(obj, "pubkey");
	CheckJSONType(valPubkey, "string", "pubkey");
	strPubkey = valPubkey.get_str();
	auto valMessage = find_value(obj, "message");
	CheckJSONType(valMessage, "string", "message");
	strMessage = valMessage.get_str();
	auto valSig = find_value(obj, "sig");
	CheckJSONType(valSig, "string", "sig");
	strSig = valSig.get_str();
	auto valAddr = find_value(obj, "addr");
	if (!valAddr.is_null())
	{
		CheckJSONType(valAddr, "string", "addr");
		strAddr = valAddr.get_str();
	}
	return *this;
}
string CVerifyMessageParam::Method() const
{
	return "verifymessage";
}

// CVerifyMessageResult
CVerifyMessageResult::CVerifyMessageResult() {}
CVerifyMessageResult::CVerifyMessageResult(const CRPCBool& fResult)
	: fResult(fResult)
{
}
Value CVerifyMessageResult::ToJSON() const
{
	CheckIsValid(fResult, "fResult");
	Value val;
	val = Value(fResult);
	return val;
}
CVerifyMessageResult& CVerifyMessageResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "bool", "result");
	fResult = v.get_bool();
	return *this;
}
string CVerifyMessageResult::Method() const
{
	return "verifymessage";
}

/////////////////////////////////////////////////////
// makekeypair

// CMakeKeyPairParam
CMakeKeyPairParam::CMakeKeyPairParam() {}
Value CMakeKeyPairParam::ToJSON() const
{
	Object ret;

	return ret;
}
CMakeKeyPairParam& CMakeKeyPairParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "makekeypair");
	auto obj = v.get_obj();
	return *this;
}
string CMakeKeyPairParam::Method() const
{
	return "makekeypair";
}

// CMakeKeyPairResult
CMakeKeyPairResult::CMakeKeyPairResult() {}
CMakeKeyPairResult::CMakeKeyPairResult(const CRPCString& strPrivkey, const CRPCString& strPubkey)
	: strPrivkey(strPrivkey), strPubkey(strPubkey)
{
}
Value CMakeKeyPairResult::ToJSON() const
{
	Object ret;
	CheckIsValid(strPrivkey, "strPrivkey");
	ret.push_back(Pair("privkey", std::string(strPrivkey)));
	CheckIsValid(strPubkey, "strPubkey");
	ret.push_back(Pair("pubkey", std::string(strPubkey)));

	return ret;
}
CMakeKeyPairResult& CMakeKeyPairResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "makekeypair");
	auto obj = v.get_obj();
	auto valPrivkey = find_value(obj, "privkey");
	CheckJSONType(valPrivkey, "string", "privkey");
	strPrivkey = valPrivkey.get_str();
	auto valPubkey = find_value(obj, "pubkey");
	CheckJSONType(valPubkey, "string", "pubkey");
	strPubkey = valPubkey.get_str();
	return *this;
}
string CMakeKeyPairResult::Method() const
{
	return "makekeypair";
}

/////////////////////////////////////////////////////
// getpubkeyaddress

// CGetPubkeyAddressParam
CGetPubkeyAddressParam::CGetPubkeyAddressParam() {}
CGetPubkeyAddressParam::CGetPubkeyAddressParam(const CRPCString& strPubkey, const CRPCString& strReversal)
	: strPubkey(strPubkey), strReversal(strReversal)
{
}
Value CGetPubkeyAddressParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strPubkey, "strPubkey");
	ret.push_back(Pair("pubkey", std::string(strPubkey)));
	if (strReversal.IsValid())
	{
		ret.push_back(Pair("reversal", std::string(strReversal)));
	}

	return ret;
}
CGetPubkeyAddressParam& CGetPubkeyAddressParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "getpubkeyaddress");
	auto obj = v.get_obj();
	auto valPubkey = find_value(obj, "pubkey");
	CheckJSONType(valPubkey, "string", "pubkey");
	strPubkey = valPubkey.get_str();
	auto valReversal = find_value(obj, "reversal");
	if (!valReversal.is_null())
	{
		CheckJSONType(valReversal, "string", "reversal");
		strReversal = valReversal.get_str();
	}
	return *this;
}
string CGetPubkeyAddressParam::Method() const
{
	return "getpubkeyaddress";
}

// CGetPubkeyAddressResult
CGetPubkeyAddressResult::CGetPubkeyAddressResult() {}
CGetPubkeyAddressResult::CGetPubkeyAddressResult(const CRPCString& strAddress)
	: strAddress(strAddress)
{
}
Value CGetPubkeyAddressResult::ToJSON() const
{
	CheckIsValid(strAddress, "strAddress");
	Value val;
	val = Value(strAddress);
	return val;
}
CGetPubkeyAddressResult& CGetPubkeyAddressResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "address");
	strAddress = v.get_str();
	return *this;
}
string CGetPubkeyAddressResult::Method() const
{
	return "getpubkeyaddress";
}

/////////////////////////////////////////////////////
// gettemplateaddress

// CGetTemplateAddressParam
CGetTemplateAddressParam::CGetTemplateAddressParam() {}
CGetTemplateAddressParam::CGetTemplateAddressParam(const CRPCString& strTid)
	: strTid(strTid)
{
}
Value CGetTemplateAddressParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strTid, "strTid");
	ret.push_back(Pair("tid", std::string(strTid)));

	return ret;
}
CGetTemplateAddressParam& CGetTemplateAddressParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "gettemplateaddress");
	auto obj = v.get_obj();
	auto valTid = find_value(obj, "tid");
	CheckJSONType(valTid, "string", "tid");
	strTid = valTid.get_str();
	return *this;
}
string CGetTemplateAddressParam::Method() const
{
	return "gettemplateaddress";
}

// CGetTemplateAddressResult
CGetTemplateAddressResult::CGetTemplateAddressResult() {}
CGetTemplateAddressResult::CGetTemplateAddressResult(const CRPCString& strAddress)
	: strAddress(strAddress)
{
}
Value CGetTemplateAddressResult::ToJSON() const
{
	CheckIsValid(strAddress, "strAddress");
	Value val;
	val = Value(strAddress);
	return val;
}
CGetTemplateAddressResult& CGetTemplateAddressResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "address");
	strAddress = v.get_str();
	return *this;
}
string CGetTemplateAddressResult::Method() const
{
	return "gettemplateaddress";
}

/////////////////////////////////////////////////////
// maketemplate

// CMakeTemplateParam
CMakeTemplateParam::CMakeTemplateParam() {}
CMakeTemplateParam::CMakeTemplateParam(const CTemplateRequest& data)
	: data(data)
{
}
Value CMakeTemplateParam::ToJSON() const
{
	CheckIsValid(data, "data");
	return data.ToJSON();
}
CMakeTemplateParam& CMakeTemplateParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "data");
	data.FromJSON(v.get_obj());
	return *this;
}
string CMakeTemplateParam::Method() const
{
	return "maketemplate";
}

// CMakeTemplateResult
CMakeTemplateResult::CMakeTemplateResult() {}
CMakeTemplateResult::CMakeTemplateResult(const CRPCString& strAddress, const CRPCString& strHex)
	: strAddress(strAddress), strHex(strHex)
{
}
Value CMakeTemplateResult::ToJSON() const
{
	Object ret;
	CheckIsValid(strAddress, "strAddress");
	ret.push_back(Pair("address", std::string(strAddress)));
	CheckIsValid(strHex, "strHex");
	ret.push_back(Pair("hex", std::string(strHex)));

	return ret;
}
CMakeTemplateResult& CMakeTemplateResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "maketemplate");
	auto obj = v.get_obj();
	auto valAddress = find_value(obj, "address");
	CheckJSONType(valAddress, "string", "address");
	strAddress = valAddress.get_str();
	auto valHex = find_value(obj, "hex");
	CheckJSONType(valHex, "string", "hex");
	strHex = valHex.get_str();
	return *this;
}
string CMakeTemplateResult::Method() const
{
	return "maketemplate";
}

/////////////////////////////////////////////////////
// decodetransaction

// CDecodeTransactionParam
CDecodeTransactionParam::CDecodeTransactionParam() {}
CDecodeTransactionParam::CDecodeTransactionParam(const CRPCString& strTxdata)
	: strTxdata(strTxdata)
{
}
Value CDecodeTransactionParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strTxdata, "strTxdata");
	ret.push_back(Pair("txdata", std::string(strTxdata)));

	return ret;
}
CDecodeTransactionParam& CDecodeTransactionParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "decodetransaction");
	auto obj = v.get_obj();
	auto valTxdata = find_value(obj, "txdata");
	CheckJSONType(valTxdata, "string", "txdata");
	strTxdata = valTxdata.get_str();
	return *this;
}
string CDecodeTransactionParam::Method() const
{
	return "decodetransaction";
}

// CDecodeTransactionResult
CDecodeTransactionResult::CDecodeTransactionResult() {}
CDecodeTransactionResult::CDecodeTransactionResult(const CTransactionData& transaction)
	: transaction(transaction)
{
}
Value CDecodeTransactionResult::ToJSON() const
{
	CheckIsValid(transaction, "transaction");
	return transaction.ToJSON();
}
CDecodeTransactionResult& CDecodeTransactionResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "transaction");
	transaction.FromJSON(v.get_obj());
	return *this;
}
string CDecodeTransactionResult::Method() const
{
	return "decodetransaction";
}

/////////////////////////////////////////////////////
// listunspent

// CListUnspentParam
CListUnspentParam::CListUnspentParam() {}
CListUnspentParam::CListUnspentParam(const CRPCString& strAddress, const CRPCString& strFork, const CRPCUint64& nMax, const CRPCString& strFile)
	: strAddress(strAddress), strFork(strFork), nMax(nMax), strFile(strFile)
{
}
Value CListUnspentParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strAddress, "strAddress");
	ret.push_back(Pair("address", std::string(strAddress)));
	if (strFork.IsValid())
	{
		ret.push_back(Pair("fork", std::string(strFork)));
	}
	if (nMax.IsValid())
	{
		ret.push_back(Pair("max", uint64(nMax)));
	}
	if (strFile.IsValid())
	{
		ret.push_back(Pair("file", std::string(strFile)));
	}

	return ret;
}
CListUnspentParam& CListUnspentParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "listunspent");
	auto obj = v.get_obj();
	auto valAddress = find_value(obj, "address");
	CheckJSONType(valAddress, "string", "address");
	strAddress = valAddress.get_str();
	auto valFork = find_value(obj, "fork");
	if (!valFork.is_null())
	{
		CheckJSONType(valFork, "string", "fork");
		strFork = valFork.get_str();
	}
	auto valMax = find_value(obj, "max");
	if (!valMax.is_null())
	{
		CheckJSONType(valMax, "uint", "max");
		nMax = valMax.get_uint64();
	}
	auto valFile = find_value(obj, "file");
	if (!valFile.is_null())
	{
		CheckJSONType(valFile, "string", "file");
		strFile = valFile.get_str();
	}
	return *this;
}
string CListUnspentParam::Method() const
{
	return "listunspent";
}

// CListUnspentResult::CAddresses
CListUnspentResult::CAddresses::CAddresses() {}
CListUnspentResult::CAddresses::CAddresses(const CRPCString& strAddress, const CRPCVector<CUnspentData>& vecUnspents, const CRPCDouble& dSum)
	: strAddress(strAddress), vecUnspents(vecUnspents), dSum(dSum)
{
}
CListUnspentResult::CAddresses::CAddresses(const CRPCType& null)
	: strAddress(null), vecUnspents(null), dSum(null)
{
}
Value CListUnspentResult::CAddresses::ToJSON() const
{
	Object ret;
	CheckIsValid(strAddress, "strAddress");
	ret.push_back(Pair("address", std::string(strAddress)));
	CheckIsValid(vecUnspents, "vecUnspents");
	Array vecUnspentsArray;
	for (auto& v : vecUnspents)
	{
		vecUnspentsArray.push_back(v.ToJSON());
	}
	ret.push_back(Pair("unspents", vecUnspentsArray));
	CheckIsValid(dSum, "dSum");
	ret.push_back(Pair("sum", double(dSum)));

	return ret;
}
CListUnspentResult::CAddresses& CListUnspentResult::CAddresses::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CListUnspentResult::CAddresses");
	auto obj = v.get_obj();
	auto valAddress = find_value(obj, "address");
	CheckJSONType(valAddress, "string", "address");
	strAddress = valAddress.get_str();
	auto valUnspents = find_value(obj, "unspents");
	CheckJSONType(valUnspents, "array", "unspents");
	auto vecUnspentsArray = valUnspents.get_array();
	for (auto& v : vecUnspentsArray)
	{
		vecUnspents.push_back(CRPCVector<CUnspentData>::value_type().FromJSON(v));
	}
	auto valSum = find_value(obj, "sum");
	CheckJSONType(valSum, "double", "sum");
	dSum = valSum.get_real();
	return *this;
}
bool CListUnspentResult::CAddresses::IsValid() const
{
	if (!strAddress.IsValid()) { return false; }
	if (!vecUnspents.IsValid()) { return false; }
	if (!dSum.IsValid()) { return false; }
	return true;
}

// CListUnspentResult
CListUnspentResult::CListUnspentResult() {}
CListUnspentResult::CListUnspentResult(const CRPCVector<CAddresses>& vecAddresses, const CRPCDouble& dTotal)
	: vecAddresses(vecAddresses), dTotal(dTotal)
{
}
Value CListUnspentResult::ToJSON() const
{
	Object ret;
	CheckIsValid(vecAddresses, "vecAddresses");
	Array vecAddressesArray;
	for (auto& v : vecAddresses)
	{
		vecAddressesArray.push_back(v.ToJSON());
	}
	ret.push_back(Pair("addresses", vecAddressesArray));
	CheckIsValid(dTotal, "dTotal");
	ret.push_back(Pair("total", double(dTotal)));

	return ret;
}
CListUnspentResult& CListUnspentResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "listunspent");
	auto obj = v.get_obj();
	auto valAddresses = find_value(obj, "addresses");
	CheckJSONType(valAddresses, "array", "addresses");
	auto vecAddressesArray = valAddresses.get_array();
	for (auto& v : vecAddressesArray)
	{
		vecAddresses.push_back(CRPCVector<CAddresses>::value_type().FromJSON(v));
	}
	auto valTotal = find_value(obj, "total");
	CheckJSONType(valTotal, "double", "total");
	dTotal = valTotal.get_real();
	return *this;
}
string CListUnspentResult::Method() const
{
	return "listunspent";
}

/////////////////////////////////////////////////////
// getwork

// CGetWorkParam
CGetWorkParam::CGetWorkParam() {}
CGetWorkParam::CGetWorkParam(const CRPCString& strSpent, const CRPCString& strPrivkey, const CRPCString& strPrev)
	: strSpent(strSpent), strPrivkey(strPrivkey), strPrev(strPrev)
{
}
Value CGetWorkParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strSpent, "strSpent");
	ret.push_back(Pair("spent", std::string(strSpent)));
	CheckIsValid(strPrivkey, "strPrivkey");
	ret.push_back(Pair("privkey", std::string(strPrivkey)));
	if (strPrev.IsValid())
	{
		ret.push_back(Pair("prev", std::string(strPrev)));
	}

	return ret;
}
CGetWorkParam& CGetWorkParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "getwork");
	auto obj = v.get_obj();
	auto valSpent = find_value(obj, "spent");
	CheckJSONType(valSpent, "string", "spent");
	strSpent = valSpent.get_str();
	auto valPrivkey = find_value(obj, "privkey");
	CheckJSONType(valPrivkey, "string", "privkey");
	strPrivkey = valPrivkey.get_str();
	auto valPrev = find_value(obj, "prev");
	if (!valPrev.is_null())
	{
		CheckJSONType(valPrev, "string", "prev");
		strPrev = valPrev.get_str();
	}
	return *this;
}
string CGetWorkParam::Method() const
{
	return "getwork";
}

// CGetWorkResult::CWork
CGetWorkResult::CWork::CWork() {}
CGetWorkResult::CWork::CWork(const CRPCInt64& nPrevblockheight, const CRPCString& strPrevblockhash, const CRPCUint64& nPrevblocktime, const CRPCInt64& nAlgo, const CRPCString& strBits, const CRPCString& strData)
	: nPrevblockheight(nPrevblockheight), strPrevblockhash(strPrevblockhash), nPrevblocktime(nPrevblocktime), nAlgo(nAlgo), strBits(strBits), strData(strData)
{
}
CGetWorkResult::CWork::CWork(const CRPCType& null)
	: nPrevblockheight(null), strPrevblockhash(null), nPrevblocktime(null), nAlgo(null), strBits(null), strData(null)
{
}
Value CGetWorkResult::CWork::ToJSON() const
{
	Object ret;
	CheckIsValid(nPrevblockheight, "nPrevblockheight");
	ret.push_back(Pair("prevblockheight", int64(nPrevblockheight)));
	CheckIsValid(strPrevblockhash, "strPrevblockhash");
	ret.push_back(Pair("prevblockhash", std::string(strPrevblockhash)));
	CheckIsValid(nPrevblocktime, "nPrevblocktime");
	ret.push_back(Pair("prevblocktime", uint64(nPrevblocktime)));
	CheckIsValid(nAlgo, "nAlgo");
	ret.push_back(Pair("algo", int64(nAlgo)));
	CheckIsValid(strBits, "strBits");
	ret.push_back(Pair("bits", std::string(strBits)));
	CheckIsValid(strData, "strData");
	ret.push_back(Pair("data", std::string(strData)));

	return ret;
}
CGetWorkResult::CWork& CGetWorkResult::CWork::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "CGetWorkResult::CWork");
	auto obj = v.get_obj();
	auto valPrevblockheight = find_value(obj, "prevblockheight");
	CheckJSONType(valPrevblockheight, "int", "prevblockheight");
	nPrevblockheight = valPrevblockheight.get_int64();
	auto valPrevblockhash = find_value(obj, "prevblockhash");
	CheckJSONType(valPrevblockhash, "string", "prevblockhash");
	strPrevblockhash = valPrevblockhash.get_str();
	auto valPrevblocktime = find_value(obj, "prevblocktime");
	CheckJSONType(valPrevblocktime, "uint", "prevblocktime");
	nPrevblocktime = valPrevblocktime.get_uint64();
	auto valAlgo = find_value(obj, "algo");
	CheckJSONType(valAlgo, "int", "algo");
	nAlgo = valAlgo.get_int64();
	auto valBits = find_value(obj, "bits");
	CheckJSONType(valBits, "string", "bits");
	strBits = valBits.get_str();
	auto valData = find_value(obj, "data");
	CheckJSONType(valData, "string", "data");
	strData = valData.get_str();
	return *this;
}
bool CGetWorkResult::CWork::IsValid() const
{
	if (!nPrevblockheight.IsValid()) { return false; }
	if (!strPrevblockhash.IsValid()) { return false; }
	if (!nPrevblocktime.IsValid()) { return false; }
	if (!nAlgo.IsValid()) { return false; }
	if (!strBits.IsValid()) { return false; }
	if (!strData.IsValid()) { return false; }
	return true;
}

// CGetWorkResult
CGetWorkResult::CGetWorkResult() {}
CGetWorkResult::CGetWorkResult(const CRPCBool& fResult, const CWork& work)
	: fResult(fResult), work(work)
{
}
Value CGetWorkResult::ToJSON() const
{
	Object ret;
	if (fResult.IsValid())
	{
		ret.push_back(Pair("result", bool(fResult)));
	}
	if (work.IsValid())
	{
		ret.push_back(Pair("work", work.ToJSON()));
	}

	return ret;
}
CGetWorkResult& CGetWorkResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "getwork");
	auto obj = v.get_obj();
	auto valResult = find_value(obj, "result");
	if (!valResult.is_null())
	{
		CheckJSONType(valResult, "bool", "result");
		fResult = valResult.get_bool();
	}
	auto valWork = find_value(obj, "work");
	if (!valWork.is_null())
	{
		CheckJSONType(valWork, "object", "work");
		work.FromJSON(valWork.get_obj());
	}
	return *this;
}
string CGetWorkResult::Method() const
{
	return "getwork";
}

/////////////////////////////////////////////////////
// submitwork

// CSubmitWorkParam
CSubmitWorkParam::CSubmitWorkParam() {}
CSubmitWorkParam::CSubmitWorkParam(const CRPCString& strData, const CRPCString& strSpent, const CRPCString& strPrivkey)
	: strData(strData), strSpent(strSpent), strPrivkey(strPrivkey)
{
}
Value CSubmitWorkParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strData, "strData");
	ret.push_back(Pair("data", std::string(strData)));
	CheckIsValid(strSpent, "strSpent");
	ret.push_back(Pair("spent", std::string(strSpent)));
	CheckIsValid(strPrivkey, "strPrivkey");
	ret.push_back(Pair("privkey", std::string(strPrivkey)));

	return ret;
}
CSubmitWorkParam& CSubmitWorkParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "submitwork");
	auto obj = v.get_obj();
	auto valData = find_value(obj, "data");
	CheckJSONType(valData, "string", "data");
	strData = valData.get_str();
	auto valSpent = find_value(obj, "spent");
	CheckJSONType(valSpent, "string", "spent");
	strSpent = valSpent.get_str();
	auto valPrivkey = find_value(obj, "privkey");
	CheckJSONType(valPrivkey, "string", "privkey");
	strPrivkey = valPrivkey.get_str();
	return *this;
}
string CSubmitWorkParam::Method() const
{
	return "submitwork";
}

// CSubmitWorkResult
CSubmitWorkResult::CSubmitWorkResult() {}
CSubmitWorkResult::CSubmitWorkResult(const CRPCString& strHash)
	: strHash(strHash)
{
}
Value CSubmitWorkResult::ToJSON() const
{
	CheckIsValid(strHash, "strHash");
	Value val;
	val = Value(strHash);
	return val;
}
CSubmitWorkResult& CSubmitWorkResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "hash");
	strHash = v.get_str();
	return *this;
}
string CSubmitWorkResult::Method() const
{
	return "submitwork";
}

/////////////////////////////////////////////////////
// querystat

// CQueryStatParam
CQueryStatParam::CQueryStatParam() {}
CQueryStatParam::CQueryStatParam(const CRPCString& strType, const CRPCString& strFork, const CRPCString& strBegin, const CRPCUint64& nCount)
	: strType(strType), strFork(strFork), strBegin(strBegin), nCount(nCount)
{
}
Value CQueryStatParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strType, "strType");
	ret.push_back(Pair("type", std::string(strType)));
	if (strFork.IsValid())
	{
		ret.push_back(Pair("fork", std::string(strFork)));
	}
	if (strBegin.IsValid())
	{
		ret.push_back(Pair("begin", std::string(strBegin)));
	}
	if (nCount.IsValid())
	{
		ret.push_back(Pair("count", uint64(nCount)));
	}

	return ret;
}
CQueryStatParam& CQueryStatParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "querystat");
	auto obj = v.get_obj();
	auto valType = find_value(obj, "type");
	CheckJSONType(valType, "string", "type");
	strType = valType.get_str();
	auto valFork = find_value(obj, "fork");
	if (!valFork.is_null())
	{
		CheckJSONType(valFork, "string", "fork");
		strFork = valFork.get_str();
	}
	auto valBegin = find_value(obj, "begin");
	if (!valBegin.is_null())
	{
		CheckJSONType(valBegin, "string", "begin");
		strBegin = valBegin.get_str();
	}
	auto valCount = find_value(obj, "count");
	if (!valCount.is_null())
	{
		CheckJSONType(valCount, "uint", "count");
		nCount = valCount.get_uint64();
	}
	return *this;
}
string CQueryStatParam::Method() const
{
	return "querystat";
}

// CQueryStatResult
CQueryStatResult::CQueryStatResult() {}
CQueryStatResult::CQueryStatResult(const CRPCString& strStattable)
	: strStattable(strStattable)
{
}
Value CQueryStatResult::ToJSON() const
{
	CheckIsValid(strStattable, "strStattable");
	Value val;
	val = Value(strStattable);
	return val;
}
CQueryStatResult& CQueryStatResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "stattable");
	strStattable = v.get_str();
	return *this;
}
string CQueryStatResult::Method() const
{
	return "querystat";
}

/////////////////////////////////////////////////////
// signrawtransactionwithwallet

// CSignRawTransactionWithWalletParam
CSignRawTransactionWithWalletParam::CSignRawTransactionWithWalletParam() {}
CSignRawTransactionWithWalletParam::CSignRawTransactionWithWalletParam(const CRPCString& strAddrin, const CRPCString& strTxdata)
	: strAddrin(strAddrin), strTxdata(strTxdata)
{
}
Value CSignRawTransactionWithWalletParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strAddrin, "strAddrin");
	ret.push_back(Pair("addrIn", std::string(strAddrin)));
	CheckIsValid(strTxdata, "strTxdata");
	ret.push_back(Pair("txdata", std::string(strTxdata)));

	return ret;
}
CSignRawTransactionWithWalletParam& CSignRawTransactionWithWalletParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "signrawtransactionwithwallet");
	auto obj = v.get_obj();
	auto valAddrin = find_value(obj, "addrIn");
	CheckJSONType(valAddrin, "string", "addrIn");
	strAddrin = valAddrin.get_str();
	auto valTxdata = find_value(obj, "txdata");
	CheckJSONType(valTxdata, "string", "txdata");
	strTxdata = valTxdata.get_str();
	return *this;
}
string CSignRawTransactionWithWalletParam::Method() const
{
	return "signrawtransactionwithwallet";
}

// CSignRawTransactionWithWalletResult
CSignRawTransactionWithWalletResult::CSignRawTransactionWithWalletResult() {}
CSignRawTransactionWithWalletResult::CSignRawTransactionWithWalletResult(const CRPCString& strHex, const CRPCBool& fCompleted)
	: strHex(strHex), fCompleted(fCompleted)
{
}
Value CSignRawTransactionWithWalletResult::ToJSON() const
{
	Object ret;
	CheckIsValid(strHex, "strHex");
	ret.push_back(Pair("hex", std::string(strHex)));
	CheckIsValid(fCompleted, "fCompleted");
	ret.push_back(Pair("completed", bool(fCompleted)));

	return ret;
}
CSignRawTransactionWithWalletResult& CSignRawTransactionWithWalletResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "signrawtransactionwithwallet");
	auto obj = v.get_obj();
	auto valHex = find_value(obj, "hex");
	CheckJSONType(valHex, "string", "hex");
	strHex = valHex.get_str();
	auto valCompleted = find_value(obj, "completed");
	CheckJSONType(valCompleted, "bool", "completed");
	fCompleted = valCompleted.get_bool();
	return *this;
}
string CSignRawTransactionWithWalletResult::Method() const
{
	return "signrawtransactionwithwallet";
}

/////////////////////////////////////////////////////
// sendrawtransaction

// CSendRawTransactionParam
CSendRawTransactionParam::CSendRawTransactionParam() {}
CSendRawTransactionParam::CSendRawTransactionParam(const CRPCString& strTxdata)
	: strTxdata(strTxdata)
{
}
Value CSendRawTransactionParam::ToJSON() const
{
	Object ret;
	CheckIsValid(strTxdata, "strTxdata");
	ret.push_back(Pair("txdata", std::string(strTxdata)));

	return ret;
}
CSendRawTransactionParam& CSendRawTransactionParam::FromJSON(const Value& v)
{
	CheckJSONType(v, "object", "sendrawtransaction");
	auto obj = v.get_obj();
	auto valTxdata = find_value(obj, "txdata");
	CheckJSONType(valTxdata, "string", "txdata");
	strTxdata = valTxdata.get_str();
	return *this;
}
string CSendRawTransactionParam::Method() const
{
	return "sendrawtransaction";
}

// CSendRawTransactionResult
CSendRawTransactionResult::CSendRawTransactionResult() {}
CSendRawTransactionResult::CSendRawTransactionResult(const CRPCString& strData)
	: strData(strData)
{
}
Value CSendRawTransactionResult::ToJSON() const
{
	CheckIsValid(strData, "strData");
	Value val;
	val = Value(strData);
	return val;
}
CSendRawTransactionResult& CSendRawTransactionResult::FromJSON(const Value& v)
{
	CheckJSONType(v, "string", "data");
	strData = v.get_str();
	return *this;
}
string CSendRawTransactionResult::Method() const
{
	return "sendrawtransaction";
}

CRPCParamPtr CreateCRPCParam(const std::string& cmd, const json_spirit::Value& valParam)
{
	if (cmd == "help")
	{
		auto ptr = MakeCHelpParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "stop")
	{
		auto ptr = MakeCStopParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "version")
	{
		auto ptr = MakeCVersionParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "getpeercount")
	{
		auto ptr = MakeCGetPeerCountParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "listpeer")
	{
		auto ptr = MakeCListPeerParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "addnode")
	{
		auto ptr = MakeCAddNodeParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "removenode")
	{
		auto ptr = MakeCRemoveNodeParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "getforkcount")
	{
		auto ptr = MakeCGetForkCountParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "listfork")
	{
		auto ptr = MakeCListForkParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "getgenealogy")
	{
		auto ptr = MakeCGetGenealogyParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "getblocklocation")
	{
		auto ptr = MakeCGetBlockLocationParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "getblockcount")
	{
		auto ptr = MakeCGetBlockCountParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "getblockhash")
	{
		auto ptr = MakeCGetBlockHashParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "getblock")
	{
		auto ptr = MakeCGetBlockParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "getblockdetail")
	{
		auto ptr = MakeCgetblockdetailParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "gettxpool")
	{
		auto ptr = MakeCGetTxPoolParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "gettransaction")
	{
		auto ptr = MakeCGetTransactionParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "sendtransaction")
	{
		auto ptr = MakeCSendTransactionParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "getforkheight")
	{
		auto ptr = MakeCGetForkHeightParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "listkey")
	{
		auto ptr = MakeCListKeyParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "getnewkey")
	{
		auto ptr = MakeCGetNewKeyParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "encryptkey")
	{
		auto ptr = MakeCEncryptKeyParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "lockkey")
	{
		auto ptr = MakeCLockKeyParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "unlockkey")
	{
		auto ptr = MakeCUnlockKeyParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "importprivkey")
	{
		auto ptr = MakeCImportPrivKeyParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "importpubkey")
	{
		auto ptr = MakeCImportPubKeyParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "importkey")
	{
		auto ptr = MakeCImportKeyParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "exportkey")
	{
		auto ptr = MakeCExportKeyParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "addnewtemplate")
	{
		auto ptr = MakeCAddNewTemplateParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "importtemplate")
	{
		auto ptr = MakeCImportTemplateParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "exporttemplate")
	{
		auto ptr = MakeCExportTemplateParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "validateaddress")
	{
		auto ptr = MakeCValidateAddressParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "resyncwallet")
	{
		auto ptr = MakeCResyncWalletParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "getbalance")
	{
		auto ptr = MakeCGetBalanceParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "listtransaction")
	{
		auto ptr = MakeCListTransactionParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "sendfrom")
	{
		auto ptr = MakeCSendFromParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "createtransaction")
	{
		auto ptr = MakeCCreateTransactionParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "signtransaction")
	{
		auto ptr = MakeCSignTransactionParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "signmessage")
	{
		auto ptr = MakeCSignMessageParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "listaddress")
	{
		auto ptr = MakeCListAddressParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "exportwallet")
	{
		auto ptr = MakeCExportWalletParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "importwallet")
	{
		auto ptr = MakeCImportWalletParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "verifymessage")
	{
		auto ptr = MakeCVerifyMessageParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "makekeypair")
	{
		auto ptr = MakeCMakeKeyPairParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "getpubkeyaddress")
	{
		auto ptr = MakeCGetPubkeyAddressParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "gettemplateaddress")
	{
		auto ptr = MakeCGetTemplateAddressParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "maketemplate")
	{
		auto ptr = MakeCMakeTemplateParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "decodetransaction")
	{
		auto ptr = MakeCDecodeTransactionParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "listunspent")
	{
		auto ptr = MakeCListUnspentParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "getwork")
	{
		auto ptr = MakeCGetWorkParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "submitwork")
	{
		auto ptr = MakeCSubmitWorkParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "querystat")
	{
		auto ptr = MakeCQueryStatParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "signrawtransactionwithwallet")
	{
		auto ptr = MakeCSignRawTransactionWithWalletParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else if (cmd == "sendrawtransaction")
	{
		auto ptr = MakeCSendRawTransactionParamPtr();
		ptr->FromJSON(valParam);
		return ptr;
	}
	else 
	{
		throw CRPCException(RPC_METHOD_NOT_FOUND, cmd + " not found!");
	}
}

CRPCResultPtr CreateCRPCResult(const std::string& cmd, const json_spirit::Value& valResult)
{
	if (cmd == "help")
	{
		auto ptr = MakeCHelpResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "stop")
	{
		auto ptr = MakeCStopResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "version")
	{
		auto ptr = MakeCVersionResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "getpeercount")
	{
		auto ptr = MakeCGetPeerCountResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "listpeer")
	{
		auto ptr = MakeCListPeerResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "addnode")
	{
		auto ptr = MakeCAddNodeResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "removenode")
	{
		auto ptr = MakeCRemoveNodeResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "getforkcount")
	{
		auto ptr = MakeCGetForkCountResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "listfork")
	{
		auto ptr = MakeCListForkResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "getgenealogy")
	{
		auto ptr = MakeCGetGenealogyResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "getblocklocation")
	{
		auto ptr = MakeCGetBlockLocationResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "getblockcount")
	{
		auto ptr = MakeCGetBlockCountResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "getblockhash")
	{
		auto ptr = MakeCGetBlockHashResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "getblock")
	{
		auto ptr = MakeCGetBlockResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "getblockdetail")
	{
		auto ptr = MakeCgetblockdetailResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "gettxpool")
	{
		auto ptr = MakeCGetTxPoolResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "gettransaction")
	{
		auto ptr = MakeCGetTransactionResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "sendtransaction")
	{
		auto ptr = MakeCSendTransactionResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "getforkheight")
	{
		auto ptr = MakeCGetForkHeightResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "listkey")
	{
		auto ptr = MakeCListKeyResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "getnewkey")
	{
		auto ptr = MakeCGetNewKeyResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "encryptkey")
	{
		auto ptr = MakeCEncryptKeyResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "lockkey")
	{
		auto ptr = MakeCLockKeyResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "unlockkey")
	{
		auto ptr = MakeCUnlockKeyResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "importprivkey")
	{
		auto ptr = MakeCImportPrivKeyResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "importpubkey")
	{
		auto ptr = MakeCImportPubKeyResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "importkey")
	{
		auto ptr = MakeCImportKeyResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "exportkey")
	{
		auto ptr = MakeCExportKeyResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "addnewtemplate")
	{
		auto ptr = MakeCAddNewTemplateResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "importtemplate")
	{
		auto ptr = MakeCImportTemplateResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "exporttemplate")
	{
		auto ptr = MakeCExportTemplateResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "validateaddress")
	{
		auto ptr = MakeCValidateAddressResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "resyncwallet")
	{
		auto ptr = MakeCResyncWalletResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "getbalance")
	{
		auto ptr = MakeCGetBalanceResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "listtransaction")
	{
		auto ptr = MakeCListTransactionResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "sendfrom")
	{
		auto ptr = MakeCSendFromResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "createtransaction")
	{
		auto ptr = MakeCCreateTransactionResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "signtransaction")
	{
		auto ptr = MakeCSignTransactionResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "signmessage")
	{
		auto ptr = MakeCSignMessageResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "listaddress")
	{
		auto ptr = MakeCListAddressResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "exportwallet")
	{
		auto ptr = MakeCExportWalletResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "importwallet")
	{
		auto ptr = MakeCImportWalletResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "verifymessage")
	{
		auto ptr = MakeCVerifyMessageResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "makekeypair")
	{
		auto ptr = MakeCMakeKeyPairResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "getpubkeyaddress")
	{
		auto ptr = MakeCGetPubkeyAddressResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "gettemplateaddress")
	{
		auto ptr = MakeCGetTemplateAddressResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "maketemplate")
	{
		auto ptr = MakeCMakeTemplateResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "decodetransaction")
	{
		auto ptr = MakeCDecodeTransactionResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "listunspent")
	{
		auto ptr = MakeCListUnspentResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "getwork")
	{
		auto ptr = MakeCGetWorkResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "submitwork")
	{
		auto ptr = MakeCSubmitWorkResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "querystat")
	{
		auto ptr = MakeCQueryStatResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "signrawtransactionwithwallet")
	{
		auto ptr = MakeCSignRawTransactionWithWalletResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else if (cmd == "sendrawtransaction")
	{
		auto ptr = MakeCSendRawTransactionResultPtr();
		ptr->FromJSON(valResult);
		return ptr;
	}
	else 
	{
		auto ptr = std::make_shared<CRPCCommonResult>();
		ptr->FromJSON(valResult);
		return ptr;
	}
}

const std::vector<std::string>& RPCCmdList()
{
	static std::vector<std::string> list = 
	{
		"help",
		"stop",
		"version",
		"getpeercount",
		"listpeer",
		"addnode",
		"removenode",
		"getforkcount",
		"listfork",
		"getgenealogy",
		"getblocklocation",
		"getblockcount",
		"getblockhash",
		"getblock",
		"getblockdetail",
		"gettxpool",
		"gettransaction",
		"sendtransaction",
		"getforkheight",
		"listkey",
		"getnewkey",
		"encryptkey",
		"lockkey",
		"unlockkey",
		"importprivkey",
		"importpubkey",
		"importkey",
		"exportkey",
		"addnewtemplate",
		"importtemplate",
		"exporttemplate",
		"validateaddress",
		"resyncwallet",
		"getbalance",
		"listtransaction",
		"sendfrom",
		"createtransaction",
		"signtransaction",
		"signmessage",
		"listaddress",
		"exportwallet",
		"importwallet",
		"verifymessage",
		"makekeypair",
		"getpubkeyaddress",
		"gettemplateaddress",
		"maketemplate",
		"decodetransaction",
		"listunspent",
		"getwork",
		"submitwork",
		"querystat",
		"signrawtransactionwithwallet",
		"sendrawtransaction",
	};
	return list;
}

}  // namespace rpc
}  // namespace bigbang

