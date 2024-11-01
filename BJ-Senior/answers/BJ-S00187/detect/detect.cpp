#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct speed{
    long long pos,l,r;
};
long long d[100010],v[100010],a[100010],p[100010];
long long watch1[1000010];
speed car[100010],car_[100010];

long long chu(long long a,long long b){
    if (a%b == 0){
        return (long long)(a/b);
    }
    else{
        return (long long)(a/b)+1;
    }
}

bool cmp(speed x,speed y){
    return x.l < y.l;
}

bool cmp_(speed x,speed y){
    return x.r < y.r;
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    long long T;
    cin>>T;
    for (long long Q = 1;Q <= T;Q++){
        //clear
        for (long long i = 1;i <= 1000005;i++){
            watch1[i] = -1;
        }

        long long n,m,L,V;
        cin>>n>>m>>L>>V;
        for (long long i = 1;i <= n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        long long M = 0;
        for (long long i = 1;i <= m;i++){
            cin>>p[i];
            while (M <= p[i]){
                watch1[M] = p[i];
                M++;
            }
        }
        long long ans1 = 0,k = 0;
        for (long long i = 1;i <= n;i++){
            if (v[i] > V && a[i] >= 0){
                if (watch1[d[i]] != -1){
                    ans1++;
                    car[k].l = d[i];
                    car[k].r = L;
                    k++;
                }
            }
            if (v[i] <= V && a[i] <= 0){
                continue;
            }
            if (v[i] <= V && a[i] > 0){
                if (d[i] + 1 + (long long)(((V-v[i])*(V-v[i])+2*v[i]*(V-v[i]))/(2*a[i])) <= L){
                    if (watch1[d[i] + (long long)(((V-v[i])*(V-v[i])+2*v[i]*(V-v[i]))/(2*a[i])) + 1] != -1){
                        ans1++;
                        car[k].l = d[i] + (long long)(((V-v[i])*(V-v[i])+2*v[i]*(V-v[i]))/(2*a[i])) + 1;
                        car[k].r = L;
                        k++;
                    }
                }
            }
            if (v[i] > V && a[i] < 0){
                if (d[i] + chu(((v[i]-V)*(v[i]-V)+2*v[i]*(v[i]-V)),(2*abs(a[i]))) <= L){
                    if (watch1[d[i]] < d[i] + chu((-(v[i]-V)*(v[i]-V)+2*v[i]*(v[i]-V)),(2*abs(a[i]))) && watch1[d[i]] != -1){
                        ans1++;
                        car[k].l = d[i];
                        car[k].r = d[i] + chu((-(v[i]-V)*(v[i]-V)+2*v[i]*(v[i]-V)),(2*abs(a[i]))) - 1;
                        k++;
                    }
                }
                else{
                    if (watch1[d[i]] != -1){
                        ans1++;
                        car[k].l = d[i];
                        car[k].r = L;
                        k++;
                    }
                }
            }
        }
        cout<<ans1<<" ";
        sort(car,car+k,cmp);
        for (long long i = 0;i < k;i++){
            car[i].pos = i;
            car_[i] = car[i];
        }
        sort(car_,car_+k,cmp_);
        long long ban_pos = 0,use_p = 1,ans2 = 0;
        for (long long i = 0;i < k;i++){
            if (car_[i].pos >= ban_pos){
                while (p[use_p+1] <= car_[i].r && use_p < m){
                    use_p++;
                }
                ans2++;
                while (car[ban_pos].l <= p[use_p] && ban_pos <= k){
                    ban_pos++;
                }
                use_p++;
            }
        }
        cout<<m-ans2<<endl;
    }
    return 0;
}
