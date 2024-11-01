#include<bits/stdc++.h>
using namespace std;
long long n,t;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i = 1;i <= t;i++)
    {
        cin>>n;
        if(n % 7 == 0)
        {
            long long len = n / 7;
            for(int j = 1;j <= len;j++) cout<<"8";
            cout<<endl;
        }
        if(n % 7 == 1)
        {
            long long len = (n - 1) / 7 - 1;
            cout<<"10";
            for(int j = 1;j <= len;j++) cout<<"8";
            cout<<endl;
        }
    }
    return 0;
}
