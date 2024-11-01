#include<bits/stdc++.h>
using namespace std;
int n,x;
char s[53][2];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        char a,b;
        scanf("\n%c%c",&a,&b);
        bool ok=true;
        for(int j=1;j<=x;j++)
            if(s[j][0]==a&&s[j][1]==b){
                ok=false;
                break;
            }
        if(ok){
            s[++x][0]=a;
            s[x][1]=b;
        }
    }
    printf("%d",52-x);
}
