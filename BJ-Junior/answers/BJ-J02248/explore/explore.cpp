#include<iostream>
#include<string>
#include<math.h>
#define int long long
using namespace std;
int t,d[10],startx[10],starty[10];
char arr[1010][1010];
int fx[4] = {0,1,0,-1},fy[4] = {1,0,-1,0};
int m[10],n[10],k[10],ans[10];
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i = 1;i <= t;i++){
        cin>>n[i]>>m[i]>>k[i];
        cin>>startx[i]>>starty[i]>>d[i];
        for(int j = 1;j <= n[i];j++){
            for(int c = 1;c <= m[i];c++){
                cin>>arr[j][c];
            }
        }
        if((d[i] == 0 && arr[startx[i]][starty[i] + 1] == '.') || (d[i] == 1 && arr[startx[i] + 1][starty[i]] == '.')){
            ans[i] = 2;
        }
        else if((d[i] == 2 && arr[startx[i]][starty[i] - 1] == '.') || (d[i] == 3 && arr[startx[i] - 1][starty[i]] == '.')){
            ans[i] = 2;
        }
        else{
            ans[i] = 1;
        }
    }

    for(int i = 1;i <= t;i++) cout<<ans[i]<<"\n";
    return 0;
}