#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
int t,n,ans=0;
int num[10] = {6,2,5,5,4,5,6,3,7,6};
struct node{
    bool z;
    string str;
    int v;
};
queue <node> q;
node alg(int n){
    while(!q.empty()){
        for(int i = 0;i<10;i++){
            if(q.front().v+num[i]==n){
                if(i == 0 && !q.front().z){
                    q.front().str += "0";
                    //cout<<q.front().str<<endl;
                    q.front().v += num[i];
                    return q.front();
                }
                else if(i == 1){
                    q.front().str += "1";
                    q.front().v += num[i];
                    return q.front();
                }
                else if(i == 2){
                    q.front().str += "2";
                    q.front().v += num[i];
                    return q.front();
                }
                else if(i == 3){
                    q.front().str += "3";
                    q.front().v += num[i];
                    return q.front();
                }
                else if(i == 4){
                    q.front().str += "4";
                    q.front().v += num[i];
                    return q.front();
                }
                else if(i == 5){
                    q.front().str += "5";
                    q.front().v += num[i];
                    return q.front();
                }
                else if(i == 6){
                    q.front().str += "6";
                    q.front().v += num[i];
                    return q.front();
                }
                else if(i == 7){
                    q.front().str += "7";
                    q.front().v += num[i];
                    return q.front();
                }
                else if(i == 8){
                    q.front().str += "8";
                    q.front().v += num[i];
                    return q.front();
                }
                else if(i == 9){
                    q.front().str += "9";
                    q.front().v += num[i];
                    return q.front();
                }
            }
            else if(q.front().v+num[i] < n){
                node tmp;
                tmp.str = q.front().str;
                tmp.z = q.front().z;
                if(i == 0 && !tmp.z){
                    tmp.str += "0";
                    tmp.v = q.front().v + num[i];
                    //cout<<q.front().str<<endl;
                }
                else if(i == 1){
                    tmp.str += "1";
                    tmp.z == 0;
                    tmp.v = q.front().v + num[i];
                }
                else if(i == 2){
                    tmp.str += "2";
                    tmp.z == 0;
                    tmp.v = q.front().v + num[i];
                }
                else if(i == 3){
                    tmp.str += "3";
                    tmp.z == 0;
                    tmp.v = q.front().v + num[i];
                }
                else if(i == 4){
                    tmp.str += "4";
                    tmp.z == 0;
                    tmp.v = q.front().v + num[i];
                }
                else if(i == 5){
                    tmp.str += "5";
                    tmp.z == 0;
                    tmp.v = q.front().v + num[i];
                }
                else if(i == 6){
                    tmp.str += "6";
                    tmp.z == 0;
                    tmp.v = q.front().v + num[i];
                }
                else if(i == 7){
                    tmp.str += "7";
                    tmp.z == 0;
                    tmp.v = q.front().v + num[i];
                }
                else if(i == 8){
                    tmp.str += "8";
                    tmp.z == 0;
                    tmp.v = q.front().v + num[i];
                }
                else if(i == 9){
                    tmp.str += "9";
                    tmp.z == 0;
                    tmp.v = q.front().v + num[i];
                }
                q.push(tmp);
                //cout<<tmp.str<<" "<<tmp.v<<endl;
            }
        }
        q.pop();
        //cout<<"pop"<<" "<<q.front().str<<" "<<q.front().v<<endl;
    }
    node fail;
    fail.v = 0;
    fail.str = "-1";
    return fail;
}
int main(){
    freopen("sticks.in","r",stdin);
    //freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        while(!q.empty())q.pop();
        cin>>n;
        node start;
        start.v = 0;
        start.str = "";
        start.z = 1;
        q.push(start);
        node ans  = alg(n);
        cout<<ans.str<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
