#include <iostream>

using namespace std;

int T;
int n, m, L, V;//分别表示车辆数量、测速仪数量、主干道长度和道路限速。
const int N = 1000005;
int d[N], v[N], a[N];//车的起点,速度,加速度
int p[N];//测速器
int close[N];
int cnt = 0;
int rm = 0;

int main()
{

    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    bool flag = true;
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> L >> V;

        for (int i = 0; i < n; i++)
        {
            cin >> d[i] >> v[i] >> a[i];
            if (a[i] != 0)
                flag = false;
        }

        for (int i = 0; i < m; i++)
        {
            cin >> p[i];
            close[i] = 1;
        }

        //特判车辆加速度为0的时候
        if (flag)
        {
            for (int i = 0; i < n; i++)
            {
                if (v[i] > V && d[i] <= p[m-1])
                {
                    cnt++;//超速车辆++逻辑正确


                    /*for (int j = 0; j < m; j++)
                    {
                        if (d[i] >= p[j])
                        {
                            close[j]--;
                            break;
                        }
                    }*/


                }
            }
            /*for(int i = 0; i < m; i++)
            {

                if (close[i] == 1)
                    rm++;
            }*/

            if (cnt == 0)
            {
                cout << cnt << " " << m << endl;
                continue;
            }
            cout << cnt << " " << m-1 << endl;
        }
        else
        {

            for (int i = 0; i < n; i++)
            {
                int currentSpeed = v[i];
                for (int j = 0; j < L - d[i]; j++)
                {
                    currentSpeed += a[j];

                    if(currentSpeed > V && d[0] + j == p[j])
                    {
                        cnt++;
                        close[j]--;
                    }
                }
            }
            for(int i = 0; i < m; i++)
            {
                if (close[i] == 1)
                    rm++;
            }

            cout << cnt << " " << rm;
        }

        cnt = 0;
        rm = 0;
    }
    return 0;
}
