#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=1e5+10,C=110;
vector<int> s[N];
vector<int> f[N];
vector<int> to[N];
vector<int> cl[N];
int tag[N*2];
int g[N*2][C];
int ln[N];
int tp=0;int tt[N*2];
int n,m,k;
int tmp[N*2];
inline void gt(){
    vector<int> t1;
    for(int i=1;i<=n;i++){
        t1.clear();t1.push_back(0);
        for(int j=1;j<=ln[i];j++) t1.push_back(s[i][j]);
        sort(t1.begin(),t1.end());
        for(int j=1;j<t1.size();j++){
            if(t1[j]!=t1[j-1]) tmp[t1[j]]=++tp;
        }for(int j=1;j<=ln[i];j++){
            cl[i][j]=tmp[s[i][j]];
        }
    }
}
inline void move(){
    memset(tag,0,sizeof(tag));
    memset(tt,0,sizeof(tt));
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=ln[i];j++){
            to[i][j]=0;
        }
    }*/for(int i=1;i<=n;i++){
        for(int j=ln[i];j>=1;j--){
            to[i][j]=0;
            if(f[i][j]){
                to[i][j+1]++;
                int pr=min(ln[i]+1,j+k);
                to[i][pr]--;
                //cout<<i<<' '<<j<<' '<<pr<<' '<<cl[i][j]<<endl;
            }
        }
    }for(int i=1;i<=n;i++){
        for(int j=1;j<=ln[i];j++){
            to[i][j]+=to[i][j-1];
            if(to[i][j]>0){
                tag[s[i][j]]++;tt[cl[i][j]]--;
            }
        }
    }for(int i=1;i<=n;i++){
        for(int j=1;j<=ln[i];j++){
            f[i][j]=0;
            if(tag[s[i][j]]+tt[cl[i][j]]>0) f[i][j]=1;
        }
    }
}int LM=105;
void slv(){
    cin>>n>>k>>m;tp=0;
    memset(g,0,sizeof(g));memset(tag,0,sizeof(tag));memset(tt,0,sizeof(tt));
    for(int i=1;i<=n;i++){
        cin>>ln[i];
        s[i].resize(ln[i]+5);cl[i].resize(ln[i]+5);
        f[i].resize(ln[i]+5);to[i].resize(ln[i]+5);
        for(int j=1;j<=ln[i];j++){
            f[i][j]=0;to[i][j]=0;cin>>s[i][j];
            if(s[i][j]==1)f[i][j]=1;
        }
    }gt();//cerr<<tp<<endl;
    for(int i=1;i<=LM;i++){
        move();
        for(int j=1;j<=n;j++){
            for(int k=1;k<=ln[j];k++){
                if(to[j][k]>0) g[s[j][k]][i]=1;
                //cout<<to[j][k]<<' ';
            }//cout<<endl;
        }//cout<<endl;
    }while(m--){
        int r,c;scanf("%d%d",&r,&c);
        printf("%d\n",g[c][r]);
    }
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;cin>>t;while(t--) slv();
    fclose(stdin);fclose(stdout);
    return 0;
}//jp8akioi