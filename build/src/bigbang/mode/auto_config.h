// Copyright (c) 2019-2020 The Bigbang developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BIGBANG_MODE_AUTO_CONFIG_H
#define BIGBANG_MODE_AUTO_CONFIG_H

#include "mode/mode_impl.h"
#include "mode/mode_type.h"
#include "rpc/auto_protocol.h"

namespace bigbang
{


/////////////////////////////////////////////////////
// help

// CHelpConfig
class CHelpConfig : virtual public CBasicConfig, public rpc::CHelpParam
{
public:
	CHelpConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// stop

// CStopConfig
class CStopConfig : virtual public CBasicConfig, public rpc::CStopParam
{
public:
	CStopConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// version

// CVersionConfig
class CVersionConfig : virtual public CBasicConfig, public rpc::CVersionParam
{
public:
	CVersionConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// getpeercount

// CGetPeerCountConfig
class CGetPeerCountConfig : virtual public CBasicConfig, public rpc::CGetPeerCountParam
{
public:
	CGetPeerCountConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// listpeer

// CListPeerConfig
class CListPeerConfig : virtual public CBasicConfig, public rpc::CListPeerParam
{
public:
	CListPeerConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// addnode

// CAddNodeConfig
class CAddNodeConfig : virtual public CBasicConfig, public rpc::CAddNodeParam
{
public:
	CAddNodeConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// removenode

// CRemoveNodeConfig
class CRemoveNodeConfig : virtual public CBasicConfig, public rpc::CRemoveNodeParam
{
public:
	CRemoveNodeConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// getforkcount

// CGetForkCountConfig
class CGetForkCountConfig : virtual public CBasicConfig, public rpc::CGetForkCountParam
{
public:
	CGetForkCountConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// listfork

// CListForkConfig
class CListForkConfig : virtual public CBasicConfig, public rpc::CListForkParam
{
public:
	CListForkConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// getgenealogy

// CGetGenealogyConfig
class CGetGenealogyConfig : virtual public CBasicConfig, public rpc::CGetGenealogyParam
{
public:
	CGetGenealogyConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// getblocklocation

// CGetBlockLocationConfig
class CGetBlockLocationConfig : virtual public CBasicConfig, public rpc::CGetBlockLocationParam
{
public:
	CGetBlockLocationConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// getblockcount

// CGetBlockCountConfig
class CGetBlockCountConfig : virtual public CBasicConfig, public rpc::CGetBlockCountParam
{
public:
	CGetBlockCountConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// getblockhash

// CGetBlockHashConfig
class CGetBlockHashConfig : virtual public CBasicConfig, public rpc::CGetBlockHashParam
{
public:
	CGetBlockHashConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// getblock

// CGetBlockConfig
class CGetBlockConfig : virtual public CBasicConfig, public rpc::CGetBlockParam
{
public:
	CGetBlockConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// getblockdetail

// CgetblockdetailConfig
class CgetblockdetailConfig : virtual public CBasicConfig, public rpc::CgetblockdetailParam
{
public:
	CgetblockdetailConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// gettxpool

// CGetTxPoolConfig
class CGetTxPoolConfig : virtual public CBasicConfig, public rpc::CGetTxPoolParam
{
public:
	CGetTxPoolConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// gettransaction

// CGetTransactionConfig
class CGetTransactionConfig : virtual public CBasicConfig, public rpc::CGetTransactionParam
{
public:
	CGetTransactionConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// sendtransaction

// CSendTransactionConfig
class CSendTransactionConfig : virtual public CBasicConfig, public rpc::CSendTransactionParam
{
public:
	CSendTransactionConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// getforkheight

// CGetForkHeightConfig
class CGetForkHeightConfig : virtual public CBasicConfig, public rpc::CGetForkHeightParam
{
public:
	CGetForkHeightConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// listkey

// CListKeyConfig
class CListKeyConfig : virtual public CBasicConfig, public rpc::CListKeyParam
{
public:
	CListKeyConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// getnewkey

// CGetNewKeyConfig
class CGetNewKeyConfig : virtual public CBasicConfig, public rpc::CGetNewKeyParam
{
public:
	CGetNewKeyConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// encryptkey

// CEncryptKeyConfig
class CEncryptKeyConfig : virtual public CBasicConfig, public rpc::CEncryptKeyParam
{
public:
	CEncryptKeyConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// lockkey

// CLockKeyConfig
class CLockKeyConfig : virtual public CBasicConfig, public rpc::CLockKeyParam
{
public:
	CLockKeyConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// unlockkey

// CUnlockKeyConfig
class CUnlockKeyConfig : virtual public CBasicConfig, public rpc::CUnlockKeyParam
{
public:
	CUnlockKeyConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// importprivkey

// CImportPrivKeyConfig
class CImportPrivKeyConfig : virtual public CBasicConfig, public rpc::CImportPrivKeyParam
{
public:
	CImportPrivKeyConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// importpubkey

// CImportPubKeyConfig
class CImportPubKeyConfig : virtual public CBasicConfig, public rpc::CImportPubKeyParam
{
public:
	CImportPubKeyConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// importkey

// CImportKeyConfig
class CImportKeyConfig : virtual public CBasicConfig, public rpc::CImportKeyParam
{
public:
	CImportKeyConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// exportkey

// CExportKeyConfig
class CExportKeyConfig : virtual public CBasicConfig, public rpc::CExportKeyParam
{
public:
	CExportKeyConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// addnewtemplate

// CAddNewTemplateConfig
class CAddNewTemplateConfig : virtual public CBasicConfig, public rpc::CAddNewTemplateParam
{
public:
	CAddNewTemplateConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// importtemplate

// CImportTemplateConfig
class CImportTemplateConfig : virtual public CBasicConfig, public rpc::CImportTemplateParam
{
public:
	CImportTemplateConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// exporttemplate

// CExportTemplateConfig
class CExportTemplateConfig : virtual public CBasicConfig, public rpc::CExportTemplateParam
{
public:
	CExportTemplateConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// validateaddress

// CValidateAddressConfig
class CValidateAddressConfig : virtual public CBasicConfig, public rpc::CValidateAddressParam
{
public:
	CValidateAddressConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// resyncwallet

// CResyncWalletConfig
class CResyncWalletConfig : virtual public CBasicConfig, public rpc::CResyncWalletParam
{
public:
	CResyncWalletConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// getbalance

// CGetBalanceConfig
class CGetBalanceConfig : virtual public CBasicConfig, public rpc::CGetBalanceParam
{
public:
	CGetBalanceConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// listtransaction

// CListTransactionConfig
class CListTransactionConfig : virtual public CBasicConfig, public rpc::CListTransactionParam
{
public:
	CListTransactionConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// sendfrom

// CSendFromConfig
class CSendFromConfig : virtual public CBasicConfig, public rpc::CSendFromParam
{
public:
	CSendFromConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// createtransaction

// CCreateTransactionConfig
class CCreateTransactionConfig : virtual public CBasicConfig, public rpc::CCreateTransactionParam
{
public:
	CCreateTransactionConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// signtransaction

// CSignTransactionConfig
class CSignTransactionConfig : virtual public CBasicConfig, public rpc::CSignTransactionParam
{
public:
	CSignTransactionConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// signmessage

// CSignMessageConfig
class CSignMessageConfig : virtual public CBasicConfig, public rpc::CSignMessageParam
{
public:
	CSignMessageConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// listaddress

// CListAddressConfig
class CListAddressConfig : virtual public CBasicConfig, public rpc::CListAddressParam
{
public:
	CListAddressConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// exportwallet

// CExportWalletConfig
class CExportWalletConfig : virtual public CBasicConfig, public rpc::CExportWalletParam
{
public:
	CExportWalletConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// importwallet

// CImportWalletConfig
class CImportWalletConfig : virtual public CBasicConfig, public rpc::CImportWalletParam
{
public:
	CImportWalletConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// verifymessage

// CVerifyMessageConfig
class CVerifyMessageConfig : virtual public CBasicConfig, public rpc::CVerifyMessageParam
{
public:
	CVerifyMessageConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// makekeypair

// CMakeKeyPairConfig
class CMakeKeyPairConfig : virtual public CBasicConfig, public rpc::CMakeKeyPairParam
{
public:
	CMakeKeyPairConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// getpubkeyaddress

// CGetPubkeyAddressConfig
class CGetPubkeyAddressConfig : virtual public CBasicConfig, public rpc::CGetPubkeyAddressParam
{
public:
	CGetPubkeyAddressConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// gettemplateaddress

// CGetTemplateAddressConfig
class CGetTemplateAddressConfig : virtual public CBasicConfig, public rpc::CGetTemplateAddressParam
{
public:
	CGetTemplateAddressConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// maketemplate

// CMakeTemplateConfig
class CMakeTemplateConfig : virtual public CBasicConfig, public rpc::CMakeTemplateParam
{
public:
	CMakeTemplateConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// decodetransaction

// CDecodeTransactionConfig
class CDecodeTransactionConfig : virtual public CBasicConfig, public rpc::CDecodeTransactionParam
{
public:
	CDecodeTransactionConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// listunspent

// CListUnspentConfig
class CListUnspentConfig : virtual public CBasicConfig, public rpc::CListUnspentParam
{
public:
	CListUnspentConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// getwork

// CGetWorkConfig
class CGetWorkConfig : virtual public CBasicConfig, public rpc::CGetWorkParam
{
public:
	CGetWorkConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// submitwork

// CSubmitWorkConfig
class CSubmitWorkConfig : virtual public CBasicConfig, public rpc::CSubmitWorkParam
{
public:
	CSubmitWorkConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// querystat

// CQueryStatConfig
class CQueryStatConfig : virtual public CBasicConfig, public rpc::CQueryStatParam
{
public:
	CQueryStatConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// signrawtransactionwithwallet

// CSignRawTransactionWithWalletConfig
class CSignRawTransactionWithWalletConfig : virtual public CBasicConfig, public rpc::CSignRawTransactionWithWalletParam
{
public:
	CSignRawTransactionWithWalletConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

/////////////////////////////////////////////////////
// sendrawtransaction

// CSendRawTransactionConfig
class CSendRawTransactionConfig : virtual public CBasicConfig, public rpc::CSendRawTransactionParam
{
public:
	CSendRawTransactionConfig();
	virtual bool PostLoad();
	virtual std::string ListConfig() const;
	virtual std::string Help() const;
};

// Return help info by mode type and sub command
std::string RPCHelpInfo(EModeType type, const std::string& subCmd, const std::string& options = "");

// Dynamic create combin config with rpc command
template <typename... T>
CBasicConfig* CreateRPCCommandConfig(const std::string& cmd)
{
	if (cmd == "help")
	{
		return new mode_impl::CCombinConfig<CHelpConfig, T...>;
	}
	else if (cmd == "stop")
	{
		return new mode_impl::CCombinConfig<CStopConfig, T...>;
	}
	else if (cmd == "version")
	{
		return new mode_impl::CCombinConfig<CVersionConfig, T...>;
	}
	else if (cmd == "getpeercount")
	{
		return new mode_impl::CCombinConfig<CGetPeerCountConfig, T...>;
	}
	else if (cmd == "listpeer")
	{
		return new mode_impl::CCombinConfig<CListPeerConfig, T...>;
	}
	else if (cmd == "addnode")
	{
		return new mode_impl::CCombinConfig<CAddNodeConfig, T...>;
	}
	else if (cmd == "removenode")
	{
		return new mode_impl::CCombinConfig<CRemoveNodeConfig, T...>;
	}
	else if (cmd == "getforkcount")
	{
		return new mode_impl::CCombinConfig<CGetForkCountConfig, T...>;
	}
	else if (cmd == "listfork")
	{
		return new mode_impl::CCombinConfig<CListForkConfig, T...>;
	}
	else if (cmd == "getgenealogy")
	{
		return new mode_impl::CCombinConfig<CGetGenealogyConfig, T...>;
	}
	else if (cmd == "getblocklocation")
	{
		return new mode_impl::CCombinConfig<CGetBlockLocationConfig, T...>;
	}
	else if (cmd == "getblockcount")
	{
		return new mode_impl::CCombinConfig<CGetBlockCountConfig, T...>;
	}
	else if (cmd == "getblockhash")
	{
		return new mode_impl::CCombinConfig<CGetBlockHashConfig, T...>;
	}
	else if (cmd == "getblock")
	{
		return new mode_impl::CCombinConfig<CGetBlockConfig, T...>;
	}
	else if (cmd == "getblockdetail")
	{
		return new mode_impl::CCombinConfig<CgetblockdetailConfig, T...>;
	}
	else if (cmd == "gettxpool")
	{
		return new mode_impl::CCombinConfig<CGetTxPoolConfig, T...>;
	}
	else if (cmd == "gettransaction")
	{
		return new mode_impl::CCombinConfig<CGetTransactionConfig, T...>;
	}
	else if (cmd == "sendtransaction")
	{
		return new mode_impl::CCombinConfig<CSendTransactionConfig, T...>;
	}
	else if (cmd == "getforkheight")
	{
		return new mode_impl::CCombinConfig<CGetForkHeightConfig, T...>;
	}
	else if (cmd == "listkey")
	{
		return new mode_impl::CCombinConfig<CListKeyConfig, T...>;
	}
	else if (cmd == "getnewkey")
	{
		return new mode_impl::CCombinConfig<CGetNewKeyConfig, T...>;
	}
	else if (cmd == "encryptkey")
	{
		return new mode_impl::CCombinConfig<CEncryptKeyConfig, T...>;
	}
	else if (cmd == "lockkey")
	{
		return new mode_impl::CCombinConfig<CLockKeyConfig, T...>;
	}
	else if (cmd == "unlockkey")
	{
		return new mode_impl::CCombinConfig<CUnlockKeyConfig, T...>;
	}
	else if (cmd == "importprivkey")
	{
		return new mode_impl::CCombinConfig<CImportPrivKeyConfig, T...>;
	}
	else if (cmd == "importpubkey")
	{
		return new mode_impl::CCombinConfig<CImportPubKeyConfig, T...>;
	}
	else if (cmd == "importkey")
	{
		return new mode_impl::CCombinConfig<CImportKeyConfig, T...>;
	}
	else if (cmd == "exportkey")
	{
		return new mode_impl::CCombinConfig<CExportKeyConfig, T...>;
	}
	else if (cmd == "addnewtemplate")
	{
		return new mode_impl::CCombinConfig<CAddNewTemplateConfig, T...>;
	}
	else if (cmd == "importtemplate")
	{
		return new mode_impl::CCombinConfig<CImportTemplateConfig, T...>;
	}
	else if (cmd == "exporttemplate")
	{
		return new mode_impl::CCombinConfig<CExportTemplateConfig, T...>;
	}
	else if (cmd == "validateaddress")
	{
		return new mode_impl::CCombinConfig<CValidateAddressConfig, T...>;
	}
	else if (cmd == "resyncwallet")
	{
		return new mode_impl::CCombinConfig<CResyncWalletConfig, T...>;
	}
	else if (cmd == "getbalance")
	{
		return new mode_impl::CCombinConfig<CGetBalanceConfig, T...>;
	}
	else if (cmd == "listtransaction")
	{
		return new mode_impl::CCombinConfig<CListTransactionConfig, T...>;
	}
	else if (cmd == "sendfrom")
	{
		return new mode_impl::CCombinConfig<CSendFromConfig, T...>;
	}
	else if (cmd == "createtransaction")
	{
		return new mode_impl::CCombinConfig<CCreateTransactionConfig, T...>;
	}
	else if (cmd == "signtransaction")
	{
		return new mode_impl::CCombinConfig<CSignTransactionConfig, T...>;
	}
	else if (cmd == "signmessage")
	{
		return new mode_impl::CCombinConfig<CSignMessageConfig, T...>;
	}
	else if (cmd == "listaddress")
	{
		return new mode_impl::CCombinConfig<CListAddressConfig, T...>;
	}
	else if (cmd == "exportwallet")
	{
		return new mode_impl::CCombinConfig<CExportWalletConfig, T...>;
	}
	else if (cmd == "importwallet")
	{
		return new mode_impl::CCombinConfig<CImportWalletConfig, T...>;
	}
	else if (cmd == "verifymessage")
	{
		return new mode_impl::CCombinConfig<CVerifyMessageConfig, T...>;
	}
	else if (cmd == "makekeypair")
	{
		return new mode_impl::CCombinConfig<CMakeKeyPairConfig, T...>;
	}
	else if (cmd == "getpubkeyaddress")
	{
		return new mode_impl::CCombinConfig<CGetPubkeyAddressConfig, T...>;
	}
	else if (cmd == "gettemplateaddress")
	{
		return new mode_impl::CCombinConfig<CGetTemplateAddressConfig, T...>;
	}
	else if (cmd == "maketemplate")
	{
		return new mode_impl::CCombinConfig<CMakeTemplateConfig, T...>;
	}
	else if (cmd == "decodetransaction")
	{
		return new mode_impl::CCombinConfig<CDecodeTransactionConfig, T...>;
	}
	else if (cmd == "listunspent")
	{
		return new mode_impl::CCombinConfig<CListUnspentConfig, T...>;
	}
	else if (cmd == "getwork")
	{
		return new mode_impl::CCombinConfig<CGetWorkConfig, T...>;
	}
	else if (cmd == "submitwork")
	{
		return new mode_impl::CCombinConfig<CSubmitWorkConfig, T...>;
	}
	else if (cmd == "querystat")
	{
		return new mode_impl::CCombinConfig<CQueryStatConfig, T...>;
	}
	else if (cmd == "signrawtransactionwithwallet")
	{
		return new mode_impl::CCombinConfig<CSignRawTransactionWithWalletConfig, T...>;
	}
	else if (cmd == "sendrawtransaction")
	{
		return new mode_impl::CCombinConfig<CSendRawTransactionConfig, T...>;
	}
	else 
	{
		return new mode_impl::CCombinConfig<T...>();
	}
}

}  // namespace bigbang

#endif  // BIGBANG_MODE_AUTO_CONFIG_H
