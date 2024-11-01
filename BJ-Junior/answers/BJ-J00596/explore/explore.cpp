#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,sum;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	char a[1001][1001];
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		sum=1;
		for(int j=1;j<=k;j++){
			if(d==1){
				if(y+1>m||a[x][y+1]=='x'){
					d+=1;
					d%=4;
				}else{
					y++;
					sum++;
				}
			}else if(d==0){
				if(x+1>m||a[x+1][y]=='x'){
					d+=1;
					d%=4;
				}else{
					x++;
					sum++;
				}
			}else if(d==3){
				if(y-1>m||a[x][y-1]=='x'){
					d+=1;
					d%=4;
				}else{
					y--;
					sum++;
				}
			}else if(d==2){
				if(x-1>m||a[x-1][y]=='x'){
					d+=1;
					d%=4;
				}else{
					x--;
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
}