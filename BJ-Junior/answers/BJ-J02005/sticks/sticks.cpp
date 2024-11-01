#include<bits/stdc++.h>
using namespace std;
int T;
int main()
{
    freopen("sticks.in","r".stdin);
    freopen("sticks.out","w".stdout);
    int a[1000000];
    cin>>T;
    if(T==1) cout<<-1,return 0;
    for(int i=1;i<=T;i++)
    {
        cout<<a[i];
    }
    return 0;
}