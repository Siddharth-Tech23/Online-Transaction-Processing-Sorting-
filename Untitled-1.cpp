#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Transaction {
    string transaction_id;
    string user_id;
    double amount;
    string timestamp;
    string status;
};
void insertionSort(vector<Transaction>& transactions) {
    for (int i = 1; i < transactions.size(); i++) {
        Transaction key = transactions[i];
        int j = i - 1;

        while (j >= 0 && transactions[j].timestamp > key.timestamp) {
            transactions[j + 1] = transactions[j];
            j--;
        }
        transactions[j + 1] = key;
    }
}

void printTransactions(const vector<Transaction>& transactions) {
    cout << left << setw(12) << "Txn_ID" << setw(10) << "User_ID" << setw(10) 
         << "Amount" << setw(20) << "Timestamp" << "Status" << endl;
    for (const auto& txn : transactions) {
        cout << left << setw(12) << txn.transaction_id << setw(10) << txn.user_id 
             << setw(10) << txn.amount << setw(20) << txn.timestamp << txn.status << endl;
    }
}

vector<Transaction> loadTransactionsFromCSV(const string& filename) {
    vector<Transaction> transactions;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file!" << endl;
        return transactions;
    }

    string line;
    getline(file, line); 

    while (getline(file, line)) {
        stringstream ss(line);
        Transaction txn;
        string amount_str;

        getline(ss, txn.transaction_id, ',');
        getline(ss, txn.user_id, ',');
        getline(ss, amount_str, ',');
        txn.amount = stod(amount_str);
        getline(ss, txn.timestamp, ',');
        getline(ss, txn.status, ',');

        transactions.push_back(txn);
    }

    file.close();
    return transactions;
}

int main() {
    vector<Transaction> transactions = loadTransactionsFromCSV("C:/Users/siddh/OneDrive/Desktop/projecy/transactions.csv");

    cout << "Before Sorting:\n";
    printTransactions(transactions);

    insertionSort(transactions);

    cout << "\nAfter Sorting:\n";
    printTransactions(transactions);

    return 0;
}