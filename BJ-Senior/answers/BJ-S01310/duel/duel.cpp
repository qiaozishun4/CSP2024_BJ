#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],vis[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int ans=n;
	for(int i=n,j=n-1;i>=1;i--){
		while((a[j]>=a[i]||vis[j])&&j>0)
			j--;
		if(j>0)vis[j]=1,j--,ans--;
	}
	cout<<ans<<endl;
	return 0;
}