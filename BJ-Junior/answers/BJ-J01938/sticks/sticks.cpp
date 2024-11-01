#include <bits/stdc++.h>
using namespace std;

int T,n;
int num[15] = {6,2,5,5,4,5,6,3,7,6};
int sum[100005];
int minn = 1e9;


void dfs(int step)
{
    if(n == 0)
    {
        int mod = 1;
        for(int i = 1 ; i < step-1 ; i++) mod*=10;
        int ans = 0;
        int u = 1;
        step -= 1;
        sort(sum+1,sum+step+1);
        while(sum[u] == 0)
        {
            u += 1;
        }
        ans = sum[u]*mod;
        for(int i = 1 ; i <= step ; i++)
        {
            if(i != u)
            {
                mod /= 10;
                ans = ans+sum[i]*mod;
            }
        }
        minn = min(minn,ans);
        return;
    }
    for(int i = 7 ; i >= 2 ; i--)
    {
        if(i == 7 && n-7 != 1 && n-7 >=0)
        {
            sum[step] = 8;
            n -= 7;
            dfs(step+1);
            n += 7;
        }
        else if(i == 6 && n-6 != 1 && n-6 >=0)
        {
            sum[step] = 6;
            n -= 6;
            dfs(step+1);
            n += 6;
        }
        else if(i == 5&& n-5 != 1 && n-5 >=0)
        {
            sum[step] = 2;
            n -= 5;
            dfs(step+1);
            n += 5;
        }
        else if(i == 4 && n-4 != 1 && n-4 >=0)
        {
            sum[step] = 4;
            n -= 4;
            dfs(step+1);
            n += 4;
        }
        else if(i == 3 && n-3 != 1 && n-3 >=0)
        {
            sum[step] = 7;
            n -= 3;
            dfs(step+1);
            n += 3;
        }
        else if(i == 2&& n-2 != 1 && n-2 >=0)
        {
            sum[step] = 1;
            n -= 2;
            dfs(step+1);
            n += 2;
        }
    }
}

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> T;
    for(int i = 1 ; i <= T ; i++)
    {
        minn = 1e9;
        cin >> n;
        if(n <= 1) cout << -1 << endl;
        else
        {
            dfs(1);
            cout << minn << endl;
        }
    }
    return 0;
}
