#include <stdio.h>
#include <iostream>

using namespace std;

class BST{
    private:
        class Node{
            public:
                Node* left;
                Node* right;
                int val;
                Node(){
                    left = nullptr;
                    right = nullptr;
                }
                Node(int v){
                    left = nullptr;
                    right = nullptr;
                    val = v;
                }
        };
    public:
        Node* root;
        BST(){
            root = nullptr;
        }
        BST(int v){
            root = new Node(v);
        }


        //how does the find operation actually work?
        //try to run through the function calls for finding 7 on the following tree
        /*
                             8
                         /       \
                    6               12
                  /    \          /     \  
                4       7       10      15
              /
            2
        
        */
        bool findValHelper(Node* curr, int v){
            if(curr == nullptr){
                return false;
            }
            if(curr->val == v){
                return true;
            }
            if(curr->val > v){
                return findValHelper(curr->left, v);
            }
            return findValHelper(curr->right, v);
        }
        bool findVal(int v){
            return findValHelper(root, v);
        }

        //how does the insert function actually operate?
        //can you think of a way to make this function iterative instead of recursive? (hint: zybooks does it iteratively)
        //try to run through the operation for inserting 5 on the tree below:
        /*
                             8
                         /       \
                    6               12
                  /    \          /     \  
                4       7       10      15
              /
            2
        
        */
        void insertValHelper(Node* curr, int v){
            if(curr->val > v){
                if(curr->left == nullptr){
                    curr -> left = new Node(v);
                }else{
                    insertValHelper(curr->left, v);
                }
            }else{
                if(curr->right == nullptr){
                    curr -> right = new Node(v);
                }else{
                    insertValHelper(curr->right, v);
                }
            }
        }
        void insertVal(int v){
            if(root == nullptr){
                root = new Node(v);
                return;
            }
            insertValHelper(root, v);
        }

        //try to implement this remove value function to remove the node containing v, assuming v is unique in the tree
        void removeValue(int v){

        }

        //this function prints the nodes "In order". How will the nodes be outputted? Increasing order? Decreasing? random?
        void printInOrderHelper(Node* curr){
            if(!curr){
                return;
            }
            printInOrderHelper(curr->left);
            cout<<curr->val<<"->";
            printInOrderHelper(curr->right);
        }
        void printInOrder(){
            printInOrderHelper(root);
            cout<<endl;
        }
};

int main(){
    BST test;
    test.insertVal(5);
    test.printInOrder();
    test.insertVal(5);
    test.insertVal(2);
    test.insertVal(1);
    test.insertVal(4);
    test.insertVal(7);
    test.insertVal(9);
    test.printInOrder();

}