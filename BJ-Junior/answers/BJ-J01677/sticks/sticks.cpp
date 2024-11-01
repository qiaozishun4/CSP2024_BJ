#include<bits/stdc++.h>
using namespace std;

int ans,n,m;
int d1,q;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>q;
	while(q--){
		cin>>n;
		if(n%7==0){
		for(int i=1;i<=n/7;i++){
			cout<<8;
		}
		cout<<endl;
		}
		else {
			cout<<108;
			for(int i=1;i<=(n-15)/7;i++){
			cout<<8;
			}cout<<endl;
		}
		
	}
	return 0;
}
