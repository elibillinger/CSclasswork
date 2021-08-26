#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <chrono>


using namespace std;
using namespace std::chrono;

//Powerset function from https://www.techiedelight.com/generate-power-set-given-set/
// Has time complexity of O(n2^n)
vector<vector<pair<int,int>>> PowerSet (vector<pair<int,int>> const &items,int n){
    vector<vector<pair<int,int>>> set;
    vector<pair<int,int>> temp;
    int N = pow(2,n); //number of subsets
    for( int i = 0; i < N; i++){
        temp = {};
        for (int j = 0; j < n; j++){
            if ( i & (1 << j)) {
                int temp1,temp2;
                temp1 = items[j].first;
                temp2 = items[j].second;
                temp.emplace_back(temp1,temp2);
            }
        }
        set.push_back(temp);
    }
    return set;
}
//Exhaustive Solution
vector<pair<int,int>> Exhaustive (int w, int n, vector<pair<int,int>> items){
    vector<pair<int,int>> knapsack;
    vector<vector<pair<int,int>>> powerSet;
    powerSet = PowerSet(items,n);
    int bestValue = 0;
    for(vector<pair<int,int>> subset: powerSet){
        int subsetValue = 0,subsetWeight = 0;
        for( pair<int,int> item: subset){
            subsetValue += item.second;
            subsetWeight += item.first;
            if(subsetWeight <= w && subsetValue >= bestValue){
                bestValue = subsetValue;
                knapsack = subset;
            }
        }
    }
    return knapsack;
}

//Sort by weight/value
bool VWSort (const pair<int,int> &a, const pair<int,int> &b){
    double aWV = (double)a.second / (double)a.first;
    double bWV = (double)b.second / (double)b.first;
    if(bWV != aWV){
        return aWV > bWV;
    } else if (bWV == aWV){
        return a.second > b.second;
    }

}
// Heuristic Solution
vector<pair<int,int>> Heuristic(int W, int n, vector<pair<int,int>> items){
    vector<pair<int,int>> knapsack;
    int currentW = W;
    int valueFinal = 0;
    sort(items.begin(), items.end(),VWSort);
    for (pair<int,int> item : items){
        if(item.first <= currentW){
            knapsack.push_back(item);
            currentW = currentW - item.first;
            valueFinal += item.second;
        }
    }
    return knapsack;
}

int main() {
    int weightCapacity,itemNum;
    vector<pair<int,int>> items;
    vector<pair<int,int>> knapsack;
    // read input file
    ifstream input("input.txt");
    if (input.fail()) {
        cerr << "Could not open 'input.txt' " << endl;
    }
    input >> weightCapacity;
    input >> itemNum;
    int temp1,temp2;
    while(!input.eof()){
        input >> temp1;
        input >> temp2;
        items.emplace_back(temp1,temp2);
    }

    auto start = high_resolution_clock::now();
    //knapsack = Exhaustive(weightCapacity,itemNum,items);
    knapsack = Heuristic(weightCapacity,itemNum,items);
    auto stop = high_resolution_clock::now();

// output value and which items
//    int temp = 0;
//    for(int i = 0; i < knapsack.size(); i++){
//        temp += knapsack[i].second;
//    }
//    cout << temp << endl;
//    for(pair<int,int> i: knapsack){
//        int counter = 1;
//        for(pair<int,int> j: items){
//            if(j == i){
//                cout << counter << " ";
//            }
//            counter++;
//        }
//    }
    //output time
    auto duration = duration_cast<nanoseconds>(stop-start);
    cout << "\nTime taken: " << duration.count()/1.0e9 << "s"<< endl;



    return 0;
}
