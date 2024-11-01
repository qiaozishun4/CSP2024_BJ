#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N],ans,vis[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int p2=2,p1=1;
	while(p2<=n&&p1<=n){
		if(a[p2]>a[p1]){
			vis[p1]=1;
			p1++,p2++;
		}else{
			p2++;
		}
	}
	for(int i=1;i<=n;i++) if(!vis[i]) ans++;
	cout<<ans;
	return 0;
}