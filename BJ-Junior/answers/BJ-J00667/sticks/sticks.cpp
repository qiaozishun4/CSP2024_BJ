#include<iostream>
using namespace std;
int main(){
	int t,n;
	freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
	cin>>t;
	for(int j=0;j<t;j++){
		cin>>n;
		if(n%2==0){
			for(int i=0;i<n/2;i++){
				cout<<1;
			}
			cout<<endl;
		}else if(n%7==0){
			for(int i=0;i<n/7;i++){
				cout<<8;
			}
			cout<<endl;
		}else if(n%6==0){
			for(int i=0;i<n/6;i++){
				cout<<0;
			}
			cout<<endl;
		}else if(n%5==0){
			for(int i=0;i<n/5;i++){
				cout<<2;
			}
			cout<<endl;
		}else if(n%4==0){
			for(int i=0;i<n/4;i++){
				cout<<4;
			}
			cout<<endl;
		}else if(n%3==0){
			for(int i=0;i<n/3;i++){
				cout<<7;
			}
			cout<<endl;
		}else if(n==1){
			cout<<-1<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
	
	return 0;
}
