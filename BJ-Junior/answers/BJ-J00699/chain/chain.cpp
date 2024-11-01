#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int t,n,k,q,x,l,jl,a,b;
vector<int> ad[100005];
bool vi[200005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.ans","w",stdout);
	cin>>t;
	while (t--){
		cin>>n>>k>>q;
		for (int i=1;i<=n;i++){
			cin>>l;
			for (int j=1;j<=l;j++){
				cin>>x;
				ad[i].push_back(x);
				if (j-jl+1<=k)
					vi[x]=1;
				if (x==1){
					jl=j;
					continue;
				}
			}
		}
		for (int i=1;i<=q;i++){
			cin>>a>>b;
			cout<<vi[b]<<'\n';
		}
	}
	return 0;
}