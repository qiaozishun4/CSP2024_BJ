#include <bits/stdc++.h>
using namespace std;
int t,n,m,k;
long long robx,roby,sum=0;
int robd;
long long a[1145][1145];
char thing[1145][1145];
int step;
bool movement(long long xx,long long yy,int dire){
    step--;
    a[xx][yy]=1;
    if (dire == 0 && yy+1 <= m){
        if (thing[xx][yy+1] != '.' and a[xx][yy+1] == 0){
            step--;
            dire = (dire+1)%4;
        }
        else{
            roby++;
            a[xx][yy+1] = 1;
            return 1;//East
        }
    }
    if (dire == 1 and xx+1 <= n){
        if (thing[xx+1][yy] != '.' && a[xx+1][yy] == 0){
            step--;
            dire = (dire+1)%4;
        }
        else{
            robx++;
            a[xx+1][yy] = 1;
            return 1;//South
        }
    }
    if (dire == 2 and yy-1 >= 1){
        if (thing[xx][yy-1] != '.' && a[xx][yy-1] == 0){
            step--;
            dire = (dire+1)%4;
        }
        else{
            roby--;
            a[xx][yy-1] = 1;
            return 1;//West
        }
    }
    if (dire == 3 and xx-1 >= 1){
        if (thing[xx-1][yy] != '.' and a[xx-1][yy] == 0){
            step--;
            dire = (dire+1)%4;
        }
        else{
            robx--;
            a[xx-1][yy] = 1;
            return 1;//North
        }
    }
    if (dire == 0 && yy+1 <= m){
        if (thing[xx][yy+1] != '.' and a[xx][yy+1] == 0){
            step--;
            dire = (dire+1)%4;
        }
        else{
            roby++;
            a[xx][yy+1] = 1;
            return 1;//East
        }
    }
    if (dire == 0 and yy+1 <= m){
        if (thing[xx][yy+1] != '.'){
            step--;
            dire = (dire+1)%4;
        }
        else{
            roby++;
            a[xx][yy+1] = 1;
            return 1;//East
        }
    }
    if (dire == 1 and xx+1 <= n){
        if (thing[xx+1][yy] != '.'){
            step--;
            dire = (dire+1)%4;
        }
        else{
            robx++;
            a[xx+1][yy] = 1;
            return 1;//South
        }
    }
    if (dire == 2 and yy-1 >= 1){
        if (thing[xx][yy-1] != '.'){
            step--;
            dire = (dire+1)%4;
        }
        else{
            roby--;
            a[xx][yy-1] = 1;
            return 1;//West
        }
    }
    if (dire == 3 and xx-1 >= 1){
        if (thing[xx-1][yy] != '.'){
            step--;
            dire = (dire+1)%4;
        }
        else{
            robx--;
            a[xx-1][yy] = 1;
            return 1;//North
        }
    }
    if (dire == 0 and yy+1 <= m){
        if (thing[xx][yy+1] != '.'){
            step--;
            dire = (dire+1)%4;
        }
        else{
            roby++;
            a[xx][yy+1] = 1;
            return 1;//East
        }
    }
    return 0; //无路可走
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    while(t--){
        for (int i = 1;i<=n;i++){
            for (int j = 1;j<=m;j++){
                a[i][j]=0;
            }
        }
        cin >> n >> m >> k;
        cin >> robx >> roby >> robd;
        for (int i = 1;i<=n;i++){
            for (int j = 1;j<=m;j++){
                cin >> thing[i][j];
            }
        }
        step = k;
        for (int i = 1;i<=step;){
            bool flag = movement(robx,roby,robd);
            if (flag == 0){
                a[robx][roby]=1;
                sum++;
            }
        }
        for (int i = 1;i<=n;i++){
            for (int j = 1;j<=m;j++){
                if (a[i][j] == 1){
                    sum++;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}
