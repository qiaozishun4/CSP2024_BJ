#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
struct car{
    double left,right;
}cars[MAXN];

bool cmp(car a, car b){
    return a.left<b.left;
}

int cnt = 0;
int detectors[MAXN];

bool inRange(int car, int detector){
    return cars[car].right>=detectors[detector] and cars[car].left <= detectors[detector];
}


int n,m,V;

int get_detected_cars(){
    int indexC = 1;
    int detector_position;
    int detected_count = 0;
    for(int i=0;i<m;i++){
        cin>>detector_position;
        detector_position = detectors[i];
        while(cars[indexC].right < detector_position and indexC<=cnt){
            indexC++;
        }
        while(cars[indexC].right>=detector_position and cars[indexC].left <= detector_position and indexC<=cnt){
            indexC++;
            detected_count++;
        }
    }
    return detected_count;
}
int true_ans, maximum_depth=0;
void dp(int depth){
    if(get_detected_cars() == true_ans){
        maximum_depth = max(depth,maximum_depth);
    }
    else{
        return;
    }
    int temp;
    for(int i = 0; i<m;i++){
        if(detectors[i] == -1) continue;
        temp = detectors[i];
        detectors[i] = -1;
        dp(depth+1);
        detectors[i] = temp;
    }
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    double L;
    double left, right;
    int d,v,a;
    for(int t=0;t<T;t++){
        cin>>n>>m>>L>>V;
        for(int i = 0; i<n; i++){
            cin>>d>>v>>a;

            if(a == 0){
                if(v>V){
                    left = d;
                    right = L;
                }
                else{
                    left = right = -1;
                }
            }

            else if(a > 0){
                if(v>V){
                    left = d;
                    right = L;
                }
                else{
                    if(d + v*(V-v)/a+ 0.5*(V-v)*(V-v)/a > L){
                        left = right = -1;
                    }
                    else{
                            left = d + v*(V-v)/a+ 0.5*(V-v)*(V-v)/a;
                            right = L;
                    }
                }
            }
            else{
                if(v>V){
                    left = d;
                    right = min(d + v*(V-v)/a+ 0.5*(V-v)*(V-v)/a,L);
                }
                else{
                    left = right = -1;
                }

            }

            cars[++cnt] = {left,right};

            }//car initiation loop
        sort(cars+1,cars+cnt,cmp);
        for(int i=1;i<=cnt;i++){
            cout<<cars[i].left<<" "<<cars[i].right<<endl;
        }


        for(int i=0;i<m;i++) cin>>detectors[i];
        true_ans = get_detected_cars();
        dp(0);
        cout<<true_ans<<" "<<m-maximum_depth<<endl;

        }// T loop


}//outer loop


