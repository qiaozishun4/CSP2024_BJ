#include<bits/stdc++.h>
using namespace std;
const int N=1e3+3;
typedef long long ll;
ll mp[10];
void init(){
	mp[1]=2,mp[2]=5,mp[3]=5,mp[4]=4,mp[5]=5;
	mp[6]=6,mp[7]=3,mp[8]=7,mp[9]=6,mp[0]=6;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ll t;
	cin>>t;
	init();
	while(t--){
		ll num;
		cin>>num;
		string ans;
		while(num>0){
			for(ll i=0;i<=9;i++){
				if(ans.size()==0 && i==0) continue;
				if(num-i>=0){
					ans+=i+'0';
				}
				num-=mp[i];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
