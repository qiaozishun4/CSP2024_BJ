#include<bits/stdc++.h>
using namespace std;
int cnt[4][15];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    char hc1,hc2;
    int n,a=-1,b=-1,sum=0;
    scanf("%d",&n);
    while(n--){
        cin>>hc1;
        cin>>hc2;
        if(hc1=='D'){
            a=0;
        }
        if(hc1=='C'){
            a=1;
        }
        if(hc1=='H'){
            a=2;
        }
        if(hc1=='S'){
            a=3;
        }
        if(hc2=='A'){
            b=0;
        }
        if(hc2=='2'){
            b=1;
        }
        if(hc2=='3'){
            b=2;
        }
        if(hc2=='4'){
            b=3;
        }
        if(hc2=='5'){
            b=4;
        }
        if(hc2=='6'){
            b=5;
        }
        if(hc2=='7'){
            b=6;
        }
        if(hc2=='8'){
            b=7;
        }
        if(hc2=='9'){
            b=8;
        }
        if(hc2=='T'){
            b=9;
        }
        if(hc2=='J'){
            b=10;
        }
        if(hc2=='Q'){
            b=11;
        }
        if(hc2=='K'){
            b=12;
        }
            cnt[a][b]=1;
        }
         for(int i=0;i<4;i++){
            for(int j=0;j<13;j++){
                if(cnt[i][j]==0){
                    sum++;
                }
            }

        }
        printf("%d",sum);
        fclose(stdin);
        fclose(stdout);
        return 0;
        }


