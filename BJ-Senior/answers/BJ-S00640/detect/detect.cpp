#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
#define int long long
using namespace std;
const int N=1e5+5;
struct nd {
    int d,v,a;
} car[N] ;
int n,m,L,V,p[N];//qz[N];
void sol() {
    memset(car,0,sizeof car);
    memset(p,0,sizeof p);


    /*A*/ int maxp=0;

    bool A=1,B=1,C=1;

    cin>>n>>m>>L>>V;
    forr(i,1,n) {
        cin>>car[i].d>>car[i].v>>car[i].a;
        if(car[i].a!=0) A=0;
        if(car[i].a<=0) B=0;
    }
    forr(i,1,m) {
        cin>>p[i];
        maxp=max(maxp,p[i]);
    }

    //sort(p+1,p+1+m);
    //forr(i,p[1],p[m]) qz[i] = qz[i-1] + p[i];

    if(A) { // ok test 3
        int cnt=0;
        forr(i,1,n) {
            if(car[i].d <= maxp && car[i].v >V) cnt++;
        }
        cout<<cnt<<' ';
        if(cnt==0) cout<< m <<endl;
        else cout<< m-1 <<endl;
        return ;
    }
    if(B) { // ok test 4
        int cnt=0;
        forr(i,1,n) {
            if(car[i].d > maxp) continue;
            if(car[i].d == maxp) {
                if(car[i].v > V) cnt++;
                continue;
            }
            int wy = maxp-car[i].d;
            if( car[i].v * car[i].v + 2 * car[i].a * wy > V*V ) cnt++;
        }
        cout<<cnt<<' ';
        if(cnt==0) cout<< m <<endl;
        else cout<< m-1 <<endl;
        return ;
    }
    else { // low n,m
        sort(p+1,p+1+m);

        int cnt = 0;
        forr(i,1,n) {
            bool cs=0;
            forr(j,1,m) {
                if(p[j] < car[i].d) continue;
                else if(p[j] == car[i].d) {
                    if(car[i].v > V) {
                        cs=1;
                        break;
                    }
                } else {
                    int wy = p[j] - car[i].d;
                    if( car[i].v * car[i].v + 2 * car[i].a * wy > V*V ) {
                        cs=1;
                        break;
                    }
                }
            }
            if(cs==1) cnt++;
        }

        //////
        cout<<cnt<<' ';

        int T=(1<<m)-1,mincs=m;
        forr(i,1,T) {
            int p2[30]={0},tp2=1, k=i;
            forr(j,1,m) {
                if(k%2==1) {
                    p2[tp2] = p[j];
                    tp2++;
                }
                k /= 2;
            } tp2--;
            // p2 : all cs

            int cnt2 = 0;
            forr(i,1,n) {
                bool cs=0;
                forr(j,1,m) {
                    if(p2[j] < car[i].d) continue;
                    else if(p2[j] == car[i].d) {
                        if(car[i].v > V) {
                            cs=1;
                            break;
                        }
                    } else {
                        int wy = p2[j] - car[i].d;
                        if( car[i].v * car[i].v + 2 * car[i].a * wy > V*V ) {
                            cs=1;
                            break;
                        }
                    }
                }
                if(cs==1) cnt2++;
            }

            if(cnt == cnt2) mincs = min(mincs,tp2);
            // p2
        }
        cout << m-mincs << endl;
    }

    return ;
}




signed main() {
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    int T; cin>>T; while(T--) sol();return 0;}
