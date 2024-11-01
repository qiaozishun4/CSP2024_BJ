#include <bits/stdc++.h>
using namespace std;
int a[14]={8,0,1,7,4,2,6,8,10,18,22,20,28,68};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==1)cout<<-1<<endl;
        else
        {
            int cnt=n/7-1;
            n=n-7*cnt;
            if(n==1)n=8,cnt--;
            cout<<a[n];
            for(int i=1;i<=cnt;i++)cout<<8;
            cout<<endl;
        }
    }
}