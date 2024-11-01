#include <bits/stdc++.h>
using namespace std;
int a[114]={-1,1,7,4,2,6,8,10,18,23,20,28,80,88,108,188,200,208,288,688};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		if(n%7==0){
			for(int j=1;j<=n/7;j++){
				cout<<8;
			}
			cout<<endl;
		}
		else if(n%7==1){
			cout<<10;
			for(int j=1;j<(n-1)/7;j++){
				cout<<8;
			}
			cout<<endl;
		}
		else cout<<a[n]<<endl;
	}
	return 0;
}
