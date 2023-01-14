#include<bits/stdc++.h>
#include<cstring>
#include<string>
using namespace std;

template<typename T>

class node{
public:
    string key;
    T value;
    node *next;

    node(string key, T value)
    {
        this->key=key;
        this->value=value;
        next=NULL;
    }

    ~node(){
        if(next!=NULL){
            delete next;
        }
    }
};

class Hashtable
{
    node<T>** table;
    int current_size;
    int total_size;

    int hashfn(string key)
    {
        int idx=0;
        for(auto ch : key)
        {
            idx=(idx+ch*power)%total_size;
            power=(power*29)%total_size;
        }
        return idx;
    }
    void reshash(){
        node<T>** oldTable=table;
        int oldTs=total_size;
        total_size=2*total_size+1;
        table=new node<T>*[total_size];
        for(int i=0;i<total_size;i++){
            table[i]=NULL;
        }
        for(int i=0;i<oldTs;i++){
            node<T> *temp=oldTable[i];
            while(temp!=NULL){
                string key=temp->key;
                T value=temp->value;
                insert_element(key, value);
                temp=temp->next;
            }
            if(oldTable[i]!=NULL){
                delete oldTable[i];
            }
        }
        delete [] oldTable;
    }

public:

    hashtable(int default_size=7)
    {
        current_size=0;
        total_size=default_size;

        table = new node<T>*[total_size];

        for(int i=0;i<total_size;i++)
            table[i]=NULL;
    }

    void insert_element(string key, T value)
    {
        int idx= hashfn(key);

        node<T>* n=new node<T>(key,value);

        n->next=table[idx];
        table[idx]=n;
        current_size++;

        T load_factor=current_size/T(total_size);
        if(load_factor>0.7){
            reshash();
        }
    }

    void print(){
        for(int i=0;i<total_size;i++){
            cout<<"Bucket "<<i<<"->";

            node<T>* temp=table[i];
            while(temp!=NULL){
                cout<<temp->key<<"->";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};
