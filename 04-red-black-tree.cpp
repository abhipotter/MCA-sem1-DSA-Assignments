#include <iostream>
#include <string>
using namespace std;
class RedBlackTree {
    enum Color {
        RED, BLACK
    };
    struct Node {
        int key;
        Color color;
        Node *left,*right,*parent;
    };
    Node *nil, *root;
    void leftRotate(Node* x) {
        Node* y=x->right;
        x->right=y->left;
        if(y->left!=nil)y->left->parent=x;
        y->parent=x->parent;
        if(x->parent==nil)root=y;
        else if(x==x->parent->left)x->parent->left=y;
        else x->parent->right=y;
        y->left=x;
        x->parent=y;
    }
    void rightRotate(Node* x) {
        Node* y=x->left;
        x->left=y->right;
        if(y->right!=nil)y->right->parent=x;
        y->parent=x->parent;
        if(x->parent==nil)root=y;
        else if(x==x->parent->right)x->parent->right=y;
        else x->parent->left=y;
        y->right=x;
        x->parent=y;
    }
    void fixInsert(Node* z) {
        while(z->parent->color==RED) {
            if(z->parent==z->parent->parent->left) {
                Node* y=z->parent->parent->right;
                if(y->color==RED) {
                    z->parent->color=BLACK;
                    y->color=BLACK;
                    z->parent->parent->color=RED;
                    z=z->parent->parent;
                }
                else {
                    if(z==z->parent->right) {
                        z=z->parent;
                        leftRotate(z);
                    }
                    z->parent->color=BLACK;
                    z->parent->parent->color=RED;
                    rightRotate(z->parent->parent);
                }
            }else {
                Node* y=z->parent->parent->left;
                if(y->color==RED) {
                    z->parent->color=BLACK;
                    y->color=BLACK;
                    z->parent->parent->color=RED;
                    z=z->parent->parent;
                }
                else {
                    if(z==z->parent->left) {
                        z=z->parent;
                        rightRotate(z);
                    }
                    z->parent->color=BLACK;
                    z->parent->parent->color=RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color=BLACK;
    }
    void transplant(Node* u,Node* v) {
        if(u->parent==nil)root=v;
        else if(u==u->parent->left)u->parent->left=v;
        else u->parent->right=v;
        v->parent=u->parent;
    }
    Node* minimum(Node* n)const {
        while(n->left!=nil)n=n->left;
        return n;
    }
    Node* findNode(int key)const {
        Node* n=root;
        while(n!=nil&&n->key!=key)n=key<n->key?n->left:n->right;
        return n;
    }
    void fixDelete(Node* x) {
        while(x!=root&&x->color==BLACK) {
            if(x==x->parent->left) {
                Node* w=x->parent->right;
                if(w->color==RED) {
                    w->color=BLACK;
                    x->parent->color=RED;
                    leftRotate(x->parent);
                    w=x->parent->right;
                }
                if(w->left->color==BLACK&&w->right->color==BLACK) {
                    w->color=RED;
                    x=x->parent;
                }
                else {
                    if(w->right->color==BLACK) {
                        w->left->color=BLACK;
                        w->color=RED;
                        rightRotate(w);
                        w=x->parent->right;
                    }
                    w->color=x->parent->color;
                    x->parent->color=BLACK;
                    w->right->color=BLACK;
                    leftRotate(x->parent);
                    x=root;
                }
            }else {
                Node* w=x->parent->left;
                if(w->color==RED) {
                    w->color=BLACK;
                    x->parent->color=RED;
                    rightRotate(x->parent);
                    w=x->parent->left;
                }
                if(w->right->color==BLACK&&w->left->color==BLACK) {
                    w->color=RED;
                    x=x->parent;
                }
                else {
                    if(w->left->color==BLACK) {
                        w->right->color=BLACK;
                        w->color=RED;
                        leftRotate(w);
                        w=x->parent->left;
                    }
                    w->color=x->parent->color;
                    x->parent->color=BLACK;
                    w->left->color=BLACK;
                    rightRotate(x->parent);
                    x=root;
                }
            }
        }
        x->color=BLACK;
    }
    void inorder(Node* n)const {
        if(n==nil)return;
        inorder(n->left);
        cout<<n->key<<' ';
        inorder(n->right);
    }
    void display(Node* n,int depth,const string& label)const {
        if(n==nil)return;
        cout<<string(depth*4,' ')<<label<<n->key<<(n->color==RED?" (RED)":" (BLACK)")<<'\n';
        display(n->left,depth+1,"L: ");
        display(n->right,depth+1,"R: ");
    }
    void clear(Node* n) {
        if(n==nil)return;
        clear(n->left);
        clear(n->right);
        delete n;
    }
    public:
    RedBlackTree() {
        nil=new Node {
            0,BLACK,nullptr,nullptr,nullptr
        };
        nil->left=nil->right=nil->parent=nil;
        root=nil;
    }
    ~RedBlackTree() {
        clear(root);
        delete nil;
    }
    RedBlackTree(const RedBlackTree&)=delete;
    RedBlackTree& operator=(const RedBlackTree&)=delete;
    bool search(int key)const {
        return findNode(key)!=nil;
    }
    void insert(int key) {
        Node* p=nil;
        Node* n=root;
        while(n!=nil) {
            p=n;
            if(key==n->key)return;
            n=key<n->key?n->left:n->right;
        }
        Node* z=new Node {
            key,RED,nil,nil,p
        };
        if(p==nil)root=z;
        else if(key<p->key)p->left=z;
        else p->right=z;
        fixInsert(z);
    }
    bool deleteKey(int key) {
        Node* z=findNode(key);
        if(z==nil)return false;
        Node* y=z;
        Color original=y->color;
        Node* x;
        if(z->left==nil) {
            x=z->right;
            transplant(z,z->right);
        }
        else if(z->right==nil) {
            x=z->left;
            transplant(z,z->left);
        }
        else {
            y=minimum(z->right);
            original=y->color;
            x=y->right;
            if(y->parent==z)x->parent=y;
            else {
                transplant(y,y->right);
                y->right=z->right;
                y->right->parent=y;
            }
            transplant(z,y);
            y->left=z->left;
            y->left->parent=y;
            y->color=z->color;
        }
        delete z;
        if(original==BLACK)fixDelete(x);
        return true;
    }
    void inorder()const {
        inorder(root);
        cout<<'\n';
    }
    void printTree()const {
        if(root==nil)cout<<"(empty)\n";
        else display(root,0,"Root: ");
    }
};
int main() {
    RedBlackTree tree;
    for(int key: {
        10,20,30,15,25,5,1
    })tree.insert(key);
    cout<<"Inorder after insertion: ";
    tree.inorder();
    tree.printTree();
    cout<<boolalpha<<"Search 15: "<<tree.search(15)<<'\n';
    tree.deleteKey(30);
    tree.deleteKey(10);
    cout<<"Inorder after deleting 30 and 10: ";
    tree.inorder();
    tree.printTree();
    cout<<"Search 10: "<<tree.search(10)<<'\n';
}
