#include<bits/stdc++.h>
//#define int long long
#define Pair pair<int,int>
using namespace std;
constexpr int N=1e5+5;
int n;
int a[N];
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	//cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int lst=0,cnt=0,max_=0;
	for(int i=1;i<=n;i++){
		if(a[i]==lst) cnt++;
		else lst=a[i],cnt=1;
		max_=max(max_,cnt);
	}
	cout<<max_<<'\n';
}