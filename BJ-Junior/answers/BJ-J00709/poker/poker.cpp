#include<bits/stdc++.h>
using namespace std;
int n,cnt=52;
int s[14],h[14],d[14],c[14];
char a,b;
int b2;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(a=='S'){
            if(b=='A'){
                b2=1;
            }else if(b=='2'){
                b2=2;
            }else if(b=='3'){
                b2=3;
            }else if(b=='4'){
                b2=4;
            }else if(b=='5'){
                b2=5;
            }else if(b=='6'){
                b2=6;
            }else if(b=='7'){
                b2=7;
            }else if(b=='8'){
                b2=8;
            }else if(b=='9'){
                b2=9;
            }else if(b=='T'){
                b2=10;
            }else if(b=='J'){
                b2=11;
            }else if(b=='Q'){
                b2=12;
            }else if(b=='K'){
                b2=13;
            }
            s[b2]=1;
        }else if(a=='H'){
            if(b=='A'){
                b2=1;
            }else if(b=='2'){
                b2=2;
            }else if(b=='3'){
                b2=3;
            }else if(b=='4'){
                b2=4;
            }else if(b=='5'){
                b2=5;
            }else if(b=='6'){
                b2=6;
            }else if(b=='7'){
                b2=7;
            }else if(b=='8'){
                b2=8;
            }else if(b=='9'){
                b2=9;
            }else if(b=='T'){
                b2=10;
            }else if(b=='J'){
                b2=11;
            }else if(b=='Q'){
                b2=12;
            }else if(b=='K'){
                b2=13;
            }
            h[b2]=1;
        }else if(a=='D'){
            if(b=='A'){
                b2=1;
            }else if(b=='2'){
                b2=2;
            }else if(b=='3'){
                b2=3;
            }else if(b=='4'){
                b2=4;
            }else if(b=='5'){
                b2=5;
            }else if(b=='6'){
                b2=6;
            }else if(b=='7'){
                b2=7;
            }else if(b=='8'){
                b2=8;
            }else if(b=='9'){
                b2=9;
            }else if(b=='T'){
                b2=10;
            }else if(b=='J'){
                b2=11;
            }else if(b=='Q'){
                b2=12;
            }else if(b=='K'){
                b2=13;
            }
            d[b2]=1;
        }else{
            if(b=='A'){
                b2=1;
            }else if(b=='2'){
                b2=2;
            }else if(b=='3'){
                b2=3;
            }else if(b=='4'){
                b2=4;
            }else if(b=='5'){
                b2=5;
            }else if(b=='6'){
                b2=6;
            }else if(b=='7'){
                b2=7;
            }else if(b=='8'){
                b2=8;
            }else if(b=='9'){
                b2=9;
            }else if(b=='T'){
                b2=10;
            }else if(b=='J'){
                b2=11;
            }else if(b=='Q'){
                b2=12;
            }else if(b=='K'){
                b2=13;
            }
            c[b2]=1;
        }
    }
    for(int i=1;i<=13;i++){
        if(s[i]==1){
            cnt--;
        }
    }
    for(int i=1;i<=13;i++){
        if(h[i]==1){
            cnt--;
        }
    }
    for(int i=1;i<=13;i++){
        if(d[i]==1){
            cnt--;
        }
    }
    for(int i=1;i<=13;i++){
        if(c[i]==1){
            cnt--;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
