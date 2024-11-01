#include <bits/stdc++.h>

using namespace std;


struct Node
{
    int far;
    bool is_useful = false;
};

struct car
{
    int far , v , a;
};

bool cmp(Node x , Node y)
{
    return x.far < y.far;
}

car c[100005];
Node sawer[100005];

int main ()
{
    freopen("detect.in" , "r" , stdin);
    freopen("detect.out" , "w" , stdout);

    int t;
    cin >> t;

    while(t--){
    int n , m , L , V;
    cin >> n >> m >> L >> V;
    for(int i = 1;i<= n;i++)
    {
        cin >> c[i].far >> c[i].v >> c[i].a;
    }

    for(int j = 1;j<=m;j++)
    {
        cin >> sawer[j].far;
        sawer[j].is_useful = false;
    }

    sort(sawer+1 ,sawer + m , cmp);

    int ans = 0;
    for(int i = 1;i<=n;i++)
    {
        if(c[i].a == 0)
        {
            if(c[i].v > V)
            {
                ans++;
            }
        }
        if(c[i].a > 0)
        {
            bool flag = false;
            int temp = 0;
            for(int j = 1;j<=m;j++)
            {
                if(sawer[j].far < c[i].far)
                    continue;
                double s = sawer[j].far - c[i].far;
                double b = sqrt(c[i].v * c[i].v + c[i].a * 2*s);
                if(b > V)
                {
                    ans++;
                }
            }
        }

        if(c[i].a <0)
        {
            if(c[i].v < V)
                continue;
            bool flag  = false;
            for(int j = 1;j<=m;j++)
            {
                if(sawer[j].far < c[i].far)
                    continue;
                double s = sawer[j].far - c[i].far;
                double b = sqrt(c[i].v * c[i].v + c[i].a * 2*s);
                if(b > V)
                {
                    flag = true;
                }
                if(b <= V)
                {
                    break;
                }
            }
            if(flag)
            {
                ans++;
            }
        }
    }
    cout << ans << " " << m - 1 <<endl;
    }
    return 0;
}
