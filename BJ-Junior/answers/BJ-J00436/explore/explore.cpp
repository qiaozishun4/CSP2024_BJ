#include<iostream>
using namespace std;
char a[10005][10005];
int mark[10005][10005];
int n,m,num;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int tmp = 0;
    cin >> tmp;
    for(int i = 0;i < tmp;i++){
    cin >> n >> m >> num;
    int x,y,fang;
    cin >> x >> y >> fang;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    for(int i = 0;i < num;i++){
        if(fang == 0){
            if(a[x][y+1] == '.'){
                    //cout << x << y <<endl;
                y++;
                cnt++;
                //a[x][y] = 'l';
                //continue;
            }else{
                fang = (fang+1)%4;
                //continue;
            }
        }
        else if(fang == 1){
                //cout << x << y <<endl;
            if(a[x+1][y] == '.'){
                x++;
                cnt++;
                //a[x][y] = 'l';
                //continue;
            }else{
                fang = (fang+1)%4;
                //continue;
            }
        }
        else if(fang == 2){
            //cout << x << y <<endl;
            if(a[x][y-1] == '.'){
                y--;
                cnt++;
                //a[x][y] = 'l';
                //continue;
            }else{
                fang = (fang+1)%4;
                //continue;
            }
        }
        else if(fang == 3){
            //cout << x << y <<endl;
            if(a[x-1][y] == '.'){
                x--;
                cnt++;
                //a[x][y] = 'l';
                //continue;
            }else{
                fang = (fang+1)%4;
                //continue;
            }
        }
    }
    cout << cnt;
    cout << endl;
}
    return 0;
}

