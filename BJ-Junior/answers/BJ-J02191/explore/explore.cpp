#include<bits/stdc++.h>
using namespace std;
#define int long long
char a[10005][10005];
int flag[10005][10005];
signed main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
		int x,y,d,n,m,k,ans=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) cin>>a[i][j];
			
		flag[x][y]=true;
		for(int i=1;i<=k;i++){
			if(d==0){
				if(a[x][y+1]=='x'||y+1>m)d=(d+1)%4;
				else{
					y++;
					if(flag[x][y]==false)
						ans++;
					else flag[x][y]=true;
					}
			}else if(d==1){
				if(a[x+1][y]=='x'||x+1>n)d=(d+1)%4;
				else{
					x++;
					if(flag[x][y]==false)
						ans++;
					else flag[x][y]=true;
					}
			}else if(d==2){
				if(a[x][y-1]=='x'||y-1<1)d=(d+1)%4;
				else{
					y--;
					if(flag[x][y]==false)
						ans++;
					else flag[x][y]=true;
					}
			}else if(d==3){
				if(a[x-1][y]=='x'||x-1<1)d=(d+1)%4;
				else{
					x--;
					if(flag[x][y]==false)
						ans++;
					else flag[x][y]=true;
					}
			}
			//cout<<x<<' '<<y<<' '<<d<<endl;
		}
		cout<<++ans<<endl;
	}
	return 0;
}
