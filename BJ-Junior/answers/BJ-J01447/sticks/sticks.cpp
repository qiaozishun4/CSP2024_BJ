#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        if(n%7==0)
        {
            for(int i=1;i<=n/7;i++)cout<<8;
            cout<<endl;
        }
        else if(n%7==1)
        {
            n--;
            for(int i=1;i<=n/7-1;i++)cout<<8;
            cout<<10;
            cout<<endl;
        }
    }
    return 0;
}
