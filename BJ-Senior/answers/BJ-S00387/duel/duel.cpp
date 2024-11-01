#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=1e5+10;
int n,a[maxn],t[maxn];
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
	}
	int ans=-1;
	for(int i=1;i<=1e5;i++){
		ans=max(ans,t[i]);
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
