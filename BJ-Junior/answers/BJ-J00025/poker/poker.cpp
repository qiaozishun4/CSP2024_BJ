#include<bits/stdc++.h>
using namespace std;
int n,vis[9][39],ans;
char a,b;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		int tmp1,tmp2;
		if(a=='D')tmp1=1;
		else if(a=='C')tmp1=2;
		else if(a=='H')tmp1=3;
		else tmp1=4;

		if(b=='A')tmp2=1;
		else if(b=='T')tmp2=10;
		else if(b=='J')tmp2=11;
		else if(b=='Q')tmp2=12;
		else if(b=='K')tmp2=13;
		else tmp2=b-'0';	
		vis[tmp1][tmp2]=1;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(vis[i][j]==0)ans++;
		}
	}
	cout<<ans;
	return 0;
}