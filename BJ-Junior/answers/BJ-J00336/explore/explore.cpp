#include <bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int x,y,d;
char a[1100][1100];
int pos[10];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    int g=0;
    int res=t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        while(k!=0){
            if(d==0){
                if(a[x][y+1]=='x'){
                    d=(d+1)%4;
                    k--;
                }else{
                    pos[g]++;
                    y++;
                    k--;
                }
            }
            if(d==1){
                if(a[x+1][y]=='x'){
                    d=(d+1)%4;
                    k--;
                }else{
                    pos[g]++;
                    x++;
                    k--;
                }
            }
            if(d==2){
                if(a[x][y-1]=='x'){
                    d=(d+1)%4;
                    k--;
                }else{
                    pos[g]++;
                    y--;
                    k--;
                }
            }
            if(d==3){
                if(a[x-1][y]=='x'){
                    d=0;
                    k--;
                }else{
                    pos[g]++;
                    x--;
                    k--;
                }
            }
        }
        g++;
    }
    for(int i=0;i<res;i++) cout<<pos[i]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}