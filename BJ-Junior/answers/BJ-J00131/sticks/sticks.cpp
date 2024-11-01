#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define REP(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mkp make_pair
#define ins insert
#define endl '\n'
using namespace std;
int T,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        if(n==1)cout<<-1;
        else if(n==2)putchar('1');
        else if(n==3)putchar('7');
        else if(n==4)putchar('4');
        else if(n==5)putchar('2');
        else if(n==6)putchar('6');
        else if(n%7==0){
            FOR(i,1,n/7)putchar('8');
        }
        else if(n%7==1){
            cout<<"10";
            FOR(i,1,(n-8)/7)putchar('8');
        }
        else if(n%7==2){
            putchar('1');
            FOR(i,1,(n-2)/7)putchar('8');
        }
        else if(n%7==3){
            cout<<"22";
            FOR(i,1,(n-10)/7)putchar('8');
        }
        else if(n%7==4){
            cout<<"20";
            FOR(i,1,(n-11)/7)putchar('8');
        }
        else if(n%7==5){
            cout<<"28";
            FOR(i,1,(n-12)/7)putchar('8');
        }
        else if(n%7==6){
            putchar('6');
            FOR(i,1,(n-6)/7)putchar('8');
        }
        cout<<endl;
    }
    return 0;
}
/*
luogu uid=923403
XD
*/
