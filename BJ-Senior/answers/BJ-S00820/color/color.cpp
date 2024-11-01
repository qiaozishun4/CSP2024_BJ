#include<bits/stdc++.h>

using namespace std;
long long n;
const int N = 2e5 + 10;
long long a[N];
long long col[N];
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    long long T;
    cin >> T;
    while(T -- )
    {
        cin >> n;
        long long r = 1 << n;
        r -- ;
        for(int i = 1; i <= n; i ++ )
        {
            cin >> a[i];
        }
        long long ans = 0;
        for(int i = 0; i <= r; i ++ )
        {
            long long mark = 0;
            for(int j = 1; j <= n; j ++ )
            {
                if(i >> (j - 1) & 1)
                {
                    col[j] = 1;
                }else col[j] = 0;
            }
            long long q1 = 0, q2 = 0;
            for(int j = 1; j <= n; j ++ )
            {
                if(col[j] == 0)
                {
                    if(q1 == 0)
                    {
                        q1 = j;
                    }else
                    {
                        if(a[q1] == a[j])
                        {
                            mark += a[j];
                        }
                        q1 = j;
                    }
                }else if(col[j] == 1)
                {
                    if(q2 == 0)
                    {
                        q2 = j;
                    }else
                    {
                        if(a[q2] == a[j])
                        {
                            mark += a[j];
                        }
                        q2 = j;
                    }
                }
            }
            ans = max(ans, mark);
        }
        cout << ans << endl;
    }

	return 0;
}
