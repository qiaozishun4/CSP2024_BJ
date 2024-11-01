#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

long long T;
int num[10] = {6,2,5,5,4,5,6,3,7,6};

long long all(long long x )
{
    long long ans =  0 ;
    while( x )
    {
        ans += num[x%10];
        x /= 10 ;
    }
    return ans ;

}

int main()
{
    freopen("sticks.in","r" , stdin );
    freopen("sticks.out","w" , stdout );
    cin >>T;
    while(T--)
    {
        long long n;
        cin >> n ;
        if(n < 2 )
        {
            cout <<-1 << "\n" ;
            continue;
        }
        if(n == 2 )
        {
            cout << 1 <<"\n";
            continue;
        }
        if( n % 7 == 0 )
        {
            for(int i = 1 ; i <= n / 7 ; i++)
                cout <<8;
            cout <<"\n";
            continue;
        }
        bool flag = false;
        for(long long i = pow(10,n/7-1) ; i <= pow(10,n/2+1); i++)
        {
            if( all(i) == n )
            {
                cout << i << "\n";
                flag = true;
                break;
            }
        }
        if(flag == false )cout <<-1 <<"\n";

    }



    return 0 ;
}
