#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int a[MAXN],N;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&N);
    for(int i=1;i<=N;i++) scanf("%d",&a[i]);
  //  printf("!%d\n",N);
    sort(a+1,a+N+1);
    int ind=0;
    for(int i=1;i<=N;i++)
    {
        if(i>ind+1&&a[ind+1]<a[i]) ind++;
    }
    printf("%d\n",N-ind);
    return 0;
}