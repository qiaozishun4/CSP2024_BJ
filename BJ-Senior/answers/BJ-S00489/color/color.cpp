#include<bits/stdc++.h>
using namespace std;
int kl[1000000],cnt[1000005]={0};
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,sum=0,maxn=-1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>kl[i];
			cnt[kl[i]]++;
			maxn=max(kl[i],maxn);
		}
		for(int i=1;i<=maxn;i++){
			if(cnt[i]>1){
				sum+=(cnt[i]-1)*i;
			}
		}
		cout<<sum<<endl;
		memset(cnt,0,sizeof(cnt));
	}
	return 0;
}