#include<iostream>
#include<algorithm>
using namespace std;
int h[100005],rinfact[100005],xiabiao=1,alive[100005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int r[n+1];
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    sort(r+1,r+n+1,cmp);
    int a=r[1];
//    map<int,int> h;
    for(int i=1;i<=n;i++){
        if(h[r[i]]==0){
            rinfact[xiabiao]=r[i];
            xiabiao++;
        }
        h[r[i]]++;
        alive[r[i]]++;
    }
    xiabiao--;
    for(int i=1;i<=xiabiao;i++){
        int nowi=i+1;
        while(nowi<=xiabiao){
            if(h[rinfact[i]]>=alive[rinfact[nowi]]){
                h[rinfact[i]]-=alive[rinfact[nowi]];
                alive[rinfact[nowi]]=0;
            }
            else{
                alive[rinfact[nowi]]-=h[rinfact[i]];
                break;
            }
            nowi++;
        }
    }
    int ans=0;
    for(int i=1;i<=xiabiao;i++){
        ans+=alive[rinfact[i]];
    }
    cout<<ans;
    return 0;
}
