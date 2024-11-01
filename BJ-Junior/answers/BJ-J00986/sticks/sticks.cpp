#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll oo=3e18;
int T;
ll n;

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		if(n==1){
			cout<<-1<<"\n";
			continue;
		}
		if(n==2){
			cout<<1<<"\n";
			continue;
		}
		if(n==3){
			cout<<7<<"\n";
			continue;
		}
		if(n==4){
			cout<<4<<"\n";
			continue;
		}
		if(n==5){
			cout<<2<<"\n";
			continue;
		}
		if(n==6){
			cout<<6<<"\n";
			continue;
		}
		ll k=n/7;
		ll tn=n-(k-1)*7;
		/*
		0->6
		1->2
		2->5
		3->5
		4->4
		5->5
		6->6
		7->3
		8->7
		9->6
		*/
		if(tn==7)
			cout<<"8";
		if(tn==8)
			cout<<"10";
		if(tn==9)
			cout<<"18";
		if(tn==10)
			cout<<"23";
		if(tn==11)
			cout<<"20";
		if(tn==12)
			cout<<"28";
		if(tn==13)
			cout<<"68";
		for(int i=1;i<k;i++)
			cout<<"8";
		cout<<"\n";
	}	
	return 0;
}
//LXT5201314