#include<bits/stdc++.h>
using namespace std;
int f[105][200005],t,s[105][200005];
struct node{
	int x,y;
};
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		int n,k,q,l,x,cnt=0,a[200005];
		cin>>n>>k>>q;
		node b[200005];
		map<node,int> m;
		for(int i=1;i<=n;i++){
			cin>>l;
			for(int j=1;j<=l;j++){
				cin>>x;
				cnt++;
				a[cnt]=x;
				if(a[cnt]==1)f[0][cnt]=1;
			}
		}
		for(int i=1;i<=100;i++){
			int h[200005],m[200005];
			memset(h,0,sizeof(h));
			for(int j=1;j<=cnt;j++){
				if(f[i-1][j]==1){
					h[a[j]]++;
					m[a[j]]=j;
				}
			}
			for(int j=1;j<=cnt;j++){
				if(h[a[j]]>1||(h[a[j]]==1&&m[a[j]]!=j))f[i-1][j]=1;
				else f[i-1][j]=0;
			}
			for(int j=1;j<=cnt;j++){
				node v=b[j];
				int x=v.x,y=v.y;
				s[x][y]=s[x][y-1]+f[x-1][j];
				int u=s[x][y-1];
				if(y>k)u-=s[x][y-k-1];
				if(u>0)f[i][j]=1;
				else f[i][j]=0;
			}
		}
		while(q--){
			int r,c;
			cin>>r>>c;
			bool flag=false;
			for(int i=1;i<=cnt;i++){
				if(a[cnt]==c&&f[r][i]==1){
					flag=true;
					break;
				}
			}
			if(flag)puts("1");
			else puts("0");
		}
	}
	return 0;
}
