#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int n,mi=999999,m,t[100001]={},flag=0,ii,cnt=0,g[100001],temp[100001]={},iii;
int findf(int d){
    int cn=0;
    for(int i=0;i<100001;i++){
        if(t[i]){
            if(cn==d)
                return i;
            cn++;
        }

    }
    return 0;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>flag;
        t[flag]++;
    }
    for(int i=0;i<10001;i++){
        ii=findf(0);
        iii=findf(1);
        t[ii]=max(0,t[ii]-t[iii]+temp[iii]);
        temp[iii]=min(t[iii],temp[iii]+t[ii]);
    }
    for(int i=0;i<10001;i++)
        cnt+=t[i];
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;

}
