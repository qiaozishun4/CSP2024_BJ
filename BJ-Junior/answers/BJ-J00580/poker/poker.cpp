#include<bits/stdc++.h>
using namespace std;
string ss = "A23456789TJQK";
int a[53];
int main()
{
    freopen( "poker.in" , "r" , stdin );
    freopen( "poker.out" , "w" , stdout );
    int n;
    cin >> n;
    string s;
    while( n-- )
    {
        cin >> s;
        if( s[0] == 'D' )
        {
            for( int i = 0; i < 13; i++ )
            {
                if( s[1] == ss[i] )
                {
                    a[i]++;
                    break;
                }
            }
        }
        else if( s[0] == 'C' )
        {
            for( int i = 0; i < 13; i++ )
            {
                if( s[1] == ss[i] )
                {
                    a[i + 13]++;
                    break;
                }
            }
        }
        else if( s[0] == 'H' )
        {
            for( int i = 0; i < 13; i++ )
            {
                if( s[1] == ss[i] )
                {
                    a[i + 26]++;
                    break;
                }
            }
        }
        else if( s[0] == 'S' )
        {
            for( int i = 0; i < 13; i++ )
            {
                if( s[1] == ss[i] )
                {
                    a[i + 39]++;
                    break;
                }
            }
        }
    }
    int ans = 0;
    for( int i = 0; i < 52; i++ )
    {
        if( a[i] == 0 )
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
