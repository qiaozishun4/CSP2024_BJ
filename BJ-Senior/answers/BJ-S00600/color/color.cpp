#include"bits/stdc++.h"
using namespace std;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        long long ans = 0;;
        int a[100010];
        int c[100010];
        for(int i = 0;i < 100010;i++)
            c[i] = 0;
        for(int i = 0;i < n;i++)
            cin >> a[i];
        for(int i = 0;i < n;i++)
        {
            for(int j = i+1;j < n;j++)
            {
                if(a[i] == a[j])
                {
                    bool f = 1;
                    for(int k = i;k <= j;k++)
                    {
                        if(c[k] == 2)
                        {
                            f = 0;
                            break;
                        }
                    }
                    if(f)
                    {
                        ans += a[i];
                        for(int k = i;k <= j;k++)
                            c[k]++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
