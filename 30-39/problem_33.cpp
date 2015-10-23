/*
面试题33：把数组排成最小的数
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，
则打印出这三个数字能排成的最小数字为321323。
*/

#include<algorithm>
#include<vector>
#include<iostream>
#include<sstream>

using namespace std;

class Solution
{
public:

	struct smallerDigit : public std::binary_function<string, string, bool>
	{
		inline bool operator()(const string& s1, const string& s2)
		{
			string sa = s1 + s2;
			string sb = s2 + s1;

			return sa < sb;
		}
	};

	string largestNumber(vector<int> &num) {
		vector<string> str;
		for (size_t i = 0; i != num.size(); ++i)
		{
			stringstream ss;
			ss << num[i];
			str.push_back(ss.str());
		}

		sort(str.begin(), str.end(), smallerDigit());

		if (str.size() > 0 && str[0] == "0")
		{
			return "0";
		}

		string r;
		for (size_t i = 0; i != str.size(); ++i)
			r.append(str[i]);

		return r;
	}

};