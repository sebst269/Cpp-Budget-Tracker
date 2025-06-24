# cpp-budget-tracker

A simple command-line C++ tool for tracking personal income and expenses.  
Log transactions with a date, category, and amount, then view a summary of all entries with a running total.

---

## Features

- Add income or expense transactions with custom categories  
- View all logged transactions and total balance  
- Save data to a local CSV file (`transactions.csv`)  
- Easy-to-use terminal interface  
- Clean, modular C++ code with file I/O  

---

## Example Usage

```
1. Add Transaction
2. View Transactions
3. Exit

Choose an option: 1
Enter date (YYYY-MM-DD): 2025-06-23
Enter category: groceries
Enter amount (positive for income, negative for expense): -45.90
```

```
--- Transaction History ---
2025-06-23 | groceries | $-45.90
---------------------------
Total: $-45.90
```

---

## Getting Started

### Compile
Make sure you have `g++` installed, then run:
```
g++ main.cpp -o budget_tracker
```

### Run
```
./budget_tracker
```

---

## File Structure

```
cpp-budget-tracker/
├── main.cpp            # Core program logic
├── transactions.csv    # Stores your logged data
└── README.md           # Project overview and usage
``

