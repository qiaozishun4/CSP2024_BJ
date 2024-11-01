#include<bits/stdc++.h>
#define f1 first
#define s2 second
using namespace std;

typedef pair<double,double> pll;
double p[100005];
pll cs[100005];
vector<int> mis[100005];
int bcs[100005];
int n,m;
double L,V;

pll ifcs(double di,double vi,double ai){
    if(ai>0){
        if(vi>V)
            return {di,L};
        double k=(V*V-vi*vi)/(2*ai)+di+0.0001;
        if(k>=L)
            return {-1,-1};
        return {k,L};
    }
    if(ai<0){
        if(vi<=V)
            return {-1,-1};
        double k=(V*V-vi*vi)/(2*ai)+di-0.0001;
        if(k>L)
            return {di,L};
        return {di,k};
    }
    if(vi>V)
        return{di,L};
    return {-1,-1};
}




int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int ans=0;
        double d,v,a;
        memset(bcs,0,sizeof(bcs));
        cin>>n>>m>>L>>V;
        for(int i=0;i<n;i++){
            cin>>d>>v>>a;
            cs[i]=ifcs(d,v,a);
        //    cout<<cs[i].f1<<' '<<cs[i].s2<<endl;
        }
        for(int i=0;i<m;i++){
            cin>>p[i];
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(cs[i].f1<=p[j] && p[j]<=cs[i].s2){
                    mis[j].push_back(i);
                    ans+=(!bcs[i]);
                    bcs[i]++;
                }
            }
        }
        cout<<ans<<' ';

        ans=0;
        for(int i=0;i<m;i++){
            int j;
            for(j=0;j<mis[i].size();j++){
                if(bcs[mis[i][j]]<=1)
                    break;
            }
            if(j==mis[i].size()){
                ans++;
                for(j=0;j<mis[i].size();j++)
                    bcs[mis[i][j]]--;
            }
        }
        cout<<ans<<endl;
        for(int i=0;i<m;i++)
            mis[i].clear();
    }

    return 0;
}
