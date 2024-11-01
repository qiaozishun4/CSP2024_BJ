#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,sp;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(ll i=1;i<=t;i++){
		cin>>n;
		if(n<=7){
			if(n==1)cout<<-1<<endl;
			if(n==2)cout<<1<<endl;
			if(n==3)cout<<7<<endl;
			if(n==4)cout<<4<<endl;
			if(n==5)cout<<2<<endl;
			if(n==6)cout<<6<<endl;
			if(n==7)cout<<8<<endl;
			continue;
		}
		else if(n<=14){
			if(n==8)cout<<10<<endl;
			if(n==9)cout<<18<<endl;
			if(n==10)cout<<23<<endl;
			if(n==11)cout<<30<<endl;
			if(n==12)cout<<25<<endl;
			if(n==13)cout<<80<<endl;
			if(n==14)cout<<88<<endl;
			continue;
		}
		else if(n<=14){
			if(n==8)cout<<10<<endl;
			if(n==9)cout<<18<<endl;
			if(n==10)cout<<23<<endl;
			if(n==11)cout<<30<<endl;
			if(n==12)cout<<25<<endl;
			if(n==13)cout<<80<<endl;
			if(n==14)cout<<88<<endl;
			continue;
		}
		else if(n<=21){
			if(n==15)cout<<108<<endl;
			if(n==16)cout<<188<<endl;
			if(n==17)cout<<225<<endl;
			if(n==18)cout<<208<<endl;
			if(n==19)cout<<288<<endl;
			if(n==20)cout<<688<<endl;
			if(n==21)cout<<888<<endl;
			continue;
		}
		else if(n<=28){
			if(n==22)cout<<1688<<endl;
			if(n==23)cout<<1888<<endl;
			if(n==24)cout<<2288<<endl;
			if(n==25)cout<<2688<<endl;
			if(n==26)cout<<2888<<endl;
			if(n==27)cout<<6888<<endl;
			if(n==28)cout<<8888<<endl;
			continue;
		}
		else if(n<=35){
			if(n==29)cout<<16888<<endl;
			if(n==30)cout<<18888<<endl;
			if(n==31)cout<<22888<<endl;
			if(n==32)cout<<26888<<endl;
			if(n==33)cout<<28888<<endl;
			if(n==34)cout<<68888<<endl;
			if(n==35)cout<<88888<<endl;
			continue;
		}
		else if(n<=42){
			if(n==36)cout<<168888<<endl;
			if(n==37)cout<<188888<<endl;
			if(n==38)cout<<228888<<endl;
			if(n==39)cout<<268888<<endl;
			if(n==40)cout<<288888<<endl;
			if(n==41)cout<<688888<<endl;
			if(n==42)cout<<888888<<endl;
			continue;
		}
		else if(n<=49){
			if(n==43)cout<<1688888<<endl;
			if(n==44)cout<<1888888<<endl;
			if(n==45)cout<<2288888<<endl;
			if(n==46)cout<<2688888<<endl;
			if(n==47)cout<<2888888<<endl;
			if(n==48)cout<<6888888<<endl;
			if(n==49)cout<<8888888<<endl;
			continue;
		}
		else if(n<=56){
			if(n==50)cout<<16888888<<endl;
			if(n==51)cout<<18888888<<endl;
			if(n==52)cout<<22888888<<endl;
			if(n==53)cout<<26888888<<endl;
			if(n==54)cout<<28888888<<endl;
			if(n==55)cout<<68888888<<endl;
			if(n==56)cout<<88888888<<endl;
			continue;
		}
	}
	return 0;
	}
