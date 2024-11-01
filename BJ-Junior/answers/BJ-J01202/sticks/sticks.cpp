#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int ans[20]={0,-1,1,7,4,2,6,8,108,202,200,208,288,808};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int l=1;l<=t;++l)
    {
        cin>>n;
        if(n<7)
            cout<<ans[n]<<endl;
        else if(n%7==0)
        {
            for(int i=1;i<=n/7;++i)
                cout<<8;
            cout<<endl;
        }
        else
        {
            int tmp=n%7;
            tmp+=7;
            cout<<ans[tmp];
            for(int i=1;i<=n/7-2;++i)
            {
                cout<<8;
            }
            cout<<endl;
        }
    }
    return 0;
}
