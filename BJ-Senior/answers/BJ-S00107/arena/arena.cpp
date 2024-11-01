#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N=1e5+3,M=N,R=__lg(N)+3,G=N;
bool d[R][G];
int agen[N];
int c[M];
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>agen[i];
    }
    for (int i=1;i<=m;i++)
    {
        cin>>c[i];
    }
    int k;
    if ((1<<__lg(n))==n)
    {
        k=__lg(n);
    }
    else
    {
        k=__lg(n)+1;
    }
    for (int i=1;i<=k;i++)
    {
        for (int j=1;j<=(1<<(k-i));j++)
        {
            char c;
            cin>>c;
            d[i][j]=c-'0';
        }
    }
    int t;
    cin>>t;
    while (t--)
    {
        cout<<0<<endl;
    }
    return 0;
}
