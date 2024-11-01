#include<bits/stdc++.h>
using namespace std;
bool f[305][305];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,sum=0;
    cin>>n;
    char x,y;
    for (int i=1;i<=n;i++)
    {
        cin>>x>>y;
        int a=int(x),b=int(y);
        if (f[a][b]==0) sum++,f[a][b]=1;
    }
    cout<<52-sum;
    return 0;
}
