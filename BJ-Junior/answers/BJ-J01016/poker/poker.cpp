#include <iostream>
using namespace std;
int n,pai[5][15],ans;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string a;
        cin>>a;
        int s;
        if(a[1]>='2'&&a[1]<='9')
            s=a[1]-'0';
        if(a[1]=='A')
            s=1;
        if(a[1]=='T')
            s=10;
        if(a[1]=='J')
            s=11;
        if(a[1]=='Q')
            s=12;
        if(a[1]=='K')
            s=13;
        if(a[0]=='D')
            pai[1][s]++;
        if(a[0]=='C')
            pai[2][s]++;
        if(a[0]=='H')
            pai[3][s]++;
        if(a[0]=='S')
            pai[4][s]++;
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(pai[i][j]==0)
                ans++;
        }
    }
    cout<<ans;
    return 0;
}
