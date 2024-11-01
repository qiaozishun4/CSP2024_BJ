#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[15]={6,2,5,5,4,5,6,3,7,6};
bool c(ll n,ll res){
	ll sum=0;
	while(res){
		sum+=a[res%10];
		res/=10;
	}
	return n==sum;
}
ll check(ll n){
	ll res=1;
	while(!c(n,res)){
		res++;
		if(res>=100000){
			return -1;
		}
	}
	return res;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll x=check(n);
		cout<<x<<'\n';
	}
	return 0;
}