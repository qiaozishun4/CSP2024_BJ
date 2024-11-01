
#include <bits/stdc++.h>
using namespace std;
string s[1005];
long long cnt[1005][1005];
long long n,m,k;
long long x,y,d;
long long zhao(long long x, long long y , long long d){
    long long ans = 0;
    cnt[0][0]=1;
    for (long long i = 0; i < k; i++){
        long long xx = x,xy = y;
        if (d == 0){
            xy += 1;
        }
        if (d == 1){
            xx += 1;
        }
        if (d == 2){
            xy -= 1;
        }
        if (d == 3){
            xx -= 1;
        }
        if (s[xx][xy] == 'x' or !(xx < n and xx >= 0 and xy < m and xy >= 0)){
            d = (d+1)%4;
        }
        else{
            cnt[xx][xy]=1;
            x = xx;
            y = xy;
        }
    }
    for (long long i = 0; i < n; i++){
        for (long long j = 0; j < m; j++){
            if (cnt[i][j] >= 1){
                ans ++;
            }
        }
    }
    return ans;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    long long t;
    cin >>t;
    while ( t--){
        cin >> n >> m >> k >> x >>y >> d;
        for (long long i = 0; i < n; i++){
            cin >> s[i];
            for (long long j= 0; j < m; j++){
                cnt[i][j] = 0;
            }
        }
        x--;
        y--;
        cout << zhao(x,y,d) << "\n";
    }

    return 0;
}

