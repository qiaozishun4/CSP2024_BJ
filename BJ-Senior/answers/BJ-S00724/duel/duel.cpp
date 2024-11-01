#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int a[100010];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int now=0;
    for(int i=1;i<=n;i++)
    {
        now++;
        while(now<=i)now++;
        while(a[now]==a[i]&&now<=n)now++;
        if(now==n+1)
        {
            cout<<n-i+1<<endl;
            return 0;
        }
    }
    return 0;
}