#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

typedef long long LL;

using namespace std;

const int N = 1e5+5;

int T;
int n,m,L,V;

int tot = 0;
struct over_range{   //beyond the speed
    LL l,r;
    bool operator < (const over_range& a) const{
        if(r != a.r) return r < a.r;
        return l < a.l;
    }
    bool operator > (const over_range& a) const{
        if(r != a.r) return r > a.r;
        return l > a.l;
    }
};
over_range calc(int d0,int v0,int a){   //calculate the range of over_speed
    if(a > 0){
        if(v0 > V) return over_range{d0,L};
        LL l = (V*V-v0*v0)/2/a;
        if(l < (V*V-v0*v0)/2.0/a) l++;  //make it upper
        return over_range{l+d0,L};
    }
    if(a < 0){
        if(v0 < V) return over_range{L+1,L+1};
        LL r = (V*V-v0*v0)/2/a;
        return over_range{d0,d0+r};
    }
    if(a == 0){
        if(v0 <= V) return over_range{L+1,L+1};
        else return over_range{d0,L};
    }
}

struct car{
    int d,v,a;
}c[N];

int detect[N];
bool cmp(int a,int b){return a<b;}  //smaller -> bigger

int anscar = 0, ansdel = 0;

priority_queue<over_range, vector<over_range>, greater<over_range> > q;    //dagendui, the end lefter the fronter
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        while(q.size()) q.pop();
        memset(detect,0,sizeof(detect));
        memset(c,0,sizeof(c));
        scanf("%d%d%d%d",&n,&m,&L,&V);
        ansdel = m;
        anscar = 0;
        for(int i = 1;i <= n;i++){
            scanf("%d%d%d",&c[i].d,&c[i].v,&c[i].a);    //d, v0, a
            over_range ra = calc(c[i].d,c[i].v,c[i].a);    //range
            //printf("[%d,%d]\n",ra.l,ra.r);
            if(ra.l <= L) q.push(ra);
        }
        for(int i = 1;i <= m;i++){
            scanf("%d",&detect[i]);
        }
        sort(detect+1,detect+m+1,cmp);

        LL last_detector = 0;
        for(int i = 1;i <= m;i++){
            while(q.size() && q.top().r < detect[i]){   //it cannot be detected
                //printf("[%d,%d]out\n",q.top().l,q.top().r);
                q.pop();
            }

            while(q.size() && q.top().l <= last_detector && last_detector <= q.top().r){    //use the last detector to detect
                //printf("[%d,%d]is detected\n",q.top().l, q.top().r);
                q.pop();
                anscar++;
            }

            while(q.top().l <= detect[i+1] && detect[i+1] <= q.top().r) i++;
            //printf("last:%d:[%d,%d], %d, %d, %d\n",last_detector,q.top().l, q.top().r, q.size(),q.top().l <= last_detector,last_detector <= q.top().r);

            //printf("%d:[%d,%d]\n",detect[i],q.top().l, q.top().r);
            if(q.size() && q.top().l <= detect[i] && detect[i] <= q.top().r){
                ansdel--; //this monitor cannot be removed
                last_detector = detect[i];
                //printf("%d cannot be deleted\n",detect[i]);
            }
            while(q.size() && q.top().l <= detect[i] && detect[i] <= q.top().r){
                //printf("[%d,%d]is detected\n",q.top().l, q.top().r);
                q.pop();
                anscar++;
            }
        }
        printf("%d %d\n",anscar,ansdel);
    }
    return 0;
}
