//#include<cassert>
#include<iostream>
#include<algorithm>
using namespace std;
char d[20][100005];
int n,m,a2[100005],c[100005],xX[4],tp,K,T;
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a2[i];
    for(int i=1;i<=m;i++)
        cin>>c[i];
    while((1<<K)<n)k++;
    for(int i=1;i<=k;i++)
        cin>>d[i];
    cin>>T;
    while(T--)
    {
        for(int i=0;i<4;i++)
            cin>>xX[i];
        for(int i=1;i<=n;i++)
            a[i]=a2[i]%xX[i%4];

    }
    return 0;
}
