#include<iostream>
#include<cstdio>
#include<set>
#define N 52
using namespace std ;
int main(){
    freopen("poker.in","r",stdin) ;
    freopen("poker.out","w",stdout) ;
    set <string> s ;
    int n ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        string x ;
        cin >> x ;
        s.insert(x) ;
    }
    int ans = N - s.size() ;
    cout << ans ;
    fclose(stdin) ;
    fclose(stdout) ;
    return 0 ;
}
