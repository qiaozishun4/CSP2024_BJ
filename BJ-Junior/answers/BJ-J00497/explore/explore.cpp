#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,sum;
char f[1010][1010];
bool p[1010][1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>f[i][j];
			}
		}
		sum=1;
		memset(p,true,sizeof(p));
		while(k--){
			if(d==0){
				p[x][y]=false;
				if(y+1<=m&&f[x][y+1]=='.'){
					++y;
					if(p[x][y]==true){
						sum++;
					}
				}else{
					d=(d+1)%4;
				}
			}else if(d==1){
				p[x][y]=false;
				if(x+1<=n&&f[x+1][y]=='.'){
					++x;
					if(p[x][y]==true){
						sum++;
					}
				}else{
					d=(d+1)%4;
				}
			}else if(d==2){
				p[x][y]=false;
				if(y-1>=1&&f[x][y-1]=='.'){
					--y;
					if(p[x][y]==true){
						sum++;
					}
				}else{
					d=(d+1)%4;
				}
			}else if(d==3){
				p[x][y]=false;
				if(x-1>=1&&f[x-1][y]=='.'){
					--x;
					if(p[x][y]==true){
						sum++;
					}
				}else{
					d=(d+1)%4;
				}
			}
		}
		cout<<sum<<endl;
	}
    return 0;
}
