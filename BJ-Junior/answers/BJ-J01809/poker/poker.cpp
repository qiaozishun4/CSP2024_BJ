#include<bits/stdc++.h>
using namespace std;
bool a[5][200];
string s;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=0,x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		if(s[0]=='D')x=1;
		if(s[0]=='C')x=2;
		if(s[0]=='H')x=3;
		if(s[0]=='S')x=4;
		if(!a[x][s[1]])ans++,a[x][s[1]]=1;
	}
	cout<<52-ans;
	return 0;
}