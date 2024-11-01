#include<bits/stdc++.h>
using namespace std;

char hua[]={'D','C','H','S'},shu[]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'},c,s;
bool b[256][256];
int n;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        c=getchar();
        while(c=='\n'){
            c=getchar();
        }
        s=getchar();
        b[c][s]=1;
    }
    int cnt=52;
    for(int i=0;i<4;++i){
        for(int j=0;j<13;++j){
            if(b[hua[i]][shu[j]]){
                cnt--;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
