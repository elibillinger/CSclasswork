#include <iostream>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
//string Josephus(vector<string> guests, int M) {
//    queue<string> guest;
//    queue<string> update;
//    int counter = 0;
//    for( int i = 0; i < guests.size(); i++){
//        guest.push(guests[i]);
//    }
//    while(guest.size()> 1){
//        counter += 1;
//        if(counter == M){
//            guest.pop();
//            counter = 0;
//        } else {
//            guest.push(guest.front());
//            guest.pop();
//        }
//    }
//    return guest.front();
//}


string encrypt(string message){
//    string alphabet = "abcdefghijklmnopqrstuvwxyz";
//    set<char> messageLetters (message.begin(),message.end());
//    vector<char> messageEncrypt;
//    vector<char> update;
//    for( char letter : message){
//        messageEncrypt.push_back(letter);
//    }
//    for(char letter: messageLetters){
//        auto temp = find(messageEncrypt.begin(),messageEncrypt.end(),letter);
//        if(temp != messageEncrypt.end()){
//
//        }
//    }
//    for (int i = 0; i < messageEncrypt.size(); i++){
//
//    }
//
//
//    return "the";
//    string encrypt;
//    char alphabet[26];
//    for(char & i : alphabet){
//        i='0';
//    }
//
//    char letter = 'a';
//    for(char & i : message){
//        if(alphabet[(int)(i-'a')]=='0'){
//            alphabet[(int)(i-'a')]=letter;
//            letter += 1;
//        }
//    }
//    for (char & i : message){
//        letter=alphabet[(int)(i - 'a')];
//        encrypt.push_back(letter);
//    }
//    return encrypt;
}
//bool is_valid(string expr, string left, string right) { // 9/10
//    queue<char> equation;
//    vector<char> dilimiter;
//    for (char & i : left){
//        dilimiter.push_back(i);
//    }
//    for (char & i : right){
//        dilimiter.push_back(i);
//    }
//    for ( int j = 0; j < expr.size(); j ++){
//        for ( int k = 0; k < dilimiter.size(); k++) {
//            if (expr[j] == dilimiter[k]) {
//                equation.push(expr[j]);
//            }
//        }
//    }
//    if(equation.size()%2 == 0){
//        return true;
//    } else{
//        return false;
//    }
//}
//vector<string> whos_dishonest(vector<string> &club1,
//                              vector<string> &club2,
//                              vector<string> &club3) {
//    vector<string> multiClub;
//    set<string>clubOne(club1.begin(),club1.end());
//    set<string>clubTwo(club2.begin(),club2.end());
//    set<string>clubThree(club3.begin(),club3.end());
//    for( string name: clubOne){
//        auto dishonest = clubTwo.find(name);
//        if(dishonest != clubTwo.end()){
//            multiClub.push_back(name);
//        }
//    }
//    for( string name: clubOne){
//        auto dishonest = clubThree.find(name);
//        if(dishonest != clubThree.end()){
//            multiClub.push_back(name);
//        }
//    }
//    for( string name: clubTwo){
//        auto dishonest = clubThree.find(name);
//        if(dishonest != clubThree.end()){
//            multiClub.push_back(name);
//        }
//    }
//    sort(multiClub.begin(),multiClub.end());
//    set<string> mult(multiClub.begin(),multiClub.end());
//    vector<string> multFinal(mult.begin(),mult.end());
//    return multFinal;
//}

string kitten_path(int kitten, map<int, vector<int>> tree) {
//    for( auto key : tree){
//
//    }
    map<int,int> m1;
    string ans;
    int i;
    for(auto & j : tree)
    {
        for(i=0;i<j.second.size();i++)
        {
            m1[j.second[i]]=j.first;
        }
    }
    int temp=kitten;
    while(temp)
    {
        ans+=to_string(temp);
        ans+=" ";
        temp=m1[temp];
    }
    ans+="0";
    return ans;
}

int main() {
//    vector<string> guests = {"Josephus", "Titus", "Simon", "Eleazar"};
//    cout << Josephus(guests,3);
//    cout << encrypt("hello");
//string one = "(easy)";
//string two = "(";
//string three = ")";
//    cout << is_valid(one,two,three);
//   vector<string> one =  {"JOHN","JOHN","FRED","PEG"};
//   vector<string> two =  {"PEG","GEORGE"};
//   vector<string> three = {"GEORGE","DAVID"};
//    whos_dishonest(one,two,three);
int kitten = 9;
map<int, vector<int>> tree = {{0 , {1, 2, 3, 4}},
                              {4 , {5, 6, 7}},
                              {6 , {8, 9, 10}}};
cout << kitten_path(kitten,tree);
    return 0;
}
