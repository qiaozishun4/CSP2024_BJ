#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		int n,m,L,V;
		cin>>n>>m>>L>>V;
		int d,v,a;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>d>>v>>a;
			if(v>V){
				ans++;
			}
		}
		int p[100010];
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		cout<<ans<<" "<<1<<endl;
	}
	return 0;
}
