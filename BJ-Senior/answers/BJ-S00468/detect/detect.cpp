#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
struct node{
    int d;//位置
    int v;//速度
    int a;//加速度
    bool out_speed;
};
struct node2{
    int pos;
    bool catch_car;
};
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    int n,m,L,V;
    node car[100001]={};
    node2 speed_checker[100001]={};
    bool have_checker[100001]={};
    bool over_speed[100001]={};
    int useless;
    int out_speed_car;
    while(T--){
        cin>>n>>m>>L>>V;
        out_speed_car=0;
        memset(car,0,sizeof(car));
        memset(speed_checker,0,sizeof(speed_checker));
        memset(over_speed,0,sizeof(over_speed));
        for(int i=1;i<=n;i++){
            cin>>car[i].d>>car[i].v>>car[i].a;
            car[i].out_speed=false;
        }
        for(int i=1;i<=m;i++){
            cin>>useless;
            speed_checker[i].pos=useless;
            have_checker[useless]=true;
            speed_checker[i].catch_car=false;
        }
        for(int i=1;i<=n;i++){//遍历每一辆车
            if(car[i].a==0){
                if(car[i].v<=V){
                    continue;
                }else{
                    for(int j=car[i].d;j<=L;j++){
                        over_speed[j]=true;
                        if(have_checker[j]==true){
                            //out_speed_car++;
                            car[i].out_speed=true;
                        }
                    }
                }
            }else if(car[i].a>0){
                //这辆车在加速，
                //应计算出他多久后会超速，找出他超速的位置，
                double t=double(V-car[i].v)/car[i].a;
                //cout<<t<<endl;
                double over_pos=double(car[i].v)*t+0.5*double(car[i].a)*t*t;
                over_pos+=double(car[i].d);
                for(int j=int(over_pos+1.0);j<=L;j++){
                    over_speed[j]=true;
                    if(have_checker[j]==true){
                        //out_speed_car++;
                        car[i].out_speed=true;
                    }
                }
            }else{
                //如果该车刚开始就没有超速，那么全程就不可能超速，所以可以忽略
                if(car[i].v<=V){
                    continue;
                }else{
                    //计算出他从超速到不超速需要多久，
                    //然后计算出超速走过了那些地方，
                    double t=double(V-car[i].v)/car[i].a;
                    double okay_pos=double(car[i].v)*t+0.5*double(car[i].a)*t*t;
                    okay_pos+=double(car[i].d);

                    for(int j=car[i].d;j<=int(okay_pos+1.0);j++){
                        over_speed[j]=true;
                        if(have_checker[j]==true){
                            //out_speed_car++;
                            car[i].out_speed=true;
                        }
                    }
                }
            }

        }
        int cnt1=0,cnt2=0;
        for(int i=1;i<=n;i++){
            if(car[i].out_speed==true){
                cnt1++;
            }
        }

        for(int i=1;i<=L;i++){
                cout<<over_speed[i]<<' '<<have_checker[i]<<endl;

            if(over_speed[i]==true&&have_checker[i]==true){
                cnt2++;
            }
        }
        cout<<cnt1<<" "<<m-cnt2<<endl;
    }
    return 0;
}
