#include<bits/stdc++.h>
using namespace std;
int num[15]={0,6,2,5,5,4,5,6,3,7,6};
int ans[100005];
int a[100005];
int ax=10000005;
int vis[100005];
void dfs(int n,int x){
	if(n<2){
		return ;
	}
	for(int i=1;i<=10;i++){
		if(n==num[i]){
			if(i==1) continue;
			a[x]=i-1;
			if(x<ax){
				for(int j=1;j<=x;j++){
					ans[j]=a[j];
				}
				ax=x;
			}
			else if(x==ax){
				bool f=0;
				for(int j=x;j>=1;j--){
					if(a[j]<ans[j]){
						f=1;
						break;
					}
				}
				if(f){
					for(int j=1;j<=x;j++) ans[j]=a[j];
				    ax=x;
				}
			}
			return ;
		}
		
	}
	for(int i=1;i<=10;i++){
		if(n>num[i]){
			a[x]=i-1;
			dfs(n-num[i],x+1);
		}
		
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n<2){
			cout<<-1<<endl;
			continue;
		}
		if(n%7==0){
			string s;
			for(int i=1;i<=n/7;i++){
				s+='8';
			}
			cout<<s;
			continue;
		}
		dfs(n,1);
		for(int i=ax;i>=1;i--)
			cout<<ans[i];
		cout<<endl;
		ax=1000005;
	}
    return 0;
}
