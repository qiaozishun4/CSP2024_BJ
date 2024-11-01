#include <bits/stdc++.h>
using namespace std;
int n,t,r;
char a,b;
int f;
int d[210];
int turning(char x){
    if(x=='A')return 1;
    if(x=='2')return 2;
    if(x=='3')return 3;
    if(x=='4')return 4;
    if(x=='5')return 5;
    if(x=='6')return 6;
    if(x=='7')return 7;
    if(x=='8')return 8;
    if(x=='9')return 9;
    if(x=='T')return 10;
    if(x=='J')return 11;
    if(x=='Q')return 12;
    if(x=='K')return 13;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        f=0;
        cin>>a>>b;
        if(a=='C'){
            t+=13;
        }
        if(a=='S'){
            t+=26;
        }
        if(a=='H'){
            t+=39;
        }
        t+=turning(b);
        d[i]=t;
        for(int j=1;j<i;j++){
            if(d[j]==t){
                f=1;
                break;
            }
        }
        if(!f)r++;
        t=0;
    }
    cout<<52-r<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}