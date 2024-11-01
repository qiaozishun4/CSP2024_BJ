#include <bits/stdc++.h>
using namespace std;

int n;
int t;
int ans = 0;
int r_cnt = 0;
int b_cnt = 0;
int near_r = -1;
int near_b = -1;

struct group
{
    bool color;
    int v;
    int point;
};
struct group g[200005];

void cln()
{
    ans = 0;
    r_cnt = 0;
    b_cnt = 0;
    near_r = -1;
    near_b = -1;
    for (int i = 1 ; i <= n ; i++)
    {
        g[i].color == false;
        g[i].point == 0;
    }
}

int pt()
{
    int res = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
        if (i == 1)
        {
            g[i].point = 0;
            if(g[i].color == 1)
            {
                near_b = 1;
                b_cnt++;
            }
            else
            {
                near_r = 1;
                r_cnt++;
            }
        }
        else
        {
            if(g[i].color == 1)
            {
                if(near_b != -1)
                {
                   if(g[near_b].v == g[i].v)
                    {
                        g[i].point = g[i].v;
                    }
                    else
                    {
                        g[i].point = 0;
                    }
                }
                else
                {
                    g[i].point = 0;
                }

                b_cnt++;
                near_b = i;
                res += g[i].point;
            }
            else
            {
                if(near_r != -1)
                {
                   if(g[near_r].v == g[i].v)
                    {
                        g[i].point = g[i].v;
                    }
                    else
                    {
                        g[i].point = 0;
                    }
                }
                else
                {
                    g[i].point = 0;
                }

                r_cnt++;
                near_r = i;
                res+=g[i].point;
            }
        }
    }

    return res;

}

int f()
{
    cln();

    for (int i = 0 ; i <= ((1 << n) - 1) ; i ++)
    {
        for (int j = 1 ,cur = i ; cur != 0 ; j++,cur = cur >> 1)
        {
            g[j].color = bool(cur & 1);
            //cout << g[j].color;
        }
        //cout <<endl;
        ans = max(ans,pt());
    }

    return ans;
}

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);

    cin >> t;
    for(int i = 1 ; i <= t ; i ++)
    {
        cin >> n;
        if (n == 1)
        {
            cout << 0;
            break;
        }
        for (int i = 1 ; i <= n ; i ++)
        {
            cin >> g[i].v;
        }

        cout << f() << endl;
    }
    return 0;
}
