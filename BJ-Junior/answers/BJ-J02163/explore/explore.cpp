#include<bits/stdc++.h>
using namespace std;
int sum[1001];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,n,m;
	cin>>t;
	for(int l=1;l<=t;l++){
		int x,y,d;
		long long k;
		cin>>n>>m>>k>>x>>y>>d;
		char a[n+1][m+1];
		bool b[n+1][m+1];
		memset(b,0,sizeof(b));
		b[x][y]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=k;i++){
			if(d==0){
				if((a[x][y+1]=='.')&&(y+1<=m)){
					if(b[x][y+1]==0){
						b[x][y+1]=1;
						sum[l]++;
						y+=1;
					}
				}else{
					d=(d+1)%4;
				}
			}else if(d==1){
				if((a[x+1][y]=='.')&&(x+1<=n)){
					if(b[x+1][y]==0){
						b[x+1][y]=1;
						sum[l]++;
						x+=1;
					}
				}else{
					d=(d+1)%4;
				}
			}else if(d==2){
				if((a[x][y-1]=='.')&&(y-1>=1)){
					if(b[x][y-1]==0){
						b[x][y-1]=1;
						sum[l]++;
						y-=1;
					}
				}else{
					d=(d+1)%4;
				}
			}else{
				if((a[x-1][y]=='.')&&(x-1>=1)){
					if(b[x-1][y]==0){
						b[x-1][y]=1;
						sum[l]++;
						x-=1;
					}
				}else{
					d=(d+1)%4;
				}
			}
		}
	}
	for(int i=1;i<=t;i++){
		cout<<sum[i]+1<<endl;
	}
	return 0;
}
