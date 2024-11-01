#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MX = 1e6 + 7;
int A[MX],las[MX],buc[MX];
ll f[MX];
int main(){
	ios :: sync_with_stdio(false);cin.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;cin >> T;
	while(T--){
		int N;cin >> N;
		for(int i = 1;i <= N;i++)cin >> A[i];
		for(int i = 1;i <= N;i++){las[i] = buc[A[i]];buc[A[i]] = i;}
		for(int i = 1;i <= N;i++)buc[A[i]] = 0;
		memset(f,-0x3f,sizeof(f));
		f[MX] = 0;ll mx = 0,d = 0;
		for(int i = 2;i <= N;i++){
			int u = i & 1,v = u ^ 1;ll val = (A[i] == A[i - 1] ? A[i] : 0);
			f[i - 1] = max(mx + d,f[las[i]] + A[i] + d) - d - val;mx = max(mx,f[i - 1]);
			d += val;
		}
		ll ans = 0;
		for(int i = 0;i < N;i++)ans = max(ans,f[i] + d);
		cout << ans << '\n';
	}
	return 0;
}