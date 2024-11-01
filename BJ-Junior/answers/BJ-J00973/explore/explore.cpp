#include <iostream>
using namespace std;

void my_f(int n,int m,int k,int x,int y,int d,char a){
    int add;
    for(int i = 1;i <= k;i++){
        if(d == 0){
            x,y = x,y+1;
            if((y > n) or (y == 0)){
                d = (d+1)%4;
                y -= 1;
            }else add++;
        }else if(d == 1){
            x,y = x+1,y;
            if((x > m) or (x == 0)){
                d = (d+1)%4;
                x -= 1;
            }else add++;
        }else if(d == 2){
            x,y = x,y-1;
            if((y > n) or (y == 0)){
                d = (d+1)%4;
                y += 1;
            }else add++;
        }else{
            x,y = x-1,y;
            if((x > m) or (x == 0)){
                d = (d+1)%4;
                x += 1;
            }else add++;
        }
    }
    cout << add << endl;
}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,n,m,k,x,y,d;
    cin >> t;
    cin >> n >> m >> k;
    cin >> x >> y >> d;
    char a[n][m];
    for(int i = 1;i <= t;i++){
        for(int j = 0;j < n;j++){
            for(int k = 0;k < m;k++){
                cin >> a[n][m];
            }
        }
        my_f(n,m,k,x,y,d,a);
    }
    return 0;
}
