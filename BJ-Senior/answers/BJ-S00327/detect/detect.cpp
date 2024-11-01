#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
double d[N], v[N], a[N], p[N],wy[N];int vis[N];
int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int t,n,m;double L,V;
	cin>>t;
	while(t--){
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		sort(p+1,p+1+m);
		int cnt = 0;
		for(int i=1; i<=n; i++){
			if(v[i]>V&&d[i]<=p[m])cnt++;
		}
		cout<<cnt<<" "<<m-(cnt>0)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

