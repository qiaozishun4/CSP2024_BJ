#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    int n,r[100001][2],b[100001],cnt=0,da,xiao,m=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i][1];
        r[i][2]=1;
        b[r[i][1]]++;
    }
    for(int i=1;i<=n;i++){
        if(b[r[i][1]]!=0) m++;
    }
    bool f=true;
    for(int i=1;i<=n;i++){
        f=true;
        for(int j=1;j<=n;j++){
            if(r[i][2]==1){
                f=false;
                break;
            }
        }
        if(f==true) break;
        b[r[i++][1]]=(b[r[i][1]]+b[r[i++][1]])-min(b[r[i][1]],b[r[i++][1]]);
        cnt-=min(b[r[i][1]],b[r[i++][1]]);
        for(int j=1;j<=min(b[r[i][1]],b[r[i++][1]]);j++) r[j][2]=0;
    }
    cout<<b[r[m][1]]<<endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
