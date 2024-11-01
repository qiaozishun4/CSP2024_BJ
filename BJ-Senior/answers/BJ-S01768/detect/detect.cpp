#include <bits/stdc++.h>
using namespace std;
int t;
struct Car
{
    long long d,v,a;
    long long ov = 0,ov1 = 0;
}car[100005];
struct Y
{
    queue<int> vec;
    int p;
}y[100005];
int re[100005];
bool cmp(Y xx,Y yy)
{
    if(xx.vec.size() != yy.vec.size()) return xx.vec.size() > yy.vec.size();
    return xx.p < yy.p;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> t;
    while(t--)
    {
        memset(re,0,sizeof(re));
        int n,m,L;
        long long V;
        cin >> n >> m >> L >> V;
        V *= V;
        for(int i = 1;i <= n;i++)
        {
            cin >> car[i].d >> car[i].v >> car[i].a;
            if(car[i].a > 0)
            {
                car[i].ov = V - car[i].v * car[i].v;
                car[i].ov = floor(car[i].ov / (2 * car[i].a));
                car[i].ov += car[i].d;
            }
            else if(car[i].a == 0)
            {
                car[i].ov = L + 1;
            }
            else
            {
                car[i].ov1 = V - car[i].v * car[i].v;
                double x = car[i].ov1 / (2 * car[i].a);
                car[i].ov1 = floor(car[i].ov1 / (2 * car[i].a));
                if(x - car[i].ov1 >= 0) car[i].ov1++;
                car[i].ov1 += car[i].d;
            }
        }
        int ans1 = 0,ans2 = 0;
        for(int i = 1;i <= m;i++)
        {
            cin >> y[i].p;
            for(int j = 1;j <= n;j++)
            {
                if(y[i].p > car[j].ov && car[j].ov)
                {
                    y[i].vec.push(j);
                    if(!re[j])
                    {
                        ans1++;
                        re[j] = 1;
                    }
                }
                else if(y[i].p < car[j].ov1 && car[j].ov1 && y[i].p >= car[j].d)
                {
                    y[i].vec.push(j);
                    if(!re[j])
                    {
                        ans1++;
                        re[j] = 1;
                    }
                }
            }
        }
        sort(y + 1,y + 1 + m,cmp);
        cout << ans1 << " ";
        memset(re,0,sizeof(re));
        for(int i = 1;i <= m;i++)
        {
            if(y[i].vec.empty())
            {
                ans2++;
                continue;
            }
            int flag = 0;
            while(!y[i].vec.empty())
            {
                int num = y[i].vec.front();
                y[i].vec.pop();
                if(!re[num])
                {
                    re[num] = 1;
                    flag = 1;
                }
            }
            if(!flag) ans2++;
        }
        cout << ans2 << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
