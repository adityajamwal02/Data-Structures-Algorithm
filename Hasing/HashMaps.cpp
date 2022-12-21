#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int main()
{
    vector<string> names{"Aditya", "Jamwal", "Adi", "Jam", "Rohit"};
    unordered_map <string, int> Messages{
    {"Aditya",400 },
    {"Jamwal", 230 },
    {"Adi", 100 },
    {"Jam", 530 },
    {"Rohit", 900 }
    };


   for(int i=0;i<names.size();i++)
   {
       cout<<Messages[names[i]]<<endl;
   }

   return 0;
}

