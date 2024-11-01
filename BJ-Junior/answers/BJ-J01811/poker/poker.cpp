#include <bits/stdc++.h>
using namespace std;
bool poker[55];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		char _color=s[0];
		char _data=s[1];
		
		int color,data;
		if(_color=='D') color=0;
		else if(_color=='C') color=1;
		else if(_color=='H') color=2;
		else if(_color=='S') color=3;
		
		if(_data=='A') data=0;
		if(_data>='2'&&_data<='9') data=_data-'1';
		if(_data=='T') data=9;
		if(_data=='J') data=10;
		if(_data=='Q') data=11;
		if(_data=='K') data=12;
		
		int ind=color*13+data;
		poker[ind]=1;
	}
	int ans=0;
	for(int i=0;i<52;i++)
	{
		if(poker[i]==0) ans++;
	}
	cout<<ans;
	return 0;
}