#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,t,a[]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,177,408,208,588,808};
signed main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i,j,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if (n==1)
            cout<<-1<<endl;
        else if (n%7==0)
        {
            for (i=1;i<=n/7;i++)
                cout<<8;
            cout<<endl;
        }
        else if (n%7==1)
        {
            cout<<10;
            for (i=1;i<n/7;i++)
                cout<<8;
            cout<<endl;
        }
        else
            cout<<a[n]<<endl;
    }
}
