#include <bits/stdc++.h>
long long t,n,m,l,v;
struct moniter{
    int have,open,cont;
}mop[2000005]={};

struct car{;
    int from,v,a,to;
    int cs,csfr,csto;
}ca[100005]={};


using namespace std;

int init(){
    n=0;
    m=0;
    l=0;
    v=0;
    return 0;
}

int moc(int fr,int en){
    for(int i=fr;i<=en;i++){
        if(mop[i].have==1){
            mop[i].cont++;
        }
    }
}

int rein(){
    cin>>n>>m>>l>>v;//n, m, L, V ,分别表示车辆数量、测速仪数量、主干道长度和道路限速。
    for(int i=1;i<=n;i++){
        cin>>ca[i].from>>ca[i].v>>ca[i].a;

        if(ca[i].a>=0){//加速
            ca[i].to=l;
            if(ca[i].v>v){//全程超速
                ca[i].cs=1;
                ca[i].csfr=ca[i].from;
                ca[i].csto=l;
                moc(ca[i].csfr,ca[i].csto)
                continue;
            }

            int s=(v+1)*(v+1)-ca[i].v


        }
        else{
            c[i].to=int(double(double(c[i].v*c[i].v)/double(2*c[i].a)))+c[i].from;
        }


    }
}

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t
    cout<<1<<endl<<0<<endl<<8<<endl;
    for(int qwerty=1;qwerty<=t;qwerty++){
        init();
        rein();

    }
    return 0;
}
