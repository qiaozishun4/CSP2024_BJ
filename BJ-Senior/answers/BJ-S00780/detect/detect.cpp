#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int N = 100010;
const int M = 1000010;

int T, n, m, L, V;
int p[N], d[N], v[N], a[N];

struct range {
    int l, r;
    const bool operator < (range &R) const {
        return l < R.l;
    }
}cars[N];

int S[M], left[M];
bool skip[N];

int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        memset(S, 0, sizeof(S));
        memset(skip, 0, sizeof(skip));
        scanf("%d%d%d%d", &n, &m, &L, &V);
        for(int i = 0; i < n; i++){
            scanf("%d%d%d", &d[i], &v[i], &a[i]);
        }
        for(int i = 0; i < m; i++){
            int p;
            scanf("%d", &p);
            S[p] = 1;
        }
        left[0] = -1;
        for(int i = 1; i <= L; i++){
            if(S[i]==1)
                left[i] = i;
            else
                left[i] = left[i-1];
            S[i] = S[i-1] + S[i];
        }
        int num = 0;
        for(int i = 0; i < n; i++){
            if(a[i] >= 0){
                int LEFT;
                if(v[i] > V)
                    LEFT = d[i];
                else if(a[i] > 0)
                    LEFT = ((V*V-v[i]*v[i])/(2*a[i])) + 1 + d[i];
                else
                    continue;
                if(LEFT > L)
                    continue;
                // printf("%d, %d (%d>%d)\n", LEFT, L, S[L], S[LEFT-1]);
                if(S[L] > S[LEFT-1]){
                    cars[num].l = LEFT;
                    cars[num].r = L;
                    num++;
                }
            }
            else{
                if(v[i] <= V)
                    continue;
                int RIGHT = d[i] + ((v[i]*v[i] - V*V)/(-2*a[i]));
                if((v[i]*v[i]-V*V)%(-2*a[i])==0)
                    RIGHT--;
                RIGHT = min(RIGHT, L);
                // printf("%d, %d (%d>%d)\n", d[i], RIGHT, S[RIGHT], S[d[i]-1]);
                if(S[RIGHT] > (d[i]?S[d[i]-1]:0)){
                    cars[num].l = d[i];
                    cars[num].r = RIGHT;
                    num++;
                }
            }
        }
        printf("%d ", num);
        if(num){
            sort(cars, cars + num);
            int curR = cars[num-1].r;
            for(int i = num-2; i >= 0; i--){
                if (cars[i].r > curR)
                    skip[i] = true;
                else
                    curR = cars[i].r;
            }
            int curP = -1, cntP = 0;
            for(int i = 0; i < num; i++){
                if(skip[i]) continue;
                // printf("%d, %d(%d)\n", cars[i].l, cars[i].r, curP);
                if(curP >= cars[i].l) continue;
                cntP++;
                curP = left[cars[i].r];
            }
            printf("%d\n", m - cntP);
        }
        else
            printf("%d\n", m);
    }
    return 0;
}