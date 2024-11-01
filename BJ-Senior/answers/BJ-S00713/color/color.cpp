#include<bits/stdc++.h>
using namespace std;
int t,n,a[102337],b[102337];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> t;
	for(int tt=0;tt<t;tt++){
		cin >> n;
		for(int i=1;i<=n;i++)cin >> a[i];
		int ans=0;
		for(int i=0;i<(1<<n);i++){
			int curans=0;
			int cod=i;
			for(int j=1;j<=n;j++){
				b[j]=(cod>>(j-1))%2;
			}
			int pre0=0,pre1=0;
			for(int j=1;j<=n;j++){
				if(b[j]){
					if(pre1&&a[pre1]==a[j])curans+=a[j];
					pre1=j;
				}else{
					if(pre0&&a[pre0]==a[j])curans+=a[j];
					pre0=j;
				}
			}
			ans=max(ans,curans);
		}
		cout << ans << endl;
	}
	return 0;
}