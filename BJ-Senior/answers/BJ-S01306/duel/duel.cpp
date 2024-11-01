#include<bits/stdc++.h>
using namespace std;
int n,ans,sum,x=1,y=2,f;
struct abc
{
    int a,b;
}a[100005];
bool cmp(abc x,abc y)
{
    return x.a<y.a;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].a;
        a[i].b=0;
    }
    sort(a+1,a+n+1,cmp);
    f=true;
    while(f)
    {
        if(sum==n)
        {
            break;
        }
        while(a[x].a==a[y].a&&x<n&&y<n&&x!=y)
        {
            x++;
            y++;
        }
        if(x==y)
        {
            y++;
        }
        if(a[y].a>a[x].a&&a[y].b==0)
        {
            ans++;
            sum++;
            a[y].b=1;
            for(int j=x;j>=1;j--)
            {
                a[j].a=a[j-1].a;
                a[j].b=a[j-1].b;
            }
        }
        else
        {
            a[y].b=1;
            sum++;
        }

        if(x>n||y>n)
        {
            x--;
            y--;
        }
        else
        {
            x++;
            y++;
        }
    }
    cout<<n-ans-1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
