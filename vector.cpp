#include<iostream>
#include<list>
#include<deque>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<set>
#include<vector>
using namespace std;
int main(){
    vector<int> vector1={1,2,3,4,5};
    // cout<<vector1.size()<<endl;
    // vector1.push_back(6);
    // cout<<vector1.size()<<endl;
    // vector1.pop_back();
    // cout<<vector1.size()<<endl;
    // cout<<vector1.front()<<endl;
    // cout<<vector1.back()<<endl;
    // cout<<vector1.at(2)<<endl;
    // cout<<vector1.capacity()<<endl;
    // for(int i: vector1){
    //     cout<<i<<" ";
    // }
    // vector<int>::iterator it;
    // for(it=vector1.begin();it!=vector1.end();it++){
    //     cout<<*it<<" ";
    // }
    // cout<<endl;
    // vector<int>::reverse_iterator rit;
    // for(rit=vector1.rbegin();rit!=vector1.rend();rit++){
    //     cout<<*rit<<" ";
    // }
    // cout<<endl;
    // for(auto it=vector1.begin();it!=vector1.end();it++){
    //     cout<<*it<<" ";
    // }
    // cout<<endl;
    // for(auto rit=vector1.rbegin();rit!=vector1.rend();rit++){
    //     cout<<*rit<<" ";
    // }
    // cout<<endl;
    // stack<int> s;
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // // stack<int> s2;
    // // s2.swap(s);
    // // cout<<"Stack size: "<<s2.size()<<endl;
    // cout<<"Stack top element: "<<s.top()<<endl;
    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    // queue<int> q;
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // // queue<int> q2;
    // // q2.swap(q);
    // // cout<<"Stack size: "<<q2.size()<<endl;
    // cout<<"Stack front element: "<<q.front()<<endl;
    // while(!q.empty()){
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }
    // priority_queue<int, vector<int>, greater<int>> pq;
    // pq.push(5);
    // pq.push(1);
    // pq.push(3);
    // cout<<"Priority Queue top element: "<<pq.top()<<endl;
    // while(!pq.empty()){
    //     cout<<pq.top()<<" ";
    //     pq.pop();
    // }
    map<string,int> m;   // unique keys and sorted order
    m.insert({"oppo",9});
    m["samsung"]=25;
    m["apple"]=17;
    for(auto p:m){    // pair<string,int> p
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<m.count("samsung")<<endl;
    cout<<m["oppo"]<<endl;
    m.erase("apple");
    if(m.find("oppo")!=m.end()){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
    if(m.find("apple")!=m.end()){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
    multimap<string,int> mm;   // duplicate keys and sorted order
    mm.insert({"oppo",9});
    mm.insert({"oppo",25});
    mm.insert({"apple",17});
    mm.erase(m.find("oppo"));  // erases only one key
    for(auto p1:mm){    // pair<string,int> p1
        cout<<p1.first<<" "<<p1.second<<endl;
    }
    unordered_map<string,int> um;   // unique keys and unsorted order
    um["samsung"]=25;
    um["apple"]=17;
    um["oppo"]=9;
    for(auto p2:um){    // pair<string,int> p2
        cout<<p2.first<<" "<<p2.second<<endl;
    }
    set<int> s;   // unique elements and sorted order
    s.insert(5);
    s.insert(1);
    s.insert(3);
    s.insert(3);
    for(int x:s){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<*(s.lower_bound(3))<<endl;  // >=
    cout<<*(s.upper_bound(3))<<endl;  // >
    return 0;    

}