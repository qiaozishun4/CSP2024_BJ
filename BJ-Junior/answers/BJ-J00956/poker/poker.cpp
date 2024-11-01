#include<bits/stdc++.h>
using namespace std;
int n,d[13],c[13],h[13],s[13];

int main(){
    cin >> n;
    fropen("poker.in","r",stdin);
    fropen("poker.out","w",stdout);
    for(int i=0;i<n;i++){
        char a,b;
        cin >> a >> b;
        if(a=='D'){
            int num;
            if(b=='A'){
                num=0;
            }else if(b=='T'){
                num=9;
            }else if(b=='J'){
                num=10;
            }else if(b=='Q'){
                num=11;
            }else if(b=='K'){
                num=12;
            }else{
                num=b-'0'-1;
            }
            d[num]=1;
        }
        if(a=='C'){
            int num;
            if(b=='A'){
                num=0;
            }else if(b=='T'){
                num=9;
            }else if(b=='J'){
                num=10;
            }else if(b=='Q'){
                num=11;
            }else if(b=='K'){
                num=12;
            }else{
                num=b-'0'-1;
            }
            c[num]=1;
        }
        if(a=='H'){
            int num;
            if(b=='A'){
                num=0;
            }else if(b=='T'){
                num=9;
            }else if(b=='J'){
                num=10;
            }else if(b=='Q'){
                num=11;
            }else if(b=='K'){
                num=12;
            }else{
                num=b-'0'-1;
            }
            h[num]=1;

        }
        if(a=='S'){
            int num;
            if(b=='A'){
                num=0;
            }else if(b=='T'){
                num=9;
            }else if(b=='J'){
                num=10;
            }else if(b=='Q'){
                num=11;
            }else if(b=='K'){
                num=12;
            }else{
                num=b-'0'-1;
            }
            s[num]=1;
        }
    }
    int cnt=0;
    for(int i=0;i<13;i++){
        cnt+=d[i];
        cnt+=c[i];
        cnt+=h[i];
        cnt+=s[i];
    }
    cout << 52-cnt;
    return 0;
}
