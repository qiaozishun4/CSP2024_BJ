#include <bits/stdc++.h>
using namespace std;
int n;
int a[5][14];
int ans;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    //cout<<'1'-48<<endl;
    for(int i=1;i<=n;i++){
        char opt,num;
        cin>>opt>>num;
        //cout<<opt<<" "<<num<<endl;
        int tmp=0;
        if(opt=='D'){
            if(num=='A') tmp=1;
            if(num=='T') tmp=10;
            if(num=='J') tmp=11;
            if(num=='Q') tmp=12;
            if(num=='K') tmp=13;
            if(num=='2') tmp=2;
            if(num=='3') tmp=3;
            if(num=='4') tmp=4;
            if(num=='5') tmp=5;
            if(num=='6') tmp=6;
            if(num=='7') tmp=7;
            if(num=='8') tmp=8;
            if(num=='9') tmp=9;
            a[1][tmp]=1;
        }
        if(opt=='C'){
            if(num=='A') tmp=1;
            if(num=='T') tmp=10;
            if(num=='J') tmp=11;
            if(num=='Q') tmp=12;
            if(num=='K') tmp=13;
            if(num=='2') tmp=2;
            if(num=='3') tmp=3;
            if(num=='4') tmp=4;
            if(num=='5') tmp=5;
            if(num=='6') tmp=6;
            if(num=='7') tmp=7;
            if(num=='8') tmp=8;
            if(num=='9') tmp=9;
            a[2][tmp]=1;
        }
        if(opt=='H'){
            if(num=='A') tmp=1;
            if(num=='T') tmp=10;
            if(num=='J') tmp=11;
            if(num=='Q') tmp=12;
            if(num=='K') tmp=13;
            if(num=='2') tmp=2;
            if(num=='3') tmp=3;
            if(num=='4') tmp=4;
            if(num=='5') tmp=5;
            if(num=='6') tmp=6;
            if(num=='7') tmp=7;
            if(num=='8') tmp=8;
            if(num=='9') tmp=9;
            a[3][tmp]=1;
        }
        if(opt=='S'){
            if(num=='A') tmp=1;
            if(num=='T') tmp=10;
            if(num=='J') tmp=11;
            if(num=='Q') tmp=12;
            if(num=='K') tmp=13;
            if(num=='2') tmp=2;
            if(num=='3') tmp=3;
            if(num=='4') tmp=4;
            if(num=='5') tmp=5;
            if(num=='6') tmp=6;
            if(num=='7') tmp=7;
            if(num=='8') tmp=8;
            if(num=='9') tmp=9;
            a[4][tmp]=1;
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!a[i][j]){
                //cout<<i<<" "<<j<<endl;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
