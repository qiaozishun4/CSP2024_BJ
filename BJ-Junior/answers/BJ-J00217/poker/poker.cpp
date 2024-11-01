#include<bits/stdc++.h>
using namespace std;
bool poker[4][13];
int main(){
    int n,xd,yd,ans=0;
    char x,y;
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        getchar();
        x=getchar();
        y=getchar();
        if(x=='C'){
            xd=0;
        }
        else if(x=='S'){
            xd=1;
        }
        else if(x=='H'){
            xd=2;
        }
        else if(x=='D'){
            xd=3;
        }
        if(y=='A'){
            yd=0;
        }
        else if(y=='T'){
            yd=9;
        }
        else if(y=='J'){
            yd=10;
        }
        else if(y=='Q'){
            yd=11;
        }
        else if(y=='K'){
            yd=12;
        }
        else {
            yd=y-'0'-1;
        }
        poker[xd][yd]=true;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            if(!poker[i][j]){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
