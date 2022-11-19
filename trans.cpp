#include<bits/stdc++.h>
#include <sstream>
using namespace std;
map<char,int>dir;
int main()
{
	dir['Áã']=0;
    dir['Ò¼']=1;
    dir['·¡']=2;
    dir['Èþ']=3;
    dir['ËÁ']=4;
    dir['Îé']=5;
    dir['Â½']=6;
    dir['Æâ']=7;
    dir['°Æ']=8;
    dir['¾Á']=9;
	string s1,s2;
	cin>>s1;
	for(int i=0;i<s1.size();i++)
	{
		cout<<dir[s1[i]];
	}
} 
