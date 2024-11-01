#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,ans;
char x,y;
bool cnt[5][14];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x>>y;
        if(x=='D'){
            a=1;
        }
        else if(x=='C'){
            a=2;
        }
        else if(x=='H'){
            a=3;
        }
        else if(x=='S'){
            a=4;
        }
        c=y-'0';
        if(c>=2&&c<=9){
            b=c;
        }
        else if(y=='A'){
            b=1;
        }
        else if(y=='T'){
            b=10;
        }
        else if(y=='J'){
            b=11;
        }
        else if(y=='Q'){
            b=12;
        }
        else if(y=='K'){
            b=13;
        }
        cnt[a][b]=1;
    }
    for(int i=1;i<=4;++i){
        for(int j=1;j<=13;++j){
            if(!cnt[i][j]) ++ans;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
