#include<iostream>
using namespace std;
typedef long long ll;
ll t;
const int N=1e5+5;
ll n,m,L,V;
ll a[N],d[N],v[N];
int main(){
	freopen("detet.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		ll ans=0;
		cin>>n>>m>>L>>V;
		for(int i=1; i<=n; i++){
			cin>>d[i]>>v[i]>>a[i];
			if(v[i]>V){
				ans++;
			}
		}
		cout<<ans<<" "<<m-2<<endl;
	}
	return 0;
}
