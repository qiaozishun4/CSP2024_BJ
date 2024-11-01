#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e5+5;
struct car{
	int v,a,d;
};
int T;
car a[N];
int L;
int V;
bool A=true;
bool f[N];
int p[N];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	int ans;
	while(T--){
		ans=0;
		int ll;
		cin>>n>>m>>L>>V;
		ll=m;
		for(int i=1;i<=n;i++){
			cin>>a[i].d>>a[i].v>>a[i].a;
			if(a[i].v>V){
				ans++;
				ll--;
			}
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		cout<<ans<<" "<<ll<<endl;
	}
	return 0;
}
