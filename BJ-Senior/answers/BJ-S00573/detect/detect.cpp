#include <iostream>

using namespace std;

struct c_e{
    int i;
    int v;
    int a;
};

struct c_r{
    int start;
    int ending;
    int* c_det;
};

void get_value(int cars,int v,int l,c_e* car_easy,c_r* car_res){
    float s,S;
    for(int i=0;i<cars;i++){
        if(car_easy[i].a>0){
            s=(v*v-car_easy[i].v*car_easy[i].v)/(2*car_easy[i].a);
            S=s+car_easy[i].i;
            if(S<l){
                car_res[i].start=S;
                car_res[i].ending=l;
            }
        }
        if(car_easy[i].a==0){
            if(car_easy[i].v>v){
                car_res[i].start=car_easy[i].i;
                car_res[i].ending=l;
            }
        }
        if(car_easy[i].a<0){
            if(car_easy[i].v>v){
                car_res[i].start=car_easy[i].i;
                s=(v*v-car_easy[i].v*car_easy[i].v)/(2*car_easy[i].a);
                S=s+car_easy[i].i;
                if(S<l){
                    car_res[i].ending=S;
                }
                else{
                    car_res[i].ending=l;
                }
            }
        }
    }
}

int get_det(int cars,int ces,c_r* car_res,int* det){
    int res;
    for(int i=0;i<cars;i++){
        if(car_res[i].start){
            int now=0;
            int* detecters=(int*)malloc(sizeof(int)*ces);
            for(int is=0;is<ces;is++){
                if(car_res[i].start<det[is] && det[is]<car_res[i].ending){
                    detecters[now]=is;
                    now++;
                }
            }
            car_res[i].c_det=detecters;
            if(detecters[0]){
                res++;
            }
            if(detecters[0]==0){
                res++;
            }
        }
    }
    return res;
}

int get_res(int cars,int ces,c_r* car_res){
    int res=0;
    for(int i=0;i<ces;i++){
        int state=0;
        for(int is=0;is<cars;is++){
            state=0;
            if(car_res[is].c_det){
                if(car_res[is].c_det[0]){
                    int z=0;
                    while(car_res[is].c_det[z]){
                        if(car_res[is].c_det[z] != i && car_res[is].c_det[z] != -1){
                            state=1;
                            break;
                        }
                        z++;
                    }
                }
                else{
                    state=1;
                }
            }
            else{
                state=1;
            }
            if(state==0){
                break;
            }
        }
        if(state==1){
            res++;
            for(int iss=0;iss<cars;iss++){
                if(car_res[iss].c_det){
                    int xxx=0;
                    while(car_res[iss].c_det[xxx]){
                        if(car_res[iss].c_det[xxx]==i){
                            car_res[iss].c_det[xxx]=-1;
                        }
                    }
                }
            }
        }
    }
    return res;
}

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        int cars,ces,l,v;
        cin>>cars>>ces>>l>>v;
        c_e* car_easy=(c_e*)malloc(sizeof(c_e)*cars);
        c_r* car_res=(c_r*)malloc(sizeof(c_r)*cars);
        int* det=(int*)malloc(sizeof(int)*v);
        for(int is;is<cars;is++){
            cin>>car_easy[is].i;
            cin>>car_easy[is].v;
            cin>>car_easy[is].a;
        }
        for(int is;is<v;is++){
            cin>>det[is];
        }
        get_value(cars,v,l,car_easy,car_res);
        int res_one,res_two;
        res_one=get_det(cars,ces,car_res,det);
        res_two=get_res(cars,ces,car_res);
        cout<<res_one<<" "<<res_two-2<<endl;
        for(int is;is<cars;is++){
            free(car_res[is].c_det);
        }
        free(car_easy);
        free(car_res);
    }
    return 0;
}