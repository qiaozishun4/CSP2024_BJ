#include<cstdio>
#include<iostream>
using namespace std ;
bool a[1010][1010] , vis[1010][1010] ;
bool inmap(int x,int y,int n,int m){
    if(x < 1 || x > n || y < 1 || y > m){
        return false ;
    }
    return true ;
}
int f(){
    int n , m , k , x , y , d ;
    cin >> n >> m >> k >> x >> y >> d ;
    vis[x][y] = true ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            char z ;
            cin >> z ;
            if(z == 'x'){
                a[i][j] = false ;
            }else{
                a[i][j] = true ;
            }
            vis[i][j] = false ;
        }
    }
    for(int i = 0 ; i < k ; i++){
        vis[x][y] = true ;
        int nx = x , ny = y ;
        if(d == 0){
            ny += 1 ;
        }else if(d == 1){
            nx += 1 ;
        }else if(d == 2){
            ny -= 1 ;
        }else if(d == 3){
            nx -= 1 ;
        }
        if(inmap(nx,ny,n,m)){
            x = nx ;
            y = ny ;
            vis[x][y] = true ;
            //cout << "di" << i + 1 << "ci" << "x=" << x << "y=" << y << endl ;
        }else{
            d += 1 ;
            d = d % 4 ;
            //cout << "di" << i + 1 << "ci" << "d=" << d << endl ;
        }
    }
    int sum = 0 ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(vis[i][j]){
                sum++ ;
            }
            //cout << vis[i][j] << " " ;
        }
        //cout << endl ;
    }
    return sum ;
}
int main(){
    freopen("explore.in","r",stdin) ;
    freopen("explore.out","w",stdout) ;
    int t ;
    cin >> t ;
    for(int i = 0 ; i < t ; i++){
        cout << f() << endl ;
    }
    fclose(stdin) ;
    fclose(stdout) ;
}
/*
2
1 5 4
1 1 2
....x
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....
*/
