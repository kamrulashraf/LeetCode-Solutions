#include <bits/stdc++.h>
using namespace std;



struct node{
      int val;
      node* next;
};

struct comp{
      bool operator()(const node *a,const node *b){
            return a->val < b->val;
      }
};


int main(){
      int n;
      cin >> n;
      
      while(n){
            cout << n << endl;
            n -= n&-n;
      }

}

