#include<bits/stdc++.h>
using namespace std;
 int d[14]={0};
 int c[14]={0};
 int h[14]={0};
 int s[14]={0};
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    string k;
    for(int i=0;i<n;i++){
        cin>>k;
        int typ;
        if(k[1]>'1'&&k[1]<='9'){
            typ=k[1]-'0';
        }
        else if(k[1]=='A'){
            typ=1;
        }
        else if(k[1]=='T'){
            typ=10;
        }
        else if(k[1]=='J'){
            typ=11;
        }
        else if(k[1]=='Q'){
            typ=12;
        }
        else{
            typ=13;
        }
        if(k[0]=='D'){
            d[typ]=1;
        }
        else if(k[0]=='C'){
            c[typ]=1;
        }
        else if(k[0]=='H'){
            h[typ]=1;
        }
        else{
            s[typ]=1;
        }
    }
    int ans=52;
    for(int i=1;i<=13;i++){
        ans-=d[i];
        ans-=c[i];
        ans-=h[i];
        ans-=s[i];
    }
    cout<<ans;
    return 0;
}
