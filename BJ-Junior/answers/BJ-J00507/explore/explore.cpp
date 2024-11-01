#include<bits/stdc++.h>
using namespace std;
bool biao[1001][1001];
char tu[1001][1001];
int bx[]={0,1,0,-1};
int by[]={1,0,-1,0};
int a,b,c;
void dfs(int x,int y,int d){
    biao[x][y]=1;
    if(c<=0) return ;
    int _x,_y;
    _x=x+bx[d];
    _y=y+by[d];
    c--;
    if(_x>0 && _x<=a && _y>0 && _y<=b && tu[_x][_y]=='.'){
        dfs(_x,_y,d);
    }
    else {
        dfs(x,y,(d+1)%4);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin >> T;
    for(int I=1;I<=T;I++){
        cin >> a >> b >> c;
        int x,y,d;
        cin >> x >> y >> d;
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                biao[i][j]=0;
                cin >> tu[i][j];
            }
        }
        dfs(x,y,d);
        int da=0;
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                if(biao[i][j]==1) da++;
            }
        }
        cout << da << "\n";
    }
    return 0;
}
