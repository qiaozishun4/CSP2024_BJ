#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int q[5][14]={0};
int ans=0;
signed main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char a,b;
        cin>>a>>b;
        int A,B;
        if(a=='C'){
            A=1;
        }
        if(a=='S'){
            A=2;
        }
        if(a=='H'){
            A=3;
        }
        if(a=='D'){
            A=4;
        }
        if(b=='A'){
            B=1;
        }
        if(b=='J'){
            B=11;
        }
        if(b=='Q'){
            B=12;
        }
        if(b=='K'){
            B=13;
        }
        if(b=='2'){
            B=2;
        }
        if(b=='3'){
            B=3;
        }
        if(b=='4'){
            B=4;
        }
        if(b=='5'){
            B=5;
        }
        if(b=='6'){
            B=6;
        }
        if(b=='7'){
            B=7;
        }
        if(b=='8'){
            B=8;
        }
        if(b=='9'){
            B=9;
        }
        if(b=='T'){
            B=10;
        }
        q[A][B]=1;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(q[i][j]==0){
                ans++;
            }
        }
    }
    //for(int i=1;i<=4;i++){
        //for(int j=1;j<=13;j++){
          //  cout<<q[i][j]<<" ";
        //}
        //cout<<endl;
    //}
    cout<<ans;
    return 0;
}

