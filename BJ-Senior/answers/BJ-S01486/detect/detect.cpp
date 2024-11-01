#include<bits/stdc++.h>
using namespace std;
typedef pair <int, int> pii;
const int N = 1e5 + 5, M = 1e6 + 5;
int d[N], v[N], a[N], p[N], cntf[N], f[M];
vector < pii > v1;
bool cmp(pii a, pii b)
{
    return a.first < b.first;
}
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        memset(f, 0, sizeof(f));
        memset(cntf, 0, sizeof(cntf));
        v1.clear();
        int n, m, L, V;
        cin >> n >> m >> L >> V;
        for(int i = 1;i <= n;i++)
            cin >> d[i] >> v[i] >> a[i];
        for(int i = 1;i <= m;i++)
            cin >> p[i], f[p[i]]++;
        for(int i = L;i >= 1;i--)
            f[i] += f[i + 1];
        int cnt = 0;
        for(int i = 1;i <= n;i++)
        {
            if(a[i] == 0)
            {
                if(v[i] > V && f[d[i]] > 0)
                    cnt++, v1.push_back({d[i], L});
                continue;
            }
            int flag = (V * V - v[i] * v[i]) / (2 * a[i]);
            if(a[i] < 0)
            {
                if(f[d[i]] - f[min(d[i] + flag + 1, L + 1)] > 0)
                    cnt++, v1.push_back({d[i], min(d[i] + flag, L)});
            }
            else if(a[i] > 0)
            {
                if(f[min(d[i] + flag, L + 1)] > 0)
                    cnt++, v1.push_back({min(d[i] + flag, L), L});
            }
        }
        sort(v1.begin(), v1.end(), cmp);
        for(int i = 0;i < v1.size();i++)
            cntf[i] = f[v1[i].first] - f[v1[i].second + 1];
        int cnt1 = 0;
        for(int i = 1;i <= m;i++)
        {
            if(p[i] < v1[0].first)
                continue;
            if(p[i] > v1[v1.size() - 1].second)
                break;
            bool fl = true;
            for(int j = 0;j < v1.size();j++)
            {
                if(p[i] < v1[j].first)
                    break;
                if(p[i] > v1[j].second)
                    continue;
                if(cntf[j] == 1)
                {
                    fl = false;
                    break;
                }
            }
            if(fl == false)
            {
                cnt1++;
                continue;
            }
            for(int j = 0;j < v1.size();j++)
            {
                if(p[i] < v1[j].first)
                    break;
                if(p[i] > v1[j].second)
                    continue;
                cntf[j]--;
            }
        }
        cnt1 = m - cnt1;
        cout << cnt << " " << cnt1 << endl;
    }
    return 0;
}