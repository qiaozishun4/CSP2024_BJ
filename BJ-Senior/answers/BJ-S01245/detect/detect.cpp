#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Car
{
    int d, v, a;
} cars[100001];
vector<int> detor[101];
bool over[100001];
int de[1000001];

int main()
{
    ifstream fin("detect.in");
    ofstream fout("detect.out");

    int t;
    fin >> t;
    while (t--)
    {
        bool c2 = true, c3 = true;
        int n, m, L, V;
        fin >> n >> m >> L >> V;
        if (n <= 20 && m <= 20)
        {
            for (int i = 0; i < n; i++)
            {
                fin >> cars[i].d >> cars[i].v >> cars[i].a;
            }
            for (int i = 0; i < m; i++)
            {
                int p;
                fin >> p;
                for (int j = 0; j < n; j++)
                {
                    if (cars[j].d > p)
                    {
                        continue;
                    }
                    if (cars[j].v * cars[j].v + 2 * cars[j].a * (p - cars[j].d) > V * V)
                    {
                        over[j] = true;
                        detor[i].push_back(j);
                    }
                }
            }
            int ans1 = 0;
            for (int i = 0; i < n; i++)
            {
                ans1 += over[i];
            }
            fout << ans1 << ' ';

            long long up = 1;
            for (int i = 0; i < m; i++)
            {
                up *= 2;
            }

            bool hav[20];
            int ans2 = 0;
            for (long long i = 0; i < up; i++)
            {
                int total = 0;
                bool check = true;
                bool cxk[30];
                long long nw = i;

                for (int j = 0; j < m; j++)
                {
                    cxk[j] = false;
                    hav[j] = nw % 2;
                    nw /= 2;
                    if (!hav[j])
                    {
                        total++;
                    }
                }

                for (int j = 0; j < m; j++)
                {
                    if (hav[j])
                    {
                        for (int z = 0; z < detor[j].size(); z++)
                        {
                            cxk[detor[j][z]] = true;
                        }
                    }
                }
                for (int j = 0; j < n; j++)
                {
                    if (!cxk[j] && over[j])
                    {
                        check = false;
                    }
                }

                if (check)
                {
                    ans2 = max(ans2, total);
                }
            }
            fout << ans2 << endl;
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            fin >> cars[i].d >> cars[i].v >> cars[i].a;
            if (cars[i].v <= 0)
            {
                c2 = false;
            }
            if (cars[i].v >= 0)
            {
                c3 = false;
            }
        }
        memset(over, 0, sizeof(over));

        int last = 0, cnt = 0;
        for (int i = 0; i < m; i++)
        {
            int p;
            fin >> p;
            for (int j = last; j < p; j++)
            {
                de[j] = cnt;
            }
            last = p;
            cnt++;
        }
        for (int j = last; j <= L; j++)
        {
            de[j] = cnt;
        }

        for (int i = 0; i < n; i++)
        {
            if (cars[i].a == 0)
            {
                over[i] = (cars[i].v > V) && (de[L] - de[cars[i].d - 1]);
                continue;
            }

            double x = (V * V - cars[i].v * cars[i].v) / (2.0 * cars[i].a);
            if (x < 0 && cars[i].a > 0)
            {
                over[i] = de[L] - de[cars[i].d - 1];
                continue;
            }
            if (x < 0 && cars[i].a < 0)
            {
                over[i] = false;
                continue;
            }

            int t1 = cars[i].d + x;
            if (t1 >= L)
            {
                continue;
            }
            over[i] = (cars[i].a >= 0 ? de[L] - de[t1] : de[t1] - de[cars[i].d - 1]);
        }

        int ans1 = 0;
        for (int i = 0; i < n; i++)
        {
            ans1 += over[i];
        }
        fout << ans1 << ' ';

        if (c2)
        {
            if (ans1 == 0)
            {
                fout << m << endl;
            }
            else
            {
                fout << m - 1 << endl;
            }
        }
        else
        {
            fout << endl;
        }
    }
}