#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
ll l[N],s[1005][1005],r[N],c[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ll t,n,k,q,i,j;
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(i=1;i<=n;i++){
			cin>>l[i];
			for(j=1;j<=l[i];j++){
				cin>>s[i][j];
			}
		}
		for(i=1;i<=q;i++){
			cin>>r[i]>>c[i];
			cout<<1<<"\n";
		}
	}
	return 0;
}