#include <bits/stdc++.h>
using namespace std;
const int N=2e5;
int T;
int n;
int a[N];
bool f[N];
int cnt;
int ans;
void fun(int k){
	if(k<=n){
		f[k]=0;
		fun(k+1);
		f[k]=1;
		fun(k+1);
		return;
	}
	cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(f[i]==f[j]){
				if(a[i]==a[j])
					cnt+=a[i];
				break;
			}
		}
	}
	ans=max(ans,cnt);
	return;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin >> a[i];
		fun(1);
		cout <<ans<<endl;
	}
	
	return 0;
}