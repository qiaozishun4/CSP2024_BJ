#include <bits/stdc++.h>
using namespace std;
int main(){
    int T,n,m,k,x,y,d;
    int re=1;
    string arr;
    ifstream input("explore.in")
    ofstream output("explore.out")
    input>>T;
    for(int i=1;i<=T;i++){
        input>>n>>m>>k>>x>>y>>d;
        int add[n+2][m+2];
        for(int nm=0;nm<=n+2;nm++){
            for(int mn=0;mn<=m+2;mn++){
                add[nm][mn]=0;
            }
        }
        for(int j=1;j<=n;j++){
            input>>arr;
            for(int ab=1;sb<=m;sb++){
                if(arr[sb-1]=='.'){
                    add[j][sb]=1;
                }else{
                    add[j][sb]=0;
                }
            }
        }
        for(int bu=1;bu<=k;bu++){
            if(d==0){
                int ab=add[x][y+1];
                if(ab==1){
                    y++;
                    re++;
                }else{
                    d=(d+1)%4;
                }
            }else if(d==1){
                int ab=add[x+1][y];
                if(ab==1){
                    x++;
                    re++;
                }else{
                    d=(d+1)%4;
                }
            }else if(d==2){
                int ab=add[x][y-1];
                if(ab==1){
                    y--;
                    re++;
                }else{
                    d=(d+1)%4;
                }
            }else if(d==3){
                int ab=add[x-1][y];
                if(ab==1){
                    x--;
                    re++;
                }else{
                    d=(d+1)%4;
                }
            }
        }
        output<<re<<endl;
        re=0;
    }
    input.close();
    output.close();
}