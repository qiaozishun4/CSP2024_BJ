#include<bits/stdc++.h>
using namespace std;
char s[1005][1005];
int n,m;
bool emptyhere(int x,int y){
    if(x <= n && x >= 1 && y <= m && y >= 1 && s[x][y] != 'x'){
        return true;
    }
    return false;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T,k,x,y,d,ans;
    cin >> T;
    while(T --){
        ans = 0;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= m;j ++){
                cin >> s[i][j];
            }
        }
        for(int i = 1;i <= k;i ++){
            s[x][y] = 'y';
            if(d == 0){
                if(emptyhere(x,y + 1) == true){
                    y ++;
                }else{
                    d = (d + 1) % 4;
                }
            }
            else if(d == 1){
                if(emptyhere(x + 1,y) == true){
                    x ++;
                }else{
                    d = (d + 1) % 4;
                }
            }
            else if(d == 2){
                if(emptyhere(x,y - 1) == true){
                    y --;
                }else{
                    d = (d + 1) % 4;
                }
            }
            else if(d == 3){
                if(emptyhere(x - 1,y) == true){
                    x --;
                }else{
                    d = (d + 1) % 4;
                }
            }
        }
        s[x][y] = 'y';
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= m;j ++){
                if(s[i][j] == 'y'){
                    ans ++;
                }
            }
        }
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}