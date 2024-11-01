#include<bits/stdc++.h>
using namespace std;
long long x[200][200];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    long long n,sum=0;
    cin>>n;
    while(n--)
    {
        char a[2];
        cin>>a;
        x[a[0]][a[1]]++;
    }
    for(long long i=1;i<=150;i++)
    {
        for(long long j=1;j<=150;j++)
        {
            if(x[i][j]!=0) sum++;
        }
    }
    cout<<52-sum;
    return 0;
}
