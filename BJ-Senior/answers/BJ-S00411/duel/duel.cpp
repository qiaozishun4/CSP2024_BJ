#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int c[100005],b[100005];
    int len=0,cnt=0;
    int n;
    cin>>n;
    for(int i=1;i<=10000;i++){
        if(b[i]!=0){
            len++;
            c[len]+=b[i];
        }
    }
    int ans=0;
    for(int i=1;i<=len;i++){
        cnt-=c[i];
        if(cnt>c[i])
{

    ans+=cnt;
}    }
cout<<n-ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
