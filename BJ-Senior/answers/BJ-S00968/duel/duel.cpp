#include <bits/stdc++.h>

using namespace std;
int n,a[666666];
int mie,beimie;
bool ok = false;
int main()
{
    ios::sync_with_stdio();
    cin.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    int ans = n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    /*for(int i = 1;i <= n;i++){
        cout << a[i] << " ";
    }*/
    //cout << endl;
    beimie = 1;
    mie = upper_bound(a+1,a+n+1,a[beimie]) - a;
    for(int i = 1;i <= n;i++){
        /*cout << mie << endl;
        cout << beimie << endl;
        cout << ans << endl;
        cout << endl;*/
        if(mie > n){
            cout << ans;
            return 0;
        }
        ans--;
        if(!(a[i + 1] - a[beimie] != 0)){
            mie++;
            //cout << "meibian" << endl;
        }
        else{
            mie = upper_bound(a+1,a+n+1,a[i+1]) - a;
            beimie = i + 1;
            //cout << "bian" << endl;
        }
    }
    return 0;
}
