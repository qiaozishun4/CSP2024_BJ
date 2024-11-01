#include <bits/stdc++.h>
using namespace std;
struct Car{
    int number;
    double Speed;
};
int n,m,V,L,R=301;
int d[301],v[301],a[301],p[301];
vector<Car> M[301];
bool tooFast[301];
void Speed(){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(d[j]<=p[i]){
                Car C;
                C.number=j;
                C.Speed=sqrt(v[j]*v[j]+2*a[j]*(p[i]-d[j]));
                if(C.Speed>V){
                    tooFast[j]==true;
                    M[i].push_back(C);
                }
            }
        }
    }
}
int Check(){
    int result=0;
    for(int i=0;i<n;i++){
        if(tooFast[i]==true){
            result++;
        }
    }
    return result;
}
void Remove(int ans){
    if(Check()>0){
        R=min(R,ans);
        return;
    }
    int maxnumber=M[0].size();
    vector<int> maxpos;
    maxpos.push_back(0);
    for(int i=1;i<m;i++){
        int SIZE=M[i].size();
        for(int j=0;j<M[i].size();j++){
            if(tooFast[M[i][j].number]==false){
                SIZE--;
            }
        }
        if(SIZE>maxnumber){
            maxnumber=M[i].size();
            maxpos.clear();
            maxpos.push_back(i);
        }
        else if(SIZE==maxnumber){
            maxpos.push_back(i);
        }
    }
    for(int i=0;i<maxpos.size();i++){
        for(int j=0;j<M[maxpos[i]].size();j++){
            tooFast[M[maxpos[i]][j].number]=false;
        }
        Remove(ans+1);
        for(int j=0;j<M[maxpos[i]].size();j++){
            tooFast[M[maxpos[i]][j].number]=true;
        }
    }
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    for(int x=0;x<T;x++){
        cin>>n>>m>>L>>V;
        for(int i=0;i<n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>p[i];
            M[i].clear();
        }
        memset(tooFast,0,sizeof(tooFast));
        Speed();
        int ans=0;
        for(int i=0;i<n;i++){
            if(tooFast[i]==true){
                ans++;
            }
        }
        R=301;
        cout<<ans<<" ";
        Remove(0);
        cout<<R;
    }
    return 0;
}