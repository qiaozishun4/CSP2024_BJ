#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t,n;
int ans[20]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n<=14)
        {
            cout<<ans[n]<<"\n";
            continue;
        }
        if(n%7==0)
        {
            int p=n/7;
            for(int i=1;i<=p;i++) cout<<"8";
            cout<<"\n";
            continue;
        }
        if(n%7==1)
        {
            int p=n/7-1;
            cout<<"10";
            for(int i=1;i<=p;i++) cout<<"8";
            cout<<"\n";
            continue;
        }
        if(n%7==2)
        {
            int p=n/7;
            cout<<"1";
            for(int i=1;i<=p;i++) cout<<"8";
            cout<<"\n";
            continue;
        }
        if(n%7==3)
        {
            int p=n/7-2;
            cout<<"200";
            for(int i=1;i<=p;i++) cout<<"8";
            cout<<"\n";
            continue;
        }
        if(n%7==4)
        {
            int p=n/7-1;
            cout<<"20";
            for(int i=1;i<=p;i++) cout<<"8";
            cout<<"\n";
            continue;
        }
        if(n%7==5)
        {
            int p=n/7;
            cout<<"2";
            for(int i=1;i<=p;i++) cout<<"8";
            cout<<"\n";
            continue;
        }
        if(n%7==6)
        {
            int p=n/7;
            cout<<"6";
            for(int i=1;i<=p;i++) cout<<"8";
            cout<<"\n";
            continue;
        }
    }
    return 0;
}
