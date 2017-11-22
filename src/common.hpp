#pragma once
#include <map>
#include <set>
#include <string>
#include <vector>
//#include <queue>

enum PriType {
	Equal,
	Asc,
	Desc,
	Tria,
};

typedef std::map<int, std::set<std::string>> priseed;

//only sequential!
priseed cross(std::vector<priseed> seeds) {
	priseed rst;
	//std::vector<std::string> q;
	//q.push_back("");
	//for (priseed seed : seeds) {
	//	std::vector<std::string>
	//	for (priseed::reverse_iterator ite = seed.rbegin(); ite != seed.rend(); ++ite) {
	//		for ()
	//	}
	//}
	return rst;
}