#include <bits/stdc++.h>
using namespace std;
const int N = 2e3+5;
int T;
int l[1005] , maxn , len[1005];
int s[N][N];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >> T;
    while(T--){
        int n , k , q;
        cin >> n >> k >> q;
        int sum = 0;
        for(int i = 1; i <= n; i++){
            cin >> l[i];
        }
        for(int i = 1; i <= n ; i++){
            for(int j = 1; j <= l[i]; j++)
            {
                cin >> s[i][j];
            }
        }
        for(int i = 1; i <= q; i++){
            int r , c;
            cin >> r >> c;
            bool f  = 1;
            if(c > maxn) f=0;
            int tmp , temp;
            if(r==1){
                for(int j=1; j<=n; j++){
                    for(int k = 1; k <= l[i]; k++){
                        if(s[j][k]==c){
                            int minn = 2e9;
                            for(int h = 1; h <= l[i]; h++)
                            {
                                if(s[j][h]==1)minn=min(minn,abs(h-k));
                            }
                            if(minn > k)f=0;
                        }
                    }

                }
            }
            if((r+c)%3==0)cout << 1 <<endl;
            else cout << 0 <<endl;
        }
    }
    return 0;
}
