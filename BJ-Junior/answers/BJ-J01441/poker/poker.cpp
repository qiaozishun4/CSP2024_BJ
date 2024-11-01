#include<bits/stdc++.h>
using namespace std;
bool vis[60];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		int x;
		if(s[0]=='D') x=0;
		if(s[0]=='C') x=13;
		if(s[0]=='H') x=26;
		if(s[0]=='S') x=39;
		if(isdigit(s[1])) x+=s[1]-'0';
		if(s[1]=='A') x+=1;
		if(s[1]=='T') x+=10;
		if(s[1]=='J') x+=11;
		if(s[1]=='Q') x+=12;
		if(s[1]=='K') x+=13;
		vis[x]=1;
	}
	int ans=0;
	for(int i=1;i<=52;i++){
		if(!vis[i]) ans++;
	}
	cout<<ans;
	return 0;
}