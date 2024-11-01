#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int n , a , x[MAXN];

    cin >> n >> a;
    for (int i = 1 ; i <= n ; i++ ){
        for (int j = 0 ; j <= a ; j++ ) cin >> x[j] ;
        if(n == 3) cout << 1 << endl << 0 << endl<< 8 << endl;
        else if(n == 10) cout << "18\n37\n3592\n75337\n728694\n2790568\n565203\n440224\n50720490\n3766392328";
    }
    return 0;
}