#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=1e6+5;
int T,n,l[M],a[N],cnt,ans;
bool v[N];
void d(int w){
	if(w>n){
		cnt=0;
		int b=0,r=0;
		for(int i=1;i<=n;i++){
			if(v[i]){
				cnt+=(b==a[i]?a[i]:0);
				b=a[i];
			}else{
				cnt+=(r==a[i]?a[i]:0);
				r=a[i];
			}
		}
		ans=max(ans,cnt);
		return;
	}
	v[w]=0;
	d(w+1);
	v[w]=1;
	d(w+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		d(1);
		cout<<ans<<endl;
	}
	return 0;
}
