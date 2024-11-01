#include <iostream>
#include <cstdio>
using namespace std;
long long num[200010],best[2010][2010][2];//0 red_last,1 blue_last

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    long long T;
    cin>>T;
    for (long long Q = 1;Q <= T;Q++){
        for (long long i = 1;i <= 2005;i++){
            for (long long j = 1;j <= 2005;j++){
                best[i][j][0] = 0;best[i][j][1] = 0;
            }
        }
        long long n;
        cin>>n;
        for (long long i = 1;i <= n;i++){
            cin>>num[i];
        }
        for (long long i = 2;i <= n;i++){
            //i-red
            for (long long j = 1;j <= i-1;j++){
                if (num[j] == num[i]){
                    best[i][i-1][0] = max(best[i][i-1][0],best[i-1][j][1] + num[i]);
                }
                else{
                    best[i][i-1][0] = max(best[i][i-1][0],best[i-1][j][1]);
                }
            }
            for (long long j = 1;j <= i-1;j++){
                if (num[i-1] == num[i]){
                    best[i][j][0] = max(best[i][j][0],best[i-1][j][0] + num[i]);
                }
                else{
                    best[i][j][0] = max(best[i][j][0],best[i-1][j][0]);
                }
            }

            //i-blue
            for (long long j = 1;j <= i-1;j++){
                if (num[j] == num[i]){
                    best[i][i-1][1] = max(best[i][i-1][1],best[i-1][j][0] + num[i]);
                }
                else{
                    best[i][i-1][1] = max(best[i][i-1][1],best[i-1][j][0]);
                }
            }
            for (long long j = 1;j <= i-1;j++){
                if (num[i-1] == num[i]){
                    best[i][j][1] = max(best[i][j][1],best[i-1][j][1] + num[i]);
                }
                else{
                    best[i][j][1] = max(best[i][j][1],best[i-1][j][1]);
                }
            }
        }
        long long maxn = 0;
        for (long long i = 1;i <= n-1;i++){
            maxn = max(maxn,max(best[n][i][0],best[n][i][1]));
        }
        cout<<maxn<<endl;
    }

    return 0;
}
