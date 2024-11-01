#include<bits/stdc++.h>
#define N 100010
using namespace std;
int T;
int n,m,L,V;//car number,  speeder number,   road lenght,  speed limit
struct car{
    int d,v,a;// x v a
    int l,r;//[l,r] is the range of over speed
}C[N];
int p[N];// speeder location
int osnum,kccsl;
priority_queue< pair<int,int> > rg;
pair<int,int> b[N];
bool vis[10*N],vis2[10*N];
int bjccs[N];

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>V;
        osnum=0;kccsl=0;
        memset(vis,false,10*N);
        memset(vis2,false,10*N);

        for(int i=1;i<=n;i++){
            cin>>C[i].d>>C[i].v>>C[i].a;
            if(C[i].a>0){
                C[i].l=(((V*V)-(C[i].v*C[i].v))/(2*C[i].a))+C[i].d+1;
                C[i].r=L;
            }else if(C[i].a<0){
                C[i].r=(((V*V)-(C[i].v*C[i].v))/(2*C[i].a))+C[i].d;
                if(((V*V)-(C[i].v*C[i].v))==(C[i].r-C[i].d)*2*C[i].a) C[i].r--;
                C[i].l=C[i].d;
            }else if (C[i].a==0){
                if(C[i].v>V){
                    C[i].l=C[i].d;
                    C[i].r=L;
                }else{
                    C[i].l=L+1;
                    C[i].r=L+2;
                }
            }
            if(C[i].l>C[i].r) {
                C[i].l=L+1;
                C[i].r=L+2;
            }
            if(C[i].l!=L+1){
                pair<int,int> temp;
                temp.first=C[i].l;
                temp.second=C[i].r;
                rg.push(temp);
            }

        }


        n=rg.size();
        int temp=n;
        while(rg.size()){

            b[temp].first=rg.top().first;
            b[temp].second=rg.top().second;
            rg.pop();
            temp--;
        }





        for(int i=1;i<=m;i++){
            cin>>p[i];
            vis[p[i]]=1;
        }

        osnum=0;kccsl=0;
        for(int i=1;i<=n;i++){
            for(int index=b[i].first;index<=b[i].second;index++){
                if(vis[index]==true){
                    vis2[index]=true;
                    osnum++;
                    break;
                }
            }
        }


        /*for(int i=1;i<=n;i++){
            if(bjccs[i]!=0) osnum++;
        }*/
        for(int i=0;i<=L;i++){
            if(vis2[i]==true) kccsl++;

        }

        kccsl=m-kccsl;


        cout<<osnum<<" "<<kccsl<<endl;


    }
    return 0;

}

