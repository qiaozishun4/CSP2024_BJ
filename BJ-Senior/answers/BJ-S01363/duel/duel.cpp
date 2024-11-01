#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int n;
const int N=1e6;
int a[N];
bool v[N],w[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]>a[i]&&!v[j]&&!w[j]){
				v[i]=1;
				w[j]=1;
				break;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}