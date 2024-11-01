#include <iostream>
#include <cstdio>
#include <string>
#define ll long long
using namespace std;

int T,n,k,q;
int a[15][3000005];
int tmpc;

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&T);

    while(T--)
    {
        bool flag = 0;
        scanf("%d %d %d",&n,&k,&q);
        for(int i = 1;i <= n;i++)
        {
            int tmp;
            if(i == 1) tmpc = tmp;
            cin >> tmp;
            for(int j = 1;j <= tmp;i++)
                cin >> a[i][j];
        }
        for(int i = 1;i <= q;i++)
        {
            int r,c;
            cin >> r >> c;
            if(r == 1)
            {
                int left = 1,right = 1 + k;
                for(;right <= tmpc;right++,left++)
                {
                    if(left == 1 && right == c)
                    {
                        flag = 1;
                        break;
                    }
                }
            }
        }
        cout << flag << endl;
    }
    return 0;
}
