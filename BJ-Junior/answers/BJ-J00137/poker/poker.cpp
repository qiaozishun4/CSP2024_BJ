#include <bits/stdc++.h>
using namespace std;
int a[30][10];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,tot=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        char stuf,rnum;
        int num;
        scanf("%c%c",&stuf,&rnum);
        if(rnum>'0'&&rnum<='9'){
            num=rnum-'0';
        }
        else{
            if(rnum=='T'){
                num=10;
            }
            if(rnum='J'){
                num=11;
            }
            if(rnum='Q'){
                num=12;
            }
            if(rnum='K'){
                num=13;
            }
        }if(stuf=='D'){
            if(a[num][1]==0){
                tot++;
            }
            a[num][1]++;
        }
        if(stuf=='C'){
            if(a[num][2]==0){
                tot++;
            }
            a[num][2]++;
        }
        if(stuf=='H'){
            if(a[num][3]==0){
                tot++;
            }
            a[num][3]++;
        }
        if(stuf=='D'){
            if(a[num][4]==0){
                tot++;
            }
            a[num][4]++;
        }
    }
    printf("%d",tot);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
