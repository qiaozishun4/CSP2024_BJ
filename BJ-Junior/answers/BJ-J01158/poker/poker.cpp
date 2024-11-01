#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream input("poker.in");
    ofstream output("pocker.out")
    string a;
    int c[14],d[14],h[14],s[14];
    int n,x=0,shu=0;
    input>>n;
    for(int i=1;i<=13;i++){
        c[i]=0;
        d[i]=0;
        h[i]=0;
        s[i]=0;
    }
    for(int i=1;i<=n;i++){
        input>>a;
        if(a[1]=='A'){
            x=1;
        }else if(a[1]=='T'){
            x=10;
        }else if(a[1]=='J'){
            x=11;
        }else if(a[1]=='Q'){
            x=12;
        }else if(a[1]=='K'){
            x=13;
        }else{
            x=a[1]-'0';
        }
        if(a[0]=='D'){
            d[x]=x;
        }else if(a[0]=='C'){
            c[x]=x;
        }else if(a[0]=='H'){
            h[x]=x;
        }else if(a[0]=='S'){
            s[x]=x;
        }
    }
    for(int i=1;i<=13;i++){
        if(d[i]==0){
            shu++;
        }
        if(c[i]==0){
            shu++;
        }
        if(s[i]==0){
            shu++;
        }
        if(h[i]==0){
            shu++;
        }
    }
    output<<shu;
    input.close();
    output.close();
}