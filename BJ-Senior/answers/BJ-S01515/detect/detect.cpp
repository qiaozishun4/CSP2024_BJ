#include<bits/stdc++.h>
using namespace std;
int n,m,whmax=0;
struct ligh{
int times,la,who[10005];
}p[100005];
bool cmp(ligh x,ligh y)
{
    return x.times>y.times;
}
void delet(int x)
{
    for(int i=1;i<=m;i++)
    for(int j=1;j<=whmax;j++){

        if(p[i].who[j]==x)
            p[i].times--;
        if(p[i].who[j]==0)
            break;
    }
    sort(p+1,p+1+m,cmp);

}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int cnt=0,ans=0,whosecnt=0,l,v,d[100005],vc[100005],a[100005];
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++)
            cin>>d[i]>>vc[i]>>a[i];
        for(int i=1;i<=m;i++)
            cin>>p[i].la;
        for(int i=1;i<=n;i++)
        {
            int f12=0;
            for(int j=1;j<=m;j++)
            {
                if(d[i]<p[j].la)
                {
                    long long now=vc[i]*vc[i]+2*a[i]*(p[j].la-d[i]);
                   if(now<0)
                        break;
                    if(now>v*v)
                    {
                        if(f12==0)
                        {
                            f12=1;
                            ans++;
                        }
                        p[j].times++;
                        whosecnt++;
                        p[j].who[whosecnt]=i;
                    }
                }
                //cout<<cnt<<endl;
            }
        }
        cout<<ans<<" ";
        sort(p+1,p+1+m,cmp);
        while(p[1].times){
            for(int i=1;i<=n;i++)
            {
                if(d[i]<p[1].la)
                {
                    long long now=vc[i]*vc[i]+2*a[i]*(p[1].la-d[i]);
                    if(now<0)
                        break;
                    if(now>v*v)
                    {
                        delet(i);
                        cnt++;
                    }
                }
                //cout<<cnt<<endl;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
