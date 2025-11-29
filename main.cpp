#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N;
    cin >> N;
    vector<pair<int,int>> vec(N);

    for(int i = 0;i<N;i++){
        cin >> vec[i].first >> vec[i].second;
    }

    vector<int> vx(1000001,0);
    vector<int> vy(1000001,0);
    for(int i = 1;i<N;i++){
        if(vec[i].first == vec[i-1].first){
            if(vec[i].second >vec[i-1].second){
                vy[vec[i-1].second+500000]++;
                vy[vec[i].second+500000]--;
            }
            else{
                vy[vec[i-1].second+500000]--;
                vy[vec[i].second+500000]++;
            }
        }
        else{
            if(vec[i].first > vec[i-1].first){
                vx[vec[i-1].first+500000]++;
                vx[vec[i].first+500000]--;
            }
            else{
                vx[vec[i-1].first+500000]--;
                vx[vec[i].first+500000]++;
            }
        }
    }
    if(vec[0].first == vec[N-1].first){
        if(vec[0].second >vec[N-1].second){
            vy[vec[N-1].second+500000]++;
            vy[vec[0].second+500000]--;
        }
        else{
            vy[vec[N-1].second+500000]--;
            vy[vec[0].second+500000]++;
        }
    }
    else{
        if(vec[0].first > vec[N-1].first){
            vx[vec[N-1].first+500000]++;
            vx[vec[0].first+500000]--;
        }
        else{
            vx[vec[N-1].first+500000]--;
            vx[vec[0].first+500000]++;
        }
    }


    int mx = 0;
    int p1=vy[0];
    int p2=vx[0];
    for(int i = 1;i<1000001;i++){
        mx = max(mx,max(p1,p2));
        p1+=vy[i];
        p2+=vx[i];
    }
    cout << mx << "\n";
}
