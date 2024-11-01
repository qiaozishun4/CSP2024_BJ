#include<bits/stdc++.h>
using namespace std;
char c[1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,m,k;
	int x,y,d;
	int T;
	cin>>T;
	int t;
	for(t=0;t<T;t++){
		cin>>n>>m>>k>>x>>y>>d;
		x--;
		y--;
		int i,j;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				cin>>c[i][j];
			}
		}
		int xx=x,yy=y,dd=d;
		for(int K=0;K<k;K++){
			if(d==0){
				if((c[x][y+1]=='.' or c[x][y+1]=='*') and y+1<m){
					c[x][y]='*';
					y++;
				}
				else
					d++;
			}
			else if(d==1){
				if((c[x+1][y]=='.' or c[x+1][y]=='*') and x+1<n){
					c[x][y]='*';
					x++;
				}
				else
					d++;
			}
			else if(d==2){
				if((c[x][y-1]=='.' or c[x][y-1]=='*') and y>0){
					c[x][y]='*';
					y--;
				}
				else
					d++;
			}
			else if(d==3){
				if((c[x-1][y]=='.' or c[x-1][y]=='*') and x>0){
					c[x][y]='*';
					x--;
				}
				else{
					d=0;
				}
			}
			if(x==xx and y==yy and d==dd) break;
		}
		c[x][y]='*';
		int ans=0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
	//			cout<<c[i][j];
				if(c[i][j]=='*') ans++;
			}
	//		cout<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
