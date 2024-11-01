#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
long long a[300005],c[300005],p=0;
bool b[300005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[n]==2){
		int ans=0,ans2=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}else{
				ans2++;
			}
		}
		cout<<n-min(ans,ans2)<<endl;
	}else{
		long long sum=0;
		while(n!=0){
			int now=0,k=0;
			for(int i=1;i<=n;i++){
				if(a[i]>now){
					k++;
					b[i]=1;
					now=a[i];
				}
			}
			sum++;
			p=0;
			for(int i=1;i<=n;i++){
				if(b[i]!=1){
					c[++p]=a[i];
				}
			}
			for(int i=1;i<=p;i++){
				a[i]=c[i];
				b[i]=0;
			}
			n=p;
		}
		cout<<sum<<endl;
	}
	return 0;
}