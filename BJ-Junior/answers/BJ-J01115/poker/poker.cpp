//hello world
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n = 0,cnt[5][15];
    char a,b;
    cin>>n;
    for(int i = 1;i <= 4;i++){
        for(int j = 1;j <= 15;j++){
            cnt[i][j] = 0;
        }
    }
    for(int i = 1;i <= n;i++){
        cin>>a>>b;
        if(a == 'D'){
            if(b == 'A'){cnt[1][1] = 1;}
            else if(b == 'T'){cnt[1][10] = 1;}
            else if(b == 'J'){cnt[1][11] = 1;}
            else if(b == 'Q'){cnt[1][12] = 1;}
            else if(b == 'K'){cnt[1][13] = 1;}
            else{cnt[1][int(b)-47] = 1;}
        }
        if(a == 'C'){
            if(b == 'A'){cnt[2][1] = 1;}
            else if(b == 'T'){cnt[2][10] = 1;}
            else if(b == 'J'){cnt[2][11] = 1;}
            else if(b == 'Q'){cnt[2][12] = 1;}
            else if(b == 'K'){cnt[2][13] = 1;}
            else{cnt[2][int(b)-47] = 1;}
        }
        if(a == 'H'){
            if(b == 'A'){cnt[3][1] = 1;}
            else if(b == 'T'){cnt[3][10] = 1;}
            else if(b == 'J'){cnt[3][11] = 1;}
            else if(b == 'Q'){cnt[3][12] = 1;}
            else if(b == 'K'){cnt[3][13] = 1;}
            else{cnt[3][int(b)-47] = 1;}
        }
        if(a == 'S'){
            if(b == 'A'){cnt[4][1] = 1;}
            else if(b == 'T'){cnt[4][10] = 1;}
            else if(b == 'J'){cnt[4][11] = 1;}
            else if(b == 'Q'){cnt[4][12] = 1;}
            else if(b == 'K'){cnt[4][13] = 1;}
            else{cnt[4][int(b)-47] = 1;}
        }
    }
    int ans = 0;
    for(int i = 1;i <= 4;i++){
        for(int j = 1;j <= 15;j++){
            ans += cnt[i][j];
            //cout<<cnt[i][j];
        }
        //cout<<endl;
    }
    cout<<52-ans<<endl;
    return 0;
}
