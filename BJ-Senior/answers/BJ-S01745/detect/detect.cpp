# include <bits/stdc++.h>
using namespace std;
int T;
struct node{
    int d,v,a;
    int x,y;
};
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        int n,m,l;
        double v;
        int num = 0;
        int check[100005];
        vector <node> car;
        cin>>n>>m>>l>>v;
        for(int i=0;i<n;i++){
            node ls;
            cin>>ls.d>>ls.v>>ls.a;
            if(ls.a<=0&&ls.v<v){
                continue;
            }
            car.push_back(ls);
        }
        for(int i=1;i<=m;i++){
            cin>>check[i];
        }
        n = car.size();
        for(int i=0;i<n;i++){
            if(car[i].d>check[m]) continue;
            if(car[i].a>=0 && car[i].v>v && car[i].d<=check[m]){
                num++;
                for(int j=1;j<=m;j++){
                    if(check[j]<car[i].d) continue;
                    else{
                        car[i].x = j;
                        car[i].y = check[m];
                        break;
                    }
                }
                continue;
            }

            double v0 = car[i].v;
            bool pd = 0;
            for(int j=1;j<=m;j++){
                if(check[j]<car[i].d) continue;
                if((v0*v0 + 2*car[i].a*(check[j]-car[i].d))<=0) continue;
                double c = sqrt(v0*v0 + 2*car[i].a*(check[j]-car[i].d));
                if(c>v){
                    if(!pd){
                        num++;
                        pd = 1;
                        car[i].x = j;
                    }
                    car[i].y = j;
                }
            }
        }
        int ans = 0;
        bool dl[1000005];
        memset(dl,0,sizeof(dl));
        for(int i=0;i<n;i++){
            //printf("%d %d\n",car[i].x,car[i].y);
            if(dl[i]||(car[i].x==0&&car[i].y==0)) continue;
            node ls = car[i];
            ans++;
            for(int j=i+1;j<n;j++){
                if(max(ls.x,car[j].x)<=min(ls.y,car[j].y)){
                    ls.x = max(ls.x,car[j].x);
                    ls.y = min(ls.y,car[j].y);
                    dl[j] = 1;
                }
            }

        }
        printf("%d %d\n",num,m-ans);
    }
    return 0;
}
