#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

int n, m, l, vmax;
struct CAR{
    int d0;
    int v0;
    int a;
    // V>Vmax at probe [l,r)
    int l;
    int r;
    inline void rd(){
        scanf("%d%d%d", &d0, &v0, &a);
    }
};
vector<CAR> cs;
vector<int> pbl;
vector<int> t;


int bs(double k, const vector<int> &arr, int eq)
{
    int l, r, mid;

    l = 0;
    r = arr.size();
    while (l < r) // [l,r)
    {
        mid = (l + r) / 2;
        if (k<arr[mid])
            r = mid;
        else if (k>arr[mid])
            l = mid + 1;
        else
            return mid+eq; // arr[mid]==k
    }
    return l; // First arr[idx]>=k
}
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T, ans1, ans2;
    double dt;
    register int i,j;
    scanf("%d", &T);
    while(T>0){
        scanf("%d%d%d%d", &n, &m, &l, &vmax);
        cs.resize(n);
        pbl.resize(m);
        t.resize(m);
        ans1=0;
        ans2=0; // How many must be kept
        for(i=0;i<n;i++){
            cs[i].rd();
        }
        for(i=0;i<m;i++){
            scanf("%d", &pbl[i]);
        }
        for(i=0;i<n;i++){
            if(cs[i].a==0){
                if(cs[i].v0>vmax){
                    cs[i].l = bs(cs[i].d0, pbl, 0); // = []
                    cs[i].r = m;
                }else{
                    cs[i].l = -1;
                    cs[i].r = -1;
                }
            }else{
                dt = (vmax*vmax-cs[i].v0*cs[i].v0)/(2.0*cs[i].a); // V_inst at d0+dt = vmax
                if(cs[i].a>0){
                    cs[i].r = m;
                    if(dt<0){
                        dt=cs[i].d0;
                    }else dt+=cs[i].d0;
                    cs[i].l = bs(dt, pbl, 1); // = ()
                }else{
                    if(dt<0){
                        cs[i].l = -1;
                        cs[i].r = -1;
                    }else{
                        cs[i].l = bs(cs[i].d0, pbl, 0); // = []
                        cs[i].r = bs(dt+cs[i].d0, pbl, 0); // = []
                    }
                }
            }
            // printf("D:\t%d\t%d\t%d\t%llf\n", i, cs[i].l, cs[i].r, dt);
            if(cs[i].r-cs[i].l>0){
                ans1++;
            }else{ // Exclude
                cs[i].l=-1;
                cs[i].r=-1;
            }
        }
        printf("%d ", ans1);
        i=0;
        while(i<cs.size()){
            if(cs[i].l!=-1){
                for(j=cs[i].l;j<cs[i].r;j++){
                    t[j]++;
                }
                i++;
            }else{
                cs.erase(cs.begin()+i);
            }
        }
        while(cs.size()>0){
            j=0;
            for(i=1;i<m;i++){
                if(t[j]<t[i]){
                    j=i;
                }
            }
            // printf("D: Erase\t%d\n", j);
            ans1=j; // tmp
            i=0;
            while(i<cs.size()){
                if(cs[i].l<=ans1 && ans1<cs[i].r){
                    for(j=cs[i].l;j<cs[i].r;j++){
                        t[j]--;
                    }
                    cs.erase(cs.begin()+i);
                }else i++;
            }
            ans2++;
        }
        printf("%d\n", m-ans2);
        T--;
    }
    return 0;
}