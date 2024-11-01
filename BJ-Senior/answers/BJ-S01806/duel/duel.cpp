#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int a[100005];
int b[100005];

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(b[a[i]] == 0)cnt++;
        b[a[i]]++;
    }
    sort(a + 1,a + n + 1);
    unique(a + 1,a + n + 1);
    for(int i = 1;i <= cnt - 1;i++)
    {
        b[a[i]] -= min(b[a[i]],b[a[i + 1]]);
        b[a[i + 1]] += b[a[i]];
    }
    cout << b[a[cnt]] << endl;
    return 0;
}

//对于每一只怪兽，分成不同的阶级，UP attack LOW, UP += LOW,low first
