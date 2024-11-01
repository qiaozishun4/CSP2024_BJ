#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn=2e5+7;
int n,ans=0;
int a[maxn];
int h(vector<bool>vec){
	int sum=0;
	for(int i=1;i<(int)vec.size();i++)
		for(int j=i-1;j>=0;j--)
			if(vec[i]==vec[j])
				sum+=(a[i+1]==a[j+1]?a[i+1]:0);
	return sum;
}
void dfs(int dep,vector<bool>vec){
	if(dep>n){
		ans=max(ans,h(vec));
		return;
	}
	vec.push_back(0);
	dfs(dep+1,vec);
	vec.pop_back();
	vec.push_back(1);
	dfs(dep+1,vec);
	vec.pop_back();
}
void solve(){
	cin>>n;
	if(n>15){
		cout<<0<<endl;
		return;
	}
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ans=0;
	vector<bool>vec={};
	dfs(1,vec);
	cout<<ans<<endl;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
	int T;cin>>T;
	while(T--) solve();
	return 0;
}
