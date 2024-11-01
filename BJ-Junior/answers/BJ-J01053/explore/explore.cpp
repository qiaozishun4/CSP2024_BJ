
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010];
int vi[1010][1010];
int p[10][10]={{0,1},{1,0},{0,-1},{-1,0}};
void f(){
	for(int i=0;i<1010;i++){
		for(int j=0;j<1010;j++){
			vi[i][j]=0;
		}
	}
	int n,m,k;
	int x,y,d;
	cin>>n>>m>>k;
	cin>>x>>y>>d;
	char z;
	vi[x][y]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>z;
			if(z=='.'){
				a[i][j]=0;
			}else{
				a[i][j]=1;
			}
			
		}
	}
	for(int i=0;i<k;i++){
		int dx=x+p[d][0];
		int dy=y+p[d][1];
		if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&a[dx][dy]==0){
			x=dx;
			y=dy;
		}else{
		
			d=(d+1)%4;
		}
		vi[x][y]=1;
		//cout<<x<<" "<<y<<" "<<d<<endl;
	}
	int an=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(vi[i][j]){
				an++;
			}
		}
	}
	cout<<an<<endl;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		f();
	}
}

