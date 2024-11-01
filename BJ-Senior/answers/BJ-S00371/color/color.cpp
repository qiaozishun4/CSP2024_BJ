#include<bits/stdc++.h>
using namespace std;
int t;
int a[15];
bool b[15];
int n, ans = -1e9;
void dfs(int step)
{
    if(step>n)
    {
        int sum = 0;
        int nr = -1, nb = -1;
        for(int i = 1;i <= n;i++)
        {
            if(b[i]==0)
            {
                if(nr==-1) nr = i;
                else if(a[i]==a[nr]) nr = i, sum+=a[nr];
                else nr = i;
            }
            else
            {
                if(nb==-1) nb = i;
                else if(a[i]==a[nb]) nb = i, sum+=a[nb];
                else nb = i;
            }
        }
        ans=max(ans, sum);
        return ;
    }
    b[step]=0;
    dfs(step+1);
    b[step]=1;
    dfs(step+1);
}
int main()
{
    //freopen("color.in", "r", stdin);
    //freopen("color.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        ans = -1e9;
        cin >> n;
        if(n<=15)
        {
            for(int i = 1;i <= n;i++)
            {
                cin >> a[i];
            }
            dfs(1);
            cout << ans << "\n";
        }
        else
        {
            vector<int> vec[100005];
            for(int i = 1;i <= n;i++)
            {
                vec[i] = vector<int>();
            }
            for(int i  = 1;i <= n;i++)
            {
                cin >> a[i];
                vec[a[i]].push_back(i);
            }
            int c[100005] = {};
            for(int i = n;i >= 1;i--)
            {
                if(c[i]) continue;
                if(c[i+1]==1) c[i]=2;
                else c[i]=1;
                for(auto j : vec[a[i]])
                {
                    c[j]=c[i];
                }
            }
            int nr = -1, nb = -1, sum = 0;
            for(int i = 1;i <= n;i++)
            {
                if(c[i]==1)
                {
                    if(nr==-1) nr = i;
                    else if(a[i]==a[nr]) nr = i, sum+=a[nr];
                    else nr = i;
                }
                else
                {
                    if(nb==-1) nb = i;
                    else if(a[i]==a[nb]) nb = i, sum+=a[nb];
                    else nb = i;
                }
            }
            cout << sum << "\n";
        }
    }
    return 0;
}
