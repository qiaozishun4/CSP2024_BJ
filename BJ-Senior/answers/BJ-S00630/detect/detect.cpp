#include<bits/stdc++.h>
using namespace std;
int d[100010], v[100010], a[100010], p[100010];
int unl[100010];
struct PD
{
    int id = 0, num = 0;
    vector<int> r;
} pd[100010];

bool cmp(PD a, PD b)
{
    return a.num > b.num;
}
int main()
{
    ifstream fin("detect.in", ios::in);
    ofstream fout("detect.out", ios::out);
    int t;
    fin >> t;
    while(t--)
    {
        int n, m, L, V;
        fin >> n >> m >> L >> V;
        vector<int> init;
        for(int i = 0;i < m;i++) pd[i].id = i, pd[i].num = 0, pd[i].r = init;
        for(int i = 0;i < n;i++)
        {
            fin >> d[i] >> v[i] >> a[i];
            unl[i] = 0;
        }
        for(int i = 0;i < m;i++) fin >> p[i];
        int sum = 0;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                int sp = sqrt(max(0, v[i] * v[i] + 2 * a[i] * p[j]));
                if(sp > V)
                {
                    unl[i]++;
                    sum++;
                    pd[j].num++;
                    pd[j].r.push_back(i);
                }
            }
        }
        sort(pd, pd + m, cmp);
        int ans1 = 0, ans2 = 0;
        for(int i = 0;i < n;i++)
        {
            if(unl[i] >= 1) ans1++;
        }
        for(int i = 0;i < m;i++)
        {
            bool flag = false;
            for(int j = 0;j < pd[i].r.size();j++)
            {
                int k = pd[i].r[j];
                if(unl[k] < 2)
                {
                    flag = true;
                    break;
                }
            }
            if(!flag)
            {
                ans2++;
                for(int j = 0;j < pd[i].r.size();j++)
                {
                    int k = pd[i].r[j];
                    unl[k]--;
                }
            }
        }
        fout << ans1 << ' ' << ans2-- << endl;
    }
    return 0;
}
