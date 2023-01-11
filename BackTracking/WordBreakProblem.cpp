/*
Given a str which is a valid sentence without any spaces between the words and a dictionary of valid English words, find all possible number of ways to break the sentence in individual dictionary words.
Input Format
In the function a string str and a vector of strings representing dictionary is passed
Output Format
Return an integer representing the total no. of ways

Sample Input
dictionary = { i, like, sam, sung, samsung, mobile}
str = "ilikesamsungmobile"
Sample Output
2
Explanation
Following are the 2 possible ways to break the string
 i like sam sung mobile
 i like samsung mobile
*/

#include<bits/stdc++.h>
using namespace std;

int cnt = 0;
vector<string> v;
void help(string s, int n, string res, vector<string> &word)
{
	for (int i = 1; i <= n; i++)
	{
		string ss = s.substr(0, i);
		int l = word.size();
		bool flag = false;

		for (int j = 0; j < l; j++)
			if (word[j] == ss)
				flag = true;

		if (flag)
		{
			if (i == n)
			{
				res += ss;
				// v.push_back(res);
				cnt++;
				return;
			}
			help(s.substr(i, n - i), n - i, res + ss + " ", word);
		}
	}
}

int wordBreak(string s, vector<string> &dictionary)
{
	cnt = 0;
	// v.clear();
	help(s, s.size(), "", dictionary);
	// for (auto x : v) cout << x << '\n';
	return cnt;
}
