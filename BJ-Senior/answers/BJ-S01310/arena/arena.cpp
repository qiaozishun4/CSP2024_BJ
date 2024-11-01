#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int T,n,m,k,_a[N],a[N],c[N];
vector <int> d[25];
vector <int> w[25];
int ans,now,sum[N];
void solve(){
	ans=0;
	for(int i=1;i<=(1<<k);i++)sum[i]=sum[i-1]+i;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=(1<<k-i);j++)
			w[i][j]=0;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=(1<<k-i);j++){
			int L=j*2-1,R=j*2,op=d[i][j];
			if(op==0){
				if(a[w[i-1][L]]>=i){
					w[i][j]=w[i-1][L];
				}else{
					w[i][j]=w[i-1][R];
				}
			}else{
				if(a[w[i-1][R]]>=i){
					w[i][j]=w[i-1][R];
				}else{
					w[i][j]=w[i-1][L];
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		ans^=(w[(int)(ceil(log2(c[i])))][1]*i);
	}
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;k=ceil(log2(n));
	for(int i=1;i<=n;i++)cin>>_a[i];
	for(int i=1;i<=m;i++)cin>>c[i];
	w[0].resize((1<<k)+5);
	for(int i=1;i<=(1<<k);i++)
		if(i<=n)w[0][i]=i;
		else w[0][i]=0;
	for(int i=1;i<=k;i++){
		d[i].resize((1<<k-i)+5);
		w[i].resize((1<<k-i)+5);
		string s;
		cin>>s;
		for(int j=1;j<=(1<<k-i);j++)
			d[i][j]=s[j-1]-'0';
	}
	cin>>T;
	while(T--){
		int x[4];
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(int i=1;i<=n;i++)
			a[i]=_a[i]^x[i&3];
		solve();
	}
	return 0;
}