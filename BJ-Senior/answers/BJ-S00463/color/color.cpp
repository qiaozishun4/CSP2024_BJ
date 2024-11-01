#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
#define REPG(i,h,x) for(int i=h[x];~i;i=edge[i].next)
#define CLR(a,x) memset(a,x,sizeof(a))
#define pii pair<int,int>

const int N=1005;
int T,n,a[N],ans;
bool col[N];
void dfs(int cur){
	if(cur==n+1){
		int lstA=0,lstB=0,Ans=0;
		for(int i=1;i<=n;i++){
			if(col[i]==0){
				if(a[i]==a[lstA]) Ans+=a[i];
				lstA=i;
			}else{
				if(a[i]==a[lstB]) Ans+=a[i];
				lstB=i;
			}
		}
		ans=max(ans,Ans);
		return;
	}
	dfs(cur+1);
	col[cur]=1,dfs(cur+1),col[cur]=0;
}
inline void solve(){
	scanf("%d",&n),ans=0,CLR(col,0);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1);
	printf("%d\n",ans);
}
int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
