#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
    int di,vi,ai,x,y,id;
    bool f;
}a[1000000];
int p[100000];
int tt[1000][1000],c[1000];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,l,v;
        cin>>n>>m>>l>>v;
        int cnt = 0;
        for(int i = 1;i<=n;i++)
        {
            c[i] = 0;
            cin>>a[i].di>>a[i].vi>>a[i].ai;
            a[i].id = i;
            if(a[i].ai == 0)
            {
                if(a[i].vi>v)
                {
                    a[i].x = a[i].di;
                    a[i].y = l;
                    a[i].f = 1;
                }
                else a[i].f = 0;
            }
            else if(a[i].ai>0)
            {
                if(a[i].vi>v)
                {
                    a[i].x = a[i].di;
                    a[i].y = l;
                    a[i].f = 1;
                }
                else
                {
                    int s = ((v*v)-(a[i].vi*a[i].vi))/(2*a[i].ai);
                    s+=1;
                    if(s<=l)
                    {
                        a[i].x = a[i].di+s;
                        a[i].y = l;
                        a[i].f = 1;
                    }
                    else a[i].f = 0;
                }
            }
            else if(a[i].ai<0)
            {
                if(a[i].vi<v)a[i].f = 0;
                else
                {
                    int s = (v*v)-(a[i].vi*a[i].vi);
                    if(s%(2*a[i].ai) == 0)
                    {
                        s/=(2*a[i].ai);
                        s-=1;
                    }
                    else s/=(2*a[i].ai);
                    a[i].x = a[i].di;
                    a[i].y = a[i].di+s;
                    a[i].f = 1;
                }
            }
        }
        for(int i = 1;i<=m;i++)
        {
            cin>>p[i];
            tt[i][0] = 0;
        }
        sort(p+1,p+m+1);
        for(int i = 1;i<=n;i++)
        {
            if(a[i].f == 0)continue;
            bool flag = 0;
            for(int j = 1;j<=m;j++)
            {
                if(p[j]>=a[i].x&&p[j]<=a[i].y)
                {
                    flag = 1;
                    tt[p[j]][0]++;
                    tt[p[j]][tt[p[j]][0]] = a[i].id;
                    c[i]++;
                }
            }
            if(flag == 1)cnt++;
        }
        cout<<cnt<<endl;
        int ans = 0;
        for(int i = 1;i<=m;i++)
        {
            bool flag = 0;
            for(int j = 1;j<=tt[p[i]][0];j++)
            {
                if(c[tt[p[i]][j]] == 1)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                ans++;
                for(int j = 1;j<=tt[p[i]][0];j++)c[tt[p[i]][j]]--;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
