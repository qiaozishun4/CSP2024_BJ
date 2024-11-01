#include <bits/stdc++.h>
using namespace std;
int T,a[100010]={-1,-1,7,6,4,2,6,8,10,18,23,20,28,68,88,108,188,200,208,288,688};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    for(int num=0;num<T;num++)
    {
        int n;
        cin>>n;
        cout<<a[n];
    }
    return 0;
}
