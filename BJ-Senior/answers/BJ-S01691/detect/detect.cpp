#include <bits/stdc++.h>
using namespace std;
int t;
int n,m,l,v;
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> l >> v;
        int d1[100005]={0}, v1[100005]={0}, a1[100005]={0};
        for(int i=1; i<=n; i++)
        {
            cin >> d1[i] >> v1[i] >> a1[i];
        }
        int p[100005] = {0};
        for(int i=1; i<=m; i++)
        {
            cin >> p[i];
        }
        int num = 0;
        bool ans[100005] = {0};
        for(int i=1; i<=n; i++)
        {
            bool flag = false;
            for(int j=1; j<=m; j++)
            {
                if(p[j] >= d1[i])
                {
                    if(v < v1[i]+a1[i]*(p[j]-d1[i]))
                    {
                        num++;
                        break;
                    }
                }
            }
        }
        cout << num << " " << m-num+1 << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
