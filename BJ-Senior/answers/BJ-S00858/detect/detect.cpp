#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int t, n, m, l, v, p[100010];
struct str{
    int d, v, a;
}car[100010];
bool detected[100010];//超速了没有?
int ans1, ans2 = 1000000;
vector<int> dtct[100010];
bool tdetected[100010];

int speed(int len, int x){//第x辆车行使到了len距离 后的速度 向上取整
    if(len < car[x].d) return 0;
    if(len == car[x].d) return car[x].v;
    len -= car[x].d;
    return ceil(sqrt( car[x].v*car[x].v + 2*car[x].a*len));
}

bool issolvea(){
    for(int i=1; i<=n; i++){
        if(car[i].a!=0) return false;
    }
    return true;
}

bool issolveb(){
    for(int i=1; i<=n; i++){
        if(car[i].a<0) return false;
    }
    return true;
}

void solvea(){
    int lastcam=0;
    for(int i=0; i<=m; i++) if(p[i] > lastcam) lastcam = p[i];
    for(int i=1; i<=n; i++) if(car[i].v > v && car[i].d <= lastcam) ans1++;
    cout<<ans1<<' ';
    if(ans1) cout<<m-1<<endl;
    else cout<<m<<endl;
}

void solveb(){
    int lastcam=0;
    for(int i=0; i<=m; i++) if(p[i] > lastcam) lastcam = p[i];
    for(int i=1; i<=n; i++) if(speed(lastcam, i) > v && car[i].d <= lastcam) ans1++;
    cout<<ans1<<' ';
    if(ans1) cout<<m-1<<endl;
    else cout<<m<<endl;
}

void dfsother(int step, vector<int> curdetected, int enabledcam){
    //cout<<step<<endl;
    if(step == m+1){
        for(int i=1; i<=n; i++) tdetected[i] = 0;
        for(int i=0; i<curdetected.size(); i++) tdetected[curdetected[i]] = true;
        for(int i=1; i<=n; i++) if(tdetected[i] != detected[i]) return ;
        ans2 = min(ans2, enabledcam);
        return ;
    }
    dfsother(step+1, curdetected, enabledcam);
    for(int i=0; i<dtct[step].size(); i++) curdetected.push_back(dtct[step][i]);
    enabledcam++;
    dfsother(step+1, curdetected, enabledcam);
}

void othersolve(){
    ans2 = 1000000;
    for(int i=1; i<=n; i++) detected[i] = 0;
    for(int i=1; i<=n; i++) dtct[i].clear();
    for(int i=1; i<=n; i++){
        //if(car[i].v < v && car[i].a<=0) continue;
        for(int j=1; j<=m; j++){//第i辆车在第j个拍照点有没有超速
            if(speed(p[j] , i) > v){
                dtct[j].push_back(i);
                detected[i] = true;
            }
        }
    }
    for(int i=1; i<=n; i++) if(detected[i]) ans1++;

    vector<int> justtemp;
    dfsother(1, justtemp, 0);
    cout<<ans1<<' '<<m - ans2<<endl;
}

int main(){

    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    cin>>t;
    while(t--){
        ans1 = 0;
        cin>>n>>m>>l>>v;
        for(int i=1; i<=n; i++) cin>>car[i].d>>car[i].v>>car[i].a;
        for(int i=1; i<=m; i++) cin>>p[i];

        if(issolvea()) solvea();
        else if(issolveb()) solveb();
        else if(n<=100) othersolve();
        else{
            cout<<n<<' '<<0<<endl;
        }
    }

    return 0;
}
