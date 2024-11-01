#include<bits/stdc++.h>
using namespace std;
void sol();
signed main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--) sol();
	return 0;
}
int a[]={6,2,5,5,4,5,6,3,7,6},n,box[100010];
//a每个数字的小木棍个数 b深捜时选数顺序
string ans;
bool operator<(string a,string b){
	if(a.size()!=b.size()) return a.size()<b.size();
	return a<b;
}
void dfs(int x,int sum,bool &f){
	if(sum>n) return;
	if(sum==n){
		string s="";
		for(int i=1;i<x;i++) s+=char(box[i]+48);
		if(s<ans) ans=s;
		f=1;
		return;
	}
	for(int i=0;i<10;i++){
		if(x==1&&i==0) continue;
		box[x]=i;
		dfs(x+1,sum+a[i],f);
	}
}
void sol(){
	ans="";
	for(int i=1;i<=1e5;i++) ans+='1';
	cin>>n;
	bool f=0;
	dfs(1,0,f);
	if(f==0) ans="-1";
	cout<<ans<<endl;
}
