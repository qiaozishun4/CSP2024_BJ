#include <bits/stdc++.h>
using namespace std;
char ditu[1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,n,m,k,x0,y0,d0;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>k;
		cin>>x0>>y0>>d0;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				cin>>ditu[j][k];
			}
		}	
		if(d0==0&&(y0+1>m||ditu[x0][y0+1]=='x')) cout<<1<<endl;
		else if(d0==0&&y0+1<=m&&ditu[x0][y0+1]=='.') cout<<2<<endl;
		else if(d0==1&&(x0+1>n||ditu[x0+1][y0]=='x')) cout<<1<<endl;
		else if(d0==1&&x0+1<=n&&ditu[x0+1][y0]=='.') cout<<2<<endl;
		else if(d0==2&&(y0-1<1||ditu[x0][y0-1]=='x')) cout<<1<<endl;
		else if(d0==2&&y0-1>=1&&ditu[x0][y0-1]=='.') cout<<2<<endl;
		else if(d0==3&&(x0-1<1||ditu[x0-1][y0]=='x')) cout<<1<<endl;
		else if(d0==3&&x0-1>=1&&ditu[x0-1][y0]=='.') cout<<2<<endl;
	}
	return 0;
}
