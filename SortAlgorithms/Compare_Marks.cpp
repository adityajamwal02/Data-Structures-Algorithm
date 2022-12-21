#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int calculateMarks(vector<int> marks)
{
    return marks[0]+marks[1]+marks[2]+marks[3];
}
bool compareMarks(pair<string,vector<int>> s1, pair<string,vector<int>> s2)
{
    vector<int> m1=s1.second;
    vector<int> m2=s2.second;
    return calculateMarks(m1)>calculateMarks(m2);
}
int main()
{
    vector<pair<string,vector<int>>>student_marks=
    {
        {"ABC", {20,20,19,18}},
        {"KLM", {10,20,15,18}},
        {"PQR", {19,14,19,10}},
        {"XYZ", {17,20,19,18}}
    };
    sort(student_marks.begin(),student_marks.end(),compareMarks); //Syntax: sort over vector from begin to end while comparing condition overall//
    for(auto s: student_marks)
    {
        cout<<s.first<<" "<<calculateMarks(s.second)<<endl;
    }
}

