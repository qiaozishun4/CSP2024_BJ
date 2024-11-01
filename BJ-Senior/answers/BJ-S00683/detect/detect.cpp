#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
#include<cstdio>
#define maxn 100010
using namespace std;
int T,car_num,detect_num,road_length,limit_V,maxcnt;
struct Car{
    int away;
    int start_V;
    int plus_V;
    bool becaught;
}car[maxn];
struct Detect{
    int away;
    vector<int> catch_car;
}detect[maxn];
bool compare(Detect x,Detect y){
    return x.catch_car.size()>y.catch_car.size();
}
int tmp[100000*10000],tmp1[maxn];
void calculate(int tmp[],int tmp1[],bool isDetected[],int now,int num,int cnt){
    int tmptmp[maxn][maxn]={},cnt1=0;
    for(int i=1;i<=num;i++){
        for(int j=1;j<=tmp1[i];j++){
            tmptmp[i][j]=tmp[cnt+j];
        }
        cnt1+=tmp1[i];
    }
    for(int i=1;i<=tmp1[i];i++){
        isDetected[tmptmp[now][i]]=1;
    }
    cnt++;
    bool flag=0;
    for(int i=1;i<=num;i++){
        if(isDetected[i]==0){
            flag=1;
            break;
        }
    }
    if(!flag){
        maxcnt=max(maxcnt,cnt);
        return ;
    }
    else{
        for(int i=1;i<=num-now;i++){
            calculate(tmp,tmp1,isDetected,i,num,cnt);
        }
    }
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>car_num>>detect_num>>road_length>>limit_V;
        for(int j=1;j<=car_num;j++){
            cin>>car[j].away>>car[j].start_V>>car[j].plus_V;
            car[j].becaught=0;
        }
        for(int j=1;j<=detect_num;j++){
            cin>>detect[j].away;
        }
        for(int j=1;j<=car_num;j++){
            int detect_i=1;
            while(car[j].away>detect[detect_i].away) detect_i++;
            for(int k=detect_i;k<=detect_num;k++){
                double now_V=sqrt(pow(double(car[j].start_V),2)+2*double(car[j].plus_V)*(double(detect[k].away)-double(car[j].away)));
                if(now_V>limit_V){
                    car[j].becaught=1;
                    detect[k].catch_car.push_back(car[j].away);
                }
            }
        }
        int exceed=0;
        for(int j=1;j<=car_num;j++){
            if(car[j].becaught) exceed++;
        }
        cout<<exceed<<" ";
        sort(detect+1,detect+detect_num+1,compare);
        bool isDetected[detect_num+1];
        memset(isDetected,0,sizeof(isDetected));
        int cnt=0;
        for(int j=1;j<=detect_num;j++){
            tmp1[j]=detect[j].catch_car.size();
            for(int k=1;k<=tmp1[j];k++){
                tmp[cnt+k]=detect[j].catch_car[k];
            }
            cnt+=tmp1[j];
        }
        calculate(tmp,tmp1,isDetected,1,detect_num,0);
        cout<<maxcnt<<endl;

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}