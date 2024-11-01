#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=2e5+5;
vector<int>v[N];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		freopen("chain.in","r",stdin);
		freopen("chain.out","w",stdout);
		int n,maxlen,q,i,j,k;
		scanf("%d%d%d",&n,&maxlen,&q);
		for(i=1;i<=n;++i){
			int size;
			scanf("%d",&size);
			//cout<<size<<endl;
			int x;
			for(j=1;j<=size;++j){
				scanf("%d",&x);
				v[i].push_back(x);
				cout<<v[i][j-1]<<" ";
			}
			cout<<endl;
		}
		for(i=1;i<=q;++i){
			bool ans=0;
			int x,y;
			scanf("%d%d",&x,&y);
			int cnt=10000000;
			for(j=1;j<=n;++j){
				for(k=0;k<v[j].size();++k){
					if(v[j][k]==1)cnt=k;
					cout<<j<<" "<<cnt<<endl;
					if(v[j][k]==y&&k-cnt+1>=2&&k-cnt+1<=maxlen)ans=1;
					if(ans)break;
				}
				if(ans)break;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=2e5+5;
vector<int>v[N];
int size[N];
int dp[M][105],dp1[M][105];
int xw1[N],xw2[N],ans[N];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(dp,0,sizeof(dp));
		memset(dp1,0,sizeof(dp1));
		int n,maxlen,q,i,j,k,maxv=0,r=0;
		scanf("%d%d%d",&n,&maxlen,&q);
		for(i=1;i<=n;++i){
			int size;
			scanf("%d",&size);
			for(j=1;j<=size;++j)scanf("%d",&v[i][j]);
			maxv=max(maxv,v[i][j]);
		}
		for(i=1;i<=q;++i){
			scanf("%d%d",&xw1[i],&xw2[i]);
			r=max(r,xw1[i]+1);
		}
		dp[1][1]=1;
		for(i=1;i<=r;++i){
			for(j=1;j<=n;++j){
				if(dp1[dp[i]][i]){//ru guo bu neng zai zai di i+1 lun xuan ci hang
					continue;
				}
				for(k=1;k<=size[j];++k){
					int dy=1000000;
					for(int o=1;o<=maxv;++o){
						if(dp[o]==i&&v[j][k]==o){//ke yi yong ci xiang zuo wei ci lun jie long kai tou
							dy=k;
							break;
						}
					}
					if(k-dy+1>=2&&k-dy+1<=maxlen){//ke yi yong ci xiang zuo wei ci lun jie long jie wei
						if(!(dp1[v[j][k]!=0&&dp1[v[j][k]!=j))dp1[v[j][k]][i+1]=j;
						dp[v[j][k]]=i+1;
					}
				}
			}
		}
		for(i=1;i<=q;++i)
					
	}
	return 0;
}
*/
