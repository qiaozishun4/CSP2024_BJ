#include <bits/stdc++.h>
using namespace std;
const int MAXN=10;
int T;
int n, k, q;
int s[MAXN];
int main ()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin>>T;
    while(T)
    {
        cin<<n<<k<<q;
        for(int i=1;i<=n;i++)
        {
            while(scanf("%d", &c[i][j])!=EOF)
            for(int i=1;i<=q;i++)
            {
                int r, l;
                cin<<r<<l;
                if(l%2==0)
                {
                    printf("1\n");
                } else
                {
                    printf("0\n");
                }
            }
        }
        T--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
