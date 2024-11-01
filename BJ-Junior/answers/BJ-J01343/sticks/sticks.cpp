#include <bits/stdc++.h>
using namespace std;
int t,n,dig,extra;
int main(){
    //*####################################################################
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    //####################################################################*/
    cin >> t;
    while(t--){
        cin >> n;
        if(n<=7||n==10){
            switch(n){
            case 1:
                cout << -1;
                break;
            case 2:
                cout << 1;
                break;
            case 3:
                cout << 7;
                break;
            case 4:
                cout << 4;
                break;
            case 5:
                cout << 2;
                break;
            case 6:
                cout << 6;
                break;
            case 7:
                cout << 8;
                break;
            case 10:
                cout << 22;
                break;
            }
        }else{
            dig = (n-1)/7+1;
            extra = (n-1)%7+1;
            switch(extra){
            case 1:
                cout << 10;
                for(int i = 2;i < dig;++i)cout << 8;
                break;
            case 2:
                cout << 1;
                for(int i = 1;i < dig;++i)cout << 8;
                break;
            case 3:
                cout << 200;
                for(int i = 3;i < dig;++i)cout << 8;
                break;
            case 4:
                cout << 20;
                for(int i = 2;i < dig;++i)cout << 8;
                break;
            case 5:
                cout << 2;
                for(int i = 1;i < dig;++i)cout << 8;
                break;
            case 6:
                cout << 6;
                for(int i = 1;i < dig;++i)cout << 8;
                break;
            case 7:
                for(int i = 0;i < dig;++i)cout << 8;
                break;
            }
        }
        cout << endl;
    }
    return 0;
}

/*
1  IIIII     -- A    K   K     A   U   U       CCC   SSS  PPPP            J
2    I        ---A   K  K     A A  U   U      C   C S   S P   P           J
3    I        A---A  K K     A   A U   U      C     S     P   P           J
4    I        AAA--- KK      AAAAA U   U      C      SSS  PPPP  -----     J
5    I        A   A----K     A   A U   U      C         S P               J
6    I        A   A -----    A   A U   U      C   C S   S P           J   J
7  IIIII      A   A  K ----  A   A  UUU        CCC   SSS  P            JJJ
*/
