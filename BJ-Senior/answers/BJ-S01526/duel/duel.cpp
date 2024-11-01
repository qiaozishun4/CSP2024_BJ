#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n,ans;
int rnum[N];

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&rnum[i]);
    }
    sort(rnum+1,rnum+1+n);
    int i=1,j=2;
    while(j<=n){
        while(j<=n && rnum[j]<=rnum[i]) ++j;
        if(j>n) break;
        ans++;
        ++j;
        ++i;
    }
    printf("%d",n-ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}