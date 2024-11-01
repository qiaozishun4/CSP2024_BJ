#include<bits/stdc++.h>
using namespace std;
int ans[5][14];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int n;
    cin>>n;
    int s=0;
    for(int i=1;i<=n;i++){
        char col,num;
        cin>>col>>num;
        if(num>='0' && num<='9')
            int tnum=num-'0';
        else if(num=='T')
            int tnum=10;
        else if(num=='J')
            int tnum=11;
        else if(num=='A')
            int tnum=1;
        else if(num='Q')
            int tnum=12;
        else
            int tnum=13;
        if(col=='D') ans[1][tnum]++;
        if(col=='C') ans[2][tnum]++;
        if(col=='H') ans[3][tnum]++;
        if(col=='S') ans[4][tnum]++;

    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(ans[i][j]==0) s++;
        }
    }
    cout<<s;
    return 0;
    fclose(stdin);
   fclose(stdout);

}
