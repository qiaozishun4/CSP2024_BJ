#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
char s[1090][1009]={};
int main(){
freopen("explore.in","r",stdin);
freopen("explore.out","w",stdout);
cin>>t;
while(t--){
	long long h=1;
	cin>>n>>m>>k>>x>>y>>d;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>s[i][j];
		}
	}
	for(int i=0;i<k;i++){
		int xx,yy;
		if(d==0){
			yy=y+1;
			xx=x;
		}
		if(d==1){
			xx=x+1;
			yy=y;
		}
		if(d==2){
			xx=x;
			yy=y-1;
		}
		if(d==3){
			xx=x-1;
			yy=y;
		}
		if(1<=xx&&xx<=n&&1<=yy&&yy<=m&&s[xx][yy]=='.'){
			x=xx;
			y=yy;
			h++;
		}else{
			d=(d+1)%4;
		}
	}
	cout<<h<<endl;
}
	return 0;
}