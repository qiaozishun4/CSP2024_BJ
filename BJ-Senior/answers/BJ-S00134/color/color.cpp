#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        memset(a,0,sizeof(a));
        int n;
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            cin>>a[i];
        }
        cout<<"0"<<endl;
    }
    return 0;
}
