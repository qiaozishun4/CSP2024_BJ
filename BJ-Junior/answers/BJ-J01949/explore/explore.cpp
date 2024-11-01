#include<bits/stdc++.h>
using namespace std;
char mp[1005][1005];
bool vis[1005][1005]={0};
int f[5][3]={{0,1},{1,0},{0,-1},{-1,0}};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin.tie(0);
int t;
cin>>t;
while(t--){
int n,m,k;
cin>>n>>m>>k;
int sx,sy,sd;
cin>>sx>>sy>>sd;
sx--;
sy--;
for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		char c;
		cin>>c;
		mp[i][j]=c;
	}
}
for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		vis[i][j]=0;
		}
	}
int ans=1;
vis[sx][sy]=1;
for(int i=0;i<k;i++){
	int a=sx+f[sd][0],b=sy+f[sd][1];
	if(a>=0&&a<n&&b>=0&&b<m&&mp[a][b]=='.'){
		if(!vis[a][b]){
			ans++;
			vis[a][b]=1;
			}
			sx=a;
			sy=b;
	}
	else{
		sd=(sd+1)%4;
		}
	}
cout<<ans<<"\n";	
}
fclose(stdin);
fclose(stdout);
return 0;
}