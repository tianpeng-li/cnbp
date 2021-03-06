#pragma once
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
//#include <queue>

namespace cnbp {

	using namespace std;

	enum PriType {
		Equal,
		Asc,
		Desc,
		Tria,
	};

	enum PriLevel {
		F = 1000,
		G = 500,
		H = 100,
		I = 10,
		J = 5,
		N = 1
	};

	typedef std::map<int, std::set<std::string>> priseed;

	//only sequential!
	//this function is terrible, use recursion!
	priseed cross(const std::vector<priseed> & seeds) {
		priseed q;
		q[1].insert("");
		for (priseed seed : seeds) {
			priseed nq;
			for (priseed::const_iterator old_ite = q.begin();
				old_ite != q.end(); old_ite++) {
				for (const std::string & old_str : old_ite->second) {
					for (priseed::const_iterator cur_ite = seed.begin();
						cur_ite != seed.end(); ++cur_ite) {
						for (const std::string & cur_str : cur_ite->second) {
							nq[old_ite->first * cur_ite->first].insert(old_str + cur_str);
						}
					}
				}
			}
			q = nq;
		}
		return q;
	}

	char toUpper(char lc) {
		return lc - 32;
	}
}