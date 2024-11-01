#include<bits/stdc++.h>
using namespace std;
int sum;
set<int> st;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
    string s;
    int n;
    cin>>n;
    while(n--)
    {
		cin>>s;
		if(s[1]=='A') sum=10;
		else if(s[1]=='T') sum=100;
		else if(s[1]=='J') sum=110;
		else if(s[1]=='Q') sum=120;
		else if(s[1]=='K') sum=130;
		else sum=(s[1]-'0')*10;
		if(s[0]=='D') sum+=1;
		else if(s[0]=='C') sum+=2;
		else if(s[0]=='H') sum+=3;
		else sum+=4;
		st.insert(sum);
	}
	cout<<52-st.size();
    return 0;
}
