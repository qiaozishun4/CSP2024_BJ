#include <bits/stdc++.h>
using namespace std;

int t,n,m,l,v;
struct car{
    double d,v,a,over,stop;
}car[100005];
struct c{
    int p,num;
}csy[100005];

void input(int i){
    cin>>car[i].d>>car[i].v>>car[i].a;
    if(car[i].v = 0) car[i].stop = car[i].d;
    else if(car[i].a < 0) car[i].stop = car[i].d+(0-(car[i].v*car[i].v))/(2*car[i].a);
    else car[i].stop = 0x3f3f3f3f;

    double over;
    if(car[i].a != 0) over = ((v*v)-(car[i].v * car[i].v))/(2*car[i].a);
    else over = 0x3f3f3f3f;

    if(car[i].v > v) car[i].over = car[i].d;
    else if(over>=0 && (over+car[i].d)<=l){
        car[i].over = over+car[i].d;
    }
    else{
        car[i].over = 0x3f3f3f3f;
    }

}

int ans1,ans2;

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>l>>v;
        for(int i = 1;i<=n;i++){
            input(i);
        }
        for(int j = 1;j<=m;j++){
            cin>>csy[j].p;
            csy[j].num = 0;
        }
        for(int i = 1;i<=n;i++){
            //cout<<car[i].over<<","<<car[i].stop<<" ";
            bool flag = false;
            for(int j = 1;j<=m;j++){
                if(csy[j].p >= car[i].over && csy[j].p <= car[i].stop){
                    flag = true;
                    csy[j].num ++;
                }
            }
            if(flag) ans1++;
        }
        for(int j = 1;j<=m;j++){
            if(!csy[j].num) ans2++;
        }
        //cout<<endl;
        cout<<ans1<<" "<<ans2<<endl;
    }

    return 0;
}
