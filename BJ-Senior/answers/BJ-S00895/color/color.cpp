#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[200007],col[200007];
int ans=0,num=0;
void cal(){
	//for(int i=1;i<=n;i++)cout<<col[i]<<" "<<a[i]<<endl;
	for(int i=2;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(col[i]==col[j]){
				if(a[i]==a[j]){
					//cout<<"i="<<i<<" j="<<j<<" +="<<a[i]<<endl;
					num+=a[i];
				}
				break;
			}
		}
	}
	//cout<<num<<endl<<endl;
	ans=max(ans,num);
}
void dfs(int now){
	if(now==n){
		num=0;
		cal();
		return;
	}
	for(int i=1;i<=2;i++){
		col[now+1]=i;dfs(now+1);
	}col[now+1]=0;
	return;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(0);
		cout<<ans<<endl;ans=0;
	}
	return 0;
}
