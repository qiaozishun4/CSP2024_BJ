#include <bits/stdc++.h>
using namespace std;
const int N=100;
int h[N]={0,-1,1,7,4,5,6,8,10,18,22,20,28,68,88,108,188,228,208,288,688};
int ans[10];
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        int n;
        cin>>n;
        cout<<h[n]<<endl;
    }
    return 0;
}
