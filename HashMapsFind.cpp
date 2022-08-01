#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main()
{

    unordered_map<string, int> mp;

    mp ={
        {
            "mom", 5
        },
        {
            "dad", 9
        },
        {
            "sis", 8
        },
        {
            "bro", 10
        }
    };

    string input;
    cin>>input;

    unordered_map<string, int>::const_iterator it = mp.find(input);

    if(it!=mp.end())
    {
        cout<<it->first<<" : "<<it->second<<endl;
    }else
    {
        cout<<" Not present "<<endl;
    }

    return 0;
}
