#include <bits/stdc++.h>
using namespace std;

inline int read()
{
    register int x = 0, f = 1;
    register char c = getchar();
    while(c > '9' || c < '0')
    {
        if(c == '-')f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

//16:08尝试思考一个n^2的dp
//16:13有了，记录前i个染色完成，最后一个与结尾不同色的位置，总共n^2种
//每次转移之前记录一下每个值在上一层的dp值max以及上一层所有的dp值max
//17:04拿下50pts
//17:10hey!!!!!观察dp式子，发现除了f[i][i-1]之外的是在a[i]==a[i-1]的时候进行区间加，f[i][i-1]是寻找之前的max
//还有就是之前a[i]=a[j]的要加
//应该是对每个a[i]维护
//啊啊啊啊好像是这么做的
//线段树维护区间加单点改区间最大值
//搞定！

int f[2010][2010], n, a[200010];//0表上一个是红，1表上一个是蓝

signed main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        memset(f, 0, sizeof(f));
        memset(a, 0, sizeof(a));
        cin >> n;
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i];
        }
        for(int i = 1;i <= n;i++)
        {
            for(int j = 0;j < i - 1;j++)
            {
                f[i][j] = f[i - 1][j] + (a[i] == a[i - 1] ? a[i] : 0);
            }
            for(int j = 0;j < i - 1;j++)
            {
                f[i][i - 1] = max(f[i - 1][j] + (a[i] == a[j] ? a[i] : 0), f[i][i - 1]);
            }
        }
        //for(int i = 1;i <= n;i++)
        //{
        //    cout << i << ": ";
        //    for(int j = 1;j < i;j++)
        //    {
        //        cout << f[i][j] << " ";
        //    }
        //    cout << "\n";
        //}
        //for(int i = 1;i <= n;i++)
        //{
        //    for(int j = 1;j < i;j++)
        //    {
        //        cout << maxx[i][j] << " ";
        //    }
        //    cout << "\n";
        //}
        int ans = 0;
        for(int i = 0;i < n;i++)
        {
            ans = max(ans, f[n][i]);
        }
        cout << ans << "\n";
    }
    return 0;
}