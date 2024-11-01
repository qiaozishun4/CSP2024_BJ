#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n%8==0){
			int k=n/8;
			while(k--){
				cout<<9;
			}
			cout<<endl;
		}else if(n%7==0){
			int k=n/7;
			while(k--){
				cout<<8;
			}
			cout<<endl;
		}else if(n%7==1){
			int k=n%7;
			k--;
			cout<<10;
			while(k--){
				cout<<8;
			}
			cout<<endl;
		}else{
			cout<<-1;
		}	
	}
	return 0;
}
