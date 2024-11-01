#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
int t;
int n,m,L,V;
int b[N],c[N],f[1000001];
struct node1{
    int d,v,a,f,f1,f2;
}a[N];
struct node2{
    int x,f;
}bl[N];
int ans1,ans2;

bool cmp(node2 x,node2 y){
    return x.f < y.f;
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
        cin>>n>>m>>L>>V;
        for(int i = 0;i < n;i++)
            cin>>a[i].d>>a[i].v>>a[i].a;
        for(int i = 0;i < m;i++){
            cin>>b[i];
        }
        b[m] = 1e9;
        double s;
        int x;
        ans1 = 0;
        ans2 = 0;
        for(int i = 0;i <= m;i++){
            c[i] = 0;
        }
        x = 0;
        for(int i = 0 ;i <= L;i++){
            f[i] = x;
            if(i == b[x])
                x++;
        }
        for(int i = 0;i < n;i++){
            a[i].f = 0;
            a[i].f1 = m;
            a[i].f2 = m;
            if(a[i].a < 0){
                if(a[i].v <= V)
                    continue;
                else{
                    a[i].f1 = f[a[i].d];
                    c[a[i].f1]++;
                    s = (1.0*V*V-a[i].v*a[i].v)/(2*a[i].a);
                    if(int(s) != s){
                        a[i].f2 = int(s)+1+a[i].d <= L ? f[int(s)+1+a[i].d] : m;
                    }else{
                        a[i].f2 = int(s)+a[i].d <= L ? f[int(s)+a[i].d] : m;
                    }
                    c[a[i].f2]--;
                    a[i].f = a[i].f2-a[i].f1;
                }
            }
            if(a[i].a == 0){
                if(a[i].v <= V)
                    continue;
                else{
                    a[i].f1 = f[a[i].d];
                    c[a[i].f1]++;
                    a[i].f = m-a[i].f1;
                }
            }
            if(a[i].a > 0){
                if(a[i].v > V){
                    a[i].f1 = f[a[i].d];
                    c[a[i].f1]++;
                }else{
                    s = (1.0*V*V-a[i].v*a[i].v)/(2*a[i].a);
                    a[i].f1 = int(s)+a[i].d+1 <= L ? f[int(s)+a[i].d+1] : m;
                    c[a[i].f1]++;
                }
                a[i].f = m-a[i].f1;
            }
            if(a[i].f){
                ans1++;
            }
        }
        bl[0].f = c[0];
        bl[0].x = 0;
        for(int i = 1;i < m;i++){
            bl[i].f = bl[i-1].f+c[i];
            bl[i].x = i;
        }
        sort(bl,bl+m,cmp);
        bool vis;
        for(int i = 0;i < m;i++){
            vis = true;
            for(int j = 0;j < n;j++){
                if(bl[i].x >= a[j].f1 && bl[i].x < a[j].f2){
                    if(a[j].f == 1){
                        vis = false;
                        break;
                    }
                }
            }
            if(vis){
                ans2++;
                for(int j = 0;j < n;j++){
                    if(bl[i].x >= a[j].f1 && bl[i].x < a[j].f2){
                        a[j].f--;
                    }
                }
            }
        }
        cout<<ans1<<' '<<ans2<<'\n';
	}
	return 0;
}
