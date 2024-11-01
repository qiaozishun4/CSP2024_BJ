#include<bits/stdc++.h>
using namespace	std;
int a[100005];
long long maxn;
int n;
vector<int> red,blue;
void dfs(int x,long long ans){
	if(x==n+1){
		maxn=max(maxn,ans);
		return ;
	}
	red.push_back(a[x]);
	if(red.size()>1&&*(++red.rbegin())==a[x]) dfs(x+1,ans+a[x]);
	else dfs(x+1,ans);
	red.pop_back();
	
	blue.push_back(a[x]);
	if(blue.size()>1&&*(++blue.rbegin())==a[x]) dfs(x+1,ans+a[x]);
	else dfs(x+1,ans);
	blue.pop_back();
}
void fun(){
	maxn=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<maxn<<endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--) fun();
	return 0;
}
