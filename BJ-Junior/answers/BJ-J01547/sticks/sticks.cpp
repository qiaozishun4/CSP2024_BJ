#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n;
int T;
int sti[11]={6 , 2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6};//0123456789
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >>T;
    while(T--)
    {
        cin >> n;
        if(n==1){
            cout << -1 <<endl;
            continue;
        }
        if(n==3){
            cout << 7 << endl;
            continue;
        }
        if(n == 10){
            cout << 23 << endl;
            continue;
        }
        if(n==4){
            cout << 4 << endl;
            continue;
        }
        if(n%7==0)
        {
            for(int i = 1; i <= n/7; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if(n%7==1)
        {
            cout << 10;
            for(int i = 1; i <= (n-8)/7; i++)cout << 8;
            cout << endl;
        }
        else if(n%7==2){
            cout <<1;
            for(int i  =1; i <= (n-2)/7; i++)cout << 8;
            cout << endl;
        }
        else if(n%7==3){
            cout << 200;
            for(int i = 1; i <= (n-17)/7; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if(n%7==4)
        {
            cout << 20;
            for(int i = 1; i <= (n-11)/7; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if(n%7==5)
        {
            cout << 2;
            for(int i = 1; i <= (n-12)/7; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if(n%7==6)
        {
            cout << 6;
            for(int i = 1; i <= (n-6)/7; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
    }
    return 0;
}

