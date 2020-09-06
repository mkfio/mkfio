// Copyright (c) 2019-2020 The Bigbang developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BIGBANG_AUTO_OPTIONS_H
#define BIGBANG_AUTO_OPTIONS_H

#include <string>
#include <vector>
#include <sstream>

#include "mode/config_macro.h"

using std::string;
using std::vector;
using std::ostringstream;

namespace bigbang
{
class CBasicConfigOption
{
public:
	bool fTestNet;
	bool fWallet;
	bool fVersion;
	bool fPurge;
	bool fCheckRepair;
	bool fOnlyCheck;
	int nLogFileSize;
	int nLogHistorySize;
protected:
protected:
	string HelpImpl() const
	{
		ostringstream oss;
		oss << "  -testnet                              Use the test network\n";
		oss << "  -nowallet                             Launch server without wallet\n";
		oss << "  -version                              Get mkf version\n";
		oss << "  -purge                                Purge database and blockfile\n";
		oss << "  -checkrepair                          Check and repair database\n";
		oss << "  -onlycheck                            Only check database and blockfile\n";
		oss << "  -logfilesize=<size>                   Log file size(M) (default: 10M)\n";
		oss << "  -loghistorysize=<size>                Log history size(M) (default: 2048M)\n";
		return oss.str();
	}
	void AddOptionsImpl(boost::program_options::options_description& desc)
	{
		AddOpt(desc, "testnet", fTestNet, bool(false));
		AddOpt(desc, "wallet", fWallet, bool(true));
		AddOpt(desc, "version", fVersion, bool(false));
		AddOpt(desc, "purge", fPurge, bool(false));
		AddOpt(desc, "checkrepair", fCheckRepair, bool(true));
		AddOpt(desc, "onlycheck", fOnlyCheck, bool(false));
		AddOpt(desc, "logfilesize", nLogFileSize, int(10));
		AddOpt(desc, "loghistorysize", nLogHistorySize, int(2048));
	}
	string ListConfigImpl() const
	{
		ostringstream oss;
		oss << " -testnet: " << (fTestNet ? "Y" : "N") << "\n";
		oss << " -wallet: " << (fWallet ? "Y" : "N") << "\n";
		oss << " -version: " << (fVersion ? "Y" : "N") << "\n";
		oss << " -purge: " << (fPurge ? "Y" : "N") << "\n";
		oss << " -checkrepair: " << (fCheckRepair ? "Y" : "N") << "\n";
		oss << " -onlycheck: " << (fOnlyCheck ? "Y" : "N") << "\n";
		oss << " -logfilesize: " << nLogFileSize << "\n";
		oss << " -loghistorysize: " << nLogHistorySize << "\n";
		return oss.str();
	}
};
class CForkConfigOption
{
public:
	vector<string> vFork;
	vector<string> vGroup;
protected:
protected:
	string HelpImpl() const
	{
		ostringstream oss;
		oss << "  -addfork=<forkid>                     Add a supported fork\n";
		oss << "  -addgroup=<forkid of group leader>    Add a supported fork group\n";
		return oss.str();
	}
	void AddOptionsImpl(boost::program_options::options_description& desc)
	{
		AddOpt(desc, "addfork", vFork);
		AddOpt(desc, "addgroup", vGroup);
	}
	string ListConfigImpl() const
	{
		ostringstream oss;
		oss << " -addfork: ";
		for (auto& s: vFork)
		{
			oss << s << " ";
		}
		oss << "\n";
		oss << " -addgroup: ";
		for (auto& s: vGroup)
		{
			oss << s << " ";
		}
		oss << "\n";
		return oss.str();
	}
};
class CMintConfigOption
{
public:
	string strAddressMpvss;
	string strKeyMpvss;
	string strAddressCryptonight;
	string strkeyCryptonight;
protected:
protected:
	string HelpImpl() const
	{
		ostringstream oss;
		oss << "  -mpvssaddress=<address>               mpvss address\n";
		oss << "  -mpvsskey=<key>                       mpvss key\n";
		oss << "  -cryptonightaddress=<address>         POW cryptonight address\n";
		oss << "  -cryptonightkey=<key>                 POW cryptonight key\n";
		return oss.str();
	}
	void AddOptionsImpl(boost::program_options::options_description& desc)
	{
		AddOpt(desc, "mpvssaddress", strAddressMpvss);
		AddOpt(desc, "mpvsskey", strKeyMpvss);
		AddOpt(desc, "cryptonightaddress", strAddressCryptonight);
		AddOpt(desc, "cryptonightkey", strkeyCryptonight);
	}
	string ListConfigImpl() const
	{
		ostringstream oss;
		oss << " -mpvssaddress: " << strAddressMpvss << "\n";
		oss << " -mpvsskey: " << strKeyMpvss << "\n";
		oss << " -cryptonightaddress: " << strAddressCryptonight << "\n";
		oss << " -cryptonightkey: " << strkeyCryptonight << "\n";
		return oss.str();
	}
};
class CRPCBasicConfigOption
{
public:
	int nRPCPortInt;
	bool fRPCListen;
	bool fRPCListen4;
	bool fRPCListen6;
	string strRPCUser;
	string strRPCPass;
	bool fRPCSSLEnable;
	bool fRPCSSLVerify;
	string strRPCCAFile;
	string strRPCCertFile;
	string strRPCPKFile;
	string strRPCCiphers;
	bool fStatDataEnable;
	bool fRPCLogEnable;
protected:
protected:
	string HelpImpl() const
	{
		ostringstream oss;
		oss << "  -rpcport=port                         Listen for JSON-RPC connections on <port> (default: 9902 or testnet: 9904))\n";
		oss << "  -rpclisten                            Accept RPC IPv4 and IPv6 connections (default: 0)\n";
		oss << "  -rpclisten4                           Accept RPC IPv4 connections (default: 0)\n";
		oss << "  -rpclisten6                           Accept RPC IPv6 connections (default: 0)\n";
		oss << "  -rpcuser=<user>                       <user> name for JSON-RPC connections\n";
		oss << "  -rpcpassword=<password>               <password> for JSON-RPC connections\n";
		oss << "  -rpcssl                               Use OpenSSL (https) for JSON-RPC connections or not (default false)\n";
		oss << "  -norpcsslverify                       Verify SSL or not (default yes)\n";
		oss << "  -rpccafile=<file.crt>                 SSL CA file name (default ca.crt)\n";
		oss << "  -rpccertfile=<file.crt>               Server certificate file (default: server.crt)\n";
		oss << "  -rpcpkfile=<file.pem>                 Server private key (default: server.pem)\n";
		oss << "  -rpcciphers=<ciphers>                 Acceptable ciphers (default: TLSv1+HIGH:!SSLv2:!aNULL:!eNULL:!AH:!3DES:@STRENGTH)\n";
		oss << "  -statdata                             Enable statistical data or not (default false)\n";
		oss << "  -rpclog                               Enable write RPC log (default true)\n";
		return oss.str();
	}
	void AddOptionsImpl(boost::program_options::options_description& desc)
	{
		AddOpt(desc, "rpcport", nRPCPortInt, int(0));
		AddOpt(desc, "rpclisten", fRPCListen, bool(false));
		AddOpt(desc, "rpclisten4", fRPCListen4, bool(false));
		AddOpt(desc, "rpclisten6", fRPCListen6, bool(false));
		AddOpt(desc, "rpcuser", strRPCUser);
		AddOpt(desc, "rpcpassword", strRPCPass);
		AddOpt(desc, "rpcssl", fRPCSSLEnable, bool(false));
		AddOpt(desc, "rpcsslverify", fRPCSSLVerify, bool(false));
		AddOpt(desc, "rpccafile", strRPCCAFile, string(""));
		AddOpt(desc, "rpccertfile", strRPCCertFile, string(""));
		AddOpt(desc, "rpcpkfile", strRPCPKFile, string(""));
		AddOpt(desc, "rpcciphers", strRPCCiphers, string("TLSv1+HIGH:!SSLv2:!aNULL:!eNULL:!AH:!3DES:@STRENGTH"));
		AddOpt(desc, "statdata", fStatDataEnable, bool(false));
		AddOpt(desc, "rpclog", fRPCLogEnable, bool(true));
	}
	string ListConfigImpl() const
	{
		ostringstream oss;
		oss << " -rpcport: " << nRPCPortInt << "\n";
		oss << " -rpclisten: " << (fRPCListen ? "Y" : "N") << "\n";
		oss << " -rpclisten4: " << (fRPCListen4 ? "Y" : "N") << "\n";
		oss << " -rpclisten6: " << (fRPCListen6 ? "Y" : "N") << "\n";
		oss << " -rpcuser: " << strRPCUser << "\n";
		oss << " -rpcpassword: " << strRPCPass << "\n";
		oss << " -rpcssl: " << (fRPCSSLEnable ? "Y" : "N") << "\n";
		oss << " -rpcsslverify: " << (fRPCSSLVerify ? "Y" : "N") << "\n";
		oss << " -rpccafile: " << strRPCCAFile << "\n";
		oss << " -rpccertfile: " << strRPCCertFile << "\n";
		oss << " -rpcpkfile: " << strRPCPKFile << "\n";
		oss << " -rpcciphers: " << strRPCCiphers << "\n";
		oss << " -statdata: " << (fStatDataEnable ? "Y" : "N") << "\n";
		oss << " -rpclog: " << (fRPCLogEnable ? "Y" : "N") << "\n";
		return oss.str();
	}
};
class CRPCClientConfigOption
{
public:
	string strRPCConnect;
	unsigned int nRPCConnectTimeout;
protected:
protected:
	string HelpImpl() const
	{
		ostringstream oss;
		oss << "  -rpchost=<ip>                         Send commands to node running on <ip> (default: 127.0.0.1)\n";
		oss << "  -rpctimeout=<time>                    Connection timeout <time> seconds (default: 120)\n";
		return oss.str();
	}
	void AddOptionsImpl(boost::program_options::options_description& desc)
	{
		AddOpt(desc, "rpchost", strRPCConnect, string("127.0.0.1"));
		AddOpt(desc, "rpctimeout", nRPCConnectTimeout, (unsigned int)(DEFAULT_RPC_CONNECT_TIMEOUT));
	}
	string ListConfigImpl() const
	{
		ostringstream oss;
		oss << " -rpchost: " << strRPCConnect << "\n";
		oss << " -rpctimeout: " << nRPCConnectTimeout << "\n";
		return oss.str();
	}
};
class CRPCServerConfigOption
{
public:
	unsigned int nRPCMaxConnections;
	vector<string> vRPCAllowIP;
protected:
protected:
	string HelpImpl() const
	{
		ostringstream oss;
		oss << "  -rpcmaxconnections=<num>              Set max connections to <num> (default: 5)\n";
		oss << "  -rpcallowip=<ip>                      Allow JSON-RPC connections from specified <ip> address\n";
		return oss.str();
	}
	void AddOptionsImpl(boost::program_options::options_description& desc)
	{
		AddOpt(desc, "rpcmaxconnections", nRPCMaxConnections, (unsigned int)(DEFAULT_RPC_MAX_CONNECTIONS));
		AddOpt(desc, "rpcallowip", vRPCAllowIP);
	}
	string ListConfigImpl() const
	{
		ostringstream oss;
		oss << " -rpcmaxconnections: " << nRPCMaxConnections << "\n";
		oss << " -rpcallowip: ";
		for (auto& s: vRPCAllowIP)
		{
			oss << s << " ";
		}
		oss << "\n";
		return oss.str();
	}
};
class CStorageConfigOption
{
public:
	int nCheckLevel;
	int nCheckDepth;
	string strRecoveryDir;
protected:
protected:
	string HelpImpl() const
	{
		ostringstream oss;
		oss << "  -chklvl=<n>                           Set storage check level (default: 0, range=0-3)\n";
		oss << "  -chkdpth=<n>                          Set storage check depth (default: 1440, range=0-n)\n";
		oss << "  -recoverydir=<path>                   Set block data directory to recovery from it. It will clear all <-datadir> database except wallet address, so <-recoverydir> must be not equal <-datadir/block>\n";
		return oss.str();
	}
	void AddOptionsImpl(boost::program_options::options_description& desc)
	{
		AddOpt(desc, "chklvl", nCheckLevel, int(0));
		AddOpt(desc, "chkdpth", nCheckDepth, int(1440));
		AddOpt(desc, "recoverydir", strRecoveryDir, string(""));
	}
	string ListConfigImpl() const
	{
		ostringstream oss;
		oss << " -chklvl: " << nCheckLevel << "\n";
		oss << " -chkdpth: " << nCheckDepth << "\n";
		oss << " -recoverydir: " << strRecoveryDir << "\n";
		return oss.str();
	}
};
class CNetworkConfigOption
{
public:
	bool fListen;
	bool fListen4;
	bool fListen6;
	string strListenAddressv4;
	string strListenAddressv6;
	int nPortInt;
	string strGateWay;
	int nMaxConnection;
	unsigned int nConnectTimeout;
	vector<string> vNode;
	vector<string> vConnectTo;
	string strTrustAddress;
	vector<string> vDNSeed;
protected:
protected:
	string HelpImpl() const
	{
		ostringstream oss;
		oss << "  -listen                               Accept IPv4 and IPv6 connections from outside (default: 0)\n";
		oss << "  -listen4                              Accept IPv4 connections from outside (default: 0)\n";
		oss << "  -listen6                              Accept IPv6 connections from outside (default: 0)\n";
		oss << "  -listenaddressv4=<ip>                 listens for IPv4 addresses (default: 0.0.0.0)\n";
		oss << "  -listenaddressv6=<ip>                 listens for IPv6 addresses (default: ::)\n";
		oss << "  -port=<port>                          Listen for connections on <port> (default: 8801 or testnet: 8803)\n";
		oss << "  -gateway=<ip>:<port>                  The form of <ip>:<port> of address of gateway(<ip> can be IPv4 or IPv6, default <port>: 8801, IPv6 format: [ip]:port)\n";
		oss << "  -maxconnections=<n>                   Maintain at most <n> connections to peers (default: 125)\n";
		oss << "  -timeout=<n>                          Specify connection timeout (in milliseconds, 5 by default)\n";
		oss << "  -addnode=<address>:<port>             Add a node to connect to and attempt to keep the connection open(<address> can be IPv4 or IPv6 or domain name, default <port>: 8801, IPv6 format: [ip]:port)\n";
		oss << "  -connect=<address>:<port>             Connect only to the specified node(<address> can be IPv4 or IPv6 or domain name, default <port>: 8801, IPv6 format: [ip]:port)\n";
		oss << "  -confidentAddress=<address>           Trust node address(<address> can be IPv4 or IPv6)\n";
		oss << "  -dnseed=<address>:<port>              DNSeed address list(<address> can be IPv4 or IPv6 or domain name, default <port>: 9906, IPv6 format: [ip]:port)\n";
		return oss.str();
	}
	void AddOptionsImpl(boost::program_options::options_description& desc)
	{
		AddOpt(desc, "listen", fListen, bool(false));
		AddOpt(desc, "listen4", fListen4, bool(false));
		AddOpt(desc, "listen6", fListen6, bool(false));
		AddOpt(desc, "listenaddressv4", strListenAddressv4, string("0.0.0.0"));
		AddOpt(desc, "listenaddressv6", strListenAddressv6, string("::"));
		AddOpt(desc, "port", nPortInt, int(0));
		AddOpt(desc, "gateway", strGateWay);
		AddOpt(desc, "maxconnections", nMaxConnection, int(DEFAULT_MAX_OUTBOUNDS + DEFAULT_MAX_INBOUNDS));
		AddOpt(desc, "timeout", nConnectTimeout, (unsigned int)(DEFAULT_CONNECT_TIMEOUT));
		AddOpt(desc, "addnode", vNode);
		AddOpt(desc, "connect", vConnectTo);
		AddOpt(desc, "confidentAddress", strTrustAddress);
		AddOpt(desc, "dnseed", vDNSeed);
	}
	string ListConfigImpl() const
	{
		ostringstream oss;
		oss << " -listen: " << (fListen ? "Y" : "N") << "\n";
		oss << " -listen4: " << (fListen4 ? "Y" : "N") << "\n";
		oss << " -listen6: " << (fListen6 ? "Y" : "N") << "\n";
		oss << " -listenaddressv4: " << strListenAddressv4 << "\n";
		oss << " -listenaddressv6: " << strListenAddressv6 << "\n";
		oss << " -port: " << nPortInt << "\n";
		oss << " -gateway: " << strGateWay << "\n";
		oss << " -maxconnections: " << nMaxConnection << "\n";
		oss << " -timeout: " << nConnectTimeout << "\n";
		oss << " -addnode: ";
		for (auto& s: vNode)
		{
			oss << s << " ";
		}
		oss << "\n";
		oss << " -connect: ";
		for (auto& s: vConnectTo)
		{
			oss << s << " ";
		}
		oss << "\n";
		oss << " -confidentAddress: " << strTrustAddress << "\n";
		oss << " -dnseed: ";
		for (auto& s: vDNSeed)
		{
			oss << s << " ";
		}
		oss << "\n";
		return oss.str();
	}
};
} // namespace bigbang

#endif // BIGBANG_AUTO_OPTIONS_H
