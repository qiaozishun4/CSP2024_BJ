#include <bits/stdc++.h>
using namespace  std;
int T;
int n , m;
int a[100005] , a_[100005] , c[100005];
string s[100];
int x[4];
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin >> n >> m;
    for(int i  =1; i <= n; i++)
    {
        cin >> a_[i];
    }
    for(int i = 1; i <= m; i++) cin >> c[i];
    int cur = 0;
    int tmp = n;
    while(tmp > 0){
        cin >> s[++cur];
        tmp/=2;
    }
    cin >> T;
    while(T--){
        for(int i = 0; i <= 3; i++)cin >> x[i];
        for(int i = 1; i <= n; i++)
        {
            a[i]=a_[i]^(x[i%4]);
        }
        int mul = 0;
        for(int i = 1; i <= m; i++)
        {
            int maxn = 0;
            for(int j = 1; j <= c[i]; j++)
            {
                maxn  =max(maxn , a[i]);
            }
            int sum = 0;
            for(int j = 1; j <= c[i]; j++)
            {
                if(a[i]==maxn)sum+=i;
            }
            mul^=sum+1;
        }
        cout << mul <<endl;
        memset(x,0,sizeof(x));
    }
    return 0;
}



