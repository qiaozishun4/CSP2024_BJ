#include <iostream>
using namespace std;
const int N=1e5+5;
int T;
int n,m,k;
int x0,y0,d0;
string a[N];
long long cnt[10];
bool b[1005][1005];
int main()
{
    cin >>T;
    int tmp=T;
    int h=0;
    while (T--){
        cnt[h]=1;
        cin >> n >> m>>k;
        cin >> x0 >>y0>>d0;
        int x=x0,y=y0,d=d0;
        for (int i=1; i<=n; i++){
            cin >> a[i];
        }
        for (int i=0; i<k; i++){
            int xt,yt;
            if(d==0){
            xt=x;
            yt=y+1;
            }
            else if (d==1){
                xt=x+1;
                yt=y;
            }
            else if (d==2){
                xt=x;
                yt=y-1;
            }
            else if (d==3){
                xt=x-1;
                yt=y;
            }
            if (xt>=1 && xt<=n){
                if (yt>=1 && yt<=m){
                    if (a[xt][yt-1]=='.'){
                            b[xt][yt]=1;
                            x=xt;
                            y=yt;
                    }
                    else d=(d+1)%4;
                }
                else d=(d+1)%4;
            }
            else d=(d+1)%4;

        }
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m;j++){
                if (b[i][j]==1) cnt[h]++;
            }
        }
        h++;

    }
    for (int i=0; i<tmp; i++){
        cout <<cnt[i]<<endl;
    }
    return 0;
}
