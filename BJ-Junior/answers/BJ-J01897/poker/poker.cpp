#include<bits/stdc++.h>
using namespace std;
int a[10][20],n,cnt;
map<char,int>p,q;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    p['D']=1,p['C']=2,p['H']=3,p['S']=4;
    q['A']=1,q['T']=10,q['J']=11,q['Q']=12,q['K']=13;
    cin>>n;
    for(int i=1;i<=n;i++){
        char x,y;
        cin>>x>>y;
        a[p[x]][((isdigit(y))?y-'0':q[y])]=1;
    }for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!a[i][j])cnt++;
        }
    }cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
