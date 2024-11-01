#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x,y,d,a[10001][10001],b[10001][10001];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	long long T;
	cin>>T;
	for(long long k1=1;k1<=T;k1++){
		long long count1=1;
		cin>>n>>m>>k>>x>>y>>d;
		for(long long i=1;i<=n;i++){
			string c;
			cin>>c;
			for(long long j=1;j<=m;j++){
				a[i][j]=c[j-1];
			}
		}
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=m;j++){
				b[i][j]=0;
			}
		}
		b[x][y]=1;
		for(long long i=1;i<=k;i++){
			if(d==0){
				if(y+1>m||y+1<1||a[x][y+1]=='x'){
					d=1;
				}else{
					y+=1;
					if(b[x][y]==0){
						count1++;
						b[x][y]=1;
					} 
				}
			}else if(d==1){
				if(x+1>n||x+1<1||a[x+1][y]=='x'){
					d=2;
				}else{
					x+=1;
					if(b[x][y]==0){
						count1++;
						b[x][y]=1;
					} 
				}
			}else if(d==2){
				if(y-1>m||y-1<1||a[x][y-1]=='x'){
					d=3;
				}else{
					y-=1;
					if(b[x][y]==0){
						count1++;
						b[x][y]=1;
					} 
				}
			}else if(d==3){
				if(x-1>n||x-1<1||a[x-1][y]=='x'){
					d=0;
				}else{
					x-=1;
					if(b[x][y]==0){
						count1++;
						b[x][y]=1;
					} 
				}
			}
		}
		cout<<count1<<endl;
	}
	return 0;
}
