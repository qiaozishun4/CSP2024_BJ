#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,b[5][30],xx,yy,ans;
char x,y;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		if(x=='D') xx=1;
		if(x=='C') xx=2;
		if(x=='H') xx=3;
		if(x=='S') xx=4;
		if(y>='2'&&y<='9') yy=y-'0';
		if(y=='A') yy=1;
		if(y=='T') yy=10;
		if(y=='J') yy=11;
		if(y=='Q') yy=12;
		if(y=='K') yy=13;
		b[xx][yy]++;
	}for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(b[i][j]==0) ans++;
		}
	}cout<<ans;
	return 0;
}