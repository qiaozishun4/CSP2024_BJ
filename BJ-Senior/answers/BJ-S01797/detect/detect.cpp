#include<bits/stdc++.h>
#define Maxcar 100004
using namespace std;
int T,n,m,L,V;
struct Car{
    int d,v,a;
    double from=-1,to=-1;
    bool tect=false;
}car[Maxcar];
void found(int num){
    if(car[num].a<0){
        double s=(V^2-car[num].v^2)/(2*car[num].a);
        if(s>=0){
            car[num].from=car[num].d;
            if(car[num].d+s<=L) car[num].to=car[num].d+s;
            else car[num].to=L;
        }
    }
    else if(car[num].a==0){
        if(car[num].v>V){
            car[num].from=car[num].d;
            car[num].to=L;
        }
    }
    else{
        double s=(V^2-car[num].v^2)/(2*car[num].a);
        if(s<=L){
            car[num].to=L;
            if(s>=0) car[num].from=car[num].d+s;
            else car[num].from=car[num].d;
        }
    }
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    for(int t=0;t<T;t++){
        cin>>n>>m>>L>>V;
        int ans1=0,ans2=0,detect[m];
        bool used[m];
        for(int i=0;i<n;i++) cin>>car[i].d>>car[i].v>>car[i].a;
        for(int i=0;i<m;i++) cin>>detect[m];
        for(int i=0;i<n;i++){
            found(i);
            for(int j=0;j<m;j++){
                if(detect[j]>=car[i].from&&detect[j]<=car[i].to){
                    used[j]==true;
                    car[i].tect=true;
                }
            }
        }
        //for(int i=0;i<n;i++) cout<<car[i].from<<' '<<car[i].to<<' '<<car[i].tect<<endl;
        for(int i=0;i<n;i++) if(car[i].tect==true) ans1++;
        for(int i=0;i<n;i++) if(used[i]==false) ans2++;
        cout<<ans1<<' '<<ans2<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
