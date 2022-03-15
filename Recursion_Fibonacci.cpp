#include<iostream>
using namespace std;
int fibonacci(int n)
{
    if(n==0 or n==1)
    {
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}
int main()
{
    int n;
    cin>>n;
    cout<<"Element at Position "<<n<<" is: "<<fibonacci(n);
}
