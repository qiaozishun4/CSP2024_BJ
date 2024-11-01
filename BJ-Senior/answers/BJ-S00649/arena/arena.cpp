#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int maxn=1e5+10;
int n,m,A[maxn],c[maxn],a[maxn],X[5],pw[maxn],k;
int b[maxn];
bool d[20][maxn],vis[maxn];
int cur[maxn],nxt[maxn],tot;
void solve(int x){
	int K=log2(x);
	for(int i=1;i<=x;i++) cur[i]=i;
	for(int j=1;j<=K;j++){
		tot=0;
		for(int i=1;i<=1<<(K-j);i++){
			int p=2*i,q=2*i-1;
			if(d[j][i]){
				if(b[cur[p]]>=j) nxt[i]=cur[p];
				else nxt[i]=cur[q];
			}
			else{
				if(b[cur[q]]>=j) nxt[i]=cur[q];
				else nxt[i]=cur[p];
			}
		}
		for(int i=1;i<=1<<(K-j);i++) cur[i]=nxt[i];
	}
	vis[cur[1]]=1;
}
void so(){
	ll res=0;
	cin>>X[0]>>X[1]>>X[2]>>X[3];
	for(int i=1;i<=n;i++) a[i]=A[i]^X[i%4];
	//if(is0){s2();return;}
	for(int i=1;i<=m;i++){
		int x=pw[lower_bound(pw,pw+1+20,c[i])-pw];
		for(int j=1;j<=c[i];j++) b[j]=a[j];
		for(int j=0;j<1<<(x-c[i]);j++){
			for(int l=0;l<x-c[i];l++) b[c[i]+1+l]=(j>>l&1)?INT_MAX:0;
			solve(x);
		}
		ll ans=0;
		for(int j=1;j<=x;j++){
			if(vis[j]) ans+=j;
			vis[j]=0;
		}
		res^=1ll*i*ans;
	}
	cout<<res<<endl;
}
bool is2n=1,is0=1;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("arena.in","r",stdin);
	freopen("arena,out","w",stdout);
	pw[0]=1;
	for(int i=1;i<=20;i++) pw[i]=pw[i-1]*2;
	cin>>n>>m;
	k=lower_bound(pw,pw+1+20,n)-pw;
	for(int i=1;i<=n;i++) cin>>A[i];
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	for(int i=1;i<=k;i++){
		char ch;
		for(int j=1;j<=1<<(k-i);j++) cin>>ch,d[i][j]=ch-'0',is0&=!d[i][j];
	}
	int t;cin>>t;
	while(t--) so();
	return 0;
}
