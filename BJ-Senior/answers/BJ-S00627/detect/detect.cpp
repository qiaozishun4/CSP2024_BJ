#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <queue>

using namespace std;

struct car
{
    int start;
    int v;
    int a;
    int os_checker;
    car(int c, int a, int b)
    {
        start = c;
        v = a;
        this->a = b;
        os_checker = -1;
    }
    car()
    {
        start = 0;
        v = 0;
        a = 0;
        os_checker = -1;
    }
};

struct side
{
    int start;
    int over;
    side()
    {
        start = -1;
        over = -1;
    }
    side(int a, int b)
    {
        start = a;
        over = b;
    }
    bool operator > (const side &another)const
    {
        return this->over > another.over;
    }
};

bool che[100001];
car cars[100000];
bool mode[100001];
priority_queue <side, vector <side>, greater<side>> pqs;

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T, n, m, len, lim, temp, osp = 0, osc = 0, tend, cstart, cover;
    int last = -1, ans = 0, sp = 0;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> n >> m >> len >> lim;
        for (int j = 0; j < n; j++)
        {
            cin >> cars[j].start >> cars[j].v >> cars[j].a;
        }
        cin >> temp;
        che[temp] = true;
        cstart = temp;
        for (int j = 1; j < m - 1; j++)
        {
            cin >> temp;
            che[temp] = true;
        }
        cin >> temp;
        che[temp] = true;
        cover = temp;
        for (int j = 0; j < n; j++)
        {
//            cout << cars[j].start << ' ' << (double(lim) * lim - cars[j].v * cars[j].v) / (2 * cars[j].a) + cars[j].start << endl;
            if (cars[j].a <= 0 && cars[j].v <= lim)
            {
//                cout << j << "alivev1" << endl;
                continue;
            }
            else
            {
                if (cars[j].a > 0)
                {
                    osp = ceil((double(lim) * lim - cars[j].v * cars[j].v) / (2 * cars[j].a)) + cars[j].start;
                    if (osp > len)
                    {
//                        cout << j << "alivev2" << endl;
                        continue;
                    }
                    if (osp < 0)
                    {
                        osp = 0;
                    }
                    for (int k = osp; k < cover; k++)
                    {
                        if (che[k] == true)
                        {

                            if (che[k] == osp && (lim * lim - cars[j].v * cars[j].v) / (2 * cars[j].a) + cars[j].start > 0 && osp == int(floor((double(lim) * lim - cars[j].v * cars[j].v) / (2 * cars[j].a)) + cars[j].start))
                            {
                                sp = 1;
                                continue;
                            }
                            osc++;
                            cars[j].os_checker = k;
                            pqs.push(side(osp + sp, cover));
                            sp = 0;
                            break;
                        }
                    }
                }
                else if (cars[j].a < 0)
                {
                    osp = (lim * lim - cars[j].v * cars[j].v) / (2 * cars[j].a) + cars[j].start;
                    if (osp < 0)
                    {
//                        cout << j << "alivev3" << ' ' << osp << endl;
                        continue;
                    }
                    if (osp > len)
                    {
                        osp = len;
                    }
                    tend = max(cars[j].start, cstart);
                    for (int k = osp; k >= tend; k--)
                    {
                        if (che[k] == true)
                        {
                            if (che[k] == osp && (lim * lim - cars[j].v * cars[j].v) / (2 * cars[j].a) + cars[j].start < len && osp == int(ceil((double(lim) * lim - cars[j].v * cars[j].v) / (2 * cars[j].a)) + cars[j].start))
                            {
                                sp = 1;
                                continue;
                            }
                            osc++;
                            cars[j].os_checker = k;
                            pqs.push(side(cars[j].start, osp - sp));
                            sp = 0;
                            break;
                        }
                    }
                }
                else
                {
                    pqs.push(side(cars[j].start, cover));
                    osc++;
                    continue;
                }
            }
        }
        while (!pqs.empty())
        {
//            cout << pqs.top().start << ' ' << pqs.top().over << endl;
            if (last < pqs.top().start)
            {
//                cout << "takemore" << endl;
                last = pqs.top().over;
                ans++;
            }
            pqs.pop();
        }
        ans = m - ans;
        cout << osc << ' ' << ans << endl;
        osc = 0;
        ans = 0;
        osp = 0;
        last = 0;
        sp = 0;
    }
    return 0;
}
