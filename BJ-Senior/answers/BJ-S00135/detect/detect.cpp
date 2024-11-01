//本来能写出来的，可惜时间不够了，后面的删除算法没时间写了呜呜呜
//不过T1AC了有分就能进NOIP了哈哈哈
//NOIP再见哈[鄙视]
#include <bits/stdc++.h>
using namespace std;

int n,m,L,V;

struct car
{
    int d;
    int v;
    int a;
    int above[2] = {-1,-1};
}car[100000];

double abovepos(int d,int v,int a)
{
    return (pow(V,2)-pow(v,2))/(2*a);
}

void cal()
{
    cin >> n >> m >> L >> V;
    int road[L];
    for(int i = 0; i <= L; i++)
        road[i] = i;
    for(int i = 0; i < n; i++)
        cin >> car[i].d >> car[i].v >> car[i].a;
    int detect[m];
    int cardetect[100000][m] = {{}};
    for(int i = 0; i < m; i++)
        cin >> detect[i];
    for(int i = 0; i < n; i++)
    {
        if(car[i].a == 0 && car[i].v > V)
        {
            car[i].above[0] = car[i].d;
            car[i].above[1] = L;
        }
        else if(car[i].a > 0)
        {
            int pos0 = ceil(abovepos(car[i].d,car[i].v,car[i].a))+car[i].d;
            if(pos0 < L)
            {
                car[i].above[0] = pos0;
                car[i].above[1] = L;
            }
        }
        else if(car[i].a < 0)
        {
            int pos0 = ceil(abovepos(car[i].d,car[i].v,car[i].a))+car[i].d;
            if(pos0 <= L)
            {
                car[i].above[0] = car[i].d;
                car[i].above[1] = pos0;
            }
            else
            {
                car[i].above[0] = car[i].d;
                car[i].above[1] = L;
            }
        }
    }
//    for(int i = 0; i < n; i++)
//        cout << car[i].d << ' ' << car[i].v << ' ' << car[i].a << endl << car[i].above[0] << ' ' << car[i].above[1] << endl << endl;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        int st = 0;
        if(car[i].a > 0)
        {
            for(int j = 0; j < m; j++)
            {
                if(detect[j]>car[i].above[0] && detect[j]<=car[i].above[1])
                {
                    if(detect[j]>=car[i].d)
                    {
                        cardetect[i][j] = detect[j];
                        st = 1;
                    }
                }
            }
        }
        else if(car[i].a < 0)
        {
            for(int j = 0; j < m; j++)
            {
                if(detect[j]>=car[i].above[0] && detect[j]<car[i].above[1])
                {
                    if(detect[j]>=car[i].d)
                    {
                        cardetect[i][j] = detect[j];
                        st = 1;
                    }
                }
            }
        }
        else if(car[i].a == 0 && car[i].v > V)
        {
            for(int j = 0; j < m; j++)
                if(detect[j]>=car[i].d)
                {
                    cardetect[i][j] = detect[j];
                    st = 1;
                }
        }
        if(st)
        {
            cnt++;
        }
    }
    cout << cnt << ' ';
    int de[m][n];
    int delcnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            de[j][i] = cardetect[i][j];
    for(int i = 0; i < m; i++)
    {
        int zero = 0;
        for(int j = 0; j < n; j++)
        {
            if(de[m][n] == 0)
            {
                zero++;
            }
        }
        if(zero == n)
            delcnt++;
    }
    cout << cnt;
}

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
        cal();

    fclose(stdin);
    fclose(stdout);
    return 0;
}


