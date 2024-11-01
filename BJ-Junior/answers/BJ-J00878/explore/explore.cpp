#include<bits/stdc++.h>
using namespace std;
char map1[1002][1002];
int map2[1002][1002];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin >> T;
    while(T --){
        int n,m,k,x0,y0,d0;
        cin >> n >> m >> k >> x0 >> y0 >> d0;
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= m;j ++){
                map1[i][j] = 0;
                map2[i][j] = 0;
            }
        }
        int k1 = k;
        string s,emp;
        getline(cin,emp);
        for(int i = 1;i < n + 1;i ++){
            getline(cin,s);
            for(int j = 1;j < s.length() + 1;j ++) map1[i][j] = s[j - 1];
        }
        map2[x0][y0] = 1;
        for(int i = 0;i < k;i ++){
            int x_next,y_next,x_now,y_now;
            if(i == 0){
                x_next = x0;
                y_next = y0;
                x_now = x0;
                y_now = y0;
            }
            if(d0 == 0) y_next ++;
            else if(d0 == 1) x_next ++;
            else if(d0 == 2) y_next --;
            else x_next --;
            if(1 <= x_next && x_next <= n && 1 <= y_next && y_next <= m && map1[x_next][y_next] == '.'){
                map2[x_next][y_next] = 1;
                x_now = x_next;
                y_now = y_next;
            }else{
                x_next = x_now;
                y_next = y_now;
                d0 = (d0 + 1) % 4;
            }
        }
        int cnt = 0;
        for(int i = 1;i <= n;i ++) for(int j = 1;j <= m;j ++) if(map2[i][j] == 1) cnt ++;
        cout << cnt << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
