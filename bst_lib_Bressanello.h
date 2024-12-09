#include <iostream>
#include <vector>
using namespace std;

class Node{
    private:
        int data;
        Node *lchild;
        Node *rchild;
        int weight {1};
    public:
        Node(int k)
        : data {k}, lchild {nullptr}, rchild {nullptr}{};
        bool searchI(int k){
            Node *father = this;
            Node *current = this;
            bool check {true};
                do{
                    if(current==NULL){
                        cout << "Node not found!!" << endl;
                        return false;
                        check = false;
                    }
                    if(current->data==k){
                        cout << "Node found!!" << endl;
                        return true;
                        check = false;
                    }
                    if(k<current->data){
                        father = current;
                        current = current->lchild;
                        check = true;
                    } else {
                        father = current;
                        current = current->rchild;
                        check = true;
                    }
            }while(check);

            return true;

        }
        bool searchR(int k){
            bool check {true};
            do{
                if(this==NULL){
                    cout << "Node not found!!" << endl;
                    return false;
                    check = false;
                }
                if(this->data==k){
                    cout << "Node found!!" << endl;
                    return true;
                    check = false;
                }
                if(k<this->data){
                    return this->lchild->searchR(k);
                } else {
                    return this->rchild->searchR(k);
                }
            }while(check);

            return true;

        }
        Node *insertI(int k){
            Node *current = this;
            Node *father = this;
            bool check {true};
            do{
                if(current==NULL){
                    if(k<father->data){
                        father->lchild = new Node(k);
                        return this;
                        check = false;
                    } else {
                        father->rchild = new Node(k);
                        return this;
                        check = false;
                    }
                }
                if(current->data==k){
                    current->weight++;
                    return current;
                    check = false;
                }
                if(k<current->data){
                    father = current;
                    current = current->lchild;
                } else {
                    father = current;
                    current = current->rchild;
                }
            }while(check);

            return this;
        
        }
        Node *insertR(int k){
            if(this==NULL){
                return new Node(k);
            }
            if(this->data==k){
                this->weight++;
                return this;
            }
            if(k<this->data){
                if(this->lchild==nullptr){
                    this->lchild = new Node(k);
                } else {
                    this->lchild->insertR(k);
                }
            } else {
                if(this->rchild==nullptr){
                    this->rchild = new Node(k);
                } else {
                    this->rchild->insertR(k);
                }
            }
            return this;
        }
        void preOrder(){
            if(this==NULL) return;
            cout << this->data << " ";
            this->lchild->inOrder();
            this->rchild->inOrder();
        }
        void inOrder(){
            if(this==NULL) return;
            this->lchild->inOrder();
            cout << this->data << " ";
            this->rchild->inOrder();
        }
        void postOrder(){
            if(this==NULL) return;
            this->lchild->postOrder();
            this->rchild->postOrder();
            cout << this->data << " ";
        }
        Node *deleteNode(int k){
            Node *father = this;
            Node *current = this;
            Node *tmp = this;
            bool check {true};
            do{
                if(current==NULL){
                    cout << "Node not found!" << endl;
                    check = false;
                }
                if(current->data==k){
                    if(current->lchild==nullptr && current->rchild==nullptr){
                        if(current->data==father->lchild->data){
                            delete current;
                            current = nullptr;
                            father->lchild = nullptr;
                            check = false;
                            return father;
                        } else {
                            delete current;
                            current = nullptr;
                            father->rchild = nullptr;
                            check = false;
                            return father;
                        }
                    } else if(current->lchild==nullptr){
                        tmp = current->rchild;
                        current->data = tmp->data;
                        current->lchild = tmp->lchild;
                        current->rchild = tmp->rchild;
                        delete tmp;
                        tmp = nullptr;
                        check = false;
                        return this;
                    } else if(current->rchild==nullptr){
                        tmp = current->lchild;
                        current->data = tmp->data;
                        current->lchild = tmp->lchild;
                        current->rchild = tmp->rchild;
                        delete tmp;
                        tmp = nullptr;
                        check = false;
                        return this;
                    }
                } else if(k<current->data) {
                    father = current;
                    current = current->lchild;
                } else {
                    father = current;
                    current = current->rchild;
                }
            }while(check);
        
            return current;

        }
        bool isBst(){
            Node *root = this;
            bool check {true};
            do{
                if(root->lchild==nullptr && root->rchild==nullptr){
                    return true;
                }
                if(root->lchild==nullptr){
                    if(root->data>root->rchild->data){
                        return false;
                    } else {
                        root = root->rchild;
                    }
                } else if(root->rchild==nullptr){
                    if(root->data<root->lchild->data){
                        return false;
                    } else {
                        root = root->lchild;
                    }
                } else if(root->data<root->lchild->data || root->data>root->rchild->data){
                    return false;
                } else {
                    root = root->lchild; 
                }
            }while(check);

            return true;

        }
};
