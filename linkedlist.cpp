#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

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
    void printLL() {
        Node* temp=head;
        while (temp!=NULL) {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};



int main() {
    list l1;
    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);
    l1.push_back(4);
    l1.pop_front();
    l1.pop_back();
    l1.insert(3,2);

    l1.printLL();
    cout<<l1.search(2)<<endl;
    return 0;
}