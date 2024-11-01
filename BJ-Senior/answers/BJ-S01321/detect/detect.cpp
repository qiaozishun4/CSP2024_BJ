#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100001];
int n,m,l,V;
int d[3001];
int v[3001];
int p[3001];
int st[3001][3001];
int c[3001];
int ans;
int arr1[3001];
int arr[3001];
int brr[3001];
int tmp[3001][2];
bool check(int i,bool fl){
	int j=1;
	if(fl){
		j=m;
		for(;j<=m;j++){
			if(p[j]<d[i])continue;
			int V1=v[i]*v[i]+2*a[i]*(p[j]-d[i]);
			if(V1>V*V)return 1;
		}
	}
	else{
		for(;j<=m;j++){
			if(p[j]<d[i])continue;
			int V1=v[i]*v[i]+2*a[i]*(p[j]-d[i]);
			if(V1>V*V)st[j][i]=1,arr1[i]++;
		}
	}
	return 0;
}
void dfs(int i,int cnt,string arr2){
	if(i==m+1){
		for(int o=1;o<=n;o++){
			arr[o]=arr1[o];
			for(int j=1;j<=m;j++){
				if(arr2[j]=='0')continue;
				if(st[j][o])arr[o]--;
			}
		}
		bool fl=0;
		for(int j=1;j<=n;j++)if(arr[j]<0||(!arr[j]&&arr1[j]))fl=1;
		if(fl)return ;
		ans=max(ans,cnt);
		return ;
	}
	dfs(i+1,cnt,arr2+'0');
	dfs(i+1,cnt+1,arr2+'1');
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	cin>>n>>m>>l>>V;
	bool f1=1;
	for(int i=1;i<=n;i++){
		cin>>d[i]>>v[i]>>a[i];
		if(a[i]<0)f1=0;
	}
	for(int i=1;i<=m;i++)cin>>p[i];
	if(f1){
		for(int i=1;i<=n;i++)c[i]=check(i,1);
		bool ans=0;
		for(int i=1;i<=n;i++)if(c[i])ans=1;
		cout<<ans;
		return 0;
	}
	if(n<=20){
		for(int i=1;i<=n;i++){
			c[i]=check(i,0);
		}
		dfs(1,0," ");
		cout<<ans;
		return 0;
	}
}
