#include<bits/stdc++.h>
using namespace std;
int n, ans;
int a[100005];
bool life[100005];
bool atk[100005];
void dfs(int left_atk, int left_life)
{
    if(left_atk==0)
    {
        ans=min(ans, left_life);
        return ;
    }
    for(int i = 1;i <= n;i++)
    {
        if(!atk[i]&&life[i])
        {
            for(int j = 1;j <= n;j++)
            {
                if(j!=i&&life[j]&&left_life-left_atk<ans)
                {
                    atk[i]=1;
                    if(a[j]<a[i])
                    {
                        life[j]=0;
                        dfs(left_atk-1, left_life-1);
                    }
                    else dfs(left_atk-1, left_life);
                }
            }
        }
    }
}
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        life[i]++;
    }
    ans = n;
    dfs(n, n);
    cout <<ans;
    return 0;
}
