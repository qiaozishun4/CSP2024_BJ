#include<bits/stdc+.h>
using namespace std;
int t,n,m,sum = 1,k,d,x,y;
char a[1000][1000];
bool dt(int x,int y,int n,int m){
    if(x < 0 || x > n){
        return 0;
    }
    if(y < 0 || y > m){
        return 0;
    }
    return 1;
}
int main(){
    feropen("explore.in","r",stdin);
    feropen("explore.out","w",stdout);
    cin>>t;
    for(int i = 0;i < t;i++){
        cin>>n>>m>>x;
        cin>>x>>y>>d;
        for(int i = 0;i < k;i++){
            if(d == 0){
                if(a[x][y+1] == '.' && dt(x,y+1,n,m)){
                    y++;
                    sum++;
                }else{
                    d = (d+1)%4;
                }
            }else if(d == 1){
                if(a[x+1][y] == '.' && dt(x+1,y,n,m){
                    x++;
                    sum++;
                }else{
                    d = (d+1)%4;
                }
            }else if(d == 2){
                if(a[x][y-1] == '.' && dt(x,y-1,n,m){
                    y--;
                    sum++;
                }else{
                    d = (d+1)%4;
                }
            }else{
                if(a[x-1][y] == '.' && dt(x-1,y,n,m){
                    x--;
                    sum++;
                }else{
                    d = (d+1)%4;
                }
            }
        }
    }
    cout<<sum;
    return 0;
}