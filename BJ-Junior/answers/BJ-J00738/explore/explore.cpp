#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T,n,m,k,x0,y0,d0,d,x,y;
    cin >> T;
    for (int i = 0 ; i < T ; i ++){
        cin >> n >>m >>k;
        cin >> x0 >> y0 >>d0;
        int x_list[1000000]={},y_list[1000000] = {} ;
        char map[n][m]={};
        for (int j = 1 ; j <=n ; j ++){
            for (int h= 1 ; h<=m ; h++){
                cin >>map[j][h];
            }
        }
        x = x0;
        y = y0;
        d = d0;
        int count = 0;
        int c2 = 0;
        x_list[count] = x;
        y_list[count] = y;
        count ++ ;
        for (int g = 0 ; g < k ; g ++){
            if (d==0){
                if(1<=x && x<=n && y+1 <=m && y+1>=1 && map[x][y+1] == '.'){
                    y += 1;
                    for (int o = 0 ; o <= count ; o ++ ){
                        if (x_list[o] == x&&y_list[o] == y) c2 ++;
                    }
                    if (c2 == 0){
                        count ++ ;
                        x_list[count] = x;
                        y_list[count] = y;
                    }
                }else{
                    d = (d+1) % 4;
                }
            }
           else if (d==1){
                if(1<=x+1&&x+1<=n&&y <=m && y>=1 && map[x+1][y]=='.'){
                    x += 1;
                    for (int o = 0 ; o <= count ; o ++ ){
                        if (x_list[o] == x&&y_list[o] == y) c2 ++;
                    }
                    if (c2 == 0){
                        count ++ ;
                        x_list[count] = x;
                        y_list[count] = y;
                    }
                }else{
                    d = (d+1) % 4;
                }
            }
            else if (d==2){
                if(1<=x && x<=n && y-1 <=m && y-1>=1 && map[x][y-1] == '.'){
                    y -= 1;
                    for (int o = 0 ; o <= count ; o ++ ){
                        if (x_list[o] == x&&y_list[o] == y) c2 ++;
                    }
                    if (c2 == 0){
                        count ++ ;
                        x_list[count] = x;
                        y_list[count] = y;
                    }
                }else{
                    d = (d+1) % 4;
                }
            }
            else if (d==3){
                if(1<=x-1&&x-1<=n&&y <=m && y>=1 && map[x-1][y]=='.'){
                    x -= 1;
                    for (int o = 0 ; o <= count ; o ++ ){
                        if (x_list[o] == x&&y_list[o] == y) c2 ++;
                    }
                    if (c2 == 0){
                        count ++ ;
                        x_list[count] = x;
                        y_list[count] = y;
                    }
                }else{
                    d = (d+1) % 4;
                }
            }

            }
            cout << count<<endl;
        }
        return 0;
    }