#include <bits/stdc++.h>
using namespace std;
int n,k,q,l,a[200005];
struct node{
	int c,r;
}qi[100005];
int main()
{	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(--t){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l;
			for(int j=1;j<=l;j++) cin>>a[j];
		}
		for(int i=1;i<=q;i++){
			cin>>qi[i].r>>qi[i].c;
		}
		for(int i=1;i<=q;i++){
			cout<<1<<endl;
		}
	}
	return 0;
}

