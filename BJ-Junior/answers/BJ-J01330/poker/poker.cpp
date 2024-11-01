#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 60;
int n, cnt;
struct dat{
	char h, d;
}a[N];
signed main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin>>n;
	for(int i = 1; i <= n; i++) {
		cin>>a[i].h>>a[i].d;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i+1; j <= n; j++) {
			if(a[i].h == a[j].h && a[i].d == a[j].d) cnt++;
		}
	}
	if(cnt != 0) cout<<52 - n + cnt<<endl;
	else cout<<52 - n<<endl;
	return 0;
}
