#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int n, cnt, ans;
int a[N], b[N], c[N];//b = alive, c = attackable
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf(" %d",&n);
    ans = n;
    for(int i = 1; i <= n; i++){
        scanf(" %d",&a[i]);
    }
    sort(a+1, a+n+1);
    cnt = 1;
    b[1] = 1;
    c[1] = 1;
    for(int i = 2; i <= n; i++){
        if(a[i] == a[i - 1]) b[cnt]++, c[cnt] = b[cnt];
        else b[++cnt]++, c[cnt] = b[cnt];
    }
    if(cnt == 1) printf("%d\n",n);
    else if(cnt == 2) printf("%d\n",n - min(b[1], b[2]));
    else{
        if(b[cnt] >= (n + 1) / 2) printf("%d\n",2 * b[cnt] - n);
        else{
            int l = 1, r = 2;
            while(l <= r && r <= cnt){
                if(c[r] > b[l]){
                    ans -= b[l];
                    c[r] -= b[l];
                    l++;
                    r += (l == r);
                }
                else if(c[r] < b[l]){
                    ans -= c[r];
                    b[l] -= c[r];
                    c[r] = 0;
                    r++;
                }
                else if(l != r && c[r] == b[l]){
                    ans -= b[l];
                    c[r] = 0;
                    b[l] = 0;
                    l++;
                    r++;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
