#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=1e6+5;
int d[N],v[N],a[N],p[N],las[M],nex[M],ans[N];
struct Node
{
	int l,r;
}b[N];
bool cmp(Node x,Node y)
{
	return x.r<y.r;
}
int main()
{
	ios::sync_with_stdio(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	
	int T;
	cin>>T;
	while(T--)
	{
		memset(las,0,sizeof(las));
		memset(nex,0,sizeof(nex));
		memset(ans,0,sizeof(ans));
		int n,m,L,V;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
		}
		int mx=0;
		nex[0]=1;
		for(int i=1;i<=m;i++)cin>>p[i];
		sort(p+1,p+m+1);
		for(int i=1;i<=m;i++)
		{
			if(i+1<=m)nex[p[i]]+=i+1;
			nex[p[i]]-=i;
			las[p[i]+1]+=i;
			if(i-1>=1)las[p[i]+1]-=i-1;
			mx=max(mx,p[i]);
		}
		for(int i=1;i<=L;i++)
		{
			las[i]+=las[i-1],nex[i]+=nex[i-1];
		}
		//for(int i=1;i<=mx;i++)cout<<las[i]<<" "<<nex[i]<<endl;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			int l,r;
			if(a[i]==0)
			{
				if(v[i]>V)l=(d[i]==0?1:nex[d[i]-1]),r=m;
				else continue;
			}
			else
			{
				double fen=double(V*V-v[i]*v[i])/double(2*a[i]);
				if(fen==0)
				{
					if(a[i]<0)continue;
					l=nex[d[i]],r=m;
				}
				else
				{
					if(fen<0&&a[i]<0)continue;
					if(fen<0&&v[i]>V)fen=-1;
					if(a[i]<0)
					{
						l=(d[i]==0?1:nex[d[i]-1]),r=las[d[i]+int(ceil(fen))];
						//cout<<l<<"* "<<d[i]+int(ceil(fen))<<endl;
					}
					else
					{
						l=(d[i]+int(fen)==-1?1:nex[d[i]+int(fen)]),r=m;
					}
				}
				
			}
			if(l>r||l==0||r==0)continue;
			cnt++;
			b[cnt].l=l;
			b[cnt].r=r;
		}
		sort(b+1,b+cnt+1,cmp);
		cout<<cnt<<" ";
		int ancnt=0;
		for(int i=1;i<=cnt;i++)
		{
			if(ancnt&&b[i].l<=ans[ancnt]&&ans[ancnt]<=b[i].r)continue;
			ans[++ancnt]=b[i].r;
		}
		cout<<m-ancnt<<endl;
	}
	return 0;
}