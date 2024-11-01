#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int t,n;
	int a[100005],b[100005];
	string s[1000];
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>b[i];
		}
		for(int i=1;i<=n;i++){
			cin>>s[i];
		}
	}
	return 0;
}
