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
        //if the value you are searching for is greater than the current node, go right. otherwise you can go left.
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
        //find the location to insert by traveling left or right like find
        //inserts once it finds a null location to insert to
        //can you think of a way to make this function iterative instead of recursive? (hint: zybooks does it iteratively)
        //can have a while loop that loops through the tree, similar to a linked list, and adds at the end
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
        Node* findSuccessorParent(Node* curr){
            if(curr->left->left == nullptr){
                return curr;
            }
            return findSuccessorParent(curr->left);
        }

        Node* removeValueHelper(Node* curr, int v){
            if(curr == nullptr){
                return nullptr;
            }

            if(curr->val > v){
                curr->left = removeValueHelper(curr->left, v);
                return curr;
            }else if(curr->val < v){
                curr->right = removeValueHelper(curr->right, v);
                return curr;
            }

            if(curr->left == nullptr && curr->right == nullptr){
                return nullptr;
            }else if(curr->left == nullptr){
                Node* ret = curr->right;
                if(curr == root){
                    root = ret;
                }
                delete curr;
                //return removeValueHelper(ret, v);
                return ret;
            } else if(curr->right == nullptr){
                Node* ret = curr->left;
                if(curr == root){
                    root = ret;
                }
                delete curr;
                //return removeValueHelper(ret, v);
                return ret;
            }

            if(curr->right->left == nullptr){
                curr->val = curr->right->val;
                Node* del = curr->right;
                curr->right = curr->right->right;
                delete del;
            }else{
                Node* succParent = findSuccessorParent(curr->right);
                curr->val = succParent->left->val;
                delete succParent->left;
                succParent->left = nullptr;
            }
            //return removeValueHelper(curr, v);
            return curr;
        }

        void removeValue(int v){
            removeValueHelper(root, v);
        }

        //this function prints the nodes "In order". How will the nodes be outputted? Increasing order? Decreasing? random?
        //increasing order
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
    test.insertVal(1);
    test.printInOrder();
    test.insertVal(5);
    test.insertVal(5);
    test.insertVal(5);
    test.insertVal(7);
    test.insertVal(7);
    test.insertVal(9);
    test.printInOrder();
    test.removeValue(7);
    test.printInOrder();
    test.removeValue(5);
    test.printInOrder();

}