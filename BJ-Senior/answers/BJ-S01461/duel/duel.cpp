#include <bits/stdc++.h>
using namespace std;
#define LL long long

#define N 100007
#define m 100000
int r[N],cnt[N];

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>r[i];
	sort(r+1,r+n+1);
	// for(int i=1;i<=n;i++) cout<<r[i]<<' ';
	// cout<<'\n';
	
	int p1=1,p2=1;
	for(;;){
		// cout<<p1<<' ';
		while(r[p2]<=r[p1]&&p2<=n) p2++;
		if(p2>n) {p1--;break;}
		// cout<<p2<<'\n';
		p2++;
		if(p2>n) break;
		p1++;
	}
	cout<<n-p1<<'\n';

    return 0;
}
