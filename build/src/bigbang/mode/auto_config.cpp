// Copyright (c) 2019-2020 The Bigbang developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#include "auto_config.h"

#include <sstream>

#include "json/json_spirit_reader_template.h"

using namespace std;
using namespace bigbang::rpc;
using namespace json_spirit;

namespace bigbang
{

/////////////////////////////////////////////////////
// help

// CHelpConfig
CHelpConfig::CHelpConfig()
{
}
bool CHelpConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 2)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strCommand = *++it;
	}
	return true;
}
string CHelpConfig::ListConfig() const
{
	return "";
}
string CHelpConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        help (\"command\")\n";
	oss << "\n";
	oss << "List commands, or get help for a command.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"command\"                              (string, optional) command name\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"command\": \"\"                        (string, optional) command name\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"help\"                       (string, required) help info\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli help\n";
	oss << "\n>> mkf-cli help getpeercount\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "\tnone\n\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// stop

// CStopConfig
CStopConfig::CStopConfig()
{
}
bool CStopConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 1)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	return true;
}
string CStopConfig::ListConfig() const
{
	return "";
}
string CStopConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        stop\n";
	oss << "\n";
	oss << "Stop bigbang server.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << "\tnone\n\n";
	oss << "Request:\n";
	oss << " \"param\" : {}\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"result\"                     (string, required) stop result\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli stop\n";
	oss << "<< mkf server stopping\n";
	oss << "\n>> curl -d '{\"id\":1,\"method\":\"stop\",\"jsonrpc\":\"2.0\",\"params\":{}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":1,\"jsonrpc\":\"2.0\",\"result\":\"bigbang server stopping\"}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "\tnone\n\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// version

// CVersionConfig
CVersionConfig::CVersionConfig()
{
}
bool CVersionConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 1)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	return true;
}
string CVersionConfig::ListConfig() const
{
	return "";
}
string CVersionConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        version\n";
	oss << "\n";
	oss << "Get bigbang server version.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << "\tnone\n\n";
	oss << "Request:\n";
	oss << " \"param\" : {}\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"version\"                    (string, required) bigbang version\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli version\n";
	oss << "<< mkf server version is v0.1.0\n";
	oss << "\n>> curl -d '{\"id\":0,\"method\":\"version\",\"jsonrpc\":\"2.0\",\"params\":{}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":0,\"jsonrpc\":\"2.0\",\"result\":\"Bigbang server version is v0.1.0\"}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "\tnone\n\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// getpeercount

// CGetPeerCountConfig
CGetPeerCountConfig::CGetPeerCountConfig()
{
}
bool CGetPeerCountConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 1)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	return true;
}
string CGetPeerCountConfig::ListConfig() const
{
	return "";
}
string CGetPeerCountConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        getpeercount\n";
	oss << "\n";
	oss << "Return the number of connections to other nodes.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << "\tnone\n\n";
	oss << "Request:\n";
	oss << " \"param\" : {}\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": count                        (int, required) peer count\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli getpeercount\n";
	oss << "<< 0\n";
	oss << "\n>> curl -d '{\"id\":3,\"method\":\"getpeercount\",\"jsonrpc\":\"2.0\",\"params\":{}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":3,\"jsonrpc\":\"2.0\",\"result\":0}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "\tnone\n\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// listpeer

// CListPeerConfig
CListPeerConfig::CListPeerConfig()
{
}
bool CListPeerConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 1)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	return true;
}
string CListPeerConfig::ListConfig() const
{
	return "";
}
string CListPeerConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        listpeer\n";
	oss << "\n";
	oss << "Return data about each connected network node.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << "\tnone\n\n";
	oss << "Request:\n";
	oss << " \"param\" : {}\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\" :\n";
	oss << "   [\n";
	oss << "     \"peer\":                            (object, required) \n";
	oss << "     {\n";
	oss << "       \"address\": \"\",                   (string, required) peer address\n";
	oss << "       \"services\": \"\",                  (string, required) service\n";
	oss << "       \"lastsend\": \"\",                  (string, required) last send time(utc)\n";
	oss << "       \"lastrecv\": \"\",                  (string, required) last receive time(utc)\n";
	oss << "       \"conntime\": \"\",                  (string, required) active time(utc)\n";
	oss << "       \"pingtime\": 0,                   (int, required) ping pong time\n";
	oss << "       \"version\": \"\",                   (string, required) version\n";
	oss << "       \"subver\": \"\",                    (string, required) sub version\n";
	oss << "       \"inbound\": true|false,           (bool, required) accept multiple connection or not\n";
	oss << "       \"height\": 0,                     (int, required) starting height\n";
	oss << "       \"banscore\": 0                    (int, required) ban score\n";
	oss << "     }\n";
	oss << "   ]\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli listpeer\n";
	oss << "<< [{\"address\":\"113.105.146.22\",\"services\":\"NODE_NETWORK,NODE_DELEGATED\",\"lastsend\":\"2019-10-25 03:11:09\",\"lastrecv\":\"2019-10-25 03:11:09\",\"conntime\":\"2019-10-25 03:05:23\",\"version\":\"0.1.0\",\"subver\":\"/Bigbang:0.9.2/Protocol:0.1.0/9be9a865898c5cea90c716c17603cf3f0f185a5b\",\"inbound\":false,\"height\":31028,\"banscore\":true}]\n";
	oss << "\n>> curl -d '{\"id\":40,\"method\":\"listpeer\",\"jsonrpc\":\"2.0\",\"params\":{}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":40,\"jsonrpc\":\"2.0\",\"result\":[{\"address\":\"113.105.146.22\",\"services\":\"NODE_NETWORK,NODE_DELEGATED\",\"lastsend\":\"2019-10-25 03:11:09\",\"lastrecv\":\"2019-10-25 03:11:09\",\"conntime\":\"2019-10-25 03:05:23\",\"version\":\"0.1.0\",\"subver\":\"/Bigbang:0.9.2/Protocol:0.1.0/9be9a865898c5cea90c716c17603cf3f0f185a5b\",\"inbound\":false,\"height\":31028,\"banscore\":true}]}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "\tnone\n\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// addnode

// CAddNodeConfig
CAddNodeConfig::CAddNodeConfig()
{
}
bool CAddNodeConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 2)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strNode = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[node] is required");
	}
	return true;
}
string CAddNodeConfig::ListConfig() const
{
	return "";
}
string CAddNodeConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        addnode <\"node\">\n";
	oss << "\n";
	oss << "Attempt to add a node into the addnode list.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"node\"                                 (string, required) node host:port\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"node\": \"\"                           (string, required) node host:port\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"result\"                     (string, required) add node result\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli addnode 113.105.146.22\n";
	oss << "<< Add node successfully: 113.105.146.22\n";
	oss << "\n>> curl -d '{\"id\":3,\"method\":\"addnode\",\"jsonrpc\":\"2.0\",\"params\":{\"node\":\"113.105.146.22:8801\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":3,\"jsonrpc\":\"2.0\",\"result\":\"Add node successfully: 113.105.146.22:8801\"}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-206,\"message\":\"Failed to add node.\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// removenode

// CRemoveNodeConfig
CRemoveNodeConfig::CRemoveNodeConfig()
{
}
bool CRemoveNodeConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 2)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strNode = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[node] is required");
	}
	return true;
}
string CRemoveNodeConfig::ListConfig() const
{
	return "";
}
string CRemoveNodeConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        removenode <\"node\">\n";
	oss << "\n";
	oss << "Attempt to remove a node from the addnode list.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"node\"                                 (string, required) node host:port\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"node\": \"\"                           (string, required) node host:port\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"result\"                     (string, required) remove node result\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli removenode 113.105.146.22\n";
	oss << "<< Remove node successfully: 113.105.146.22\n";
	oss << "\n>> curl -d '{\"id\":67,\"method\":\"removenode\",\"jsonrpc\":\"2.0\",\"params\":{\"node\":\"113.105.146.22:8801\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":67,\"jsonrpc\":\"2.0\",\"result\":\"Remove node successfully: 113.105.146.22:8801\"}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-206,\"message\":\"Failed to remove node.\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// getforkcount

// CGetForkCountConfig
CGetForkCountConfig::CGetForkCountConfig()
{
}
bool CGetForkCountConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 1)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	return true;
}
string CGetForkCountConfig::ListConfig() const
{
	return "";
}
string CGetForkCountConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        getforkcount\n";
	oss << "\n";
	oss << "Return the number of forks.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << "\tnone\n\n";
	oss << "Request:\n";
	oss << " \"param\" : {}\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": count                        (int, required) fork count\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli getforkcount\n";
	oss << "<< 1\n";
	oss << "\n>> curl -d '{\"id\":69,\"method\":\"getforkcount\",\"jsonrpc\":\"2.0\",\"params\":{}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":69,\"jsonrpc\":\"2.0\",\"result\":1}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "\tnone\n\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// listfork

// CListForkConfig
CListForkConfig::CListForkConfig()
{
	boost::program_options::options_description desc("CListForkConfig");

	AddOpt<bool>(desc, "a");

	AddOptions(desc);
}
bool CListForkConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 2)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (vm.find("a") != vm.end())
	{
		auto value = vm["a"];
		fAll = value.as<bool>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			istringstream iss(*++it);
			iss >> boolalpha >> fAll;
			if (!iss.eof() || iss.fail())
				throw CRPCException(RPC_PARSE_ERROR, "[all] type error, needs bool");
		}
		else
		{
			fAll = false;
		}
	}
	return true;
}
string CListForkConfig::ListConfig() const
{
	return "";
}
string CListForkConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        listfork (-a|-noa*all*)\n";
	oss << "\n";
	oss << "If true, list of all forks, or subscribed forks\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " -a|-noa*all*                           (bool, optional, default=false) list all forks or not\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"all\": true|false                    (bool, optional, default=false) list all forks or not\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\" :\n";
	oss << "   [\n";
	oss << "     \"profile\":                         (object, required) fork profile info\n";
	oss << "     {\n";
	oss << "       \"fork\": \"\",                      (string, required) fork id with hex system\n";
	oss << "       \"name\": \"\",                      (string, required) fork name\n";
	oss << "       \"symbol\": \"\",                    (string, required) fork symbol\n";
	oss << "       \"amount\": 0.0,                   (double, required) amount\n";
	oss << "       \"reward\": 0.0,                   (double, required) mint reward\n";
	oss << "       \"halvecycle\": 0,                 (uint, required) halve cycle: 0: fixed reward, >0: blocks of halve cycle\n";
	oss << "       \"isolated\": true|false,          (bool, required) is isolated\n";
	oss << "       \"private\": true|false,           (bool, required) is private\n";
	oss << "       \"enclosed\": true|false,          (bool, required) is enclosed\n";
	oss << "       \"owner\": \"\"                      (string, required) owner's address\n";
	oss << "     }\n";
	oss << "   ]\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli listfork\n";
	oss << "<< [{\"fork\":\"a63d6f9d8055dc1bd7799593fb46ddc1b4e4519bd049e8eba1a0806917dcafc0\",\"name\":\"BigBang Network\",\"symbol\":\"BIG\",\"amount\":100000000.000000,\"reward\":15,\"halvecycle\":0,\"isolated\":true,\"private\":false,\"enclosed\":false,\"owner\":\"1mjw7aa0s7v9sv7x3thvcexxzjz4tq82j5qc12dy29ktqy84haa0j7dwb\"}]\n";
	oss << "\n>> {\"id\":69,\"method\":\"listfork\",\"jsonrpc\":\"2.0\",\"params\":{}}\n";
	oss << "<< {\"id\":69,\"jsonrpc\":\"2.0\",\"result\":[{\"fork\":\"a63d6f9d8055dc1bd7799593fb46ddc1b4e4519bd049e8eba1a0806917dcafc0\",\"name\":\"BigBang Network\",\"symbol\":\"BIG\",\"amount\":100000000.000000,\"reward\":15,\"halvecycle\":0,\"isolated\":true,\"private\":false,\"enclosed\":false,\"owner\":\"1mjw7aa0s7v9sv7x3thvcexxzjz4tq82j5qc12dy29ktqy84haa0j7dwb\"}]}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "\tnone\n\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// getgenealogy

// CGetGenealogyConfig
CGetGenealogyConfig::CGetGenealogyConfig()
{
	boost::program_options::options_description desc("CGetGenealogyConfig");

	AddOpt<string>(desc, "f");

	AddOptions(desc);
}
bool CGetGenealogyConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 2)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (vm.find("f") != vm.end())
	{
		auto value = vm["f"];
		strFork = value.as<string>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			strFork = *++it;
		}
	}
	return true;
}
string CGetGenealogyConfig::ListConfig() const
{
	return "";
}
string CGetGenealogyConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        getgenealogy (-f=\"fork\")\n";
	oss << "\n";
	oss << "Return the list of ancestry and subline.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " -f=\"fork\"                              (string, optional) fork hash\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"fork\": \"\"                           (string, optional) fork hash\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\" :\n";
	oss << " {\n";
	oss << "   [\n";
	oss << "     \"ancestry\":                        (object, required) ancestry\n";
	oss << "     {\n";
	oss << "       \"parent\": \"\",                    (string, required) parent fork hash\n";
	oss << "       \"height\": 0                      (int, required) parent origin height\n";
	oss << "     }\n";
	oss << "   ]\n";
	oss << "   [\n";
	oss << "     \"subline\":                         (object, required) subline\n";
	oss << "     {\n";
	oss << "       \"sub\": \"\",                       (string, required) sub fork hash\n";
	oss << "       \"height\": 0                      (int, required) sub origin height\n";
	oss << "     }\n";
	oss << "   ]\n";
	oss << " }\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli getgenealogy\n";
	oss << "<< {\"ancestry\":[],\"subline\":[]}\n";
	oss << "\n>> curl -d '{\"id\":75,\"method\":\"getgenealogy\",\"jsonrpc\":\"2.0\",\"params\":{}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":75,\"jsonrpc\":\"2.0\",\"result\":{\"ancestry\":[],\"subline\":[]}}\n";
	oss << "\n>> mkf-cli getgenealogy 1\n";
	oss << "<< {\"code\":-6,\"message\":\"Unknown fork\"}\n";
	oss << "\n>> curl -d '{\"id\":1,\"method\":\"getgenealogy\",\"jsonrpc\":\"2.0\",\"params\":{\"fork\":\"1\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":1,\"jsonrpc\":\"2.0\",\"error\":{\"code\":-6,\"message\":\"Unknown fork\"}}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid fork\"}\n";
	oss << "* {\"code\":-6,\"message\":\"Unknown fork\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// getblocklocation

// CGetBlockLocationConfig
CGetBlockLocationConfig::CGetBlockLocationConfig()
{
}
bool CGetBlockLocationConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 2)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strBlock = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[block] is required");
	}
	return true;
}
string CGetBlockLocationConfig::ListConfig() const
{
	return "";
}
string CGetBlockLocationConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        getblocklocation <\"block\">\n";
	oss << "\n";
	oss << "Return the location with given block.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"block\"                                (string, required) block hash\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"block\": \"\"                          (string, required) block hash\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\" :\n";
	oss << " {\n";
	oss << "   \"fork\": \"\",                          (string, required) fork hash\n";
	oss << "   \"height\": 0                          (int, required) block height\n";
	oss << " }\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli getblocklocation 609a797ca28042d562b11355038c516d65ba30b91c7033d83c61b81aa8c538e3\n";
	oss << "<< {\"fork\":\"a63d6f9d8055dc1bd7799593fb46ddc1b4e4519bd049e8eba1a0806917dcafc0\",\"height\":1}\n";
	oss << "\n>> curl -d '{\"id\":6,\"method\":\"getblocklocation\",\"jsonrpc\":\"2.0\",\"params\":{\"block\":\"609a797ca28042d562b11355038c516d65ba30b91c7033d83c61b81aa8c538e3\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":6,\"jsonrpc\":\"2.0\",\"result\":{\"fork\":\"a63d6f9d8055dc1bd7799593fb46ddc1b4e4519bd049e8eba1a0806917dcafc0\",\"height\":1}}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"Unknown block.\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// getblockcount

// CGetBlockCountConfig
CGetBlockCountConfig::CGetBlockCountConfig()
{
	boost::program_options::options_description desc("CGetBlockCountConfig");

	AddOpt<string>(desc, "f");

	AddOptions(desc);
}
bool CGetBlockCountConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 2)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (vm.find("f") != vm.end())
	{
		auto value = vm["f"];
		strFork = value.as<string>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			strFork = *++it;
		}
	}
	return true;
}
string CGetBlockCountConfig::ListConfig() const
{
	return "";
}
string CGetBlockCountConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        getblockcount (-f=\"fork\")\n";
	oss << "\n";
	oss << "Return the number of blocks in the given fork, includes extended block and vacant block\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " -f=\"fork\"                              (string, optional) fork hash\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"fork\": \"\"                           (string, optional) fork hash\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": count                        (int, required) block count\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli getblockcount\n";
	oss << "<< 32081\n";
	oss << "\n>> curl -d '{\"id\":4,\"method\":\"getblockcount\",\"jsonrpc\":\"2.0\",\"params\":{}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":4,\"jsonrpc\":\"2.0\",\"result\":32081}\n";
	oss << "\n>> mkf-cli getblockcount -f=a63d6f9d8055dc1bd7799593fb46ddc1b4e4519bd049e8eba1a0806917dcafc0\n";
	oss << "<< 32081\n";
	oss << "\n>> curl -d '{\"id\":5,\"method\":\"getblockcount\",\"jsonrpc\":\"2.0\",\"params\":{\"fork\":\"0\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":5,\"jsonrpc\":\"2.0\",\"result\":32081}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid fork\"}\n";
	oss << "* {\"code\":-6,\"message\":\"Unknown fork\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// getblockhash

// CGetBlockHashConfig
CGetBlockHashConfig::CGetBlockHashConfig()
{
	boost::program_options::options_description desc("CGetBlockHashConfig");

	AddOpt<string>(desc, "f");

	AddOptions(desc);
}
bool CGetBlockHashConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 3)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		istringstream iss(*++it);
		iss >> nHeight;
		if (!iss.eof() || iss.fail())
			throw CRPCException(RPC_PARSE_ERROR, "[height] type error, needs int");
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[height] is required");
	}
	if (vm.find("f") != vm.end())
	{
		auto value = vm["f"];
		strFork = value.as<string>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			strFork = *++it;
		}
	}
	return true;
}
string CGetBlockHashConfig::ListConfig() const
{
	return "";
}
string CGetBlockHashConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        getblockhash <height> (-f=\"fork\")\n";
	oss << "\n";
	oss << "Return a list of block hash in fork at specific height.\n"
	       "First of the list is the main block hash, others are extended blocks hash in order.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " height                                 (int, required) block height\n";
	oss << " -f=\"fork\"                              (string, optional) fork hash\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"height\": 0,                         (int, required) block height\n";
	oss << "   \"fork\": \"\"                           (string, optional) fork hash\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\" :\n";
	oss << "   [\n";
	oss << "     \"hash\": \"\"                         (string, required) one block hash\n";
	oss << "   ]\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli getblockhash 0\n";
	oss << "<< [\"a63d6f9d8055dc1bd7799593fb46ddc1b4e4519bd049e8eba1a0806917dcafc0\"]\n";
	oss << "\n>> curl -d '{\"id\":37,\"method\":\"getblockhash\",\"jsonrpc\":\"2.0\",\"params\":{\"height\":0}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":37,\"jsonrpc\":\"2.0\",\"result\":[\"a63d6f9d8055dc1bd7799593fb46ddc1b4e4519bd049e8eba1a0806917dcafc0\"]}\n";
	oss << "\n>> mkf-cli getblockhash 0 -f=a63d6f9d8055dc1bd7799593fb46ddc1b4e4519bd049e8eba1a0806917dcafc0\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid fork\"}\n";
	oss << "* {\"code\":-6,\"message\":\"Unknown fork\"}\n";
	oss << "* {\"code\":-6,\"message\":\"Block number out of range.\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// getblock

// CGetBlockConfig
CGetBlockConfig::CGetBlockConfig()
{
}
bool CGetBlockConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 2)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strBlock = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[block] is required");
	}
	return true;
}
string CGetBlockConfig::ListConfig() const
{
	return "";
}
string CGetBlockConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        getblock <\"block\">\n";
	oss << "\n";
	oss << "Return details of a block with given block-hash.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"block\"                                (string, required) block hash\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"block\": \"\"                          (string, required) block hash\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\" :\n";
	oss << " {\n";
	oss << "   \"hash\": \"\",                          (string, required) block hash\n";
	oss << "   \"hashPrev\": \"\",                      (string, required) block prev hash\n";
	oss << "   \"version\": 0,                        (uint, required) version\n";
	oss << "   \"type\": \"\",                          (string, required) block type\n";
	oss << "   \"time\": 0,                           (uint, required) block time\n";
	oss << "   \"fork\": \"\",                          (string, required) fork hash\n";
	oss << "   \"height\": 0,                         (uint, required) block height\n";
	oss << "   \"txmint\": \"\",                        (string, required) transaction mint hash\n";
	oss << "   [\n";
	oss << "     \"tx\": \"\"                           (string, required) transaction hash\n";
	oss << "   ]\n";
	oss << "   \"prev\": \"\"                           (string, optional) previous block hash\n";
	oss << " }\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli getblock ca49b8d07ac2849c455a813dd967bb0b306b48406d787259f4ddb8f6a0e0cf4c\n";
	oss << "<< {\"hash\":\"ca49b8d07ac2849c455a813dd967bb0b306b48406d787259f4ddb8f6a0e0cf4c\",\"version\":1,\"type\":\"primary-pow\",\"time\":1538138566,\"prev\":\"47b86e794e7ce0546def4fe3603d58d9cc9fc87eeee676bd15ae90e45ab51f8a\",\"fork\":\"a63d6f9d8055dc1bd7799593fb46ddc1b4e4519bd049e8eba1a0806917dcafc0\",\"height\":31296,\"txmint\":\"3d4ed629c594b924d72480e29a332ca91915be685c85940a8c501f8248269e29\",\"tx\":[]}\n";
	oss << "\n>> curl -d '{\"id\":10,\"method\":\"getblock\",\"jsonrpc\":\"2.0\",\"params\":{\"block\":\"ca49b8d07ac2849c455a813dd967bb0b306b48406d787259f4ddb8f6a0e0cf4c\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":10,\"jsonrpc\":\"2.0\",\"result\":{\"hash\":\"ca49b8d07ac2849c455a813dd967bb0b306b48406d787259f4ddb8f6a0e0cf4c\",\"version\":1,\"type\":\"primary-pow\",\"time\":1538138566,\"prev\":\"47b86e794e7ce0546def4fe3603d58d9cc9fc87eeee676bd15ae90e45ab51f8a\",\"fork\":\"a63d6f9d8055dc1bd7799593fb46ddc1b4e4519bd049e8eba1a0806917dcafc0\",\"height\":31296,\"txmint\":\"3d4ed629c594b924d72480e29a332ca91915be685c85940a8c501f8248269e29\",\"tx\":[]}}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"Unknown block.\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// getblockdetail

// CgetblockdetailConfig
CgetblockdetailConfig::CgetblockdetailConfig()
{
}
bool CgetblockdetailConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 2)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strBlock = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[block] is required");
	}
	return true;
}
string CgetblockdetailConfig::ListConfig() const
{
	return "";
}
string CgetblockdetailConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        getblockdetail <\"block\">\n";
	oss << "\n";
	oss << "Return details of a block with given block-hash.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"block\"                                (string, required) block hash\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"block\": \"\"                          (string, required) block hash\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\" :\n";
	oss << " {\n";
	oss << "   \"hash\": \"\",                          (string, required) block hash\n";
	oss << "   \"hashPrev\": \"\",                      (string, required) block prev hash\n";
	oss << "   \"version\": 0,                        (uint, required) version\n";
	oss << "   \"type\": \"\",                          (string, required) block type\n";
	oss << "   \"time\": 0,                           (uint, required) block time\n";
	oss << "   \"bits\": 0,                           (uint, required) nBits\n";
	oss << "   \"fork\": \"\",                          (string, required) fork hash\n";
	oss << "   \"height\": 0,                         (uint, required) block height\n";
	oss << "   \"txmint\":                            (object, required) transaction mint data\n";
	oss << "   {\n";
	oss << "     \"txid\": \"\",                        (string, required) transaction hash\n";
	oss << "     \"version\": 0,                      (uint, required) version\n";
	oss << "     \"type\": \"\",                        (string, required) transaction type\n";
	oss << "     \"time\": 0,                         (uint, required) transaction timestamp\n";
	oss << "     \"lockuntil\": 0,                    (uint, required) unlock time\n";
	oss << "     \"blockhash\": \"\",                   (string, required) which block tx located in\n";
	oss << "     [\n";
	oss << "       \"vin\":                           (object, required) vin struct\n";
	oss << "       {\n";
	oss << "         \"txid\": \"\",                    (string, required) pre-vout transaction hash\n";
	oss << "         \"vout\": 0                      (uint, required) pre-vout number\n";
	oss << "       }\n";
	oss << "     ]\n";
	oss << "     \"sendfrom\": \"\",                    (string, required) send from address\n";
	oss << "     \"sendto\": \"\",                      (string, required) send to address\n";
	oss << "     \"amount\": 0.0,                     (double, required) amount\n";
	oss << "     \"txfee\": 0.0,                      (double, required) transaction fee\n";
	oss << "     \"data\": \"\",                        (string, required) data\n";
	oss << "     \"sig\": \"\",                         (string, required) sign\n";
	oss << "     \"fork\": \"\",                        (string, required) fork hash\n";
	oss << "     \"confirmations\": 0                 (int, optional) confirmations\n";
	oss << "   }\n";
	oss << "   [\n";
	oss << "     \"tx\":                              (object, required) transaction data\n";
	oss << "     {\n";
	oss << "       \"txid\": \"\",                      (string, required) transaction hash\n";
	oss << "       \"version\": 0,                    (uint, required) version\n";
	oss << "       \"type\": \"\",                      (string, required) transaction type\n";
	oss << "       \"time\": 0,                       (uint, required) transaction timestamp\n";
	oss << "       \"lockuntil\": 0,                  (uint, required) unlock time\n";
	oss << "       \"blockhash\": \"\",                 (string, required) which block tx located in\n";
	oss << "       [\n";
	oss << "         \"vin\":                         (object, required) vin struct\n";
	oss << "         {\n";
	oss << "           \"txid\": \"\",                  (string, required) pre-vout transaction hash\n";
	oss << "           \"vout\": 0                    (uint, required) pre-vout number\n";
	oss << "         }\n";
	oss << "       ]\n";
	oss << "       \"sendfrom\": \"\",                  (string, required) send from address\n";
	oss << "       \"sendto\": \"\",                    (string, required) send to address\n";
	oss << "       \"amount\": 0.0,                   (double, required) amount\n";
	oss << "       \"txfee\": 0.0,                    (double, required) transaction fee\n";
	oss << "       \"data\": \"\",                      (string, required) data\n";
	oss << "       \"sig\": \"\",                       (string, required) sign\n";
	oss << "       \"fork\": \"\",                      (string, required) fork hash\n";
	oss << "       \"confirmations\": 0               (int, optional) confirmations\n";
	oss << "     }\n";
	oss << "   ]\n";
	oss << "   \"prev\": \"\"                           (string, optional) previous block hash\n";
	oss << " }\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli getblockdetail 0000497da49cf85b3f7faabe13716534b6dfd9e287b109356cb6bcb8c795f0d7\n";
	oss << "<< {\"hash\":\"0000497da49cf85b3f7faabe13716534b6dfd9e287b109356cb6bcb8c795f0d7\",\"hashPrev\":\"0000497c07f9b1309dd48aa729ef8cea91dd2610b9e93fe6d5a210d035a7d6f0\",\"version\":1,\"type\":\"primary-pow\",\"time\":1576134143,\"bits\":36,\"fork\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"height\":18813,\"txmint\":{\"txid\":\"5df1e5ffc3bea8bb3e86f822e5072aa2843242f1889f3cdc5559f7201569079a\",\"version\":1,\"type\":\"work\",\"time\":1576134143,\"lockuntil\":0,\"anchor\":\"0000497c07f9b1309dd48aa729ef8cea91dd2610b9e93fe6d5a210d035a7d6f0\",\"vin\":[],\"sendfrom\":\"000000000000000000000000000000000000000000000000000000000\",\"sendto\":\"20g075m4mh5trbkdy8vbh74n9h7t3npe7tewpnvsfb19p57jnyf3kdh45\",\"amount\":1153.000800,\"txfee\":0.000000,\"data\":\"\",\"sig\":\"\",\"fork\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"confirmations\":15},\"tx\":[{\"txid\":\"5df1e5eb943a31136951da3afb491d4d6f4e3aeba5cfca9c4ef5ca00c30920b8\",\"version\":1,\"type\":\"token\",\"time\":1576134123,\"lockuntil\":0,\"anchor\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"vin\":[{\"txid\":\"5df1e2d022709018117f93273ca192308776586916ba21ee7e513fe04fab9b2f\",\"vout\":0},{\"txid\":\"5df1dee3e78e4526f90d15cdcc8e96fedfe1103eca7065772f2ac2bc41d4ad8f\",\"vout\":1}],\"sendfrom\":\"20g07atym1beahmdk267hkqrgvhw1x0gj3bwth8q7yxcyfgcbszbpqgsr\",\"sendto\":\"1xjzjhz5w0an635wngt5qyx8xbg9x2vg0wzkz1a9hx5c97w0b9k0wbzjt\",\"amount\":499.999900,\"txfee\":0.000100,\"data\":\"\",\"sig\":\"64f1a77bd0e00f8023ffa2f7e0a76eb795414d9a57eb2f4ce5e9cc730c8103c501e1cbd24fa95312b81d2dc5ef6f60c39a9485819d4fa11bcfdde5f99151c8a4f99612f76c34f85b16bee2dd3c06e7cb876fb1ef7d6f7d2160de2d3fd9beb75c9b19e90ed9c46053ce81106e1e37717ad175489f30045180be1a2cc7ae524f790e\",\"fork\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"confirmations\":15},{\"txid\":\"5df1e5eb90ce47fceb3ace5e463f88db7ec98769e2a77571f5bc4b7e957aa69f\",\"version\":1,\"type\":\"token\",\"time\":1576134123,\"lockuntil\":0,\"anchor\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"vin\":[{\"txid\":\"5df1e5eb943a31136951da3afb491d4d6f4e3aeba5cfca9c4ef5ca00c30920b8\",\"vout\":1}],\"sendfrom\":\"20g07atym1beahmdk267hkqrgvhw1x0gj3bwth8q7yxcyfgcbszbpqgsr\",\"sendto\":\"1c23w26d19h6sntvktzfycpgwfge4efy3zghdjc93mnxbptdw7yqwbwgy\",\"amount\":499.999900,\"txfee\":0.000100,\"data\":\"\",\"sig\":\"64f1a77bd0e00f8023ffa2f7e0a76eb795414d9a57eb2f4ce5e9cc730c8103c501e1cbd24fa95312b81d2dc5ef6f60c39a9485819d4fa11bcfdde5f99151c8a4f9374f46f5caf72e9488a168a64c21744d3160b67d168376420945f9375dfda5a5967678db5f32e26ea17e990f9d00890ae0cc4b72ed0ed8a12f80c2aa6de40700\",\"fork\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"confirmations\":15},{\"txid\":\"5df1e5eb8208741b33a708a72a29a7380843789975e000dcc74eb31f857b691e\",\"version\":1,\"type\":\"token\",\"time\":1576134123,\"lockuntil\":0,\"anchor\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"vin\":[{\"txid\":\"5df1e1ea583124fa957a4c995cdea702bbdea2e832f8b0fe9a2d1d32578b8869\",\"vout\":0},{\"txid\":\"5df1e5eb90ce47fceb3ace5e463f88db7ec98769e2a77571f5bc4b7e957aa69f\",\"vout\":1}],\"sendfrom\":\"20g07atym1beahmdk267hkqrgvhw1x0gj3bwth8q7yxcyfgcbszbpqgsr\",\"sendto\":\"11nf1cnwft7f2yhr3qnbx9qxsc0b75y4gn7v1rd1qza8khzjdv7623gmm\",\"amount\":999.999900,\"txfee\":0.000100,\"data\":\"\",\"sig\":\"64f1a77bd0e00f8023ffa2f7e0a76eb795414d9a57eb2f4ce5e9cc730c8103c501e1cbd24fa95312b81d2dc5ef6f60c39a9485819d4fa11bcfdde5f99151c8a4f95b134de0889f32099b50f354d754b34b4cebdfab6eaa150f0de465967c020a3f140713591b1faf03d4112fa0924a796aca54be26fb8091ba472e8e0632e7c600\",\"fork\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"confirmations\":15},{\"txid\":\"5df1e5eb17690dbeae0609370f87c30b490eaf123500fdd55f961780415d5d22\",\"version\":1,\"type\":\"token\",\"time\":1576134123,\"lockuntil\":0,\"anchor\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"vin\":[{\"txid\":\"5df1e5eb8208741b33a708a72a29a7380843789975e000dcc74eb31f857b691e\",\"vout\":1}],\"sendfrom\":\"20g07atym1beahmdk267hkqrgvhw1x0gj3bwth8q7yxcyfgcbszbpqgsr\",\"sendto\":\"1eenpdhcyk5y3ma5pjzf3gp2drq344mc7vcdep170zmbafg5317ae044h\",\"amount\":499.999900,\"txfee\":0.000100,\"data\":\"\",\"sig\":\"64f1a77bd0e00f8023ffa2f7e0a76eb795414d9a57eb2f4ce5e9cc730c8103c501e1cbd24fa95312b81d2dc5ef6f60c39a9485819d4fa11bcfdde5f99151c8a4f977497144b8d4fc40250ecfc7e007d03f1d6293decd0bb115a0b5939a92314282edce494dde0b992e2b503a1f9f50ae00f6f8bc850fd4cbd5e32771f54bea470f\",\"fork\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"confirmations\":15},{\"txid\":\"5df1e5eb3000e640a2bea70acdc4f994fb05c8a36e54480e5cdc0ccc578f9cc0\",\"version\":1,\"type\":\"token\",\"time\":1576134123,\"lockuntil\":0,\"anchor\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"vin\":[{\"txid\":\"5df1e3e1bd39f2188ce116039c8af172b9a6b4a4ae464bef5734b496540d9db4\",\"vout\":0},{\"txid\":\"5df1e5eb17690dbeae0609370f87c30b490eaf123500fdd55f961780415d5d22\",\"vout\":1}],\"sendfrom\":\"20g07atym1beahmdk267hkqrgvhw1x0gj3bwth8q7yxcyfgcbszbpqgsr\",\"sendto\":\"1q6xgeqaa9hzy19qhhfpmg7hhee05bnq6ha7ph2kvb1d2w6b8qe8hffcy\",\"amount\":499.999900,\"txfee\":0.000100,\"data\":\"\",\"sig\":\"64f1a77bd0e00f8023ffa2f7e0a76eb795414d9a57eb2f4ce5e9cc730c8103c501e1cbd24fa95312b81d2dc5ef6f60c39a9485819d4fa11bcfdde5f99151c8a4f969d47d443711312df441072eca89c3cea44197bec0a7b709ad9d533684f051081c94ed71bea935a8f2eb224cf3a4cb6fa0c79e8925e68a6b8ff35a3fe196a80f\",\"fork\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"confirmations\":15},{\"txid\":\"5df1e5ebb45d6713d5048b73780a2e5e9e36a10c5b432bb409ff930b116ffef1\",\"version\":1,\"type\":\"token\",\"time\":1576134123,\"lockuntil\":0,\"anchor\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"vin\":[{\"txid\":\"5df1e5eb3000e640a2bea70acdc4f994fb05c8a36e54480e5cdc0ccc578f9cc0\",\"vout\":1}],\"sendfrom\":\"20g07atym1beahmdk267hkqrgvhw1x0gj3bwth8q7yxcyfgcbszbpqgsr\",\"sendto\":\"1mp11457nha6830emx3mkv4r2zvtg6aebsacdd72x8gzkpqrpvcn6ygd9\",\"amount\":499.999900,\"txfee\":0.000100,\"data\":\"\",\"sig\":\"64f1a77bd0e00f8023ffa2f7e0a76eb795414d9a57eb2f4ce5e9cc730c8103c501e1cbd24fa95312b81d2dc5ef6f60c39a9485819d4fa11bcfdde5f99151c8a4f9c517184e60c41bde9d504d48a02f815a6de60889175d0307b5810336d1c0eacc63978ff83338a5c7546c6e16d76336ac9c436f95cf9dc9e06928e3df80a7a00e\",\"fork\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"confirmations\":15},{\"txid\":\"5df1e5eb169ec81721b49ca9325b80afd950a685067aa003ae83b8d6d0d982b0\",\"version\":1,\"type\":\"token\",\"time\":1576134123,\"lockuntil\":0,\"anchor\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"vin\":[{\"txid\":\"5df1e337d09b7d286885cd69c0da98c7d04cf740221019d70bcbbb313a159d2a\",\"vout\":0},{\"txid\":\"5df1e5ebb45d6713d5048b73780a2e5e9e36a10c5b432bb409ff930b116ffef1\",\"vout\":1}],\"sendfrom\":\"20g07atym1beahmdk267hkqrgvhw1x0gj3bwth8q7yxcyfgcbszbpqgsr\",\"sendto\":\"1a2fse94fpjepygypmn7qwg8jv8jt2nybqdp2me317tn3t7qy20m9gqmt\",\"amount\":499.999900,\"txfee\":0.000100,\"data\":\"\",\"sig\":\"64f1a77bd0e00f8023ffa2f7e0a76eb795414d9a57eb2f4ce5e9cc730c8103c501e1cbd24fa95312b81d2dc5ef6f60c39a9485819d4fa11bcfdde5f99151c8a4f98b71bda06c23d650ed07d3a0c743689583df2c7f0c26be9c8a75b26e20d3cdafd2bfc6653ce519bd2164ae5f1301b65a220b1a7a34fb0676850f26fcf567c30e\",\"fork\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"confirmations\":15},{\"txid\":\"5df1e5ebf4b068ad6775a68cb27a95abea0ee058b1d7c356e46fa04e006b255e\",\"version\":1,\"type\":\"token\",\"time\":1576134123,\"lockuntil\":0,\"anchor\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"vin\":[{\"txid\":\"5df1e5eb169ec81721b49ca9325b80afd950a685067aa003ae83b8d6d0d982b0\",\"vout\":1}],\"sendfrom\":\"20g07atym1beahmdk267hkqrgvhw1x0gj3bwth8q7yxcyfgcbszbpqgsr\",\"sendto\":\"161pk1rj8qkxmbwfcw4131b9qmxqcby7975vhe81h6k3wczg8r7dw7xg2\",\"amount\":499.999900,\"txfee\":0.000100,\"data\":\"\",\"sig\":\"64f1a77bd0e00f8023ffa2f7e0a76eb795414d9a57eb2f4ce5e9cc730c8103c501e1cbd24fa95312b81d2dc5ef6f60c39a9485819d4fa11bcfdde5f99151c8a4f959d19b18b937ef40516e051d8e36a86d86291f2fb2f4db30ba465eb076154b294b0024ab95267f353f095053bd0160999eaeb902c7add7bf11f54ebce1166202\",\"fork\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"confirmations\":15}],\"prev\":\"0000497c07f9b1309dd48aa729ef8cea91dd2610b9e93fe6d5a210d035a7d6f0\"}\n";
	oss << "\n>> curl -d '{\"id\":10,\"method\":\"getblockdetail\",\"jsonrpc\":\"2.0\",\"params\":{\"block\":\"0000497da49cf85b3f7faabe13716534b6dfd9e287b109356cb6bcb8c795f0d7\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":10,\"jsonrpc\":\"2.0\",\"result\":{\"hash\":\"0000497da49cf85b3f7faabe13716534b6dfd9e287b109356cb6bcb8c795f0d7\",\"hashPrev\":\"0000497c07f9b1309dd48aa729ef8cea91dd2610b9e93fe6d5a210d035a7d6f0\",\"version\":1,\"type\":\"primary-pow\",\"time\":1576134143,\"bits\":36,\"fork\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"height\":18813,\"txmint\":{\"txid\":\"5df1e5ffc3bea8bb3e86f822e5072aa2843242f1889f3cdc5559f7201569079a\",\"version\":1,\"type\":\"work\",\"time\":1576134143,\"lockuntil\":0,\"anchor\":\"0000497c07f9b1309dd48aa729ef8cea91dd2610b9e93fe6d5a210d035a7d6f0\",\"vin\":[],\"sendfrom\":\"000000000000000000000000000000000000000000000000000000000\",\"sendto\":\"20g075m4mh5trbkdy8vbh74n9h7t3npe7tewpnvsfb19p57jnyf3kdh45\",\"amount\":1153.000800,\"txfee\":0.000000,\"data\":\"\",\"sig\":\"\",\"fork\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"confirmations\":63},\"tx\":[{\"txid\":\"5df1e5eb943a31136951da3afb491d4d6f4e3aeba5cfca9c4ef5ca00c30920b8\",\"version\":1,\"type\":\"token\",\"time\":1576134123,\"lockuntil\":0,\"anchor\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"vin\":[{\"txid\":\"5df1e2d022709018117f93273ca192308776586916ba21ee7e513fe04fab9b2f\",\"vout\":0},{\"txid\":\"5df1dee3e78e4526f90d15cdcc8e96fedfe1103eca7065772f2ac2bc41d4ad8f\",\"vout\":1}],\"sendfrom\":\"20g07atym1beahmdk267hkqrgvhw1x0gj3bwth8q7yxcyfgcbszbpqgsr\",\"sendto\":\"1xjzjhz5w0an635wngt5qyx8xbg9x2vg0wzkz1a9hx5c97w0b9k0wbzjt\",\"amount\":499.999900,\"txfee\":0.000100,\"data\":\"\",\"sig\":\"64f1a77bd0e00f8023ffa2f7e0a76eb795414d9a57eb2f4ce5e9cc730c8103c501e1cbd24fa95312b81d2dc5ef6f60c39a9485819d4fa11bcfdde5f99151c8a4f99612f76c34f85b16bee2dd3c06e7cb876fb1ef7d6f7d2160de2d3fd9beb75c9b19e90ed9c46053ce81106e1e37717ad175489f30045180be1a2cc7ae524f790e\",\"fork\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"confirmations\":63},{\"txid\":\"5df1e5eb90ce47fceb3ace5e463f88db7ec98769e2a77571f5bc4b7e957aa69f\",\"version\":1,\"type\":\"token\",\"time\":1576134123,\"lockuntil\":0,\"anchor\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"vin\":[{\"txid\":\"5df1e5eb943a31136951da3afb491d4d6f4e3aeba5cfca9c4ef5ca00c30920b8\",\"vout\":1}],\"sendfrom\":\"20g07atym1beahmdk267hkqrgvhw1x0gj3bwth8q7yxcyfgcbszbpqgsr\",\"sendto\":\"1c23w26d19h6sntvktzfycpgwfge4efy3zghdjc93mnxbptdw7yqwbwgy\",\"amount\":499.999900,\"txfee\":0.000100,\"data\":\"\",\"sig\":\"64f1a77bd0e00f8023ffa2f7e0a76eb795414d9a57eb2f4ce5e9cc730c8103c501e1cbd24fa95312b81d2dc5ef6f60c39a9485819d4fa11bcfdde5f99151c8a4f9374f46f5caf72e9488a168a64c21744d3160b67d168376420945f9375dfda5a5967678db5f32e26ea17e990f9d00890ae0cc4b72ed0ed8a12f80c2aa6de40700\",\"fork\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"confirmations\":63},{\"txid\":\"5df1e5eb8208741b33a708a72a29a7380843789975e000dcc74eb31f857b691e\",\"version\":1,\"type\":\"token\",\"time\":1576134123,\"lockuntil\":0,\"anchor\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"vin\":[{\"txid\":\"5df1e1ea583124fa957a4c995cdea702bbdea2e832f8b0fe9a2d1d32578b8869\",\"vout\":0},{\"txid\":\"5df1e5eb90ce47fceb3ace5e463f88db7ec98769e2a77571f5bc4b7e957aa69f\",\"vout\":1}],\"sendfrom\":\"20g07atym1beahmdk267hkqrgvhw1x0gj3bwth8q7yxcyfgcbszbpqgsr\",\"sendto\":\"11nf1cnwft7f2yhr3qnbx9qxsc0b75y4gn7v1rd1qza8khzjdv7623gmm\",\"amount\":999.999900,\"txfee\":0.000100,\"data\":\"\",\"sig\":\"64f1a77bd0e00f8023ffa2f7e0a76eb795414d9a57eb2f4ce5e9cc730c8103c501e1cbd24fa95312b81d2dc5ef6f60c39a9485819d4fa11bcfdde5f99151c8a4f95b134de0889f32099b50f354d754b34b4cebdfab6eaa150f0de465967c020a3f140713591b1faf03d4112fa0924a796aca54be26fb8091ba472e8e0632e7c600\",\"fork\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"confirmations\":63},{\"txid\":\"5df1e5eb17690dbeae0609370f87c30b490eaf123500fdd55f961780415d5d22\",\"version\":1,\"type\":\"token\",\"time\":1576134123,\"lockuntil\":0,\"anchor\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"vin\":[{\"txid\":\"5df1e5eb8208741b33a708a72a29a7380843789975e000dcc74eb31f857b691e\",\"vout\":1}],\"sendfrom\":\"20g07atym1beahmdk267hkqrgvhw1x0gj3bwth8q7yxcyfgcbszbpqgsr\",\"sendto\":\"1eenpdhcyk5y3ma5pjzf3gp2drq344mc7vcdep170zmbafg5317ae044h\",\"amount\":499.999900,\"txfee\":0.000100,\"data\":\"\",\"sig\":\"64f1a77bd0e00f8023ffa2f7e0a76eb795414d9a57eb2f4ce5e9cc730c8103c501e1cbd24fa95312b81d2dc5ef6f60c39a9485819d4fa11bcfdde5f99151c8a4f977497144b8d4fc40250ecfc7e007d03f1d6293decd0bb115a0b5939a92314282edce494dde0b992e2b503a1f9f50ae00f6f8bc850fd4cbd5e32771f54bea470f\",\"fork\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"confirmations\":63},{\"txid\":\"5df1e5eb3000e640a2bea70acdc4f994fb05c8a36e54480e5cdc0ccc578f9cc0\",\"version\":1,\"type\":\"token\",\"time\":1576134123,\"lockuntil\":0,\"anchor\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"vin\":[{\"txid\":\"5df1e3e1bd39f2188ce116039c8af172b9a6b4a4ae464bef5734b496540d9db4\",\"vout\":0},{\"txid\":\"5df1e5eb17690dbeae0609370f87c30b490eaf123500fdd55f961780415d5d22\",\"vout\":1}],\"sendfrom\":\"20g07atym1beahmdk267hkqrgvhw1x0gj3bwth8q7yxcyfgcbszbpqgsr\",\"sendto\":\"1q6xgeqaa9hzy19qhhfpmg7hhee05bnq6ha7ph2kvb1d2w6b8qe8hffcy\",\"amount\":499.999900,\"txfee\":0.000100,\"data\":\"\",\"sig\":\"64f1a77bd0e00f8023ffa2f7e0a76eb795414d9a57eb2f4ce5e9cc730c8103c501e1cbd24fa95312b81d2dc5ef6f60c39a9485819d4fa11bcfdde5f99151c8a4f969d47d443711312df441072eca89c3cea44197bec0a7b709ad9d533684f051081c94ed71bea935a8f2eb224cf3a4cb6fa0c79e8925e68a6b8ff35a3fe196a80f\",\"fork\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"confirmations\":63},{\"txid\":\"5df1e5ebb45d6713d5048b73780a2e5e9e36a10c5b432bb409ff930b116ffef1\",\"version\":1,\"type\":\"token\",\"time\":1576134123,\"lockuntil\":0,\"anchor\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"vin\":[{\"txid\":\"5df1e5eb3000e640a2bea70acdc4f994fb05c8a36e54480e5cdc0ccc578f9cc0\",\"vout\":1}],\"sendfrom\":\"20g07atym1beahmdk267hkqrgvhw1x0gj3bwth8q7yxcyfgcbszbpqgsr\",\"sendto\":\"1mp11457nha6830emx3mkv4r2zvtg6aebsacdd72x8gzkpqrpvcn6ygd9\",\"amount\":499.999900,\"txfee\":0.000100,\"data\":\"\",\"sig\":\"64f1a77bd0e00f8023ffa2f7e0a76eb795414d9a57eb2f4ce5e9cc730c8103c501e1cbd24fa95312b81d2dc5ef6f60c39a9485819d4fa11bcfdde5f99151c8a4f9c517184e60c41bde9d504d48a02f815a6de60889175d0307b5810336d1c0eacc63978ff83338a5c7546c6e16d76336ac9c436f95cf9dc9e06928e3df80a7a00e\",\"fork\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"confirmations\":63},{\"txid\":\"5df1e5eb169ec81721b49ca9325b80afd950a685067aa003ae83b8d6d0d982b0\",\"version\":1,\"type\":\"token\",\"time\":1576134123,\"lockuntil\":0,\"anchor\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"vin\":[{\"txid\":\"5df1e337d09b7d286885cd69c0da98c7d04cf740221019d70bcbbb313a159d2a\",\"vout\":0},{\"txid\":\"5df1e5ebb45d6713d5048b73780a2e5e9e36a10c5b432bb409ff930b116ffef1\",\"vout\":1}],\"sendfrom\":\"20g07atym1beahmdk267hkqrgvhw1x0gj3bwth8q7yxcyfgcbszbpqgsr\",\"sendto\":\"1a2fse94fpjepygypmn7qwg8jv8jt2nybqdp2me317tn3t7qy20m9gqmt\",\"amount\":499.999900,\"txfee\":0.000100,\"data\":\"\",\"sig\":\"64f1a77bd0e00f8023ffa2f7e0a76eb795414d9a57eb2f4ce5e9cc730c8103c501e1cbd24fa95312b81d2dc5ef6f60c39a9485819d4fa11bcfdde5f99151c8a4f98b71bda06c23d650ed07d3a0c743689583df2c7f0c26be9c8a75b26e20d3cdafd2bfc6653ce519bd2164ae5f1301b65a220b1a7a34fb0676850f26fcf567c30e\",\"fork\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"confirmations\":63},{\"txid\":\"5df1e5ebf4b068ad6775a68cb27a95abea0ee058b1d7c356e46fa04e006b255e\",\"version\":1,\"type\":\"token\",\"time\":1576134123,\"lockuntil\":0,\"anchor\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"vin\":[{\"txid\":\"5df1e5eb169ec81721b49ca9325b80afd950a685067aa003ae83b8d6d0d982b0\",\"vout\":1}],\"sendfrom\":\"20g07atym1beahmdk267hkqrgvhw1x0gj3bwth8q7yxcyfgcbszbpqgsr\",\"sendto\":\"161pk1rj8qkxmbwfcw4131b9qmxqcby7975vhe81h6k3wczg8r7dw7xg2\",\"amount\":499.999900,\"txfee\":0.000100,\"data\":\"\",\"sig\":\"64f1a77bd0e00f8023ffa2f7e0a76eb795414d9a57eb2f4ce5e9cc730c8103c501e1cbd24fa95312b81d2dc5ef6f60c39a9485819d4fa11bcfdde5f99151c8a4f959d19b18b937ef40516e051d8e36a86d86291f2fb2f4db30ba465eb076154b294b0024ab95267f353f095053bd0160999eaeb902c7add7bf11f54ebce1166202\",\"fork\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"confirmations\":63}],\"prev\":\"0000497c07f9b1309dd48aa729ef8cea91dd2610b9e93fe6d5a210d035a7d6f0\"}}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"Unknown block.\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// gettxpool

// CGetTxPoolConfig
CGetTxPoolConfig::CGetTxPoolConfig()
{
	boost::program_options::options_description desc("CGetTxPoolConfig");

	AddOpt<string>(desc, "f");
	AddOpt<bool>(desc, "d");

	AddOptions(desc);
}
bool CGetTxPoolConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 3)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (vm.find("f") != vm.end())
	{
		auto value = vm["f"];
		strFork = value.as<string>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			strFork = *++it;
		}
	}
	if (vm.find("d") != vm.end())
	{
		auto value = vm["d"];
		fDetail = value.as<bool>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			istringstream iss(*++it);
			iss >> boolalpha >> fDetail;
			if (!iss.eof() || iss.fail())
				throw CRPCException(RPC_PARSE_ERROR, "[detail] type error, needs bool");
		}
		else
		{
			fDetail = false;
		}
	}
	return true;
}
string CGetTxPoolConfig::ListConfig() const
{
	return "";
}
string CGetTxPoolConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        gettxpool (-f=\"fork\") (-d|-nod*detail*)\n";
	oss << "\n";
	oss << "If detail==0, return the count and total size of txs for given fork.\n"
	       "Otherwise,return all transaction ids and sizes in memory pool for given fork.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " -f=\"fork\"                              (string, optional) fork hash\n";
	oss << " -d|-nod*detail*                        (bool, optional, default=false) get detail or not\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"fork\": \"\",                          (string, optional) fork hash\n";
	oss << "   \"detail\": true|false                 (bool, optional, default=false) get detail or not\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\" :\n";
	oss << " {\n";
	oss << "   (if detail=false)\n";
	oss << "   \"count\": 0,                          (uint, optional) transaction pool count\n";
	oss << "   (if detail=false)\n";
	oss << "   \"size\": 0,                           (uint, optional) transaction total size\n";
	oss << "   (if detail=true)\n";
	oss << "   [\n";
	oss << "     \"pool\":                            (object, required) pool struct\n";
	oss << "     {\n";
	oss << "       \"hex\": \"\",                       (string, required) tx pool hex\n";
	oss << "       \"size\": 0                        (uint, required) tx pool size\n";
	oss << "     }\n";
	oss << "   ]\n";
	oss << " }\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli gettxpool\n";
	oss << "<< {\"count\":0,\"size\":0}\n";
	oss << "\n>> curl -d '{\"id\":11,\"method\":\"gettxpool\",\"jsonrpc\":\"2.0\",\"params\":{}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":11,\"jsonrpc\":\"2.0\",\"result\":{\"count\":0,\"size\":0}}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid fork\"}\n";
	oss << "* {\"code\":-6,\"message\":\"Unknown fork\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// gettransaction

// CGetTransactionConfig
CGetTransactionConfig::CGetTransactionConfig()
{
	boost::program_options::options_description desc("CGetTransactionConfig");

	AddOpt<bool>(desc, "s");

	AddOptions(desc);
}
bool CGetTransactionConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 3)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strTxid = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[txid] is required");
	}
	if (vm.find("s") != vm.end())
	{
		auto value = vm["s"];
		fSerialized = value.as<bool>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			istringstream iss(*++it);
			iss >> boolalpha >> fSerialized;
			if (!iss.eof() || iss.fail())
				throw CRPCException(RPC_PARSE_ERROR, "[serialized] type error, needs bool");
		}
		else
		{
			fSerialized = false;
		}
	}
	return true;
}
string CGetTransactionConfig::ListConfig() const
{
	return "";
}
string CGetTransactionConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        gettransaction <\"txid\"> (-s|-nos*serialized*)\n";
	oss << "\n";
	oss << "Get transaction information\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"txid\"                                 (string, required) transaction hash\n";
	oss << " -s|-nos*serialized*                    (bool, optional, default=false) If serialized=0, return an Object with information about <txid>.\n"
	       "                                        If serialized is non-zero, return a string that is\n"
	       "                                        serialized, hex-encoded data for <txid>.\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"txid\": \"\",                          (string, required) transaction hash\n";
	oss << "   \"serialized\": true|false             (bool, optional, default=false) If serialized=0, return an Object with information about <txid>.\n"
	       "                                        If serialized is non-zero, return a string that is\n"
	       "                                        serialized, hex-encoded data for <txid>.\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\" :\n";
	oss << " {\n";
	oss << "   (if serialized=true)\n";
	oss << "   \"serialization\": \"\",                 (string, optional) transaction hex data\n";
	oss << "   (if serialized=false)\n";
	oss << "   \"transaction\":                       (object, optional) transaction data\n";
	oss << "   {\n";
	oss << "     \"txid\": \"\",                        (string, required) transaction hash\n";
	oss << "     \"version\": 0,                      (uint, required) version\n";
	oss << "     \"type\": \"\",                        (string, required) transaction type\n";
	oss << "     \"time\": 0,                         (uint, required) transaction timestamp\n";
	oss << "     \"lockuntil\": 0,                    (uint, required) unlock time\n";
	oss << "     \"blockhash\": \"\",                   (string, required) which block tx located in\n";
	oss << "     [\n";
	oss << "       \"vin\":                           (object, required) vin struct\n";
	oss << "       {\n";
	oss << "         \"txid\": \"\",                    (string, required) pre-vout transaction hash\n";
	oss << "         \"vout\": 0                      (uint, required) pre-vout number\n";
	oss << "       }\n";
	oss << "     ]\n";
	oss << "     \"sendfrom\": \"\",                    (string, required) send from address\n";
	oss << "     \"sendto\": \"\",                      (string, required) send to address\n";
	oss << "     \"amount\": 0.0,                     (double, required) amount\n";
	oss << "     \"txfee\": 0.0,                      (double, required) transaction fee\n";
	oss << "     \"data\": \"\",                        (string, required) data\n";
	oss << "     \"sig\": \"\",                         (string, required) sign\n";
	oss << "     \"fork\": \"\",                        (string, required) fork hash\n";
	oss << "     \"confirmations\": 0                 (int, optional) confirmations\n";
	oss << "   }\n";
	oss << " }\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli gettransaction 5df09031322f99db08a4747d652e0733f60c9b523a6a489b5f72e0031a2b2a03\n";
	oss << "<< {\"transaction\":{\"txid\":\"5df09031322f99db08a4747d652e0733f60c9b523a6a489b5f72e0031a2b2a03\",\"version\":1,\"type\":\"token\",\"time\":1576046641,\"lockuntil\":0,\"anchor\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"vin\":[{\"txid\":\"5df088912a5a607904d8c69670a8b704c5739e847d2002c862f6b0cd712b797a\",\"vout\":0}],\"sendfrom\":\"1n56xmva8131c4q0961anv5wdzfqtdctyg9e53fxp65f1jyhbtkfbxz6q\",\"sendto\":\"1mkeeh3zeeejsvknz5d0bm78k81s585jbj5kf0rxjx3ah6ngh33b1erg9\",\"amount\":162.260000,\"txfee\":0.100000,\"data\":\"\",\"sig\":\"d6594d9215c58224f9707a84f773b00394561df0bba769a279dd065b98bc03a946928f8a6508a728eceff3e22d5181da16b78087c79b68532b31553bdc855000\",\"fork\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"confirmations\":1597}}\n";
	oss << "\n>> curl -d '{\"id\":13,\"method\":\"gettransaction\",\"jsonrpc\":\"2.0\",\"params\":{\"txid\":\"5df09031322f99db08a4747d652e0733f60c9b523a6a489b5f72e0031a2b2a03\",\"serialized\":false}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":13,\"jsonrpc\":\"2.0\",\"result\":{\"transaction\":{\"txid\":\"5df09031322f99db08a4747d652e0733f60c9b523a6a489b5f72e0031a2b2a03\",\"version\":1,\"type\":\"token\",\"time\":1576046641,\"lockuntil\":0,\"anchor\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"vin\":[{\"txid\":\"5df088912a5a607904d8c69670a8b704c5739e847d2002c862f6b0cd712b797a\",\"vout\":0}],\"sendfrom\":\"1n56xmva8131c4q0961anv5wdzfqtdctyg9e53fxp65f1jyhbtkfbxz6q\",\"sendto\":\"1mkeeh3zeeejsvknz5d0bm78k81s585jbj5kf0rxjx3ah6ngh33b1erg9\",\"amount\":162.260000,\"txfee\":0.100000,\"data\":\"\",\"sig\":\"d6594d9215c58224f9707a84f773b00394561df0bba769a279dd065b98bc03a946928f8a6508a728eceff3e22d5181da16b78087c79b68532b31553bdc855000\",\"fork\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"confirmations\":1631}}}\n";
	oss << "\n>> mkf-cli gettransaction -s 5df09031322f99db08a4747d652e0733f60c9b523a6a489b5f72e0031a2b2a03\n";
	oss << "<< {\"serialization\":\"010000003190f05d00000000701af4705c5e6fcb04efc3ca3c851c1e4d8948e10923025f54bea9b000000000017a792b71cdb0f662c802207d849e73c504b7a87096c6d80479605a2a9188f05d0001a4dce88fee73a59dcebf2b40ba1d13407254164b9166f063b2e8d513561118d620e4ab0900000000a0860100000000000040d6594d9215c58224f9707a84f773b00394561df0bba769a279dd065b98bc03a946928f8a6508a728eceff3e22d5181da16b78087c79b68532b31553bdc855000\"}\n";
	oss << "\n>> curl -d '{\"id\":13,\"method\":\"gettransaction\",\"jsonrpc\":\"2.0\",\"params\":{\"txid\":\"5df09031322f99db08a4747d652e0733f60c9b523a6a489b5f72e0031a2b2a03\",\"serialized\":true}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":13,\"jsonrpc\":\"2.0\",\"result\":{\"serialization\":\"010000003190f05d00000000701af4705c5e6fcb04efc3ca3c851c1e4d8948e10923025f54bea9b000000000017a792b71cdb0f662c802207d849e73c504b7a87096c6d80479605a2a9188f05d0001a4dce88fee73a59dcebf2b40ba1d13407254164b9166f063b2e8d513561118d620e4ab0900000000a0860100000000000040d6594d9215c58224f9707a84f773b00394561df0bba769a279dd065b98bc03a946928f8a6508a728eceff3e22d5181da16b78087c79b68532b31553bdc855000\"}}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"No information available about transaction.\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// sendtransaction

// CSendTransactionConfig
CSendTransactionConfig::CSendTransactionConfig()
{
}
bool CSendTransactionConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 2)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strTxdata = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[txdata] is required");
	}
	return true;
}
string CSendTransactionConfig::ListConfig() const
{
	return "";
}
string CSendTransactionConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        sendtransaction <\"txdata\">\n";
	oss << "\n";
	oss << "Submit raw transaction (serialized, hex-encoded) to local node and network.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"txdata\"                               (string, required) transaction binary data\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"txdata\": \"\"                         (string, required) transaction binary data\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"data\"                       (string, required) transaction raw data\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli sendtransaction 01000000000000002b747e24738befccff4a05c21dba749632cb8eb410233fa110e3f58a779b4325010ef45be50157453a57519929052d0818c269dee60be98958d5ab65bc7e0919810001b9c3b7aa16c6cb1bf193faf717580d03347148b2145ca98b30b1376d634c12f440420f0000000000a0860100000000000212348182e8a36441d116ce7a97f9a216d43a3dfc4280295874007b8ff5fd45eec9052e0182e8a36441d116ce7a97f9a216d43a3dfc4280295874007b8ff5fd45eec9052ed494d90cd96c252446b4a10459fea8c06186154b2bee2ce2182556e9ba40e7e69ddae2501862e4251bba2abf11c90d6f1fd0dec48a1419e81bb8c7d922cf3e03\n";
	oss << "<< 0a1b944071970589aa524a6f4e40e0b50bab9a64feefc292867692bbf35442a6\n";
	oss << "\n>> curl -d '{\"id\":9,\"method\":\"sendtransaction\",\"jsonrpc\":\"2.0\",\"params\":{\"txdata\":\"01000000000000002b747e24738befccff4a05c21dba749632cb8eb410233fa110e3f58a779b4325010ef45be50157453a57519929052d0818c269dee60be98958d5ab65bc7e0919810001b9c3b7aa16c6cb1bf193faf717580d03347148b2145ca98b30b1376d634c12f440420f0000000000a0860100000000000212348182e8a36441d116ce7a97f9a216d43a3dfc4280295874007b8ff5fd45eec9052e0182e8a36441d116ce7a97f9a216d43a3dfc4280295874007b8ff5fd45eec9052ed494d90cd96c252446b4a10459fea8c06186154b2bee2ce2182556e9ba40e7e69ddae2501862e4251bba2abf11c90d6f1fd0dec48a1419e81bb8c7d922cf3e03\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":9,\"jsonrpc\":\"2.0\",\"result\":\"0a1b944071970589aa524a6f4e40e0b50bab9a64feefc292867692bbf35442a6\"}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-8,\"message\":\"TX decode failed\"}\n";
	oss << "* {\"code\":-10,\"message\":\"Tx rejected : xxx\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// getforkheight

// CGetForkHeightConfig
CGetForkHeightConfig::CGetForkHeightConfig()
{
	boost::program_options::options_description desc("CGetForkHeightConfig");

	AddOpt<string>(desc, "f");

	AddOptions(desc);
}
bool CGetForkHeightConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 2)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (vm.find("f") != vm.end())
	{
		auto value = vm["f"];
		strFork = value.as<string>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			strFork = *++it;
		}
	}
	return true;
}
string CGetForkHeightConfig::ListConfig() const
{
	return "";
}
string CGetForkHeightConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        getforkheight (-f=\"fork\")\n";
	oss << "\n";
	oss << "Return the number of height in the given fork.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " -f=\"fork\"                              (string, optional) fork hash\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"fork\": \"\"                           (string, optional) fork hash\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": height                       (int, required) fork height\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli getforkheight\n";
	oss << "<< 32081\n";
	oss << "\n>> curl -d '{\"id\":4,\"method\":\"getforkheight\",\"jsonrpc\":\"2.0\",\"params\":{}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":4,\"jsonrpc\":\"2.0\",\"result\":32081}\n";
	oss << "\n>> mkf-cli getforkheight -f=a63d6f9d8055dc1bd7799593fb46ddc1b4e4519bd049e8eba1a0806917dcafc0\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid fork\"}\n";
	oss << "* {\"code\":-6,\"message\":\"Unknown fork\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// listkey

// CListKeyConfig
CListKeyConfig::CListKeyConfig()
{
}
bool CListKeyConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 1)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	return true;
}
string CListKeyConfig::ListConfig() const
{
	return "";
}
string CListKeyConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        listkey\n";
	oss << "\n";
	oss << "Return Object that has pubkey as keys, associated status as values.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << "\tnone\n\n";
	oss << "Request:\n";
	oss << " \"param\" : {}\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\" :\n";
	oss << "   [\n";
	oss << "     \"pubkey\":                          (object, required) public key info\n";
	oss << "     {\n";
	oss << "       \"key\": \"\",                       (string, required) public key with hex system\n";
	oss << "       \"version\": 0,                    (int, required) public key version\n";
	oss << "       \"public\": true|false,            (bool, required) is only public key or not in wallet\n";
	oss << "       \"locked\": true|false,            (bool, required) public key locked\n";
	oss << "       \"timeout\": 0                     (int, optional) public key timeout locked\n";
	oss << "     }\n";
	oss << "   ]\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli listkey\n";
	oss << "<< [{\"key\":\"3d266a564ec85f3385babf615b1d7eeb01b3e4456d35174732bb9ec0fa8c8f4f\",\"version\": 1,\"locked\": true},{\"key\":\"58e148d9e8610a6504c26ed346d15920c4d832cf0f03ecb8a016e0d0ec838b1b\",\"version\": 1,\"locked\": true}]\n";
	oss << "\n>> curl -d '{\"id\":43,\"method\":\"listkey\",\"jsonrpc\":\"2.0\",\"params\":{}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":43,\"jsonrpc\":\"2.0\",\"result\":[{\"key\":\"3d266a564ec85f3385babf615b1d7eeb01b3e4456d35174732bb9ec0fa8c8f4f\",\"version\": 1,\"locked\": true},{\"key\":\"58e148d9e8610a6504c26ed346d15920c4d832cf0f03ecb8a016e0d0ec838b1b\",\"version\": 1,\"locked\": true}]}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "\tnone\n\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// getnewkey

// CGetNewKeyConfig
CGetNewKeyConfig::CGetNewKeyConfig()
{
}
bool CGetNewKeyConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 2)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strPassphrase = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[passphrase] is required");
	}
	return true;
}
string CGetNewKeyConfig::ListConfig() const
{
	return "";
}
string CGetNewKeyConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        getnewkey <\"passphrase\">\n";
	oss << "\n";
	oss << "Return a new pubkey for receiving payments.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"passphrase\"                           (string, required) passphrase\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"passphrase\": \"\"                     (string, required) passphrase\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"pubkey\"                     (string, required) public key\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli getnewkey 123\n";
	oss << "<< f4124c636d37b1308ba95c14b2487134030d5817f7fa93f11bcbc616aab7c3b9\n";
	oss << "\n>> curl -d '{\"id\":7,\"method\":\"getnewkey\",\"jsonrpc\":\"2.0\",\"params\":{\"passphrase\":\"123\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":7,\"jsonrpc\":\"2.0\",\"result\":\"f4124c636d37b1308ba95c14b2487134030d5817f7fa93f11bcbc616aab7c3b9\"}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"Passphrase must be nonempty\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Failed add new key.\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// encryptkey

// CEncryptKeyConfig
CEncryptKeyConfig::CEncryptKeyConfig()
{
	boost::program_options::options_description desc("CEncryptKeyConfig");

	AddOpt<string>(desc, "new");
	AddOpt<string>(desc, "old");

	AddOptions(desc);
}
bool CEncryptKeyConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 4)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strPubkey = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[pubkey] is required");
	}
	if (vm.find("new") != vm.end())
	{
		auto value = vm["new"];
		strPassphrase = value.as<string>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			strPassphrase = *++it;
		}
		else
		{
			throw CRPCException(RPC_PARSE_ERROR, "[passphrase] is required");
		}
	}
	if (vm.find("old") != vm.end())
	{
		auto value = vm["old"];
		strOldpassphrase = value.as<string>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			strOldpassphrase = *++it;
		}
		else
		{
			throw CRPCException(RPC_PARSE_ERROR, "[oldpassphrase] is required");
		}
	}
	return true;
}
string CEncryptKeyConfig::ListConfig() const
{
	return "";
}
string CEncryptKeyConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        encryptkey <\"pubkey\"> <-new=\"passphrase\"> <-old=\"oldpassphrase\">\n";
	oss << "\n";
	oss << "Changes the passphrase for <oldpassphrase> to <passphrase>\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"pubkey\"                               (string, required) public key\n";
	oss << " -new=\"passphrase\"                      (string, required) passphrase of key\n";
	oss << " -old=\"oldpassphrase\"                   (string, required) old passphrase of key\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"pubkey\": \"\",                        (string, required) public key\n";
	oss << "   \"passphrase\": \"\",                    (string, required) passphrase of key\n";
	oss << "   \"oldpassphrase\": \"\"                  (string, required) old passphrase of key\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"result\"                     (string, required) encrypt key result\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> encryptkey f4c3babec11363be80e7b6aa1d803d63206a11f36fc99b874b63a262110a0add -new=456 -old=123\n";
	oss << "<< Encrypt key successfully: f4c3babec11363be80e7b6aa1d803d63206a11f36fc99b874b63a262110a0add\n";
	oss << "\n>> curl -d '{\"id\":5,\"method\":\"encryptkey\",\"jsonrpc\":\"2.0\",\"params\":{\"pubkey\":\"f4c3babec11363be80e7b6aa1d803d63206a11f36fc99b874b63a262110a0add\",\"passphrase\":\"456\",\"oldpassphrase\":\"123\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":5,\"jsonrpc\":\"2.0\",\"result\":\"Encrypt key successfully: f4c3babec11363be80e7b6aa1d803d63206a11f36fc99b874b63a262110a0add\"}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"Passphrase must be nonempty\"}\n";
	oss << "* {\"code\":-6,\"message\":\"Old passphrase must be nonempty\"}\n";
	oss << "* {\"code\":-4,\"message\":\"Unknown key\"}\n";
	oss << "* {\"code\":-406,\"message\":\"The passphrase entered was incorrect.\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// lockkey

// CLockKeyConfig
CLockKeyConfig::CLockKeyConfig()
{
}
bool CLockKeyConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 2)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strPubkey = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[pubkey] is required");
	}
	return true;
}
string CLockKeyConfig::ListConfig() const
{
	return "";
}
string CLockKeyConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        lockkey <\"pubkey\">\n";
	oss << "\n";
	oss << "Removes the encryption key from memory, locking the key.\n"
	       "After calling this method, you will need to call unlockkey again.\n"
	       "before being able to call any methods which require the key to be unlocked.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"pubkey\"                               (string, required) pubkey or pubkey address\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"pubkey\": \"\"                         (string, required) pubkey or pubkey address\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"result\"                     (string, required) lock key result\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli lockkey 2e05c9ee45fdf58f7b007458298042fc3d3ad416a2f9977ace16d14164a3e882\n";
	oss << "<< Lock key successfully: 2e05c9ee45fdf58f7b007458298042fc3d3ad416a2f9977ace16d14164a3e882\n";
	oss << "\n>> curl -d '{\"id\":1,\"method\":\"lockkey\",\"jsonrpc\":\"2.0\",\"params\":{\"pubkey\":\"2e05c9ee45fdf58f7b007458298042fc3d3ad416a2f9977ace16d14164a3e882\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":1,\"jsonrpc\":\"2.0\",\"result\":\"Lock key successfully: 2e05c9ee45fdf58f7b007458298042fc3d3ad416a2f9977ace16d14164a3e882\"}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-4,\"message\":\"Unknown key\"}\n";
	oss << "* {\"code\":-6,\"message\":\"This method only accepts pubkey or pubkey address as parameter rather than template address you supplied.\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Failed to lock key\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// unlockkey

// CUnlockKeyConfig
CUnlockKeyConfig::CUnlockKeyConfig()
{
	boost::program_options::options_description desc("CUnlockKeyConfig");

	AddOpt<int64>(desc, "t");

	AddOptions(desc);
}
bool CUnlockKeyConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 4)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strPubkey = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[pubkey] is required");
	}
	if (next(it, 1) != vecCommand.end())
	{
		strPassphrase = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[passphrase] is required");
	}
	if (vm.find("t") != vm.end())
	{
		auto value = vm["t"];
		nTimeout = value.as<int64>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			istringstream iss(*++it);
			iss >> nTimeout;
			if (!iss.eof() || iss.fail())
				throw CRPCException(RPC_PARSE_ERROR, "[timeout] type error, needs int");
		}
	}
	return true;
}
string CUnlockKeyConfig::ListConfig() const
{
	return "";
}
string CUnlockKeyConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        unlockkey <\"pubkey\"> <\"passphrase\"> (-t=timeout)\n";
	oss << "\n";
	oss << "If (timeout) > 0,stores the wallet decryption key in memory for (timeout) seconds.\n"
	       "before being able to call any methods which require the key to be locked.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"pubkey\"                               (string, required) pubkey or pubkey address\n";
	oss << " \"passphrase\"                           (string, required) passphrase\n";
	oss << " -t=timeout                             (int, optional) auto unlock timeout\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"pubkey\": \"\",                        (string, required) pubkey or pubkey address\n";
	oss << "   \"passphrase\": \"\",                    (string, required) passphrase\n";
	oss << "   \"timeout\": 0                         (int, optional) auto unlock timeout\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"result\"                     (string, required) unlock key result\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli unlockkey d716e72ce58e649a57d54751a7707e325b522497da3a69ae8301a2cbec391c07 1234\n";
	oss << "<< Unlock key successfully: d716e72ce58e649a57d54751a7707e325b522497da3a69ae8301a2cbec391c07\n";
	oss << "\n>> curl -d '{\"id\":13,\"method\":\"unlockkey\",\"jsonrpc\":\"2.0\",\"params\":{\"pubkey\":\"d716e72ce58e649a57d54751a7707e325b522497da3a69ae8301a2cbec391c07\",\"passphrase\":\"1234\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":13,\"jsonrpc\":\"2.0\",\"result\":\"Unlock key successfully: d716e72ce58e649a57d54751a7707e325b522497da3a69ae8301a2cbec391c07\"}\n";
	oss << "\n>> mkf-cli unlockkey f4124c636d37b1308ba95c14b2487134030d5817f7fa93f11bcbc616aab7c3b9 123 10\n";
	oss << "<< Unlock key successfully: f4124c636d37b1308ba95c14b2487134030d5817f7fa93f11bcbc616aab7c3b9\n";
	oss << "\n>> curl -d '{\"id\":15,\"method\":\"unlockkey\",\"jsonrpc\":\"2.0\",\"params\":{\"pubkey\":\"f4124c636d37b1308ba95c14b2487134030d5817f7fa93f11bcbc616aab7c3b9\",\"passphrase\":\"123\",\"timeout\":10}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":15,\"jsonrpc\":\"2.0\",\"result\":\"Unlock key successfully: f4124c636d37b1308ba95c14b2487134030d5817f7fa93f11bcbc616aab7c3b9\"}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"Passphrase must be nonempty\"}\n";
	oss << "* {\"code\":-4,\"message\":\"Unknown key\"}\n";
	oss << "* {\"code\":-409,\"message\":\"Key is already unlocked\"}\n";
	oss << "* {\"code\":-406,\"message\":\"The passphrase entered was incorrect.\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// importprivkey

// CImportPrivKeyConfig
CImportPrivKeyConfig::CImportPrivKeyConfig()
{
	boost::program_options::options_description desc("CImportPrivKeyConfig");

	AddOpt<bool>(desc, "s");

	AddOptions(desc);
}
bool CImportPrivKeyConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 4)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strPrivkey = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[privkey] is required");
	}
	if (next(it, 1) != vecCommand.end())
	{
		strPassphrase = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[passphrase] is required");
	}
	if (vm.find("s") != vm.end())
	{
		auto value = vm["s"];
		fSynctx = value.as<bool>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			istringstream iss(*++it);
			iss >> boolalpha >> fSynctx;
			if (!iss.eof() || iss.fail())
				throw CRPCException(RPC_PARSE_ERROR, "[synctx] type error, needs bool");
		}
		else
		{
			fSynctx = true;
		}
	}
	return true;
}
string CImportPrivKeyConfig::ListConfig() const
{
	return "";
}
string CImportPrivKeyConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        importprivkey <\"privkey\"> <\"passphrase\"> (-s|-nos*synctx*)\n";
	oss << "\n";
	oss << "Add a private key to your wallet.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"privkey\"                              (string, required) private key\n";
	oss << " \"passphrase\"                           (string, required) passphrase\n";
	oss << " -s|-nos*synctx*                        (bool, optional, default=true) sync tx or not\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"privkey\": \"\",                       (string, required) private key\n";
	oss << "   \"passphrase\": \"\",                    (string, required) passphrase\n";
	oss << "   \"synctx\": true|false                 (bool, optional, default=true) sync tx or not\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"pubkey\"                     (string, required) public key with hex number system\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli importprivkey feb51e048380c0ade1cdb60b25e9f3e05cd4507553a97faadc8a94771fcb1a5b 123\n";
	oss << "<< d716e72ce58e649a57d54751a7707e325b522497da3a69ae8301a2cbec391c07\n";
	oss << "\n>> curl -d '{\"id\":9,\"method\":\"importprivkey\",\"jsonrpc\":\"2.0\",\"params\":{\"privkey\":\"feb51e048380c0ade1cdb60b25e9f3e05cd4507553a97faadc8a94771fcb1a5b\",\"passphrase\":\"123\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":9,\"jsonrpc\":\"2.0\",\"result\":\"d716e72ce58e649a57d54751a7707e325b522497da3a69ae8301a2cbec391c07\"}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid private key\"}\n";
	oss << "* {\"code\":-6,\"message\":\"Passphrase must be nonempty\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Failed to add key\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Failed to sync wallet tx\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// importpubkey

// CImportPubKeyConfig
CImportPubKeyConfig::CImportPubKeyConfig()
{
}
bool CImportPubKeyConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 2)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strPubkey = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[pubkey] is required");
	}
	return true;
}
string CImportPubKeyConfig::ListConfig() const
{
	return "";
}
string CImportPubKeyConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        importpubkey <\"pubkey\">\n";
	oss << "\n";
	oss << "Add a public key to your wallet.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"pubkey\"                               (string, required) private key\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"pubkey\": \"\"                         (string, required) private key\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"address\"                    (string, required) address of public key\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli importpubkey 73f3b3d8545b60e58deb791c4da33089a40d7c6156a89e76e00ac0be2a9924d5\n";
	oss << "<< 1tmj9janyr05e0xmyn1b62z0dmj4k18td3hwyq3f5c1dn9p5kydsjpvrm\n";
	oss << "\n>> curl -d '{\"id\":31,\"method\":\"importpubkey\",\"jsonrpc\":\"2.0\",\"params\":{\"pubkey\":\"73f3b3d8545b60e58deb791c4da33089a40d7c6156a89e76e00ac0be2a9924d5\"}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":31,\"jsonrpc\":\"2.0\",\"result\":\"73f3b3d8545b60e58deb791c4da33089a40d7c6156a89e76e00ac0be2a9924d5\"}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"Template id is not allowed\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Failed to add key\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Failed to sync wallet tx\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// importkey

// CImportKeyConfig
CImportKeyConfig::CImportKeyConfig()
{
	boost::program_options::options_description desc("CImportKeyConfig");

	AddOpt<bool>(desc, "s");

	AddOptions(desc);
}
bool CImportKeyConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 3)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strPubkey = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[pubkey] is required");
	}
	if (vm.find("s") != vm.end())
	{
		auto value = vm["s"];
		fSynctx = value.as<bool>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			istringstream iss(*++it);
			iss >> boolalpha >> fSynctx;
			if (!iss.eof() || iss.fail())
				throw CRPCException(RPC_PARSE_ERROR, "[synctx] type error, needs bool");
		}
		else
		{
			fSynctx = true;
		}
	}
	return true;
}
string CImportKeyConfig::ListConfig() const
{
	return "";
}
string CImportKeyConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        importkey <\"pubkey\"> (-s|-nos*synctx*)\n";
	oss << "\n";
	oss << "Reveal the serialized key corresponding to <pubkey>.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"pubkey\"                               (string, required) public key data\n";
	oss << " -s|-nos*synctx*                        (bool, optional, default=true) sync tx or not\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"pubkey\": \"\",                        (string, required) public key data\n";
	oss << "   \"synctx\": true|false                 (bool, optional, default=true) sync tx or not\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"pubkey\"                     (string, required) public key with hex number system\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli importkey 642e19a647f9f2b795b8edf97c849ab1866855c9ac6b59d4cf2d9e63d23639de010000002f63a31bed90496a03bb58269e77b98751aa902be47ecbf9ac3adef221cbdcf6ecfba5a9c86e92323fb5af7a2df3f805caaf5dd80caf630e5eb206f0\n";
	oss << "<< de3936d2639e2dcfd4596bacc9556886b19a847cf9edb895b7f2f947a6192e64\n";
	oss << "\n>> curl -d '{\"id\":3,\"method\":\"importkey\",\"jsonrpc\":\"2.0\",\"params\":{\"pubkey\":\"642e19a647f9f2b795b8edf97c849ab1866855c9ac6b59d4cf2d9e63d23639de010000002f63a31bed90496a03bb58269e77b98751aa902be47ecbf9ac3adef221cbdcf6ecfba5a9c86e92323fb5af7a2df3f805caaf5dd80caf630e5eb206f0\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":3,\"jsonrpc\":\"2.0\",\"result\":\"de3936d2639e2dcfd4596bacc9556886b19a847cf9edb895b7f2f947a6192e64\"}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-32602,\"message\":\"Failed to verify serialized key\"}\n";
	oss << "* {\"code\":-32602,\"message\":\"Can't import the key with empty passphrase\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Failed to add key\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Failed to sync wallet tx\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// exportkey

// CExportKeyConfig
CExportKeyConfig::CExportKeyConfig()
{
}
bool CExportKeyConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 2)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strPubkey = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[pubkey] is required");
	}
	return true;
}
string CExportKeyConfig::ListConfig() const
{
	return "";
}
string CExportKeyConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        exportkey <\"pubkey\">\n";
	oss << "\n";
	oss << "Reveal the serialized key corresponding to <pubkey>.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"pubkey\"                               (string, required) public key\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"pubkey\": \"\"                         (string, required) public key\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"pubkey\"                     (string, required) public key with binary system\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli exportkey de3936d2639e2dcfd4596bacc9556886b19a847cf9edb895b7f2f947a6192e64\n";
	oss << "<< 642e19a647f9f2b795b8edf97c849ab1866855c9ac6b59d4cf2d9e63d23639de010000002f63a31bed90496a03bb58269e77b98751aa902be47ecbf9ac3adef221cbdcf6ecfba5a9c86e92323fb5af7a2df3f805caaf5dd80caf630e5eb206f0\n";
	oss << "\n>> curl -d '{\"id\":13,\"method\":\"exportkey\",\"jsonrpc\":\"2.0\",\"params\":{\"pubkey\":\"de3936d2639e2dcfd4596bacc9556886b19a847cf9edb895b7f2f947a6192e64\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":13,\"jsonrpc\":\"2.0\",\"result\":\"642e19a647f9f2b795b8edf97c849ab1866855c9ac6b59d4cf2d9e63d23639de010000002f63a31bed90496a03bb58269e77b98751aa902be47ecbf9ac3adef221cbdcf6ecfba5a9c86e92323fb5af7a2df3f805caaf5dd80caf630e5eb206f0\"}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-4,\"message\":\"Unknown key\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Failed to export key\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// addnewtemplate

// CAddNewTemplateConfig
CAddNewTemplateConfig::CAddNewTemplateConfig()
{
}
bool CAddNewTemplateConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 11)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		data.strType = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[type] is required");
	}
	if (data.strType == "delegate")
	{
		string strOriginDelegate;
		if (next(it, 1) != vecCommand.end())
		{
			strOriginDelegate = *++it;
		}
		else
		{
			throw CRPCException(RPC_PARSE_ERROR, "[delegate] is required");
		}
		Value valOriginDelegate;
		if (!read_string(strOriginDelegate, valOriginDelegate, RPC_MAX_DEPTH))
		{
			throw CRPCException(RPC_PARSE_ERROR, "parse json error");
		}
		data.delegate.FromJSON(valOriginDelegate);
	}
	if (data.strType == "vote")
	{
		string strOriginVote;
		if (next(it, 1) != vecCommand.end())
		{
			strOriginVote = *++it;
		}
		else
		{
			throw CRPCException(RPC_PARSE_ERROR, "[vote] is required");
		}
		Value valOriginVote;
		if (!read_string(strOriginVote, valOriginVote, RPC_MAX_DEPTH))
		{
			throw CRPCException(RPC_PARSE_ERROR, "parse json error");
		}
		data.vote.FromJSON(valOriginVote);
	}
	if (data.strType == "fork")
	{
		string strOriginFork;
		if (next(it, 1) != vecCommand.end())
		{
			strOriginFork = *++it;
		}
		else
		{
			throw CRPCException(RPC_PARSE_ERROR, "[fork] is required");
		}
		Value valOriginFork;
		if (!read_string(strOriginFork, valOriginFork, RPC_MAX_DEPTH))
		{
			throw CRPCException(RPC_PARSE_ERROR, "parse json error");
		}
		data.fork.FromJSON(valOriginFork);
	}
	if (data.strType == "mint")
	{
		string strOriginMint;
		if (next(it, 1) != vecCommand.end())
		{
			strOriginMint = *++it;
		}
		else
		{
			throw CRPCException(RPC_PARSE_ERROR, "[mint] is required");
		}
		Value valOriginMint;
		if (!read_string(strOriginMint, valOriginMint, RPC_MAX_DEPTH))
		{
			throw CRPCException(RPC_PARSE_ERROR, "parse json error");
		}
		data.mint.FromJSON(valOriginMint);
	}
	if (data.strType == "multisig")
	{
		string strOriginMultisig;
		if (next(it, 1) != vecCommand.end())
		{
			strOriginMultisig = *++it;
		}
		else
		{
			throw CRPCException(RPC_PARSE_ERROR, "[multisig] is required");
		}
		Value valOriginMultisig;
		if (!read_string(strOriginMultisig, valOriginMultisig, RPC_MAX_DEPTH))
		{
			throw CRPCException(RPC_PARSE_ERROR, "parse json error");
		}
		data.multisig.FromJSON(valOriginMultisig);
	}
	if (data.strType == "weighted")
	{
		string strOriginWeighted;
		if (next(it, 1) != vecCommand.end())
		{
			strOriginWeighted = *++it;
		}
		else
		{
			throw CRPCException(RPC_PARSE_ERROR, "[weighted] is required");
		}
		Value valOriginWeighted;
		if (!read_string(strOriginWeighted, valOriginWeighted, RPC_MAX_DEPTH))
		{
			throw CRPCException(RPC_PARSE_ERROR, "parse json error");
		}
		data.weighted.FromJSON(valOriginWeighted);
	}
	if (data.strType == "exchange")
	{
		string strOriginExchange;
		if (next(it, 1) != vecCommand.end())
		{
			strOriginExchange = *++it;
		}
		else
		{
			throw CRPCException(RPC_PARSE_ERROR, "[exchange] is required");
		}
		Value valOriginExchange;
		if (!read_string(strOriginExchange, valOriginExchange, RPC_MAX_DEPTH))
		{
			throw CRPCException(RPC_PARSE_ERROR, "parse json error");
		}
		data.exchange.FromJSON(valOriginExchange);
	}
	if (data.strType == "payment")
	{
		string strOriginPayment;
		if (next(it, 1) != vecCommand.end())
		{
			strOriginPayment = *++it;
		}
		else
		{
			throw CRPCException(RPC_PARSE_ERROR, "[payment] is required");
		}
		Value valOriginPayment;
		if (!read_string(strOriginPayment, valOriginPayment, RPC_MAX_DEPTH))
		{
			throw CRPCException(RPC_PARSE_ERROR, "parse json error");
		}
		data.payment.FromJSON(valOriginPayment);
	}
	if (next(it, 1) != vecCommand.end())
	{
		istringstream iss(*++it);
		iss >> boolalpha >> data.fSynctx;
		if (!iss.eof() || iss.fail())
			throw CRPCException(RPC_PARSE_ERROR, "[synctx] type error, needs bool");
	}
	else
	{
		data.fSynctx = true;
	}
	return true;
}
string CAddNewTemplateConfig::ListConfig() const
{
	return "";
}
string CAddNewTemplateConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        addnewtemplate <\"type\"> <{delegate}>|<{vote}>|<{fork}>|<{mint}>|<{multisig}>|<{weighted}>|<{exchange}>|<{payment}> (*synctx*)\n";
	oss << "\n";
	oss << "Return encoded address for the given template id.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"type\"                                 (string, required) template type\n";
	oss << "  (if type=delegate)\n";
	oss << " {delegate}                             (object, required) a delegate template\n";
	oss << "  (if type=vote)\n";
	oss << " {vote}                                 (object, required) a vote template\n";
	oss << "  (if type=fork)\n";
	oss << " {fork}                                 (object, required) a new fork template\n";
	oss << "  (if type=mint)\n";
	oss << " {mint}                                 (object, required) a mint template\n";
	oss << "  (if type=multisig)\n";
	oss << " {multisig}                             (object, required) a multiple sign template\n";
	oss << "  (if type=weighted)\n";
	oss << " {weighted}                             (object, required) a weighted multiple sign template\n";
	oss << "  (if type=exchange)\n";
	oss << " {exchange}                             (object, required) a exchange template\n";
	oss << "  (if type=payment)\n";
	oss << " {payment}                              (object, required) a payment template\n";
	oss << " *synctx*                               (bool, optional, default=true) sync tx or not\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"type\": \"\",                          (string, required) template type\n";
	oss << "   (if type=delegate)\n";
	oss << "   \"delegate\":                          (object, required) a delegate template\n";
	oss << "   {\n";
	oss << "     \"delegate\": \"\",                    (string, required) delegate public key\n";
	oss << "     \"owner\": \"\"                        (string, required) owner address\n";
	oss << "   }\n";
	oss << "   (if type=vote)\n";
	oss << "   \"vote\":                              (object, required) a vote template\n";
	oss << "   {\n";
	oss << "     \"delegate\": \"\",                    (string, required) delegate template address\n";
	oss << "     \"owner\": \"\"                        (string, required) owner address\n";
	oss << "   }\n";
	oss << "   (if type=fork)\n";
	oss << "   \"fork\":                              (object, required) a new fork template\n";
	oss << "   {\n";
	oss << "     \"redeem\": \"\",                      (string, required) redeem address\n";
	oss << "     \"fork\": \"\"                         (string, required) fork hash\n";
	oss << "   }\n";
	oss << "   (if type=mint)\n";
	oss << "   \"mint\":                              (object, required) a mint template\n";
	oss << "   {\n";
	oss << "     \"mint\": \"\",                        (string, required) mint public key\n";
	oss << "     \"spent\": \"\"                        (string, required) spent address\n";
	oss << "   }\n";
	oss << "   (if type=multisig)\n";
	oss << "   \"multisig\":                          (object, required) a multiple sign template\n";
	oss << "   {\n";
	oss << "     \"required\": 0,                     (int, required) required weight > 0\n";
	oss << "     [\n";
	oss << "       \"key\": \"\"                        (string, required) public key\n";
	oss << "     ]\n";
	oss << "   }\n";
	oss << "   (if type=weighted)\n";
	oss << "   \"weighted\":                          (object, required) a weighted multiple sign template\n";
	oss << "   {\n";
	oss << "     \"required\": 0,                     (int, required) required weight\n";
	oss << "     [\n";
	oss << "       \"pubkey\":                        (object, required) public key\n";
	oss << "       {\n";
	oss << "         \"key\": \"\",                     (string, required) public key\n";
	oss << "         \"weight\": 0                    (int, required) weight\n";
	oss << "       }\n";
	oss << "     ]\n";
	oss << "   }\n";
	oss << "   (if type=exchange)\n";
	oss << "   \"exchange\":                          (object, required) a exchange template\n";
	oss << "   {\n";
	oss << "     \"addr_m\": \"\",                      (string, required) addr_m\n";
	oss << "     \"addr_s\": \"\",                      (string, required) addr_s\n";
	oss << "     \"height_m\": 0,                     (int, required) height_m\n";
	oss << "     \"height_s\": 0,                     (int, required) height_s\n";
	oss << "     \"fork_m\": \"\",                      (string, required) fork_m hash\n";
	oss << "     \"fork_s\": \"\"                       (string, required) fork_s hash\n";
	oss << "   }\n";
	oss << "   (if type=payment)\n";
	oss << "   \"payment\":                           (object, required) a payment template\n";
	oss << "   {\n";
	oss << "     \"business\": \"\",                    (string, required) business\n";
	oss << "     \"customer\": \"\",                    (string, required) customer\n";
	oss << "     \"height_exec\": 0,                  (int, required) height_exec\n";
	oss << "     \"height_end\": 0,                   (int, required) height_end\n";
	oss << "     \"amount\": 0,                       (int, required) amount\n";
	oss << "     \"pledge\": 0                        (int, required) pledge\n";
	oss << "   }\n";
	oss << "   \"synctx\": true|false                 (bool, optional, default=true) sync tx or not\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"address\"                    (string, required) address of template\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli addnewtemplate mint '{\"mint\": \"e8e3770e774d5ad84a8ea65ed08cc7c5c30b42e045623604d5c5c6be95afb4f9\", \"spent\": \"1z6taz5dyrv2xa11pc92y0ggbrf2wf36gbtk8wjprb96qe3kqwfm3ayc1\"}'\n";
	oss << "<< 20g0b87qxcd52ceh9zmpzx0hy46pjfzdnqbkh8f4tqs4y0r6sxyzyny25\n";
	oss << "\n>> curl -d '{\"id\":1,\"method\":\"addnewtemplate\",\"jsonrpc\":\"2.0\",\"params\":{\"type\":\"mint\",\"mint\":{\"mint\":\"e8e3770e774d5ad84a8ea65ed08cc7c5c30b42e045623604d5c5c6be95afb4f9\",\"spent\":\"1z6taz5dyrv2xa11pc92y0ggbrf2wf36gbtk8wjprb96qe3kqwfm3ayc1\"}}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":1,\"jsonrpc\":\"2.0\",\"result\":\"20g0b87qxcd52ceh9zmpzx0hy46pjfzdnqbkh8f4tqs4y0r6sxyzyny25\"}\n";
	oss << "\n>> mkf-cli addnewtemplate delegate '{\"delegate\":\"2e05c9ee45fdf58f7b007458298042fc3d3ad416a2f9977ace16d14164a3e882\",\"owner\":\"1gbma6s21t4bcwymqz6h1dn1t7qy45019b1t00ywfyqymbvp90mqc1wmq\"}'\n";
	oss << "\n>> mkf-cli addnewtemplate fork '{\"redeem\":\"1gbma6s21t4bcwymqz6h1dn1t7qy45019b1t00ywfyqymbvp90mqc1wmq\",\"fork\":\"a63d6f9d8055dc1bd7799593fb46ddc1b4e4519bd049e8eba1a0806917dcafc0\"}'\n";
	oss << "\n>> mkf-cli addnewtemplate multisig '{\"required\": 1, \"pubkeys\": [\"2e05c9ee45fdf58f7b007458298042fc3d3ad416a2f9977ace16d14164a3e882\", \"f4124c636d37b1308ba95c14b2487134030d5817f7fa93f11bcbc616aab7c3b9\"]}'\n";
	oss << "\n>> mkf-cli addnewtemplate weighted '{\"required\": 1, \"pubkeys\": [{\"key\":\"2e05c9ee45fdf58f7b007458298042fc3d3ad416a2f9977ace16d14164a3e882\", \"weight\": 1},{\"key\": \"f4124c636d37b1308ba95c14b2487134030d5817f7fa93f11bcbc616aab7c3b9\", \"weight\": 2}]}'\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid parameters,failed to make template\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Failed to add template\"}\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid parameter, missing weight\"}\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid parameter, missing redeem address\"}\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid parameter, missing spent address\"}\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid parameter, missing owner address\"}\n";
	oss << "* {\"code\":-6,\"message\":\"template type error. type: xxx\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// importtemplate

// CImportTemplateConfig
CImportTemplateConfig::CImportTemplateConfig()
{
	boost::program_options::options_description desc("CImportTemplateConfig");

	AddOpt<bool>(desc, "s");

	AddOptions(desc);
}
bool CImportTemplateConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 3)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strData = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[data] is required");
	}
	if (vm.find("s") != vm.end())
	{
		auto value = vm["s"];
		fSynctx = value.as<bool>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			istringstream iss(*++it);
			iss >> boolalpha >> fSynctx;
			if (!iss.eof() || iss.fail())
				throw CRPCException(RPC_PARSE_ERROR, "[synctx] type error, needs bool");
		}
		else
		{
			fSynctx = true;
		}
	}
	return true;
}
string CImportTemplateConfig::ListConfig() const
{
	return "";
}
string CImportTemplateConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        importtemplate <\"data\"> (-s|-nos*synctx*)\n";
	oss << "\n";
	oss << "Return encoded address for the given template.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"data\"                                 (string, required) template data\n";
	oss << " -s|-nos*synctx*                        (bool, optional, default=true) sync tx or not\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"data\": \"\",                          (string, required) template data\n";
	oss << "   \"synctx\": true|false                 (bool, optional, default=true) sync tx or not\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"address\"                    (string, required) address of template\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli importtemplate 0100010282e8a36441d116ce7a97f9a216d43a3dfc4280295874007b8ff5fd45eec9052e01b9c3b7aa16c6cb1bf193faf717580d03347148b2145ca98b30b1376d634c12f402\n";
	oss << "<< 21w2040000000000000000000000000000000000000000000000epcek\n";
	oss << "\n>> curl -d '{\"id\":52,\"method\":\"importtemplate\",\"jsonrpc\":\"2.0\",\"params\":{\"data\":\"0100010282e8a36441d116ce7a97f9a216d43a3dfc4280295874007b8ff5fd45eec9052e01b9c3b7aa16c6cb1bf193faf717580d03347148b2145ca98b30b1376d634c12f402\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":52,\"jsonrpc\":\"2.0\",\"result\":\"21w2040000000000000000000000000000000000000000000000epcek\"}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid parameters,failed to make template\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Failed to add template\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Failed to sync wallet tx\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// exporttemplate

// CExportTemplateConfig
CExportTemplateConfig::CExportTemplateConfig()
{
}
bool CExportTemplateConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 2)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strAddress = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[address] is required");
	}
	return true;
}
string CExportTemplateConfig::ListConfig() const
{
	return "";
}
string CExportTemplateConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        exporttemplate <\"address\">\n";
	oss << "\n";
	oss << "Return encoded address for the given template.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"address\"                              (string, required) template address\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"address\": \"\"                        (string, required) template address\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"data\"                       (string, required) data of template\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli exporttemplate 2040fpytdr4k5h8tk0nferr7zb51tkccrkgqf341s6tg05q9xe6hth1m\n";
	oss << "<< 0100010282e8a36441d116ce7a97f9a216d43a3dfc4280295874007b8ff5fd45eec9052e01b9c3b7aa16c6cb1bf193faf717580d03347148b2145ca98b30b1376d634c12f402\n";
	oss << "\n>> curl -d '{\"id\":25,\"method\":\"exporttemplate\",\"jsonrpc\":\"2.0\",\"params\":{\"address\":\"2040fpytdr4k5h8tk0nferr7zb51tkccrkgqf341s6tg05q9xe6hth1m4\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":25,\"jsonrpc\":\"2.0\",\"result\":\"0100010282e8a36441d116ce7a97f9a216d43a3dfc4280295874007b8ff5fd45eec9052e01b9c3b7aa16c6cb1bf193faf717580d03347148b2145ca98b30b1376d634c12f402\"}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid address\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Unkown template\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// validateaddress

// CValidateAddressConfig
CValidateAddressConfig::CValidateAddressConfig()
{
}
bool CValidateAddressConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 2)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strAddress = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[address] is required");
	}
	return true;
}
string CValidateAddressConfig::ListConfig() const
{
	return "";
}
string CValidateAddressConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        validateaddress <\"address\">\n";
	oss << "\n";
	oss << "Return information about <address>.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"address\"                              (string, required) wallet address\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"address\": \"\"                        (string, required) wallet address\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\" :\n";
	oss << " {\n";
	oss << "   \"isvalid\": true|false,               (bool, required) is valid\n";
	oss << "   (if isvalid=true)\n";
	oss << "   \"addressdata\":                       (object, required) address data\n";
	oss << "   {\n";
	oss << "     \"address\": \"\",                     (string, required) wallet address\n";
	oss << "     \"ismine\": true|false,              (bool, required) is mine\n";
	oss << "     \"type\": \"\",                        (string, required) type, pubkey or template\n";
	oss << "     (if type=pubkey)\n";
	oss << "     \"pubkey\": \"\",                      (string, required) public key\n";
	oss << "     (if type=template)\n";
	oss << "     \"template\": \"\",                    (string, required) template type name\n";
	oss << "     (if type=template && ismine=true)\n";
	oss << "     \"templatedata\":                    (object, required) template data\n";
	oss << "     {\n";
	oss << "       \"type\": \"\",                      (string, required) template type\n";
	oss << "       \"hex\": \"\",                       (string, required) temtplate data\n";
	oss << "       (if type=delegate)\n";
	oss << "       \"delegate\":                      (object, required) delegate template struct\n";
	oss << "       {\n";
	oss << "         \"delegate\": \"\",                (string, required) delegate public key\n";
	oss << "         \"owner\": \"\"                    (string, required) owner address\n";
	oss << "       }\n";
	oss << "       (if type=vote)\n";
	oss << "       \"vote\":                          (object, required) vote template struct\n";
	oss << "       {\n";
	oss << "         \"delegate\": \"\",                (string, required) delegate template address\n";
	oss << "         \"owner\": \"\"                    (string, required) owner address\n";
	oss << "       }\n";
	oss << "       (if type=fork)\n";
	oss << "       \"fork\":                          (object, required) fork template struct\n";
	oss << "       {\n";
	oss << "         \"redeem\": \"\",                  (string, required) redeem address\n";
	oss << "         \"fork\": \"\"                     (string, required) fork hash\n";
	oss << "       }\n";
	oss << "       (if type=mint)\n";
	oss << "       \"mint\":                          (object, required) mint template struct\n";
	oss << "       {\n";
	oss << "         \"mint\": \"\",                    (string, required) mint public key\n";
	oss << "         \"spent\": \"\"                    (string, required) spent address\n";
	oss << "       }\n";
	oss << "       (if type=multisig)\n";
	oss << "       \"multisig\":                      (object, required) multisig template struct\n";
	oss << "       {\n";
	oss << "         \"required\": 0,                 (int, required) required weight\n";
	oss << "         [\n";
	oss << "           \"key\": \"\"                    (string, required) public key\n";
	oss << "         ]\n";
	oss << "       }\n";
	oss << "       (if type=exchange)\n";
	oss << "       \"exchange\":                      (object, required) exchange template struct\n";
	oss << "       {\n";
	oss << "         \"spend_m\": \"\",                 (string, required) spend_m\n";
	oss << "         \"spend_s\": \"\",                 (string, required) spend_s\n";
	oss << "         \"height_m\": 0,                 (int, required) height m\n";
	oss << "         \"height_s\": 0,                 (int, required) height s\n";
	oss << "         \"fork_m\": \"\",                  (string, required) fork m\n";
	oss << "         \"fork_s\": \"\"                   (string, required) fork s\n";
	oss << "       }\n";
	oss << "       (if type=payment)\n";
	oss << "       \"payment\":                       (object, required) a payment template\n";
	oss << "       {\n";
	oss << "         \"business\": \"\",                (string, required) business\n";
	oss << "         \"customer\": \"\",                (string, required) customer\n";
	oss << "         \"height_exec\": 0,              (int, required) height_exec\n";
	oss << "         \"height_end\": 0,               (int, required) height_end\n";
	oss << "         \"amount\": 0,                   (int, required) amount\n";
	oss << "         \"pledge\": 0                    (int, required) pledge\n";
	oss << "       }\n";
	oss << "       (if type=weighted)\n";
	oss << "       \"weighted\":                      (object, required) weighted template struct\n";
	oss << "       {\n";
	oss << "         \"required\": 0,                 (int, required) required weight\n";
	oss << "         [\n";
	oss << "           \"pubkey\":                    (object, required) public key\n";
	oss << "           {\n";
	oss << "             \"key\": \"\",                 (string, required) public key\n";
	oss << "             \"weight\": 0                (int, required) weight\n";
	oss << "           }\n";
	oss << "         ]\n";
	oss << "       }\n";
	oss << "     }\n";
	oss << "   }\n";
	oss << " }\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli validateaddress 20g0753dp5b817d7v0hbag6a4neetzfdgbcyt2pkx93hrzn97epzbyn26\n";
	oss << "<< {\"isvalid\":true,\"addressdata\":{\"address\":\"20g0753dp5b817d7v0hbag6a4neetzfdgbcyt2pkx93hrzn97epzbyn26\",\"ismine\":true,\"type\":\"template\",\"template\":\"mint\"}}\n";
	oss << "\n>> curl -d '{\"id\":2,\"method\":\"validateaddress\",\"jsonrpc\":\"2.0\",\"params\":{\"address\":\"20g0753dp5b817d7v0hbag6a4neetzfdgbcyt2pkx93hrzn97epzbyn26\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":2,\"jsonrpc\":\"2.0\",\"result\":{\"isvalid\":true,\"addressdata\":{\"address\":\"20g0753dp5b817d7v0hbag6a4neetzfdgbcyt2pkx93hrzn97epzbyn26\",\"ismine\":true,\"type\":\"template\",\"template\":\"mint\"}}}\n";
	oss << "\n>> mkf-cli validateaddress 123\n";
	oss << "<< {\"isvalid\":false}\n";
	oss << "\n>> curl -d '{\"id\":3,\"method\":\"validateaddress\",\"jsonrpc\":\"2.0\",\"params\":{\"address\":\"123\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":3,\"jsonrpc\":\"2.0\",\"result\":{\"isvalid\":false}}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "\tnone\n\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// resyncwallet

// CResyncWalletConfig
CResyncWalletConfig::CResyncWalletConfig()
{
}
bool CResyncWalletConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 2)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strAddress = *++it;
	}
	return true;
}
string CResyncWalletConfig::ListConfig() const
{
	return "";
}
string CResyncWalletConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        resyncwallet (\"address\")\n";
	oss << "\n";
	oss << "If (address) is not specified, resync wallet's tx for each address.\n"
	       "If (address) is specified, resync wallet's tx for the address.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"address\"                              (string, optional) tx address\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"address\": \"\"                        (string, optional) tx address\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"result\"                     (string, required) resync wallet result\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli resyncwallet\n";
	oss << "<< Resync wallet successfully.\n";
	oss << "\n>> curl -d '{\"id\":38,\"method\":\"resyncwallet\",\"jsonrpc\":\"2.0\",\"params\":{}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":38,\"jsonrpc\":\"2.0\",\"result\":\"Resync wallet successfully.\"}\n";
	oss << "\n>> mkf-cli resyncwallet 1gbma6s21t4bcwymqz6h1dn1t7qy45019b1t00ywfyqymbvp90mqc1wmq\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid address\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Failed to resync wallet tx\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// getbalance

// CGetBalanceConfig
CGetBalanceConfig::CGetBalanceConfig()
{
	boost::program_options::options_description desc("CGetBalanceConfig");

	AddOpt<string>(desc, "f");
	AddOpt<string>(desc, "a");

	AddOptions(desc);
}
bool CGetBalanceConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 3)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (vm.find("f") != vm.end())
	{
		auto value = vm["f"];
		strFork = value.as<string>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			strFork = *++it;
		}
	}
	if (vm.find("a") != vm.end())
	{
		auto value = vm["a"];
		strAddress = value.as<string>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			strAddress = *++it;
		}
	}
	return true;
}
string CGetBalanceConfig::ListConfig() const
{
	return "";
}
string CGetBalanceConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        getbalance (-f=\"fork\") (-a=\"address\")\n";
	oss << "\n";
	oss << "Get balance of address.\n"
	       "If (address) is not specified, return the balance for wallet's each address.\n"
	       "If (address) is specified, return the balance in the address.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " -f=\"fork\"                              (string, optional) fork hash\n";
	oss << " -a=\"address\"                           (string, optional) wallet address\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"fork\": \"\",                          (string, optional) fork hash\n";
	oss << "   \"address\": \"\"                        (string, optional) wallet address\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\" :\n";
	oss << "   [\n";
	oss << "     \"balance\":                         (object, required) balance info\n";
	oss << "     {\n";
	oss << "       \"address\": \"\",                   (string, required) wallet address\n";
	oss << "       \"avail\": 0.0,                    (double, required) balance available amount\n";
	oss << "       \"locked\": 0.0,                   (double, required) locked amount\n";
	oss << "       \"unconfirmed\": 0.0               (double, required) unconfirmed amount\n";
	oss << "     }\n";
	oss << "   ]\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli getbalance\n";
	oss << "<< [{\"address\":\"20g098nza351f53wppg0kfnsbxqf80h3x8fwp9vdmc98fbrgbv6mtjagy\",\"avail\":30.00000000,\"locked\":0.00000000,\"unconfirmed\":0.00000000}]\n";
	oss << "\n>> curl -d '{\"id\":1,\"method\":\"getbalance\",\"jsonrpc\":\"2.0\",\"params\":{}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":1,\"jsonrpc\":\"2.0\",\"result\":[{\"address\":\"20g098nza351f53wppg0kfnsbxqf80h3x8fwp9vdmc98fbrgbv6mtjagy\",\"avail\":30.00000000,\"locked\":0.00000000,\"unconfirmed\":0.00000000}]}\n";
	oss << "\n>> mkf-cli getbalance -a=20g0944xkyk8ybcmzhpv86vb5777jn1sfrdf3svzqn9phxftqth8116bm\n";
	oss << "<< [{\"address\":\"20g0944xkyk8ybcmzhpv86vb5777jn1sfrdf3svzqn9phxftqth8116bm\",\"avail\":58.99990000,\"locked\":0.00000000,\"unconfirmed\":13.99990000}]\n";
	oss << "\n>> curl -d '{\"id\":20,\"method\":\"getbalance\",\"jsonrpc\":\"2.0\",\"params\":{\"address\":\"20g0944xkyk8ybcmzhpv86vb5777jn1sfrdf3svzqn9phxftqth8116bm\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":20,\"jsonrpc\":\"2.0\",\"result\":[{\"address\":\"20g0944xkyk8ybcmzhpv86vb5777jn1sfrdf3svzqn9phxftqth8116bm\",\"avail\":58.99990000,\"locked\":0.00000000,\"unconfirmed\":13.99990000}]}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid fork\"}\n";
	oss << "* {\"code\":-6,\"message\":\"Unknown fork\"}\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid address\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// listtransaction

// CListTransactionConfig
CListTransactionConfig::CListTransactionConfig()
{
	boost::program_options::options_description desc("CListTransactionConfig");

	AddOpt<uint64>(desc, "n");
	AddOpt<int64>(desc, "o");
	AddOpt<string>(desc, "f");
	AddOpt<string>(desc, "a");

	AddOptions(desc);
}
bool CListTransactionConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 5)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (vm.find("n") != vm.end())
	{
		auto value = vm["n"];
		nCount = value.as<uint64>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			istringstream iss(*++it);
			iss >> nCount;
			if (!iss.eof() || iss.fail())
				throw CRPCException(RPC_PARSE_ERROR, "[count] type error, needs uint");
		}
	}
	if (vm.find("o") != vm.end())
	{
		auto value = vm["o"];
		nOffset = value.as<int64>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			istringstream iss(*++it);
			iss >> nOffset;
			if (!iss.eof() || iss.fail())
				throw CRPCException(RPC_PARSE_ERROR, "[offset] type error, needs int");
		}
	}
	if (vm.find("f") != vm.end())
	{
		auto value = vm["f"];
		strFork = value.as<string>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			strFork = *++it;
		}
	}
	if (vm.find("a") != vm.end())
	{
		auto value = vm["a"];
		strAddress = value.as<string>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			strAddress = *++it;
		}
	}
	return true;
}
string CListTransactionConfig::ListConfig() const
{
	return "";
}
string CListTransactionConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        listtransaction (-n=count) (-o=offset) (-f=\"fork\") (-a=\"address\")\n";
	oss << "\n";
	oss << "If (offset) < 0,return last (count) transactions,\n"
	       "If (offset) >= 0,return up to (count) most recent transactions skipping the first (offset) transactions.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " -n=count                               (uint, optional) transaction count. If not set, return 10 tx\n";
	oss << " -o=offset                              (int, optional) query offset. If not set, from 0\n";
	oss << " -f=\"fork\"                              (string, optional) fork hash. If not set, return all local fork 10 tx\n";
	oss << " -a=\"address\"                           (string, optional) from address or sendto address\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"count\": 0,                          (uint, optional) transaction count. If not set, return 10 tx\n";
	oss << "   \"offset\": 0,                         (int, optional) query offset. If not set, from 0\n";
	oss << "   \"fork\": \"\",                          (string, optional) fork hash. If not set, return all local fork 10 tx\n";
	oss << "   \"address\": \"\"                        (string, optional) from address or sendto address\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\" :\n";
	oss << "   [\n";
	oss << "     \"transaction\":                     (object, required) wallet transaction data\n";
	oss << "     {\n";
	oss << "       \"txid\": \"\",                      (string, required) transaction hash\n";
	oss << "       \"fork\": \"\",                      (string, required) fork hash\n";
	oss << "       \"type\": \"\",                      (string, required) transaction type\n";
	oss << "       \"time\": 0,                       (uint, required) transaction timestamp\n";
	oss << "       \"send\": true|false,              (bool, required) is from me\n";
	oss << "       \"to\": \"\",                        (string, required) to address\n";
	oss << "       \"amount\": 0.0,                   (double, required) transaction amount\n";
	oss << "       \"fee\": 0.0,                      (double, required) transaction fee\n";
	oss << "       \"lockuntil\": 0,                  (uint, required) lockuntil\n";
	oss << "       \"blockheight\": 0,                (int, optional) block height\n";
	oss << "       \"from\": \"\"                       (string, optional) from address\n";
	oss << "     }\n";
	oss << "   ]\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli listtransaction\n";
	oss << "<< [{\"txid\":\"4a8e6035b575699cdb25d45beadd49f18fb1303f57ec55493139e65d811e74ff\",\"fork\":\"a63d6f9d8055dc1bd7799593fb46ddc1b4e4519bd049e8eba1a0806917dcafc0\",\"blockheight\":31296,\"type\":\"work\",\"time\":1547916097,\"send\":false,\"to\":\"20g098nza351f53wppg0kfnsbxqf80h3x8fwp9vdmc98fbrgbv6mtjagy\",\"amount\":15.00000000,\"fee\":0.00000000,\"lockuntil\":0},{\"txid\":\"0aa6954236382a6c1c46cce7fa3165b4d1718f5e03ca67cd5fe831616a9000da\",\"fork\":\"a63d6f9d8055dc1bd7799593fb46ddc1b4e4519bd049e8eba1a0806917dcafc0\",\"blockheight\":31297,\"type\":\"work\",\"time\":1547916097,\"send\":false,\"to\":\"20g098nza351f53wppg0kfnsbxqf80h3x8fwp9vdmc98fbrgbv6mtjagy\",\"amount\":15.00000000,\"fee\":0.00000000,\"lockuntil\":0}]\n";
	oss << "\n>> curl -d '{\"id\":2,\"method\":\"listtransaction\",\"jsonrpc\":\"2.0\",\"params\":{}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":2,\"jsonrpc\":\"2.0\",\"result\":[{\"txid\":\"4a8e6035b575699cdb25d45beadd49f18fb1303f57ec55493139e65d811e74ff\",\"fork\":\"a63d6f9d8055dc1bd7799593fb46ddc1b4e4519bd049e8eba1a0806917dcafc0\",\"blockheight\":31296,\"type\":\"work\",\"time\":1547916097,\"send\":false,\"to\":\"20g098nza351f53wppg0kfnsbxqf80h3x8fwp9vdmc98fbrgbv6mtjagy\",\"amount\":15.00000000,\"fee\":0.00000000,\"lockuntil\":0},{\"txid\":\"0aa6954236382a6c1c46cce7fa3165b4d1718f5e03ca67cd5fe831616a9000da\",\"fork\":\"a63d6f9d8055dc1bd7799593fb46ddc1b4e4519bd049e8eba1a0806917dcafc0\",\"blockheight\":31297,\"type\":\"work\",\"time\":1547916097,\"send\":false,\"to\":\"20g098nza351f53wppg0kfnsbxqf80h3x8fwp9vdmc98fbrgbv6mtjagy\",\"amount\":15.00000000,\"fee\":0.00000000,\"lockuntil\":0}]}\n";
	oss << "\n>> mkf-cli listtransaction 1 -1\n";
	oss << "<< [{\"txid\":\"5a1b7bf5e32a77ecb3c53782a8e06f2b12bdcb73b677d6f89b6f82f85f14373a\",\"fork\":\"a63d6f9d8055dc1bd7799593fb46ddc1b4e4519bd049e8eba1a0806917dcafc0\",\"blockheight\":32086,\"type\":\"work\",\"time\":1547916097,\"send\":false,\"to\":\"20g098nza351f53wppg0kfnsbxqf80h3x8fwp9vdmc98fbrgbv6mtjagy\",\"amount\":15.00000000,\"fee\":0.00000000,\"lockuntil\":0}]\n";
	oss << "\n>> curl -d '{\"id\":0,\"method\":\"listtransaction\",\"jsonrpc\":\"2.0\",\"params\":{\"count\":1,\"offset\":-1}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":0,\"jsonrpc\":\"2.0\",\"result\":[{\"txid\":\"5a1b7bf5e32a77ecb3c53782a8e06f2b12bdcb73b677d6f89b6f82f85f14373a\",\"fork\":\"a63d6f9d8055dc1bd7799593fb46ddc1b4e4519bd049e8eba1a0806917dcafc0\",\"blockheight\":32086,\"type\":\"work\",\"time\":1547916097,\"send\":false,\"to\":\"20g098nza351f53wppg0kfnsbxqf80h3x8fwp9vdmc98fbrgbv6mtjagy\",\"amount\":15.00000000,\"fee\":0.00000000,\"lockuntil\":0}]}\n";
	oss << "\n>> listtransaction -n=1 -o=-1\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"Negative, zero or out of range count\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Failed to list transactions\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// sendfrom

// CSendFromConfig
CSendFromConfig::CSendFromConfig()
{
	boost::program_options::options_description desc("CSendFromConfig");

	AddOpt<string>(desc, "f");
	AddOpt<string>(desc, "d");
	AddOpt<string>(desc, "sm");
	AddOpt<string>(desc, "ss");
	AddOpt<string>(desc, "td");

	AddOptions(desc);
}
bool CSendFromConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 10)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strFrom = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[from] is required");
	}
	if (next(it, 1) != vecCommand.end())
	{
		strTo = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[to] is required");
	}
	if (next(it, 1) != vecCommand.end())
	{
		istringstream iss(*++it);
		iss >> dAmount;
		if (!iss.eof() || iss.fail())
			throw CRPCException(RPC_PARSE_ERROR, "[amount] type error, needs double");
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[amount] is required");
	}
	if (next(it, 1) != vecCommand.end())
	{
		istringstream iss(*++it);
		iss >> dTxfee;
		if (!iss.eof() || iss.fail())
			throw CRPCException(RPC_PARSE_ERROR, "[txfee] type error, needs double");
	}
	if (vm.find("f") != vm.end())
	{
		auto value = vm["f"];
		strFork = value.as<string>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			strFork = *++it;
		}
	}
	if (vm.find("d") != vm.end())
	{
		auto value = vm["d"];
		strData = value.as<string>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			strData = *++it;
		}
	}
	if (vm.find("sm") != vm.end())
	{
		auto value = vm["sm"];
		strSign_M = value.as<string>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			strSign_M = *++it;
		}
	}
	if (vm.find("ss") != vm.end())
	{
		auto value = vm["ss"];
		strSign_S = value.as<string>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			strSign_S = *++it;
		}
	}
	if (vm.find("td") != vm.end())
	{
		auto value = vm["td"];
		strSendtodata = value.as<string>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			strSendtodata = *++it;
		}
	}
	return true;
}
string CSendFromConfig::ListConfig() const
{
	return "";
}
string CSendFromConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        sendfrom <\"from\"> <\"to\"> <$amount$> ($txfee$) (-f=\"fork\") (-d=\"data\") (-sm=\"sign_m\") (-ss=\"sign_s\") (-td=\"sendtodata\")\n";
	oss << "\n";
	oss << "<amount> and <txfee> are real and rounded to the nearest 0.000001\n"
	       "Return transaction id\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"from\"                                 (string, required) from address\n";
	oss << " \"to\"                                   (string, required) to address\n";
	oss << " $amount$                               (double, required) amount\n";
	oss << " $txfee$                                (double, optional) transaction fee\n";
	oss << " -f=\"fork\"                              (string, optional) fork hash\n";
	oss << " -d=\"data\"                              (string, optional) output data\n";
	oss << " -sm=\"sign_m\"                           (string, optional) exchange sign m\n";
	oss << " -ss=\"sign_s\"                           (string, optional) exchange sign s\n";
	oss << " -td=\"sendtodata\"                       (string, optional) If the 'to' address of transaction is a template, this option allows to save the template hex data. The hex data is equal output of RPC 'exporttemplate'\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"from\": \"\",                          (string, required) from address\n";
	oss << "   \"to\": \"\",                            (string, required) to address\n";
	oss << "   \"amount\": 0.0,                       (double, required) amount\n";
	oss << "   \"txfee\": 0.0,                        (double, optional) transaction fee\n";
	oss << "   \"fork\": \"\",                          (string, optional) fork hash\n";
	oss << "   \"data\": \"\",                          (string, optional) output data\n";
	oss << "   \"sign_m\": \"\",                        (string, optional) exchange sign m\n";
	oss << "   \"sign_s\": \"\",                        (string, optional) exchange sign s\n";
	oss << "   \"sendtodata\": \"\"                     (string, optional) If the 'to' address of transaction is a template, this option allows to save the template hex data. The hex data is equal output of RPC 'exporttemplate'\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"transaction\"                (string, required) transaction hash\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli sendfrom 20g0944xkyk8ybcmzhpv86vb5777jn1sfrdf3svzqn9phxftqth8116bm 1q71vfagprv5hqwckzbvhep0d0ct72j5j2heak2sgp4vptrtc2btdje3q 1\n";
	oss << "<< 01a9f3bb967f24396293903c856e99896a514756a220266afa347a8b8c7f0038\n";
	oss << "\n>> curl -d '{\"id\":18,\"method\":\"sendfrom\",\"jsonrpc\":\"2.0\",\"params\":{\"from\":\"20g0944xkyk8ybcmzhpv86vb5777jn1sfrdf3svzqn9phxftqth8116bm\",\"to\":\"1q71vfagprv5hqwckzbvhep0d0ct72j5j2heak2sgp4vptrtc2btdje3q\",\"amount\":1.00000000}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":18,\"jsonrpc\":\"2.0\",\"result\":\"01a9f3bb967f24396293903c856e99896a514756a220266afa347a8b8c7f0038\"}\n";
	oss << "\n>> mkf-cli sendfrom 20g0753dp5b817d7v0hbag6a4neetzfdgbcyt2pkx93hrzn97epzbyn26 1q71vfagprv5hqwckzbvhep0d0ct72j5j2heak2sgp4vptrtc2btdje3q 1 0.1 -f=a63d6f9d8055dc1bd7799593fb46ddc1b4e4519bd049e8eba1a0806917dcafc0\n";
	oss << "<< 8f92969642024234481e104481f36145736b465ead2d52a6657cf38bd52bdf59\n";
	oss << "\n>> curl -d '{\"id\":53,\"method\":\"sendfrom\",\"jsonrpc\":\"2.0\",\"params\":{\"from\":\"20g0753dp5b817d7v0hbag6a4neetzfdgbcyt2pkx93hrzn97epzbyn26\",\"to\":\"1q71vfagprv5hqwckzbvhep0d0ct72j5j2heak2sgp4vptrtc2btdje3q\",\"amount\":1.00000000,\"txfee\":0.10000000,\"fork\":\"a63d6f9d8055dc1bd7799593fb46ddc1b4e4519bd049e8eba1a0806917dcafc0\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":53,\"jsonrpc\":\"2.0\",\"result\":\"8f92969642024234481e104481f36145736b465ead2d52a6657cf38bd52bdf59\"}\n";
	oss << "\n>> mkf-cli sendfrom 20r07rwj0032jssv0d3xaes1kq6z1cvjmz1jwhme0m1jf23vx48v683s3 1w8ehkb2jc0qcn7wze3tv8enzzwmytn9b7n7gghwfa219rv1vhhd82n6h 12.345 1 -sm='1b8c6b0807472627cec2f77b2a33428539b64493f7f1b9f7be4dfbdee72f9aeb3b5763fa39ce5df2425d8d530698de9c1cea993bccfce6596901b6b8cb054103' -ss='a51a925a50a7101ca25c8165050b61421f9e54aad5b0cfb4a4947da82f5fb62fec8e96fb80bd697db33f391bf1f875179d446ac08829f85cf8fe6483ec9acf0c' -f='92099485ffec67128fe4dbaca96ed8faf54ccc0b4760cd0d78a3d1e051a2498f'\n";
	oss << "<< 8f92969642024234481e104481f36145736b465ead2d52a6657cf38bd52bdf59\n";
	oss << "\n>> curl -d '{\"id\":53,\"method\":\"sendfrom\",\"jsonrpc\":\"2.0\",\"params\":{\"from\":\"20r07rwj0032jssv0d3xaes1kq6z1cvjmz1jwhme0m1jf23vx48v683s3\",\"to\":\"1w8ehkb2jc0qcn7wze3tv8enzzwmytn9b7n7gghwfa219rv1vhhd82n6h\",\"amount\":12.345000,\"txfee\":1.00000000,\"sm\":\"1b8c6b0807472627cec2f77b2a33428539b64493f7f1b9f7be4dfbdee72f9aeb3b5763fa39ce5df2425d8d530698de9c1cea993bccfce6596901b6b8cb054103\", \"ss\":\"a51a925a50a7101ca25c8165050b61421f9e54aad5b0cfb4a4947da82f5fb62fec8e96fb80bd697db33f391bf1f875179d446ac08829f85cf8fe6483ec9acf0c\",\"fork\":\"92099485ffec67128fe4dbaca96ed8faf54ccc0b4760cd0d78a3d1e051a2498f\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":53,\"jsonrpc\":\"2.0\",\"result\":\"5ce79ba78b44f8710710c8e35b8d3b725c2f994d4038b74fda84f0b061c01a76\"}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid from address\"}\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid to address\"}\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid fork\"}\n";
	oss << "* {\"code\":-6,\"message\":\"Unknown fork\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Failed to create transaction\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Failed to sign transaction\"}\n";
	oss << "* {\"code\":-401,\"message\":\"The signature is not completed\"}\n";
	oss << "* {\"code\":-10,\"message\":\"Tx rejected : xxx\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// createtransaction

// CCreateTransactionConfig
CCreateTransactionConfig::CCreateTransactionConfig()
{
	boost::program_options::options_description desc("CCreateTransactionConfig");

	AddOpt<string>(desc, "f");
	AddOpt<string>(desc, "d");

	AddOptions(desc);
}
bool CCreateTransactionConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 7)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strFrom = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[from] is required");
	}
	if (next(it, 1) != vecCommand.end())
	{
		strTo = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[to] is required");
	}
	if (next(it, 1) != vecCommand.end())
	{
		istringstream iss(*++it);
		iss >> dAmount;
		if (!iss.eof() || iss.fail())
			throw CRPCException(RPC_PARSE_ERROR, "[amount] type error, needs double");
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[amount] is required");
	}
	if (next(it, 1) != vecCommand.end())
	{
		istringstream iss(*++it);
		iss >> dTxfee;
		if (!iss.eof() || iss.fail())
			throw CRPCException(RPC_PARSE_ERROR, "[txfee] type error, needs double");
	}
	if (vm.find("f") != vm.end())
	{
		auto value = vm["f"];
		strFork = value.as<string>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			strFork = *++it;
		}
	}
	if (vm.find("d") != vm.end())
	{
		auto value = vm["d"];
		strData = value.as<string>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			strData = *++it;
		}
	}
	return true;
}
string CCreateTransactionConfig::ListConfig() const
{
	return "";
}
string CCreateTransactionConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        createtransaction <\"from\"> <\"to\"> <$amount$> ($txfee$) (-f=\"fork\") (-d=\"data\")\n";
	oss << "\n";
	oss << "<amount> and <txfee> are real and rounded to the nearest 0.000001.\n"
	       "Return serialized tx.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"from\"                                 (string, required) from address\n";
	oss << " \"to\"                                   (string, required) to address\n";
	oss << " $amount$                               (double, required) amount\n";
	oss << " $txfee$                                (double, optional) transaction fee\n";
	oss << " -f=\"fork\"                              (string, optional) fork hash\n";
	oss << " -d=\"data\"                              (string, optional) output data\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"from\": \"\",                          (string, required) from address\n";
	oss << "   \"to\": \"\",                            (string, required) to address\n";
	oss << "   \"amount\": 0.0,                       (double, required) amount\n";
	oss << "   \"txfee\": 0.0,                        (double, optional) transaction fee\n";
	oss << "   \"fork\": \"\",                          (string, optional) fork hash\n";
	oss << "   \"data\": \"\"                           (string, optional) output data\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"transaction\"                (string, required) transaction data\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli createtransaction 20g0753dp5b817d7v0hbag6a4neetzfdgbcyt2pkx93hrzn97epzbyn26 1q71vfagprv5hqwckzbvhep0d0ct72j5j2heak2sgp4vptrtc2btdje3q 1 0.1 -f=a63d6f9d8055dc1bd7799593fb46ddc1b4e4519bd049e8eba1a0806917dcafc0 -d=12345\n";
	oss << "<< 01000000000000002b747e24738befccff4a05c21dba749632cb8eb410233fa110e3f58a779b4325010ef45be50157453a57519929052d0818c269dee60be98958d5ab65bc7e0919810001b9c3b7aa16c6cb1bf193faf717580d03347148b2145ca98b30b1376d634c12f440420f0000000000a08601000000000002123400\n";
	oss << "\n>> curl -d '{\"id\":59,\"method\":\"createtransaction\",\"jsonrpc\":\"2.0\",\"params\":{\"from\":\"20g0753dp5b817d7v0hbag6a4neetzfdgbcyt2pkx93hrzn97epzbyn26\",\"to\":\"1q71vfagprv5hqwckzbvhep0d0ct72j5j2heak2sgp4vptrtc2btdje3q\",\"amount\":1.00000000,\"txfee\":0.10000000,\"fork\":\"a63d6f9d8055dc1bd7799593fb46ddc1b4e4519bd049e8eba1a0806917dcafc0\",\"data\":\"12345\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":59,\"jsonrpc\":\"2.0\",\"result\":\"01000000000000002b747e24738befccff4a05c21dba749632cb8eb410233fa110e3f58a779b4325010ef45be50157453a57519929052d0818c269dee60be98958d5ab65bc7e0919810001b9c3b7aa16c6cb1bf193faf717580d03347148b2145ca98b30b1376d634c12f440420f0000000000a08601000000000002123400\"}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid from address\"}\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid to address\"}\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid fork\"}\n";
	oss << "* {\"code\":-6,\"message\":\"Unknown fork\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Failed to create transaction\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// signtransaction

// CSignTransactionConfig
CSignTransactionConfig::CSignTransactionConfig()
{
	boost::program_options::options_description desc("CSignTransactionConfig");

	AddOpt<string>(desc, "td");

	AddOptions(desc);
}
bool CSignTransactionConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 3)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strTxdata = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[txdata] is required");
	}
	if (vm.find("td") != vm.end())
	{
		auto value = vm["td"];
		strSendtodata = value.as<string>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			strSendtodata = *++it;
		}
	}
	return true;
}
string CSignTransactionConfig::ListConfig() const
{
	return "";
}
string CSignTransactionConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        signtransaction <\"txdata\"> (-td=\"sendtodata\")\n";
	oss << "\n";
	oss << "Return json object with keys:\n"
	       "hex : raw transaction with signature(s) (hex-encoded string)\n"
	       "completed : true if transaction has a completed set of signature (false if not)\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"txdata\"                               (string, required) transaction data(hex string)\n";
	oss << " -td=\"sendtodata\"                       (string, optional) If the 'to' address of transaction is a template, this option allows to save the template hex data. The hex data is equal output of RPC 'exporttemplate'\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"txdata\": \"\",                        (string, required) transaction data(hex string)\n";
	oss << "   \"sendtodata\": \"\"                     (string, optional) If the 'to' address of transaction is a template, this option allows to save the template hex data. The hex data is equal output of RPC 'exporttemplate'\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\" :\n";
	oss << " {\n";
	oss << "   \"hex\": \"\",                           (string, required) hex of transaction data\n";
	oss << "   \"completed\": true|false              (bool, required) transaction completed or not\n";
	oss << " }\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli signtransaction 01000000000000002b747e24738befccff4a05c21dba749632cb8eb410233fa110e3f58a779b4325010ef45be50157453a57519929052d0818c269dee60be98958d5ab65bc7e0919810001b9c3b7aa16c6cb1bf193faf717580d03347148b2145ca98b30b1376d634c12f440420f0000000000a08601000000000002123400\n";
	oss << "<< {\"hex\":\"01000000000000002b747e24738befccff4a05c21dba749632cb8eb410233fa110e3f58a779b4325010ef45be50157453a57519929052d0818c269dee60be98958d5ab65bc7e0919810001b9c3b7aa16c6cb1bf193faf717580d03347148b2145ca98b30b1376d634c12f440420f0000000000a0860100000000000212348182e8a36441d116ce7a97f9a216d43a3dfc4280295874007b8ff5fd45eec9052e0182e8a36441d116ce7a97f9a216d43a3dfc4280295874007b8ff5fd45eec9052ed494d90cd96c252446b4a10459fea8c06186154b2bee2ce2182556e9ba40e7e69ddae2501862e4251bba2abf11c90d6f1fd0dec48a1419e81bb8c7d922cf3e03\",\"complete\":true}\n";
	oss << "\n>> curl -d '{\"id\":62,\"method\":\"signtransaction\",\"jsonrpc\":\"2.0\",\"params\":{\"txdata\":\"01000000000000002b747e24738befccff4a05c21dba749632cb8eb410233fa110e3f58a779b4325010ef45be50157453a57519929052d0818c269dee60be98958d5ab65bc7e0919810001b9c3b7aa16c6cb1bf193faf717580d03347148b2145ca98b30b1376d634c12f440420f0000000000a08601000000000002123400\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":62,\"jsonrpc\":\"2.0\",\"result\":{\"hex\":\"01000000000000002b747e24738befccff4a05c21dba749632cb8eb410233fa110e3f58a779b4325010ef45be50157453a57519929052d0818c269dee60be98958d5ab65bc7e0919810001b9c3b7aa16c6cb1bf193faf717580d03347148b2145ca98b30b1376d634c12f440420f0000000000a0860100000000000212348182e8a36441d116ce7a97f9a216d43a3dfc4280295874007b8ff5fd45eec9052e0182e8a36441d116ce7a97f9a216d43a3dfc4280295874007b8ff5fd45eec9052ed494d90cd96c252446b4a10459fea8c06186154b2bee2ce2182556e9ba40e7e69ddae2501862e4251bba2abf11c90d6f1fd0dec48a1419e81bb8c7d922cf3e03\",\"complete\":true}}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-8,\"message\":\"TX decode failed\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Failed to sign transaction\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// signmessage

// CSignMessageConfig
CSignMessageConfig::CSignMessageConfig()
{
	boost::program_options::options_description desc("CSignMessageConfig");

	AddOpt<string>(desc, "a");

	AddOptions(desc);
}
bool CSignMessageConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 4)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strPubkey = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[pubkey] is required");
	}
	if (next(it, 1) != vecCommand.end())
	{
		strMessage = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[message] is required");
	}
	if (vm.find("a") != vm.end())
	{
		auto value = vm["a"];
		strAddr = value.as<string>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			strAddr = *++it;
		}
	}
	return true;
}
string CSignMessageConfig::ListConfig() const
{
	return "";
}
string CSignMessageConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        signmessage <\"pubkey\"> <\"message\"> (-a=\"addr\")\n";
	oss << "\n";
	oss << "Sign a message with the private key of an pubkey\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"pubkey\"                               (string, required) public key\n";
	oss << " \"message\"                              (string, required) message to be signed\n";
	oss << " -a=\"addr\"                              (string, optional) address signed\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"pubkey\": \"\",                        (string, required) public key\n";
	oss << "   \"message\": \"\",                       (string, required) message to be signed\n";
	oss << "   \"addr\": \"\"                           (string, optional) address signed\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"signature\"                  (string, required) signature of message\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli signmessage 2e05c9ee45fdf58f7b007458298042fc3d3ad416a2f9977ace16d14164a3e882 123456\n";
	oss << "<< 045977f8c07e6d846d6055357f36a70c16c071cb85115e3ffb498e171a9ac3f4aed1292203a0c8e42c4becafad3ced0d9874abd2a8b788fda9f07099a1e71707\n";
	oss << "\n>> curl -d '{\"id\":4,\"method\":\"signmessage\",\"jsonrpc\":\"2.0\",\"params\":{\"pubkey\":\"2e05c9ee45fdf58f7b007458298042fc3d3ad416a2f9977ace16d14164a3e882\",\"message\":\"123456\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":4,\"jsonrpc\":\"2.0\",\"result\":\"045977f8c07e6d846d6055357f36a70c16c071cb85115e3ffb498e171a9ac3f4aed1292203a0c8e42c4becafad3ced0d9874abd2a8b788fda9f07099a1e71707\"}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-4,\"message\":\"Unknown key\"}\n";
	oss << "* {\"code\":-405,\"message\":\"Key is locked\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Failed to sign message\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// listaddress

// CListAddressConfig
CListAddressConfig::CListAddressConfig()
{
}
bool CListAddressConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 1)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	return true;
}
string CListAddressConfig::ListConfig() const
{
	return "";
}
string CListAddressConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        listaddress\n";
	oss << "\n";
	oss << "List all of the addresses from pub keys and template ids\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << "\tnone\n\n";
	oss << "Request:\n";
	oss << " \"param\" : {}\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\" :\n";
	oss << "   [\n";
	oss << "     \"addressdata\":                     (object, required) address data\n";
	oss << "     {\n";
	oss << "       \"type\": \"\",                      (string, required) type, pubkey or template\n";
	oss << "       \"address\": \"\",                   (string, required) public key or template address\n";
	oss << "       (if type=pubkey)\n";
	oss << "       \"pubkey\": \"\",                    (string, required) public key\n";
	oss << "       (if type=template)\n";
	oss << "       \"template\": \"\",                  (string, required) template type name\n";
	oss << "       (if type=template)\n";
	oss << "       \"templatedata\":                  (object, required) template data\n";
	oss << "       {\n";
	oss << "         \"type\": \"\",                    (string, required) template type\n";
	oss << "         \"hex\": \"\",                     (string, required) temtplate data\n";
	oss << "         (if type=delegate)\n";
	oss << "         \"delegate\":                    (object, required) delegate template struct\n";
	oss << "         {\n";
	oss << "           \"delegate\": \"\",              (string, required) delegate public key\n";
	oss << "           \"owner\": \"\"                  (string, required) owner address\n";
	oss << "         }\n";
	oss << "         (if type=vote)\n";
	oss << "         \"vote\":                        (object, required) vote template struct\n";
	oss << "         {\n";
	oss << "           \"delegate\": \"\",              (string, required) delegate template address\n";
	oss << "           \"owner\": \"\"                  (string, required) owner address\n";
	oss << "         }\n";
	oss << "         (if type=fork)\n";
	oss << "         \"fork\":                        (object, required) fork template struct\n";
	oss << "         {\n";
	oss << "           \"redeem\": \"\",                (string, required) redeem address\n";
	oss << "           \"fork\": \"\"                   (string, required) fork hash\n";
	oss << "         }\n";
	oss << "         (if type=mint)\n";
	oss << "         \"mint\":                        (object, required) mint template struct\n";
	oss << "         {\n";
	oss << "           \"mint\": \"\",                  (string, required) mint public key\n";
	oss << "           \"spent\": \"\"                  (string, required) spent address\n";
	oss << "         }\n";
	oss << "         (if type=multisig)\n";
	oss << "         \"multisig\":                    (object, required) multisig template struct\n";
	oss << "         {\n";
	oss << "           \"required\": 0,               (int, required) required weight\n";
	oss << "           [\n";
	oss << "             \"key\": \"\"                  (string, required) public key\n";
	oss << "           ]\n";
	oss << "         }\n";
	oss << "         (if type=exchange)\n";
	oss << "         \"exchange\":                    (object, required) exchange template struct\n";
	oss << "         {\n";
	oss << "           \"spend_m\": \"\",               (string, required) spend_m\n";
	oss << "           \"spend_s\": \"\",               (string, required) spend_s\n";
	oss << "           \"height_m\": 0,               (int, required) height m\n";
	oss << "           \"height_s\": 0,               (int, required) height s\n";
	oss << "           \"fork_m\": \"\",                (string, required) fork m\n";
	oss << "           \"fork_s\": \"\"                 (string, required) fork s\n";
	oss << "         }\n";
	oss << "         (if type=payment)\n";
	oss << "         \"payment\":                     (object, required) a payment template\n";
	oss << "         {\n";
	oss << "           \"business\": \"\",              (string, required) business\n";
	oss << "           \"customer\": \"\",              (string, required) customer\n";
	oss << "           \"height_exec\": 0,            (int, required) height_exec\n";
	oss << "           \"height_end\": 0,             (int, required) height_end\n";
	oss << "           \"amount\": 0,                 (int, required) amount\n";
	oss << "           \"pledge\": 0                  (int, required) pledge\n";
	oss << "         }\n";
	oss << "         (if type=weighted)\n";
	oss << "         \"weighted\":                    (object, required) weighted template struct\n";
	oss << "         {\n";
	oss << "           \"required\": 0,               (int, required) required weight\n";
	oss << "           [\n";
	oss << "             \"pubkey\":                  (object, required) public key\n";
	oss << "             {\n";
	oss << "               \"key\": \"\",               (string, required) public key\n";
	oss << "               \"weight\": 0              (int, required) weight\n";
	oss << "             }\n";
	oss << "           ]\n";
	oss << "         }\n";
	oss << "       }\n";
	oss << "     }\n";
	oss << "   ]\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli listaddress\n";
	oss << "<< [{\"type\":\"pubkey\",\"address\":\"1gbma6s21t4bcwymqz6h1dn1t7qy45019b1t00ywfyqymbvp90mqc1wmq\",\"pubkey\":\"182e8a36441d116ce7a97f9a216d43a3dfc4280295874007b8ff5fd45eec9052e\"},{\"type\":\"template\",\"address\":\"208043ht3c51qztrdfa0f3349pe2m8ajjw1mdb2py68fbckaa2s24tq55\",\"template\":\"multisig\",\"templatedata\":{\"type\":\"multisig\",\"hex\":\"0200010282e8a36441d116ce7a97f9a216d43a3dfc4280295874007b8ff5fd45eec9052eb9c3b7aa16c6cb1bf193faf717580d03347148b2145ca98b30b1376d634c12f4\",\"multisig\":{\"sigsrequired\":1,\"addresses\":[\"1gbma6s21t4bcwymqz6h1dn1t7qy45019b1t00ywfyqymbvp90mqc1wmq\",\"1q71vfagprv5hqwckzbvhep0d0ct72j5j2heak2sgp4vptrtc2btdje3q\"]}}},{\"type\":\"template\",\"address\":\"20g0b87qxcd52ceh9zmpzx0hy46pjfzdnqbkh8f4tqs4y0r6sxyzyny25\",\"template\":\"mint\",\"templatedata\":{\"type\":\"mint\",\"hex\":\"0400f9b4af95bec6c5d504366245e0420bc3c5c78cd05ea68e4ad85a4d770e77e3e801f9b4af95bec6c5d504366245e0420bc3c5c78cd05ea68e4ad85a4d770e77e3e8\",\"mint\":{\"mint\":\"1z6taz5dyrv2xa11pc92y0ggbrf2wf36gbtk8wjprb96qe3kqwfm3ayc1\",\"spent\":\"1z6taz5dyrv2xa11pc92y0ggbrf2wf36gbtk8wjprb96qe3kqwfm3ayc1\"}}}]\n";
	oss << "\n>> curl -d '{\"id\":1,\"method\":\"listaddress\",\"jsonrpc\":\"2.0\",\"params\":{}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":0,\"jsonrpc\":\"2.0\",\"result\":[{\"type\":\"pubkey\",\"address\":\"1gbma6s21t4bcwymqz6h1dn1t7qy45019b1t00ywfyqymbvp90mqc1wmq\",\"pubkey\":\"182e8a36441d116ce7a97f9a216d43a3dfc4280295874007b8ff5fd45eec9052e\"},{\"type\":\"template\",\"address\":\"208043ht3c51qztrdfa0f3349pe2m8ajjw1mdb2py68fbckaa2s24tq55\",\"template\":\"multisig\",\"templatedata\":{\"type\":\"multisig\",\"hex\":\"0200010282e8a36441d116ce7a97f9a216d43a3dfc4280295874007b8ff5fd45eec9052eb9c3b7aa16c6cb1bf193faf717580d03347148b2145ca98b30b1376d634c12f4\",\"multisig\":{\"sigsrequired\":1,\"addresses\":[\"1gbma6s21t4bcwymqz6h1dn1t7qy45019b1t00ywfyqymbvp90mqc1wmq\",\"1q71vfagprv5hqwckzbvhep0d0ct72j5j2heak2sgp4vptrtc2btdje3q\"]}}},{\"type\":\"template\",\"address\":\"20g0b87qxcd52ceh9zmpzx0hy46pjfzdnqbkh8f4tqs4y0r6sxyzyny25\",\"template\":\"mint\",\"templatedata\":{\"type\":\"mint\",\"hex\":\"0400f9b4af95bec6c5d504366245e0420bc3c5c78cd05ea68e4ad85a4d770e77e3e801f9b4af95bec6c5d504366245e0420bc3c5c78cd05ea68e4ad85a4d770e77e3e8\",\"mint\":{\"mint\":\"1z6taz5dyrv2xa11pc92y0ggbrf2wf36gbtk8wjprb96qe3kqwfm3ayc1\",\"spent\":\"1z6taz5dyrv2xa11pc92y0ggbrf2wf36gbtk8wjprb96qe3kqwfm3ayc1\"}}}]}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "\tnone\n\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// exportwallet

// CExportWalletConfig
CExportWalletConfig::CExportWalletConfig()
{
}
bool CExportWalletConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 2)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strPath = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[path] is required");
	}
	return true;
}
string CExportWalletConfig::ListConfig() const
{
	return "";
}
string CExportWalletConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        exportwallet <\"path\">\n";
	oss << "\n";
	oss << "Export all of keys and templates from wallet to a specified file in JSON format.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"path\"                                 (string, required) save file path\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"path\": \"\"                           (string, required) save file path\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"result\"                     (string, required) export result\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli exportwallet /Users/Loading/a.txt\n";
	oss << "<< Wallet file has been saved at: /Users/Loading/a.txt\n";
	oss << "\n>> {\"id\":4,\"method\":\"exportwallet\",\"jsonrpc\":\"2.0\",\"params\":{\"path\":\"/Users/Loading/a.txt\"}}\n";
	oss << "<< {\"id\":4,\"jsonrpc\":\"2.0\",\"result\":\"Wallet file has been saved at: /Users/Loading/a.txt\"}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid template address\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Must be an absolute path.\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Cannot export to a folder.\"}\n";
	oss << "* {\"code\":-401,\"message\":\"File has been existed.\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Failed to create directories.\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Failed to export key\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Unkown template\"}\n";
	oss << "* {\"code\":-401,\"message\":\"filesystem_error\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// importwallet

// CImportWalletConfig
CImportWalletConfig::CImportWalletConfig()
{
}
bool CImportWalletConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 2)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strPath = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[path] is required");
	}
	return true;
}
string CImportWalletConfig::ListConfig() const
{
	return "";
}
string CImportWalletConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        importwallet <\"path\">\n";
	oss << "\n";
	oss << "Import keys and templates from an archived file to the wallet in JSON format.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"path\"                                 (string, required) save file path\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"path\": \"\"                           (string, required) save file path\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"result\"                     (string, required) export result\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli importwallet /Users/Loading/a.txt\n";
	oss << "<< Imported 0 keys and 0 templates.\n";
	oss << "\n>> {\"id\":5,\"method\":\"importwallet\",\"jsonrpc\":\"2.0\",\"params\":{\"path\":\"/Users/Loading/a.txt\"}}\n";
	oss << "<< {\"id\":5,\"jsonrpc\":\"2.0\",\"result\":\"Imported 0 keys and 0 templates.\"}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid parameters,failed to make template\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Must be an absolute path.\"}\n";
	oss << "* {\"code\":-401,\"message\":\"File has been existed.\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Filesystem_error - failed to read.\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Wallet file exported is invalid, check it and try again.\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Data format is not correct, check it and try again.\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Failed to add key\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Failed to sync wallet tx\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Failed to add template\"}\n";
	oss << "* {\"code\":-32602,\"message\":\"Failed to verify serialized key\"}\n";
	oss << "* {\"code\":-32602,\"message\":\"Can't import the key with empty passphrase\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// verifymessage

// CVerifyMessageConfig
CVerifyMessageConfig::CVerifyMessageConfig()
{
	boost::program_options::options_description desc("CVerifyMessageConfig");

	AddOpt<string>(desc, "a");

	AddOptions(desc);
}
bool CVerifyMessageConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 5)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strPubkey = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[pubkey] is required");
	}
	if (next(it, 1) != vecCommand.end())
	{
		strMessage = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[message] is required");
	}
	if (next(it, 1) != vecCommand.end())
	{
		strSig = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[sig] is required");
	}
	if (vm.find("a") != vm.end())
	{
		auto value = vm["a"];
		strAddr = value.as<string>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			strAddr = *++it;
		}
	}
	return true;
}
string CVerifyMessageConfig::ListConfig() const
{
	return "";
}
string CVerifyMessageConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        verifymessage <\"pubkey\"> <\"message\"> <\"sig\"> (-a=\"addr\")\n";
	oss << "\n";
	oss << "Verify a signed message\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"pubkey\"                               (string, required) public key\n";
	oss << " \"message\"                              (string, required) message to be verified\n";
	oss << " \"sig\"                                  (string, required) sign\n";
	oss << " -a=\"addr\"                              (string, optional) address signed\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"pubkey\": \"\",                        (string, required) public key\n";
	oss << "   \"message\": \"\",                       (string, required) message to be verified\n";
	oss << "   \"sig\": \"\",                           (string, required) sign\n";
	oss << "   \"addr\": \"\"                           (string, optional) address signed\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": result                       (bool, required) message verified result.\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli verifymessage 2e05c9ee45fdf58f7b007458298042fc3d3ad416a2f9977ace16d14164a3e882 123456 045977f8c07e6d846d6055357f36a70c16c071cb85115e3ffb498e171a9ac3f4aed1292203a0c8e42c4becafad3ced0d9874abd2a8b788fda9f07099a1e71707\n";
	oss << "<< true\n";
	oss << "\n>> curl -d '{\"id\":5,\"method\":\"verifymessage\",\"jsonrpc\":\"2.0\",\"params\":{\"pubkey\":\"2e05c9ee45fdf58f7b007458298042fc3d3ad416a2f9977ace16d14164a3e882\",\"message\":\"123456\",\"sig\":\"045977f8c07e6d846d6055357f36a70c16c071cb85115e3ffb498e171a9ac3f4aed1292203a0c8e42c4becafad3ced0d9874abd2a8b788fda9f07099a1e71707\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":5,\"jsonrpc\":\"2.0\",\"result\":true}\n";
	oss << "\n>> mkf-cli verifymessage 2e05c9ee45fdf58f7b007458298042fc3d3ad416a2f9977ace16d14164a3e882 12345 045977f8c07e6d846d6055357f36a70c16c071cb85115e3ffb498e171a9ac3f4aed1292203a0c8e42c4becafad3ced0d9874abd2a8b788fda9f07099a1e71707\n";
	oss << "<< false\n";
	oss << "\n>> curl -d '{\"id\":6,\"method\":\"verifymessage\",\"jsonrpc\":\"2.0\",\"params\":{\"pubkey\":\"2e05c9ee45fdf58f7b007458298042fc3d3ad416a2f9977ace16d14164a3e882\",\"message\":\"12345\",\"sig\":\"045977f8c07e6d846d6055357f36a70c16c071cb85115e3ffb498e171a9ac3f4aed1292203a0c8e42c4becafad3ced0d9874abd2a8b788fda9f07099a1e71707\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":6,\"jsonrpc\":\"2.0\",\"result\":false}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid pubkey\"}\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid message\"}\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid sig\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// makekeypair

// CMakeKeyPairConfig
CMakeKeyPairConfig::CMakeKeyPairConfig()
{
}
bool CMakeKeyPairConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 1)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	return true;
}
string CMakeKeyPairConfig::ListConfig() const
{
	return "";
}
string CMakeKeyPairConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        makekeypair\n";
	oss << "\n";
	oss << "Make a public/private key pair.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << "\tnone\n\n";
	oss << "Request:\n";
	oss << " \"param\" : {}\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\" :\n";
	oss << " {\n";
	oss << "   \"privkey\": \"\",                       (string, required) private key\n";
	oss << "   \"pubkey\": \"\"                         (string, required) public key\n";
	oss << " }\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli makekeypair\n";
	oss << "<< {\"privkey\":\"833a5d51d2db84debc0eb3a40d7d41b2723452d211d7e81ce489a95ef48b2324\",\"pubkey\":\"e8e3770e774d5ad84a8ea65ed08cc7c5c30b42e045623604d5c5c6be95afb4f9\"}\n";
	oss << "\n>> curl -d '{\"id\":42,\"method\":\"makekeypair\",\"jsonrpc\":\"2.0\",\"params\":{}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":42,\"jsonrpc\":\"2.0\",\"result\":{\"privkey\":\"833a5d51d2db84debc0eb3a40d7d41b2723452d211d7e81ce489a95ef48b2324\",\"pubkey\":\"e8e3770e774d5ad84a8ea65ed08cc7c5c30b42e045623604d5c5c6be95afb4f9\"}}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "\tnone\n\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// getpubkeyaddress

// CGetPubkeyAddressConfig
CGetPubkeyAddressConfig::CGetPubkeyAddressConfig()
{
	boost::program_options::options_description desc("CGetPubkeyAddressConfig");

	AddOpt<string>(desc, "r");

	AddOptions(desc);
}
bool CGetPubkeyAddressConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 3)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strPubkey = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[pubkey] is required");
	}
	if (vm.find("r") != vm.end())
	{
		auto value = vm["r"];
		strReversal = value.as<string>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			strReversal = *++it;
		}
	}
	return true;
}
string CGetPubkeyAddressConfig::ListConfig() const
{
	return "";
}
string CGetPubkeyAddressConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        getpubkeyaddress <\"pubkey\"> (-r=\"reversal\")\n";
	oss << "\n";
	oss << "Return encoded address for the given public key.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"pubkey\"                               (string, required) public key\n";
	oss << " -r=\"reversal\"                          (string, optional) reversal get address pubkey\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"pubkey\": \"\",                        (string, required) public key\n";
	oss << "   \"reversal\": \"\"                       (string, optional) reversal get address pubkey\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"address\"                    (string, required) address of public key\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli getpubkeyaddress e8e3770e774d5ad84a8ea65ed08cc7c5c30b42e045623604d5c5c6be95afb4f9\n";
	oss << "<< 1z6taz5dyrv2xa11pc92y0ggbrf2wf36gbtk8wjprb96qe3kqwfm3ayc1\n";
	oss << "\n>> curl -d '{\"id\":44,\"method\":\"getpubkeyaddress\",\"jsonrpc\":\"2.0\",\"params\":{\"pubkey\":\"e8e3770e774d5ad84a8ea65ed08cc7c5c30b42e045623604d5c5c6be95afb4f9\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":44,\"jsonrpc\":\"2.0\",\"result\":\"1z6taz5dyrv2xa11pc92y0ggbrf2wf36gbtk8wjprb96qe3kqwfm3ayc1\"}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid pubkey\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// gettemplateaddress

// CGetTemplateAddressConfig
CGetTemplateAddressConfig::CGetTemplateAddressConfig()
{
}
bool CGetTemplateAddressConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 2)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strTid = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[tid] is required");
	}
	return true;
}
string CGetTemplateAddressConfig::ListConfig() const
{
	return "";
}
string CGetTemplateAddressConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        gettemplateaddress <\"tid\">\n";
	oss << "\n";
	oss << "Return encoded address for the given template id.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"tid\"                                  (string, required) template id\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"tid\": \"\"                            (string, required) template id\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"address\"                    (string, required) address of template\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli gettemplateaddress 2040fpytdr4k5h8tk0nferr7zb51tkccrkgqf341s6tg05q9xe6hth1m4\n";
	oss << "<< 21w2040000000000000000000000000000000000000000000000epcek\n";
	oss << "\n>> curl -d '{\"id\":53,\"method\":\"gettemplateaddress\",\"jsonrpc\":\"2.0\",\"params\":{\"tid\":\"2040fpytdr4k5h8tk0nferr7zb51tkccrkgqf341s6tg05q9xe6hth1m4\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":53,\"jsonrpc\":\"2.0\",\"result\":\"21w2040000000000000000000000000000000000000000000000epcek\"}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid tid\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// maketemplate

// CMakeTemplateConfig
CMakeTemplateConfig::CMakeTemplateConfig()
{
}
bool CMakeTemplateConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 11)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		data.strType = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[type] is required");
	}
	if (data.strType == "delegate")
	{
		string strOriginDelegate;
		if (next(it, 1) != vecCommand.end())
		{
			strOriginDelegate = *++it;
		}
		else
		{
			throw CRPCException(RPC_PARSE_ERROR, "[delegate] is required");
		}
		Value valOriginDelegate;
		if (!read_string(strOriginDelegate, valOriginDelegate, RPC_MAX_DEPTH))
		{
			throw CRPCException(RPC_PARSE_ERROR, "parse json error");
		}
		data.delegate.FromJSON(valOriginDelegate);
	}
	if (data.strType == "vote")
	{
		string strOriginVote;
		if (next(it, 1) != vecCommand.end())
		{
			strOriginVote = *++it;
		}
		else
		{
			throw CRPCException(RPC_PARSE_ERROR, "[vote] is required");
		}
		Value valOriginVote;
		if (!read_string(strOriginVote, valOriginVote, RPC_MAX_DEPTH))
		{
			throw CRPCException(RPC_PARSE_ERROR, "parse json error");
		}
		data.vote.FromJSON(valOriginVote);
	}
	if (data.strType == "fork")
	{
		string strOriginFork;
		if (next(it, 1) != vecCommand.end())
		{
			strOriginFork = *++it;
		}
		else
		{
			throw CRPCException(RPC_PARSE_ERROR, "[fork] is required");
		}
		Value valOriginFork;
		if (!read_string(strOriginFork, valOriginFork, RPC_MAX_DEPTH))
		{
			throw CRPCException(RPC_PARSE_ERROR, "parse json error");
		}
		data.fork.FromJSON(valOriginFork);
	}
	if (data.strType == "mint")
	{
		string strOriginMint;
		if (next(it, 1) != vecCommand.end())
		{
			strOriginMint = *++it;
		}
		else
		{
			throw CRPCException(RPC_PARSE_ERROR, "[mint] is required");
		}
		Value valOriginMint;
		if (!read_string(strOriginMint, valOriginMint, RPC_MAX_DEPTH))
		{
			throw CRPCException(RPC_PARSE_ERROR, "parse json error");
		}
		data.mint.FromJSON(valOriginMint);
	}
	if (data.strType == "multisig")
	{
		string strOriginMultisig;
		if (next(it, 1) != vecCommand.end())
		{
			strOriginMultisig = *++it;
		}
		else
		{
			throw CRPCException(RPC_PARSE_ERROR, "[multisig] is required");
		}
		Value valOriginMultisig;
		if (!read_string(strOriginMultisig, valOriginMultisig, RPC_MAX_DEPTH))
		{
			throw CRPCException(RPC_PARSE_ERROR, "parse json error");
		}
		data.multisig.FromJSON(valOriginMultisig);
	}
	if (data.strType == "weighted")
	{
		string strOriginWeighted;
		if (next(it, 1) != vecCommand.end())
		{
			strOriginWeighted = *++it;
		}
		else
		{
			throw CRPCException(RPC_PARSE_ERROR, "[weighted] is required");
		}
		Value valOriginWeighted;
		if (!read_string(strOriginWeighted, valOriginWeighted, RPC_MAX_DEPTH))
		{
			throw CRPCException(RPC_PARSE_ERROR, "parse json error");
		}
		data.weighted.FromJSON(valOriginWeighted);
	}
	if (data.strType == "exchange")
	{
		string strOriginExchange;
		if (next(it, 1) != vecCommand.end())
		{
			strOriginExchange = *++it;
		}
		else
		{
			throw CRPCException(RPC_PARSE_ERROR, "[exchange] is required");
		}
		Value valOriginExchange;
		if (!read_string(strOriginExchange, valOriginExchange, RPC_MAX_DEPTH))
		{
			throw CRPCException(RPC_PARSE_ERROR, "parse json error");
		}
		data.exchange.FromJSON(valOriginExchange);
	}
	if (data.strType == "payment")
	{
		string strOriginPayment;
		if (next(it, 1) != vecCommand.end())
		{
			strOriginPayment = *++it;
		}
		else
		{
			throw CRPCException(RPC_PARSE_ERROR, "[payment] is required");
		}
		Value valOriginPayment;
		if (!read_string(strOriginPayment, valOriginPayment, RPC_MAX_DEPTH))
		{
			throw CRPCException(RPC_PARSE_ERROR, "parse json error");
		}
		data.payment.FromJSON(valOriginPayment);
	}
	if (next(it, 1) != vecCommand.end())
	{
		istringstream iss(*++it);
		iss >> boolalpha >> data.fSynctx;
		if (!iss.eof() || iss.fail())
			throw CRPCException(RPC_PARSE_ERROR, "[synctx] type error, needs bool");
	}
	else
	{
		data.fSynctx = true;
	}
	return true;
}
string CMakeTemplateConfig::ListConfig() const
{
	return "";
}
string CMakeTemplateConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        maketemplate <\"type\"> <{delegate}>|<{vote}>|<{fork}>|<{mint}>|<{multisig}>|<{weighted}>|<{exchange}>|<{payment}> (*synctx*)\n";
	oss << "\n";
	oss << "Return encoded address for the given template id.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"type\"                                 (string, required) template type\n";
	oss << "  (if type=delegate)\n";
	oss << " {delegate}                             (object, required) a delegate template\n";
	oss << "  (if type=vote)\n";
	oss << " {vote}                                 (object, required) a vote template\n";
	oss << "  (if type=fork)\n";
	oss << " {fork}                                 (object, required) a new fork template\n";
	oss << "  (if type=mint)\n";
	oss << " {mint}                                 (object, required) a mint template\n";
	oss << "  (if type=multisig)\n";
	oss << " {multisig}                             (object, required) a multiple sign template\n";
	oss << "  (if type=weighted)\n";
	oss << " {weighted}                             (object, required) a weighted multiple sign template\n";
	oss << "  (if type=exchange)\n";
	oss << " {exchange}                             (object, required) a exchange template\n";
	oss << "  (if type=payment)\n";
	oss << " {payment}                              (object, required) a payment template\n";
	oss << " *synctx*                               (bool, optional, default=true) sync tx or not\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"type\": \"\",                          (string, required) template type\n";
	oss << "   (if type=delegate)\n";
	oss << "   \"delegate\":                          (object, required) a delegate template\n";
	oss << "   {\n";
	oss << "     \"delegate\": \"\",                    (string, required) delegate public key\n";
	oss << "     \"owner\": \"\"                        (string, required) owner address\n";
	oss << "   }\n";
	oss << "   (if type=vote)\n";
	oss << "   \"vote\":                              (object, required) a vote template\n";
	oss << "   {\n";
	oss << "     \"delegate\": \"\",                    (string, required) delegate template address\n";
	oss << "     \"owner\": \"\"                        (string, required) owner address\n";
	oss << "   }\n";
	oss << "   (if type=fork)\n";
	oss << "   \"fork\":                              (object, required) a new fork template\n";
	oss << "   {\n";
	oss << "     \"redeem\": \"\",                      (string, required) redeem address\n";
	oss << "     \"fork\": \"\"                         (string, required) fork hash\n";
	oss << "   }\n";
	oss << "   (if type=mint)\n";
	oss << "   \"mint\":                              (object, required) a mint template\n";
	oss << "   {\n";
	oss << "     \"mint\": \"\",                        (string, required) mint public key\n";
	oss << "     \"spent\": \"\"                        (string, required) spent address\n";
	oss << "   }\n";
	oss << "   (if type=multisig)\n";
	oss << "   \"multisig\":                          (object, required) a multiple sign template\n";
	oss << "   {\n";
	oss << "     \"required\": 0,                     (int, required) required weight > 0\n";
	oss << "     [\n";
	oss << "       \"key\": \"\"                        (string, required) public key\n";
	oss << "     ]\n";
	oss << "   }\n";
	oss << "   (if type=weighted)\n";
	oss << "   \"weighted\":                          (object, required) a weighted multiple sign template\n";
	oss << "   {\n";
	oss << "     \"required\": 0,                     (int, required) required weight\n";
	oss << "     [\n";
	oss << "       \"pubkey\":                        (object, required) public key\n";
	oss << "       {\n";
	oss << "         \"key\": \"\",                     (string, required) public key\n";
	oss << "         \"weight\": 0                    (int, required) weight\n";
	oss << "       }\n";
	oss << "     ]\n";
	oss << "   }\n";
	oss << "   (if type=exchange)\n";
	oss << "   \"exchange\":                          (object, required) a exchange template\n";
	oss << "   {\n";
	oss << "     \"addr_m\": \"\",                      (string, required) addr_m\n";
	oss << "     \"addr_s\": \"\",                      (string, required) addr_s\n";
	oss << "     \"height_m\": 0,                     (int, required) height_m\n";
	oss << "     \"height_s\": 0,                     (int, required) height_s\n";
	oss << "     \"fork_m\": \"\",                      (string, required) fork_m hash\n";
	oss << "     \"fork_s\": \"\"                       (string, required) fork_s hash\n";
	oss << "   }\n";
	oss << "   (if type=payment)\n";
	oss << "   \"payment\":                           (object, required) a payment template\n";
	oss << "   {\n";
	oss << "     \"business\": \"\",                    (string, required) business\n";
	oss << "     \"customer\": \"\",                    (string, required) customer\n";
	oss << "     \"height_exec\": 0,                  (int, required) height_exec\n";
	oss << "     \"height_end\": 0,                   (int, required) height_end\n";
	oss << "     \"amount\": 0,                       (int, required) amount\n";
	oss << "     \"pledge\": 0                        (int, required) pledge\n";
	oss << "   }\n";
	oss << "   \"synctx\": true|false                 (bool, optional, default=true) sync tx or not\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\" :\n";
	oss << " {\n";
	oss << "   \"address\": \"\",                       (string, required) address of template\n";
	oss << "   \"hex\": \"\"                            (string, required) template data hex string\n";
	oss << " }\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli maketemplate multisig '{\"required\": 1, \"pubkeys\": [\"2e05c9ee45fdf58f7b007458298042fc3d3ad416a2f9977ace16d14164a3e882\", \"f4124c636d37b1308ba95c14b2487134030d5817f7fa93f11bcbc616aab7c3b9\"]}'\n";
	oss << "<< {\"address\":\"208043ht3c51qztrdfa0f3349pe2m8ajjw1mdb2py68fbckaa2s24tq55\",\"hex\":\"0200010282e8a36441d116ce7a97f9a216d43a3dfc4280295874007b8ff5fd45eec9052eb9c3b7aa16c6cb1bf193faf717580d03347148b2145ca98b30b1376d634c12f4\"}\n";
	oss << "\n>> curl -d '{\"id\":54,\"method\":\"maketemplate\",\"jsonrpc\":\"2.0\",\"params\":{\"type\":\"multisig\",\"multisig\":{\"required\":1,\"pubkeys\":[\"2e05c9ee45fdf58f7b007458298042fc3d3ad416a2f9977ace16d14164a3e882\",\"f4124c636d37b1308ba95c14b2487134030d5817f7fa93f11bcbc616aab7c3b9\"]}}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":54,\"jsonrpc\":\"2.0\",\"result\":{\"address\":\"208043ht3c51qztrdfa0f3349pe2m8ajjw1mdb2py68fbckaa2s24tq55\",\"hex\":\"0200010282e8a36441d116ce7a97f9a216d43a3dfc4280295874007b8ff5fd45eec9052eb9c3b7aa16c6cb1bf193faf717580d03347148b2145ca98b30b1376d634c12f4\"}}\n";
	oss << "\n>> mkf-cli maketemplate delegate '{\"delegate\":\"2e05c9ee45fdf58f7b007458298042fc3d3ad416a2f9977ace16d14164a3e882\",\"owner\":\"1gbma6s21t4bcwymqz6h1dn1t7qy45019b1t00ywfyqymbvp90mqc1wmq\"}'\n";
	oss << "\n>> mkf-cli maketemplate fork '{\"redeem\":\"1gbma6s21t4bcwymqz6h1dn1t7qy45019b1t00ywfyqymbvp90mqc1wmq\",\"fork\":\"a63d6f9d8055dc1bd7799593fb46ddc1b4e4519bd049e8eba1a0806917dcafc0\"}'\n";
	oss << "\n>> mkf-cli maketemplate mint '{\"mint\": \"e8e3770e774d5ad84a8ea65ed08cc7c5c30b42e045623604d5c5c6be95afb4f9\", \"spent\": \"1z6taz5dyrv2xa11pc92y0ggbrf2wf36gbtk8wjprb96qe3kqwfm3ayc1\"}'\n";
	oss << "\n>> mkf-cli maketemplate weighted '{\"required\": 1, \"pubkeys\": [{\"key\":\"2e05c9ee45fdf58f7b007458298042fc3d3ad416a2f9977ace16d14164a3e882\", \"weight\": 1},{\"key\": \"f4124c636d37b1308ba95c14b2487134030d5817f7fa93f11bcbc616aab7c3b9\", \"weight\": 2}]}'\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid parameters, failed to make template\"}\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid parameter, missing weight\"}\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid parameter, missing redeem address\"}\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid parameter, missing spent address\"}\n";
	oss << "* {\"code\":-6,\"message\":\"Invalid parameter, missing owner address\"}\n";
	oss << "* {\"code\":-6,\"message\":\"template type error. type: xxx\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// decodetransaction

// CDecodeTransactionConfig
CDecodeTransactionConfig::CDecodeTransactionConfig()
{
}
bool CDecodeTransactionConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 2)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strTxdata = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[txdata] is required");
	}
	return true;
}
string CDecodeTransactionConfig::ListConfig() const
{
	return "";
}
string CDecodeTransactionConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        decodetransaction <\"txdata\">\n";
	oss << "\n";
	oss << "Return a JSON object representing the serialized, hex-encoded transaction.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"txdata\"                               (string, required) transaction raw data\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"txdata\": \"\"                         (string, required) transaction raw data\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\" :\n";
	oss << " {\n";
	oss << "   \"txid\": \"\",                          (string, required) transaction hash\n";
	oss << "   \"version\": 0,                        (uint, required) version\n";
	oss << "   \"type\": \"\",                          (string, required) transaction type\n";
	oss << "   \"time\": 0,                           (uint, required) transaction timestamp\n";
	oss << "   \"lockuntil\": 0,                      (uint, required) unlock time\n";
	oss << "   \"blockhash\": \"\",                     (string, required) which block tx located in\n";
	oss << "   [\n";
	oss << "     \"vin\":                             (object, required) vin struct\n";
	oss << "     {\n";
	oss << "       \"txid\": \"\",                      (string, required) pre-vout transaction hash\n";
	oss << "       \"vout\": 0                        (uint, required) pre-vout number\n";
	oss << "     }\n";
	oss << "   ]\n";
	oss << "   \"sendfrom\": \"\",                      (string, required) send from address\n";
	oss << "   \"sendto\": \"\",                        (string, required) send to address\n";
	oss << "   \"amount\": 0.0,                       (double, required) amount\n";
	oss << "   \"txfee\": 0.0,                        (double, required) transaction fee\n";
	oss << "   \"data\": \"\",                          (string, required) data\n";
	oss << "   \"sig\": \"\",                           (string, required) sign\n";
	oss << "   \"fork\": \"\",                          (string, required) fork hash\n";
	oss << "   \"confirmations\": 0                   (int, optional) confirmations\n";
	oss << " }\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli decodetransaction 010000003190f05d00000000701af4705c5e6fcb04efc3ca3c851c1e4d8948e10923025f54bea9b000000000017a792b71cdb0f662c802207d849e73c504b7a87096c6d80479605a2a9188f05d0001a4dce88fee73a59dcebf2b40ba1d13407254164b9166f063b2e8d513561118d620e4ab0900000000a0860100000000000040d6594d9215c58224f9707a84f773b00394561df0bba769a279dd065b98bc03a946928f8a6508a728eceff3e22d5181da16b78087c79b68532b31553bdc855000\n";
	oss << "<< {\"txid\":\"5df09031322f99db08a4747d652e0733f60c9b523a6a489b5f72e0031a2b2a03\",\"version\":1,\"type\":\"token\",\"time\":1576046641,\"lockuntil\":0,\"anchor\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"vin\":[{\"txid\":\"5df088912a5a607904d8c69670a8b704c5739e847d2002c862f6b0cd712b797a\",\"vout\":0}],\"sendfrom\":\"1n56xmva8131c4q0961anv5wdzfqtdctyg9e53fxp65f1jyhbtkfbxz6q\",\"sendto\":\"1mkeeh3zeeejsvknz5d0bm78k81s585jbj5kf0rxjx3ah6ngh33b1erg9\",\"amount\":162.260000,\"txfee\":0.100000,\"data\":\"\",\"sig\":\"d6594d9215c58224f9707a84f773b00394561df0bba769a279dd065b98bc03a946928f8a6508a728eceff3e22d5181da16b78087c79b68532b31553bdc855000\",\"fork\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\"}\n";
	oss << "\n>> curl -d '{\"id\":1,\"method\":\"decodetransaction\",\"jsonrpc\":\"2.0\",\"params\":{\"txdata\":\"010000003190f05d00000000701af4705c5e6fcb04efc3ca3c851c1e4d8948e10923025f54bea9b000000000017a792b71cdb0f662c802207d849e73c504b7a87096c6d80479605a2a9188f05d0001a4dce88fee73a59dcebf2b40ba1d13407254164b9166f063b2e8d513561118d620e4ab0900000000a0860100000000000040d6594d9215c58224f9707a84f773b00394561df0bba769a279dd065b98bc03a946928f8a6508a728eceff3e22d5181da16b78087c79b68532b31553bdc855000\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":1,\"jsonrpc\":\"2.0\",\"result\":{\"txid\":\"5df09031322f99db08a4747d652e0733f60c9b523a6a489b5f72e0031a2b2a03\",\"version\":1,\"type\":\"token\",\"time\":1576046641,\"lockuntil\":0,\"anchor\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\",\"vin\":[{\"txid\":\"5df088912a5a607904d8c69670a8b704c5739e847d2002c862f6b0cd712b797a\",\"vout\":0}],\"sendfrom\":\"1n56xmva8131c4q0961anv5wdzfqtdctyg9e53fxp65f1jyhbtkfbxz6q\",\"sendto\":\"1mkeeh3zeeejsvknz5d0bm78k81s585jbj5kf0rxjx3ah6ngh33b1erg9\",\"amount\":162.260000,\"txfee\":0.100000,\"data\":\"\",\"sig\":\"d6594d9215c58224f9707a84f773b00394561df0bba769a279dd065b98bc03a946928f8a6508a728eceff3e22d5181da16b78087c79b68532b31553bdc855000\",\"fork\":\"00000000b0a9be545f022309e148894d1e1c853ccac3ef04cb6f5e5c70f41a70\"}}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-8,\"message\":\"TX decode failed\"}\n";
	oss << "* {\"code\":-6,\"message\":\"Unknown anchor block\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// listunspent

// CListUnspentConfig
CListUnspentConfig::CListUnspentConfig()
{
	boost::program_options::options_description desc("CListUnspentConfig");

	AddOpt<string>(desc, "f");
	AddOpt<uint64>(desc, "n");
	AddOpt<string>(desc, "if");

	AddOptions(desc);
}
bool CListUnspentConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 5)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strAddress = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[address] is required");
	}
	if (vm.find("f") != vm.end())
	{
		auto value = vm["f"];
		strFork = value.as<string>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			strFork = *++it;
		}
	}
	if (vm.find("n") != vm.end())
	{
		auto value = vm["n"];
		nMax = value.as<uint64>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			istringstream iss(*++it);
			iss >> nMax;
			if (!iss.eof() || iss.fail())
				throw CRPCException(RPC_PARSE_ERROR, "[max] type error, needs uint");
		}
		else
		{
			nMax = 10;
		}
	}
	if (vm.find("if") != vm.end())
	{
		auto value = vm["if"];
		strFile = value.as<string>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			strFile = *++it;
		}
	}
	return true;
}
string CListUnspentConfig::ListConfig() const
{
	return "";
}
string CListUnspentConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        listunspent <\"address\"> (-f=\"fork\") (-n=max) (-if=\"file\")\n";
	oss << "\n";
	oss << "Return a JSON object listing unspent utxo by user specifying arguments address, fork(optional, main fork by default), maximum unspents(optional, 3 by default) and an input file containing list of multiple addresses(optional, plain text file name must be absolute path, one line only contains one wallet address with maximum of 10,000 lines). You may specify one wallet address in RPC command line with or without a text file name, core wallet will return all unspent utxos in a single batch operation.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"address\"                              (string, required) address to receive the unspent\n";
	oss << " -f=\"fork\"                              (string, optional) fork hash\n";
	oss << " -n=max                                 (uint, optional, default=10) maximum unspents(0 means unlimited)\n";
	oss << " -if=\"file\"                             (string, optional) input file containing list of multiple addresses\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"address\": \"\",                       (string, required) address to receive the unspent\n";
	oss << "   \"fork\": \"\",                          (string, optional) fork hash\n";
	oss << "   \"max\": 0,                            (uint, optional, default=10) maximum unspents(0 means unlimited)\n";
	oss << "   \"file\": \"\"                           (string, optional) input file containing list of multiple addresses\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\" :\n";
	oss << " {\n";
	oss << "   [\n";
	oss << "     \"addr\":                            (object, required) \n";
	oss << "     {\n";
	oss << "       \"address\": \"\",                   (string, required) address to list unspent\n";
	oss << "       [\n";
	oss << "         \"unspent\":                     (object, required) unspent data\n";
	oss << "         {\n";
	oss << "           \"txid\": \"\",                  (string, required) txid\n";
	oss << "           \"out\": 0,                    (uint, required) tx output point\n";
	oss << "           \"amount\": 0.0,               (double, required) amount\n";
	oss << "           \"time\": 0,                   (uint, required) time transaction made\n";
	oss << "           \"lockuntil\": 0               (uint, required) lockuntil\n";
	oss << "         }\n";
	oss << "       ]\n";
	oss << "       \"sum\": 0.0                       (double, required) sum of unspent amount\n";
	oss << "     }\n";
	oss << "   ]\n";
	oss << "   \"total\": 0.0                         (double, required) total of unspent amount for list of addresses\n";
	oss << " }\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli listunspent 1965p604xzdrffvg90ax9bk0q3xyqn5zz2vc9zpbe3wdswzazj7d144mm -f=00000000beb6f9e2a8813f4778b26820a8649894de63624e65bc0ffa9562730b -n=1\n";
	oss << "<< {\"unspents\":[{\"txid\":\"5dd4bb56b3d0aed9bb0e0a80d01ec1f70d7bd4d1fc200a48df330154b366ca8e\",\"out\":0,\"amount\":1000.000000,\"time\":1574222678,\"lockuntil\":0}],\"sum\":1000.000000}\n";
	oss << "\n>> mkf-cli listunspent 20g075m4mh5trbkdy8vbh74n9h7t3npe7tewpnvsfb19p57jnyf3kdh45 -if=/home/oijen/addr10\n";
	oss << "<< {\"addresses\":[{\"address\":\"1zbyhm9p0aa1wvebg3wch7xkhxsv5m9z32jsnjngpfnf7cgd778st8tds\",\"unspents\":[{\"txid\":\"5de8bcce65733bbcfff18130de6f3f10cfd46ce94aa4775070f1634777029401\",\"out\":0,\"amount\":340.999900,\"time\":1575533774,\"lockuntil\":0},{\"txid\":\"5e0423aadb07b4142abcf29e576e56d0eff594d5da18f6915155c1ece4c66309\",\"out\":0,\"amount\":11.999900,\"time\":1577329578,\"lockuntil\":0},{\"txid\":\"5df7b69db367bfc7a9b40fea36e2459f99e214db9505a44f9dfa9052e1d6f411\",\"out\":0,\"amount\":10.999900,\"time\":1576515229,\"lockuntil\":0}],\"sum\":363.999700},{\"address\":\"1z98n1sfbhtw3b5wrre69fh648e4res1g7r9bzcp0kf85hte75mv0zc01\",\"unspents\":[],\"sum\":0.000000},{\"address\":\"1tbvg7cxbqg36rph6ymws856ms4j5e4cvbd4ssy0ejxn1h869g9hfwv4c\",\"unspents\":[],\"sum\":0.000000},{\"address\":\"1j42adjfq37j9grmwsh4gnayfgg6kep59d78srpxg8zf8hdqv1yptjwzx\",\"unspents\":[{\"txid\":\"5df58dcccb52641f3b9c090ba5760181a3999370137cc6b5bbacc30b7b4b5909\",\"out\":0,\"amount\":499.999900,\"time\":1576373708,\"lockuntil\":0},{\"txid\":\"5df80dad00f53331757e19fae811308ec59d722ffb189958ecdb7cc4ad79b30d\",\"out\":0,\"amount\":499.999900,\"time\":1576537517,\"lockuntil\":0},{\"txid\":\"5df7a4344d2d887c929cf6d08bf825bfacc14d8c86cf62ab3944caa142bc6c0f\",\"out\":0,\"amount\":499.999900,\"time\":1576510516,\"lockuntil\":0}],\"sum\":1499.999700},{\"address\":\"1ztsgg3m6az2sm8t6ap6k3cw36z5ewd5sp05k7a62h6rqvpqp871aqpq6\",\"unspents\":[],\"sum\":0.000000},{\"address\":\"1ny00y8whrser450hfw3d87h1p3emdeca4fq5xetddwfz9mb4e38ndxx0\",\"unspents\":[],\"sum\":0.000000},{\"address\":\"1944eh1ysrjy1rgjyxcr9b0nvmbra2bmtm6v6kt1a3ag6wf07hfa0apgg\",\"unspents\":[],\"sum\":0.000000},{\"address\":\"1rjcyqyzsf1p8b22fxdx79qwfcr7wzkx1n2xykc5chzd905jymbfd8j4n\",\"unspents\":[{\"txid\":\"5df61f85cbe11a3ab7eedbc2929241aa10c27179ec0b4fef3cea9f803a9aad15\",\"out\":0,\"amount\":499.999900,\"time\":1576411013,\"lockuntil\":0},{\"txid\":\"5e04142090815b50bf1688e5cbd3ceca550c8f2ad6e44d690fb7a5f21b478227\",\"out\":0,\"amount\":499.999900,\"time\":1577325600,\"lockuntil\":0},{\"txid\":\"5dfa848c46ee3c4b3b468674433dad2b3d5531428e5b60ef3d827c020859f73a\",\"out\":0,\"amount\":499.999900,\"time\":1576699020,\"lockuntil\":0}],\"sum\":1499.999700},{\"address\":\"1jvy4ys1yrz3rg6te1h70mt0t89v9d0pbr038d48wmyzyzvrxk7safdg2\",\"unspents\":[],\"sum\":0.000000},{\"address\":\"1dq62d8y4fz20sfg63zzy4h4ayksswv1fgqjzvegde306bxxg5zygc27q\",\"unspents\":[{\"txid\":\"5df31decea3f149fe53062fbdbc8ca4e42d54e348f9e3c482a1edfb0c5b34100\",\"out\":0,\"amount\":499.999900,\"time\":1576213996,\"lockuntil\":0},{\"txid\":\"5df26e22ab57f87fa7f5ee931b09cdc550583ab7517afa18e5f68db1ee53fb02\",\"out\":0,\"amount\":499.999900,\"time\":1576168994,\"lockuntil\":0},{\"txid\":\"5df235df6a0d575378361ba75560ffab8ee9c786a58e604f14c037d7ec2afd05\",\"out\":0,\"amount\":499.999900,\"time\":1576154591,\"lockuntil\":0}],\"sum\":1499.999700},{\"address\":\"20g075m4mh5trbkdy8vbh74n9h7t3npe7tewpnvsfb19p57jnyf3kdh45\",\"unspents\":[{\"txid\":\"5e032143eb0c23c13f2d422144f1337ecd467c2163c7758e5a00b4d6fbe7ba00\",\"out\":0,\"amount\":1153.000000,\"time\":1577263427,\"lockuntil\":0},{\"txid\":\"5e046a5cae5ea2622a37ad737f53e9185b60ea010242191b75f276b8d50dc900\",\"out\":0,\"amount\":1153.000000,\"time\":1577347676,\"lockuntil\":0},{\"txid\":\"5e0399615cb69be399d6b6fee2bc1aca10d9d4e222467f9eef76745334b8ad01\",\"out\":0,\"amount\":1153.000000,\"time\":1577294177,\"lockuntil\":0}],\"sum\":3459.000000}],\"total\":8322.998800}\n";
	oss << "\n>> curl -d '{\"id\":0,\"method\":\"listunspent\",\"jsonrpc\":\"2.0\",\"params\":{\"address\":\"1965p604xzdrffvg90ax9bk0q3xyqn5zz2vc9zpbe3wdswzazj7d144mm\",\"fork\":\"00000000beb6f9e2a8813f4778b26820a8649894de63624e65bc0ffa9562730b\",\"max\":1}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":0,\"jsonrpc\":\"2.0\",\"result\":{\"unspents\":[{\"txid\":\"5dd4bb56b3d0aed9bb0e0a80d01ec1f70d7bd4d1fc200a48df330154b366ca8e\",\"out\":0,\"amount\":1000.000000,\"time\":1574222678,\"lockuntil\":0}],\"sum\":1000.000000}}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-401,\"message\":\"Address as an argument should be provided.\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Acquiring unspent list failed.\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// getwork

// CGetWorkConfig
CGetWorkConfig::CGetWorkConfig()
{
}
bool CGetWorkConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 4)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strSpent = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[spent] is required");
	}
	if (next(it, 1) != vecCommand.end())
	{
		strPrivkey = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[privkey] is required");
	}
	if (next(it, 1) != vecCommand.end())
	{
		strPrev = *++it;
	}
	return true;
}
string CGetWorkConfig::ListConfig() const
{
	return "";
}
string CGetWorkConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        getwork <\"spent\"> <\"privkey\"> (\"prev\")\n";
	oss << "\n";
	oss << "If (prev hash) is matched with the current primary chain,return true\n"
	       "If next block is not generated by proof-of-work,return false\n"
	       "Otherwise, return formatted proof-of-work parameters to work on:\n"
	       "\"prevblockheight\" : prevblock height\n"
	       "\"prevblockhash\" : prevblock hash\n"
	       "\"prevblocktime\" : prevblock timestamp\n"
	       "\"algo\" : proof-of-work algorithm: cryptonight=1,...\n"
	       "\"bits\" : proof-of-work difficulty nbits\n"
	       "\"data\" : work data\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"spent\"                                (string, required) spent address\n";
	oss << " \"privkey\"                              (string, required) private key\n";
	oss << " \"prev\"                                 (string, optional) prev block hash\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"spent\": \"\",                         (string, required) spent address\n";
	oss << "   \"privkey\": \"\",                       (string, required) private key\n";
	oss << "   \"prev\": \"\"                           (string, optional) prev block hash\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\" :\n";
	oss << " {\n";
	oss << "   (if prev is matched or block is not generated by POW)\n";
	oss << "   \"result\": true|false,                (bool, optional) result\n";
	oss << "   (if next block is generated by POW)\n";
	oss << "   \"work\":                              (object, optional) work data\n";
	oss << "   {\n";
	oss << "     \"prevblockheight\": 0,              (int, required) prev block height\n";
	oss << "     \"prevblockhash\": \"\",               (string, required) prev block hash\n";
	oss << "     \"prevblocktime\": 0,                (uint, required) prev block time\n";
	oss << "     \"algo\": 0,                         (int, required) algo\n";
	oss << "     \"bits\": \"\",                        (string, required) bits\n";
	oss << "     \"data\": \"\"                         (string, required) work data\n";
	oss << "   }\n";
	oss << " }\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli getwork 1pdr1knaaa4fzr846v89g3q2tzb8pbvbavbbft8xppkky0mqnmsq8gn5y ceae964a1119f110b0cff3614426dd692f8467a95cc2c276e523efc63c5e5031 7ee748e9a827d476d1b4ddb77dc8f9bad779f7b71593d5c5bf73b535e1cc2446\n";
	oss << "<< {\"work\":{\"prevblockheight\":23,\"prevblockhash\":\"f734bb6bc12ab4058532113cfe6a3412d1036eae25f60a97ee1b17effc6e74de\",\"prevblocktime\":1538142032,\"algo\":1,\"bits\":25,\"data\":\"01000100822fae5bde746efcef171bee970af625ae6e03d112346afe3c11328505b42ac16bbb34f74300000000000000000000000000000000000000000000000000000000000000000001190000000000000000000000000000000000000000000000000000000000000000\"}}\n";
	oss << "\n>> curl -d '{\"id\":1,\"method\":\"getwork\",\"jsonrpc\":\"2.0\",\"params\":{\"spent\":\"1pdr1knaaa4fzr846v89g3q2tzb8pbvbavbbft8xppkky0mqnmsq8gn5y\",\"privkey\":\"ceae964a1119f110b0cff3614426dd692f8467a95cc2c276e523efc63c5e5031\",\"prev\":\"7ee748e9a827d476d1b4ddb77dc8f9bad779f7b71593d5c5bf73b535e1cc2446\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":1,\"jsonrpc\":\"2.0\",\"result\":{\"work\":{\"prevblockheight\":23,\"prevblockhash\":\"f734bb6bc12ab4058532113cfe6a3412d1036eae25f60a97ee1b17effc6e74de\",\"prevblocktime\":1538142032,\"algo\":1,\"bits\":25,\"data\":\"01000100822fae5bde746efcef171bee970af625ae6e03d112346afe3c11328505b42ac16bbb34f74300000000000000000000000000000000000000000000000000000000000000000001190000000000000000000000000000000000000000000000000000000000000000\"}}}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\" : -32603, \"message\" : \"The primary chain is invalid.\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// submitwork

// CSubmitWorkConfig
CSubmitWorkConfig::CSubmitWorkConfig()
{
}
bool CSubmitWorkConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 4)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strData = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[data] is required");
	}
	if (next(it, 1) != vecCommand.end())
	{
		strSpent = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[spent] is required");
	}
	if (next(it, 1) != vecCommand.end())
	{
		strPrivkey = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[privkey] is required");
	}
	return true;
}
string CSubmitWorkConfig::ListConfig() const
{
	return "";
}
string CSubmitWorkConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        submitwork <\"data\"> <\"spent\"> <\"privkey\">\n";
	oss << "\n";
	oss << "Attempt to construct and submit new block to network\n"
	       "Return hash of new block.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"data\"                                 (string, required) work data\n";
	oss << " \"spent\"                                (string, required) spent address\n";
	oss << " \"privkey\"                              (string, required) private key\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"data\": \"\",                          (string, required) work data\n";
	oss << "   \"spent\": \"\",                         (string, required) spent address\n";
	oss << "   \"privkey\": \"\"                        (string, required) private key\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"hash\"                       (string, required) block hash\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli submitwork 01000100502fae5b4624cce135b573bfc5d59315b7f779d7baf9c87db7ddb4d176d427a8e948e77e43000000000000000000000000000000000000000000000000000000000000000000011acfff020000000000000000000000000000000000000000000000000000000000 1dj5qcjst7eh4tems36n1m500hhyba3vx436t4a8hgdm7r7jrdbf2yqp9 41a9f94395ced97d5066e2d099df4f1e2bd96057f9c38e8ea3f8a02eccd0a98e\n";
	oss << "<< f734bb6bc12ab4058532113cfe6a3412d1036eae25f60a97ee1b17effc6e74de\n";
	oss << "\n>> curl -d '{\"id\":2,\"method\":\"submitwork\",\"jsonrpc\":\"2.0\",\"params\":{\"data\":\"01000100502fae5b4624cce135b573bfc5d59315b7f779d7baf9c87db7ddb4d176d427a8e948e77e43000000000000000000000000000000000000000000000000000000000000000000011acfff020000000000000000000000000000000000000000000000000000000000\",\"spent\":\"1dj5qcjst7eh4tems36n1m500hhyba3vx436t4a8hgdm7r7jrdbf2yqp9\",\"privkey\":\"41a9f94395ced97d5066e2d099df4f1e2bd96057f9c38e8ea3f8a02eccd0a98e\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":2,\"jsonrpc\":\"2.0\",\"result\":\"f734bb6bc12ab4058532113cfe6a3412d1036eae25f60a97ee1b17effc6e74de\"}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\" : -4, \"message\" : \"Invalid spent address\"}\n";
	oss << "* {\"code\" : -4, \"message\" : \"Invalid private key\"}\n";
	oss << "* {\"code\" : -4, \"message\" : \"Invalid mint template\"}\n";
	oss << "* {\"code\" : -6, \"message\" : \"Block rejected : operation failed\"}\n";
	oss << "* {\"code\" : -6, \"message\" : \"Block rejected : block proof-of-work is invalid\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// querystat

// CQueryStatConfig
CQueryStatConfig::CQueryStatConfig()
{
	boost::program_options::options_description desc("CQueryStatConfig");

	AddOpt<string>(desc, "f");
	AddOpt<string>(desc, "b");
	AddOpt<uint64>(desc, "n");

	AddOptions(desc);
}
bool CQueryStatConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 5)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strType = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[type] is required");
	}
	if (vm.find("f") != vm.end())
	{
		auto value = vm["f"];
		strFork = value.as<string>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			strFork = *++it;
		}
	}
	if (vm.find("b") != vm.end())
	{
		auto value = vm["b"];
		strBegin = value.as<string>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			strBegin = *++it;
		}
	}
	if (vm.find("n") != vm.end())
	{
		auto value = vm["n"];
		nCount = value.as<uint64>();
	}
	else
	{
		if (next(it, 1) != vecCommand.end())
		{
			istringstream iss(*++it);
			iss >> nCount;
			if (!iss.eof() || iss.fail())
				throw CRPCException(RPC_PARSE_ERROR, "[count] type error, needs uint");
		}
	}
	return true;
}
string CQueryStatConfig::ListConfig() const
{
	return "";
}
string CQueryStatConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        querystat <\"type\"> (-f=\"fork\") (-b=\"begin\") (-n=count)\n";
	oss << "\n";
	oss << "Query statistical data\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"type\"                                 (string, required) statistical type: maker: block maker, p2psyn: p2p synchronization\n";
	oss << " -f=\"fork\"                              (string, optional) fork hash (default all fork)\n";
	oss << " -b=\"begin\"                             (string, optional) begin time(HH:MM:SS) (default last count records)\n";
	oss << " -n=count                               (uint, optional) get record count (default 20)\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"type\": \"\",                          (string, required) statistical type: maker: block maker, p2psyn: p2p synchronization\n";
	oss << "   \"fork\": \"\",                          (string, optional) fork hash (default all fork)\n";
	oss << "   \"begin\": \"\",                         (string, optional) begin time(HH:MM:SS) (default last count records)\n";
	oss << "   \"count\": 0                           (uint, optional) get record count (default 20)\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"stattable\"                  (string, required) statistical data table\n"
	       "                                        1) maker: block maker\n"
	       "                                        -- time: statistical time, format: hh:mm:ss\n"
	       "                                        -- powblocks: number of POW blocks produced in one minute\n"
	       "                                        -- dposblocks: number of DPOS blocks produced in one minute\n"
	       "                                        -- tps: number of TX produced in one second\n"
	       "                                        2) p2psyn: p2p synchronization\n"
	       "                                        -- time: statistical time, format: hh:mm:ss\n"
	       "                                        -- recvblocks: number of synchronized receiving blocks in one minute\n"
	       "                                        -- recvtps: number of synchronized receiving TX in one second\n"
	       "                                        -- sendblocks: number of synchronized sending blocks in one minute\n"
	       "                                        -- sendtps: number of synchronized sending TX in one second\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli querystat maker -b=09:11:00 -n=2\n";
	oss << "<< time      blocktps  tps  \r\n09:11:59  1       12     \r\n09:12:59  1       22     \n";
	oss << "\n>> curl -d '{\"id\":1,\"method\":\"querystat\",\"jsonrpc\":\"2.0\",\"params\":{\"type\":\"maker\",\"begin\":\"09:11:00\",\"count\":2}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":0,\"jsonrpc\":\"2.0\",\"result\":\"time      blocktps  tps  \r\n09:11:59  1       12     \r\n09:12:59  1       22     \"}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\" : -6, \"message\" : \"Invalid type: is empty\"}\n";
	oss << "* {\"code\" : -6, \"message\" : \"Invalid type\"}\n";
	oss << "* {\"code\" : -6, \"message\" : \"Invalid fork\"}\n";
	oss << "* {\"code\" : -6, \"message\" : \"Invalid count\"}\n";
	oss << "* {\"code\" : -32603, \"message\" : \"query error\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// signrawtransactionwithwallet

// CSignRawTransactionWithWalletConfig
CSignRawTransactionWithWalletConfig::CSignRawTransactionWithWalletConfig()
{
}
bool CSignRawTransactionWithWalletConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 3)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strAddrin = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[addrIn] is required");
	}
	if (next(it, 1) != vecCommand.end())
	{
		strTxdata = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[txdata] is required");
	}
	return true;
}
string CSignRawTransactionWithWalletConfig::ListConfig() const
{
	return "";
}
string CSignRawTransactionWithWalletConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        signrawtransactionwithwallet <\"addrIn\"> <\"txdata\">\n";
	oss << "\n";
	oss << "Return json object with keys:\n"
	       "hex : raw transaction with signature(s) (hex-encoded string)\n"
	       "completed : true if transaction has a completed set of signature (false if not)\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"addrIn\"                               (string, required) hex address string of pubkey or templateid used to sign offline transaction\n";
	oss << " \"txdata\"                               (string, required) raw transaction data(hex string)\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"addrIn\": \"\",                        (string, required) hex address string of pubkey or templateid used to sign offline transaction\n";
	oss << "   \"txdata\": \"\"                         (string, required) raw transaction data(hex string)\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\" :\n";
	oss << " {\n";
	oss << "   \"hex\": \"\",                           (string, required) hex of transaction data\n";
	oss << "   \"completed\": true|false              (bool, required) transaction completed or not\n";
	oss << " }\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli signrawtransactionwithwallet 20m0fetg8ypthr01xxyxmdxbr27bt0fp8j151d321w72ht9ywfkzxxnf5 01000000e0d2cc5e0000000091d2b15e9aeeb57483889873bd0aea1273c8e5bb8df436c2bd4e8506000000000195a751b8eaef2e9a2337be86b4e892e15d723ff992501c82c5a6d2aa7bcbcc5e010139d9d6ac592bb962578d52aac4b0755e5fd59d2d10bb20914896047741205f57c0cf6a000000000010270000000000000000\n";
	oss << "<< {\"hex\":\"01000000e0d2cc5e0000000091d2b15e9aeeb57483889873bd0aea1273c8e5bb8df436c2bd4e8506000000000195a751b8eaef2e9a2337be86b4e892e15d723ff992501c82c5a6d2aa7bcbcc5e010139d9d6ac592bb962578d52aac4b0755e5fd59d2d10bb20914896047741205f57c0cf6a0000000000102700000000000000ee75b03705c7e9f66feed2338df515ee8826ff991258d0f9786203ce2d3445958d0202004bb6c84b2311f42905ea3749fe0ea2ae2ed79c950daa53d1dd899e99622c02030000000000000013f64ef0eb65bd1846bbe2835937868e8f76cc6ec1d15c18bfe41b5d6b38b3b5014eb8d334d9a93c1c51c31d300050fdf5fa8b9f6029af7354331b87a2300ec2c90106587926a76ffed40f884b39396fdbe4c0ca0a72e6499caecd130073117da5fb01014b4b4efd5425e102e7d13b089bb1c5387c877a4bd147251ad241a21246a443a9e46b18b24d8ae6a22faf6d6c79f3acd014e17f79491f42dd0f5d001d4a294b08\",\"completed\":false}\n";
	oss << "\n>> curl -d '{\"id\":62,\"method\":\"signrawtransactionwithwallet\",\"jsonrpc\":\"2.0\",\"params\":{\"addrIn\":\"20m0fetg8ypthr01xxyxmdxbr27bt0fp8j151d321w72ht9ywfkzxxnf5\",\"txdata\":\"01000000000000002b747e24738befccff4a05c21dba749632cb8eb410233fa110e3f58a779b4325010ef45be50157453a57519929052d0818c269dee60be98958d5ab65bc7e0919810001b9c3b7aa16c6cb1bf193faf717580d03347148b2145ca98b30b1376d634c12f440420f0000000000a08601000000000002123400\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":62,\"jsonrpc\":\"2.0\",\"result\":{\"hex\":\"01000000e0d2cc5e0000000091d2b15e9aeeb57483889873bd0aea1273c8e5bb8df436c2bd4e8506000000000195a751b8eaef2e9a2337be86b4e892e15d723ff992501c82c5a6d2aa7bcbcc5e010139d9d6ac592bb962578d52aac4b0755e5fd59d2d10bb20914896047741205f57c0cf6a0000000000102700000000000000fd2e0175b03705c7e9f66feed2338df515ee8826ff991258d0f9786203ce2d3445958d0202004bb6c84b2311f42905ea3749fe0ea2ae2ed79c950daa53d1dd899e99622c02030000000000000013f64ef0eb65bd1846bbe2835937868e8f76cc6ec1d15c18bfe41b5d6b38b3b5014eb8d334d9a93c1c51c31d300050fdf5fa8b9f6029af7354331b87a2300ec2c90106587926a76ffed40f884b39396fdbe4c0ca0a72e6499caecd130073117da5fb01054b4b4efd5425e102e7d13b089bb1c5387c877a4bd147251ad241a21246a443a9e46b18b24d8ae6a22faf6d6c79f3acd014e17f79491f42dd0f5d001d4a294b087f54c5679e286e77d07c6f9df1e3084daab9bb8accd5725b9146c4fe99f645c177e4d0079dacca1d85afb4f70044eb64e803054dbe150d7c4e6bb5c2bcc78007\",\"completed\":true}}\n";
	oss << "\n>> mkf-cli signrawtransactionwithwallet 16g92n3v2p04htxgck0r3awk878d9x7gx60kp3wmc47wwdp6b491pxa9x 0100000065d5cc5e0000000091d2b15e9aeeb57483889873bd0aea1273c8e5bb8df436c2bd4e85060000000001a4df918abd7a55a7296e22b6dbfd1be7fd09651003387456fa59d3d11f96cc5e010139d9d6ac592bb962578d52aac4b0755e5fd59d2d10bb20914896047741205f5720aa44000000000010270000000000000000\n";
	oss << "<< {\"hex\":\"0100000065d5cc5e0000000091d2b15e9aeeb57483889873bd0aea1273c8e5bb8df436c2bd4e85060000000001a4df918abd7a55a7296e22b6dbfd1be7fd09651003387456fa59d3d11f96cc5e010139d9d6ac592bb962578d52aac4b0755e5fd59d2d10bb20914896047741205f5720aa44000000000010270000000000000040844cfb574ada0ea0c37a76042c25b7fc82756deefc8a6150ef5babb54bf1ab3de3eba03cc3bc7ab74051ca5986ed83c2286fbcf0ab120ec4491425cef0d25502\",\"completed\":true}\n";
	oss << "\n>> curl -d '{\"id\":62,\"method\":\"signrawtransactionwithwallet\",\"jsonrpc\":\"2.0\",\"params\":{\"addrIn\":\"16g92n3v2p04htxgck0r3awk878d9x7gx60kp3wmc47wwdp6b491pxa9x\",\"txdata\":\"0100000065d5cc5e0000000091d2b15e9aeeb57483889873bd0aea1273c8e5bb8df436c2bd4e85060000000001a4df918abd7a55a7296e22b6dbfd1be7fd09651003387456fa59d3d11f96cc5e010139d9d6ac592bb962578d52aac4b0755e5fd59d2d10bb20914896047741205f5720aa44000000000010270000000000000000\"}}' http://127.0.0.1:9902\n";
	oss << "<< {\"id\":62,\"jsonrpc\":\"2.0\",\"result\":{\"hex\":\"0100000065d5cc5e0000000091d2b15e9aeeb57483889873bd0aea1273c8e5bb8df436c2bd4e85060000000001a4df918abd7a55a7296e22b6dbfd1be7fd09651003387456fa59d3d11f96cc5e010139d9d6ac592bb962578d52aac4b0755e5fd59d2d10bb20914896047741205f5720aa44000000000010270000000000000040844cfb574ada0ea0c37a76042c25b7fc82756deefc8a6150ef5babb54bf1ab3de3eba03cc3bc7ab74051ca5986ed83c2286fbcf0ab120ec4491425cef0d25502\",\"completed\":true}}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-8,\"message\":\"TX decode failed\"}\n";
	oss << "* {\"code\":-401,\"message\":\"Failed to sign offline transaction\"}\n";
	oss << "\n";
	return oss.str();
}

/////////////////////////////////////////////////////
// sendrawtransaction

// CSendRawTransactionConfig
CSendRawTransactionConfig::CSendRawTransactionConfig()
{
}
bool CSendRawTransactionConfig::PostLoad()
{
	if (fHelp)
	{
		return true;
	}

	if (vecCommand.size() > 2)
	{
		throw CRPCException(RPC_PARSE_ERROR, string("too arguments given."));
	}
	auto it = vecCommand.begin(); 
(void)it;
	if (next(it, 1) != vecCommand.end())
	{
		strTxdata = *++it;
	}
	else
	{
		throw CRPCException(RPC_PARSE_ERROR, "[txdata] is required");
	}
	return true;
}
string CSendRawTransactionConfig::ListConfig() const
{
	return "";
}
string CSendRawTransactionConfig::Help() const
{
	std::ostringstream oss;
	oss << "\nUsage:\n";
	oss << "        sendrawtransaction <\"txdata\">\n";
	oss << "\n";
	oss << "Submit transaction raw data(serialized, hex-encoded) with offline signature using pubkey or template address.\n";
	oss << "\n";
	oss << "Arguments:\n";
	oss << " \"txdata\"                               (string, required) hex string of transaction binary data\n";
	oss << "\n";
	oss << "Request:\n";
	oss << " \"param\" :\n";
	oss << " {\n";
	oss << "   \"txdata\": \"\"                         (string, required) hex string of transaction binary data\n";
	oss << " }\n";
	oss << "\n";
	oss << "Response:\n";
	oss << " \"result\": \"data\"                       (string, required) txid: hash of transaction raw data\n";
	oss << "\n";
	oss << "Examples:\n";
	oss << ">> mkf-cli sendrawtransaction 01000000e0d2cc5e0000000091d2b15e9aeeb57483889873bd0aea1273c8e5bb8df436c2bd4e8506000000000195a751b8eaef2e9a2337be86b4e892e15d723ff992501c82c5a6d2aa7bcbcc5e010139d9d6ac592bb962578d52aac4b0755e5fd59d2d10bb20914896047741205f57c0cf6a0000000000102700000000000000fd2e0175b03705c7e9f66feed2338df515ee8826ff991258d0f9786203ce2d3445958d0202004bb6c84b2311f42905ea3749fe0ea2ae2ed79c950daa53d1dd899e99622c02030000000000000013f64ef0eb65bd1846bbe2835937868e8f76cc6ec1d15c18bfe41b5d6b38b3b5014eb8d334d9a93c1c51c31d300050fdf5fa8b9f6029af7354331b87a2300ec2c90106587926a76ffed40f884b39396fdbe4c0ca0a72e6499caecd130073117da5fb01054b4b4efd5425e102e7d13b089bb1c5387c877a4bd147251ad241a21246a443a9e46b18b24d8ae6a22faf6d6c79f3acd014e17f79491f42dd0f5d001d4a294b087f54c5679e286e77d07c6f9df1e3084daab9bb8accd5725b9146c4fe99f645c177e4d0079dacca1d85afb4f70044eb64e803054dbe150d7c4e6bb5c2bcc78007\n";
	oss << "<< 5eccd2e09fe34ae041d9a90d896759041b2bc2844f43ed6929889b53e826386b\n";
	oss << "\n>> curl -d '{\"id\":3,\"method\":\"sendrawtransaction\",\"jsonrpc\":\"2.0\",\"params\":{\"txdata\":\"0100000065d5cc5e0000000091d2b15e9aeeb57483889873bd0aea1273c8e5bb8df436c2bd4e85060000000001a4df918abd7a55a7296e22b6dbfd1be7fd09651003387456fa59d3d11f96cc5e010139d9d6ac592bb962578d52aac4b0755e5fd59d2d10bb20914896047741205f5720aa44000000000010270000000000000040844cfb574ada0ea0c37a76042c25b7fc82756deefc8a6150ef5babb54bf1ab3de3eba03cc3bc7ab74051ca5986ed83c2286fbcf0ab120ec4491425cef0d25502\"}}' http://127.0.0.1:19902\n";
	oss << "<< {\"id\":3,\"jsonrpc\":\"2.0\",\"result\":\"5eccd565e410131217f89ade75e3f89a5a17627edaa7da7638babc94e331ea49\"}\n";
	oss << "\n";
	oss << "Errors:\n";
	oss << "* {\"code\":-8,\"message\":\"Raw tx decode failed\"}\n";
	oss << "* {\"code\":-10,\"message\":\"Tx rejected : xxx\"}\n";
	oss << "\n";
	return oss.str();
}

std::string RPCHelpInfo(EModeType type, const std::string& subCmd, const std::string& options)
{
	std::ostringstream oss;
	if (type == EModeType::SERVER)
	{
		oss << "\nUsage:\n";
		oss << "        mkf-server (OPTIONS)\n";
		oss << "\n";
		oss << "Run mkf server\n";
		oss << "\n";
		oss << "Options:\n";
		oss << options << "\n";
	}
	else if (type == EModeType::CONSOLE)
	{
		if (subCmd.empty())
		{
			if (!options.empty())
			{
				oss << "\nUsage:\n";
				oss << "        mkf-cli (OPTIONS) COMMAND\n";
				oss << "\n";
				oss << "Run mkf RPC client\n";
				oss << "\n";
				oss << "Options:\n";
				oss << options << "\n";
			}
			oss << "Commands:\n";
			oss << "  help                                  List commands, or get help for a command.\n";
			oss << "  stop                                  Stop bigbang server.\n";
			oss << "  version                               Get bigbang server version.\n";
			oss << "  getpeercount                          Return the number of connections to other nodes.\n";
			oss << "  listpeer                              Return data about each connected network node.\n";
			oss << "  addnode                               Attempt to add a node into the addnode list.\n";
			oss << "  removenode                            Attempt to remove a node from the addnode list.\n";
			oss << "  getforkcount                          Return the number of forks.\n";
			oss << "  listfork                              If true, list of all forks, or subscribed forks\n";
			oss << "  getgenealogy                          Return the list of ancestry and subline.\n";
			oss << "  getblocklocation                      Return the location with given block.\n";
			oss << "  getblockcount                         Return the number of blocks in the given fork, includes extended block and vacant block\n";
			oss << "  getblockhash                          Return a list of block hash in the fork at a specific height.\n";
			oss << "  getblock                              Return details of a block with given block-hash.\n";
			oss << "  getblockdetail                        Return details of a block with given block-hash.\n";
			oss << "  gettxpool                             Get transaction pool information\n";
			oss << "  gettransaction                        Get transaction information\n";
			oss << "  sendtransaction                       Submit raw transaction (serialized, hex-encoded) to local node and network.\n";
			oss << "  getforkheight                         Return the number of height in the given fork.\n";
			oss << "  listkey                               Return Object that has pubkey as keys, associated status as values.\n";
			oss << "  getnewkey                             Return a new pubkey for receiving payments.\n";
			oss << "  encryptkey                            Changes the passphrase for <oldpassphrase> to <passphrase>\n";
			oss << "  lockkey                               Removes the encryption key from memory, locking the key.\n";
			oss << "  unlockkey                             Unlock the key.\n";
			oss << "  importprivkey                         Add a private key to your wallet.\n";
			oss << "  importpubkey                          Add a public key to your wallet.\n";
			oss << "  importkey                             Reveal the serialized key corresponding to <pubkey>.\n";
			oss << "  exportkey                             Reveal the serialized key corresponding to <pubkey>.\n";
			oss << "  addnewtemplate                        Return encoded address for the given template id.\n";
			oss << "  importtemplate                        Return encoded address for the given template.\n";
			oss << "  exporttemplate                        Return encoded address for the given template.\n";
			oss << "  validateaddress                       Return information about <address>.\n";
			oss << "  resyncwallet                          Resync wallet's transactions.\n";
			oss << "  getbalance                            Get balance of an address.\n";
			oss << "  listtransaction                       Return transactions list.\n";
			oss << "  sendfrom                              Send a transaction.\n";
			oss << "  createtransaction                     Create a transaction.\n";
			oss << "  signtransaction                       Sign a transaction.\n";
			oss << "  signmessage                           Sign a message with the private key of an pubkey\n";
			oss << "  listaddress                           List all of the addresses from pub keys and template ids\n";
			oss << "  exportwallet                          Export all of keys and templates from wallet to a specified file in JSON format.\n";
			oss << "  importwallet                          Import keys and templates from an archived file to the wallet in JSON format.\n";
			oss << "  verifymessage                         Verify a signed message\n";
			oss << "  makekeypair                           Make a public/private key pair.\n";
			oss << "  getpubkeyaddress                      Return encoded address for the given public key.\n";
			oss << "  gettemplateaddress                    Return encoded address for the given template id.\n";
			oss << "  maketemplate                          Return encoded address for the given template id.\n";
			oss << "  decodetransaction                     Return a JSON object representing the serialized, hex-encoded transaction.\n";
			oss << "  listunspent                           Return a JSON object listing unspent utxo by user specifying arguments address, fork(optional, main fork by default), maximum unspents(optional, 3 by default) and an input file containing list of multiple addresses(optional, plain text file name must be absolute path, one line only contains one wallet address with maximum of 10,000 lines). You may specify one wallet address in RPC command line with or without a text file name, core wallet will return all unspent utxos in a single batch operation.\n";
			oss << "  getwork                               Get mint work\n";
			oss << "  submitwork                            Submit mint work\n";
			oss << "  querystat                             Query statistical data\n";
			oss << "  signrawtransactionwithwallet          Sign a transaction offline.\n";
			oss << "  sendrawtransaction                    Submit transaction raw data(serialized, hex-encoded) with offline signature using pubkey or template address.\n";
		}
		if (subCmd == "all" || subCmd == "help")
		{
			oss << CHelpConfig().Help();
		}
		if (subCmd == "all" || subCmd == "stop")
		{
			oss << CStopConfig().Help();
		}
		if (subCmd == "all" || subCmd == "version")
		{
			oss << CVersionConfig().Help();
		}
		if (subCmd == "all" || subCmd == "getpeercount")
		{
			oss << CGetPeerCountConfig().Help();
		}
		if (subCmd == "all" || subCmd == "listpeer")
		{
			oss << CListPeerConfig().Help();
		}
		if (subCmd == "all" || subCmd == "addnode")
		{
			oss << CAddNodeConfig().Help();
		}
		if (subCmd == "all" || subCmd == "removenode")
		{
			oss << CRemoveNodeConfig().Help();
		}
		if (subCmd == "all" || subCmd == "getforkcount")
		{
			oss << CGetForkCountConfig().Help();
		}
		if (subCmd == "all" || subCmd == "listfork")
		{
			oss << CListForkConfig().Help();
		}
		if (subCmd == "all" || subCmd == "getgenealogy")
		{
			oss << CGetGenealogyConfig().Help();
		}
		if (subCmd == "all" || subCmd == "getblocklocation")
		{
			oss << CGetBlockLocationConfig().Help();
		}
		if (subCmd == "all" || subCmd == "getblockcount")
		{
			oss << CGetBlockCountConfig().Help();
		}
		if (subCmd == "all" || subCmd == "getblockhash")
		{
			oss << CGetBlockHashConfig().Help();
		}
		if (subCmd == "all" || subCmd == "getblock")
		{
			oss << CGetBlockConfig().Help();
		}
		if (subCmd == "all" || subCmd == "getblockdetail")
		{
			oss << CgetblockdetailConfig().Help();
		}
		if (subCmd == "all" || subCmd == "gettxpool")
		{
			oss << CGetTxPoolConfig().Help();
		}
		if (subCmd == "all" || subCmd == "gettransaction")
		{
			oss << CGetTransactionConfig().Help();
		}
		if (subCmd == "all" || subCmd == "sendtransaction")
		{
			oss << CSendTransactionConfig().Help();
		}
		if (subCmd == "all" || subCmd == "getforkheight")
		{
			oss << CGetForkHeightConfig().Help();
		}
		if (subCmd == "all" || subCmd == "listkey")
		{
			oss << CListKeyConfig().Help();
		}
		if (subCmd == "all" || subCmd == "getnewkey")
		{
			oss << CGetNewKeyConfig().Help();
		}
		if (subCmd == "all" || subCmd == "encryptkey")
		{
			oss << CEncryptKeyConfig().Help();
		}
		if (subCmd == "all" || subCmd == "lockkey")
		{
			oss << CLockKeyConfig().Help();
		}
		if (subCmd == "all" || subCmd == "unlockkey")
		{
			oss << CUnlockKeyConfig().Help();
		}
		if (subCmd == "all" || subCmd == "importprivkey")
		{
			oss << CImportPrivKeyConfig().Help();
		}
		if (subCmd == "all" || subCmd == "importpubkey")
		{
			oss << CImportPubKeyConfig().Help();
		}
		if (subCmd == "all" || subCmd == "importkey")
		{
			oss << CImportKeyConfig().Help();
		}
		if (subCmd == "all" || subCmd == "exportkey")
		{
			oss << CExportKeyConfig().Help();
		}
		if (subCmd == "all" || subCmd == "addnewtemplate")
		{
			oss << CAddNewTemplateConfig().Help();
		}
		if (subCmd == "all" || subCmd == "importtemplate")
		{
			oss << CImportTemplateConfig().Help();
		}
		if (subCmd == "all" || subCmd == "exporttemplate")
		{
			oss << CExportTemplateConfig().Help();
		}
		if (subCmd == "all" || subCmd == "validateaddress")
		{
			oss << CValidateAddressConfig().Help();
		}
		if (subCmd == "all" || subCmd == "resyncwallet")
		{
			oss << CResyncWalletConfig().Help();
		}
		if (subCmd == "all" || subCmd == "getbalance")
		{
			oss << CGetBalanceConfig().Help();
		}
		if (subCmd == "all" || subCmd == "listtransaction")
		{
			oss << CListTransactionConfig().Help();
		}
		if (subCmd == "all" || subCmd == "sendfrom")
		{
			oss << CSendFromConfig().Help();
		}
		if (subCmd == "all" || subCmd == "createtransaction")
		{
			oss << CCreateTransactionConfig().Help();
		}
		if (subCmd == "all" || subCmd == "signtransaction")
		{
			oss << CSignTransactionConfig().Help();
		}
		if (subCmd == "all" || subCmd == "signmessage")
		{
			oss << CSignMessageConfig().Help();
		}
		if (subCmd == "all" || subCmd == "listaddress")
		{
			oss << CListAddressConfig().Help();
		}
		if (subCmd == "all" || subCmd == "exportwallet")
		{
			oss << CExportWalletConfig().Help();
		}
		if (subCmd == "all" || subCmd == "importwallet")
		{
			oss << CImportWalletConfig().Help();
		}
		if (subCmd == "all" || subCmd == "verifymessage")
		{
			oss << CVerifyMessageConfig().Help();
		}
		if (subCmd == "all" || subCmd == "makekeypair")
		{
			oss << CMakeKeyPairConfig().Help();
		}
		if (subCmd == "all" || subCmd == "getpubkeyaddress")
		{
			oss << CGetPubkeyAddressConfig().Help();
		}
		if (subCmd == "all" || subCmd == "gettemplateaddress")
		{
			oss << CGetTemplateAddressConfig().Help();
		}
		if (subCmd == "all" || subCmd == "maketemplate")
		{
			oss << CMakeTemplateConfig().Help();
		}
		if (subCmd == "all" || subCmd == "decodetransaction")
		{
			oss << CDecodeTransactionConfig().Help();
		}
		if (subCmd == "all" || subCmd == "listunspent")
		{
			oss << CListUnspentConfig().Help();
		}
		if (subCmd == "all" || subCmd == "getwork")
		{
			oss << CGetWorkConfig().Help();
		}
		if (subCmd == "all" || subCmd == "submitwork")
		{
			oss << CSubmitWorkConfig().Help();
		}
		if (subCmd == "all" || subCmd == "querystat")
		{
			oss << CQueryStatConfig().Help();
		}
		if (subCmd == "all" || subCmd == "signrawtransactionwithwallet")
		{
			oss << CSignRawTransactionWithWalletConfig().Help();
		}
		if (subCmd == "all" || subCmd == "sendrawtransaction")
		{
			oss << CSendRawTransactionConfig().Help();
		}
	}
	else if (type == EModeType::MINER)
	{
		oss << "\nUsage:\n";
		oss << "        mkf-miner (OPTIONS)\n";
		oss << "\n";
		oss << "Run mkf miner\n";
		oss << "\n";
		oss << "Options:\n";
		oss << options << "\n";
	}
	else 
	{
	}
	return oss.str();
}

}  // namespace bigbang

