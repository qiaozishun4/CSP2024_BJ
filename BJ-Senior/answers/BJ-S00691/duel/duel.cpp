#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    int x=1,s=n;
    for(int i=2;i<=n;i++)
    {
        if(a[i]>a[x])
        {
            s--;
            x++;
        }
    }
    printf("%d",s);
    return 0;
}
