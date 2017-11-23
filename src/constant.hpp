#pragma once
#include "common.hpp"
#include <algorithm>
#include <iterator>

namespace cnbp {

	using namespace std;

	class Constant {
	public:
		Constant() {
			charPriInit();
		}

		const priseed & getChar() const { return cPri; };
		const priseed & getSpChar() const { return spcPri; };


	private:
		priseed cPri;
		priseed spcPri;

		void charPriInit() {
			set<string> nonPri;
			for (char c = 'a'; c <= 'z'; c++) {
				string s;
				s.push_back(c);
				nonPri.insert(s);
			}
			cPri[10] = { "l", "w", "z" };
			cPri[9] = { "c", "y", "h" };
			for_each(cPri[10].begin(), cPri[10].end(),
				[&nonPri](const string& str) {nonPri.erase(str); });
			for_each(cPri[9].begin(), cPri[9].end(),
				[&nonPri](const string& str) {nonPri.erase(str); });
			cPri[1] = nonPri;
		}

		void spcInit() {
			spcPri[3] = {"@", "."};
			spcPri[2] = {"_", "-"};
		}

	};
}