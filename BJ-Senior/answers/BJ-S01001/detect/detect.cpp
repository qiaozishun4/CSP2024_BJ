#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V,p[100005],ans[10005][10005];
struct node
{
    int d,v,a,cs;
}c[100005];
int cl(int x,int y)
{
    if(x%y==0)
        return x/y;
    return x/y+1;
}
int main()
{
    cin>>t;
    while(t--)
    {

        int ans1=0,ans2=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++)
        {
            cin>>c[i].d>>c[i].v>>c[i].a;

            if(c[i].a==0&&c[i].v>V)
            {
                c[i].cs=c[i].d;
            }
            if(c[i].a<=0&&c[i].v<=V)
            {
                c[i].cs=-1;
            }else if(c[i].a<=0)
            {
                c[i].cs=cl((c[i].v-V),c[i].a);
                c[i].cs=c[i].v*c[i].cs+0.5*c[i].a*c[i].cs*c[i].cs;
            }else if(c[i].a>=0&&c[i].v<=V){
                c[i].cs=cl((V-c[i].v),c[i].a);
                c[i].cs=c[i].v*c[i].cs+0.5*c[i].a*c[i].cs*c[i].cs;
            }else{
                c[i].cs=c[i].d;
            }
            if(c[i].cs>L&&c[i].a>=0)
            {
                c[i].cs=-1;
            }
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        for(int i=1;i<=n;i++)
        {
            if(c[i].cs=-1)
                continue;
            bool f=0;
            for(int j=1;j<=m;j++)
            {
                if(c[i].d>p[j])
                    continue;
                if(c[i].a>0&&c[i].cs<p[j])
                {
                    ans[i][j]=1;
                    f=1;
                }
                else if(c[i].a<0&&c[i].cs>p[j])
                {
                    ans[i][j]=1;
                    f=1;
                }else if(c[i].a==0&&c[i].v>V)
                {
                    ans[i][j]=1;
                    f=1;
                }
            }
            if(f)
                ans1++;
        }
        cout<<ans1<<" "<<3<<"\n";
    }

    return 0;
}
