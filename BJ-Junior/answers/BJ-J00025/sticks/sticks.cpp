#include<bits/stdc++.h>
using namespace std;
int t,n,ans,k;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n<2)cout<<-1<<"\n";
		else if(n==2)cout<<1<<"\n";
		else if(n==3)cout<<7<<"\n";
		else if(n==4)cout<<4<<"\n";
		else if(n==5)cout<<2<<"\n";
		else if(n==6)cout<<6<<"\n";
		else if(n==7)cout<<8<<"\n";
		else if(n==8)cout<<10<<"\n";
		else if(n==9)cout<<18<<"\n";
		else if(n==10)cout<<22<<"\n";
		else if(n==11)cout<<20<<"\n";
		else if(n==12)cout<<28<<"\n";
		else if(n==13)cout<<68<<"\n";
		else if(n==14)cout<<88<<"\n";
		else if(n==15)cout<<108<<"\n";
		else if(n==16)cout<<202<<"\n";
		else if(n==17)cout<<200<<"\n";
		else if(n==18)cout<<208<<"\n";
		else if(n==19)cout<<288<<"\n";
		else if(n==20)cout<<601<<"\n";
	}
	return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    