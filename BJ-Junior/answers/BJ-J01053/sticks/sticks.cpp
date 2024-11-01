

#include<bits/stdc++.h>
using namespace std;
int n;
void f(){
	int fl=0;
	if(n<7){
		if(n==1){
			cout<<-1;
		}else if(n==2){
			cout<<1;
		}else if(n==3){
			cout<<7;
		}else if(n==4){
			cout<<4;
		}else if(n==5){
			cout<<2;
		}else if(n==6){
			cout<<6;
		}
		cout<<endl;
		return ;
	}
	int x=n%7;
	if(x==0){
		cout<<6;
		x=(n-14)/7;
		fl=1;
	}else if(x==1){
		cout<<10;
		x=(n-8)/7;
	}else if(x==2){
		cout<<18;
		x=(n-9)/7;
	}else if(x==3){
		cout<<22;
		x=(n-10)/7;
	}else if(x==4){
		cout<<20;
		x=(n-11)/7;
	}else if(x==5){
		cout<<2;
		x=(n-5)/7;
	}else if(x==6){
		cout<<2;
		x=(n-13)/7;
		fl=1;
	}
	for(int i=0;i<x;i++){
		cout<<8;
	}
	if(fl==1){
		cout<<9;
	}
	cout<<endl;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		f();
	}
} 
