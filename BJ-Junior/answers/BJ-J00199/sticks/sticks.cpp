#include<cstdio>
#include<iostream>
using namespace std ;
int s[] = {6,2,5,5,4,5,6,3,7,6} ;
int f(int n){
    int sum = 0 ;
    while(n){
        sum += s[n % 10] ;
        n /= 10 ;
    }
    return sum ;
}
int main(){
    freopen("sticks.in","r",stdin) ;
    freopen("sticks.out","w",stdout) ;
    int t ;
    cin >> t ;
    for(int k = 0 ; k < t ; k++){
        int n ;
        cin >> n ;
        bool flag = false ;
        for(int i = 0 ; i <= n * 100; i++){
            if(f(i) == n){
                cout << i << endl ;
                flag = true ;
                i += n * 100 ;
            }
        }
        if(!flag){
            cout << -1 << endl ;
        }
    }

    /*
    int x ;
    cin >> x ;
    cout << f(x) ;
    */
    fclose(stdin) ;
    fclose(stdout) ;
}
