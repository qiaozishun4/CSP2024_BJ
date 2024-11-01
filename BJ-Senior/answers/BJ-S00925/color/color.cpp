#include <bits/stdc++.h>
#define int long long
#define maxn 1000010
using namespace std;

int a[maxn],c[3],n;
int dfs(int w,int color)
{

	// for(int i=1;i<w;i++) cout<<" ";
	// cout<<w<<" "<<color<<endl;

	if(w>n){return 0;}
	int cs=(a[c[color]]==a[w]?a[w]:0);
	int bb=c[color];
	c[color]=w;
	int d1=0,d2=0;
	d1=dfs(w+1,1);
	d2=dfs(w+1,2);

	// for(int i=1;i<w;i++) cout<<" ";
	// cout<<d1<<" "<<d2<<" "<<cs<<" "<<" "<<bb<<endl;

	
	c[color]=bb;
	// if(w==1) cs=0;


	return max(d1,d2)+cs;
}

signed main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);

	int T;
	cin>>T;
	while(T--)
	{
		memset(c,0,sizeof(c));
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		cout<<max(dfs(1,1),dfs(1,2))<<endl;
	}
	return 0;
}