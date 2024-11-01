#include <iostream>
#include <cmath>
#include <algorithm>
#include <file>

using namespace std;

int n,count = 0,maxn = 0;
int monster[100010] = {0};
int monst[100010];
int ans;

int main()
{
    freopen("duel.in","r",stdin);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> monster[i];
        monst[monster[i]] += 1;
        if(monster[i] > maxn) maxn = monster[i];
    }
    while(count < n)
    {
        for(int i = 1; i <= maxn; i++)
        {
            if(monst[i] > 0) monst[i] -= 1; count += 1
        }
        ans += 1;
    }
    cout << ans;
    freopen("duel.out","w",stdout);
    return 0;
}
