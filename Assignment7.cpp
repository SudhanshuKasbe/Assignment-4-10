//1(a)
// #include <iostream>
// using namespace std;

// int main() {
//     int a[] = {5,4,3,2,1};
//     int n = 5;

//     for (int i = 0; i < n - 1; i++) {
//         int min = i;

//         for (int j = i + 1; j < n; j++)
//             if (a[j] < a[min])
//                 min = j;

//         int t = a[i];
//         a[i] = a[min];
//         a[min] = t;
//     }

//     for (int i = 0; i < n; i++)
//         cout << a[i] << " ";
// }


//1(b)
// #include <iostream>
// using namespace std;

// int main() {
//     int a[] = {5,4,3,2,1};
//     int n = 5;

//     for (int i = 1; i < n; i++) {
//         int key = a[i];
//         int j = i - 1;

//         while (j >= 0 && a[j] > key) {
//             a[j + 1] = a[j];
//             j--;
//         }

//         a[j + 1] = key;
//     }

//     for (int i = 0; i < n; i++)
//         cout << a[i] << " ";
// }



//1(c)
// #include <iostream>
// using namespace std;

// int main() {
//     int a[] = {5,4,3,2,1};
//     int n = 5;

//     for (int i = 0; i < n - 1; i++)
//         for (int j = 0; j < n - i - 1; j++)
//             if (a[j] > a[j + 1]) {
//                 int t = a[j];
//                 a[j] = a[j + 1];
//                 a[j + 1] = t;
//             }

//     for (int i = 0; i < n; i++)
//         cout << a[i] << " ";
// }


//1(d)
// #include <iostream>
// using namespace std;

// void merge(int a[], int l, int m, int r) {
//     int n1 = m - l + 1;
//     int n2 = r - m;

//     int L[n1], R[n2];

//     for (int i = 0; i < n1; i++)
//         L[i] = a[l + i];
//     for (int i = 0; i < n2; i++)
//         R[i] = a[m + 1 + i];

//     int i = 0, j = 0, k = l;

//     while (i < n1 && j < n2) {
//         if (L[i] <= R[j])
//             a[k++] = L[i++];
//         else
//             a[k++] = R[j++];
//     }

//     while (i < n1)
//         a[k++] = L[i++];

//     while (j < n2)
//         a[k++] = R[j++];
// }

// void mergeSort(int a[], int l, int r) {
//     if (l < r) {
//         int m = (l + r) / 2;

//         mergeSort(a, l, m);
//         mergeSort(a, m + 1, r);

//         merge(a, l, m, r);
//     }
// }

// int main() {
//     int a[] = {5,4,3,2,1};
//     int n = 5;

//     mergeSort(a, 0, n - 1);

//     for (int i = 0; i < n; i++)
//         cout << a[i] << " ";
// }


//1(e)
// #include <iostream>
// using namespace std;

// int partition(int a[], int low, int high) {
//     int p = a[high];
//     int i = low - 1;

//     for (int j = low; j < high; j++) {
//         if (a[j] < p) {
//             i++;
//             int t = a[i];
//             a[i] = a[j];
//             a[j] = t;
//         }
//     }

//     int t = a[i + 1];
//     a[i + 1] = a[high];
//     a[high] = t;

//     return i + 1;
// }

// void quickSort(int a[], int low, int high) {
//     if (low < high) {
//         int pi = partition(a, low, high);

//         quickSort(a, low, pi - 1);
//         quickSort(a, pi + 1, high);
//     }
// }

// int main() {
//     int a[] = {5,4,3,2,1};
//     int n = 5;

//     quickSort(a, 0, n - 1);

//     for (int i = 0; i < n; i++)
//         cout << a[i] << " ";
// }



//2
// #include <iostream>
// using namespace std;

// int main() {
//     int a[] = {9,3,5,1,8,7,2,4,6};
//     int n = 9;

//     int start = 0, end = n - 1;

//     while (start < end) {
//         int min = start;
//         int max = start;

//         for (int i = start; i <= end; i++) {
//             if (a[i] < a[min])
//                 min = i;
//             if (a[i] > a[max])
//                 max = i;
//         }

//         int t = a[start];
//         a[start] = a[min];
//         a[min] = t;

//         if (max == start)
//             max = min;

//         t = a[end];
//         a[end] = a[max];
//         a[max] = t;

//         start++;
//         end--;
//     }

//     for (int i = 0; i < n; i++)
//         cout << a[i] << " ";
// }