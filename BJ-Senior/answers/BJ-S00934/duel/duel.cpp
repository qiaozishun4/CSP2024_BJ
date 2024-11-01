#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
int num[100005];
int a[100005];
int b[100005];
int m;
int ans;

signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> num[i];
    }
    sort(num+1,num+1+n);
    for(int i = 1;i <= n;i++){
        if(num[i] != num[i-1]){
            m++;
        }
        a[m]++;
        b[m]++;
    }
    ans = n;
    int j = 1;
    for(int i = 2;i <= m;i++){
        while(i > j && b[i] >= a[j]){
            ans -= a[j];
            b[i] -= a[j];
            a[j] = 0;
            j++;
        }
        if(i > j){
            a[j] -= b[i];
            ans -= b[i];
            b[i] = 0;
        }
    }
    cout << ans;
}
