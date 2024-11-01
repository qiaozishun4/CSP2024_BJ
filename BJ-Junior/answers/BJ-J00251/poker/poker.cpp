#include <bits/stdc++.h>
using namespace std;
int n,ans=52,h[10][20],code[200],code2[200];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    code['A']=1;
    code['T']=10;
    code['J']=11;
    code['Q']=12;
    code['K']=13;
    code2['D']=1;
    code2['C']=2;
    code2['H']=3;
    code2['S']=4;
    for(int i=2;i<=9;i++){
        code[i+'0']=i;
    }
    for(int i=1;i<=n;i++){
        int x,y;
        char xx,yy;
        cin>>xx>>yy;
        x=code2[xx];
        y=code[yy];
        if(h[x][y]==0){
            h[x][y]=1;
            ans--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
