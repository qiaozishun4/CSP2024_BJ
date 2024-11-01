#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    char a[2];
    int p[5][14]={0},ans=0,x,y;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(a[0]=='D'){
            x=1;
        }else if(a[0]=='C'){
            x=2;
        }else if(a[0]=='H'){
            x=3;
        }else if(a[0]=='S'){
            x=4;
        }
        if(a[1]>='2'&&a[1]<='9'){
            y=(int)(a[1]-'0');
        }else if(a[1]=='A'){
            y=1;
        }else if(a[1]=='T'){
            y=10;
        }else if(a[1]=='J'){
            y=11;
        }else if(a[1]=='Q'){
            y=12;
        }else if(a[1]=='K'){
            y=13;
        }
        p[x][y]++;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(p[i][j]==0){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
