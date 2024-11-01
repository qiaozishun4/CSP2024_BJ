#include<bits/stdc++.h>
using namespace std;
void bei7(long long a){
	for(long long i=1;i<=a/7;i++){
		cout<<8;
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	long long T;
	cin>>T;
	for(int k=1;k<=T;k++){
		long long a;
		cin>>a;
		if(a%7==0){
			bei7(a);
			cout<<endl;
		}else if(a%7==1&&a!=1){
			cout<<10;
			bei7(a-8);
			cout<<endl;
		}else if(a<7){
			if(a==1) cout<<"-1"<<endl;
			else if(a==2) cout<<1<<endl;
			else if(a==3) cout<<7<<endl;
			else if(a==4) cout<<4<<endl;
			else if(a==5) cout<<2<<endl;
			else if(a==6) cout<<6<<endl;
		}
	}
	return 0;
}
