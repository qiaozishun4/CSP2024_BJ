#include <bits/stdc++.h>
using namespace std;
struct car
{
    int d , sp , a;
}ca[100010];
int c[100010];
int vis[100010];
int vi[100010];
int main()
{
    freopen("detect.in" , "r" , stdin);
    freopen("detect.out" , "w" , stdout);
    int T;
    cin >> T;
    while(T--)
    {
        //memset
        int n , m , L , V;
        cin >> n >> m >> L >> V;
        for(int i = 1 ; i <= n ; i ++)
        {
            //scanf("%d %d %d" , &ca[i].d , &ca[i].sp , ca[i].a);
            cin >> ca[i].d >> ca[i].sp >> ca[i].a;
        }
        for(int i = 1 ; i <= m ; i ++)
        {
            scanf("%d" , &c[i]);
        }
        if(n <= 20 && m <= 20)
        {
            int cnt = 0;
            for(int i = 1 ; i <= n ; i ++)
            {
                int v = ca[i].sp , l = ca[i].d , jia = ca[i].a;
                if(jia == 0)
                {
                    if(v > V && l <= c[m])
                    {
                        cnt ++;
                        for(int y = 1 ; y <= m ; y ++)
                        {
                            if(l <= c[y])
                            {
                                vis[i] ++;
                            }
                        }
                    }
                }
                else if(jia > 0)
                {
                    if(v > V && l <= c[m])
                    {
                        cnt ++;
                        for(int y = 1 ; y <= m ; y ++)
                        {
                            if(l <= c[y])
                            {
                                vis[i]++;
                            }
                        }
                        continue;
                    }
                    if(l > c[m])
                    {
                        continue;
                    }
                    double speed = 0;
                    speed = sqrt(v * 1.0 * v * 1.0 + 2.0 * jia * 1.0 * (c[m] * 1.0 - l * 1.0) *1.0);
                    if(speed > V)
                    {
                        cnt ++;
                        for(int y = 1 ; y <= m ; y ++)
                        {
                            if(l <= c[y])
                            {
                                vis[i]++;
                            }
                        }
                    }
                }
                else if(jia < 0){
                    if(v <= V)
                    {
                        continue;
                    }
                    int K = 0;
                    for(int j = 1 ; j <= m ; j ++)
                    {
                        if(c[j] >= l)
                        {
                            K = j;
                            break;
                        }
                    }
                    double speed = 0;
                    speed = sqrt(v * 1.0 * v * 1.0 + 2.0 * jia * 1.0 * (c[K] * 1.0 - l * 1.0) *1.0);
                    if(speed > V)
                    {
                        cnt ++;
                        for(int y = K ; y <= m ; y ++)
                        {
                            double speed2 = 0;
                            speed = sqrt(v * 1.0 * v * 1.0 + 2.0 * jia * 1.0 * (c[y] * 1.0 - l * 1.0) *1.0);
                            if(speed > V)
                            {
                                vis[y] ++;
                            }
                        }
                    }
                }
            }
            cout << cnt << " ";
            for(int i = 1 ; i <= m ; i ++)
            {
                if(vis[i] == n)
                {
                    cout << m-1;
                    break;
                }
            }
        }
        else{
            int cnt = 0;
            int isyun = 0 , isjia = 0 , isjian = 0;
            for(int i = 1 ; i <= n ; i ++)
            {
                int v = ca[i].sp , l = ca[i].d , jia = ca[i].a;
                if(jia == 0)
                {
                    isyun ++;
                    if(v > V && l <= c[m])
                    {
                        cnt ++;
                    }
                }
                else if(jia > 0)
                {
                    isjia ++;
                    if(v > V && l <= c[m])
                    {
                        cnt ++;
                        continue;
                    }
                    if(l > c[m])
                    {
                        continue;
                    }
                    double speed = 0;
                    speed = sqrt(v * 1.0 * v * 1.0 + 2.0 * jia * 1.0 * (c[m] * 1.0 - l * 1.0) *1.0);
                    if(speed > V)
                    {
                        cnt ++;
                    }
                }
                else if(jia < 0){
                    isjian++;
                    /*if(v <= V)
                    {
                        continue;
                    }
                    double S = 0;
                    S = (V * 1.0 * V - v * 1.0 * v) * 1.0 / (2.0 * jia * 1.0)* 1.0;
                    if(S < c[1])
                    {
                        continue;
                    }
                    for(int j = 1 ; j <= m ; j ++)
                    {
                        if(S >= c[j] && l <= c[m])
                        {
                            cnt ++;
                            break;
                        }
                    }*/
                    if(v <= V)
                    {
                        continue;
                    }
                    if(l > c[m])
                    {
                        continue;
                    }
                    int K = 0;
                    for(int j = 1 ; j <= m ; j ++)
                    {
                        if(c[j] >= l)
                        {
                            K = j;
                            break;
                        }
                    }
                    double speed = 0;
                    speed = sqrt(v * 1.0 * v * 1.0 + 2.0 * jia * 1.0 * (c[K] * 1.0 - l * 1.0) *1.0);
                    if(speed > V)
                    {
                        cnt ++;
                        vi[K]++;
                    }
                }
            }
            cout << cnt << " ";
            if( cnt != 0)
            {
                if(isyun == n)
                {
                    cout << m - 1 ;
                }
                if(isjia == n)
                {
                    cout << m - 1 ;
                }
                if(isjian == n)
                {
                    int sum = 0;
                    for(int u = 1 ; u <= m ; u ++)
                    {
                        sum += vi[u];
                    }
                    cout << sum;
                }
            }
            if(cnt == 0)
            {
                cout << m ;
            }
        }


        cout << endl;
        for(int i = 1 ; i <= n ; i ++)
        {
            ca[i].d = ca[i].sp = ca[i].a = 0;
        }
        for(int i = 1 ; i <= m ; i ++)
        {
            c[i] = 0;
        }
    }
    return 0;
}
