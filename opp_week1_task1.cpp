#include <iostream>
#include <string>
using namespace std;
void createArray(int a[], int size);
void printArray(int a[], int n);
void reverse(int a[], int size);
int maxArray(int a[], int size);
void selectSort(int a[], int size);
bool isSort(int a[], int n);
int search1(int a[], int size, int x);
int search2(int a[], int x, int right, int left = 0);

int main() {
  int select, a[10000], size, index, n, x;
  cout << "MENU\n";
  cout << "0. Dong chuong trinh.\n";
  cout << "1. Tao mang.\n";
  cout << "2. Ham in n so nguyen trong mang a, tach nhau boi dau phay.\n";
  cout << "3. Dao chieu mang a.\n";
  cout << "4. Tim so lon nhat tong mang.\n";
  cout << "5. Sap xep mang theo chieu tang dan bang select sort.\n";
  cout << "6. Kiem tra mang a co sap xep tang dan hay khong.\n";
  cout << "7. Tim so nguyen x co trong mang hay khong.\n";
  select = 1;
  while (select) {
    cout << "\nChon chuc nang: ";
    cin >> select;
    if (select == 0) {
      cout << "Chuong trinh da dong.";
    } else {
      switch (select) {
      case 1: {
        cout << "Tao mang.\n";
        cout << "Nhap do lon cho mang: ";
        cin >> size;
        createArray(a, size);
        break;
      }
      case 2: {
        cout << "In n so nguyen trong mang a, tach nhau boi dau phay.\n";
        cout << "Nhap n: ";
        cin >> n;
        printArray(a, n);
        break;
      }
      case 3: {
        cout << "Dao chieu mang a.\n";
        cout << "Mang a ban dau.\n";
        printArray(a, size);
        reverse(a, size);
        cout << "Sau khi dao chieu.\n";
        printArray(a, size);
        break;
      }
      case 4: {
        cout << "Tim so lon nhat tong mang.\n";
        cout << "So lo nhat trong mang la: " << maxArray(a, size) << endl;
        break;
      }
      case 5: {
        cout << "Sap xep mang theo chieu tang dan bang select sort.\n";
        cout << "Mang a ban dau.\n";
        printArray(a, size);
        selectSort(a, size);
        cout << "Sau khi sap xep.\n";
        printArray(a, size);
        break;
      }
      case 6: {
        cout << "Kiem tra mang a co sap xep tang dan hay khong.\n";
        if (isSort(a, size))
          cout << "True\n";
        else
          cout << "False\n";
        break;
      }
      case 7: {
        cout << "Tim so nguyen x co trong mang hay khong.\n";
        cout << "Nhap x: ";
        cin >> x;
        if (isSort(a, size)) {
          index = search2(a, x, size - 1);
          if (index == -1)
            cout << "x khong co trong mang a.\n";
          else
            cout << "x nam o vi tri " << index << " trong mang a.\n";
        } else {
          index = search1(a, size, x);
          if (index == -1)
            cout << "x khong co trong mang a.\n";
          else
            cout << "x nam o vi tri " << index << " trong mang a.\n";
        }
        break;
      }
      }
    }
  }
  return 0;
}

void createArray(int a[], int size) {
  for (int i = 0; i < size; i++) {
    cout << "Nhap vao phan tu a[" << i << "] : ";
    cin >> a[i];
  }
}
void printArray(int a[], int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i];
    if (i != n - 1)
      cout << ", ";
    else
      cout << endl;
  }
}
void reverse(int a[], int size) {
  for (int i = 0; i < size / 2; i++) {
    int temp = a[i];
    a[i] = a[size - 1 - i];
    a[size - 1 - i] = temp;
  }
}
int maxArray(int a[], int size) {
  string str;
  int max;
  str = "None";
  if (size != 0) {
    for (int i = 0; i < size; i++) {
      if (str == "None") {
        str = to_string(a[i]);
        max = stoi(str);
      } else {
        if (a[i] > max)
          max = a[i];
      }
    }
    return max;
  }
  return -1;
}
void selectSort(int a[], int size) {
  for (int i = 0; i < size - 1; i++) {
    int imin = i;
    for (int j = i + 1; j < size; j++) {
      if (a[imin] > a[j]) {
        int temp = a[imin];
        a[imin] = a[j];
        a[j] = temp;
      }
    }
  }
}
bool isSort(int a[], int size) {
  for (int i = 0; i < size - 1; i++) {
    if (a[i] > a[i + 1])
      return false;
  }
  return true;
}
int search1(int a[], int size, int x) {
  for (int i = 0; i < size; i++) {
    if (x == a[i])
      return i;
  }
  return -1;
}
int search2(int a[], int x, int right, int left) {
  int mid = (left + right) / 2;
  if (right - left <= 1) {
    if (x == a[left]) return left;
    else if (x == a[right]) return right;
    else return -1;
  }
  else if (x== a[mid]) return mid;
  else if (x > a[mid]) return search2(a, x, right, mid);
  else if (x < a[mid]) return search2(a, x, mid, left);
}