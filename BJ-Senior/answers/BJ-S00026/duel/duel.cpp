#include<bits/stdc++.h>
using namespace std;
int n, r[100010], k[100010], cnt=0, q=0,ans=0;
bool cmp1(int a, int b){
	return a<b;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		k[i]=0;
	}
	for(int i=0;i<n;i++){
		cin>>r[i];
	}
	sort(r,r+n,cmp1);
	
	q=r[0];
	for(int i=0;i<n;i++){
		if(r[i]!=q){
			cnt++;
			q=r[i];
		}
		k[cnt]++;
	}
	ans=k[0];
	for(int i=1;i<=cnt;i++){
		ans-=k[i];
		if(ans<0){
			ans=0;
		}
		ans+=k[i];
	}
	cout<<ans;
	return 0;
}