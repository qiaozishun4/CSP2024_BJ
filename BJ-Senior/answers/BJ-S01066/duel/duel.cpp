#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,r[N];
struct jg{
    int num=0;
    int flag=0; //0表示未发起攻击，是几表示几个已发起攻击
};
jg cnt[N];
int ans=0;

void gs(int a,int b){
    int i=b-1;
    if(i==0){
        return;
    }
    else if(cnt[i].num==0){
        gs(a,i--);
    }
    else if(cnt[a].num==0){
        return;
    }
    else{
        if(cnt[a].num-cnt[a].flag>=cnt[i].num){
            ans-=cnt[i].num;
//            cout<<ans<<" ";
            cnt[a].flag+=cnt[i].num;
            cnt[i].num=0;
            if(cnt[a].num-cnt[a].flag>0)
                gs(a,i--);
            else
                return;
        }
        else{
            ans-=cnt[a].num-cnt[a].flag;
 //           cout<<ans<<" ";
            cnt[i].num-=cnt[a].num-cnt[a].flag;
            cnt[a].flag=cnt[a].num;
            return;
        }
    }
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    ans=n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
        cnt[r[i]].num++;
    }
    for(int i=2;i<=N;i++){
        gs(i,i);
    }
    cout<<ans;
    return 0;
}
