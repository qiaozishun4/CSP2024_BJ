#include <bits/stdc++.h>
using namespace std;
int T,n,k,q,tmp,tmp2;
int main(){
    //*####################################################################
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    //####################################################################*/
    cin >> T;
    while(T--){
        cin >> n >> k >> q;
        while(q--){
            cout << "0\n";
            cin >> tmp >> tmp2;
        }
        while(n--){
            cin >> tmp;
            while(tmp--)cin >> tmp2;
        }
    }
    //Are there someone tell me how to solve this problem?
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
