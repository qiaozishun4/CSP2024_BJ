#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
char a[N][N];
struct node{
	int x,y;
};
bool operator < (node x,node y){
	return (x.x<y.x)||(x.x==y.x&&x.y<y.y);
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,m,k;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		map<node,int> mp;
		mp[node{x,y}]++;
		while(k--){
			if(d==0){
				if(x<=n&&x>=1&&y+1<=m&&y+1>=1&&a[x][y+1]=='.'){
					y+=1;
					mp[node{x,y}]++;
				}else{
					d=(d+1)%4;
				}
			}else if(d==1){
				if(x+1<=n&&x+1>=1&&y<=m&&y>=1&&a[x+1][y]=='.'){
					x+=1;
					mp[node{x,y}]++;
				}else{
					d=(d+1)%4;
				}
			}else if(d==2){
				if(x>=1&&x<=n&&y-1>=1&&y-1<=m&&a[x][y-1]=='.'){
					y-=1;
					mp[node{x,y}]++;
				}else{
					d=(d+1)%4;
				}
			}else if(d==3){
				if(x-1>=1&&x-1<=n&&y>=1&&y<=m&&a[x-1][y]=='.'){
					x-=1;
					mp[node{x,y}]++;
				}else{
					d=(d+1)%4;
				}
			}
		}
		cout<<mp.size()<<endl;
	}
	return 0;
}
