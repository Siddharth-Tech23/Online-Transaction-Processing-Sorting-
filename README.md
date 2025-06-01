# 📊 Online Transaction Processing - Sorting

A practical project demonstrating how to optimize **Online Transaction Processing (OTP)** systems by maintaining a sorted list of transactions using **Insertion Sort**.

---

## 📝 Problem Statement

Efficiently maintain a sorted list of transactions in **real-time systems**, where transactions arrive continuously.  
Maintaining a sorted log ensures:

- ⚡ Quick retrieval of data  
- 📈 Accurate and real-time data tracking  
- 📊 Smooth transaction processing  

---

## 💡 Importance

In **Online Transaction Processing (OTP)**:

- Transactions are continuously generated
- Keeping them sorted enhances system efficiency
- Critical for **financial systems, real-time dashboards, and e-commerce apps**

This project shows how **Insertion Sort** can be applied effectively in such scenarios.

---

## 🛠️ Tech Stack

- **C++**
- Standard libraries (iostream, vector)
- Basic console I/O

---

## 📦 Code Example

```cpp
#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& transactions) {
    int n = transactions.size();
    for (int i = 1; i < n; i++) {
        int key = transactions[i];
        int j = i - 1;
        while (j >= 0 && transactions[j] > key) {
            transactions[j + 1] = transactions[j];
            j = j - 1;
        }
        transactions[j + 1] = key;
    }
}

int main() {
    vector<int> transactions = {500, 200, 700, 300, 100};

    cout << "Before Sorting:\n";
    for (int t : transactions)
        cout << t << " ";

    insertionSort(transactions);

    cout << "\nAfter Sorting:\n";
    for (int t : transactions)
        cout << t << " ";

    return 0;
}
