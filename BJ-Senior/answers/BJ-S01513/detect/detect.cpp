#include<bits/stdc++.h>
using namespace std;

struct node{
    int l,r;
}b[100010];
int T,n,m,l,V,p[100010],d[100010],v[100010],a[100010],ans1,blen,fa,fb,fc;

int fir1(int l,int r,double t){
    if(l == r){
        if(p[l] <= t){
            return 1919810;
        }
        return l;
    }
    int mid = (l + r) / 2;
    if(p[mid] > t){
        return fir1(l,mid,t);
    }else{
        return fir1(mid + 1,r,t);
    }
}

int fir2(int l,int r,double t){
    if(l == r){
        if(p[l] < t){
            return 1919810;
        }
        return l;
    }
    int mid = (l + r) / 2;
    if(p[mid] >= t){
        return fir2(l,mid,t);
    }else{
        return fir2(mid + 1,r,t);
    }
}

bool cmp(node n1,node n2){
    return n1.r < n2.r;
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    cin >> T;

    while(T--){
        ans1 = 0;
        blen = 0;
        fa = true;
        fb = true;
        fc = true;
        cin >> n >> m >> l >> V;
        for(int i = 1;i <= n;i++){
            cin >> d[i] >> v[i] >> a[i];
            if(a[i] == 0){
                fb = false;
                fc = false;
            }else if(a[i] > 0){
                fa = false;
                fc = false;
            }else{
                fb = false;
                fa = false;
            }
        }

        for(int i = 1;i <= m;i++){
            cin >> p[i];
        }

        for(int i = 1;i <= n;i++){
            double tstart,tend;
            if(a[i] == 0){
                if(v[i] <= V){
                    continue;
                }else{
                    int x = fir2(1,m,d[i]);
                    if(x != 1919810 && p[x] <= l){
 //                       cout << i << endl;
                        ans1++;
                        b[++blen] = {x,m};
                        continue;
                    }
                    continue;
                }
            }else if(a[i] > 0){
                tstart = d[i] + (V * V - v[i] * v[i]) / 2.0 / a[i];
                tend = l;
                if(tstart >= l){
                    continue;
                }else{
                    int x = fir1(1,m,tstart);
                    if(x != 1919810 && p[x] <= l){
//                        cout << i << endl;
                        ans1++;
                        b[++blen] = {x,m};
                        continue;
                    }else{
                        continue;
                    }
                }
            }else{
                if(v[i] <= V){
                    continue;
                }else{
                    tstart = d[i];
                    tend = d[i] + (V * V - v[i] * v[i]) / 2.0 / a[i];
                    int x = fir2(1,m,tstart);
                    if(x != 1919810 && p[x] < tend){
//                        cout << i << endl;
                        ans1++;
                        b[++blen] = {x,fir2(1,m,tend) - 1};
                        continue;
                    }
                }
            }
        }
        cout << ans1 << " ";
        if(fa){
//            cout << 114514 << endl;
            if(ans1 == 0){
                cout << m << endl;
            }else{
                cout << m - 1 << endl;
            }
        }else if(fb){
            if(ans1 == 0){
                cout << m << endl;
            }else{
                cout << m - 1 << endl;
            }
        }else{
            int ans2 = 0,c = 0;
            sort(b + 1,b + 1 + blen,cmp);
            for(int i = 1;i <= blen;i++){
                if(c < b[i].l){
                    ans2++;
                    c = b[i].r;
                }
            }
            cout << n - ans2 << endl;
        }
        /*else if(fc){
            int c = 0,ans2 = 0;
            sort(b + 1,b + 1 + blen,cmp);
            for(int i = 1;i <= blen;i++){
                if(c < b[i].l){
                    ans2++;
                    c = b[i].r;
                }
            }
            cout << ans2 << endl;
        }
        */
    }
    
    return 0;
}