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
        void inOrder(){
            if(this==NULL) return;
            this->lchild->inOrder();
            cout << this->data << " ";
            this->rchild->inOrder();
        }
};
