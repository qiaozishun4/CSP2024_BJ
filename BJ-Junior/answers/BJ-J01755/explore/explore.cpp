#include<bits/stdc++.h>
using namespace std;
int t;
int n,m;
int k;
int x,y;
int vis[1005][1005]= {0};
char a[1005][1005];
int d;
int is_valid(int xx,int yy){
    if(xx > n||xx < 1 ||yy > m ||yy < 1){
        return false;
    }
    if(a[xx][yy] == 'x'){
        return false;
    }
    if(vis[x][y]){
        return false;
    }
    return true;
}
int kis1(){
    if(d == 0){
        if(is_valid(x,y+1)){
            return 2;
        }else{
            return 1;
        }
    }
    if(d == 1){
        if(is_valid(x+1,y)){
            return 2;
        }else{
            return 1;
        }
    }
    if(d == 2){
        if(is_valid(x,y-1)){
            return 2;
        }else{
            return 1;
        }
    }
    if(d == 3){
        if(is_valid(x-1,y)){
            return 2;
        }else{
            return 1;
        }
    }
}
int go(){
    int cnt = 0;
    for(int i = 1;i <= k;i++){
        if(is_valid(x,y)){
            cnt++;
        }
        vis[x][y] = 1;
        if(d == 0){
            y +=1;
            if(!is_valid(x,y)){
                y-=1;
                d=(d+1)%4;
            }
            continue;
        }
        if(d == 1){
            x +=1;
            if(!is_valid(x,y)){
                x-=1;
                d=(d+1)%4;
            }
            continue;
        }
        if(d == 2){
            y-=1;
            if(!is_valid(x,y)){
                y+=1;
                d=(d+1)%4;
            }
            continue;
        }
        if(d == 3){
            x-=1;
            if(!is_valid(x,y)){
                x+=1;
                d=(d+1)%4;
            }
            continue;
        }
    }
    return cnt;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    for(int i = 1;i <= t;i++){
        cin >> n >> m;
        cin >> k;
        cin >>x >> y;
        cin >> d;
        cout << n <<' ' << m;
        cout << ' ' << k;
        cout << endl << x << y;
        cout << d;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                cin >> a[i][j];
            }
        }
        if(k == 1){
            cout << kis1() <<endl;
            return 0;
        }
        cout << go() <<endl;
    }
    return 0;
}
