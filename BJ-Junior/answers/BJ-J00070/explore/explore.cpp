#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int xx,yy,d;
bool mapa[1010][1010];
bool is[1010][1010];
int ans=1;
bool flag=0;
void dfs(int x,int y,int d,int step,int arrive){
	if(!is[x][y]){
			arrive++;
			is[x][y]=true;
	}
	if(step==k){
		 ans=arrive;
		 return ;
	 }
	 if(d==0&&y+1<=m&&mapa[x][y + 1]==true) dfs(x,y+1,d,step+1,arrive);
	 else if(d==1&&x+1<=n&&mapa[x+1][y]==true) dfs(x+1,y,d,step+1,arrive);
	 else if(d==2&&y-1>=1&&mapa[x][y-1]==true) dfs(x,y-1,d,step+1,arrive);
	 else if(d==3&&x-1>=1&&mapa[x-1][y]==true) dfs(x-1,y,d,step+1,arrive);
	 else{
		d=(d+1)%4;
		dfs(x,y,d,step+1,arrive);
	}
	return ;
	
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(is,false,sizeof(is));
		memset(mapa,false,sizeof(mapa));
//		cout<<1145;
		ans=1;
		flag=false;
		cin>>n>>m>>k>>xx>>yy>>d;
		string ch;
		for(int i=1;i<=n;i++){
			cin>>ch;
			for(int j=0;j<m;j++){
				if(ch[j]=='.') mapa[i][j+1]=true;
			}
//			cout<<i;
		}
//		cout<<514;
		is[xx][yy]=true;
		dfs(xx,yy,d,0,1);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
