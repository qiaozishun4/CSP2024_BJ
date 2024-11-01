#include <bits/stdc++.h>

using namespace std;
int n;
int T;
int mass = 0;
void ddd(int o,int s){
    if(o == 0){
        mass = min(mass,s);
    }
    if(o == 1) return;
    if(o >= 2)
    {
        ddd(o - 2,s * 10 + 1);
    }
    if(o >= 5)
    {
        ddd(o - 5,s * 10 + 2);
    }
    if(o >= 4)
    {
        ddd(o - 4,s * 10 + 4);
    }
    if(o >= 6)
    {
       ddd(o - 6,s * 10);
    }
    if(o >= 3)
    {
        ddd(o - 3,s * 10 + 7);
    }
    if(o >= 7)
    {
        ddd(o - 7,s * 10 + 8);
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >>T;
    while(T--){
        cin >>n;
        if(n == 1){
            cout << -1;
            cout <<endl;
        }else if(n % 7 == 0){
            n = n / 7;
            for(int i = 1;i <= n;i++) cout <<8;
            cout <<endl;
        }else if(n%7 == 1){
            n -= 1;
            n = n/ 7 - 1;
            cout << 10;
            for(int i = 1;i <= n;i++) cout <<8;
            cout <<endl;
        }else{

            mass = 10000000;
            if(n >= 2)
            {
                ddd(n - 2,1);
            }
            if(n >= 5)
            {
                ddd(n - 5,2);
            }
            if(n >= 4)
            {
                ddd(n - 4,4);
            }
            if(n >= 6)
            {
               ddd(n - 6,6);
            }
            if(n >= 3)
            {
                ddd(n - 3,7);
            }
            if(n >= 7)
            {
                ddd(n - 7,8);
            }
            cout << mass << endl;
        }


    }
    return 0;
}
