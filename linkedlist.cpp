#include<iostream>
#include <unordered_map>
using namespace std;

// Singly list
class Node {
public:
    int data;
    Node* next;
    Node* random;

    Node(int val) {
        data=val;
        next=NULL;
    }
};
class list {
    Node* head;
    Node* tail;

public:
    list() {
        head=tail=NULL;
    }
    void push_front(int val) {
        Node* newnode = new Node(val);
        if (head==NULL) {
            head=tail=newnode;
            return;
        } else {
            newnode->next=head;
            head=newnode;
        }
    }
    void push_back(int val) {
        Node* newnode = new Node(val);
        if (head==NULL) {
            head=tail=newnode;
            return;
        } else {
            tail->next=newnode;
            tail=newnode;
        }
    }
    void pop_front() {
        if (head==NULL) {
            return;
        }
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    void pop_back() {
        if (head==NULL) {
            return;
        }
        Node* temp=head;
        while (temp->next!=tail) {
            temp=temp->next;
        }
        temp->next=NULL;
        delete tail;
        tail=temp;
    }
    void insert(int val,int pos) {
        if (pos<0) {
            return;
        }
        if (pos==0) {
            push_front(val);
            return;
        }
        Node* newnode=new Node(val);
        Node* temp=head;
        for (int i=0;i<pos-1;i++) {
            if (temp==NULL) {
                return;
            }
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    int search(int val) {
        Node* temp=head;
        int i=0;
        while (temp!=NULL) {
            if (temp->data==val) {
                return i;
            }
            temp=temp->next;
            i++;
        }
        return -1;
    }
    Node* reverselist(Node* head) {
        Node* curr=head;
        Node* prev=NULL;
        Node* next=NULL;

        while (curr!=NULL) {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    Node* middle(Node* head) {    // slow-fast approach
        Node* slow=head;
        Node* fast=head;
        while (fast!=NULL && fast->next!=NULL) {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    bool hascycle(Node* head) {
        Node* slow=head;
        Node* fast=head;
        while (fast!=NULL && fast->next!=NULL) {
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast) {
                return true;
            }
        }
        return false;
    }
    Node* detectstartcycle(Node* head) {
        Node* slow=head;
        Node* fast=head;
        bool iscycle=false;
        while (fast!=NULL && fast->next!=NULL) {
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast) {
                iscycle=true;
                break;
            }
        }
        if(!iscycle){
            return NULL;
        }

        slow=head;
        while (slow!=fast) {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
    Node* removecycle(Node* head) {
        Node* slow=head;
        Node* fast=head;
        bool iscycle=false;
        while (fast!=NULL && fast->next!=NULL) {
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast) {
                iscycle=true;
                break;
            }
        }
        if(!iscycle){
            return NULL;
        }

        slow=head;
        Node* prev=NULL;
        while (slow!=fast) {
            slow=slow->next;
            prev=fast;
            fast=fast->next;
        }
        prev->next=NULL;
        return slow;
    }
    Node* merge2list(Node* l1h,Node* l2h) {
        if (l1h==NULL) {
            return l2h;
        }
        if (l2h==NULL) {
            return l1h;
        }
        if (l1h->data<=l2h->data) {
            l1h->next=merge2list(l1h->next,l2h);
            return l1h;
        } else {
            l2h->next=merge2list(l1h,l2h->next);
            return l2h;
        }
    }
    Node* copylistwithrandomptr(Node* head) {
        if (head==NULL) {
            return NULL;
        }
        Node* newhead=new Node(head->data);
        Node* temp1=head->next;
        Node* temp2=newhead;
        unordered_map<Node*,Node*> m;
        m[head]=newhead;
        while (temp1!=NULL) {
            Node* copynode=new Node(temp1->data);
            m[temp1]=copynode;
            temp2->next=copynode;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        temp1=head;
        temp2=newhead;
        while (temp1!=NULL) {
            temp2->random=m[temp1->random];
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return newhead;
    }
    void print() {
        Node* temp=head;
        while (temp!=NULL) {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

// Circular list
class cirlist {
    int data;
    Node* head;
    Node* tail;

public:
    cirlist() {
        head=tail=nullptr;
    }
    void push_front(int val) {
        Node* newnode=new Node(val);
        if (head==nullptr) {
            head=tail=newnode;
            tail->next=head;
        } else {
            newnode->next=head;
            head=newnode;
            tail->next=head;
        }
    }
    void push_back(int val) {
        Node* newnode=new Node(val);
        if (head==nullptr) {
            head=tail=newnode;
            tail->next=head;
        } else {
            tail->next=newnode;
            tail=newnode;
            tail->next=head;
        }
    }
    void print() {
        if (head==nullptr) {
            return;
        }
        cout<<head->data<<" ";
        Node* temp=head->next;
        while (temp!=head) {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

};


// Doubly list
class node {
public:
    int val;
    node* next;
    node* prev;

    node(int num) {
        val=num;
        next=NULL;
        prev=NULL;
    }
};
class doublylist {
    node* head;
    node* tail;
public:
    doublylist() {
        head=tail=NULL;
    }
    void push_front(int num) {
        node* newnode=new node(num);
        if (head==NULL) {
            head=tail=newnode;
            return;
        } else {
            head->prev=newnode;
            newnode->next=head;
            head=newnode;
        }
    }
    void push_back(int num) {
        node* newnode=new node(num);
        if (head==nullptr) {
            head=tail=newnode;
            return;
        } else {
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
    }
    void pop_front() {
        if (head==nullptr) {
            return;
        }
        node* temp=head;
        head=head->next;
        temp->next=nullptr;
        head->prev=nullptr;
        delete temp;
    }
    void pop_back() {
        if (head==nullptr) {
            return;
        }
        node* temp=tail;
        tail=tail->prev;
        temp->prev=nullptr;
        tail->next=nullptr;
        delete temp;
    }
    void print() {
        node* temp=head;
        while (temp!=nullptr) {
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main() {
    doublylist dll;
    dll.push_back(1);
    dll.push_front(2);
    dll.print();

    dll.pop_front();
    dll.print();
    return 0;
}