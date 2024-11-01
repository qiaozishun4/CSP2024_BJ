#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn=1e5+7;
int n,k,q,ans=0;
vector<int>vec[maxn];
void solve(){
	cin>>n>>k>>q;
	for(int i=1;i<=n;i++){
		int l;cin>>l;
		vec[i].push_back(l);
		for(int j=1;j<=l;j++){
			int x;cin>>x;
			vec[i].push_back(x);
		}
	}
	while(q--){
		int r,c;
		cin>>r>>c;
		if(r==1){
			bool f=0;
			for(int i=1;i<=n;i++){
		//		int begin=0,endin=0;
				for(int j=1;j<=vec[i][0];j++)
					if(vec[i][j]==1){
						for(int l=j;l<=min(j+k,vec[i][0]);l++)
							if(vec[i][l]==c) {f=1;break;}
						if(f) break;
					}
				if(f) break;
			}
			cout<<(int)f<<endl;
			continue;
		}
		cout<<0<<endl;
	}
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
	int T;cin>>T;
	while(T--) solve();
    return 0;
}
