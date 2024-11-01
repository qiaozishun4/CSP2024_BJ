#include<bits/stdc++.h>
using namespace std;
const long long N=1e15;
long long n,use[1000010],sum,mn=N,num,a[1000010],t;
int st[10]={6,2,5,5,4,5,6,3,7,6};
void dfs(int d,int k){
	num=0,sum=0;
	if(d==k+1){
		for(int i=1;i<d;i++) sum+=st[a[i]];
		for(int i=2;i<d;i++)
			if(a[i]==6||a[i]==9) a[i]=0;
		int now=pow(10,d-1);
		for(int i=1;i<d;i++){
			num=num+a[i]*now;
			now/=10;
		}
		if(sum==n) mn=min(mn,num/10);
		return;
	}
	for(int i=1;i<=9;i++){
		if(!use[i]){
			a[d]=i;
			use[i]=1;
			dfs(d+1,k);
			use[i]=0;
		}
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sum=0,mn=N,num=0;
		memset(use,0,sizeof use);
		dfs(1,1);
		dfs(1,2);
		dfs(1,3);
		dfs(1,4);
		dfs(1,5);
		dfs(1,6);
		dfs(1,7);
		dfs(1,8);
		dfs(1,9);
		if(mn==N) cout<<-1<<endl;
		else cout<<mn<<endl;
	}
	return 0;
}