#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#define reg register
#define fin freopen("detect.in","r",stdin);
#define fout freopen("detect.out","w",stdout);
using namespace std;
int tests,n,m,rgs,len,speed,ans1,ans2;
int st[100005],v[100005],av[100005];
int p[100005];
bool ifex[100005];
int l[100005],r[100005];
pair<int,int> a[100005];
int main()
{
    fin
    fout
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> tests;
    while(tests--)
    {
        ans1=ans2=rgs=0;
        cin >> m >> n >> len >> speed;
        for(reg int i=1;i<=m;i++)
            cin >> st[i] >> v[i] >> av[i];
        for(reg int i=1;i<=n;i++)
            cin >> p[i];
        p[0]=p[n+1]=0;
        for(reg int i=1;i<=m;i++)
        {
            if(st[i]>p[n])
            {
                ifex[i]=0;
                continue;
            }
            int start=lower_bound(p+1,p+n+1,st[i])-p;
            if(av[i]==0)
            {
                if(v[i]>speed)
                {
                    ifex[i]=1;
                    l[i]=start;
                    r[i]=n;
                }
                else
                    ifex[i]=0;
            }
            else if(av[i]>0)
            {
                if(v[i]>speed)
                {
                    ifex[i]=1;
                    l[i]=start;
                    r[i]=n;
                }
                else
                {
                    int rc=st[i]+(speed*speed-v[i]*v[i])/(2*av[i]);
                    if(rc<p[n])
                    {
                        ifex[i]=1;
                        l[i]=upper_bound(p+1,p+n+1,rc)-p;
                        r[i]=n;
                    }
                    else
                        ifex[i]=0;
                }
            }
            else
            {
                if(v[i]<=speed)
                    ifex[i]=0;
                else
                {
                    int rc=st[i]+(v[i]*v[i]-speed*speed-2*av[i]-1)/(-2*av[i]);
                    if(p[start]>=rc)
                        ifex[i]=0;
                    else
                    {
                        ifex[i]=1;
                        l[i]=start;
                        r[i]=(rc>p[n]?n:lower_bound(p+1,p+n+1,rc)-p-1);
                    }
                }
            }
        }
        /*
        for(int i=1;i<=n;i++)
            if(ifex[i])
                cout << l[i] << ' ' << r[i] << endl;
            else
                cout << "speed not exceeded\n";
        //*/
        for(reg int i=1;i<=m;i++)
            if(ifex[i])
            {
                ans1++;
                a[++rgs]=make_pair(l[i],r[i]);
            }
        sort(a+1,a+rgs+1,[](pair<int,int> x,pair<int,int> y)->bool{return (x.second!=y.second?x.second<y.second:x.first<y.first);});
        int lastopen=0;
        for(reg int i=1;i<=rgs;i++)
        {
            if(lastopen<a[i].first)
            {
                lastopen=a[i].second;
                ans2++;
            }
        }
        cout << ans1 << ' ' << (n-ans2) << endl;
    }
    return 0;
}
