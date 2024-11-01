#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    bool poke[13][4];
    memset(poke,false,sizeof(poke));
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        char c1=s[0];
        char c2=s[1];
        int i,j;
        if(c1=='D'){
            i=0;
        }
        if(c1=='C'){
            i=1;
        }
        if(c1=='H'){
            i=2;
        }
        if(c1=='S'){
            i=3;
        }
        if(c2<='9'&&c2>='0'){
            j=c2-'1';
        }
        if(c2=='A'){
            j=0;
        }
        if(c2=='T'){
            j=9;
        }
        if(c2=='J'){
            j=10;
        }
        if(c2=='Q'){
            j=11;
        }
        if(c2=='K'){
            j=12;
        }
        poke[j][i]=true;

    }
    int ans=0;
    for(int i=0;i<13;i++){
        for(int j=0;j<4;j++){
            if(poke[i][j]==false){
                ans++;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
