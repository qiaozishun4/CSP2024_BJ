#include <bits/stdc++.h>
#define N 114514
using namespace std;
int a[N], cnt;
vector <int> deshou;
int main()
{
    //freopen("arena1.in", "r", stdin);
    //freopen("arena.out", "w", stdout);
    //freopen("color.in", "r", stdin);
    //freopen("color.out", "w", stdout);
    //freopen("detect.in", "r", stdin);
    //freopen("detect.out", "w", stdout);
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        int x;
        cin >> x;
        a[x] ++;
    }
    //sort(a + 1, a + n + 1);
    for (int i = 0; i <= 114513;  i++)
    {
        if (a[i])
        {
            deshou.push_back(a[i]);
        }
    }
    cnt = deshou[0];
    for (int i = 1; i < deshou.size(); i ++)
    {
        if (cnt <= deshou[i])
        {
            cnt = deshou[i];
        }
        else
        {
            cnt = cnt;
        }
    }
    cout << cnt << endl;
    return 0;//我是李白，这就是唐诗。
}
//Finally U Can Know China Computer Federation.
