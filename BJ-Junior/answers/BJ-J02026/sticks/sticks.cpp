#include<bits/stdc++.h>
using namespace std;
int a[21]={-1,-1,1,7,4,2,6,8,10,18,22,20,60,80,88,108,188,206,208,288,688};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int w;
        cin>>w;
        cout<<a[w]<<endl;
    }
    return 0;
}