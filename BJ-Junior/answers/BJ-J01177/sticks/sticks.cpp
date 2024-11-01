#include<string>
#include<stdio.h>
#include<iostream>
using namespace std;
int m[10]={6,2,5,5,4,5,6,3,7,6};
string ans;
inline string MIN(string a,string b){
	if(a.size()<b.size()) return a;
	if(a.size()>b.size()) return b;
	for(int i=0;i<a.size();i++){
		if(a[i]>b[i]) return b;
		if(a[i]<b[i]) return a;
	}
	return a;
}
void dfs(int n,string s){
	if(n==0){
		if(ans.size()==0) ans=s;
		else ans=MIN(ans,s);
		return;
	}
	if(n<2) return;
	for(int i=0;i<10;i++){
		if(i==0&&s.size()==0) continue;
		if(n<m[i]) continue;
		dfs(n-m[i],s+(char)('0'+i));
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		dfs(n,"");
		if(ans.size()==0) printf("-1\n");
		else cout<<ans<<"\n";
		ans="";
	}
	return 0;
}