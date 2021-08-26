#include <iostream>
#include <string>
#include <vector>

using namespace std;

string can_access(vector<int> &user_rights, int min_permission) {
    string access;
    for (int i=0; i<user_rights.size(); i++){
        cout << i;
    }
    cout << access;
}

int main() {
    vector<int> user_rights = {0,1,2,3,4,5};
    int min_permission = 2;
    for (int i=0; i < user_rights.size(); i++){

    }
    cout << 1;
    can_access(user_rights,min_permission);
}
