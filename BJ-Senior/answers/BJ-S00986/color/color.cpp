#include<bits/stdc++.h>
using namespace std;
int T;
int pre[200005];
long long sum[200005];
int a[200005];
int qz[1000005];
long long dpl[200005];
int maxx=-1;
int n;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]>maxx){
				maxx=a[i];
			}
			if(a[i]==a[i-1]){
				sum[i]+=a[i];
			}
			sum[i]+=sum[i-1];
			if(qz[a[i]]!=0){
				pre[i]=qz[a[i]];
			}
			qz[a[i]]=i;
		}
		for(int i=1;i<=n;i++){
			if(pre[i]!=0){
				if(i-pre[i]==1){
					dpl[i]=max(dpl[i-1],dpl[i-1]+a[i]);
				}else{
					if(pre[pre[i]+1]!=0){
						dpl[i]=max(dpl[i-1],dpl[pre[i]]+a[i]+a[pre[i]+1]+(sum[i-1]-sum[pre[i]+1]));
					}else{
						dpl[i]=max(dpl[i-1],dpl[pre[i]]+a[i]+(sum[i-1]-sum[pre[i]+1]));
					}
				}
			}else{
				dpl[i]=dpl[i-1];
			}
		}
		cout<<dpl[n]<<endl;
		for(int i=0;i<=n;i++){
			dpl[i]=0;
			sum[i]=0;
			pre[i]=0;
		}
		for(int i=0;i<=maxx;i++){
			qz[i]=0;
		}
		maxx=-1;
	}
	return 0;
}
