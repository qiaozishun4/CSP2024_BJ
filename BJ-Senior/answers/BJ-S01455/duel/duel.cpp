#include <bits/stdc++.h>
using namespace std;

int n,cnt;
int atk[114514],hp[114514];
bool use[114514],used[114514];
int bp[32][114514];

int solve12(){
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++){
        if(atk[i]==1)cnt1++;
        if(atk[i]==2)cnt2++;
    }
    return max(cnt1,cnt2);
}



int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        atk[i]=hp[i]=x;
    }
    sort(atk+1,atk+n+1);
    sort(hp+1,hp+n+1);
    if(atk[n]<=2){
        cout<<solve12()<<endl;
        return 0;
    }
return 0;
}
