#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    string key;
    float value;
    node * next;

    node(string key, float value)
    {
        this->key=key;
        this->value=value;
        next=NULL;
    }
};

class hashtable
{
    node<float>** table;
    int current_size;
    int total_size;

    int hashfn(string key)
    {
        int idx=0;
        for(auto ch : key)
        {
            idx=(idx+ch*power)%ts;
            power=(power*29)%ts;
        }
        return idx;
    }

public:
    hashtable(int default_size=7)
    {
        current_size=0;
        total_size=default_size;

        table = new node<float>*[total_size];

        for(int i=0;i<total_size;i++)
            table[i]=NULL;
    }

    void insert_element(string key, float value)
    {
        int idx= hashfn(key);

        node<float>* n=new node<float>(key,value);
        n->next=table[idx];
        table[idx]=n;

        cs++;
    }

    int search(string key){
        int idx=hashfn(key);
        node<float> *temp=table[idx];
        while(temp!=NULL){
            if(temp->key == key){
                return &temp->value;
            }
        temp=temp->next;
        }
    return -1;
    }
};

