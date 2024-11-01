#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+3;
typedef long long ll;
int a[N], same[N];
ll s[N];
pair<ll, int> dp[N];
unordered_map<int, int> lsm;

ll inline query(int i, int j)
{
    if(i >= j) return 0;
    return s[j] - s[i-1] - (a[i] == a[i-1] ? a[i] : 0);
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        a[0] = 0;
        s[0] = 0;
        lsm.clear();
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            s[i] = s[i-1] + (a[i] == a[i-1] ? a[i] : 0);
            if(lsm.count(a[i]))
            {
                same[i] = lsm[a[i]];
            }
            else
            {
                same[i] = 0;
            }
            lsm[a[i]] = i;
            dp[i] = (i == 1 ? make_pair(0ll, 0) : dp[i-1]);
            if(i != 1 && a[i+1] != a[dp[i].second])
                dp[i].second = i-1;
            if(same[i])
            {
                if(same[i] == i-1)//a[i] == a[i-1]
                {
                    dp[i].first = dp[i-1].first + a[i];
                    dp[i].second = dp[i-1].second;
                }
                else if(same[i] == dp[i-1].second)
                {
                    dp[i].first = dp[i-1].first + a[i];
                    dp[i].second = i-1;
                }
                else
                {
                    ll tmp = dp[same[i]].first + query(same[i]+1, i-1) + (a[same[i]+1] == a[dp[same[i]].second] ? a[same[i]+1] : 0) + a[i];
                    if(tmp >= dp[i].first)
                    {
                        dp[i].first = tmp;
                        dp[i].second = i-1;
                    }
                }
            }
            /*for(int j = 0; j < i; j++)
            {
                ll tmp = dp[j].first + query(j+1, i) + (a[j+1] == a[dp[j].second] ? a[j+1] : 0);
                if(tmp >= dp[i].first)
                {
                    dp[i].first = tmp;
                    dp[i].second = j;
                }
            }*/
            //cout << "i=" << i << " a=" << a[i] << " same=" << same[i] << " s=" << s[i] << " dpf=" << dp[i].first << " dps=" << dp[i].second << endl;
        }
        cout << dp[n].first << endl;
    }
    return 0;
}
