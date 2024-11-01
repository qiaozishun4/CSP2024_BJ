#include<bits/stdc++.h>
#include<fstream>

using namespace std;

//check your file cin!!!!!open it when you send your program!!!!!!
//ifstream ofstream!!!!!!!

ifstream fin("detect.in");
ofstream fout("detect.out");
const int N = 1e5 + 10;
long long t,n,m,l,V,d[N],cnt,v[N],a[N],p[N],ans2,ans,last;
bool f1,f2,f3,f[N];
double cur = 0.00;
int main(){
    fin >> t;
    while(t --){
        ans = ans2 = 0;
        last = 0;
        cnt = 0;
        memset(f,false,sizeof(f));
        fin >> n >> m >> l >> V;
        f1 = f2 = f3 = true;
        for(int i = 1;i <= n;i ++){
            fin >> d[i] >> v[i] >> a[i];
            //f1: <0     f2:>0      f3:=0
            if(a[i] > 0){
                f1 = false;
            }
            if(a[i] < 0){
                f2 = false;
            }
            if(a[i] != 0){
                f3 = false;
            }
        }
        for(int i = 1;i <= m;i ++){
            fin >> p[i];
            last = max(last,p[i]);
        }
        if(f3 == true){
            for(int i = 1;i <= n;i ++){
                if(v[i] > V && d[i] <= last){
                    ans ++;
                }
            }
            fout << ans << " ";
        } else if(f2 == true){
            for(int i = 1;i <= n;i ++){
                //cur = double(V * V - v[i] * v[i]) / double(2 * a[i]);
                if(last < d[i]){
                    continue;
                }
                if(v[i] > V && d[i] <= last){
                    ans ++;
                } else if((((V + v[i]) * (V - v[i]) + (2 * a[i] * d[i])) < (last * 2 * a[i]))){
                    ans ++;
                }
            }
            fout << ans << " ";
        } else {
            for(int i = 1;i <= m;i ++){
                for(int j = 1;j <= n;j ++){
                    if(p[i] < d[j] || f[j] == true){
                        continue;
                    }
                    cur = sqrt(v[j] * v[j] + 2 * a[j] * (p[i] - d[j]));
                    if(cur > V){
                        ans ++;
                        f[j] = true;
                    }
                }
            }
            fout << ans << " ";
        }
        if(ans == 0){
            fout << m << endl;
            continue;
        }
        if(f2 == true || f3 == true){
            ans2 = m - 1;
        }
        fout << ans2 << endl;
    }
    return 0;
}