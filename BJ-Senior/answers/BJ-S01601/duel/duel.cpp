#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int a[N];
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=0,pre=-1,tmp=0;
    for(int i=1;i<=n;++i){
		if(a[i]!=pre){
			pre=a[i];
			tmp=0;
		}
		++tmp;
		ans=max(ans,tmp);
	}
	cout<<ans<<endl;
    return 0;
}
