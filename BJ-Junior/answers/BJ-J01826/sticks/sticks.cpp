#include<bits/stdc++.h>
using namespace std;
int t,n,s[12]={6,2,5,5,4,5,6,3,7,6},an=INT_MAX;
void dfs(int no,int st,int a){
	if(st>n)return ;
	if(st==n){
		an=min(an,a);
		return ;
	}
	for(int i=0;i<10;i++){
		if(no==1&&i==0)continue;
		dfs(no+1,st+s[i],a*10+i);
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		dfs(1,0,0);
		if(an==INT_MAX)cout<<-1;
		else cout<<an;
		an=INT_MAX;
		cout<<'\n';
	}
	return 0;
}
