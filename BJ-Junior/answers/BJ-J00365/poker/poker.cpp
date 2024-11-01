#include <bits/stdc++.h>
using namespace std;
bool d[14], c[14], h[14], s[14];
void func( char ct, char t )
{
    if( ct == 'D' )
    {
        if( t == 'T' )
            d[10] = true;
        else if( t == 'J' )
            d[11] = true;
        else if( t == 'Q' )
            d[12] = true;
        else if( t == 'K' )
            d[13] = true;
        else
            d[t-'0'] = true;
    }
    if( ct == 'C' )
    {
        if( t == 'T' )
            c[10] = true;
        else if( t == 'J' )
            c[11] = true;
        else if( t == 'Q' )
            c[12] = true;
        else if( t == 'K' )
            c[13] = true;
        else
            c[t-'0'] = true;
    }
    if( ct == 'H' )
    {
        if( t == 'T' )
            h[10] = true;
        else if( t == 'J' )
            h[11] = true;
        else if( t == 'Q' )
            h[12] = true;
        else if( t == 'K' )
            h[13] = true;
        else
            h[t-'0'] = true;
    }
    if( ct == 'S' )
    {
        if( t == 'T' )
            s[10] = true;
        else if( t == 'J' )
            s[11] = true;
        else if( t == 'Q' )
            s[12] = true;
        else if( t == 'K' )
            s[13] = true;
        else
            s[t-'0'] = true;
    }
}
int main()
{
    freopen( "poker.in", "r", stdin );
    freopen( "poker.out", "w", stdout );
    memset( d, false, sizeof(bool)*13 );
    memset( c, false, sizeof(bool)*13 );
    memset( h, false, sizeof(bool)*13 );
    memset( s, false, sizeof(bool)*13 );
    string st;
    int n, i, cnt = 0;
    cin >> n;
    for( i = 0; i < n; i++ )
    {
        cin >> st;
        if( st[1] == 'A' )
            st[1] = '1';
        func(st[0], st[1]);
    }
    for( i = 1; i < 14; i++ )
    {
        if( !d[i] )
            cnt++;
        if( !c[i] )
             cnt++;
         if( !h[i] )
             cnt++;
        if( !s[i] )
            cnt++;
    }
    cout << cnt << endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
