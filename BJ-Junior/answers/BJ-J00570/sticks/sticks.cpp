#include <bits/stdc++.h>
using namespace std;
int t,m;
int check(int n){
	if(n<=1){
		return -1;
	}else{
		if(n%7==0){
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
			cout<<endl;
		}
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>m;
		cout<<check(m)<<endl;
	}
	return 0;
}
