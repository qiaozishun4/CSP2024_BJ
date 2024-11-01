#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","r",stdout);
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n/7;i++)
            cout<<8;
        cout<<'\n';
    }
    return 0;
}
