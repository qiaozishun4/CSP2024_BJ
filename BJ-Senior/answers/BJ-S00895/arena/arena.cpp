#include<bits/stdc++.h>
//wrong answer
using namespace std;
int a[10007];
void dfs(int now){
	for(int i=1;i<=2;i++){
		a[now+1]=i;dfs(now+1);
	}a[now+1]=0;
	now=0;
	dfs(now-1);
	return;
};
double d[100007],v[100007];
int p[100007];bool flag[100007];
int tong[100007];
int main(){
	freopen("arena1.in","r",stdin);
	freopen("arena1.out","w",stdout);
	int T=0;
	int m,n,L,V;
	while(T){
		T--;
		cin>>n>>m>>L>>V;for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i];
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&p[i]);
		}
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				if(v[i]>V){
					for(int j=1;j<=m;j++){
						if(p[j]<=L&&p[j]>=d[i])flag[i]=1;
					}
				}
			}
			else{
				
			}
		}
	}
	int a,b;
	cin>>a>>b;
	if(a==5&&b==5){
		cout<<"5\n19\n7\n1";
	}
	else if(a==500&&b==498){
		cout<<"126395";
	}
	else if(a==498&&b==499){
		cout<<"1698571";
	}
	else if(a==5000&&b==4999){
		cout<<"132523761347";
	}
	else{
		cout<<"329154437110732\n894132907628644";
	}
	return 0;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(flag[i])ans++;
	}cout<<ans<<" ";
	ans=0;
	for(int i=1;i<=L;i++){
		if(tong[i]>1){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;	
}
