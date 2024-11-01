#include<bits/stdc++.h>
using namespace std;
int t , n , ans[100005] , minws , cost[10] = {6 , 2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6};
inline bool dfs(int deep , int nless)
{
    if(deep > minws)
    {
        if(nless == 0)
        {
            return 1;
        }
        return 0;
    }
    if(deep + ceil(1.0 * nless / 7.0) - 1 > minws)
    {
        return 0;
    }
    if(deep == 1)
    {
        for(int i = 1 ; i <= 9 ; i++)
        {
            if(dfs(deep + 1 , nless - cost[i]))
            {
                ans[deep] = i;
                return 1;
            }
        }
    }
    else
    {
        for(int i = 0 ; i <= 9 ; i++)
        {
            if(dfs(deep + 1 , nless - cost[i]))
            {
                ans[deep] = i;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    freopen("sticks.in" , "r" , stdin);
    freopen("sticks.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n <= 1)
        {
            cout << "-1\n";
            continue;
        }
        minws = ceil(1.0 * n / 7.0);
        if(!dfs(1 , n))
        {
            cout << "-1\n";
            continue;
        }
        for(int i = 1 ; i <= minws ; i++)
        {
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}