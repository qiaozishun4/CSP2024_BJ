#include<bits/stdc++.h>
using namespace std;
bool health[114514],hunger[114514];
int a[114514];
int main(){
freopen("duel.in","r",stdin);
freopen("duel.out","w",stdout);
int n;
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
    hunger[i]=1;
    health[i]=1;
}
sort(a+1,a+n+1);
for(int i=1;i<=n;i++){
    if(health[i]==0||hunger[i]==0){
        continue;
    }
    if(lower_bound(a+1,a+n+1,a[i])-a-1==0){
            continue;
            }
    int fst=lower_bound(a+1,a+n+1,a[i])-a-1;
    if(health[fst]==0){
        while((health[fst]==0)&&fst>0){
            fst--;
        }
        if(health[fst]==1){
            health[fst]=0;
            hunger[i]=0;
        }else{
            continue;
        }
    }else{
        health[fst]=0;
        hunger[i]=0;
    }

}
int cnt=0;
for(int i=1;i<=n;i++){
    if(health[i]==1){
        cnt++;
    }
}
cout<<cnt;

return 0;
}
