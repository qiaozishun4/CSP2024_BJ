#include<bits/stdc++.h>
using namespace std;
int t;
int n;
long long ans = 9e18;
int stick_num[10]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
void dfs(int sticks, long long num)
{
    if(sticks==n)
    {
        ans=min(ans, num);
        return ;
    }
    for(int i = 0;i <= 9;i++)
    {
        if(sticks==0&&i==0) continue;
        if(sticks+stick_num[i]>n) continue;
        if(num*10+i>ans);
        dfs(sticks+stick_num[i], num*10+i);
    }
}
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n==1)
        {
            cout << "-1\n";
            continue;
        }
        if(n%7==0)
        {
            for(int i = 1;i <= n/7;i++) printf("8");
            printf("\n");
            continue;
        }
        ans = 9e18;
        dfs(0, 0);
        cout << ans << "\n";
    }
    return 0;
}
