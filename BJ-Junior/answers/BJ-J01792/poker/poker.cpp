#include<bits/stdc++.h>
using namespace std;
bool p[15][5];
void in(char c,int num){
    if(c=='D'){
        p[num][1]=1;
    }
    if(c=='C'){
        p[num][2]=1;
    }
    if(c=='H'){
        p[num][3]=1;
    }
    if(c=='S'){
        p[num][4]=1;
    }
}
int main(){
    int n,ans=0;
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string a;
        cin>>a;
        if(a[1]=='A'){
            in(a[0],1);
        }
        else if(a[1]=='T'){
            in(a[0],10);
        }
        else if(a[1]=='J'){
            in(a[0],11);
        }
        else if(a[1]=='Q'){
            in(a[0],12);
        }
        else if(a[1]=='K'){
            in(a[0],13);
        }
        else{
            in(a[0],a[1]-'0');
        }
    }
    for(int i=1;i<=13;i++){
        for(int j=1;j<=4;j++){
            if(p[i][j]==0){
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
