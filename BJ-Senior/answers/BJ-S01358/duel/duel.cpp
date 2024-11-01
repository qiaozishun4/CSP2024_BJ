#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+6;
ll n,cnt=0,a[N],vis[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			for(int j=n;j>=1;j--){
				if(a[i]>a[j] && !vis[j]){
					vis[j]=1;
					cnt++;
					cout<<a[i]<<" "<<a[j]<<endl;
					break;
				}
			}
		}
	}
	cout<<n-cnt;
	return 0;
}
