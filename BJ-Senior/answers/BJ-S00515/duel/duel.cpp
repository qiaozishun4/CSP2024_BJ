#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x,cnt;
map<ll,ll> mp;
vector<ll> s;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(),cout.tie();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;mp[x]++;
	}
	for(auto x:mp) s.push_back(x.second);
	for(int i=0;i<s.size();i++){
		if(i!=s.size()-1){
			int x=min(s[i],s[i+1]);
			s[i]-=x;cnt+=x;
			s[i+1]+=s[i];
		}
	}
	cout<<n-cnt<<"\n";
	return 0;
}
