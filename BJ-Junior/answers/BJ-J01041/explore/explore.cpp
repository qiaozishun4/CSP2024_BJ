#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k,x,y,d;
char s[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;

    while(t--){
        int sum = 0;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> s[i][j];
            }
        }
        while(k--){
            d %= 4;
            //ans++;
            if(d == 0){
                if(s[x][y+1] == 'x') {
                    d++;
                }
                else if(y+1 >= m) {
                    d++;
                }
                else {
                    y++;
                    sum++;
                }
            }else if(d == 1){
                if(s[x+1][y] == 'x') {
                    d++;
                }
                else if(x+1 >= n) {
                    d++;
                }
                else {
                    x++;
                    sum++;
                }
            }else if(d == 2){
                if(s[x][y-1] == 'x') {
                    d++;
                }
                else if(y-1 <= m) {
                    d++;
                }
                else {
                    y--;
                    sum++;
                }
            }else {
                if(s[x-1][y] == 'x') {
                    d++;
                }
                else if(x-1 <= n) {
                    d++;
                }
                else {
                    x--;
                    sum++;
                }
            }
        }
        cout << sum + 1 << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
