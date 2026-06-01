# SpendWise-C 💰
A lightweight, terminal-based expense tracking system written entirely in C.

SpendWise allows users to record expenses, store them permanently, and analyze spending patterns such as total expenditure and category-wise distribution.

## 📺 Project Demo
Watch the program in action here: [SpendWise Demo Video](https://youtu.be/Q-0WUm8FaR0?si=jcScA7NTmmdLctOZ)

## 🚀 How to Run
1. **Source Code:** Compile `spend-wise.c` using GCC.
2. **Executable:** You can run the pre-compiled `spend-wise.exe` (Windows only).

## Program Features ✨
- **Add daily expenses:** Input amount, category, and date.
- **Permanent Storage:** Saves records in `expenses.txt`.
- **View Records:** Displays all saved expenses in a formatted list.
- **Smart Analysis:** - Calculates total and average spending.
  - Identifies highest spending category.
  - Compares spending against a set budget.

## Concepts Used 🧠
This project applies fundamental C programming concepts:
- **Structures (`struct`):** To organize expense data.
- **File Handling:** Using `fopen`, `fprintf`, and `fscanf` for persistence.
- **Control Flow:** `while` loops for the menu and `switch` cases for logic.
- **String Manipulation:** Using `strcmp` for category filtering.

## Project Structure 📂
```text
SpendWise-C/
│── .vscode/           # Editor configuration and debugger settings
│── spend-wise.c       # Main source code
│── spend-wise.exe     # Compiled executable for Windows
│── expenses.txt       # Data file where expenses are stored
│── .gitignore         # Prevents unnecessary files from being tracked
│── LICENSE            # Project license
└── README.md          # Project documentation