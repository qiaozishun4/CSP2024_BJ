#include <iostream>
#include <algorithm>
using namespace std;
int a[100005];
int barral[100005];
int cnt=0;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)    cin>>a[i];
    sort(a,a+n);
    barral[cnt]++;
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i-1])    barral[cnt]++;
        else    barral[++cnt]++;
    }
    int rest=0;
    for(int i=1;i<=cnt;i++){
        rest+=barral[i-1];
        n-=min(barral[i],rest);
        rest-=min(barral[i],rest);
    }
    cout<<n;
    return 0;
}
