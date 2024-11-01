#include<bits/stdc++.h>
using namespace std;
int a,b,c,x,y,d,e,wh;
char di;
int ran[1001][1001] = {0};
int fs (int xx,int yy,int d){
    if (e >= c){
        ran[xx][yy] =5;
        return;
    }
    if(d == 0 && ran[xx][yy+1] != 0 && ran[xx][yy+1] != 2){
        ran[xx][yy] = 5;
        yy +=1;
        e += 1;
        fs(xx,yy,d);
        return;
    }
    else if(d == 1 && ran[xx+1][yy] != 0 && ran[xx+1][yy] != 2){
        ran[xx][yy] = 5;
        xx +=1;
        e += 1;
        fs(xx,yy,d);
        return;
    }
    else if(d == 2 && ran[xx][yy-1] != 0 && ran[xx][yy-1] != 2){
        ran[xx][yy] = 5;
        yy -=1;
        e += 1;
        fs(xx,yy,d);
        return;
    }
    else if(d == 3 && ran[xx-1][yy] != 0 && ran[xx-1][yy] != 2){
        ran[xx][yx] = 5;
        xx -=1;
        e += 1;
        fs(xx,yy,d);
        return;
    }
    else{
        ran[xx][yy] = 5;
        e += 1;
        d = (d+1)%4;
        fs(xx,yy,d);
        return;
    }
}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>wh;
    for(int pm = 1;pm<=wh;pm++){
        e = 0;
        cin>>a>>b>>c;
        cin>>x,y,d;
        for(int i = 0;i<a;i++){
            for(int j = 0;j<b;j++){
                cin>>di;
                if(di == '.'){
                    ran[i][j] = 1;
                }
                if(di == 'x'){
                    ran[i][j] = 2;
                }
            }
        }
        fs(x,y,d);
        int qqq = 0;
        for(int i = 0;i<=a;i++){
            for(int j = 0;j<=b;i++){
                if(ran[i][j] == 5){
                    qqq +=1;
                }
            }
        }
        cout<<qqq<<endl;
    }
    return 0;
}