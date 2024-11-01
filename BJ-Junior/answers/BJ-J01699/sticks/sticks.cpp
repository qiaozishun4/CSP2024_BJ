#include<bits/stdc++.h>
using namespace std;

int T;
int n;

int main(){
	
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	cin>>T;
	
	while(T--){
		
		cin>>n;
		
		if(n<2){
			cout<<-1<<endl;
			continue;
		}
		
		if(n==6){
			cout<<6<<endl;
			continue;
		}
		
		if(n==2){
			cout<<1<<endl;
			continue;
		}
		
		if(n==5){
			cout<<2<<endl;
			continue;
		}
		
		if(n==4){
			cout<<4<<endl;
			continue;
		}
		
		if(n==3){
			cout<<7<<endl;
			continue;
		}
		
		if(n==7){
			cout<<8<<endl;
			continue;
		}
		
		if(n%7==0&&n>=100){//speical A
			while(n){
				cout<<8;
				n-=7;
			}
			cout<<endl;
			continue;
		}
		
		if(n%7==1&&n>=100){//speical B
			while(n!=8){
				cout<<8;
				n-=7;
			}
			cout<<1<<6;
			cout<<endl;
			continue;
		}
		
	}
	
	return 0;
}