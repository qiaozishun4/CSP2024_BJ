#include <bits/stdc++.h>
using namespace std;

const int N = 100010, M = 1000010;

int T, n, m, L, V;

struct Car
{
    int d, v, a, flag;
};

/*struct P
{
    int v, c;
};*/

Car car[N], carr[N];

int p[N], ss[M], sss[M];

bool pp[M];

int CEIL(double x)
{
    if(x == int(x)) return x;
    return int(x) + 1;
}

int main()
{
    cin >> T;
    while(T--)
    {
        memset(pp, 0, sizeof(pp));
        cin >> n >> m >> L >> V;
        for(int i = 1;i <= n;i++)
        {
            cin >> car[i].d >> car[i].v >> car[i].a;
            if(car[i].a > 0) car[i].flag = 1;
            else if(car[i].a < 0) car[i].flag = 0;
            else car[i].flag = 2;
        }
        for(int i = 1;i <= m;i++)
        {
            cin >> p[i];
            //pp[p[i].v] = 1;
        }
        /*for(int i = 0;i <= L;i++)
        {
            
        }*/
        int cnt = 0;
        for(int i = 1;i <= n;i++)
        {
            double xs;
            double ys;
            if(car[i].flag == 2)
            {
                if(car[i].v <= V) continue;
                //carr[++cnt] = car[i];
                //sss[car[i].d]++;
                //cout << i << endl;
                for(int j = 1;j <= m;j++)
                {
                    if(p[j] >= car[i].d) {carr[++cnt] = car[i]; break; }
                }
                continue;
            }
            xs = car[i].d + 1.0 * (V * V - car[i].v * car[i].v) / (2 * car[i].a);
            ys = min(1.0 * L, car[i].d + 1.0 * (0 - car[i].v * car[i].v) / (2 * car[i].a));
            //cout << xs << " " << ys << " " << car[i].d << " " << i << endl;
            if(car[i].flag == 0)
            {
                if(xs <= car[i].d) continue;
                //sss[CEIL(xs)]--;
                //sss[car[i].d]++;
                //cout << i << endl;
                //carr[++cnt] = car[i];
                for(int j = 1;j <= m;j++)
                {
                    if(p[j] >= car[i].d&& p[i] <= CEIL(xs)) {carr[++cnt] = car[i]; break;}
                }
            }
            else
            {
                if(xs >= L) continue;
                //carr[++cnt] = car[i];
                //cout << i << endl;
                //sss[CEIL(xs)]++;
                //sss[int(ys)]--;
                for(int j = 1;j <= m;j++)
                {
                    if(p[j] >= CEIL(xs) && p[i] <= int(ys)) {carr[++cnt] = car[i]; break;}
                }
            }
        }
        //for(int i = 1;i <= L;i++) cout << sss[i] << " ";
        //cout << endl;
        cout << cnt << " " << cnt << endl;
        int cur  = 0;
        
    }
    return 0;
}