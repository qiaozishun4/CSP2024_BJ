#include<bits/stdc++.h>
using namespace std;
int d[100002],v[100002],a[100002],p[100002],vis[100002];
int cnt=0,tot=0;
int n,m,L,V;
void solveA()
{
    if(cnt==0)
        cout<<m<<endl;
    else
        cout<<m-1<<endl;
}
void solveB()
{
    for(int i=m;i>=1;i--)
    {
        bool tmp=0;
        for(int j=1;j<=n;j++)
        {
            if(p[i]<d[j])
                continue;
            double v1=sqrt(1.00*v[j]*v[j]+2.00*a[j]*(p[i]-d[j]));
            if(!vis[j]&&v1>double(V))
            {
                cnt++;
                vis[j]=true;
                tmp=1;
            }
        }
        if(tmp==0)
            tot++;
    }
}
void solveC()
{
    for(int i=1;i<=m;i++)
    {
        bool tmp=0;
        for(int j=1;j<=n;j++)
        {
            if(p[i]<d[j])
                continue;
            double v1=sqrt(1.00*v[j]*v[j]+2.00*a[j]*(p[i]-d[j]));
            if(!vis[j]&&v1>double(V))
            {
                cnt++;
                vis[j]=true;
                tmp=1;
            }
        }
        if(tmp==0)
            tot++;
    }
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T)
    {
        T--;
        memset(vis,0,sizeof(vis));
        cnt=0,tot=0;
        cin>>n>>m>>L>>V;
        bool flag=0,fb=0;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]!=0)
                flag=1;
            if(a[i]<0||a[i]==0)
                fb=1;
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        sort(p+1,p+m+1);
        if(fb==0)
            solveB();
        else
            solveC();
        cout<<cnt<<" ";
        if(flag==0)
        {
            solveA();
            continue;
        }
        cout<<tot<<endl;
    }
    return 0;
}