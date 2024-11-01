#include <iostream>
#include <set>

using namespace std;

const int N = 1e5+5;

int n,m;
int T;
int oa[N];    //original_a
int a[N];   //actually a
int c[N];   //requests
int K = 0;
bool d[20][N];
int X[10];
bool lg2[N];

int findk(int x){
    int k = 0;
    while(1<<k < x) k++;
    return k;
}

int k;
int res;
set<int> s;
void dfs(){ //2^k people joined in the competition
    set<int>::iterator it;
    int i = 1;
    int r = 1;
    int g = 1;
    //round 1
    for(it = s.begin();it != s.end();it++){
        if(lg2[i]){    //(2^i)-1 vs 2^i
            it--;
            int p1 = *it;
            s.erase(it,it);
            it++;
            int p2 = *it;
            s.erase(it,it);
            //cout << p1 << p2 << endl;
            if(!d[r][g]){   //the smaller become the defence
                if(a[p1] >= r){    //p1 win
                    s.insert(p1);
                }
                else s.insert(p2);
            }
            else{
                if(a[p2] >= r) s.insert(p2);
                else s.insert(p1);
            }
            g++;
        }
        i++;
    }
    it = s.begin();
    //other ronunds
    while(s.size() > 1){
        r++;
        g = 1;
        for(it = s.begin();it != s.end();it++,g++){
            int p1 = *it;
            s.erase(it,it);
            it++;
            int p2 = *it;
            //cout << p1 << p2 <<endl;
            s.erase(it,it);
            if(!d[r][g]){
                if(a[p1] >= r) s.insert(p1);
                else s.insert(p2);
            }
            else{
                if(a[p2] >= r) s.insert(p2);
                else s.insert(p1);
            }
        }
    }
}

int ans = 0;

int main()
{
    freopen("arena.in","r",stdin);
    //freopen("arena.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++) scanf("%d",&oa[i]);
    for(int i = 1;i <= m;i++) scanf("%d",&c[i]);
    K = findk(n);
    for(int i = 1;i <= K;i++) lg2[1<<i] = 1;
    for(int r = 1;r <= K;r++){
        for(int g = 1;g <= 1<<(K-r);g++){
            char temp;
            cin >> temp;
            d[r][g] = int(temp-'0');
        }
    }
    scanf("%d",&T);
    while(T--){
        ans = 0;
        scanf("%d%d%d%d",&X[0],&X[1],&X[2],&X[3]);
        for(int i = 1;i <= n;i++){
            //printf("%d^%d=",oa[i],X[i%4]);
            a[i] = oa[i] ^ X[i%4];
            //printf("%d ",a[i]);
            s.insert(i);
        }
        //puts("");
        for(int i = 1;i <= m;i++){
            if(c[i] == 1) ans ^= i*1;
            else{
                k = findk(c[i]);
                dfs();
                ans ^= i*res;
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}
