#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int a[100010];
bool v[100010],v2[100010];//used / been user used
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    /*
    for(int i=1;i<=n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    */
    int L=1,R=2;
    int ans=n;
    while(R<=n){
        if(v2[L]){
            L++;
            continue;
        }
        if(v[R]||v2[R]){
            R++;
            continue;
        }
        while(R<=n&&(a[L]>=a[R]||v[R]||v2[R])){
            R++;
        }
        if(R>n){
            break;
        }
        ans--;
        //cout << L << " " << R << endl;
        v2[L]=1;
        v[L]=1;
        v[R]=1;
        L++;
    }
    /*
    cout << L << " " << R << endl;
    for(int i=1;i<=n;i++){
        if(!v2[i]){
            cout << a[i] << " ";
        }
    }
    */
    cout << ans;
    return 0;
}
