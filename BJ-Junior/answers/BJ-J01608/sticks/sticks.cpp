#include<bits/stdc++.h>
using namespace std;
int T;
int sticks_n,sticks_now,num_min,num_now;
int num_of_sticks[10] = {6,2,5,5,4,5,6,3,7,6};
void dfs_ways()
{
    int i;
    for(i = 0; i <= 9; i++)
    {
        if(num_now == 0 && i == 0) continue;
        if(sticks_n - sticks_now == 0)
        {
            if(num_now <= num_min) num_min = num_now;
            return ;
        }
        if(sticks_n - sticks_now == 1) return ;

        if(sticks_now + num_of_sticks[i] > sticks_n) continue;

        num_now = num_now * 10 + i;
        sticks_now = sticks_now + num_of_sticks[i];
        dfs_ways();
        num_now /= 10;
        sticks_now = sticks_now - num_of_sticks[i];
    }
    return ;
}
void solve()
{
    int n;
    cin >> n;
    if (n <= 1)
    {
        cout << "-1\n";
        return ;
    }
    sticks_n = n;
    sticks_now = 0;
    num_min = 1e+9;
    num_now = 0;

    dfs_ways();

    cout << num_min << "\n";
    return ;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    int i;
    cin >> T;
    for (i = 1; i <= T; i++) solve();
    return 0;
}
