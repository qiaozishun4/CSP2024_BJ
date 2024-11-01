#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int QAQ=1e9+56;
int t,n,m,L,V,d[N],v[N],a[N],p[N],s2=QAQ;
bool vis[N],vis1[N];
double sssd(int v11,int a11,int v111)
{
	double v=v11,a=a11,v1=v111;
	return double(double((v1*v1-v*v))/double(2*a));
}
void dfs(int x,bool vv[N],int S)
{
	if(S>=s2) return;
	if(x==m+1) 
	{
		//cout<<vv[m]<<endl;
		bool F=0;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]) continue;
			if(a[i]==0) 
			{
				bool f=0;
				for(int j=1;j<=m;j++) if(d[i]<=p[j]&&vv[j]==1) {
					f=1;
					break;}
					if(f==0) {
					F=1;break;
					}
			}	
			if(a[i]>0)
			{
				bool f=0;
				double ll=d[i]+sssd(v[i],a[i],V);
				for(int j=1;j<=m;j++)
				{
					if(ll<double(p[j])&&vv[j]==1) 
					{
						f=1;break;}
				}
				if(f==0) {F=1;break;}
			}
			if(a[i]<0)
			{
				bool f=0;
				double ll=d[i]+sssd(v[i],a[i],V);
				for(int j=1;j<=m;j++)
						{
							//if(i==4&&j==m) cout<<ll<<" "<<p[j]<<" "<<d[i]<<" "<<vv[j]<<endl;
							if(p[j]>=d[i]&&double(p[j])<=ll&&vv[j]==1) 
							{
								f=1;
								break;
							}
						}
						if(f==0) 
						{
							F=1;break;
						}
			}
		}
		if(F==1) return;
		s2=min(s2,S);
		return;
	}
	//cout<<x<<endl;
	dfs(x+1,vv,S);
	vv[x]=1;
	dfs(x+1,vv,S+1);
	vv[x]=0;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++) cin>>p[i];
		int s1=0;
		s2=QAQ;
		for(int i=1;i<=n;i++)
		{
			//cout<<v[i]<<" "<<a[i]<<" "<<V<<endl;
			if(a[i]!=0)
			{
				double ll=double(d[i])+sssd(v[i],a[i],V);
				if(a[i]>0)
				{
					if(ll>double(L)) continue;
					else if(double(p[m])>ll) vis[i]=1,s1++;
				}
				else
				{
					if(v[i]<=V) continue;
					else
					{
						for(int j=1;j<=m;j++)
						{
							if(p[j]>=d[i]&&double(p[j])<=ll) 
							{
								vis[i]=1;
								s1++;
								break;
							}
						}
					}
				}
			}
			else
			{
				if(v[i]<=V) continue;
				else 
				{
					if(p[m]>=d[i]) vis[i]=1,s1++;
				}
			}
		}
		cout<<s1<<" ";
		int qwq=0;
		for(int i=1;i<=n;i++) if(a[i]==0) qwq++;
		int QWQ=0;
		for(int i=1;i<=n;i++) if(a[i]>0) QWQ++;
		if(qwq==n) 
		{
			if(s1==0) cout<<m<<endl;
			else cout<<m-1<<endl;
		}
		else if(QWQ==n)
		{
			if(s1==0) cout<<m<<endl;
			else cout<<m-1<<endl;
		}	
		else {dfs(1,vis1,0);
		cout<<m-s2<<endl;}
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=m;i++) vis1[i]=0;
	}
}
