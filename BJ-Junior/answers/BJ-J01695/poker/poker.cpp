#include <iostream>
#include <set>
#include <string>
using namespace std;
set<string> st;
int main() {
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        string s;
        cin>>s;
        st.insert(s);
    }
    cout<<52-st.size()<<endl;
    return 0;
}
/*
#include <iostream>
#include <cmath>
using namespace std;
typedef double db;
const db cost[9]={0,1,1,10,100,10000,1000000,1000000000,1000000000000};
const db cmul[9]={0,10,10,100,100,10000,10000,100000000,10000000000};
db Matter=1;
db Energy=0;
db AntiMatter=0;
db Photon=0;
db dms[9];
db newcost[9];
db Scale=256;
db multi[9];
void tryB(int dmsc) {
    if(Matter>=newcost[dmsc]) {
        Matter-=newcost[dmsc];
        Scale*=0.99;
        multi[dmsc]*=2;
        dms[dmsc]++;
        newcost[dmsc]*=cmul[dmsc];
    }
}
void outNumber(db x) {
    if(x<=1000) printf("%.2lf",x);
    else {
        db t=x;
        int cnt=0;
        while(t>=1) cnt++,t/=10;
        printf("%.3lfe%d",t*10,cnt-1);
    }
}
void Reset(int Tier) {
    if(Tier>=1) {
        Matter=1;
        for(int i=1;i<=8;i++) newcost[i]=cost[i];
        for(int i=1;i<=8;i++) multi[i]=1;
        for(int i=1;i<=8;i++) dms[i]=0;
        Scale=256;
        Energy=0;
    }
}
void Output() {
    // Stage Matter
    if(Matter<1e18) {
        printf("You have "); outNumber(Matter); printf(" Matter(s)\n");
        if(AntiMatter!=0) {
            printf("You have "); outNumber(AntiMatter); printf(" Antimatter(s)\n");
            printf("You have "); outNumber(Energy); printf(" Energy\n");
        }
        printf("Your progress will division by %.2lf\n",Scale);
        for(int i=1;i<=8;i++) {
            printf("You have "); outNumber(dms[i]); printf(" %d%c%c Matter Dimension",i," snrt"[min(i,4)]," tddh"[min(i,4)]);
            printf(" Cost: "); outNumber(newcost[i]); printf(" Multiplier: "); outNumber(multi[i]); printf("\n");
        }
    } else {
        db ExpectAM=(Matter/1e18);
        printf("You have too many Matters.\n");
        printf("Press any key to get %.2lf Antimatter and continue.",ExpectAM);
        getchar();
        AntiMatter+=ExpectAM;
        Reset(1);
    }
    // Stage Antimatter

}
void Frame() {
    Matter+=dms[1]*multi[1]/Scale/2*log(Energy);
    for(int i=1;i<=7;i++) dms[i]+=dms[i+1]*multi[i+1]/Scale/2*log(Energy);
    for(int i=8;i>=1;i--) tryB(i);
    if(Matter!=0 && AntiMatter!=0) Energy+=log(Matter*AntiMatter);
}
int main() {

    while(1) {
        system("clear");
        Output();
        Frame();
        system("sleep 0.5");
    }
    return 0;
}

*/
