#include <bits/stdc++.h>
using namespace std;
bool p[13][4];
int n;
void getcard(char a,char b){
    int f=0;
    if(a=='D'){
        f=0;
    }
    if(a=='C'){
        f=1;
    }
    if(a=='H'){
        f=2;
    }
    if(a=='S'){
        f=3;
    }
    int s=0;
    if(b=='A'){
        s=0;
    }else{
        if(b=='T')s=9;
        else if(b=='J')s=10;
        else if(b=='Q')s=11;
        else if(b=='K')s=12;
        else s=b-'1';
    }
    p[s][f]=true;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        char x,y;
        cin>>x>>y;
        getcard(x,y);
    }
    int ans=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            if(!p[i][j])ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}