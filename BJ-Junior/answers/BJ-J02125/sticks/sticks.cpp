#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        int n;
        cin>>n;
        if(n<2)
        {
            cout<<"-1"<<endl;
            continue;
        }
        if(n<7)
        {
            if(n==2) cout<<"2"<<endl;
            else if(n==3) cout<<"7"<<endl;
            else if(n==4) cout<<"4"<<endl;
            else if(n==5) cout<<"2"<<endl;
            else if(n==6) cout<<"6"<<endl;
            continue;
        }
        for(int i=1;i<=n/7;i++)
        {
            cout<<"8";
        }
        cout<<endl;
    }
    return 0;
}
