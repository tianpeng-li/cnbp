#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include "common.hpp"
using namespace std;

class BirthDay {
public:

	BirthDay() {
		init();
	}

	const map<int, set<string>> days() const { return day; };
	const map<int, set<string>> monthes() const { return month; };
	const map<int, set<string>> years() const { return year; };

	map<int, set<string>> monthDays() {

	}

private:
	map<int, set<string>> day;
	map<int, set<string>> month;
	map<int, set<string>> year;

	void init() {
		dayInit();
		monthInit();
		yearInit();
	}

	void dayInit() {
		formatTime(1, 31, day);
	}

	void monthInit() {
		formatTime(1, 12, month);
	}

	void yearInit() {
		formatTime(1975, 2017, year, Tria);
	}

	//[]
	void formatTime(int start, int end, map<int, set<string>>& dest,
		PriType priority = Equal, int width = 2) {
		stringstream ss;
		string buf;
		for (int i = start; i <= end; ++i) {
			ss.width(width);
			ss.fill('0');
			ss << i;
			ss >> buf;
			switch (priority)
			{
			case Equal:
				dest[0].insert(buf);
				break;
			case Asc:
				dest[i].insert(buf);
				break;
			case Desc:
				dest[end - i].insert(buf);
				break;
			case Tria:
				dest[abs(i - (end + start) / 2)].insert(buf);
				break;
			default:
				break;
			}
			ss.clear();
		}
	}
};