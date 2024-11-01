#include <bits/stdc++.h>
using namespace std;
#define CED 2
int n,cnt;
int a[5][14];
int main(){
    if(CED==2){
        freopen("poker.in","r",stdin);
        freopen("poker.out","w",stdout);
        }
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        char s[4];
        int m;
        scanf("%s",s);
        switch(s[0]){
        case D:
            m=0;
            break;
        case C:
            m=1;
            break;
        case H:
            m=2;
            break;
        default:
            m=3;

        }
        if(s[1]>='0'&&s[1]<='9'){
            a[m][s[1]-48]++;
        }else{
        switch(s[1]){
        case T:
            a[m][10]++;
            break;
        case J:
            a[m][11]++;
            break;
        case Q:
            a[m][12]++;
            break;
        case K:
            a[m][13]++;
        }
        }
    }
    for(int i=0;1<4;i++){
        for(int j=0;j<13;j++){
            if(!a[i][j]){
                cnt++;
            }
        }
    }
    printf("%d",&cnt);

    return 0;
}
