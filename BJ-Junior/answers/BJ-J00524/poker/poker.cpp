#include <bits/stdc++.h>
using namespace std;
int color,num,n,ans=52;
string s;
int vis[20][20];
void p(){
	if(s[0]=='D') color=1;
	if(s[0]=='C') color=2;
	if(s[0]=='H') color=3;
	if(s[0]=='S') color=4;
	if(s[1]<='9' && s[1]>'0') num=s[1]-48;
	if(s[1]=='A') num=1;
	if(s[1]=='T') num=10;
	if(s[1]=='J') num=11;
	if(s[1]=='Q') num=12;
	if(s[1]=='K') num=13;
	if(vis[num][color]) return ;
	vis[num][color]=1;
	ans--;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>s;
		p();
	}
	cout<<ans;
	return 0;
}
