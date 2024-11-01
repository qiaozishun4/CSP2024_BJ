#include<bits/stdc++.h>
using namespace std;
int a[100010];
map<int,int> t;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        t[a[i]]++;
    }
    long long pren=0;
    long long sheng=0;
    for(auto it:t)
    {
        if(it.second>=pren)
        {
            sheng=max(1LL*0,sheng-(it.second-pren));
        }
        else
        {
            sheng+=(pren-it.second);
        }
        pren=it.second;
    }
    printf("%lld",sheng+pren);
    return 0;
}
