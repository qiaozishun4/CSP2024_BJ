#include<bits/stdc++.h>
using namespace std;
double d[100010],v[100010],a[100010],s[100010];
int p[100010],f1[100010],f2[100010];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    for(int k=1;k<=T;k++)
    {
        memset(p,0,sizeof(p));
        memset(f1,0,sizeof(f1));
        memset(f2,0,sizeof(f2));
        memset(s,0,sizeof(s));
        int n,m,L,V;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]==0)
                s[i]=0;
            else
                s[i]=d[i]+abs(1.0*V*V-v[i]*v[i])/abs(1.0*2*a[i]);
            if(s[i]>L)
                s[i]=L+1;
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        sort(p+1,p+n+1);
        int cnt1=0,cnt2=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]<0)
            {
                int q=upper_bound(p+1,p+n+1,s[i])-p;
                if(p[q-1]>=d[i])
                {
                    cnt2++;
                    f2[cnt2]=q-1;
                    d[cnt2]=d[i];
                }
            }
            if(a[i]>0)
            {
                int q=lower_bound(p+1,p+n+1,s[i])-p;
                if(q<=m)
                {
                    cnt1++;
                    f1[cnt1]=q;
                    d[cnt1]=d[i];
                }
            }
            if(a[i]==0)
            {
                if(v[i]>V)
                {
                    int q=lower_bound(p+1,p+n+1,d[i])-p;
                    if(p[q]>=d[i])
                    {
                        cnt1++;
                        f1[cnt1]=q;
                        d[cnt1]=d[i];
                    }
                }
            }
        }
        sort(f1+1,f1+cnt1+1);
        int l=m,sl=L;
        for(int i=1;i<=cnt2;i++)
        {
            if(p[f2[i]]==-1) continue;
            if(f2[i]<sl)
            {
                m--;
                p[f2[i]]=-1;
            }
            else if(d[i]<l)
            {
                l=f2[i];
                sl=d[i];
            }
            else if(d[i]>l)
            {
                p[l]=-1;
                m--;
                l=f2[i];
                sl=d[i];
            }
        }
        cout<<cnt1+cnt2<<" ";
        if(cnt2==0&&cnt1!=0)
            cout<<m-1<<endl;
        else if(f1[cnt1]<=f2[l])
        {
            cout<<m<<endl;
        }
        else if(f1[cnt1]>f2[l])
        {
            cout<<m-1<<endl;
        }
    }
    return 0;
}
