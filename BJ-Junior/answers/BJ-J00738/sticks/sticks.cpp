#include<iostream>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T,n;
    cin >>T;
    for (int i = 0 ; i < T ; i ++){
        cin >> n;
        if (n >= 7){
            if ( n%7 == 0) { for (int i = 0 ; i < ((n)/7);i++)cout <<'8';}
            else if( n%7 == 1) {cout << '1'<<'0'  ;for (int i = 0 ; i < ((n-8)/7);i++)cout <<'8';}
            else if(n % 7 == 2){cout << '1' ;for (int i = 0 ; i < ((n-2)/7);i++)cout <<'8';}
            else if (n%7 == 3 ) {cout << '2'<<'3' ;for (int i = 0 ; i < ((n-10)/7);i++)cout <<'8';}
            else if (n%7 == 4) {cout << '2'<<'0' ;for (int i = 0 ; i < ((n-11)/7);i++)cout <<'8';}
            else if(n%7 == 5) {cout << '6'<<'0' ;for (int i = 0 ; i < ((n-12)/7);i++)cout <<'8';}
            else if (n%7 == 6) {cout << '1'<<'0'<<'2';for (int i = 0 ; i < ((n-13)/7);i++)cout <<'8';}
        }else{
            if (n<=1) cout <<-1;
            else if (n==2) cout <<1;
            else if (n==3) cout << 7;
            else if (n==4) cout <<4;
            else if (n==5) cout << 2;
            else if (n==6) cout <<6;
        }
        cout <<endl;
    }
    return 0;
}
