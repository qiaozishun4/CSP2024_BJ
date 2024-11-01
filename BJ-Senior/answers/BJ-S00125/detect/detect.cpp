#include<bits/stdc++.h>
using namespace std;

struct NA
{
    int a1, v1, d1;
};
NA f[1000002];


int main()
{
    freopen("detect.in", "r",stdin);
    freopen("detect.out", "w", stdout);
    int o, maxn = -1;
    int t[1001001];
    cin >> o;
    for(int i = 1;i<=o;i++)
    {
        int n, m, l, v, cnt = 0, g, p=1,maxb = -1;
        cin >>n >> m >> l >> v;
      //  printf("%d \n \n\n\n\n%d %d %d %d\n", i,n, m, l, v);
        for(int j = 1;j<= n;j++)
        {
            int a, b, c;
            cin >> a >>b >>c;
            f[j].d1 = a;f[j].v1 = b; f[j].a1 = c;
        }
        for(int j = 1;j<=m;j++)
        {

            cin >> t[i];
        }
        for(int j = 1;j<=n;j++)
        {


            if(t[i] > maxb)
            {
                maxb = t[i];
            }
        }
      //  cout <<maxb  <<"weqwe" <<endl;
        for(int j = 1;j<=n;j++)
        {

            if(f[j].d1 <= maxb && f[j].v1>v)
            {
                cnt++;f[j].a1 = -1;
            }

        }
        if(cnt == 0)
        {
            cout <<0 << ' ' << m << "\n";
        }
        else{
             cout <<cnt << ' ' << m-p << "\n";
        }



    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
