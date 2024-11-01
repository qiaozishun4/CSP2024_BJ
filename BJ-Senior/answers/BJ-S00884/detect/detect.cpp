#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
inline bool cmp(pair<int,int> a,pair<int,int> b)
{
	return a.second<b.second;
}
int T,n,m,L,V,d[100010],v[100010],a[100010],p[100010];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
		}
		int ans1=0,ans2=0,maxp=0;
		vector<pair<int,int> > A;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=0)
			{
				if(p[m]<d[i])
				{
					continue;
				}
				int l=1,r=m,ans=0;
				while(l<=r)
				{
					int mid=l+r>>1;
					(p[mid]>=d[i]&&v[i]*v[i]
					+2*a[i]*(p[mid]-d[i])>V*V)
					?(r=(ans=mid)-1):(l=mid+1);
				}
				if(ans)
				{
					ans1++;
					maxp=max(maxp,ans);
				}
			}
			else
			{
				int P=lower_bound(p+1,p+m+1,d[i])-p;
				int l=P,r=m,ans=0;
				while(l<=r)
				{
					int mid=l+r>>1;
					(v[i]*v[i]+2*a[i]*(p[mid]-d[i])>V*V)
					?(l=(ans=mid)+1):(r=mid-1);
				}
				if(ans)
				{
					ans1++;
					A.push_back({P,ans});
				}
			}
		}
		if(maxp)
		{
			A.push_back({maxp,m});
		}
		sort(A.begin(),A.end(),cmp);
		for(int i=0,maxr=0;i<A.size();i++)
		{
			if(A[i].first>maxr)
			{
				ans2++;
				maxr=A[i].second;
			}
		}
		cout<<ans1<<" "<<m-ans2<<'\n';
	}
	return 0;
}