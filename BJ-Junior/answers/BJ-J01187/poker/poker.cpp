#include<bits/stdc++.h>
using namespace std;
long long n,vis[1005],ans;
char a,b;
void ad(char b,long long s){
    long long add=s*13;
    if(b>='0' && b<='9'){
        vis[add+b-'0']=1;
    }
    else{
        if(b=='A'){
            vis[add+1]=1;
        }
        else if(b=='T'){
            vis[add+10]=1;
        }
        else if(b=='J'){
            vis[add+11]=1;
        }
        else if(b=='Q'){
            vis[add+12]=1;
        }
        else if(b=='K'){
            vis[add+13]=1;
        }
    }
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf(" %c %c",&a,&b);
        if(a=='D'){
            ad(b,0);
        }
        else if(a=='C'){
            ad(b,1);
        }
        else if(a=='H'){
            ad(b,2);
        }
        else if(a=='S'){
            ad(b,3);
        }
    }
    for(int i=1;i<=52;i++){
        if(vis[i]==0)ans++;
    }
    printf("%lld",ans);
    return 0;
}