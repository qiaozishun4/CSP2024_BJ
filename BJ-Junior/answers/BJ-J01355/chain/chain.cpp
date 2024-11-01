#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

struct query{
    int r,c,id;
    bool operator<(query a)const{
        return r < a.r;
    }
};

vector<query> q;
int n,k,Q;
bool isvalid[200005],tmp[100005],ans[100005];
vector<int> s[100005];

void update(int r,int lst){
    memset(tmp,0,sizeof(tmp));
    int limit = 0;
    for(int j = 1; j <= n; j++){
        if(j == lst){
            continue;
        }
        for(int i = 0; i < s[j].size(); i++){
            if(isvalid[s[j][i]]){
                limit = i+k;
            }
            else if(i<limit){
                tmp[s[j][i]] = 1;
            }
        }
    }
    for(int i = 0; i <= 200000; i++){
        isvalid[i] = tmp[i];
    }
}

void out(){
    for(int i = 0; i < 10; i++){
        cout << isvalid[i] << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        memset(isvalid,0,sizeof(isvalid));
        cin >> n >> k >> Q;
        for(int i = 1; i <= n; i++){
            int l;
            cin >> l;
            while(l--){
                int x;
                cin >> x;
                s[i].push_back(x);
            }
        }
        q.resize(Q);
        for(int i = 0; i < Q; i++){
            cin >> q[i].r >> q[i].c;
            q[i].id = i;
        }
        sort(q.begin(),q.end());
        int mx = q[Q-1].r,lst = 1,limit = 0,nowq = 0;
        for(int i = 0; i <s[1].size(); i++){
            if(s[1][i] == 1){
                limit = i+k;
            }
            else if(i<limit){
                isvalid[s[1][i]] = 1;
            }
        }//out();
        for(int j = nowq; q[j].r <= 1 && j < Q; j++){
                ans[q[j].id] = isvalid[q[j].c];
        }
        for(int i = 2; i <= mx; i++){
            update(i,lst);
            //out();
            for(int j = nowq; q[j].r <= i && j < Q; j++){
                //if(q[j].r == 1){
                    //ans[q[j].id] = 0;
                //}
                //else{
                    ans[q[j].id] = isvalid[q[j].c];
                //
                nowq++;
            }
        }
        for(int i = 0; i < Q; i++){
            cout << ans[i] << endl;
        }
    }
    return 0;
}
