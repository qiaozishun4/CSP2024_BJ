#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int maxn=1e5+10;
int n,r[maxn],ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>r[i];
	sort(r+1,r+1+n);
	for(int i=2,j=1;i<=n;i++)
		if(r[i]>r[j]) ans++,j++;
	cout<<n-ans<<endl;
	return 0;
}
