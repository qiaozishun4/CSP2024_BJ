#include<bits/stdc++.h>
using namespace std;
const int N=70;
long long n,d[N],c[N],h[N],s[N],ans,cnt;
string a;
int main (){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(a[1]=='T'){
            a[1]='10';
        }
        if(a[1]=='A'){
            a[1]='1';
        }
        if(a[1]=='J'){
            a[1]='11';
        }
        if(a[1]=='Q'){
            a[1]='12';
        }
        if(a[1]=='K'){
            a[1]='13';
        }


        if(a[0]=='D'){
            d[a[1]-'0']++;
        }
        else if(a[0]=='C'){
            c[a[1]-'0']++;
        }
        else if(a[0]=='H'){
            h[a[1]-'0']++;
        }
        else if(a[0]=='S'){
            s[a[1]-'0']++;
        }
    }
    for(int j=0;j<13;j++){
            if(d[j]==0){
                cnt++;
            }
            if(c[j]==0){
               cnt++;
            }
            if(h[j]==0){
                cnt++;
            }
            if(s[j]==0){
                cnt++;
            }
    }
    cout<<cnt;
    return 0;
}
