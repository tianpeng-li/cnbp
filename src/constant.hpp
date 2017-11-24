#pragma once
#include "common.hpp"
#include <algorithm>
#include <fstream>
#include <iterator>

namespace cnbp {

	using namespace std;

	class Constant {
	public:
		Constant() {

		}

		void init() {
			charPriInit();
			seedInit();
		}

		const priseed & getChar() const { return cPri; };
		const priseed & getSpChar() const { return spcPri; };
		const priseed & getSid() const { return sidLocPrefix; };
		const priseed & getHanzi() const { return commonHanzi; };
		const priseed & getPhone() const { return phonePrefix; };




	private:
		priseed cPri;
		priseed spcPri;
		priseed sidLocPrefix;
		priseed commonHanzi;
		priseed phonePrefix;


		void seedInit() {
			string sidLocPrefix_path = "../seed/sid_first_six.txt";
			string commonHanzi_path = "../seed/common_hanzi.txt";
			string phonePrefix_path = "../seed/solid_phone_area.txt";
			loadSeed(sidLocPrefix_path, sidLocPrefix, PriLevel::F);
			loadSeed(commonHanzi_path, commonHanzi, PriLevel::F);
			loadSeed(phonePrefix_path, phonePrefix, PriLevel::H);

			///in.open()
		}

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

		void loadSeed(string& path, priseed& dest, PriLevel level) {
			ifstream in(path);
			string buf;
			while (getline(in, buf)) {
				dest[level].insert(buf);
			}
			in.close();
		}

	};
}