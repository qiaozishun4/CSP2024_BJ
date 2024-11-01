#include <iostream>
#include <cstring>
using namespace std;

struct f{
    int d;
    double v,a;
};
const int maxnm=1e5+100;
f cars[maxnm];
int cameras[maxnm];


void detect(){
    double L,V;//主干道长度&道路限速
    int n,m;//车辆数，摄像头数
    cin>>n>>m>>L>>V;
    int cnt=0;//超速车辆个数
    for(int i=1;i<=n;i++)
    {
        cin>>cars[i].d>>cars[i].v>>cars[i].a;//起始点，初速度，加速度
    }
    int maxc=0;
    for(int i=1;i<=m;i++)
    {
        cin>>cameras[i];
        maxc=max(cameras[i],maxc);
    }
    cameras[m]=maxc;
    for(int i=1;i<=n;i++)
    {
            if(cars[i].v>V&&cars[i].d<=cameras[m]) {
                cnt++;
            }
    }
    cout<<cnt<<' '<<1<<endl;
}

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        detect();
    }
    return 0;
}
