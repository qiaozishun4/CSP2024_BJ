#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],f[N];
int n;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a+1,a+n+1);
	int l=1;
	f[1]=1;
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]){
			f[++l]=1;
		}
		else{
			f[l]++;
		}
	}
	int ans=0,t;
	t=f[1];
	for(int i=2;i<=l;i++){
		if(f[i]>t){
			ans+=t;
			t=f[i];
		}
		else{
			ans+=f[i];
		}
	}
	cout<<n-ans<<endl;
	return 0;
}
