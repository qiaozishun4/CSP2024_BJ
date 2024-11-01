#include <bits/stdc++.h>

using namespace std;
int t[5][14];
int n,ans;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string a;
        cin>>a;
        char x=a[0];
        char y=a[1];
        int k=0;
        if(x=='D'){
            k=1;
        }
        else if(x=='C'){
            k=2;
        }
        else if(x=='H'){
            k=3;
        }
        else if(x=='S'){
            k=4;
        }

        if(y=='A'){
            t[k][1]=1;
            continue;
        }
        if(y=='T'){
            t[k][10]=1;
            continue;
        }
        if(y=='J'){
            t[k][11]=1;
            continue;
        }
        if(y=='Q'){
            t[k][12]=1;
            continue;
        }
        if(y=='K'){
            t[k][13]=1;
            continue;
        }
        else{
            t[k][y-'0']=1;
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(t[i][j]==0){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
