#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+7;
struct car{
	int d,v,a;
}c[maxn];
int p[maxn],vis[maxn][maxn],flag[maxn],sum[maxn];
int n,m,L; double V;
bool check(int x,int end){
	double v1=sqrt((double)pow(c[x].v,2)+(2.0*c[x].a*(p[end]-c[x].d)));
	return v1>V;
}
int find(int x){
	int i=1,j=m,ans=0;
	while(c[x].d>p[i+1]&&i<=m) i++;
	i++;
	if(c[x].a>0){
		while(i<=j){
			int mid=(i+j)/2;
			if(check(x,mid)) ans=mid,j=mid-1;
			else i=mid+1;
		}
		for(int i=ans;i<=m;i++)
			vis[x][i]=1;
		return ans;
	}else if(c[x].a<0){
		int l=i;
		while(i<=j){
			int mid=(i+j)/2;
			if(check(x,mid)) ans=mid,i=mid+1;
			else j=mid-1;
		}
		for(int i=l;i<=ans;i++)
			vis[x][i]=1;
		return ans;
	}
	else{
		if(c[x].v<=V) return 0; 
		flag[x]=1;
		for(int j=i;j<=n;j++)
			vis[x][j]=1;
		return i;
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t; cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		memset(flag,0,sizeof(flag));
		memset(sum,0,sizeof(sum));
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)
			cin>>c[i].d>>c[i].v>>c[i].a;
		for(int i=1;i<=m;i++)
			cin>>p[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			int k=find(i);
			if(k) ans++;
		}
		cout<<ans<<' ';
		for(int j=1;j<=m;j++)
			for(int i=1;i<=n;i++)
				sum[j]+=vis[i][j];
		int num=0;
		while(1){
			bool ch=1;
			for(int i=1;i<=n;i++)
				if(!flag[i]) {ch=0; break;}
			if(ch) break;
			num++;
			int k=0;
			for(int j=1;j<=m;j++)
				if(sum[j]>sum[k]) k=j;
			if(k==0) break;
			for(int i=1;i<=n;i++)
				if(vis[i][k])
					flag[i]=1;
			memset(sum,0,sizeof(sum));
			for(int j=1;j<=m;j++)
				for(int i=1;i<=n;i++)
					if(!flag[i])
						sum[j]+=vis[i][j];
		}
		cout<<n-num<<endl;
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
