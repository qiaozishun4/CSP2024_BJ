#include<bits/stdc++.h>
using namespace std;
long long n,m,logn,a[100005],a2[100005],c[100005],ans[10005][100],tmp2[10005][105],ans2;
char tmp[100][10005];
int logg(int x){
    int logx = 0,x2 = x;
    while(x2 > 1){
        x2 /= 2;
        logx++;
    }
    if((1 << logx) != x){
        logx++;
    }
    return logx;
}
int winner(int l,int r){
    //cout << l << " " << r << '\n';
    if(l == r){
        return l;
    }
    long long tmpp = winner(l,(l + r) / 2),d = logg(r - l + 1);
    // << "\n" << tmpp << "   " << tmp[d][(l - 1) / (1 << d) + 1] << "  " << (a2[tmpp] >= d ? tmpp : winner((l + r) / 2 + 1,r)) << '\n';
    if(tmp[d][(l - 1) / (1 << d) + 1] == '0'){
        return (a2[tmpp] >= d ? tmpp : winner((l + r) / 2 + 1,r));
    }else{
        int tmpp2 = winner((l + r) / 2 + 1,r);
        return (a2[tmpp2] >= d ? tmpp2 : tmpp);
    }
}
int main(){
    freopen("arena3.in","r",stdin);
    freopen("arena3.out","w",stdout);
    cin >> n >> m;
    logn = logg(n);
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= m;i++){
        cin >> c[i];
    }
    for(int i = 1;i <= logn;i++){
        for(int j = 1;j <= (1 << (logn - i));j++){
            cin >> tmp[i][j];
        }
    }
    int t;
    cin >> t;
    while(t--){
        int x[5];
        for(int i = 0;i < 4;i++){
            cin >> x[i];
        }
        for(int i = 1;i <= n;i++){
            a2[i] = a[i] ^ x[i % 4];
        }
        ans2 = 0;
        for(int i = 1;i <= m;i++){
            int logc = logg(c[i]);
            for(int j = c[i] + 1;j <= (1 << logc);j++){
                a2[j] -= INT_MAX;
            }
            int tmpp[100005] = {0},cnt = winner(1,(1 << logc));
            tmpp[cnt] = 1;
            for(int j = c[i] + 1;j <= (1 << logc);j++){
                a2[j] += 2ll * INT_MAX;
                int winner2 = winner(1,(1 << logc));
                //cout << winner2 << " " << a2[4] << '\n';
                if(!tmpp[winner2]){
                    tmpp[winner2] = 1;
                    cnt += winner2;
                }
                //cout << " " << cnt << '\n';
                a2[j] -= 2ll * INT_MAX;
            }
            for(int j = c[i] + 1;j <= (1 << logc);j++){
                a2[j] += INT_MAX;
            }
            ans2 ^= cnt * i;
            //cout << cnt << "  #\n";
        }
        cout << ans2 << '\n';
    }
    return 0;
}
