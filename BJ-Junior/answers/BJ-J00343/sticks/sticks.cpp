#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ll t,n;
	cin>>t;
	while(t--){
		cin>>n;
		if(n%7==1){
			cout<<"10";
			while(n>=15){
				cout<<"8";
				n-=7;
			}
		}
		else{
			while(n>=7){
				cout<<"8";
				n-=7;
			}
		}
	}
	return 0;
}