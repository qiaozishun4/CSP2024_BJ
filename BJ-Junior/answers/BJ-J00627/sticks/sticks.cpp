#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		if(n<2) cout<<-1<<endl;
		else if(n%7==0){
			for(int j=1;j<=n/7;j++) cout<<"8";
		}
		else if(n%7==1){
			cout<<10;
			n-=8;
			for(int j=1;j<=n/7;j++) cout<<"8";
		}
		else if(n%7==2){
			cout<<1;
			n-=2;
			for(int j=1;j<=n/7;j++) cout<<"8";
		}
		else if(n%7==3){
			if(n==3) cout<<7<<endl;
			else if(n==10) cout<<22<<endl;
			else{
				cout<<200;
				n-=17;
				for(int j=1;j<=n/7;j++) cout<<"8";
			}
		}
		else if(n%7==4){
			if(n==4) cout<<4<<endl;
			else{
				cout<<20;
				n-=11;
				for(int j=1;j<=n/7;j++) cout<<"8";
			}
		}
		else if(n%7==5){
			cout<<2;
			n-=2;
			for(int j=1;j<=n/7;j++) cout<<"8";
		}
		else if(n%7==6){
			cout<<6;
			n-=6;
			for(int j=1;j<=n/7;j++) cout<<"8";
		}
	}
	return 0;
}
