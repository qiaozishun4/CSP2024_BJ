#include <bits/stdc++.h>
using namespace std;
bool cards[52];
int main(){
    //*####################################################################
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    //####################################################################*/
    int t,l;
    char s,p;
    cin >> t;
    while(t--){
        cin >> s >> p;
        l = 0;
        switch(s){
            case 'D':
                l++;
            case 'C':
                l++;
            case 'H':
                l++;
        }
        switch(p){
            case 'A':
                l+=4;
            case '2':
                l+=4;
            case '3':
                l+=4;
            case '4':
                l+=4;
            case '5':
                l+=4;
            case '6':
                l+=4;
            case '7':
                l+=4;
            case '8':
                l+=4;
            case '9':
                l+=4;
            case 'T':
                l+=4;
            case 'J':
                l+=4;
            case 'Q':
                l+=4;
        }
        cards[l]++;
    }
    int sum=0;
    for(int i = 0;i < 52;++i){
        sum += cards[i];
    }
    cout << 52 - sum;
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
