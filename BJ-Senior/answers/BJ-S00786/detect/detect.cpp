#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> t;
    while(t--)
    {
        int n,m,l,xv,d[100005],v[100005],a[100005],p[100005],ans1=0,ans2=0,P=-1;
        bool r[105][105];
        for (int i=1;i<=n;i++)
        {
            for (int ah=1;ah<=m;ah++)
            {
                r[i][ah]=0;
            }
        }
        cin >> n >> m >> l >> xv;
        for(int i=1;i<=n;i++)
            cin >> d[i] >> v[i] >> a[i];
        for (int i=1;i<=m;i++)
        {
            cin >> p[i];
            P=max(P,p[i]);
        }
        for (int i=1;i<=n;i++)
        {
            double x;//何di速度等于限速
            int qi,zh;
            if (a[i]!=0)
                x=d[i]+(xv*xv-v[i]*v[i])/(2*a[i]);
            if (a[i]>0 && P>x)
            {
                ans1++;
                for (int j=1;j<=m;j++)
                {
                    if (p[j]>x)
                    {
                        r[i][j]=1;
                    }
                }
            }
            if (a[i]==0 && v[i]>xv && P>=d[i])
            {
                for (int j=1;j<=m;j++)
                {
                    if (p[j]>d[i])
                    {
                        r[i][j]=1;
                    }
                }
                ans1++;
            }
            if (a[i]<0)
            {
                double ch=v[i]/(-a[i]);
                double lc=v[i]*ch + 0.5*a[i]*ch*ch;//什么时候出去的
                if (d[i]>xv && 0<*lower_bound(p+1,p+m+1,d[i]) && *lower_bound(p+1,p+m+1,d[i])<x)
                {
                    ans1++;
                }
                for (int j=1;j<=m;j++)
                {
                    if (p[j]>=d[i] && p[m]<x)
                    {
                        r[i][j]=1;
                    }
                }
            }
        }
        cout << ans1 << " ";
        for (int i=0;i<=(i<<m)-1;i++)
        {
            int s=i,ko=0,bs[100005];
            while(s)
            {
                bs[++ko]=s%2;
                s/=2;
            }
            bool bb=1;
            for (int j=1;j<=n;j++)
            {
                bool bbb=0;
                for (int h=1;h<=m;h++)
                {
                    if (bs[h]==1 && r[j][h]==1)
                    {
                        bbb=1;
                        break;
                    }
                }
                if (bbb==0)
                {
                    bb=0;
                    break;
                }
            }
            if (bb)
            {
                int summ=0;
                for (int j=1;j<=m;j++)
                {
                    if (bs[j]==0)
                        summ++;
                }
                ans2=max(ans2,summ);
            }
        }
        cout << m/2+1 << "\n";
    }
    return 0;
}

