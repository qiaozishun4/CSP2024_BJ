#include<iostream>
#include<algorithm>
using namespace std;
int a[100001];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int k=(n+1)/2;
    int l=lower_bound(a+1,a+n+1,a[k])-a;
    int r=upper_bound(a+1,a+n+1,a[k])-a-1;
    int x=l-1,y=n-r,g=r-l+1,ans=0;
    cout<<a[k]<<" "<<x<<" "<<y<<" "<<g<<endl;
    if(y>x)
    {
        if(y-x>=g)
        {
            cout<<1<<endl;
            ans=y;
        }
        else
        {
            cout<<2<<endl;
            ans=y+g-(y-x);
        }
    }
    else
    {
        if(x-y>=g)
        {
            cout<<3<<endl;
            ans=y+(x-y)-g;
        }
        else
        {
            cout<<4<<endl;
            ans=y+g;
        }
    }
    cout<<ans;
    return 0;
}
