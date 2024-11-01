#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define N 100005
#define ll long long
ll n,a[N],t[N],f[N],p,ans,m;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		t[a[i]]++;
	}
	for(int i=1;i<=MAXN;i++){
		f[i]=f[i-1]+t[i];
		if(f[i]==n){
			m=i;
			break;
		}
	}
	for(int i=1;i<=MAXN;i++){
		if(t[i]){
			p=p-t[i]<=0?0:p-t[i];
			if(p+t[i]<=f[m]-f[i]){
				ans+=t[i];
				p+=t[i];
			}
			else{
				ans+=f[m]-f[i];
				break;
			}
		}
	}
	printf("%lld",n-ans);
	return 0;
}
				
			
