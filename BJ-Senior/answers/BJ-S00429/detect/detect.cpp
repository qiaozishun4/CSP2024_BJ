#include<iostream>
#include<cmath>
using namespace std;

int p[1000001];
bool open[1000001];

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    struct car
    {
        int d;
        int v;
        int a;
    }cars[100001],r[100001],l[100001],z[100001];

    int T,n,m,L,V,cnt = 0,ans = 0;

    double check;

    cin>>T;
    cin>>n>>m>>L>>V;

    for(int i = 0;i < n;i++)
    {
        cin>>cars[i].d>>cars[i].v>>cars[i].a;
    }

    for(int i = 0;i < m;i++)
    {
        cin>>p[i];
    }

    for(int i = 0;i < n;i++)
    {
        if(cars[i].a < 0)
        {
            l[i] = cars[i];
        }
        if(cars[i].a > 0)
        {
            r[i] = cars[i];
        }
        if(cars[i].a == 0)
        {
            z[i] = cars[i];
        }
    }

    for(int i = 0;i < n;i++)
    {
        if(z[i].v > V)
        {
            ans+= 1;
        }
    }

    for(int i = 0;i < n;i++)
    {
        check = ((abs(l[i].a - 1) * abs(l[i].a - 1)) - (l[i].v * l[i].v)) / (2 * l[i].a);
        if(l[i].v > V)
        {
            for(int j = 1;j < m;j++)
            {
                if(l[i].d == p[j]&&l[i].v > V)
                {
                    ans+= 1;
                    break;
                }
                l[i].d = l[i].d + check;
                l[i].v = l[i].v + abs(l[i].a - 1);
                check = ((abs(l[i].a - 1) * abs(l[i].a - 1)) - (l[i].v * l[i].v)) / (2 * l[i].a);
            }
        }
    }

    for(int i = 0;i < n;i++)
    {
        check = ((abs(r[i].a - 1) * abs(r[i].a - 1)) - (r[i].v * r[i].v)) / (2 * r[i].a);
        if(r[i].v > V)
        {
            for(int j = 1;j < m;j++)
            {
                if(r[i].d == p[j]&&r[i].v > V)
                {
                    ans+= 1;
                    break;
                }
                r[i].d = r[i].d + check;
                r[i].v = r[i].v + abs(r[i].a - 1);
                check = (((r[i].a - 1) * (r[i].a - 1)) - (r[i].v * r[i].v)) / (2 * r[i].a);
            }
        }
    }

    for(int i = 0;i < n;i++)
    {
        for(int j = i;j < m;j++)
        {
            if(r[i].d > p[j]);
            {
                p[j] = false;
            }
            if(r[i].d < p[j])
            {
                p[j] = true;
            }
        }
        for(int j = i;j < m;j++)
        {
            if(l[i].d < p[j]);
            {
                p[j] = false;
            }
            if(l[i].d > p[j])
            {
                p[j] = true;
            }
        }

    }

    for(int i = 0;i < m;i++)
    {
        if(p[i] == false)
        {
            cnt++;
        }
    }

    cout<<ans + 1<<cnt;

    return 0;
}
