#include<bits/stdc++.h>
using namespace std;
const int Maxn=1e5+10;
int n;
int Ar[Maxn];
int tmp[Maxn],tot;
int C[Maxn];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&Ar[i]);
    }
    sort(Ar+1,Ar+1+n);
    int firstpos=1;
    int killed=0;
    for(int i=2;i<=n;i++)
    {
        if(Ar[i]>Ar[firstpos])
        {
            killed++;
            firstpos++;
        }
    }
    printf("%d\n",n-killed);
    return 0;
}
