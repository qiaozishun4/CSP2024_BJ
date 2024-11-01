#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d,nx,ny,sum;
int xc[5]={0,1,0,-1};
int yc[5]={1,0,-1,0};
string s;
char a[1010][1010];
bool b[1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
    cin>>T;
    for(int c=1;c<=T;c++){
		sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				b[i][j]=false;
			}
		}
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		if(k==0){
			cout<<1<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>s;
			for(int j=1;j<=m;j++){
				a[i][j]=s[j-1];
			}
		}
		sum+=1;
		b[x][y]=1;
		while(k>0){
			for(int i=d;i<=d+3;i++){
				d=i;
				d%=4;
				nx=x+xc[d];
				ny=y+yc[d];
				if(nx>=1 and nx<=n and ny>=1 and ny<=m and a[nx][ny]=='.' ){
					x=nx;
					y=ny;
					k--;
					if(!b[x][y]){
						sum++;
						b[x][y]=true;
					}
					break;
				}
				k--;
				if(k==0) break;
			}
		}
		cout<<sum<<endl;
	}
	
    return 0;
}
