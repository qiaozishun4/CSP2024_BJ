#include <bits/stdc++.h>
using namespace std;
int t,n,K,q,l,x,r,c;
vector <int> a[100010];
bool dfs(int step,int last,int lp){
	for(int i=1;i<=n;i++){
		if(i==lp) continue;
		int len=a[i].size();
		for(int j=0;j<len;j++){
			if(a[i][j]==last){
				for(int k=j+1;k<len && k<=j+K-1;k++){
					if(step==r){
						if(a[i][k]==c) return true;
						continue;
					}
					if(dfs(step+1,a[i][k],i)) return true;
				}
			}
		}
	}
	return false;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>K>>q;
		for(int i=1;i<=n;i++){
			cin>>l;
			for(int j=1;j<=l;j++){
				cin>>x;
				a[i].push_back(x);
			}
		}
		while(q--){
			cin>>r>>c;
			if(dfs(1,1,0)) cout<<1;
			else cout<<0;
			cout<<"\n";
		}
		for(int i=1;i<=n;i++){
			a[i].clear();
		}
	}		
	return 0;
}
