#include <bits/stdc++.h>
#define N 100010
using namespace std;
int n,a[N],sum[N],ans[N],anss,maxx;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[x]++;
		maxx=max(maxx,x);
	}
	for(int i=1;i<=maxx;i++){
		if(a[i]==0){
			sum[i]=sum[i-1];
			continue;
		}
//		cout<<"i="<<i<<endl;
		if(a[i]>=sum[i-1]){
//			cout<<"#1"<<endl;
			sum[i]=a[i];
			ans[i]=sum[i-1];
			anss+=ans[i];
		}
		else{
//			cout<<"#2"<<endl;
			sum[i]=sum[i-1]-a[i];
			ans[i]=a[i];
			anss+=ans[i];
		}
 //		cout<<a[i]<<' ';
//		cout<<sum[i]<<' '<<ans[i];
//		cout<<endl;
	}
	cout<<n-anss;
	return 0;
}

