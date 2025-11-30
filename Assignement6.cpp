//Q1
// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
//     Node* prev;
// };

// Node* head = NULL;

// void insertBeg(int x) {
//     Node* n = new Node();
//     n->data = x;
//     n->prev = NULL;
//     n->next = head;
//     if (head)
//         head->prev = n;
//     head = n;
// }

// void insertEnd(int x) {
//     Node* n = new Node();
//     n->data = x;
//     n->next = NULL;

//     if (!head) {
//         n->prev = NULL;
//         head = n;
//         return;
//     }

//     Node* t = head;
//     while (t->next)
//         t = t->next;

//     t->next = n;
//     n->prev = t;
// }

// void insertAfter(int val, int x) {
//     Node* t = head;

//     while (t && t->data != val)
//         t = t->next;

//     if (!t)
//         return;

//     Node* n = new Node();
//     n->data = x;
//     n->next = t->next;
//     n->prev = t;

//     if (t->next)
//         t->next->prev = n;

//     t->next = n;
// }

// void deleteValue(int val) {
//     Node* t = head;

//     while (t && t->data != val)
//         t = t->next;

//     if (!t)
//         return;

//     if (t->prev)
//         t->prev->next = t->next;
//     else
//         head = t->next;

//     if (t->next)
//         t->next->prev = t->prev;

//     delete t;
// }

// void search(int val) {
//     Node* t = head;
//     int pos = 1;

//     while (t) {
//         if (t->data == val) {
//             cout << "Found at " << pos << endl;
//             return;
//         }
//         pos++;
//         t = t->next;
//     }

//     cout << "Not Found\n";
// }

// void display() {
//     Node* t = head;
//     while (t) {
//         cout << t->data << " ";
//         t = t->next;
//     }
//     cout << endl;
// }

// int main() {
//     int ch, x, v;

//     while (1) {
//         cout << "\n1.InsertBeg 2.InsertEnd 3.InsertAfter 4.Delete 5.Search 6.Display 7.Exit\n";
//         cin >> ch;

//         if (ch == 7)
//             break;

//         switch (ch) {
//             case 1: cin >> x; insertBeg(x); break;
//             case 2: cin >> x; insertEnd(x); break;
//             case 3: cin >> v >> x; insertAfter(v, x); break;
//             case 4: cin >> v; deleteValue(v); break;
//             case 5: cin >> v; search(v); break;
//             case 6: display(); break;
//         }
//     }
// }


//Q2
// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
// };

// int main() {
//     int arr[] = {20,100,40,80,60};
//     int n = 5;

//     Node* head = NULL;
//     Node* tail = NULL;

//     for (int i = 0; i < n; i++) {
//         Node* t = new Node();
//         t->data = arr[i];
//         t->next = NULL;

//         if (!head)
//             head = tail = t;
//         else {
//             tail->next = t;
//             tail = t;
//         }
//     }

//     tail->next = head;

//     Node* p = head;
//     do {
//         cout << p->data << " ";
//         p = p->next;
//     } while (p != head);

//     cout << head->data;
// }

//Q3
// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
// };

// int main() {
//     Node* head = NULL;
//     Node* tail = NULL;
//     int arr[] = {10,20,30,40,50};

//     for (int i = 0; i < 5; i++) {
//         Node* t = new Node();
//         t->data = arr[i];
//         t->next = NULL;

//         if (!head)
//             head = tail = t;
//         else {
//             tail->next = t;
//             tail = t;
//         }
//     }

//     int countDLL = 0;
//     Node* p = head;

//     while (p) {
//         countDLL++;
//         p = p->next;
//     }

//     tail->next = head;

//     int countCLL = 0;
//     p = head;

//     do {
//         countCLL++;
//         p = p->next;
//     } while (p != head);

//     cout << "DLL Size: " << countDLL << endl;
//     cout << "CLL Size: " << countCLL << endl;
// }


//Q4
// #include <iostream>
// using namespace std;

// struct Node {
//     char data;
//     Node* next;
//     Node* prev;
// };

// int main() {
//     string s = "level";

//     Node* head = NULL;
//     Node* tail = NULL;

//     for (char c : s) {
//         Node* t = new Node();
//         t->data = c;
//         t->next = NULL;
//         t->prev = tail;

//         if (!head)
//             head = t;
//         else
//             tail->next = t;

//         tail = t;
//     }

//     Node* l = head;
//     Node* r = tail;

//     bool pal = true;

//     while (l != r && l->prev != r) {
//         if (l->data != r->data) {
//             pal = false;
//             break;
//         }
//         l = l->next;
//         r = r->prev;
//     }

//     cout << (pal ? "True" : "False");
// }


//Q5
// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
// };

// int main() {
//     int arr[] = {2,4,6,7,5};
//     int n = 5;

//     Node* head = NULL;
//     Node* tail = NULL;

//     for (int i = 0; i < n; i++) {
//         Node* t = new Node();
//         t->data = arr[i];
//         t->next = NULL;

//         if (!head)
//             head = tail = t;
//         else {
//             tail->next = t;
//             tail = t;
//         }
//     }

//     tail->next = head;

//     Node* slow = head;
//     Node* fast = head;

//     bool circular = false;

//     while (fast && fast->next) {
//         slow = slow->next;
//         fast = fast->next->next;

//         if (slow == fast) {
//             circular = true;
//             break;
//         }
//     }

//     cout << (circular ? "True" : "False");
// }