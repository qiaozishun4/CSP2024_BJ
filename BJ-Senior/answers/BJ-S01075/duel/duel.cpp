#include <iostream>
#include <algorithm>
#include <cstdio>
#define MAXN 100050
using namespace std;
int n,a[MAXN];

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int p=1;
    for (int i=2;i<=n;i++)
    {
        if (a[i]>a[p]) p++;
    }
    cout<<n-p+1<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
