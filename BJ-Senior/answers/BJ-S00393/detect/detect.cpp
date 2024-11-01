#include <iostream>
#include <cmath>
using namespace std;
int t,p,n,m,l,v,i,ju,s,qudiao;
//p 测速仪距最南端距
//l 道路长度
//v 道路限速
bool car[100005],pt;
double speed;
struct{
    int d,v,a;
    //d 距离最南端长度
    //v 初速度
    //a 加速度（可正可负
}c[100005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    for(int qw=0;qw<t;++qw){
        s=0;
        qudiao=0;
        cin>>n>>m>>l>>v;
        for(i=0;i<n;++i){
            cin>>c[i].d>>c[i].v>>c[i].a;
            car[i]=true;
        }
        for(i=0;i<m;++i){
            pt=false;
            cin>>p;
            for(int j=0;j<n;++j){
                ju=p-c[j].d;
                if(ju<0)continue;
                speed=sqrt(c[j].v*c[j].v+2*c[j].a*ju);
                if(speed>v&&car[j]){
                    ++s;
                    car[j]=false;
                    pt=true;
                }
            }
            if(pt)
                ++qudiao;
        }
        cout<<s<<' '<<qudiao<<endl;
    }
    return 0;
}
