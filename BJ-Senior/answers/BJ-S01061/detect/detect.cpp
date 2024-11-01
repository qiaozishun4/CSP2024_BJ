#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,inf=0x3f3f3f3f;
int d[N],v[N],a[N],p[N],n,m,l,V;
vector<pair<int,int>>  x;
bool cmp(pair<int,int> &a,pair<int,int> &b)
{
    if(a.second!=b.second)
    {
        return a.second<b.second;
    }
    return a.first>b.first;
}
signed main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        x.clear();
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]>0)
            {
                if(d[i]>p[m]) continue;
                int to=(V*V-v[i]*v[i])/a[i]/2.0+d[i];
                if(to+1>p[m]) continue;
                auto it=upper_bound(p+1,p+m+1,to)-p;
                x.push_back({it,m});
            }
            else if(a[i]<0)
            {
                if(v[i]<=V||d[i]>p[m]) continue;
                int to=(V*V-v[i]*v[i]);
                if(to%(2*a[i])==0) to=to/2/a[i];
                else to=to/2/a[i]+1;
                to+=d[i];
                auto it1=lower_bound(p+1,p+m+1,to)-p-1,it2=lower_bound(p+1,p+m+1,d[i])-p;
                if(p[it2]>=to||p[it1]<d[i]) continue;
                x.push_back({it2,it1});
            }
            else
            {
                if(d[i]>p[m]||v[i]<=V) continue;
                auto it=lower_bound(p+1,p+m+1,d[i])-p;
                x.push_back({it,m});
            }
        }
		if(!x.size())
		{
			cout<<0<<" "<<m<<'\n';
			continue;
		}
        sort(x.begin(),x.end(),cmp);
        int cnt=1,now=x[0].second;
        for(int i=1;i<x.size();i++)
        {
            if(now<x[i].first)
            {
                cnt++;
                now=x[i].second;
            }
        }
        cout<<x.size()<<" "<<m-cnt<<'\n';
    }
    return 0;
}