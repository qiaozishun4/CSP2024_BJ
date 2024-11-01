#include <iostream>

#define maxn 1000007

using namespace std;

int n , mx , t[maxn];

int main()
{
    freopen( "duel.in" , "r" , stdin );
    freopen( "duel.out" , "w" , stdout );
    cin >> n;
    for( int i = 1 ; i <= n ; ++i ) {
        int tmp; cin >> tmp; t[tmp] ++;
    }
    for( int i = 1 ; i <= 100000 ; ++i ) mx = max( mx , t[i] );
    cout << mx;
    return 0;
}
