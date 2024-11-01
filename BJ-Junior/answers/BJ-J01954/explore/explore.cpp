#include<bits/stdc++.h>
using namespace std;
int qjx[4]={0,1,0,-1};
int qjy[4]={1,0,-1,0};
int ansx=0;
int T;
int n,m,k;
int rx,ry,rd;
int v[1005][1005];
char visit[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		cin>>rx>>ry>>rd;
		memset(v,0,sizeof(v));
		memset(visit,0,sizeof(visit));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>visit[i][j];
			}
		}
		ansx=1;
		v[rx][ry]=1;
		for(int i=1;i<=k;i++){
			rx+=qjx[rd];
			ry+=qjy[rd];
			if(rx>n||ry>m||visit[rx][ry]=='x'||rx<1||ry<1){
				rx-=qjx[rd];
				ry-=qjy[rd];
				rd=(rd+1)%4;
			}
			else{
				if(!v[rx][ry]){
					v[rx][ry]=1;
					ansx+=1;
				}
				
			}
			
		}

		cout<<ansx<<endl;
	}
		
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
