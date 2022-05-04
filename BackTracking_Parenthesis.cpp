#include<bits/stdc++.h>
using namespace std;
int score(string s)
{
   if(s.empty() || s[0]==')') return 0;
   if(s[1]==')') return score(s.substr(2))+1;
   else return 2*score(s.substr(1));
}
int findScore(string s)
{
   int c=0, k=0, i=0;
   while(i<s.length())
   {
       string temp="";
       do
       {
           if(s[i]=='(') k++;
           else k--;
           temp.push_back(s[i]);
           i++;
       }while(k!=0);
       c+=score(temp);
   }
   return c;
}
int main()
{
   string s="()((()))()(())";
   cout<<findScore(s);
   return 0;
}


