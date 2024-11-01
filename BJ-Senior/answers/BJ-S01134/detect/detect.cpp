//#define DBG
//Should get 0

#ifdef DBG
#include <iostream>
#else
#include <fstream>
#endif
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

#ifdef DBG
template<typename... Arg>
void log(Arg... args)
{
    cerr << "\033[1;32m{";
    ((cerr << args << ' '), ...);
    cerr << "}\033[0;0m\n";
}
#endif

#ifndef DBG
ifstream cin("detect.in");
ofstream cout("detect.out");
#endif

long long int T, n, m, l, v;
double minx[100001], maxx[100001], d[100001], v0[100001], a[100001], xp[100001], pss[1000001];
pair<double, double> dur[100001];

template<typename T> class que
{
    int h, t;
    T data[100001];
public:
    int size()
    {
        return h-t;
    }
    bool empty()
    {
        return h-t;
    }
    void push(T d)
    {
        data[h++] = d;
    }
    void pop()
    {
        t++;
    }
    T front()
    {
        return data[t];
    }
};

int main()
{
    #ifdef DBG
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> l >> v;
        for(int i = 0; i < n; i++)
        {
            cin >> d[i] >> v0[i] >> a[i];
            if(a == 0)
            {
                if(v0[i] < v) maxx[i] = -1;
                else maxx[i] = l+1, minx[i] = d[i];
            }
            else if(a < 0)
            {
                if(v0[i] < v) maxx[i] = -1;
                else
                {
                    minx[i] = d[i];
                    maxx[i] = (v-v0[i])/a[i];
                    maxx[i] = v0[i]*maxx[i] - (a[i]*maxx[i]*maxx[i])/2;
                }
            }
            else
            {
                if(v0[i] >= v) maxx[i] = l+1, minx[i] = d[i];
                else
                {
                    maxx[i] = l+1;
                    minx[i] = (v-v0[i]) / a[i];
                    minx[i] = v0[i]*minx[i] - (a[i]*minx[i]*minx[i])/2;
                }
            }
            dur[i] = make_pair(maxx[i], minx[i]);
        }
        sort(dur, dur+n, [](pair<double, double> x, pair<double, double> y){return (x.first != y.first) ? (x.first < y.first) : (x.second > y.second);});
        memset(pss, 0, sizeof(pss));
        for(int i = 0; i < m; i++)
        {
            cin >> xp[i];
            ++pss[(int)xp[i]];
        }
        for(int i = 1; i <= l; i++)
        {
            pss[i] += pss[i-1];
        }
        int ans1 = 0, ans2 = 0;
        for(int i = 0; i < n; i++)
        {
            if(pss[(int)(minx[i] + 1)] - pss[(int)(minx[i]) - 1] > 0) ans1++;
        }
        int cur = 0, lst[100001], sz = 0, ddiff = 0;
        que<int> llst;
        for(int i = 1; i <= l; i++)
        {
            if(dur[cur].second > i) continue;
            while(cur < n && dur[cur].first < i) cur++;
            if(cur == n) break;
            while(!llst.empty() && llst.front() < dur[cur].second)
            {
                ++ddiff;
                llst.pop();
            }
            while(pss[i] - ans2 + ddiff - pss[(int)(dur[cur].second) - 1] > 1)
            {
                llst.push(i);
                ++ans2;
            }
        }
        cout << ans1 << ' ' << ans2 << '\n';
    }
    return 0;
}