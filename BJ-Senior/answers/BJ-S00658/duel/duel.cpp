#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn=1e5+7;
int n,ans=0;
int tong[maxn];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
	cin>>n;
	int mx=0;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		tong[x]++;
		mx=max(mx,x);
	}
	for(int i=1;i<=mx;i++)
		ans=max(ans,tong[i]);
	cout<<ans<<endl;
	return 0;
}
