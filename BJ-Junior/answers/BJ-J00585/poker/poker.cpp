#include <bits/stdc++.h>
using namespace std;
int n,m=0;
int h[4][14]={};
struct pai{
    char h;
    char d;
};
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    pai p;
    for(int i=0;i<n;i++){
        cin>>p.h>>p.d;
        if(p.d=='T')p.d='9'+1;
        if(p.d=='A')p.d='1';
        if(p.d=='J')p.d='9'+2;
        if(p.d=='Q')p.d='9'+3;
        if(p.d=='K')p.d='9'+4;
        if(p.h=='D'){
            h[0][0]=1;
            h[0][p.d-'0']=1;
        }
        else if(p.h=='C'){
            h[1][0]=1;
            h[1][p.d-'0']=1;
        }
        else if(p.h=='H'){
            h[2][0]=1;
            h[2][p.d-'0']=1;
        }
        else if(p.h=='S'){
            h[3][0]=1;
            h[3][p.d-'0']=1;
        }
    }
    if(h[0][0]==0)m+=13;
    if(h[1][0]==0)m+=13;
    if(h[2][0]==0)m+=13;
    if(h[3][0]==0)m+=13;
    for(int i=0;i<4;i++){
        if(h[i][0]==1){
            for(int j=1;j<14;j++)
                if(h[i][j]==0)
                    m++;
        }
    }
    printf("%d",m);
    return 0;
}