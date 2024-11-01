#include<bits/stdc++.h>
using namespace std;
int D[15]={0},c[15]={0},h[15]={0},s[15]={0};
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    char se,shu;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>se>>shu;
        if(se=='D'){
            if(shu=='A'){
               D[1]=1;
            }else if(shu=='2'){
               D[2]=1;
            }else if(shu=='3'){
               D[3]=1;
            }else if(shu=='4'){
               D[4]=1;
            }else if(shu=='5'){
               D[5]=1;
            }else if(shu=='6'){
               D[6]=1;
            }else if(shu=='7'){
               D[7]=1;
            }else if(shu=='8'){
               D[8]=1;
            }else if(shu=='9'){
               D[9]=1;
            }else if(shu=='T'){
               D[10]=1;
            }else if(shu=='J'){
               D[11]=1;
            }else if(shu=='Q'){
               D[12]=1;
            }else if(shu=='K'){
               D[13]=1;
            }
        }else if(se=='C'){
            if(shu=='A'){
               c[1]=1;
            }else if(shu=='2'){
               c[2]=1;
            }else if(shu=='3'){
               c[3]=1;
            }else if(shu=='4'){
               c[4]=1;
            }else if(shu=='5'){
               c[5]=1;
            }else if(shu=='6'){
               c[6]=1;
            }else if(shu=='7'){
               c[7]=1;
            }else if(shu=='8'){
               c[8]=1;
            }else if(shu=='9'){
               c[9]=1;
            }else if(shu=='T'){
               c[10]=1;
            }else if(shu=='J'){
               c[11]=1;
            }else if(shu=='Q'){
               c[12]=1;
            }else if(shu=='K'){
               c[13]=1;
            }
        }if(se=='H'){
            if(shu=='A'){
               h[1]=1;
            }else if(shu=='2'){
               h[2]=1;
            }else if(shu=='3'){
               h[3]=1;
            }else if(shu=='4'){
               h[4]=1;
            }else if(shu=='5'){
               h[5]=1;
            }else if(shu=='6'){
               h[6]=1;
            }else if(shu=='7'){
               h[7]=1;
            }else if(shu=='8'){
               h[8]=1;
            }else if(shu=='9'){
               h[9]=1;
            }else if(shu=='T'){
               h[10]=1;
            }else if(shu=='J'){
               h[11]=1;
            }else if(shu=='Q'){
               h[12]=1;
            }else if(shu=='K'){
               h[13]=1;
            }
        }else if(se=='S'){
            if(shu=='A'){
               s[1]=1;
            }else if(shu=='2'){
               s[2]=1;
            }else if(shu=='3'){
               s[3]=1;
            }else if(shu=='4'){
               s[4]=1;
            }else if(shu=='5'){
               s[5]=1;
            }else if(shu=='6'){
               s[6]=1;
            }else if(shu=='7'){
               s[7]=1;
            }else if(shu=='8'){
               s[8]=1;
            }else if(shu=='9'){
               s[9]=1;
            }else if(shu=='T'){
               s[10]=1;
            }else if(shu=='J'){
               s[11]=1;
            }else if(shu=='Q'){
               s[12]=1;
            }else if(shu=='K'){
               s[13]=1;
            }
        }
    }
    int num=0;

    for(int j=1;j<=13;j++){
        num+=D[j];
    }
    for(int j=1;j<=13;j++){
        num+=c[j];
    }
    for(int j=1;j<=13;j++){
        num+=h[j];
    }
    for(int j=1;j<=13;j++){
        num+=s[j];
    }
    cout<<52-num;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
