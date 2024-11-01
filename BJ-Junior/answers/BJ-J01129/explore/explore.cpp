#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool s[1005][1005];
int n,m,k,t;
int x,y,d;
long long p;
int dx,dy;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		s[x][y]=1;
		for(int i=1;i<=k;i++){
			
			if(d==0){
				y++;
			}
			if(d==1){
				x++;
			}
			if(d==2){
				y--;
			}
			if(d==3){
				x--;
			}
			s[x][y]=1;
			for(int j=1;j<=4;j++){
				dx=x,dy=y;
				if(d==0){
					y++;
				}
				if(d==1){
					x++;
				}
				if(d==2){
					y--;
				}
				if(d==3){
					x--;
				}
				if(x<=0||x>n||y<=0||y>m||a[x][y]=='x'){
					d=(d+1)%4;
				}		
				else{
					x=dx,y=dy;
					break;
				}
				x=dx,y=dy;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(s[i][j]==1){
					p++;
				}
			}
		}
		cout<<p<<endl;
		p=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				s[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				a[i][j]='.';
			}
		}
	}
    return 0;
}
