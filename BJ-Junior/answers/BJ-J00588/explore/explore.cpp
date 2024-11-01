#include <bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d,nx,ny;
int endda = 1;
bool dt[1050][1050] = {0};
bool cdk[1050][1050] = {0};
int outda[6] = {0}, das=0;
int main(){
freopen("explore.in","r",stdin);
freopen("explore.out","w",stdout);
cin >>T ;
for(int i = 0;i <T;i++){
    string omgtoohard;
    cin >> n >> m >> k;
    cin >> x >> y >> d;

    for(int e = 1;e <= n;e++){
        cin >> omgtoohard;
        for(int o = 0;o < m;o++){
             if(omgtoohard[o] == 'x'){
               dt[e][o+1] = 1;}
        }
    }
 for(int e = 0;e < k;e++){
    switch (d){
    case 0:
    nx = x;
    ny = y+1;
    break;
    case 1:
    nx = x+1;
    ny = y;
    break;
    case 2:
    nx = x;
    ny = y-1;
    break;
    case 3:
    nx = x-1;
    ny = y;
    break;
    }
    if(1 <= nx&&nx <= n&&1 <= ny&&ny <= m&&dt[nx][ny]==0 ){
      //      cout << "xy:" << nx <<" "<<ny << " can" <<endl << "nowshuchu " << endda << endl;

        x=nx;y=ny;
        if(cdk[x][y] == 0){endda++;cdk[x][y]=1;}}
    else{
        d = (d+1)%4;
        continue;
    }

 }
outda[das]=endda;
das++;
endda = 1;
    for(int e = 1;e <= n;e++){
            for(int o = 1;o <= m;o++){
                dt[e][o] = 0;
                cdk[e][o] = 0;
            }
        }
    }



for(int i = 0;i < das;i++)
    cout << outda[i] << endl;

return 0;
}
