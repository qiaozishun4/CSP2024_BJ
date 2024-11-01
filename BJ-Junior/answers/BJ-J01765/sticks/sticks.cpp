#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll cnt[10]={6,2,5,5,4,5,6,3,7,6};
ll maxx[10]={8,0,6,9,2,3,5,4,7,1};
ll need[N];
ll T;
ll ans,idx;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		ll n;
		cin>>n;
		if(n==1){
			cout<<-1;
		}
		else{
			for(ll i=0;i<9;i++){
				if(n>=cnt[maxx[i]]) need[++idx]=maxx[i];
			}
			sort(need+1,need+idx+1);
			for(ll i=1;i<=idx;i++) cout<<need[i];
		}
		cout<<"\n";
	}
	return 0;
}
