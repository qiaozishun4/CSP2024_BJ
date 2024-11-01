#include<bits/stdc++.h>
using namespace std;
int T,n,cd;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;++i){
		cin>>n;
		if(n<7){
			if(!n) cout<<-1;
			if(n==1) cout<<-1;
			if(n==2) cout<<1;
			if(n==3) cout<<7;
			if(n==4) cout<<4;
			if(n==5) cout<<2;
			if(n==6) cout<<6;
		}
		else{
			cd=n/7,n=n%7,cd--;
			if(!n) cout<<8;
			if(n==1) cout<<10;
			if(n==2) cout<<18;
			if(n==3){
				if(cd) cout<<200,cd--;
				else cout<<22;
			}
			if(n==4) cout<<20;
			if(n==5) cout<<28;
			if(n==6) cout<<68;
			while(cd) cout<<8,cd--;
		}
		cout<<"\n";
	}
	return 0;
}