#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
int ladderLength(string from, string to, vector<string>& words) {
    unordered_set<string> dict(words.begin(), words.end());

    if(dict.find(to) == dict.end()) return 0;

    unordered_map<string, int> hash;

    int level=0;
    if(from == to) return level;

    hash[from] = -1;

    queue<string> q;
    q.push(from);
    int n = from.size();

    while(!q.empty()) {

        level++;

        int qSize = q.size();

        for(int i=0; i<qSize; i++) {

            string word = q.front(); q.pop();

            for(int i=0; i<n; i++) {

                // if we have the same index for the same word , ignore
                if(hash[word]==i)
                    continue;

                char ch = word[i];  // store for later replacement

                for(char c='a'; c<='z'; c++) {

                    word[i] = c;

                    if(word == to) return level + 1;

                    // if word is present in the wordList
                    if( dict.find(word) != dict.end() ) {

                        hash[word] = i;  // store the index in hashmap

                        // remove word from dic
                        dict.erase(word);
                        q.push(word);

                    }
                }
                word[i] = ch;
            }

        }
    }

    return 0;

}
