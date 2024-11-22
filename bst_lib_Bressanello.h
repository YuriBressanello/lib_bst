#include <iostream>
using namespace std;

//smergh

struct Node {
    int data;
    int weight {1};
    Node *lchild;
    Node *rchild;
    Node(int key){
        data = key;
        lchild = nullptr;
        rchild = nullptr;
    }
};

bool it_search(Node *r, int k){
    bool check {true};
    Node *current {r};
    Node *father {r};
    do{
        if(current==NULL){
            cout << k << " non e' statotrovato" << endl;
            return 0;
            check = false;
        }

        if(current->data==k){
            cout << k << " e' stato trovato!" << endl;
            return 0;
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

    return true;

}

Node *it_insert(Node *r, int k){
    bool check {true};
    Node *current {r};
    Node *father {r};
    do{
        if(current==NULL){
            if(k<father->data){
                father->lchild = new Node(k);
                check = false;
                return r;
            } else {
                father->rchild = new Node(k);
                check = false;
                return r;
            }
            check = false;
        }

        if(current->data==k){
            current->weight++;
            check = false;
            return r;
        }

        if(k<current->data){
            father = current;
            current = current->lchild;
        } else {
            father = current;
            current = current->rchild;
        }
    }while(check);

    return r;

}


Node *ric_insert(Node *r, int k){

    if(r==nullptr){
        return new Node(k);
    }

    if(r->data==k){
        r->weight++;
        return r;
    }

    if(k<r->data){
        r->lchild = ric_insert(r->lchild, k);
    } else {
        r->rchild = ric_insert(r->rchild, k);
    }

    return r;

}

bool ric_search(Node *r, int k){

    if(r==nullptr){
        cout << k << " non e' stato trovato" << endl;
        return false;
    }

    if(r->data==k){
        cout << k << " e' stato trovato!" << endl;
        return true;
    }

    if(k<r->data){
        ric_search(r->lchild, k);
    } else {
        ric_search(r->rchild, k);
    }

    return true;

}

int conta_liv(Node *nodo){
    if(nodo==NULL) return 0;
    int l = conta_liv(nodo->lchild);
    int r = conta_liv(nodo->rchild);
    return max(r,l) + 1;
}

void pre_order(Node *nodo){
    if(nodo==NULL) return;
    cout << nodo->data << " ";
    pre_order(nodo->lchild);
    pre_order(nodo->rchild);
}

void in_order(Node *nodo){
    if(nodo==NULL) return;
    in_order(nodo->lchild);
    cout << nodo->data << " ";
    in_order(nodo->rchild);
}

void post_order(Node *nodo){
    if(nodo==NULL) return;
    post_order(nodo->lchild);
    post_order(nodo->rchild);
    cout << nodo->data << " ";
}

Node *ric_cancel(Node *nodo, int k){

    Node *current {nullptr};

    //nodo assente
    if(nodo==NULL) {
        cout << "NODO DA CANCELLARE NON TROVATO" << endl;
        return nodo;
    }

    //nodo foglia
    if(nodo->lchild==NULL && nodo->rchild==NULL && nodo->data==k){
        cout << "Il nodo " << k << " e' stato cancellato!" << endl;
        delete nodo;
        nodo = nullptr;
        return nodo;
    }

    //nodo con 1 figlio
    if(nodo->data==k){
        if(nodo->lchild==NULL){
            current = nodo->rchild;
            delete nodo;
            nodo = nullptr;
            cout << "Il nodo " << k << " e' stato cancellato!" << endl;
            return current;
        } else if(nodo->rchild==NULL){
            current = nodo->lchild;
            delete nodo;
            nodo = nullptr;
            cout << "Il nodo " << k << " e' stato cancellato!" << endl;
            return current;
        }
        current = nodo->rchild;
        nodo->data = current->data;
        nodo->rchild = ric_cancel(nodo->rchild, current->data);
    }

    if(k<nodo->data){
        nodo->lchild = ric_cancel(nodo->lchild, k);
    } else {
        nodo->rchild = ric_cancel(nodo->rchild, k);
    }

    return nodo;

}

Node *it_cancel(Node *nodo, int k){

    bool check {true};

    if(nodo==NULL){
        cout << "NODO DA CANCELLARE NON TROVATO" << endl;
        return nodo;
    }

    Node *current = nodo;
    Node *parent = nullptr;

    //salvo su current il nodo che voglio cancellare
    do{

        if(current==NULL){
            cout << "NODO DA CANCELLARE NON TROVATO" << endl;
            delete current;
            return nodo;
        }

        if(current->data==k){
            check = false;
            break;
        }

        parent = current;
        
        if(k<current->data){
            current = current->lchild;
        } else {
            current = current->rchild;
        }
    }while(check);

    //nodo foglia
    if(current->lchild==NULL && current->rchild==NULL){

        if(parent==nullptr){
            delete current;
            current = nullptr;
            cout << "Il nodo " << k << " e' stato cancellato!" << endl;
            return current;
        }

        if(parent->lchild==current){
            parent->lchild = nullptr;
            cout << "Il nodo " << k << " e' stato cancellato!" << endl;
            delete current;
        } else {
            parent->rchild = nullptr;
            cout << "Il nodo " << k << " e' stato cancellato!" << endl;
            delete current;
        }
    }

    //nodo con 1 figlio
    if(current->lchild==NULL || current->rchild==NULL){
        
        Node* child {nullptr};
        if(current->lchild==NULL){
            child = current->rchild;
        } else {
            child = current->lchild;
        }

        if(parent==NULL){
            delete current;
            current = nullptr;
            cout << "Il nodo " << k << " e' stato cancellato!" << endl;
            return child;
        }

        if(parent->lchild==current){
            parent->lchild = child;
        } else {
            parent->rchild = child;
        }
    }

    return nodo;

}