#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const double eps=1e-8;
struct node
{
    int speed,a,d;
}t[N];
int pos[N];
double check(double a,double b,double c)
{
    double k=sqrt(a*a+2*b*c);
    return k;
}

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int o;
    cin>>o;
    while(o--)
    {
        int n,m,l,v;
        cin>>n>>m>>l>>v;
        bool p0=0,p1=0,p2=0;
        for(int i=1;i<=n;i++)
        {
            cin>>t[i].d>>t[i].speed>>t[i].a;
            if(t[i].a>0) p0=p1=1;
            else
            {
                if(t[i].a==0) p1=p2=1;
                else p0=p2=1;
            }
        }
        for(int i=1;i<=m;i++)
        {
            cin>>pos[i];
        }
        sort(pos+1,pos+m+1);
        if(!p0)
        {
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(t[i].d>pos[m]||t[i].speed<=v)
                {
                    continue;
                }
                cnt++;
            }
            cout<<cnt<<" ";
            if(cnt==0) cout<<m<<endl;
            else cout<<m-1<<endl;
        }
        if(!p1)
        {
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(t[i].d>pos[m]||check(t[i].speed,t[i].a,t[i].d-pos[1])+eps<=v||abs(v-check(t[i].speed,t[i].a,t[i].d-pos[1]))<=eps)
                {
                    continue;
                }
                cnt++;
            }
            cout<<cnt<<" ";
            if(cnt==0) cout<<m<<endl;
            else cout<<m-1<<endl;
        }
        if(!p2)
        {
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(t[i].d>pos[m]||check(t[i].speed,t[i].a,pos[m]-t[i].d)+eps<=v||abs(v-check(t[i].speed,t[i].a,pos[m]-t[i].d))<=eps)
                {
                    continue;
                }
                cnt++;
            }
            cout<<cnt<<" ";
            if(cnt==0) cout<<m<<endl;
            else cout<<m-1<<endl;
        }
    }
    return 0;
}
