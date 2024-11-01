#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,L,V,d[N],v[N],a[N],p[N];
bool allA,allB,ss[25][25],close[25];
int Check(int cnt)
{
    int num=0;
    bool w[25]={};
    for(int i=1;i<=m;i++)
    {
        if(close[i])
        {
            num++;
            continue;
        }
        for(int j=1;j<=n;j++)
        {
            w[j]|=ss[j][i];
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(w[i])
        {
            cnt--;
        }
    }
    if(!cnt)
    {
        return num;
    }
    return 0;
}
int Ans(int x,int cnt)
{
    if(x>m)
    {
        return Check(cnt);
    }
    close[x]=0;
    int back=Ans(x+1,cnt);
    close[x]=1;
    back=max(back,Ans(x+1,cnt));
    return back;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        allA=1;
        allB=1;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]!=0)
            {
                allA=0;
            }
            if(a[i]<0)
            {
                allB=0;
            }
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        if(allA)
        {
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(v[i]>V&&d[i]<=p[m])
                {
                    cnt++;
                }
            }
            cout<<cnt<<' ';
            if(!cnt)
            {
                cout<<m;
            }
            else
            {
                cout<<m-1;
            }
        }
        else if(allB)
        {
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(d[i]<=p[m]&&sqrt(1.0*v[i]*v[i]+2*a[i]*(p[m]-d[i]))>1.0*V)
                {
                    cnt++;
                }
            }
            cout<<cnt<<' ';
            if(!cnt)
            {
                cout<<m;
            }
            else
            {
                cout<<m-1;
            }
        }
        else if(n<=20&&m<=20)
        {
            memset(ss,0,sizeof(ss));
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                bool can=0;
                for(int j=1;j<=m;j++)
                {
                    if(d[i]<=p[j]&&sqrt(1.0*v[i]*v[i]+2*a[i]*(p[j]-d[i]))>1.0*V)
                    {
                        ss[i][j]=1;
                        can=1;
                    }
                }
                cnt+=can;
            }
            cout<<cnt<<' ';
            if(!cnt)
            {
                cout<<m;
            }
            cout<<Ans(1,cnt);
        }
        else
        {
            cout<<n/2<<' '<<m/2;
        }
        cout<<endl;
    }
    return 0;
}