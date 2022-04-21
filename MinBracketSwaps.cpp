#include <bits/stdc++.h>
using namespace std;

int swapCount(string s)
{
	int countLeft=0,countRight=0,tswap=0,imbalance=0;
	for(int i=0;i<s.length();i++)
	{
		if (s[i]=='[')
		{
			countLeft++;
			if (imbalance>0)
			{
				tswap+=imbalance;
				imbalance--;
			}
		}
		else if(s[i]==']')
		{
            countRight++;
			imbalance=(countRight-countLeft);
		}
	}
	return tswap;
}
int main()
{
	string s="[]][][";
	cout<<swapCount(s)<<endl;
	return 0;
}
