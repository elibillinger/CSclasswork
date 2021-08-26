/*
	animal.cpp

	author: L. Henke and C. Painter-Wakefield
	date: 04 November 2019

	Animal/20 questions program for CSCI 262, starter code.

    Modified by Eli Billinger
    date 11/23/2020
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <queue>

using namespace std;

class node {
public:
    string data;
    node* left;
    node* right;
};

void play_game(node*,queue<string> questions);
node* read_game_tree();
void write_game_tree(node*);
void delete_game_tree(node*);
node* read_preorder(ifstream& fin);
node* modify_game_tree(node*,string one, string two, string saved_question);
void write_preorder(ofstream& fout,node* root);


/**
 * Handles showing the main menu/basic UI
 */
int main() {
	node* root = read_game_tree();
	if (root == NULL) return -1;

	while (true) {
		string tmp;
		int choice;
        queue<string> questions;

		cout << "Welcome to 20 questions!" << endl;
		cout << "  1) Play the game" << endl;
		cout << "  2) Save the game file" << endl;
		cout << "  3) Quit" << endl;
		cout << "Please make your selection: ";
		getline(cin, tmp);
		choice = atoi(tmp.c_str());

		switch (choice) {
    		case 1:
    		    play_game(root,questions);
    			break;
    		case 2:
    			write_game_tree(root);
    			break;
    		case 3:
    			break;
    		default:
    			cout << "Sorry, I don't understand." << endl << endl;
		}
		if (choice == 3) break;
	}

	delete_game_tree(root);
	return 0;
}

/**
 * Sets up the recursive call to the read_preorder
 * @return root of the tree
 */
node* read_game_tree() {
    ifstream fin("animal_game_tree.txt");

    return read_preorder(fin);
}

node* read_preorder(ifstream& fin){
    node* tree = new node;
    string str;
    getline(fin, str);
    tree->data = str;
    // determines it string is a Question or answer and creates respective node
    if (str.find("#Q") != string::npos)
    {
        tree->left = read_preorder(fin);
        tree->right = read_preorder(fin);
    }
    if (str.find("#A") != string::npos)
    {
        tree->right = nullptr;
        tree->left = nullptr;
    }
    return tree;
}


/**
 * Plays the game
 * @param root Root of the game tree
 * @param questions is the queue of user history of questions and answers
 */
void play_game(node* root,queue<string> questions) {
    cout << root->data.substr(3,root->data.find('\n')) << " (y/n): ";
    questions.push(root->data);
    string answer;
    getline(cin,answer);
    questions.push(answer);
    if(answer == "y"){
        if(root->left != nullptr){
            play_game(root->left,questions);
        } else {
            cout << "YAY! I guessed your animal!" << endl;
            cout << "\n";
            return;
        }
    } else if (answer == "n"){
        if(root->right != nullptr){
            play_game(root->right,questions);
        } else {
            string extend;
            cout << "BOO! I don't know!" << endl;
            // prompt for expanding tree
            cout << "\nWould you like to expand the game tree (y/n)? ";
            getline(cin,extend);
            // if yes then output question history and get new questions
            if(extend == "y"){
                cout << "\nI asked the following:" << endl;
                string saved_question;
                while(!questions.empty()){
                    saved_question = questions.front();
                    cout << questions.front().substr(3,questions.front().find('\n'));;
                    questions.pop();
                    string ans = questions.front();
                    if(ans == "n"){
                        cout << " NO" << endl;
                    } else if (ans == "y"){
                        cout << " YES" << endl;
                    }
                    questions.pop();
                }
                // asks for new questions
                cout << "\nEnter a new animal in the form of a question, \n e.g., 'Is it a whale?':" << endl;
                string question_one;
                getline(cin,question_one);
                cout << "Now enter a question for which the answer is 'yes' for your new \n animal, and which does not contradict your previous answers: " << endl;
                string question_two;
                getline(cin,question_two);
                question_one = "#A " + question_one;
                question_two = "#Q " + question_two;
                // call helper function that modifies the tree
                modify_game_tree(root,question_one,question_two,saved_question);
                return;
            } else {
                cout << "\n";
                return;
            }
        }
    }
}

/**
 * expands the tree to add new nodes
 * @param root Root of the game tree
 * @param one The new animal in form of question
 * @param two New question that is true for animal in one
 * @param saved_question The question that asked teh animal and was wrong (used for location in tree)
 */
node* modify_game_tree(node* root,string one, string two,string saved_question){
    string answer;
    string question;
    node *current = root;
    current->data = two;
    current->left = new node;
    current->left->data = one;
    current->right = new node;
    current->right->data = saved_question;
    return root;
}



/**
 * Writes the game tree, sets up a recursive call to write_preorder();
 * @param root The root of the tree
 */
void write_game_tree(node* root) {
    ofstream fout("animal.txt");
    write_preorder(fout,root);
    cout << "Game file saved in 'animal.txt'\n" << endl;
}

void write_preorder(ofstream& fout, node* root){
    if( root != NULL){
        //output data into file
        fout << root->data << endl;
        write_preorder(fout,root->left);
        write_preorder(fout,root->right);
    }
}

/**
 * Deletes the game tree
 * @param root Root of the game tree
 */
void delete_game_tree(node* root) {
    // Optional. Do a post-order deletion of the game tree.
    // This isn't strictly needed as the program exits after this is called,
    // which frees up all the memory anyway.
}
