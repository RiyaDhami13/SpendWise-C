# SpendWise-C
A lightweight, terminal-based expense tracking system written entirely in C

 C-based Expense Analyzer that allows users to record expenses, store them in a file, and analyze spending patterns such as total expenditure and category-wise distribution.

## Program Features

- Add daily expenses
- Store records permanently using files
- View all saved expenses
- Analyze total and average spending
- Category-wise expense analysis
- Budget comparison feature

## How It Works ⚙️

The program follows a menu-driven approach.

When the application starts, users are presented with four options:

1. Add Expense  
2. View Expense  
3. Analyze Expense  
4. Exit  

### 1. Add Expense
Users enter:
- Expense amount
- Category (Food, Travel, Education, Entertainment, Others)
- Date

The data is then stored permanently in a text file (`expenses.txt`) using file handling.

### 2. View Expense
The program reads all saved expense records from the file and displays them in a readable format.

### 3. Analyze Expense
The program:
- Calculates total spending
- Counts total expenses
- Calculates average spending
- Shows category-wise spending
- Identifies highest spending category
- Compares expenses with user budget

### 4. Exit
Safely closes the program.


## Concepts Used 🧠

This project applies the following C programming concepts:

- Functions
- Structures (`struct`)
- File Handling (`fopen`, `fprintf`, `fscanf`, `fclose`)
- Loops (`while`)
- Conditional Statements (`if-else`, `switch`)
- Strings (`strcmp`)

---


## Demo Link *https://youtu.be/V3avz6Iy_cY?si=weoPOqK5V_GtDm_D*

## Technologies Used 🛠️

- **Programming Language:** C
- **Compiler:** GCC / MinGW
- **IDE/Editor:** VS Code / Online GDB

---

## Project Structure 📂

```text
SpendWise-C/
│── main.c
│── expenses.txt
│── README.md
