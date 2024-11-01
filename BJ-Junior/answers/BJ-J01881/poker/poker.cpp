#include<bits/stdc++.h>
using namespace std;
int n,a[5][20],sum;
string s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        int p;
        if(s[1]=='A'){
            p=1;
        }
        else if(s[1]=='T'){
            p=10;
        }
        else if(s[1]=='J'){
            p=11;
        }
        else if(s[1]=='Q'){
            p=12;
        }
        else if(s[1]=='K'){
            p=13;
        }
        else{
            p=(int)s[1]-48;
        }
        if(s[0]=='D'){
            a[1][p]++;
        }
        if(s[0]=='C'){
            a[2][p]++;
        }
        if(s[0]=='H'){
            a[3][p]++;
        }
        if(s[0]=='S'){
            a[4][p]++;
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j]==0){
                sum++;
            }
        }
    }
    cout<<sum<<"\n";
    return 0;
}
