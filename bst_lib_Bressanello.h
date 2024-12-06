#include <iostream>
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
        void preOrder();
        void inOrder(){
            if(this==NULL) return;
            this->lchild->inOrder();
            cout << this->data << " ";
            this->rchild->inOrder();
        }
        void postOrder();
        Node *deleteNode(int k);
        bool isBst();
        friend ostream &operator<<(ostream &os, const Node *root){
            os << "Il dato del nodo: " << root->data << endl;
            os << "Il peso del nodo: " << root->weight << endl;
            if(root->lchild==NULL){
                os << "Il figlio sinistro e' una foglia" << endl;
            } else {
                os << "Il figlio sinistro: " << root->lchild->data << endl;
            }
            if(root->rchild==NULL){
                os << "Il figlio destro e' una foglia" << endl;
            } else {
                os << "Il figlio destro: " << root->rchild->data << endl;
            }
            return os;
        }
        friend istream &operator>>(istream &is, Node *root){
            cout << "Inserisci il valore del nodo: ";
            is >> root->data;
            root->lchild = nullptr;
            root->rchild = nullptr;
            root->weight = 1;
            return is;
        }
};
