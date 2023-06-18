#ifndef __DLIST_H
#define __DLIST_H
#include<iostream>
using namespace std;

template<typename T>
struct Node
{
    T data;
    Node<T> *prev, *next;
    Node(T t = T(), Node<T> *p = 0, Node<T> *n = 0):data(t),prev(p),next(n){};
};

template<typename T>
class Dlist
{
private:
    Node<T> *head, *tail;
    int size;
public:
    Dlist():head(0),tail(0),size(0){};
    Node<T> * getlink(int i)
    {
        if(i<0 || i>size-1) throw "chi so khong hop le";
        Node<T> *p = head;
        for(int j=0; j<i; j++)
        {
            p=p->next;
        }
        return p;
    }
    int getSize()
    {
        return size;
    }
    void AddFrist(T a)// add đầu
    {
        Node<T> *NewN = new Node<T>(a);
        if(head == NULL)
        { 
            head = tail = NewN;
        }else{
            NewN->next = head;
            head->prev = NewN;
            head = NewN;
        }
        size++;
    }

    void AddLast(T a)// add cuôi
    {
        Node<T> *NewN = new Node<T>(a);
        if(tail == NULL)AddFrist(a);
        else{

            tail->next = NewN;
            NewN->prev = tail;
            tail = NewN;
            size++;
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }

    

    void insert(int index, const T& v) //chèn ở vị trí i giá trị v
    {
        Node<T> *NewN = new Node<T>(v);
        Node<T> * temp = getlink(index);
        if(index == 0){
            AddFrist(v);
        }else{
            Node<T>*temp = head;
            for(int i=0;i<index;i++)
                temp = temp->next;
            Node<T> *NewN = new Node<T>(v,temp->prev,temp);
            // newN ->next = temp;
            // newNode->prev = temp->prev;
            temp->prev->next = NewN;
            temp->prev = NewN;
        }
        
        // if(i<0 || i>size)
        // {
        //     cout << "index out of range" << endl;
        //     return;
        // }
        // Node<T>* NewN = new Node<T>(v);
        // if (i == 0)AddFrist(v);
        // else if (i == size-1)AddLast(v);
        // else
        // {
        //     Node<T>* p = head;
        //     for (int j = 0; j < i; j++) 
        //     {
        //         p = p->next;
        //     }
        //     NewN->next = p;
        //     NewN->prev = p->prev;
        //     p->prev->next = NewN;
        //     p->prev = NewN;
        //     size++;
        // }
    }

    void removeFrist()// xóa đầu
    {
        if(head == NULL)
        {
            cout << "Danh sach rong"<< endl;
            return;
        }else if(tail->prev == NULL)
        {
            delete head;
            head = tail = NULL;
            size--;
        }else{
            Node<T> *old = head;
            head = head->next;
            head->prev = NULL;
            delete old;
            size--; 
        }
    }

    void removeLast()// xóa cuối
    {
        if(head == NULL)
        {
            cout << "Danh sach rong" << endl;
            return;
        }else if(tail->prev == NULL)
        {
            removeFrist();
        }else{
            Node<T> *old = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete old;
            size--;
        }
    }
    //[0,size]
    void remove(int i) //xóa ở vị trí i
    {
        if(i==0)removeFrist();
        else if(i==size-1)removeLast();
        else
        {
            Node<T>* p = head;
            for (int j = 0; j < i; j++) 
            {
                p = p->next;
            }
            p->next->prev = p->prev;
            p->prev->next = p->next;
            delete p;
            size--;
        }
    }
    void reverse() //đảo ngược
    {
        Node<T> *last = head;
        Node<T> *secondlast = NULL;
        Node<T> *thirdlast = NULL;
        tail = head;
        while(last!=NULL)
        {
            thirdlast = last->next;
            last->prev = thirdlast;
            last->next = secondlast;
            secondlast = last;
            last = thirdlast;
        }
        head = secondlast;
    }

    void swap(T &a, T &b)
    {
        T temp = a;
        a = b;
        b = temp;
    }

    void bubbleSort() //sắp xếp nổi bọt
    {
        if(head == NULL)
        {
            return;
        }
        Node<T> *p, *q;
        for(p = head; p != NULL; p = p->next)
        {
            for(q = p->next; q != NULL; q = q->next)
            {
                if(p->data > q->data)
                {
                    swap(p->data,q->data);
                }
            }
        }
    }

    void selectionSort() //sắp xếp chọn
    {
        if(head == NULL)
        {
            return;
        }
        Node<T> *p, *q;
        
        for(p = head; p != NULL; p = p->next)
        {
            Node<T> *min = p;
            for(q = p->next; q != NULL; q = q->next)
            {
                if(q->data < min->data)
                {
                    min = q;
                }
            }
            swap(p->data,min->data);
        }
    }
    /*    
    void insertionSort() // sắp xếp chèn
    {
        T key;
        Node<T> *p, *q;
        for(p = head->next;p != NULL;p=p->next)
        {
            key = p->data;
            q = p->prev;
            while(q->data > key)
            {
                q->next->data = q->data;
                q = q->prev;
            }
            q->next->data = key;
        }
    }
    */

    Dlist(const Dlist<T> & r):head(0),size(0)//hàm sao chép
    {
        if(r.head)
        {
            head = tail = new Node<T> (r.head ->data);


            size++;
            for(Node<T> *v = r.head->next;v!=NULL;v = v->next)
            {
                AddLast(v->data);
            }
        }
    }

    const Dlist & operator= (const Dlist & r)// =
    {
        if(head==r.head)return *this;
        else if(r.head != NULL)
        {
            AddFrist(r.head->data);
            for(Node<T> *v = r.head->next;v!=NULL;v = v->next)
            {
                AddLast(v->data);
            }
        }
        return *this;
    }

    void searchKey(int data)
    {
        search(data,head);
    }

    void search(int data,Node<T> * node)
    {
        if(node==NULL)
        {
            cout <<"khong tim thay"<<endl;
            return;
        }else if(node->data == data){
            cout << "tim thay"<<endl;
            return;
        }else search(data,node->next);
    }
    T sum() //Tính tổng
    {
        T sum=0;
        for(Node<T> *p=head;p!=NULL;p=p->next)
        {
            sum += p->data;
        }
        return sum;
    }

    T Max()// Tìm phần tử max
    {
        T max = head->data;
        for(Node<T> *p = head;p!=NULL;p=p->next)
        {
            if(max < p->data)
            {
                max = p->data;
            }
        }
        return max;
    }

    void removeKey( const T & e)//xóa nút dữ liệu e
    {
        int index=0;
        for(Node<T> *p=head;p!=NULL;p=p->next)
        {
            if(p->data == e)
            {
                remove(index);
            }else
            {
                index++;
            };
            
        }
    }
    
    void replace(int i, const T &e)//thay dữ liệu e vào nút i
    {
        if(i==0)
        {
            head->data = e;
        }
        else if(i==size-1)
        {
            tail->data = e;
        }
        else
        {
            Node<T>* p = head;
            for (int j = 0; j < i; j++) 
            {
                p = p->next;
            }
            p->data = e;
        }
    }

    void replaceKey(const T &e1, const T &e2)//thay nút dữ liệu e1 thành e2
    {
        for(Node<T> *p=head;p!=NULL;p=p->next)
        {
            if(p->data == e1)
            {
                p->data = e2;
            };
            
        }
    }

    void addORlist(T value)
    {
        int index = 0;
        if(head == NULL){AddFrist(value);return;}
        bubbleSort();
        for(Node<T> *p = head; p != NULL; p = p->next)
        {
            if(p->data >= value)
            {
                insert(index,value);
                return;
            }
            index++;
        }
        insert(index-1,value);
    }

    void clear()
    {
        while(head!= NULL)
        {
            removeFrist();
        }        
    }

    void print()
    {
        for(Node<T> *p=head;p!=NULL;p=p->next)
        {
            cout << p->data << " ";
        }
        cout << endl;
    }
};

#endif