#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,num=1e9;
ll a[20][20]={{0},{0},{1},{7},{4},{2,3,5},{0,6,9},{8}};
ll b[20]={0,2,3,4,5,5,5,6,6,6,7};
ll ans[50];

void init(){
	num=1e9;
	for(ll i=0;i<=40;i++){
		ans[i]=0;
	}
}

void f(ll n,ll cnt){
	if(n==0){
		num=min(num,cnt);
		return;
	}
	if(n<2) return ;
	for(ll i=1;i<=10;i++){
		if(n-b[i]>=0){
/*			
			if(cnt==0&&b[i]==6){
				ans[cnt]=a[b[i]][1];
			}else{
				ans[cnt]=a[b[i]][0];
			}
*/		
			f(n-b[i],cnt+1);
		}
	}
}

void dfs(ll n,ll num,ll tot,ll cnt){
	if(tot==n&&cnt==num){
		return ;
	}
	for(ll i=2;i<=7;i++){
		if(n>=b[i]){
			if(cnt==0&&b[i]==6){
				ans[cnt]=a[b[i]][1];
			}else{
				ans[cnt]=a[b[i]][0];
			}
			dfs(n-b[i],num,tot+b[i],cnt+1);
		}
	}
}



int main(){
	
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);	
	
	cin>>t;
	while(t--){
		init();
		
		cin>>n;
		if(n<2){
			cout<<-1<<endl;
			continue;
		}
		if(n%7==0&&n>100){
			for(ll i=1;i<=n/7;i++){
				printf("8");
			}
			printf("\n");
			continue;
		}
		if((n-1)%7==0){
			printf("10");
			for(ll i=1;i<=(n-8)/7;i++){
				printf("8");
			}
			printf("\n");
			continue;
		}
		//几位数
		f(n,0);
		ll sum=num;
	//	cout<<num<<endl;
		
		dfs(n,num,0,0);
		
		
		for(ll i=0;i<sum;i++){
			cout<<ans[i];
		}
		cout<<endl;
		
	}
	
	
	return 0;
}
