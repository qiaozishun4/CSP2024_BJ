#include<bits/stdc++.h>
using namespace std;

int T;
char MAP[1010][1010];
bool flag[1010][1010];

struct pos{
	int x;
	int y;
	int d;
	};

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	cin>>T;
	while(T--){
				
		pos now;
		int n,m,k;
		
		cin>>n>>m>>k;
		cin>>now.x>>now.y>>now.d;
		
				
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
			 flag[i][j]=0;//at first nobody came here
			}
		}
		
		flag[now.x][now.y]=1;//now somebody came here
		
		for(int i=1;i<=n;i++){
			string temp;
			cin>>temp;
			for(int j=0;j<m;j++){
				MAP[i][j+1]=temp[j];
			}
		}
		
		while(k--){//start walking
			
			if(now.d==0){
				if(now.x>=1 && now.x<=n && now.y+1>=1 && now.y+1<=m && MAP[now.x][now.y+1]=='.'){
					now.y=now.y+1;
					flag[now.x][now.y]=1;
				}
				else{
					now.d=(now.d+1)%4;
				}
			}
			else if(now.d==1){
				if(now.x+1>=1 && now.x+1<=n && now.y>=1 && now.y<=m && MAP[now.x+1][now.y]=='.'){
					now.x=now.x+1;
					flag[now.x][now.y]=1;
				}
				else{
					now.d=(now.d+1)%4;
				}
			}
			else if(now.d==2){
				if(now.x>=1 && now.x<=n && now.y-1>=1 && now.y-1<=m && MAP[now.x][now.y-1]=='.'){
					now.y=now.y-1;
					flag[now.x][now.y]=1;
				}
				else{
					now.d=(now.d+1)%4;
				}
			}
			else if(now.d==3){
				if(now.x-1>=1 && now.x-1<=n && now.y>=1 && now.y<=m && MAP[now.x-1][now.y]=='.'){
					now.x=now.x-1;
					flag[now.x][now.y]=1;
				}
				else{
					now.d=(now.d+1)%4;
				}
			}
			
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(flag[i][j]!=0)cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	
	return 0;
}