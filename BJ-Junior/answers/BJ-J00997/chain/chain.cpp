#include <bits/stdc++.h>
using namespace std;

char n[10010][20020];
int num, k, q,l;

int dg(int len, int start, int mo)
{
    if(len == -1)
        return 0;
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < 20010; j++)
        {
            if(n[i][j] == start)
            {
                for(int xx = j; xx < j+k+1; xx++)
                {
                    if(xx == mo && len == 0)
                        return 1;
                    if(dg(len-1,n[i][xx],mo) == 1)
                        return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);

    int t;
    cin >> t;

    for(int as = 0; as < t; as++)
    {
        num = 0;
        k = 0;
        q = 0;
        l = 0;
        cin >> num >> k >> q;
        for(int i = 0; i < num; i++)
        {
            cin >> l;
            for(int j = 0; j < l; j++)
            {
                cin >> n[i][j];
            }
        }
        int q1, q2;
        for(int cc = 0; cc < q; cc++)
        {
            cin >> q1 >> q2;
            cout << dg(q1,1,q2) << endl;
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
