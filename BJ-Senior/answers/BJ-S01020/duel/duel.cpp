#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int juedou[N];
bool fl_ag[N];
int nn,kk;
void gongji(int gongjix,int gongjiy){
    fl_ag[gongjix]=false;
    if(juedou[gongjix]>juedou[gongjiy]){
        fl_ag[gongjiy]=false;
        juedou[gongjiy]=N;
        nn--;
    }
}
void duel_el(){
    bool duel_flag=false;
    while(nn!=0){
        sort(juedou+1,juedou+kk+1);
        for(int i=1;i<=nn;i++){
            if(juedou[i]>juedou[1]&&fl_ag[i]==true){
                gongji(i,1);
                duel_flag=true;
                break;
            }
        }
        if(duel_flag==false) break;
        duel_flag=false;
    }
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>nn;
    kk=nn;
    for(int i=1;i<=nn;i++){
        cin>>juedou[i];
    }
    for(int i=1;i<=nn;i++) fl_ag[i]=true;
    duel_el();
    cout<<kk-nn<<'\n';
    return 0;
}
