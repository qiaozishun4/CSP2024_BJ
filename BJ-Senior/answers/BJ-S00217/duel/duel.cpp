#include <iostream>
#include <cstdio>
using namespace std;
int a[100010];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,x;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> x;
        a[x]++;
    }
    int cs=0;
    for(int i=1; i<=100000; i++)
        cs=max(cs,a[i]);
    cout << cs;
    return 0;
}