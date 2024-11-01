#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
bool d[105],c[105],h[105],s[105];
//A 2 3 4 5 6 7 8 9 T J Q K
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        char hs,nu,ka[5];
        scanf("%s",&ka);
        hs=ka[0];
        nu=ka[1];
        if(hs=='D'){
            if(nu=='A')d[1]=1;
            else if(nu=='2')d[2]=1;
            else if(nu=='3')d[3]=1;
            else if(nu=='4')d[4]=1;
            else if(nu=='5')d[5]=1;
            else if(nu=='6')d[6]=1;
            else if(nu=='7')d[7]=1;
            else if(nu=='8')d[8]=1;
            else if(nu=='9')d[9]=1;
            else if(nu=='T')d[10]=1;
            else if(nu=='J')d[11]=1;
            else if(nu=='Q')d[12]=1;
            else if(nu=='K')d[13]=1;
        }else if(hs=='C'){
            if(nu=='A')c[1]=1;
            else if(nu=='2')c[2]=1;
            else if(nu=='3')c[3]=1;
            else if(nu=='4')c[4]=1;
            else if(nu=='5')c[5]=1;
            else if(nu=='6')c[6]=1;
            else if(nu=='7')c[7]=1;
            else if(nu=='8')c[8]=1;
            else if(nu=='9')c[9]=1;
            else if(nu=='T')c[10]=1;
            else if(nu=='J')c[11]=1;
            else if(nu=='Q')c[12]=1;
            else if(nu=='K')c[13]=1;
        }else if(hs=='H'){
            if(nu=='A')h[1]=1;
            else if(nu=='2')h[2]=1;
            else if(nu=='3')h[3]=1;
            else if(nu=='4')h[4]=1;
            else if(nu=='5')h[5]=1;
            else if(nu=='6')h[6]=1;
            else if(nu=='7')h[7]=1;
            else if(nu=='8')h[8]=1;
            else if(nu=='9')h[9]=1;
            else if(nu=='T')h[10]=1;
            else if(nu=='J')h[11]=1;
            else if(nu=='Q')h[12]=1;
            else if(nu=='K')h[13]=1;
        }else{
            if(nu=='A')s[1]=1;
            else if(nu=='2')s[2]=1;
            else if(nu=='3')s[3]=1;
            else if(nu=='4')s[4]=1;
            else if(nu=='5')s[5]=1;
            else if(nu=='6')s[6]=1;
            else if(nu=='7')s[7]=1;
            else if(nu=='8')s[8]=1;
            else if(nu=='9')s[9]=1;
            else if(nu=='T')s[10]=1;
            else if(nu=='J')s[11]=1;
            else if(nu=='Q')s[12]=1;
            else if(nu=='K')s[13]=1;
        }
    }
    for(int i=1;i<=13;i++){
        if(d[i]==0)cnt++;
    }
    for(int i=1;i<=13;i++){
        if(c[i]==0)cnt++;
    }
    for(int i=1;i<=13;i++){
        if(h[i]==0)cnt++;
    }
    for(int i=1;i<=13;i++){
        if(s[i]==0)cnt++;
    }
    printf("%d",cnt);
    return 0;
}
