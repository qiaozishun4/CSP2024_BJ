#include <iostream>

using namespace std ;

int main()
{
    freopen ("poker.in", "r", stdin) ;
    freopen ("poker.out", "w", stdout) ;

    int a ;
    cin >> a ;

    string c ;

    for (int i = 0 ; i < a ; i++)
        cin >> c ;

    cout << 52 - a << endl ;

    return 0 ;
}