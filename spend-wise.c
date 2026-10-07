//Project: Spend Wise C



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void addExpense();
void viewExpenses();
void analyzeExpenses();
int caseEquals(const char *s1, const char *s2);

struct Expenses {
  float amount;
  char category[20];
  char date[15];
};


void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {

  int choice;

  while(1){
    printf("\n=============================\n");
    printf("         Spend Wise \n");
    printf("=============================\n");
    printf("What would you like to do?\n");
    printf("1. Add Expense\n");
    printf("2. View Expense\n");
    printf("3. Analyze Expense\n");
    printf("4. Exit\n");

    printf("Enter your choice: ");
    if (scanf("%d", &choice) != 1) {
      printf("Invalid input! Please enter a number.\n");
      clearInputBuffer();
      continue;
    }

    switch(choice) {
      case 1:
        addExpense();
        break;

      case 2:
        viewExpenses();
        break;

      case 3:
        analyzeExpenses();
        break;

      case 4:
        printf("\nThank you for using Spend Wise!\n");
        return 0;

      default:
        printf("Input a valid choice!\n");
    }
  }
  return 0;
}

//Function to add Expenses
void addExpense() {
  FILE *fp;
  struct Expenses e;

  fp = fopen("expenses.txt","a");
  if(fp == NULL){
    printf("Error opening file.\n");
    return;
  }

  printf("\nEnter an amount: ");
  while (scanf("%f", &e.amount) != 1 || e.amount <= 0) {
    printf("Invalid amount! Please enter a positive number: ");
    clearInputBuffer();
  }

  printf("Enter category (Food/Travel/Education/Entertainment/Others): ");
  while (scanf("%19s", e.category) != 1) {
    printf("Invalid input! Enter category: ");
    clearInputBuffer();
  }

  printf("Enter the date (YYYY-MM-DD): ");
  while (scanf("%14s", e.date) != 1) {
    printf("Invalid input! Enter date (YYYY-MM-DD): ");
    clearInputBuffer();
  }

  fprintf(fp, "%.2f %s %s\n", e.amount, e.category, e.date);
  fclose(fp);

  printf("Expense added Successfully!\n");
}


int caseEquals(const char *s1, const char *s2) {
  while (*s1 && *s2) {
    if (tolower((unsigned char)*s1) != tolower((unsigned char)*s2))
      return 0;
    s1++;
    s2++;
  }
  return *s1 == *s2;
}

//Function to view Expenses
void viewExpenses() {
  FILE *fp;
  struct Expenses e;
  int count = 0;

  fp = fopen("expenses.txt", "r");
  if(fp == NULL) {
    printf("\nNo records found!\n");
    return;
  }

  printf("\n======================== Expense Records ========================\n");
  printf("%-5s | %-12s | %-18s | %-12s\n", "No.", "Amount (Rs.)", "Category", "Date");
  printf("-----------------------------------------------------------------\n");

  while(fscanf(fp, "%f %19s %14s", &e.amount, e.category, e.date) == 3) {
    count++;
    printf("%-5d | %-12.2f | %-18s | %-12s\n", count, e.amount, e.category, e.date);
  }

  if (count == 0) {
    printf("No expense records found.\n");
  }
  printf("=================================================================\n");
  fclose(fp);
}

// Function to analyze all expense records
void analyzeExpenses() {
  FILE *fp;
  struct Expenses e;

  float total = 0;
  float food = 0, travel = 0;
  float entertainment = 0, education = 0;
  float others = 0;
  int count = 0;
  float budget;

  fp = fopen("expenses.txt", "r");
  if(fp == NULL) {
    printf("\nNo data to analyze!\n");
    return;
  }

  while(fscanf(fp, "%f %19s %14s", &e.amount, e.category, e.date) == 3) {
    total += e.amount;
    count++;

    if (caseEquals(e.category, "Food"))
      food += e.amount;
    else if (caseEquals(e.category, "Travel"))
      travel += e.amount;
    else if (caseEquals(e.category, "Education"))
      education += e.amount;
    else if (caseEquals(e.category, "Entertainment"))
      entertainment += e.amount;
    else
      others += e.amount;
  }
  fclose(fp);

  if(count == 0) {
    printf("\nNo expenses recorded.\n");
    return;
  }

  printf("\nEnter your monthly budget: ");
  while (scanf("%f", &budget) != 1 || budget < 0) {
    printf("Invalid budget! Please enter a valid non-negative number: ");
    clearInputBuffer();
  }

  printf("\n===== Expense Analysis =====\n");
  printf("Total spending: Rs. %.2f\n", total);
  printf("Number of expenses: %d\n", count);
  printf("Average spending: Rs. %.2f\n", total / count);

  printf("\nCategory Breakdown\n");
  printf("Food spending: Rs. %.2f\n", food);
  printf("Travel spending: Rs. %.2f\n", travel);
  printf("Education spending: Rs. %.2f\n", education);
  printf("Entertainment spending: Rs. %.2f\n", entertainment);
  printf("Other spending: Rs. %.2f\n", others);

  // highest category
  float max = 0;
  char highest[20] = "None";

  if (food > max) { max = food; strcpy(highest, "Food"); }
  if (travel > max) { max = travel; strcpy(highest, "Travel"); }
  if (education > max) { max = education; strcpy(highest, "Education"); }
  if (entertainment > max) { max = entertainment; strcpy(highest, "Entertainment"); }
  if (others > max) { max = others; strcpy(highest, "Others"); }

  printf("\nHighest Spending Category: %s\n", highest);

  // smart insight
  if (food > (total * 0.6))
    printf("\nInsight: You are spending more than 60%% of your total expenses on food!\n");
  else
    printf("\nInsight: Your spending habits look balanced.\n");

  if (total > budget)
    printf("Warning: You exceeded your budget by Rs. %.2f!\n", total - budget);
  else
    printf("Good job! You are within your budget (Rs. %.2f remaining).\n", budget - total);

  printf("-----------------------------\n");
}
