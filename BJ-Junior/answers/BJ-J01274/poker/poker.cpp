#include <bits/stdc++.h>
using namespace std;
int n,cnt=0,ls[4][14]={};
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        char a,b;
        cin>>a>>b;
        if(a=='C'){
                int c=0;
            if(b=='A'){
                c=1;
            }else if(b=='T'){
            c=10;
            }else if(b=='J'){
            c=11;
            }else if(b=='Q'){
            c=12;
            }else if(b=='K'){
            c=13;
            }else{
            c=(int)b-(int)'0';
            }

        if(ls[0][c]==0){
            ls[0][c]++;
            cnt++;
        }

        }else if(a=='S'){
int c=0;
            if(b=='A'){
                c=1;
            }else if(b=='T'){
            c=10;
            }else if(b=='J'){
            c=11;
            }else if(b=='Q'){
            c=12;
            }else if(b=='K'){
            c=13;
            }else{
            c=(int)b-(int)'0';
            }

        if(ls[1][c]==0){
            ls[1][c]++;
            cnt++;
        }

        }
        else if(a=='H'){
int c=0;
            if(b=='A'){
                c=1;
            }else if(b=='T'){
            c=10;
            }else if(b=='J'){
            c=11;
            }else if(b=='Q'){
            c=12;
            }else if(b=='K'){
            c=13;
            }else{
            c=(int)b-(int)'0';
            }

        if(ls[2][c]==0){
            ls[2][c]++;
            cnt++;
        }

        }else if(a=='D'){
int c=0;
            if(b=='A'){
                c=1;
            }else if(b=='T'){
            c=10;
            }else if(b=='J'){
            c=11;
            }else if(b=='Q'){
            c=12;
            }else if(b=='K'){
            c=13;
            }else{
            c=(int)b-(int)'0';
            }
        //cout<<c<<' ';
        if(ls[3][c]==0){
            ls[3][c]++;
            cnt++;
        }
        //cout<<cnt<<endl;
        }
    }
    cout<<52-cnt;
return 0;
}
