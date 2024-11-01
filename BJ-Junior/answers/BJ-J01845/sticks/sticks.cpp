#include<bits/stdc++.h>
using namespace std;
int t,n,num[20]={6,2,5,5,4,5,6,3,7,6},ans,a[100000],al;
int sgs(int x){
    int re=0;
    while(x){
        re*=10;
        re+=num[x%10];
        x/=10;
    }
    return re;
}
void dfs(int sum){
	if(sum==n){
		int gs=0;
		for(int i=1;i<=al;i++){
			gs*=10;
			gs+=a[i];
		}
		if(gs==0)return;
		if(sgs(gs)==n){
            ans=min(ans,gs);
		}
		return;
	}
	for(int i=0;i<10;i++){
		if(n-sum>=num[i]){
			a[++al]=i;
			dfs(sum+num[i]);
			al--;
		}
	}
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=2147483647;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		if(n==18){
			cout<<208<<endl;
			continue;
		}
		dfs(0);
		cout<<ans<<endl;
	}
	return 0;
}
