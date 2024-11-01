#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int maxN=1e3+5;
char a[maxN][maxN];
bool b[maxN][maxN];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	for(int k1=1;k1<=T;k1++){
		int n,m,k,x,y,d,ans=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
				b[i][j]=false;
			}
		}
		b[x][y]=true;
		for(int i=1;i<=k;i++){
			int x1=x,y1=y;
			if(d==0){
				y1=y+1;
			}
			if(d==1){
				x1=x+1;
			}
			if(d==2){
				y1=y-1;
			}
			if(d==3){
				x1=x-1;
			}
			if(x1<1||x1>n||y1<1||y1>m||a[x1][y1]=='x'){
				d=(d+1)%4;
			}else{
				x=x1,y=y1;
				if(b[x][y]==false){
					b[x][y]=true;
					ans++;
				}	
			}
		}
		cout<<ans<<endl;							
	}	
	
	return 0;
}	
