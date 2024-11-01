#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#define fin freopen("sticks.in","r",stdin);
#define fout freopen("sticks.out","w",stdout);
using namespace std;
const int stick[15]={6,2,5,5,4,5,6,3,7,6};
int tests,n;
void put8(int x)
{
    while(x--)
        putchar('8');
    putchar('\n');
}
int main()
{
    fin
    fout
    cin >> tests;
    while(tests--)
    {
        cin >> n;
        if(n%7==0)
            put8(n/7);
        else if(n%7==1)
        {
            if(n==1)
                cout << "-1\n";
            else
            {
                cout << "10";
                put8(n/7-1);
            }
        }
        else if(n%7==2)
        {
            cout << "1";
            put8(n/7);
        }
        else if(n%7==3)
        {
            if(n==3)
                cout << "7\n";
            else if(n==10)
                cout << "22\n";
            else
            {
                cout << "200";
                put8(n/7-2);
            }
        }
        else if(n%7==4)
        {
            if(n==4)
                cout << "4\n";
            else
            {
                cout << "20";
                put8(n/7-1);
            }
        }
        else if(n%7==5)
        {
            cout << "2";
            put8(n/7);
        }
        else
        {
            cout << "6";
            put8(n/7);
        }
    }
	return 0;
}
