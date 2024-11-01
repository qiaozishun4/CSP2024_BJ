#include<bits/stdc++.h>
using namespace std;
#define maxn 10005
int t,n,a[maxn],red,blue,mt[maxn];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        int maxt = (1 << n);
        red = 0;
        blue = 0;
        mt[0] = -1;
        long long res = 0;
        for(int i = 1;i <= maxt;i++){
            mt[i] = mt[i - 1] + 1;
            long long sum = 0;
            for(int j = n;j >= 0;j--){
                bool tmp = mt[i] & (1 << j);
                //cout << tmp << " ";
                if(tmp){
                    if(a[red] == a[tmp]){
                        sum += tmp;
                        //cout << red << endl;
                    }
                    red = tmp;
                }
                else{
                    if(a[blue] == a[tmp]){
                            //cout << blue << endl;
                        sum += tmp;
                    }
                    blue = tmp;
                }
            }
            //cout << endl;
            res = max(sum,res);
        }
        cout << res << endl;
    }
    return 0;
}
