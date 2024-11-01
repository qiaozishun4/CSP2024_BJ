#include<iostream>

using namespace std;
int t, n, a[25], blue, red, c, ctmp;
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n>22){for(int i=1;i<=n;i++)cin>>a[0];cout<<"0\n";continue;}
        for(int i=0;i<n;i++)cin>>a[i];
        c=0;
        for(int i=0;i<(1<<n);i++)
        {
            blue=red=ctmp=0;
            for(int j=0;j<n;j++)
            {
                if((i&(1<<j))&&blue==a[j])ctmp+=blue;
                else if(i&(1<<j))blue=a[j];
                else if((~i&(1<<j))&&red==a[j])ctmp+=red;
                else red=a[j];
            }
            c=max(c, ctmp);
        }
        cout<<c<<"\n";
    }
    return 0;
}