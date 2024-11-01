#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,k,q,num[100010],x,r,c;
vector<ll> v[100010];
map<ll,ll> ma;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>num[i];
			for(int j=1;j<=num[i];j++){
				cin>>x;
				v[i].push_back(x);
				if(j<=k&&j!=1) ma[x]++;
			}
		}for(int i=1;i<=q;i++){
			cin>>r>>c;
			if(r==1){
				if(ma[c]!=0) cout<<1<<endl;
				else cout<<0<<endl;
			}else cout<<1<<endl;
		}
	}
	return 0;
}