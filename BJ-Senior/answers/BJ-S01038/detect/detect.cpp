#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int N=1e5+5;
int T,n,m,p[N],L,V;
struct CAR{int sl,sr;}car[N];
struct NCAR{int l,r;}c[N];
bool cmp(NCAR x,NCAR y){return x.l<y.l;}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        memset(c,0,sizeof(c));
        memset(car,0,sizeof(car));
        memset(p,0,sizeof(p));
        scanf("%d%d%d%d",&n,&m,&L,&V);
        for(int i=1;i<=n;i++){
            int d,v,a,sl,sr;
            scanf("%d%d%d",&d,&v,&a);
            if(a>0){
                if(v>V)sl=d,sr=L;
                else{
                    a=a*2;
                    sl=(V*V-v*v)/a+d+1;
                    sr=L;
                }
            }
            else if(a<0){
                if(v>V){
                    sl=d;
                    a*=-2;
                    if((v*v-V*V)%a==0)sr=(v*v-V*V)/a+d-1;
                    else sr=(v*v-V*V)/a+d;
                    sr=min(sr,L);
                }
                else sl=-1,sr=-1;
            }
            else{
                if(v>V)sl=d,sr=L;
                else sl=-1,sr=-1;
            }
            car[i]={sl,sr};
        }
        for(int i=1;i<=m;i++)scanf("%d",&p[i]);
        p[m+1]=1e9;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(car[i].sr<0||car[i].sl>L)continue;
            int l=lower_bound(p+1,p+m+2,car[i].sl)-p;
            int r=upper_bound(p+1,p+m+2,car[i].sr)-p;
            r--;
            if(l>r)continue;
            c[++cnt].l=l;
            c[cnt].r=r;
        }
        sort(c+1,c+cnt+1,cmp);
        int top=1,curmn=2e9,ans=0;
        for(int i=1;i<=m;i++){
            while(c[top].l==i)curmn=min(curmn,c[top].r),top++;
            if(curmn<=i){
                ans++;
                curmn=2e9;
            }
        }
        printf("%d %d\n",cnt,m-ans);
    }
    return 0;
}
//Workingmen of all countries, unite!