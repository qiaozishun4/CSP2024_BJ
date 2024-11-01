#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,g[20]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68},data[10]={88,108,188,200,208,288,688};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n<14) cout<<g[n]<<"\n";
		else{
			cout<<data[n%7];
			for(ll i=1;i<=n/7-2;i++) cout<<"8";
			cout<<"\n";
		}
	}//zpyzpy
	return 0;
}
