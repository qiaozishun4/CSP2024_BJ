#include <bits/stdc++.h>
using namespace std;

const int N=100005;

int low_bit(int x)
{
	return x&-x;
}

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {	
		int d[N],v[N],a[N],p[N];
		queue<int> pp[N];
		int n,m,L,V;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)
			cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++)
			cin>>p[i];
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			bool flag=0;
			int idx_p;
			if(a[i]==0)
			{
				idx_p=lower_bound(p+1,p+n+1,d[i])-p;
				if(v[i]>V)
				{
					for(int j=idx_p;j<=m;j++)
					{
						pp[j].push(i);
						flag=1;
						//cout<<i<<" "<<idx_p<<endl;
					}
				}
			}
			if(a[i]>0)
			{
				int s=ceil(((V*V*1.0)-(v[i]*v[i]*1.0))/(2.0*a[i]))+d[i];
				//cout<<s<<" ";
				if(s<p[m])
				{
					idx_p=lower_bound(p+1,p+m+1,s)-p;
					for(int j=idx_p;j<=m;j++)
					{
						pp[j].push(i);
						flag=1;
						//cout<<i<<" "<<idx_p<<endl;
					}
				}
			}
			if(a[i]<0)
			{
				if(v[i]>=V)
				{
					int s=ceil(((V*V*1.0)-(v[i]*v[i]*1.0))/(2.0*a[i]))+d[i];
					int x=upper_bound(p+1,p+n+1,s)-p-1;
					cout<<s<<" ";
					idx_p=lower_bound(p+1,p+n+1,d[i])-p;
					for(int j=idx_p;j<=x;j++)
					{
						pp[j].push(i);
						flag=1;
						//cout<<i<<" "<<idx_p<<endl;
					}
				}
			}
			if(flag) ans++;
		}
		//cout<<"========";
		cout<<ans<<" ";
		int sss=ans;
		ans=1000000;
		for(int i=0;i<=m;i++)
		{
			int x=i;
			set<int> st;
			int sum=0;
			while(x>0)
			{
				int l=low_bit(x);
				x=x&(x-1);
				sum++;
				while(!pp[l].empty())
				{
					st.insert(pp[l].front());
					pp[l].push(pp[l].front());
					pp[l].pop();
				}
			}
			if(int(st.size())==sss) ans=min(ans,sum);
		}
		cout<<m-ans;
	}
    return 0;
}
