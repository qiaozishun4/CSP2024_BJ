#include<iostream>
#include<cstdio>
using namespace std;

int T;
long long n , k , q ;
long long s[10005][10005];
int l[100005];
bool check( long long r , long long c , long long step, long long last )
{
    if(step == r )
    {
        for(int i = 1 ; i <= n ; i++ )
        {
            if(s[i][1] == s[last][l[last]] && last != i && s[i][l[i]] == c )
            {
                return true;
            }
        }
        return false;

    }
    for( int i = 1 ; i <= n ; i++ )
    {
        if( s[i][1] == s[last][l[last] ]&& last != i )
        {
            check( r , c , step +1 , i );
        }

    }
}


int main()
{
    freopen( "chain.in" , "r" , stdin );
    freopen( "chain.out" , "w" , stdout);
    cin >> T;
    while( T-- )
    {
        cin >>n >>k >>q ;
        if( k == 2 *1e5 )
        {
            for( int i = 1 ; i <= n ; i++ )
            {
                cin >>l[i] ;
                for(int j = 1 ; j <= l[i] ; j++)
                {
                    cin >>s[i][j];
                }
            }
            for( int i = 1 ; i <= q ; i++)
            {

                int r , c ;
                cin >>r >>c ;
                if(check(r,c,1,1))cout <<1 << "\n";
                else cout <<0<<"\n";

            }
            continue;
        }
        for( int i = 1 ; i <= n ; i++ )
        {
            long long l;
            cin >>l[i] ;
            for(int j = 1 ; j <= l ; j++)
            {
                int x ;
                cin >> x ;
            }
        }
        for( int i = 1 ; i <= q ; i++)
        {
            cout << 0 << endl;
        }
    }




    return 0 ;
}