#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,ans[7];
char mp[1005][1005];
struct Robot{
    int x,y,d;
}r;
int main(){
	cin>>t;
	for(int z=1;z<=t;z++){
		cin>>n>>m>>k>>r.x>>r.y>>r.d;
		for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[n][m];
            }
		}
		for(int i=1;i<=k;i++){
            if((d==0&&r.x+1>m)||(d==1&&r.y+1>n)||(d==2&&r.x-1<1)||(d==3&&r.y-1<1)||(d==0&&mp[r.x][r.y+1]=='*')||(d==1&&mp[r.x+1][r.y]=='*')||(d==2&&mp[r.x][r.y-1]=='*')||(d==3&&mp[r.x-1][r.y]=='*')) d=(d+1)%4;
            else if(d==0) mp[r.x][r.y+1]='/';
            else if(d==1) mp[r.x+1][r.y]='/';
            else if(d==2) mp[r.x][r.y-1]='/';
            else if(d==3) mp[r.x-1][r.y]='/';
		}
		for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mp[n][m]=='/') ans[z]++;
            }
		}
	}
	for(int i=1;i<=t;i++) cout<<ans[i]<<endl;
	return 0;
}
