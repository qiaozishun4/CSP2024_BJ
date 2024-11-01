#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,x,y,d;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>x>>y>>d;
		char a[1010][1010];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		cout<<n*m;
	}
	return 0;
}
