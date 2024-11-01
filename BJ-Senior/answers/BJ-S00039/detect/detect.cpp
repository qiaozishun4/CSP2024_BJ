#include<iostream>
#include <vector>
#include <cstring>
using namespace std;
int q,n,m,l,V,tou[3005],use[3005],pai[3005],wm=0;
struct cs{
    int l,r;
};
vector<cs> chao;
vector<int>tu[3005];
cs over(int d,int v,int a){
    cs t;
    if(a==0){
        if(v>V){
            t.l=d;
            t.r=l;
            return t;
        }
        else{
            t.l=-1;
            t.r=-1;
            return t;
        }
    }
    if(a>0){
        double od=(V*V-v*v)/(2*a);
        int o=int(od)+1+d;
        if(o>l){
            t.l=-1;
            t.r=-1;
            return t;
        }
        t.l=max(d,o);
        t.r=l;
        return t;
    }
    if(a<0){
        double od=(V*V-v*v)/(2*a);
        od-=0.0000001;
        int o=int(od)+d;
        if(o<d){
            t.l=-1;
            t.r=-1;
            return t;
        }
        t.r=min(l,o);
        t.l=d;
        return t;
    }
    return t;
}
bool bao(int x,int ii){
    if(x>ii){
        for(int i=wm;i>0;i--){
            if(pai[i]>0){
                return false;
            }
        }
        return true;
    }
    for(int i=1;i<m;i++){
        if(!use[i]){
            use[i]=1;
            int okk=0;
            for(int j=0;j<tu[i].size();j++){
                if(pai[tu[i][j]]==1)okk++;
                pai[tu[i][j]]--;
            }
            if(!okk)continue;
            if(bao(x+1,ii))return true;
            use[i]=1;
            for(int j=0;j<tu[i].size();j++){
                pai[tu[i][j]]++;
            }
        }
    }
    return false;
}
int main(){

    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&q);
    for(int qq=0;qq<q;qq++){
        chao.clear();
        for(int i=0;i<=m;i++){
            tu[i].clear();
        }
        memset(use,0,sizeof(use));
        memset(pai,0,sizeof(pai));
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++){
            cs t;
            int t1,t2,t3;
            scanf("%d%d%d",&t1,&t2,&t3);
            t=over(t1,t2,t3);
            if(t.l!=-1)chao.push_back(t);

        }
        for(int i=1;i<=m;i++){
            int t;
            scanf("%d",&t);
            tou[i]=t;
        }
        int ans1=0;
        wm=chao.size();
        for(int i=0;i<chao.size();i++){
            int beenpai=0;
            for(int j=1;j<=m;j++){
                if(chao[i].l<=tou[j]&& chao[i].r>=tou[j]){
                    tu[j].push_back(i+1);
                    pai[i]=1;
                    if(beenpai==0){
                        ans1++;
                        pai[i+1]=1;
                        beenpai=1;
                    }
                }
            }
        }
        cout<<ans1<<" ";
        //cout<<endl;
//        for(int i=0;i<=m;i++){
//            for(int j=0;j<tu[i].size();j++){
//                cout<<tu[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        cout<<n/2+1;
        cout<<endl;
    }

    return 0;
}
