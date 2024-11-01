#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int t,n,m,l,nid[1000005],pid[1000005],cnt;
long long pre[1000005],nxt[1000005],p[100005],d[100005],v[100005],a[100005],vlmt;
struct node{
    int st,fn;
}c[100005];
bool cmp(node a1,node a2){
    return a1.st<a2.st;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    p[0]=-1;
    cin >> t;
    while(t--){
        cin >> n >> m >> l >> vlmt;
        for(int i = 1;i <= n;i++){
            cin >> d[i] >> v[i] >> a[i];
        }
        for(int i = 1;i <= m;i++){
            cin >> p[i];
            for(int j = p[i];j > p[i-1];j--){
                nxt[j]=p[i];
                nid[j]=i;
            }
        }
        for(int i = l;i > p[m];i--){
            nxt[i]=-1;
            nid[i]=-1;
        }
        p[m+1]=l+1;
        for(int i = m;i >= 1;i--){
            for(int j = p[i];j < p[i+1];j++){
                pid[j]=i;
            }
        }
        cnt=0;
        for(int i = 1;i <= n;i++){
            if(a[i]<0){
                if(v[i]<=vlmt){
                    c[i].st=c[i].fn=1000000000;
                    continue;
                }
                long long fz=v[i]*v[i]-vlmt*vlmt,fm=-2*a[i];
                fz--;
                fz/=fm;
                if(nxt[d[i]]>=0 && nxt[d[i]]<=fz+d[i]){
                    cnt++;
                    c[i].st=nid[d[i]];
                    c[i].fn=pid[min(fz+d[i],(long long)(l))];
                }
                else{
                    c[i].st=c[i].fn=1000000000;
                }
            }
            else{
                if(v[i]>vlmt){
                    if(nxt[d[i]]!=-1){
                        cnt++;
                        c[i].st=nid[d[i]];
                        c[i].fn=pid[l];
                    }
                    else{
                        c[i].st=c[i].fn=1000000000;
                    }
                }
                else{
                    if(a[i]==0){
                        c[i].st=c[i].fn=1000000000;
                    }
                    else{
                        long long fz=vlmt*vlmt-v[i]*v[i],fm=2*a[i];
                        fz/=fm;
                        fz++;
                        if(fz+d[i]<=l && nxt[fz+d[i]]!=-1){
                            cnt++;
                            c[i].st=nid[fz+d[i]];
                            c[i].fn=pid[l];
                        }
                        else{
                            c[i].st=c[i].fn=1000000000;
                        }
                    }
                }
            }
        }
        cout << cnt << " ";
        sort(c+1,c+n+1,cmp);
        int lst=-1;
        cnt=0;
        for(int i = 1;i <= n;i++){
            //cout << c[i].st << " " << c[i].fn << "  ";
            if(c[i].st==1000000000) break;
            if(c[i].st>lst){
                cnt++;
                lst=c[i].fn;
            }
            else{
                lst=min(lst,c[i].fn);
            }
        }
        cout << m-cnt << "\n";
    }
    return 0;
}
