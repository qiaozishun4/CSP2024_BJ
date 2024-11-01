#include<bits/stdc++.h>
using namespace std;
int g[100010];
struct T
{
    int last,next,zg,lg;
}a[100010];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>g[i];
    }
    sort(g+1,g+n+1);
    int k=1;
    a[1].last=-1;
    a[1].next=-2;
    for(int i=1;i<=n;i++)
    {
        if(g[i]!=g[i-1])
        {
            k++;
            a[k-1].next=k;
            a[k].last=k-1;
            a[k].next=-2;
            a[k].zg=a[k].lg=1;
        }else
        {
            a[k].zg++;
            a[k].lg++;
        }
    }
    int sh=n;
    for(int i=2;i<=k;i++)
    {
        int j=i-1;
        while(a[i].last>0)
        {
            if(a[i].lg<a[j].zg)
            {
                sh-=a[i].zg;
                a[i].zg-=a[i].lg;
                break;
            }else
            {
                a[i].lg-=a[j].zg;
                sh-=a[j].zg;
                a[i].last=a[j].last;
                j=a[i].last;
            }
        }
    }
    cout<<sh;
    return 0;
}