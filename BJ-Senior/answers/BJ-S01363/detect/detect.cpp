#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
using namespace std;
int t;
const int N=1e5+10;
int path[N];
struct node{
	int d,v,a;
}b[N];
int p[N];
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>t;
	while(t--){
		memset(path,0,sizeof(path));
		int n,m,L,V;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>b[i].d>>b[i].v>>b[i].a;
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
			path[p[i]]=-1;
		}
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
			if(b[i].v>V){
				cnt1++;
				for(int j=i;j<=n;j++){
					if(path[j]==-1){
						cnt2++;
					}
				}
			}
		}
		cout<<cnt1<<" "<<m-cnt2<<'\n';
	}
	return 0;
}