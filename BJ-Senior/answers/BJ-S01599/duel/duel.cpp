#include<iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[100100];

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int cur = 1;
    int cnt = n;
    for(int i = n/2;i <= n;i ++)
    {
        if(a[i] > a[cur])
        {
            cur++;
            cnt--;
        }
    }
    cout << cnt <<endl;
    return 0;
}
