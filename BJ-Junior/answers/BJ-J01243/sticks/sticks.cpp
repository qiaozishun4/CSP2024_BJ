#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T,n;
	cin>>T;
	while(T--){
		cin>>n;
		if(n%7==0){
			for(int i=1;i<=n/7;i++) cout<<"8";
		}else if(n%7==1){
			if(n==1) cout<<-1;
			else{
				cout<<10;
				for(int i=2;i<=n/7;i++) cout<<"8";
			}
		}else if(n%7==2){
			cout<<1;
			for(int i=1;i<=n/7;i++) cout<<"8";
		}else if(n%7==3){
			if(n==3) cout<<7;
			else{
				cout<<22;
				for(int i=2;i<=n/7;i++) cout<<"8";
			}
		}else if(n%7==4){
			if(n==4) cout<<4;
			else{
				cout<<20;
				for(int i=2;i<=n/7;i++) cout<<"8";
			}
		}else if(n%7==5){
			cout<<2;
			for(int i=1;i<=n/7;i++) cout<<"8";
		}else if(n%7==6){
			cout<<6;
			for(int i=1;i<=n/7;i++) cout<<"8";
		}
		cout<<"\n";
	}
	return 0;
}
