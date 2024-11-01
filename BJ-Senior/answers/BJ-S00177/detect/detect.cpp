#include<bits/stdc++.h>
using namespace std;
struct node{
    int d,vv,a;
    int dl,dr;
}car[100005];
int T,n,m,l,v,q[100005],fck[100005],ans,mi;
vector<int> vec[100005];
double distance(int vv,int a){
    double V=double(vv),A=double(a);
    return (v*v-V*V)/(A*2.0);
}
bool cnt(int a,int b){
    for(int i=0;i<vec[a].size();i++){
        if(vec[a][i]==b)return 1;
    }
    return 0;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        memset(q,0,sizeof(q));
        memset(fck,0,sizeof(fck));
        scanf("%d%d%d%d",&n,&m,&l,&v);
        for(int i=1;i<=n;i++)vec[i].clear();
        ans=mi=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&car[i].d,&car[i].vv,&car[i].a);
            if(car[i].a>0){
                if(2*car[i].a*(l-car[i].d)+car[i].vv*car[i].vv<=v){
                    n--,i--;
                    continue;
                }
                car[i].dl=car[i].d+floor(distance(car[i].vv,car[i].a))+1;
                car[i].dr=l;
            }
            if(car[i].a<=0){
                if(car[i].vv<=v){
                    n--,i--;
                    continue;
                }
                if(2*car[i].a*(l-car[i].d)+car[i].vv*car[i].vv>v){
                    car[i].dl=car[i].d;
                    car[i].dr=l;
                }
                else{
                    car[i].dl=car[i].d;
                    car[i].dr=car[i].d+ceil(distance(car[i].vv,car[i].a))-1;
                }
            }
        }
        for(int i=1,p;i<=m;i++){
            scanf("%d",&p);
            q[p]=i;
        }
        for(int i=1;i<=n;i++){
            bool flag=0;
            for(int j=car[i].dl;j<=car[i].dr;j++){
                if(q[j])vec[q[j]].push_back(i),flag=1,fck[i]++;
            }
            if(flag)ans++;
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                    bool flag=0;
                for(int l=0;i<vec[i].size();l++){
                    if(cnt(j,vec[i][l])==0){
                        flag=1;
                        continue;
                    }
                }
                if(flag==0){
                        mi++;
                    for(int l=0;i<vec[i].size();l++){
                        fck[vec[i][l]]--;
                    }
                    vec[m+1].push_back(i);
                }
            }
        }
        for(int i=1;i<=m;i++){
            if(!cnt(n+1,i)){
                    bool flag=0;
                for(int j=0;j<vec[i].size();j++){
                    if(fck[vec[i][j]]==1){
                        flag=1;
                        continue;
                    }
                }
                if(flag==0){
                    mi++;
                }
            }
        }
        printf("%d %d\n",ans,mi);
    }
    return 0;
}
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 ‐2
6 4 ‐4
2 5 8 9 15
*/
