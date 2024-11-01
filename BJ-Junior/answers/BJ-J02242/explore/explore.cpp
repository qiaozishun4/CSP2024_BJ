#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,k,x,y,d,cx,cy,step=1,book[1005][1005];
char mp[1005][1005];
string str;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(ll l=1;l<=t;l++){
		memset(book,0,sizeof(book));
		cin>>n>>m>>k;//mpx,mpy,order
		cin>>x>>y>>d;//rx,ry,director
		book[x][y]=1;
		for(ll i=1;i<=n;i++){//chushihua
			for(ll j=1;j<=m;j++){
				cin>>mp[i][j];
			}
		}
		for(ll i=1;i<=k;i++){//k times
			if(d==0){//check location
				cx=x,cy=y+1;
			}
			if(d==1){
				cx=x+1,cy=y;
			}
			if(d==2){
				cx=x,cy=y-1;
			}
			if(d==3){
				cx=x-1,cy=y;
			}
			if(cx<1||cx>n||cy<1||cy>m||mp[cx][cy]=='x'){
				if(d==3)d=0;
				else d++;
			}
			else{
			    x=cx,y=cy;
			    if(book[x][y]!=1){
					step++;
					book[x][y]=1;
				}
			}
			//cout<<x<<" "<<y<<" "<<d<<" "<<step<<" "<<book[x][y]<<endl;
		}
		cout<<step<<endl;
		step=1;
	}
	return 0;
	}
