#include <iostream>
#include <list>
#include <vector>

using namespace std;

class node{
public:
    string data;
    node* next;
};

string longest(node* head){
    string longest = "";
    for(node* p = head; p != nullptr; p = p->next){
        string word = p->data;
        if(word.size() > longest.size()){
            longest = word;
        }
    }
    return longest;

}

node* assemble(vector<string> parts) {
    node* head = nullptr;
    node* tail = nullptr;
    for(string n: parts){
        node* p = new node;
        p->data = n;
        p->next = nullptr;
        if( head == nullptr){
            head = tail = p;
        } else{
            tail->next = p;
            tail = p;
        }
    }
    for(node* p = head; p != nullptr; p = p->next){
        return p;
    }

}

node* compress(node* head) {
    node *current = head;
    node *previous = nullptr;
    node *next;
    while(current != nullptr){
        if(previous != nullptr && current->data == previous->data)//this is a duplicate of previous value
        {
            next = current->next;
            if(previous == nullptr)
                head = next;
            else
                previous->next = next;
            delete current;
            current = next;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
    return head;
}


node* expand(node*head){
    node *current = head;
    node *previous = nullptr;
    node *next;
    while(current != nullptr){
        if(previous != nullptr && current->data != previous->data)
        {

            node* p = new node;
            p->data = current->data;
            p->next = previous->next;
            previous->next = p;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
    return head;
}
int countNodes(node *n){
    int res = 1;
    node *temp = n;
    while (temp->next != n){
        res++;
        temp = temp->next;
    }
    return res;
}

int cycle_length(node* head) {
    node *next = head, *next_two = head;
    while (next && next_two && next_two->next){
        next = next->next;
        next_two = next_two->next->next;
        if (next == next_two)
            return countNodes(next);
    }
    return -1;
    }
int main() {
//    vector<string> parts = {"apple","orange","banana","pear"};
//    assemble(parts);
    return 0;
}
