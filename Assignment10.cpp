//Q1
// #include <iostream>
// #include <unordered_set>
// using namespace std;

// int main(){
//     int nums[] = {1,2,3,1};
//     int n = 4;

//     unordered_set<int> s;
//     bool dup = false;

//     for(int i=0;i<n;i++){
//         if(s.count(nums[i])){
//             dup = true;
//             break;
//         }
//         s.insert(nums[i]);
//     }

//     cout << (dup ? "true" : "false");
// }


//Q2
// #include <iostream>
// #include <unordered_set>
// using namespace std;

// int main(){
//     int A[] = {1,2,3,4};
//     int B[] = {3,4,5,6};

//     unordered_set<int> s;

//     for(int i=0;i<4;i++)
//         s.insert(A[i]);

//     for(int i=0;i<4;i++)
//         if(s.count(B[i]))
//             cout << B[i] << " ";
// }


//Q3
// #include <iostream>
// #include <unordered_map>
// using namespace std;

// int main(){
//     int nums[] = {2,3,2,4,3,2};
//     int n = 6;

//     unordered_map<int,int> m;

//     for(int i=0;i<n;i++)
//         m[nums[i]]++;

//     for(auto x : m)
//         cout << x.first << " -> " << x.second << " times\n";
// }



//Q4
// #include <iostream>
// #include <unordered_map>
// using namespace std;

// int main(){
//     int nums[] = {4,5,1,2,0,4};
//     int n = 6;

//     unordered_map<int,int> m;

//     for(int i=0;i<n;i++)
//         m[nums[i]]++;

//     for(int i=0;i<n;i++){
//         if(m[nums[i]] == 1){
//             cout << nums[i];
//             break;
//         }
//     }
// }



//Q5
// #include <iostream>
// #include <unordered_set>
// using namespace std;

// struct Node{
//     int data;
//     Node* next;
// };

// int main(){
//     Node* n1=new Node{1,NULL};
//     Node* n2=new Node{2,NULL};
//     Node* n3=new Node{3,NULL};
//     Node* n4=new Node{4,NULL};

//     n1->next=n2;
//     n2->next=n3;
//     n3->next=n4;
//     n4->next=n2;

//     unordered_set<Node*> s;

//     Node* t=n1;
//     bool cycle=false;

//     while(t){
//         if(s.count(t)){
//             cycle=true;
//             break;
//         }
//         s.insert(t);
//         t=t->next;
//     }

//     cout << (cycle ? "true" : "false");
// }



//Q6
// #include <iostream>
// #include <unordered_set>
// using namespace std;

// struct Node{
//     int data;
//     Node* left;
//     Node* right;
// };

// Node* newNode(int x){
//     Node* t=new Node();
//     t->data=x;
//     t->left=t->right=NULL;
//     return t;
// }

// bool check(Node* r, unordered_set<int>& s){
//     if(!r) return false;

//     if(s.count(r->data))
//         return true;

//     s.insert(r->data);

//     return check(r->left,s) || check(r->right,s);
// }

// int main(){
//     Node* root=newNode(1);
//     root->left=newNode(2);
//     root->right=newNode(3);
//     root->left->left=newNode(4);
//     root->right->left=newNode(2);

//     unordered_set<int> s;

//     bool dup = check(root,s);

//     cout << (dup ? "Duplicates Found" : "No Duplicates");
// }