#include<bits/stdc++.h>
using namespace std;
int T;
int n,k,q;
struct jyl{
    int l;
    vector<int> s;
};
struct quest{
    int r;
    int c;
};
jyl jyls[100001];
quest qts[100001];
bool dfs(int lst,int stt,int lus,int got){
    bool f=0;
//    cout<<"in to lst:"<<lst<<" stt:"<<stt<<" lus:"<<lus<<" got:"<<got<<endl;
    for(int i=1;i<=n;i++){
        if(i==lus) continue;
        for(int j=0;j<jyls[i].l;j++){
            if(jyls[i].s[j]==stt){
                for(int o=1;o<k&&j+o<jyls[i].l;o++){
                    if(lst==1&&jyls[i].s[j+o]==got) return 1;
                    else if(lst>1) f|=dfs(lst-1,jyls[i].s[j+o],i,got);
                }
            }
        }
    }
    return f;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>jyls[i].l;
            jyls[i].s.clear();
            for(int j=1;j<=jyls[i].l;j++){
                int x;
                cin>>x;
                jyls[i].s.push_back(x);
            }
        }
        for(int i=1;i<=q;i++){
            cin>>qts[i].r>>qts[i].c;
        }
        for(int i=1;i<=q;i++){
            cout<<dfs(qts[i].r,1,0,qts[i].c)<<endl/*<<endl*/;
        }
    }
    return 0;
}
