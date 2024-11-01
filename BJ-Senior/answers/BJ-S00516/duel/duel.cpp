#include<bits/stdc++.h>
using namespace std;
int n , a[100005] , lp , ans;
bool eat[100005];
int main()
{
    freopen("duel.in" , "r" , stdin);
    freopen("duel.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    sort(a + 1 , a + n + 1);
    lp = 1;
    for(int i = 2 ; i <= n ; i++)
    {
        if(a[i] > a[lp])
        {
            eat[lp] = 1;
            lp++;
        }
    }
    for(int i = 1 ; i <= n ; i++)
    {
        if(!eat[i])
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}