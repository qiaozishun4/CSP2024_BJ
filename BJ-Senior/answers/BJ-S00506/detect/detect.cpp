#include<bits/stdc++.h>

using namespace std;

int t;
int n,m,l,v,p;
struct car{
    int d;
    int v;
    int a;

    bool operator<(const car& other) const{
        return d > other.d;
    }

};

double calculateLastSpeed(car c,vector<int> ps){
    return sqrt(c.v*c.v+2*c.a*(ps[m-1]-c.d));
}
double calculateCurrentSpeed(car c,vector<int> ps,int current){
    return sqrt(c.v*c.v+2*c.a*(ps[current]-c.d));
}
int calculateUpLimit(car c,vector<int> ps,int v){
    double d = c.d-(c.v*c.v-v*v)/(2*c.a);
    int l = 0;
    int r = m-1;
    int mid = (l+r)/2;
    while(l < r){
        mid = (l+r)/2;
        if(ps[mid] >= d){
            r = mid;
        }
        if(ps[mid] < d){
            l = mid+1;
        }
    }
    return l;
}
int calculateLowLimit(car c,vector<int> ps,int v){
    if(c.v < v){
        return -1;
    }
    double d = c.d;
    int l = 0;
    int r = m-1;
    int mid = (l+r)/2;
    while(l < r){
        mid = (l+r)/2;
        if(ps[mid] >= d){
            r = mid;
        }
        if(ps[mid] < d){
            l = mid+1;
        }
    }
    double v2 = sqrt(c.v*c.v+2*c.a*(ps[l]-c.d));
    if(v2 < v){
        return -1;
    }
    return l;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    vector<car> cars;
    vector<int> ps;
    while(t>0){
        t--;
        cars.clear();
        ps.clear();

        cin>>n>>m>>l>>v;
        int d1,v1,a1;
        for(int i = 0;i < n;i++){
            cin>>d1>>v1>>a1;
            cars.push_back({d1,v1,a1});
        }
        sort(cars.begin(),cars.end());
        for(int i = 0;i < m;i++){
            cin>>p;
            ps.push_back(p);
        }
        sort(ps.begin(),ps.end());
        int lastIndex = m-1;
        int firstIndex=-1;
        bool flag = true;
        int counter1=0, counter2 = 0;
        for(int i = 0;i < n;i++){
            if(cars[i].d > ps[m-1]){
                continue;
            }
            if(cars[i].a == 0){
                if(cars[i].v > v){
                    counter1++;

                }
            }else if(cars[i].a > 0){
                if(calculateLastSpeed(cars[i],ps) > v){
                    counter1++;
                }
            }else{
                if(calculateLowLimit(cars[i],ps,v) == -1){
                    continue;
                }else{

                    if(lastIndex <= calculateUpLimit(cars[i],ps,v)){
                        counter1++;
                    }else{
                        lastIndex = calculateLowLimit(cars[i],ps,v);
                        counter1++;
                        counter2++;
                        if(flag){
                            firstIndex = calculateLowLimit(cars[i],ps,v);
                            flag = false;
                        }

                    }
                }


            }
        }

        cout<<counter1<<" "<<m-counter2<<endl;

    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}






