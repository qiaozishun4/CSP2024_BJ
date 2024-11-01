#include <iostream>
using namespace std;
typedef long long ll;
ll T,n,a[20000],d[10]={-1,-1,1,7,4,2,0,8};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        cin>>n;
        ll id=0;
        if(n==6)
        {
            cout<<6<<endl;
            continue;
        }
        if(n<=7)
        {
            cout<<d[n]<<endl;
            continue;
        }
        while(n>=7)
        {
            a[++id]=8;
            n-=7;
        }
        if(n)
        {
            if(n==1) a[id]=0,a[++id]=1;
            else if(n==2) a[++id]=1;
            else if(n<=5)
            {
                for(ll i=id;i&&n<5;i--) a[i]=0,n++;
                if(n<5) a[1]=d[1+n];
                a[++id]=2;
            }
            else if(n==6) a[++id]=6;
            else a[++id]=d[n];
        }
        for(ll i=id;i;i--) cout<<a[i];
        cout<<endl;
    }
    return 0;
}
