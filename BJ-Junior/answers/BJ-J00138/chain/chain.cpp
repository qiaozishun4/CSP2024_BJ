#include <bits/stdc++.h>
using namespace std;
int a[10010][20010];
int main()
{
    freopen("chain.in" , "r" , stdin);
    freopen("chain.out" , "w" , stdout);
	int T;
	cin >> T;
	while(T--)
    {
        int n , k , q;
        cin >> n >> k >> q;
        for(int i = 1 ; i <= n ; i ++)
        {
            int l;
            scanf("%d" , &l);
            a[i][0] = l;
            for(int j = 1 ; j <= l ; j ++)
            {
                scanf("%d" , &a[i][j]);
            }
        }
        for(int k = 1 ; k <= q ; k ++)
        {
            int r , c;
            cin >> r >> c;
            bool is = false;
            for(int i = 1 ; i <= n ; i ++)
            {
                for(int j = 1 ; j <= a[i][0] ; j ++)
                {
                    if(a[i][j] == c)
                    {
                        is = true;
                        break;
                    }
                }
                if(is)
                {
                    break;
                }
            }
            if(is)
            {
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
    }
	return 0;
}
