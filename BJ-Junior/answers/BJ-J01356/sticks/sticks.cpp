#include <bits/stdc++.h>

using namespace std;

long long a[52]={-1,-1,1,7,4,2,6,8,10,18,22,20,58,80,88,108,188,206,208,288,688,888,1088,1888,2080,2088,5888,8088,10888,18688,20688,20888,58888,80888,88888,108888,188888,206888,208888,258888,688888,888888,1088888,1888888,2068888,2088888,2888888,6888888,8888888,10888888};
int t,n;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n<=50)cout<<a[n]<<endl;
        else if(n%7==0){for(int i=1;i<=n/7;i++)cout<<8;cout<<endl;}
        else {cout<<10;for(int i=1;i+1<=n/7;i++)cout<<8;cout<<endl;}
    }
    return 0;
}
