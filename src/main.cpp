#include "gen.hpp"
#include "help.hpp"
#include "config.hpp"
#include "common.hpp"
#include <sstream>

using namespace std;
using namespace cnbp;
int main() {
	BirthDay b;

	cout << 'A' - 'a' << endl;

	b.init();
	const priseed & rst = b.names();
	//priseed rst = b.yearMonthDay();
	
	return 0;

}