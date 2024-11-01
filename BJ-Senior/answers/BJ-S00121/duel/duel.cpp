#include <bits/stdc++.h>

using namespace std;
long long a[100010];
long long b[100010];
int main()
{
    freopen("duel.in" , "r" , stdin);
    freopen("duel.out" , "w" , stdout);
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
    {
        int x;
        scanf("%d" , &x);
        b[x]++;
    }
    int cur = 0;
    for(int i = 1 ; i <= 100000 ; i ++)
    {
        if(b[i] != 0)
        {
            cur ++;
            a[cur] = b[i];
            //cout << a[cur] << " ";
        }
    }
    //cout << endl;
    long long ans = 0;
    long long sum = 0;
    for(int i = 2 ; i <= cur ; i ++)
    {
        ans += min(a[i] , a[i - 1]);
        if(a[i] < a[i - 1])
        {
            sum += (a[i - 1] - a[i]);
        }
        if(a[i] > a[i - 1])
        {
            if(a[i] - a[i - 1] >= sum)
            {
                ans += sum;
                sum = 0;
            }
            else{
                sum -= a[i] - a[i - 1];
                ans += a[i] - a[i - 1];
            }
        }
    }
    cout << (n - ans) << endl;
    return 0;
}
