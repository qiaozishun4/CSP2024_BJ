#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> a[i];
    sort(a+1,a+n+1);
    int num,ans = 0,maxn = -1;
    for(int i = 1;i <= n;i++){
        if(a[i] != num){
            maxn = max(maxn,ans);
            ans = 1;
            num = a[i];
        }
        else {
            ans++;
        }
    }
    maxn = max(ans,maxn);
    cout << maxn << endl;
    return 0;
}