#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <ctype.h>

using namespace std;
string removeWSAndUCSort(const string &str){
    string temp = "";
    for(char i : str){
        if(i!=' ') temp += toupper(i);
    }
    sort(temp.begin(), temp.end());
    return temp;
}

vector<string> anagrams(vector<string> phrases) {
    string temp1, temp2;

    for(int i=0; i<phrases.size(); i++){
        temp1 = removeWSAndUCSort(phrases[i]);
        for(int j=i+1; j<phrases.size(); j++){
            temp2 = removeWSAndUCSort(phrases[j]);
            if(temp1 == temp2){
                phrases.erase(j+phrases.begin());
                j--;
            }
        }
    }

    return phrases;
}

int how_many(vector<string> headlines, vector<string> messages) {
    int counter = 0;
    vector<char> letters_headlines;
    for(string word: headlines){
        for(char c: word) {
            letters_headlines.push_back(tolower(c));
        }
    }
    vector<char> temp = letters_headlines;
    vector<char> letters;
    for(string w: messages){
        for(char c: w) {
            if(c != ' ') letters.push_back(tolower(c));
        }
        int count = 0;
        for(char l: letters) {

            for (char & letters_headline : letters_headlines) {
                if (l == letters_headline) {
                    letters_headline = ' ';
                    count += 1;
                    break;
                }
            }
        }

        if( letters.size() == count){
            counter += 1;
            letters.clear();
        } else{
            letters.clear();
        }
        letters_headlines = temp;
    }
    return counter;
}


int snowy_highway_length(vector<int> &start_points, vector<int> &end_points) {
    int mymin = *min_element(start_points.begin(), start_points.end());
    int mymax = *max_element(end_points.begin(), end_points.end());
    vector <int> road(mymax-mymin, 0);
    for(int i=0; i<start_points.size(); ++i){
        for(int j=start_points[i]; j<end_points[i]; ++j)
            road[j-mymin] = 1;
    }
    int ans = 0;
    for(int i : road)
        ans += i;
    return ans;
}

int possible_payments(int bill, int cash) {
//    vector<int> payment;
//    int count = 0;
//    int tip_possibility = cash-bill;
//    for(int i = 1; i <= tip_possibility; i++){
//        bill += i;
//        if(bill % 5 == 0){
//           payment.push_back(bill);
//        }
//        bill -= i;
//    }
//    for(int n: payment){
//        double tip = n-bill;
//        tip = tip/bill;
//        if(tip >= 0.05 && tip <= 0.1 ){
//            count+=1;
//        }
//    }
//    return count;


    int temp = bill;
    int count = 0;
    int tip_possibility = cash - bill;
    for (int t = 0; t <= tip_possibility; t++) {
        int total = t + bill;
        double tip = (t / total);
        if (tip >= 0.05 && tip <= 0.1 && total % 5 == 0) {
            count += 1;
        }
    }
    return count;

}


int main() {
//    vector<string> test = { "Aaagmnrs", "TopCoder", "anagrams", "Drop Cote" };
//    vector<string>result = anagrams(test);
//    for(string s: result){
//        cout << s << endl;
//    }
//    vector<string> headlines = {"Earthquake in San Francisco",
//                                "Burglary at musuem in Sweden",
//                                "Poverty"};
//    vector<string> messages = {"Give me my money back",
//                               "I am the best coder",
//                               "TOPCODER"};
//    cout << how_many(headlines,messages);
    vector<int>start_points = {45,100,125,10,15,35,30,9};
    vector<int>end_points= {46,200,175,20,25,45,40,10};
    cout << snowy_highway_length(start_points,end_points);
    //cout << possible_payments(1234567,12345678);
}
