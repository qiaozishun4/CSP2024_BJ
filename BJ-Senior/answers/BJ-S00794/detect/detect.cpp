#include<bits/stdc++.h>
using namespace std;

int n,m,L,V;

struct node{
    int s,e;
    bool detected;
}cars[1009];

struct node2{
    int pos;
    int ded;
}mo[1009];//monitor


bool overSpeed[1009];


bool cmp(node x,node y){
    return x.s<y.s;
}

bool cmp2(node2 x,node2 y){
    return x.ded>y.ded;
}



int main(){
    cin.tie(0),cout.tie(0);
    ios::sync_with_stdio(false);

    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    int T;
    cin>>T;
    while(T--){

        cin>>n>>m>>L>>V;
        for(int i=0;i<n;i++){
            int d,v,a;
            cin>>d>>v>>a;
            double s;
            if(a!=0){
                s=(pow(V,2)-pow(v,2))/(2*a);//precision!!!!!
                if(s<0){
                    if(v>V)s=L;
                    else s=-1;
                }
            }else{
                if(v>V){
                    s=L;
                }else{
                    s=-1;
                }
            }
            if(a!=0){
                if( ((int)(pow(V,2)-pow(v,2))%(2*a))==0)s--;//开区间
            }
            if(v<V && a>0){
                cars[i].s=d+s+1;
                cars[i].e=L+1;
            }else{
                cars[i].s=d;
                cars[i].e=d+s;
            }
            cars[i].detected=false;

            //cout<<T<<' '<<cars[i].s<<' '<<cars[i].e<<endl;
        }

        //sort(cars,cars+n,cmp);
        //for(int i=0;i<n;i++)cout<<cars[i].s<<' '<<cars[i].e<<endl;
        for(int i=0;i<m;i++){
            //
            int tmp;
            cin>>tmp;
            mo[i].pos=tmp;
        }
        //sort(mo,mo+m,cmp2);//small to big



        //for(int i=0;i<m;i++)cout<<pos[i]<<' ';
        int cnt=0,ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //if(cars[j].s>pos[i])l++;
                if(cars[j].e<=-1){
                    continue;
                }
                if(cars[j].s<=mo[i].pos && cars[j].e>=mo[i].pos && cars[j].detected==0){
                    //cout<<"!:"<<j<<endl;;
                    cars[j].detected=1;
                    cnt++;
                    mo[i].ded++;
                }
            }
        }


        //cout<<"###"<<cnt<<endl;
        cout<<cnt<<' '<<m/2<<endl;
    }
    return 0;
}
