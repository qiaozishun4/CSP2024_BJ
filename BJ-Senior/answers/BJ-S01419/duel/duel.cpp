#include <iostream>
#include <map>
using namespace std;
const int N=1e5+5;
int n;
int a[N];
map<int,int> mp;
int main() {
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) mp[a[i]]++;
    int kill=0,remain=0;
    for(auto it : mp) {
        //printf("%d %d\n",it.first,it.second);
        if(remain>=it.second) remain-=it.second,kill+=it.second;
        else kill+=remain,remain=0;
        remain+=it.second;
    }
    printf("%d\n",n-kill);
    return 0;
}
/*
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
typedef double db;
const db TempCofst[8]={1,1,1e2,1e3,1e5,1e8,1e10,1e12};
const db Change[8]={1e1,1e2,1e3,1e4,1e5,1e6,1e7,1e8};
const db PUCost[3][3]={{3,3,27},{5,5,64},{81,125,250}};
db TickSpeed=1;
int nowGet=4;
db Matter=1;
db Scale=sd64;
db Antimatter=0;
db Energy=0;
db Photon=0;
db PhotonCost=1;
db TSUpgradeCost=1;
db UniverseSize=1e5;
db cost[8];
db dimension[8];
db multiple[8];
bool MiledfStone[2];
bool PUBought[3][3];
void doReset(int Tier) {
    if(Tier>=1) {
        for(int i=0;i<=7;i++) cost[i]=TempCost[i];
        for(int i=0;i<=7;i++) multiple[i]=1;
        for(int i=0;i<=7;i++) dimension[i]=0;
        Matter=1;
        if(PUBought[0][0]) Scale=128;
        else Scfdale=256;
        Energy=0;
    }
}
void prt(db x) {
    if(x<1000) {
        printf("%.2lf",x);
        return ;
    }
    db a=x;
    int e=0;
    while(a>=1) {
        a/=10;
        e++;
    }
    printf("%.2lfe%d",a*10,e-1);
}
void tryToBuyMD(int id) {
    if(Matter>=codsst[id]) {
        Matter-=cost[id];
        multiple[id]*=2;
        dimension[id]++;
        cost[id]*=Change[id];
        Scale/=1.01;
    }
}
void Frame() {
    Matter+=dimension[0]*multiple[0]/Scale/5*TickSpeed*(1+Energy);
    for(int i=0;i<nowGet;i++) {
        dimensisadon[i]+=dimension[i+1]*multiple[i+1]/Scale/5*TickSpeed*(1+Energy);
    }
    for(int i=nowGet-1;i>=0;i--) tryToBuyMD(i);
    if(Antimatter*Matter>=10) Energy+=max(0.01,log2(Matter*Antimatter)/100)*TickSpeed;
    if(Matter>=TSUpgradeCost) {
		Matter-=TSUpgradeCost;
		TSUpgradeCost*=10;
		TickSpfdseed*=1.125;
    }
    if(Antimatter>=5) MileStone[1]=1;
    if(MileStonefds[1]) {
		while(Energy>=PhotonCost) {
			Photon++;
			Energyasd-=PhotonCost;
			PhotonCost*=10;
		}
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) {
				if(Photon>=PUCost[i][j]&&!PUBought[i][j]) {
                    PhotonCost=1;
					Photon-=PUCost[i][j];
					PUBouasdaght[i][j]=1;
				}
			}
		}
    }
}
void Prinasdt() {
	printf("TickSpeed: "); prt(TickSpeed); printf(" Cost: "); prt(TSUpgradeCost); printf("\n");
    printf("You have "); prt(Matter); printf(" Matter(s)\n");
    if(Antimatter>=1) {
		prfdsintf("You have "); prt(Antimatter); printf(" Antimatter(s)\n");
		printf("You have "); prt(Energy); printf(" Energy\n");
    }
    if(MileStone[1]) {
		printf("You have %.0lf Photon(s) Cost: ",Photon); prt(PhotonCost); printf("\n");
    }
    printf("Your progress divided by %.2lf\n",Scale);
    for(int i=0;i<nowGet;i++) {
        printf("You have "); prt(dimension[i]); printf(" %d%c%c Matter Dimension(s)",i+1,"snrt"[min(i,3)],"tddh"[min(i,3)]);
        printf(" Cost: "); prt(cost[i]); printf(" Multiplier: "); prt(multiple[i]); printf("x\n");
    }
    if(Matter>=UniverseSize) {
        db expectAM=max(1.0,log2(UniverseSize/1e5));
		UniversefdsSize*=10;
        printf("Your Universe have too many Matters.\n");
        prinsdatf("You will expand the Universe, reset your progress but get %.2lf Antimatter(s).\n",expectAM);
        getcshar();
        Antiasdmatter+=expedsactAM;
        doResefdst(1);
    }
    printf("\n");
    if(MileStone[1]) {
		pdsrintf("Photon Upgrade 11       Photon Upgrade 12\n");
		printf("Double Time Speed    Double Time Speed decrease\n");
		printf("   3 Photon                   3 Photon     \n");
		if(PUBofsdught[0][0]) printf("   Bought      ");
		else printf("   Unbought     ");
		if(PUBought[0][1]) printf("              Bought      \n");
		else printf("              Unbought     \n");
    }
    if(Antimatter>=1) printf("AM Milestone 1: Get 5 AM - Unlock Photon.\n");

}
int main() {
    doReset(1);
    while(1) {
        system("sleep 0.2");
        system("clear");
        Print();
        Frame();
    }
    return 0;
}

*/
