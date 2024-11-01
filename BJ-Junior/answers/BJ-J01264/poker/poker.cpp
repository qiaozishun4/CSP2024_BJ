#include <bits/stdc++.h>
using namespace std;
int a[5][15];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n, t = 52;
    cin>>n;
    for (int i = 1;i<=n;i++){
        char r, s;
        int _r, _s;
        cin>>s>>r;
        switch(s){
            case 'D': _s = 1; break;
            case 'C': _s = 2; break;
            case 'H': _s = 3; break;
            case 'S': _s = 4; break;
        }
        switch(r){
            case 'A': _r = 1; break;
            case 'T': _r = 10; break;
            case 'J': _r = 11; break;
            case 'Q': _r = 12; break;
            case 'K': _r = 13; break;
            default: _r = r-'0';
        }
        t--;
        if (a[_s][_r]){
            t++;
        }
        a[_s][_r] = 1;
    }
    cout<<t;
    return 0;
}
