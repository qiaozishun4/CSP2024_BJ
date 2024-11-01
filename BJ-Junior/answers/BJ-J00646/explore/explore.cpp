#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	long long t,n,m,k,x,y,d;
	char map[1100][1100];
	cin>>t;
	while(t>0){
		bool visit[1100][1100]={false};
		long long sum=1;
		cin>>n >>m >>k;
		cin>>x >>y >>d;
		visit[x][y]=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>map[i][j];
			}
		}
		while(k!=0){
			if(d==0){
				if(y+1<=m&&map[x][y+1]!='x'){
					k--;
					if(!visit[x][y+1]){
						sum++;
						visit[x][y+1]=true;
					}
					y+=1;
				}else{
					d=(d+1)%4;
					k--;
				}
				
			}else if(d==1){
				if(x+1<=n&&map[x+1][y]!='x'){
					k--;
					if(!visit[x+1][y]){
						sum++;
						visit[x+1][y]=true;
					}
					x+=1;
				}else{
					d=(d+1)%4;
					k--;
				}
				
			}else if(d==2){
				if(y-1>=1&&map[x][y-1]!='x'){
					k--;
					if(!visit[x][y-1]){
						sum++;
						visit[x][y-1]=true;
					}
					y-=1;
				}else{
					d=(d+1)%4;
					k--;
				}
			}else{
				if(x-1>=1&&map[x-1][y]!='x'){
					k--;
					if(!visit[x-1][y]){
						sum++;
						visit[x-1][y]=true;
					}
					x-=1;
				}else{
					d=(d+1)%4;
					k--;
				}
			}
		}
		cout<<sum<<endl;;
		t--;
	}
	return 0;
}
