#include<iostream>
#include<string>
using namespace std;
template<class T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;

    Node(T t=0,Node<T> *l=0,Node<T>*r=0):data(t),left(l),right(r){};

    bool isleaf()// kiểm tra có phải là lá không
    {
        if (!left&&!right) return true;
        return false;
    }
    bool isEnternal()//kiểm tra nội
    {
        return (left || right);
    }
};

template<class T>
class BinaryTree
{
    protected:
        Node<T> *root;
    private:
        bool isEmpty()const{return root==0;}
        // duyệt tiền tố
        void printPreOrder(Node<T> * r)// NLR
        {
            if (r == NULL)
                return;
            cout << r->data <<" ";
            printPreOrder (r->left);
            printPreOrder (r->right);
        }
        //duyệt trung tố
        void LNR(Node<T>* root) {
            if (root == NULL) {
                return;
            }
            LNR(root->left);
            printf("%d ", root->data);
            LNR(root->right);
        }  
        // Hàm thực hiện duyệt cây LRN (hậu tố) sử dụng đệ quy.
        void LRN(Node<T>* root) {
            if (root == NULL) {
                return;
            }
            LRN(root->left);
            LRN(root->right);
            cout << root->data << " ";
        }
        int CountNodeRec(Node<T>*v)// đếm nốt
        {
            if (v==NULL)
            {
                return 0;
            }
            else
            {
                int countleft=CountNodeRec(v->left);
                int countright=CountNodeRec(v->right);
                return 1+countleft+countright;
            }
        }

        void destroy_tree(Node<T>*v)
        {
            if (!v)
                return;
            destroy_tree(v->left);
            destroy_tree(v->right);
            delete v;
        }

        int heightRec(Node<T>*v)// chiều cao của cây
        {
            if (v&&v->isleaf())
            {
                return 0;
            }else
            {
                return 1+max(heightRec(v->left), heightRec(v->right));
            }
        }
        //thêm giá trị vào cây với điều kiện nhỏ hơn thêm sang trái, lớn hơn thêm sang phải
        Node<T>* insertNodeRec(Node<T>* v, const T& value) {
            if (v == NULL) {
                return new Node<T>(value);
            }
            if (value < v->data) {
                v->left = insertNodeRec(v->left, value);
            } else if (value > v->data) {
                v->right = insertNodeRec(v->right, value);
            }
            return v;
        }
        // đếm Node nội
        int countEnternalRec(Node<T>*v)
        {
            if (v->isEnternal()&&v!=NULL)
            {
                return 1+countEnternalRec(v->left)+countEnternalRec(v->right);
            }
            return 0;
        }
        // tìm kiếm giá trị value trong cây
        Node<T>* TreeSearchRec(Node<T>* v, T value) 
        {
            if (v == NULL) {
                return NULL;
            } else if (value < v->data) {
                return TreeSearchRec(v->left, value);
            } else if (value > v->data) {
                return TreeSearchRec(v->right, value);
            } else {
                return v;
            }
        }

        void CopyTreeRec(Node<T>*& l, const Node<T>* r)
        {
            if (r)
            {
                l = new Node<T>(r->data);
                CopyTreeRec(l->left, r->left);
                CopyTreeRec(l->right, r->right);
            }
        }
        
        // void Remove(Node<T>* v)
        // {
        //     if(!r->left) r = r->right;
        //     else if(!r->right) r = r->left;
        //     else{
        //         Node<T>* cur = r->left;
        //         Node<T>* par = r;
        //         for(;cur->right;par=cur,cur = cur->right);
        //         r->data = cur->data;
        //     }
        // }


    public:
        BinaryTree():root(0){};
        ~BinaryTree()
        {
            destroy_tree(root);
        }
        void print()
        {
            printPreOrder(root);
        }
        int count()
        {
            return CountNodeRec(root);
        }
        int countEnternal()
        {
            return countEnternalRec(root);
        }
        int height()
        {
            return heightRec(root);
        }
        bool TreeSearch(const T& value) 
        {
            return TreeSearchRec(root, value) != NULL;
        }
        void insert(const T& value) {
            root = insertNodeRec(root, value);
        }
        void CopyTree(BinaryTree<T> *x)
        {
            CopyTreeRec(root,x->root);
        }
        const BinaryTree<T> &operator=(const BinaryTree<T> &r)
        {
            if (this == &r)
                return *this;
            destroy_tree(root);
            root = NULL;
            CopyTreeRec(root, r.root);
            return *this;
        }
};
int main()
{
    BinaryTree<int> t;
    t.insert(6);
    t.insert(4);
    t.insert(5);
    t.insert(9);
    t.insert(7);
    t.print();
    cout << endl;
    // BinaryTree<int> a;
    // a=t;
    // a.CopyTree(&t);
    //a.print();
    if(t.TreeSearch(5) == true)
    {
        cout << "Ton tai gia tri";
    }else
    {
        cout << "khong ton tai gia tri";
    }
}