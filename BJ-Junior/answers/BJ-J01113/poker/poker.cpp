#include<bits/stdc++.h>
using namespace std;
int n,ans,a[10][100];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        char x=s[0],y=s[1];
        int d;
        if(y<'2'||y>'9'){
            if(y=='A')d=1;
            else if(y=='T')d=10;
            else if(y=='J')d=11;
            else if(y=='Q')d=12;
            else if(y=='K')d=13;
        }else{
            d=int(y-'0');
        }
        if(x=='D')a[1][d]++;
        else if(x=='C')a[2][d]++;
        else if(x=='H')a[3][d]++;
        else if(x=='S')a[4][d]++;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j]==0){
                ans++;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
