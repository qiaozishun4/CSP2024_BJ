#include<bits/stdc++.h>
using namespace std;

const int MAX_ = 1e3+20;
int T;

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        int n,m,k,ans=0;
        char map[MAX_][MAX_]; // FIRST N, Second M;
        int botX,botY,botD;

        cin>>n>>m>>k;
        cin>> botX >> botY >> botD;
        
        // input map
        for(int x=1;x<=n;x++){
            for(int y=1;y<=m;y++){
                char t;
                cin>>t;
                map[x][y] = t;
            }
        }
        map[botX][botY] = '*';
        // k times operations
        while(k--){
            int tryX = botX, tryY = botY; 
            // try to move part
            if(botD==0){
                tryY++;
            }
            else if(botD==1){
                tryX++;
            }
            else if(botD==2){
                tryY--;
            }
            else if(botD==3){
                tryX--;
            }
            // check part
            bool checkX = tryX>=1 && tryX<=n;
            bool checkY = tryY>=1 && tryY<=m;
            if(checkX && checkY && map[tryX][tryY]!='x'){
                botX = tryX;
                botY = tryY;
            }else{
                botD = (botD+1) % 4;
            }
            map[botX][botY] = '*';
        }

        // finding answer part
        for(int x=1;x<=n;x++){
            for(int y=1;y<=m;y++){
                if(map[x][y]=='*'){
                    ans++;
                }
            }
        }
        cout<< ans <<endl;
    } 
    fclose(stdin);
    fclose(stdout);
    return 0;
}