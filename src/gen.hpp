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

	const priseed days() const { return day; };
	const priseed monthes() const { return month; };
	const priseed years() const { return year; };

	priseed monthDays() {
		std::vector<priseed> tomerge{month, day};
		return cross(tomerge);
	}

	priseed yearMonthDay() {
		std::vector<priseed> tomerge{ year, month, day };
		return cross(tomerge);
	}

private:
	priseed day;
	priseed month;
	priseed year;

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
	//Note: pri should > 0
	void formatTime(int start, int end, priseed& dest,
		PriType priority = Equal, int width = 2) {
		stringstream ss;
		string buf;
		for (int i = start; i <= end; ++i) {
			ss.width(width);
			ss.fill('0');
			ss << i;
			ss >> buf;
			int pri = 1;
			switch (priority)
			{
			case Equal:
				pri = 1;
				break;
			case Asc:
				pri = i;
				break;
			case Desc:
				pri = end - i;
				break;
			case Tria:
				pri = abs(i - (end + start) / 2);
				break;
			default:
				pri = 1;
				break;
			}
			if (pri < 1) {
				pri = 1;
			}
			dest[pri].insert(buf);
			ss.clear();
		}
	}
};