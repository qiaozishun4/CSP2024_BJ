#include<bits/stdc++.h>
using namespace std;
int n, m, ac1[10005], ac2[10], T, q[10005], k=1, ck=1, a[10005], ans, ans2;
string s[10005];
int lt(string c, int sl, int xs[], int cs){
    int t, n[10005];
    for(int i=1;i<=sl;i+=2){
        if(c[(i+1)/2]=='0'){
            if(xs[i]>=cs) n[++t]=xs[i];
            else n[++t]=xs[i+1];
        }
        if(c[(i+1)/2]=='1'){
            if(xs[i+1]>=cs) n[++t]=xs[i+1];
            else n[++t]=xs[i];
        }
    }
}
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin >> n >>m;
    for(int i=1;i<=n;i++){
        cin >> ac1[i];
    }
    for(int i=1;i<=m;i++){
        cin >> q[i];
    }
    while(k<=n){
        k*=2;
        ck++;
    }
    k/=2;
    ck--;
    for(int i=1;i<=ck;i++){
        cin >> s[i];
    }
    cin >> T;
    while(T--){
        for(int i=0;i<4;i++){
            cin >> ac2[i];
        }
        for(int i=1;i<=n;i++){
            a[i]=ac1[i]^ac2[i%4];
        }
        for(int i=1;i<=m;i++){
            int k2=1;
            int ck2=1;
            while(k2<=q[i]){
                k2*=2;
                ck2++;
            }
            k2/=2;
            ck2--;
            ck2=ck-ck2+1;
            ans2=lt(s[ck2],ck2,a, 1);
            ans=ans^(i*ans2);
        }
        cout <<ans << endl;
    }
    return 0;
}
