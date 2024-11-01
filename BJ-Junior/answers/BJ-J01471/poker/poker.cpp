#include<bits/stdc++.h>
using namespace std;

struct poker
{
    char a,b;
};
bool cmp(poker a,poker b)
{
    if(a.a>b.a)
    {
        return 1;
    }
    else if(a.a<b.a)
    {
        return 0;
    }
    if(a.b>=b.b)
    {
        return 1;
    }
    return 0;
}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    poker a[100];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].a>>a[i].b;
    }
    sort(a+1,a+1+n,cmp);
    //for(int i=1;i<=n;i++)
    //{
    //    cout<<a[i].a<<a[i].b<<" ";
    //}
    int ans=n;
    for(int i=1;i<=n;i++)
    {
        if(a[i].a==a[i-1].a&&a[i].b==a[i-1].b)
        {
            ans--;
        }
    }
    cout<<52-ans;
    return 0;
}
