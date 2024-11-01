#include<bits/stdc++.h>
using namespace std;
int ans[]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,208,188,209,208,288,889};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0)
        {
            for(int i=1;i<=(n/7);i++) cout<<8;
            cout<<endl;
            continue;
        }
        if(n%7==1)
        {
            cout<<"10";
            for(int i=1;i<(n/7);i++) cout<<8;
            cout<<endl;
            continue;
        }
        if(n%7==2)
        {
            cout<<"1";
            for(int i=1;i<=(n/7);i++) cout<<8;
            cout<<endl;
            continue;
        }
        cout<<ans[n]<<endl;
    }
    return 0;
}
