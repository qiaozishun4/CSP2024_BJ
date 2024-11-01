#include<bits/stdc++.h>
using namespace std;
long long t,n,ans[100010];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n%7==0){
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
			cout<<"\n";
		}else if(n%7==1){
			cout<<10;
			n-=8;
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
			cout<<"\n";
		}
	}
	return 0;
}
