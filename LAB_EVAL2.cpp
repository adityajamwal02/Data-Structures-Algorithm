#include<bits/stdc++.h>
#include<map>

using namespace std;

int left_sum=0,right_sum=0;
int digit1=0;
int digit=0;

// Node class to store the char present in words[].
// List of char (adj. list to store neighbors through the left side of words[])

class node{
public:
    char ch;
    list<char> nbrs;

    node(char ch)
    {
        this->ch=ch;
    }
};

// Graph holds info about nodes
// Maintaining (map) with char and node* to map values of char with given values assigned
// Key: Value system (map.emplace() in STL)
class graph
{
unordered_map<char,node*> mp;
public:
    graph(vector<char> characters)
    {
        for(auto character: characters)
        {
            mp[character]= new node(character);
        }
    }

    void addEdge(char x, char y, bool undir=false)            // Directed Graph: Hench, each node shall have an edge with one another
    {
        mp[x]->nbrs.push_back(y);                             //Pointer from map with char x, trying to access the property with arrow head notation
        if(undir)
        {
            mp[y]->nbrs.push_back(x);
        }
    }

void printAdjList()
{
    for(auto cpair : mp)
    {
        auto character=cpair.first;
        node *node=cpair.second;
        cout<<character<<"-->";
        for(auto nbr: node->nbrs)
        {
            cout<<nbr<<",";
        }
        cout<<endl;
    }
}
};

void compare(int left_sum,int right_sum)
{
    if(left_sum==right_sum)
    cout<<endl<<" \nTrue(1)";
    else
    cout<<endl<<" \nFalse(0)";
}

void conversion(map<char,int> mp,char token[],int s)
{
    digit1=0;
    for(int i=0;i<s;i++)
    {
        digit=0;
        char ch=token[i];
        if(ch>='A'&&ch<='Z')
        {
            int n=s-i-1;
            int value=(int)mp.at(ch);
            digit=(pow(10,n))*value;
            digit1=digit1+digit;
        }
    }
    cout<<digit1;
}

void right(map<char,int> mp,char result[],int m)
{
    for(int i=0;i<m;i++)
    {
        digit=0;
        char ch=result[i];
        if(ch>='A'&&ch<='Z')
        {
            int n=m-i-1;
            int value=(int)mp.at(ch);
            digit=(pow(10,n))*value;
            right_sum+=digit;
        }
    }
    cout<<" "<<right_sum;
}

void removeDupWord(char words[],char result[],map<char,int> mp,int m)
{
	char *token = strtok(words,",");
	while(token!=NULL)
	{
		cout<<token<<" ";
		int s=strlen(token);
		conversion(mp,token,s);
		left_sum+=digit1;
		cout<<endl;
		token=strtok(NULL,",");
	}
	cout<<left_sum<<endl;
	cout<<endl<<result;
	right(mp,result,m);
	compare(left_sum,right_sum);

}

int main()
{
    char words[]="SEND,MORE";
    char result[]="MONEY";
    int n=sizeof(words)-1;
    int m=sizeof(result)-1;

    vector<char> characters={'S','E','N','D','M','O','R','E'};
    graph g(characters);
    int l=characters.size();
    for(int i=0;i<l;i++)
    {
        for(auto j=i+1;j<l;j++)
        {
            g.addEdge(characters[i],characters[j]);
        }

    }
    g.printAdjList();
    cout<<endl;

	map<char,int> mp;
	mp.emplace('S', 9);
	mp.emplace('E', 5);
	mp.emplace('N', 6);
	mp.emplace('D', 7);
	mp.emplace('M', 1);
	mp.emplace('O', 0);
	mp.emplace('R', 8);
	mp.emplace('Y', 2);

	removeDupWord(words,result,mp,m);

	return 0;
}
