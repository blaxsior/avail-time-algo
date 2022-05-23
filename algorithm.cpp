#include <iostream>
#include "parse_info.h"

int main()
{
	std::vector<string> filename;
	filename.push_back("list1.txt");
	filename.push_back("list2.txt");
	filename.push_back("list3.txt");


	std::vector<vector<STime>> times = STimeParser::get_stime(filename,5);//비교 대상이 되는 요일의 개수 ex 월-금 -> 5 

	for (const auto day : times)
	{
		for (const auto stime : day)
		{
			cout << stime.dow << ", " << stime.start << ", " << stime.stop << endl;
		}
	}
}