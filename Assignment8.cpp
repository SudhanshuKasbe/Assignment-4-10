//1
// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* left;
//     Node* right;
// };

// Node* newNode(int x) {
//     Node* t=new Node();
//     t->data=x;
//     t->left=NULL;
//     t->right=NULL;
//     return t;
// }

// void preorder(Node* r) {
//     if(r){
//         cout<<r->data<<" ";
//         preorder(r->left);
//         preorder(r->right);
//     }
// }

// void inorder(Node* r) {
//     if(r){
//         inorder(r->left);
//         cout<<r->data<<" ";
//         inorder(r->right);
//     }
// }

// void postorder(Node* r) {
//     if(r){
//         postorder(r->left);
//         postorder(r->right);
//         cout<<r->data<<" ";
//     }
// }

// int main() {
//     Node* root=newNode(10);
//     root->left=newNode(5);
//     root->right=newNode(20);
//     root->left->left=newNode(2);
//     root->left->right=newNode(8);

//     preorder(root);
//     cout<<endl;
//     inorder(root);
//     cout<<endl;
//     postorder(root);
// }



//2
// #include <iostream>
// using namespace std;

// struct Node{
//     int data;
//     Node* left;
//     Node* right;
// };

// Node* insert(Node* r,int x){
//     if(!r){
//         r=new Node();
//         r->data=x;
//         r->left=r->right=NULL;
//         return r;
//     }
//     if(x<r->data) r->left=insert(r->left,x);
//     else if(x>r->data) r->right=insert(r->right,x);
//     return r;
// }

// bool searchRec(Node* r,int x){
//     if(!r) return false;
//     if(r->data==x) return true;
//     if(x<r->data) return searchRec(r->left,x);
//     return searchRec(r->right,x);
// }

// bool searchNonRec(Node* r,int x){
//     while(r){
//         if(r->data==x) return true;
//         if(x<r->data) r=r->left;
//         else r=r->right;
//     }
//     return false;
// }

// int maxBST(Node* r){
//     while(r->right) r=r->right;
//     return r->data;
// }

// int minBST(Node* r){
//     while(r->left) r=r->left;
//     return r->data;
// }

// Node* inorderSuccessor(Node* root,Node* n){
//     Node* succ=NULL;
//     while(root){
//         if(n->data<root->data){
//             succ=root;
//             root=root->left;
//         }
//         else root=root->right;
//     }
//     return succ;
// }

// Node* inorderPredecessor(Node* root,Node* n){
//     Node* pred=NULL;
//     while(root){
//         if(n->data>root->data){
//             pred=root;
//             root=root->right;
//         }
//         else root=root->left;
//     }
//     return pred;
// }

// Node* find(Node* r,int x){
//     while(r && r->data!=x){
//         if(x<r->data) r=r->left;
//         else r=r->right;
//     }
//     return r;
// }

// int main(){
//     Node* root=NULL;
//     int a[]={50,30,70,20,40,60,80};

//     for(int i=0;i<7;i++)
//         root=insert(root,a[i]);

//     cout<<searchRec(root,40)<<endl;
//     cout<<searchNonRec(root,90)<<endl;

//     cout<<maxBST(root)<<endl;
//     cout<<minBST(root)<<endl;

//     Node* n=find(root,40);

//     Node* s=inorderSuccessor(root,n);
//     Node* p=inorderPredecessor(root,n);

//     if(s) cout<<s->data<<endl;
//     if(p) cout<<p->data<<endl;
// }



//3
// #include <iostream>
// using namespace std;

// struct Node{
//     int data;
//     Node* left;
//     Node* right;
// };

// Node* insert(Node* r,int x){
//     if(!r){
//         Node* t=new Node();
//         t->data=x;
//         t->left=t->right=NULL;
//         return t;
//     }
//     if(x<r->data) r->left=insert(r->left,x);
//     else if(x>r->data) r->right=insert(r->right,x);
//     return r;
// }

// Node* minNode(Node* r){
//     while(r->left) r=r->left;
//     return r;
// }

// Node* deleteNode(Node* r,int x){
//     if(!r) return r;

//     if(x<r->data)
//         r->left=deleteNode(r->left,x);
//     else if(x>r->data)
//         r->right=deleteNode(r->right,x);
//     else{
//         if(!r->left){
//             Node* t=r->right;
//             delete r;
//             return t;
//         }
//         else if(!r->right){
//             Node* t=r->left;
//             delete r;
//             return t;
//         }

//         Node* t=minNode(r->right);
//         r->data=t->data;
//         r->right=deleteNode(r->right,t->data);
//     }
//     return r;
// }

// int maxDepth(Node* r){
//     if(!r) return 0;
//     int l=maxDepth(r->left);
//     int d=maxDepth(r->right);
//     return (l>d?l:d)+1;
// }

// int minDepth(Node* r){
//     if(!r) return 0;
//     if(!r->left) return minDepth(r->right)+1;
//     if(!r->right) return minDepth(r->left)+1;

//     int l=minDepth(r->left);
//     int d=minDepth(r->right);

//     return (l<d?l:d)+1;
// }

// int main(){
//     Node* root=NULL;
//     int a[]={40,20,60,10,30,50,70};

//     for(int i=0;i<7;i++)
//         root=insert(root,a[i]);

//     root=deleteNode(root,20);

//     cout<<maxDepth(root)<<endl;
//     cout<<minDepth(root)<<endl;
// }



//4
// #include <iostream>
// #include <climits>
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

// bool check(Node* r,int mn,int mx){
//     if(!r) return true;

//     if(r->data<=mn || r->data>=mx)
//         return false;

//     return check(r->left,mn,r->data) &&
//            check(r->right,r->data,mx);
// }

// int main(){
//     Node* root=newNode(10);
//     root->left=newNode(5);
//     root->right=newNode(20);
//     root->left->left=newNode(2);

//     cout<<check(root,INT_MIN,INT_MAX);
// }




//5
// #include <iostream>
// using namespace std;

// void heapify(int a[],int n,int i){
//     int l=2*i+1;
//     int r=2*i+2;
//     int max=i;

//     if(l<n && a[l]>a[max]) max=l;
//     if(r<n && a[r]>a[max]) max=r;

//     if(max!=i){
//         int t=a[i]; a[i]=a[max]; a[max]=t;
//         heapify(a,n,max);
//     }
// }

// void heapSort(int a[],int n){
//     for(int i=n/2-1;i>=0;i--)
//         heapify(a,n,i);

//     for(int i=n-1;i>=0;i--){
//         int t=a[0]; a[0]=a[i]; a[i]=t;
//         heapify(a,i,0);
//     }
// }

// int main(){
//     int a[]={5,3,8,4,1};
//     int n=5;

//     heapSort(a,n);

//     for(int i=0;i<n;i++)
//         cout<<a[i]<<" ";
// }



//6
// #include <iostream>
// using namespace std;

// #define MAX 50
// int heap[MAX];
// int size=0;

// void push(int x){
//     int i=size++;
//     heap[i]=x;

//     while(i!=0 && heap[(i-1)/2]<heap[i]){
//         int t=heap[i];
//         heap[i]=heap[(i-1)/2];
//         heap[(i-1)/2]=t;
//         i=(i-1)/2;
//     }
// }

// void pop(){
//     if(size==0) return;

//     heap[0]=heap[--size];
//     int i=0;

//     while(2*i+1<size){
//         int l=2*i+1;
//         int r=2*i+2;
//         int m=l;

//         if(r<size && heap[r]>heap[l])
//             m=r;

//         if(heap[i]<heap[m]){
//             int t=heap[i];
//             heap[i]=heap[m];
//             heap[m]=t;
//             i=m;
//         }
//         else break;
//     }
// }

// void display(){
//     for(int i=0;i<size;i++)
//         cout<<heap[i]<<" ";
//     cout<<endl;
// }

// int main(){
//     push(40);
//     push(10);
//     push(50);
//     push(20);

//     display();

//     pop();

//     display();
// }