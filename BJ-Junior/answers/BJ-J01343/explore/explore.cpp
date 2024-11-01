#include <iostream>
using namespace std;
int T,n,m,k,x,y,d,sum;
char map[1002][1002];
bool try_to_move(){
    switch(d){
    case 0:
        if(map[x][y+1]=='.'||map[x][y+1]=='!'){
            ++y;
            return true;
        }else{
            return false;
        }
    case 1:
        if(map[x+1][y]=='.'||map[x+1][y]=='!'){
            ++x;
            return true;
        }else{
            return false;
        }
    case 2:
        if(map[x][y-1]=='.'||map[x][y-1]=='!'){
            --y;
            return true;
        }else{
            return false;
        }
    case 3:
        if(map[x-1][y]=='.'||map[x-1][y]=='!'){
            --x;
            return true;
        }else{
            return false;
        }
    }
}
int main(){
    //*####################################################################
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    //####################################################################*/
    cin >> T;
    while(T--){
        sum = 1;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j){
                cin >> map[i][j];
            }
        }
        map[x][y] = '!';
        while(k--){
            if(try_to_move()){
                if(map[x][y] == '.'){
                    map[x][y] = '!';
                    ++sum;
                }
            }else{
                d = (d+1)%4;
            }
        }
        cout << sum << endl;
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
