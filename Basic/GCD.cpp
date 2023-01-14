/// GCD or HCF using for loop

#include<iostream>
using namespace std;

int main(){
    int num1, num2, hcf;
    cout<<"Enter Numbers: "<<endl;
    cin>>num1>>num2;
    if(num2>num1){
        int temp=num2;
        num2=num1;
        num1=temp;
    }
    for(int i=1;i<=num2;i++){
        if(num1%i==0 and num2%i==0){
            hcf=i;
        }
    }
    cout<<" HCF or GCD is : "<<hcf;

    return 0;
}


/// Using inbuilt function

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int num1, num2, hcf;
    cout<<"Enter Numbers: "<<endl;
    cin>>num1>>num2;
    cout<<__gcd(num1,num2);

    return 0;
}
