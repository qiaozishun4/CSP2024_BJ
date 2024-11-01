#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100010;

int n,cnt;
int a[maxn];

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    int i=1,j=2;
    while(j<=n)
    {
        while(a[j]<=a[i] && j<=n) j++;
        if(j>n) break;
        cnt++;
        i++;j++;
    }
    cout<<n-cnt<<endl;
    return 0;
}
