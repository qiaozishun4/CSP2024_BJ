#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int t[N];
vector<int> a, vec;
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, tmp;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        a.push_back(tmp);
        t[tmp]++;
    }
    sort(a.begin(), a.end());
    int la = a.size();
    for(int i = 0; i < la; i++)
    {
        if(i == 0 || a[i] != a[i-1]) vec.push_back(t[a[i]]);
    }
    int ans = n;
    int lv = vec.size();
    for(int i = 1; i < lv; i++)
    {
        int f = vec[i];
        for(int j = 0; j < i; j++)
        {
            if(vec[j] != 0)
            {
                int attack = min(vec[j], f);
                vec[j] -= attack;
                f -= attack;
                ans -= attack;
                if(f == 0) break;
            }
        }
    }
    cout << ans;
    return 0;
}
