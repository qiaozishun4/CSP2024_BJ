#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll num[]={6,2,5,5,4,5,6,3,7,6};
ll n,T;
ll serchno0(ll x){
	for(ll i=1;i<10;++i){
		if(num[i]==x)return i;
	}
	return -1;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n%7==0&&n>1){
			for(ll i=0;i<n/7;++i){
				cout<<8;
			}
		}else if(n%7==1&&n>1){
			cout<<10;
			for(ll i=0;i<n/7-1;++i){
				cout<<8;
			}
		}else if(n<=1){
			cout<<-1;
		}else if(n>=8){
			ll how=n/7-1;
			switch(n%7){
				case 2:
					cout<<18;
					break;
				case 3:
					cout<<22;
					break;
				case 4:
					cout<<20;
					break;
				case 5:
					cout<<28;
					break;
				case 6:
					cout<<68;
					break;
			}
			for(ll i=0;i<how;++i){
				cout<<8;
			}
		}else{
			cout<<serchno0(n);
		}
		cout<<endl;
	}
	return 0;
}
