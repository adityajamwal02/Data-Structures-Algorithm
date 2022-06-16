#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void findsubsets(char *input, char *output, int i, int j)
{
    //base case
    if(input[i]=='\0')
    {
        output[j]='\0';
        if(output[0]=='\0')
            cout<<"NULL";
        cout<<output<<" ";
        return;
    }
    //recursion case
    //Includes ith letter

    output[j]=input[i];
    findsubsets(input, output, i+1, j+1);

    //Excludes ith letter
    output[j]='\0';
    findsubsets(input, output, i+1, j);
}

int main()
{
    char input[100];
    char output[100];
    cin>>input;
    cout<<endl;
    findsubsets(input,output,0,0);
    return 0;
}
