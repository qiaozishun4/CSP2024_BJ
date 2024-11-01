#include <bits/stdc++.h>

using namespace std;

struct cc{
    int start;
    int endd;
    int node;
}cars[100010];

bool cmp(cc aa, cc bb){
    return aa.endd<bb.endd;
}

int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int w=0; w<t; w++){
        int n, m, l, v;
        scanf("%d%d%d%d", &n, &m, &l, &v);
        int spd[100010], spdpos[100010];
        for(int i=0; i<n; i++){
            int d, vs, a;
            scanf("%d%d%d", &d, &vs, &a);
            if(a==0){
                if(vs>v) {cars[i].start=d; cars[i].endd=1000010;}
                else if(vs<=v) {cars[i].start=-1; cars[i].endd=-1;}
            }
            else{
                int tmp=1;
                int weiyi=((pow(3, 2)-pow(vs, 2))/(2*a));
                if(weiyi*2*a!=(pow(3, 2)-pow(vs, 2))){
                    weiyi++;
                    tmp=2;
                }
                if(weiyi<0){
                    if(vs<v&&a<0) {cars[i].start=-1; cars[i].endd=-1;}
                    else if(vs==0&&a>0) {cars[i].start=d+1; cars[i].endd=1000010;}
                    else if(vs>v&&a>0) {cars[i].start=d; cars[i].endd=1000010;}

                }
                else if(vs>v&&a<0){
                    cars[i].start=d; cars[i].endd=d+weiyi;
                    if(tmp==1)
                        cars[i].start++;
                }
                else if(vs<v&&a>0){
                    cars[i].start=d+weiyi; cars[i].endd=1000010;
                    if(tmp==1)
                        cars[i].start++;
                }
            }

        }
        for(int i=0; i<m; i++){
            scanf("%d", &spd[i]);
            spdpos[spd[i]]=1;
        }
        sort(spd, spd+m);
        sort(cars, cars+n, cmp);
        int ans1=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(spd[j]>cars[i].start&&spd[j]<cars[i].endd){
                    cars[i].endd=-1;
                    ans1++;
                }
            }
        }
        printf("%d ", ans1);
        sort(cars, cars+n, cmp);
        int tmpj=0, ans=0;
        int i=0;
        for(int j=0; j<n; ){
            if(cars[i].endd==-1){
                i++;
                continue;
            }
            int tmpa=cars[i].start, tmpb=cars[i].endd;
            if(spd[j+1]>tmpb&&spd[j]>tmpa&&spd[j]<tmpb){
                ans++;
                for(;;){
                    if(spd[j]>tmpa&&spd[j]<tmpb)
                        j++;
                    else
                        break;
                }
            }
            i++;
        }
    }
}
