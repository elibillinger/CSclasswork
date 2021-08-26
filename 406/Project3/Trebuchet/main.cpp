#include <iostream>
#include <vector>
#include <algorithm>
//#include <chrono>
using namespace std::chrono;
using namespace std;
int minimum;

int trebuchetRecursive(int p, int t){
    if(p == 1){
        return t;
    } else if( t == 0){
        return 0;
    } else if ( t == 1){
        return 1;
    } else {
        vector<int> maxValues;
        for(int x = 1; x <= t; x++) {
            maxValues.push_back(max(trebuchetRecursive(p - 1, x - 1), trebuchetRecursive(p, t - x)));
        }
        return 1 + *min_element(maxValues.begin(), maxValues.end());
    }
}

vector<vector<pair<int,bool>>> traceDP(int p, int t){
    int dpTable[p+1][t+1];
    vector<vector<pair<int,bool>>> traceback;
    pair<int,bool> temp;
    for(int i = 1; i <= p; i++){
        vector<pair<int,bool>> v;
        for( int j = 0; j <= t; j++){
            if(i == 1 || j == 0 || j == 1){
                dpTable[i][j] = j;
                if(j == 0 ){
                    temp.first = 0;
                    temp.second = false;
                    v.push_back(temp);
                } else {
                    temp.first = 1;
                    temp.second = true;
                    v.push_back(temp);
                }
            } else {
                int k;
                if(j%2 == 0){
                    k = j/2;
                } else {
                    k = (j+1)/2;
                }
                for( int x = 1; x <= k; x++){
                    vector<int> m = {};
                    m.push_back(dpTable[i-1][j-x]);
                    m.push_back(dpTable[i][j-x]);
                    if( j % 2 == 1) {
                        m.push_back(max(dpTable[i - 1][j - (x+1)], dpTable[i][j - (x-1)]));
                    }
                    int min = 1 + *min_element(m.begin(),m.end());
                    if( min == dpTable[i-1][x-1] && i > 2){
                        temp.first = x;
                        temp.second = false;
                        v.push_back(temp);
                    }
                    if ( min == dpTable[i][j-x]){
                        temp.first = x;
                        temp.second = true;
                        v.push_back(temp);
                    }
                    if (dpTable[i][j-x] == dpTable[i-1][x-1]){
                        temp.first = x;
                        temp.second = true;
                        v.push_back(temp);
                    }
                    dpTable[i][j] = 1 + *min_element(m.begin(),m.end());
                }
            }
        }
        traceback.push_back(v);
    }
    minimum = dpTable[p][t];
    return traceback;
}

void tracebackFunction(int p, int t) {
    vector<vector<pair<int, bool>>> trace = traceDP(p, t);
    vector<int> targets;
//    for (int i = 0; i < trace.size(); i++) {
//        for (int j = 0; j < trace[i].size(); j++){
//            cout << trace[i][j].first << " ";
//    }
//        cout << endl;
//}
    p = p-1;
    t = t-1;
    int xT = 0;
    int x = trace[p][t].first;
    targets.clear();
    targets.push_back(x);
    int target = t + 1;
    int throws = minimum;
    while (throws > 0) {
        if (x > 0) {
            xT = trace[p][target-x].first;
        } else if (x < 0){
            xT = trace[p-1][t-x].first;
        }
        target = target-x;
        x = xT;
        targets.push_back(x);
        throws = throws - 1;
    }
    int total = 0;
    for( int i = 0; i < targets.size(); i++){
        total = total+targets[i];
        cout << total << " ";

    }
}

int tDP(int p, int t){
    int dpTable[p+1][t+1];
    for(int i = 1; i <= p; i++){
        for( int j = 0; j <= t; j++){
            if(i == 1 || j == 0 || j == 1){
                dpTable[i][j] = j;
            } else {
                vector<int> m = {};
                int k;
                if(j%2 == 0){
                    k = j/2;
                } else {
                    k = (j-1)/2;
                }
                for( int x = 1; x <= k; x++){
                    m.push_back(dpTable[i-1][j-x]);
                    m.push_back(dpTable[i][j-x]);
                    if( j % 2 == 1) {
                        m.push_back(max(dpTable[i - 1][j - (x+1)], dpTable[i][j - (x-1)]));
                    }
                }
                //cout << (1+ *min_element(m.begin(),m.end())) << " ";
                dpTable[i][j] = 1+ *min_element(m.begin(),m.end());
            }
        }
    }
//    for(int i = 1; i <= p; i++) {
//        for (int j = 0; j <= t; j++) {
//            cout << dpTable[i][j] << " ";
//        }
//        cout << endl;
//    }
    return dpTable[p][t];

}


int main() {
    //auto start = high_resolution_clock::now();
    //trebuchetRecursive(3,25);
    //tDP(2,5);
    //auto stop = high_resolution_clock::now();
   // auto duration = duration_cast<nanoseconds>(stop-start);
    //cout << "\nTime taken: " << duration.count()/1.0e9 << "s"<< endl;
    //cout << trebuchetRecursive(3,20) << endl;
    cout << tDP(2,2406) << endl;
    //tracebackFunction(5,100);
    return 0;
}
