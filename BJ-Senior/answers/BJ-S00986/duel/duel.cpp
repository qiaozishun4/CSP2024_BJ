#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
int p[100005];
int q,cnt1,cnt2;
int ans=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cnt1=0;
	cnt2=1;
	for(int i=1;i<=n;i++){
		if(i==1){
			q=a[i];
			cnt1=1;
			continue;
		}
		if(q!=a[i]){
			q=a[i];
			p[cnt2]=cnt1;
			cnt2++;
			cnt1=1;
		}else{
			cnt1++;
		}
	}
	p[cnt2]=cnt1;
	for(int i=1;i<cnt2;i++){
		p[i]=p[i]-p[i+1];
		if(p[i]<0){
			ans+=p[i];
			if(ans<0){
				ans=0;
			}
			p[i]=0;
		}
		ans+=p[i];
	}
	ans+=p[cnt2];
	cout<<ans;
	return 0;
}
