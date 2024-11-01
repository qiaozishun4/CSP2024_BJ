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
		int eight=n/7;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		if(n%7==1){
			cout<<10;
			eight--;
		}
		if(n%7==2){
			cout<<1;
		}
		if(n%7==3){
			if(n==3)	cout<<7;
			else
			{
				cout<<22;
				eight--;
			}
		}
		if(n%7==4){
			if(n==4)	cout<<4;
			else
			{
				cout<<20;
				eight--;
			}
		}
		if(n%7==5){
			cout<<2;
		}
		if(n%7==6){
			cout<<6;
		}
		for(int i=0;i<eight;i++){
			cout<<8;
		}	
		cout<<endl;
	}
	return 0;
}

