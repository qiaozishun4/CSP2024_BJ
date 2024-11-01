#include<bits/stdc++.h>
using namespace std;
int T,n,k;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;k=0;
		if(n>14){k=n/7-1;n-=7*k;}
		if(n==1){cout<<"-1\n";continue;}
		if(n==2)cout<<1;
		if(n==3)cout<<7;
		if(n==4)cout<<4;
		if(n==5)cout<<2;
		if(n==6)cout<<6;
		if(n==7)cout<<8;
		if(n==8)cout<<10;
		if(n==9)cout<<17;
		if(n==10)cout<<23;
		if(n==11)cout<<20;
		if(n==12)cout<<60;
		if(n==13)cout<<68;
		if(n==14)cout<<88;
		for(int i=1;i<=k;i++)cout<<8;
		cout<<endl;
    }
	return 0;
}
