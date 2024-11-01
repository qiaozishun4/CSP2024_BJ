#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
struct point{
	int x,y;
};
class rob{
	public:
	int d;
	point p;
	void T(){
		d=(d+1)%4;
	}
	point F(){
		point np = p;
		if(d==0)np.y++;
		if(d==1)np.x++;
		if(d==2)np.y--;
		if(d==3)np.x--;
		return np;
	}
};
bool maps[1005][1005];
bool vis[1005][1005]={false};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	for(int sogan=0;sogan<T;sogan++){
		memset(maps,0,sizeof(maps));
		memset(vis,0,sizeof(vis));
		
		int n,m,k,ans=0;
		rob r;
		cin>>n>>m>>k;
		int xo,yo,dz;
		cin>>xo>>yo>>dz;
		r.p.x=xo;
		r.p.y=yo;
		r.d=dz;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char mmp;
				cin>>mmp;
				if(mmp=='.')maps[i][j]=true;
				if(mmp=='x')maps[i][j]=false;
			}
		}
		for(int j=0;j<k;j++){
			if(vis[r.p.x][r.p.y]==false)vis[r.p.x][r.p.y]=true,ans++;//cout<<"visited "<<r.F().x<<','<<r.F().y<<endl;
			if(maps[r.F().x][r.F().y]&&(r.F().x>0&&r.F().x<=n&&r.F().y>0&&r.F().y<=m)){
				if(!vis[r.F().x][r.F().y])ans++,vis[r.F().x][r.F().y]=true;//cout<<"visited "<<r.F().x<<','<<r.F().y<<endl;
				r.p=r.F();
				//cout<<"from ("<<r.p.x<<','<<r.p.y<<")_ move to ("<<r.F().x<<','<<r.F().y<<")"<<endl;
			}else{
				//cout<<"turn"<<endl;
				r.T();
			}
		}
		cout<<ans<<endl;
	}
	
}
