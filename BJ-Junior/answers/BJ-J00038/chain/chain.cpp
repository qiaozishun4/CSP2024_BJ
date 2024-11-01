#include<bits/stdc++.h>
using namespace std;

int T,n,m,cnt,x,mx,y,k,r,f,q,c,ct[200100];
struct node{
	int n,cnt,i;
}dp[210][200100];;
map<pair<int,int>,int> a;

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		mx=1;
		scanf("%d%d%d",&n,&k,&q);
		memset(dp,0,sizeof dp);
		dp[0][1].n=1;
		dp[0][1].i=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&m);
			ct[i]=m;
			cnt=1e9;
			for(int j=1;j<=m;j++){
				scanf("%d",&x);
				a[{i,j}]=x;
				cnt++;
				if(cnt>=2&&cnt<=k){
					dp[1][a[{i,j}]].n=1;
					if(dp[1][a[{i,j}]].i!=i)dp[1][a[{i,j}]].cnt++;
					dp[1][a[{i,j}]].i=i;
				}
				if(dp[0][a[{i,j}]].n==1&&(dp[0][a[{i,j}]].cnt>=2||dp[0][a[{i,j}]].i!=i)){
					cnt=1;
				}
			}
		}
		for(int u=1;u<=q;u++){
			scanf("%d%d",&r,&c);
			if(r>mx){
				for(int e=mx+1;e<=r;e++){
					for(int i=1;i<=n;i++){
						cnt=1e9;
						for(int j=1;j<=ct[i];j++){
							cnt++;
							//cout << cnt << endl;
							if(cnt>=2&&cnt<=k){
								dp[e][a[{i,j}]].n=1;
								if(dp[e][a[{i,j}]].i!=i)dp[e][a[{i,j}]].cnt++;
								dp[e][a[{i,j}]].i=i;
							}
							if(dp[e-1][a[{i,j}]].n==1&&(dp[e-1][a[{i,j}]].cnt>=2||dp[e-1][a[{i,j}]].i!=i)){
								cnt=1;
							}
						}
					}
				}
				mx=r;
			}
			printf("%d\n",dp[r][c].n);
		}
		//for(int i=1;i<=mx;i++){
		//	for(int j=1;j<=6;j++){
		//		cout << dp[1][j].n << ' ';
		//	}
		//	cout << endl;
		//}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
