#include<bits/stdc++.h>
using namespace std;
long long a[60] = { -1 , 1 , 7 , 4 , 2 , 6 , 8 , 10 , 18 , 22 , 20 , 28 , 80 , 88 , 108 , 188 , 200 , 208 , 288 , 808 , 888 , 1088 , 1888 , 2008 , 2088 , 2888 , 8088 , 8888 , 10888 , 18888 , 20088 , 20888 , 28888 , 80888 , 88888 , 108888 , 188888 , 200888 , 208888 , 288888 , 808888 , 888888 , 1088888 , 1888888 , 2008888 , 2088888 , 2888888 , 8088888 , 8888888 , 10888888 };
int main()
{
    freopen( "sticks.in" , "r" , stdin );
    freopen( "sticks.out" , "w" , stdout );
    int t;
    cin >> t;
    while( t-- )
    {
        int n;
        cin >> n;
        if( n > 50 && n % 7 == 0 )
        {
            int x = n / 7;
            for( int i = 0; i < x; i++ )
            {
                cout << "8";
            }
            cout << endl;
        }
        else if( n <= 50 )
        {
            cout << a[n - 1] << endl;
        }
        else if( n > 50 && n % 7 == 1)
        {
            cout << "10";
            int x = n / 7;
            x--;
            for ( int i = 0; i < x; i++ )
            {
                cout << "8";
            }
            cout << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}
