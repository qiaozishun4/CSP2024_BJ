#include<bits/stdc++.h>
using namespace std;
int buc[100010],liv[1000010],n,x,cnt,res[300],resnm,resptr__,MAX_=-1;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        buc[x]++;
        liv[x]++;
        MAX_=max(MAX_,x);
    }
    //cout<<MAX_<<endl;
    for(int i=1;i<=MAX_;i++){
        if(buc[i]>0){
            res[++resptr__]=i;
        }
        if(resptr__>=2){
            int k=min(buc[res[1]],liv[res[2]]);
            //cout<<buc[res[1]]<<" "<<liv[res[2]];
            buc[res[1]]-=k;
            liv[res[1]]-=k;
            liv[res[2]]-=k;
            cnt+=k;
            if(liv[res[1]]>liv[res[2]]){
                res[2]=0;
                resptr__=1;
            }
            else if(liv[res[1]]<liv[res[2]]){
                res[1]=res[2];
                resptr__=1;
            }
            else{
                res[1]=0,res[2]=0,resptr__=0;
            }
        }
    }
    cout<<n-cnt;
    return 0;
}
