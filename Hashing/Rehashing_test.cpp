#include<iostream>
#include "Hashing_Reshashing.h"
using namespace std;

int main(){
    Hashtable<int> h;
    h.insert_element("mango", 100);
    h.insert_element("apple", 120);
    h.insert_element("banana", 140);
    h.insert_element("guava", 200);
    h.print();

    return 0;
}

