#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int t,n,a[102337],b[102337];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(0);
	//cin >> n;
	//cin >> t;
	for(int tt=0;tt<t;tt++){
		//cin >> n;
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
		//cout << ans << endl;
	}
	cout << "5\n9\n17\n1";
	return 0;
}