#include <bits/stdc++.h>
using namespace std;
int a[100010];
int flag[100010];
bool cmp(int x, int y)
{
    return x > y;
}
bool check1(int x, int y)
{
    int cnt = 0;
    for(int i = x + 1; i <= y; i++)
    {
        if(a[i] == a[i - 1])
        {
            cnt++;
        }
    }
    if(cnt == y - x)
    {
        return true;
    }
    return false;
}
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    int k = n;
    for(long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    int g = n;
    int j;
    if(a[1] == a[2])
    {
        flag[1] += 0;
        j = 1;
    }else
    {
        g--;
        flag[1] += 2;
        j = 2;
    }
    while(j <= n)
    {
        int id = 0;
        int minn  = a[1] + 1;
        if(flag[j] >= 2)
        {
            j++;
            continue;
        }
        if(check1(j, k) == true)
        {
            cout << g;
            return 0;
        }
        for(int i = j + 1; i <= n; i++)
        {
            if(a[j] - a[i] < minn && flag[i] < 2 && a[j] - a[i] != 0)
            {
                minn = a[j] - a[i];
                id = i;
            }
        }
        if(minn == a[1] + 1)
        {
            break;
        }else{
            flag[j]++;
            flag[id] += 2;
            g--;
            k--;
            j++;
        }
    }
    cout << g;
    return 0;
}

