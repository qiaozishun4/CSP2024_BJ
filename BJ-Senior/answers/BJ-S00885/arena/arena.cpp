#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define LL long long



const int N=1e5+5,CF=20;
int aa[N],a[N],c[N],d[CF][N];
int n,m,K;
namespace suba{
	int ans[CF],buc[N];
	inline void init(){
		ans[0]=1;
		rep(i,1,n) {buc[i]=i;}
		rep(j,1,K){
			rep(i,1,(1<<(K-j))){
				int x=buc[(i<<1)+d[j][i]-1],y=buc[(i<<1)+(d[j][i]^1)-1];
				buc[i]=(a[x]>=j?x:y);
			}
			ans[j]=buc[1];
		}
	}
	inline void solve(){
		init();
		LL res=0;
		rep(i,1,m) {
			res^=(1ll*i*ans[(int)log2(c[i])]);
			//printf("%d ",ans[(int)log2(c[i])]);
		}
		printf("%lld\n",res);
	}
}
int T,X[4];
string s;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%d",&aa[i]);
	rep(i,1,m) scanf("%d",&c[i]);
	while((1<<K)<n) K++;
	rep(j,1,K){
		cin>>s;
		rep(i,1,(1<<(K-j))){
			d[j][i]=s[i-1]-'0';
			
		}
	}
	
	int flag=1;
	rep(i,1,m) if(c[i]!=(c[i]&-c[i])) flag=0;
	
	scanf("%d",&T);
	//printf("%d",T);
	while(T--){
		rep(i,0,3) scanf("%d",&X[i]);
		//printf("%d %d %d %d\n",X[0],X[1],X[2],X[3]);
		rep(i,1,n) a[i]=aa[i]^X[i%4];
		//rep(i,1,n) printf("%d ",a[i]);
		if(flag==1) suba::solve();
	}
    return 0;
}