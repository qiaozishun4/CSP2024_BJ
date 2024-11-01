#include<bits/stdc++.h>
using namespace std;
int abcd[9]={2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n<2){
			cout<<-1<<endl;
			continue;
		}
		bool f=0;
		for(int i=0;i<9;i++){
			if(abcd[i]==n){
				cout<<i+1<<endl;
				f=1;
				break;
			}
		}
		if(f)	continue;
		if(n%7==1){
			cout<<10;
			for(int i=1;i<=(n-8)/7;i++){
				cout<<8;
			}
			cout<<endl;
		}else if(n%7==2){
			cout<<1;
			for(int i=1;i<=(n-2)/7;i++){
				cout<<8;
			}
			cout<<endl;
		}else if(n%7==3){
			cout<<40;
			for(int i=1;i<=(n-10)/7;i++){
				cout<<8;
			}
			cout<<endl;
		}else if(n%7==4){
			cout<<20;
			for(int i=1;i<=(n-11)/7;i++){
				cout<<8;
			}
			cout<<endl;
		}else if(n%7==5){
			cout<<2;
			for(int i=1;i<=(n-5)/7;i++){
				cout<<8;
			}
			cout<<endl;
		}else if(n%7==6){
			cout<<6;
			for(int i=1;i<=(n-6)/7;i++){
				cout<<8;
			}
			cout<<endl;
		}else{
			cout<<200;
			for(int i=1;i<=n/7-2;i++){
				cout<<8;
			}
			cout<<endl;
		}
	}
	return 0;
}
