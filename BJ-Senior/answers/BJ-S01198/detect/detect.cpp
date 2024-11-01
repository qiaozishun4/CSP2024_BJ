#include<bits/stdc++.h>
using namespace std;
double getv(int a,int v,int l)
{
    return sqrt(l*a*2.00+v*v*1.00);
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int n,m,l,vv,d[100005],v[100005],a[100005],p[100005];
    int t;
    cin>>t;
    while(t--)
    {
        bool flag1 = true,flag2 = true,flag3 = true;
        int cnt1 = 0,cnt2 = 0,maxx = 0;
        cin>>n>>m>>l>>vv;
        if(n > 20 || m > 20) flag3 = false;
        for(int i = 1;i <= n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
            if(a[i] < 0) flag1 = false;
        }
        for(int i = 1;i <= m;i++)
        {
            cin>>p[i];
            maxx = max(maxx,p[i]);
        }
        if(flag1)
        {
            for(int i = 1;i <= n;i++)
            {
                if(d[i] > maxx) continue;
                if(a[i] == 0 && v[i] > vv)
                {
                    cnt1++;
                    continue;
                }
                if(getv(a[i],v[i],maxx-d[i]) > vv)
                {
                    cnt1++;
                }
            }
            if(cnt1 == 0)m++;
            cout<<cnt1<<" "<<m-1<<endl;
        }
    }
}
/*#include<bits/stdc++.h>
using namespace std;
double getv(int a,int v,int l)
{
    return sqrt(l*a*2.00+v*v*1.00);
}
int n,m,l,vv,d[100005],v[100005],a[100005],p[100005],mc[100005];
int t;
int upper(int x)
{
    int l= 1,r = n;
    while(l < r)
    {
        int mid = (l+r)>>1;
        if(mc[mid] > x) r = mid-1;
        if(mc[mid] < x) l = mid+1;
        if(mc[mid] == x) return mc[mid];
    }
    if(mc[l] < x) return mc[l+1];
    if(l > n) return -1;
    return mc[l];
}
int main()
{
    freopen("detect1.in","r",stdin);
    freopen("detect1.out","w",stdout);
    cin>>t;
    while(t--)
    {
        bool flag1 = true,flag2 = true,flag3 = true;
        int cnt1 = 0,cnt2 = 0,maxx = 0;
        int yyy[100005];
        cin>>n>>m>>l>>vv;
        if(n > 20 || m > 20) flag3 = false;
        for(int i = 1;i <= n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
            if(a[i] < 0) flag1 = false;
        }
        for(int i = 1;i <= m;i++)
        {
            cin>>p[i];
            yyy[p[i]] = i;
            mc[i] = p[i];
            maxx = max(maxx,p[i]);
        }
        sort(mc+1,mc+1+m);
        if(flag1)
        {
            for(int i = 1;i <= n;i++)
            {
                if(d[i] > maxx) continue;
                if(a[i] == 0 && v[i] > vv)
                {
                    cnt1++;
                    continue;
                }
                if(getv(a[i],v[i],maxx-d[i]) > vv)
                {
                    cnt1++;
                }
            }
            if(cnt1 == 0)m++;
            cout<<cnt1<<" "<<m-1<<endl;
        }
        else
        {
            int vis[100005] = {};
            for(int i = 1;i <= n;i++)
            {
                if(a[i] >= 0)
                {
                    if(d[i] <=  upper(d[i]) && getv(a[i],v[i], upper(d[i])-d[i]) > vv)
                    {
                        cnt1++;
                        for(int j = yyy[upper(d[i])];j <= m;j++)
                        {
                            if(!vis[d[j])
                            {
                                cnt2++;
                            }
                        }
                        vis[maxx] = 1;
                    }
                }
                else
                {
                    if( upper(d[i]) != -1 && getv(a[i],v[i],upper(d[i])-d[i]) > vv)
                    {
                        cnt1++;
                        for(int j = yyy[upper(d[i])];j <= m;j++)
                        {
                            if(!vis[d[j])
                            {
                                cnt2++;
                            }
                        }
                        vis[upper(d[i])] = 1;
                    }
                }
            }
            cout<<cnt1<<" "<<cnt2<<endl;
        }
    }
}*/
