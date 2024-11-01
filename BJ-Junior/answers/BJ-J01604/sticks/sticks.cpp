#include<bits/stdc++.h>
using namespace std;
int a[14]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68},n,t;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n;
        if (n<=7)
        {
            cout<<a[n]<<endl;
        }
        else
        {
            cout<<a[n%7+7];
            for (int i=1;i<=n/7-1;i++)
            {
                cout<<"8";
            }
            cout<<endl;
        }
    }
    return 0;
}