#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans=0x3f3f3f3f;
int cost[10]={6,2,5,5,4,5,6,3,7,6};
int pre[10]={0,10,1,200,20,2,6};
int first[10]={0,-1,1,7,4,2,6};
int second[10]={8,10,18,22,20,28,68};
void dfs(ll now,int last,bool k){
	if(now>ans)return;
	if(last==0){
		ans=min(ans,now);
		return ;
	}
	for(int i=9;i>=0;i--){
		if(i==0&&k)continue;
		if(cost[i]>last)continue;
		dfs(now*10+i,last-cost[i],0);
	}	
}
int main(){
freopen("sticks.in","r",stdin);
freopen("sticks.out","w",stdout);
//freopen("1.in","r",stdin);
//freopen("1.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		if(n/7==0)cout<<first[n%7]<<endl;
		else if(n/7==1)cout<<second[n%7]<<endl;
		else{
			if(pre[n%7])cout<<pre[n%7];
			int tmp=pre[n%7];
			while(tmp){
				n-=cost[tmp%10];
				tmp/=10;
			}
			for(int i=1;i<=n/7;i++)cout<<"8";
			cout<<endl;
		}
	}
	return 0;
}