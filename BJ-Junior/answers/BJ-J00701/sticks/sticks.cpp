#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int ans[100005];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	memset(ans,0x3f,sizeof(ans));
	ans[6]=0;
	for(int i=1;i<=100000;i++){
		int t=i,cnt=0;
		while(t){
			cnt+=a[t%10];
			t/=10;
		}
		if(ans[cnt]==0x3f3f3f3f) ans[cnt]=i;
	}
	int t;
	cin>>t;
	while(t--){
		int x;
		cin>>x;
		cout<<(ans[x]==0x3f3f3f3f?-1:ans[x])<<endl;
	}
	return 0;
}
