#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

struct Transaction {
    std::string date;
    std::string category;
    double amount;
};

void saveTransaction(const Transaction& t, const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    file << t.date << "," << t.category << "," << t.amount << std::endl;
    file.close();
}

void viewTransactions(const std::string& filename) {
    std::ifstream file(filename);
    std::string date, category;
    double amount;
    double total = 0.0;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n--- Transaction History ---\n";
    while (file >> date) {
        getline(file, category, ',');
        file >> amount;
        file.ignore(1); // skip newline
        std::cout << date << " | " << category.substr(1) << " | $" << amount << "\n";
        total += amount;
    }
    std::cout << "---------------------------\n";
    std::cout << "Total: $" << total << "\n\n";
    file.close();
}

int main() {
    std::string filename = "transactions.csv";
    int choice;
    do {
        std::cout << "1. Add Transaction\n";
        std::cout << "2. View Transactions\n";
        std::cout << "3. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        if (choice == 1) {
            Transaction t;
            std::cout << "Enter date (YYYY-MM-DD): ";
            std::cin >> t.date;
            std::cout << "Enter category: ";
            std::cin >> t.category;
            std::cout << "Enter amount (positive for income, negative for expense): ";
            std::cin >> t.amount;
            saveTransaction(t, filename);
        } else if (choice == 2) {
            viewTransactions(filename);
