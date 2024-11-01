#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
int x,y,d,cnt,e,f;
char map2[1010][1010];
bool map1[1010][1010];
int a[4]={0,1,0,-1};
int b[4]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		memset(map2,' ',sizeof(map2));
		memset(map1,1,sizeof(map1));
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		cnt=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>map2[i][j];
			}
		}
		for(int i=1;i<=k;i++){
			e=x+a[d];
			f=y+b[d];
			if(e<=n && f<=m && map2[e][f]=='.'){
				x=e;y=f;
				if(map1[x][y]){
					cnt++;
					map1[x][y]=0;
				}
			}
			else d=(d+1)%4;
		}
		cout<<cnt<<endl;
	}
	return 0;
}

