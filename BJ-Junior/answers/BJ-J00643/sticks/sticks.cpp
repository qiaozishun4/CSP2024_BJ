#include<bits/stdc++.h>
#define N 100005
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
void solve(int xx){
	int n=xx;
	if(n==1){
		cout<<-1<<endl;
	}
	if(n==2){
		cout<<1<<endl;
	}
	if(n==3){
		cout<<7<<endl;
	}
	if(n==4){
		cout<<4<<endl;
	}
	if(n==5){
		cout<<2<<endl;
	}
	if(n==6){
		cout<<6<<endl;
	}
	if(n==7){
		cout<<8<<endl;
	}
	if(n>7){
		int num=ceil((float)n/7.0);
		int first=0;
		for(int i=1;i<=9;i++){
			int kk,aa,bb;
			kk=n-a[i];
			aa=kk/6;
			if(aa==0){
				aa=1;
			}
			bb=kk-aa*6;
			if(aa+1==num && bb<=aa){
				first=i;
				n=n-a[i];
				break;
			}
		}
		cout<<first;
		while(n>7){
			n-=6;
			cout<<0;
		}		
		if(n==1){
			cout<<-1<<endl;
		}
		if(n==2){
			cout<<1<<endl;
		}
		if(n==3){
			cout<<7<<endl;
		}
		if(n==4){
			cout<<4<<endl;
		}
		if(n==5){
			cout<<2<<endl;
		}
		if(n==6){
			cout<<0<<endl;
		}
		if(n==7){
			cout<<8<<endl;
		}
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int x;
		cin>>x;
		solve(x);
	}
	return 0;
}