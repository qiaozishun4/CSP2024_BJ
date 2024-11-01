#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct car{
    int d;
    int v;
    int a;
};
int n,m,L,V;
car allc[1000005];
int bot[1000005];

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++){
        //input a test
        scanf("%d%d%d%d",&n,&m,&L,&V);
        for (int j=0;j<n;j++){
            int ca,cb,cc;
            scanf("%d%d%d",&ca,&cb,&cc);
            allc[j]={ca,cb,cc};
        }
        for (int j=0;j<m;j++){
            int where;
            scanf("%d",&where);
            bot[j]=where;
        }
        sort(bot,bot+m);
        int over=0,big=0,reduce=0;
        for (int i=0;i<n;i++){
            if (allc[i].v>V&&allc[i].d<=bot[m-1]){
                over++;
            }
        }
        cout<<over<<" "<<m-1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
