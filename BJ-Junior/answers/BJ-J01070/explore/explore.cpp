#include <bits/stdc++.h>

using namespace std;

struct nmk{
    int n,m,k;
};

int n,m,k;
    char ma[1100][1100];
struct p{
    int x,y,d;
};
int nowque;

int nexd(int n){
    return (n+1) % 4;
}

bool in_ma(int x,int y){
    if(x > 0 && y > 0 && x <= n && y <= m){
        return 1;
    }
    return 0;
}

p nexpos(int x,int y,int d){
    //cout << "xyd: " << x << ' ' << y << ' ' << d << '\n';
    //cout <<y+1 << ' ' << x+1 << ' ' << y-1 << ' ' <<x-1 << '\n';
    //cout << (char)ma[x][y+1] << ' ' << (char)ma[x+1][y] << ' ' <<'\n';
    if(d == 0){
        if(ma[x][y+1] == '.' &&in_ma(x,y+1)){
            return {x,y+1,d};
        }
            return {x,y,nexd(d)};
    }
    if(d == 1){
        if(ma[x+1][y] == '.' &&in_ma(x+1,y)){
            return {x+1,y,d};
        }
            return {x,y,nexd(d)};
    }
    if(d == 2){
        if(ma[x][y-1] == '.' &&in_ma(x,y-1)){
            return {x,y-1,d};
        }
            return {x,y,nexd(d)};
    }
    if(d == 3){
        if(ma[x-1][y] == '.' &&in_ma(x-1,y)){
            return {x-1,y,d};
        }
            return {x,y,nexd(d)};
    }

}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin >> T;
for(int Q = 1; Q <= T; Q++){
        //cout << Q << endl;

bool isvis[1100][1100];
memset(isvis,0,sizeof(isvis));
    cin >> n >> m >> k;
    int x,y,d;
    cin >> x >> y >> d;
        for(int l = 1; l<=n;l++){
            for(int c = 1; c <= m; c++){
                cin >> ma[l][c];
            }
        }
        for(int l = 1; l<=n;l++){
            for(int c = 1; c <= m; c++){
                //cout << ma[l][c];
            }
            //cout << '\n';
        }
    int nowx = x,nowy = y,nowd = d;
    for(int i = 1;  i<= k; i++){
        isvis[nowx][nowy] = 1;
        p tmp;
        tmp = nexpos(nowx,nowy,nowd);
        isvis[tmp.x][tmp.y] = 1;
        nowx = tmp.x;
        nowy = tmp.y;
        nowd = tmp.d;
        //cout << nowx <<' ' << nowy << ' ' << nowd << '\n';
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(isvis[i][j]) ans++;
        }
    }
    cout << ans << '\n';
}
    return 0;
}
