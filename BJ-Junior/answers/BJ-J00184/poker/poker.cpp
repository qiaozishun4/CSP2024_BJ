#include<bits/stdc++.h>
using namespace std;
int n,ans;
char s,d;
int si,di;
int ph[5][15];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s>>d;
        if(s=='D'){
            si=1;
        }
        if(s=='C'){
            si=2;
        }
        if(s=='H'){
            si=3;
        }
        if(s=='S'){
            si=4;
        }
        if(d=='T'){
            di=10;
        }
        else if(d=='J'){
            di=11;
        }
        else if(d=='Q'){
            di=12;
        }
        else if(d=='K'){
            di=13;
        }
        else if(d=='A'){
            di=1;
        }
        else{
            di=(int)d-48;
        }
        if(ph[si][di]==0){
            ph[si][di]=1;
            ans++;
        }
    }
    cout<<52-ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}