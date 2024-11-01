#include<bits/stdc++.h>
using namespace std;
int ar[100007],tong[100007],n,ans,size=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		tong[a]++;
	}
	for(int i=1;i<=100000;i++){
		if(tong[i]!=0){
			ar[++size]=tong[i];
		}
	}
	for(int i=2;i<=size;i++){
		//cout<<"i="<<i<<" ans="<<ans<<" "<<ar[i]<<" "<<ar[i-1]<<endl;
		if(ar[i]-ar[i-1]>0){
			ans-=ar[i]-ar[i-1];if(ans<0)ans=0;
		}
		else if(ar[i]-ar[i-1]<0){
			ans+=ar[i-1]-ar[i];
		}
	}ans+=ar[size];
	cout<<ans;
	return 0;
}