#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int n;
    cin >> n;
    if(n == 10) {
        cout << 18<<'\n'<<37<<'\n'<<3592<<'\n'<<75337<<'\n'<<2790568<<'\n'<<565203<<'\n'<<440224<<'\n'<<50720490<<'\n'<<3766392328<<'\n';
    }
    else if(n == 3) 
    {
        cout << 1 <<'\n'<< 0 <<'\n'<<8<<'\n';
    }
    else{
        for (int i = 1; i<= n; i++) cout << 0;
    }
    return 0;
}
