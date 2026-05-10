//Project: Spend Wise C



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void addExpense();
void viewExpenses();
void analyzeExpenses();

struct Expenses {
  float amount;
  char category[20];
  char date[15];
};


int main() {

  int choice;

  while(1){
    printf("\n=============================\n");
    printf("         Spend Wise \n");
    printf("\n=============================\n");
    printf("What would you like to do?\n");
    printf("1.Add Expense\n");
    printf("2. View Expense\n");
    printf("3. Analyze Expense\n");
    printf("4. Exit\n");

    printf("Enter your choice: ");
    scanf("%d",&choice);

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

  printf("\nEnter an amount:");
  scanf("%f",&e.amount);

  printf("Enter category (Food/Travel/Education/Entertainment/Others): ");
  scanf("%19s",e.category);

  printf("Enter the date(YYYY-MM-DD): ");
  scanf("%s",e.date);

  fprintf(fp,"%f %s %s\n",e.amount,e.category,e.date);
  fclose(fp);

  printf("Expense added Successfully!\n");
}


//Function to view Expenses
void viewExpenses() {
  FILE *fp;
  struct Expenses e;

  fp = fopen("expenses.txt","r");
  if(fp == NULL) {
    printf("No records found!\n");
    return;
  }

  printf("\n===== Expense Records =====\n");
  while(fscanf(fp,"%f %s %s",&e.amount,e.category,e.date) != EOF) {
    printf("Amount: Rs. %.2f | Category: %s | Date: %s \n",e.amount,e.category,e.date);
  }
  fclose(fp);
}

// Function to analyze all expense records
void analyzeExpenses() {
  FILE *fp;
  struct Expenses e;

  float  total = 0;
  float food = 0, travel = 0;
  float entertainment = 0, education = 0;
  float others = 0;
  int count=0;
  float budget;

  fp = fopen("expenses.txt","r");
  if(fp == NULL) {
    printf("No data to analyze\n");
    return;
  }

  while(fscanf(fp,"%f %s %s",&e.amount,e.category,e.date) != EOF) {
    total += e.amount;
    count++;

  if(strcmp(e.category,"Food") == 0)
  food += e.amount;

  else if(strcmp(e.category,"Travel") == 0)
  travel += e.amount;

  else if(strcmp(e.category,"Education") == 0)
  education += e.amount;

  else if(strcmp(e.category,"Entertainment") == 0)
  entertainment += e.amount;

  else
  others += e.amount;
  }
  fclose(fp);

  printf("\nEnter your monthly budget: ");
  scanf("%f",&budget);
  if(count == 0) {
    printf("No expenses recorded.\n");
    return;
  }

  printf("\n===== Expense Analysis =====\n");
  printf("Total spending: Rs. %.2f\n",total);
  printf("Number of expenses: %d\n",count);
  printf("Average spending: Rs. %.2f\n", total / count);

  printf("\nCategory Breakdown\n");
  printf("Food spending: Rs. %.2f\n", food);
  printf("Travel spending: Rs. %.2f\n", travel);
  printf("Education spending: Rs.%.2f\n",education);
  printf("Entertainment spending: Rs.%.2f\n",entertainment);
  printf("Other spending: Rs. %.2f\n", others);

  // highest category
  float max = food;
  char highest[20] = "Food";
  
  if(travel > max) {
    max = travel;
    strcpy(highest, "Travel");
  }
  if(education > max) {
    max = education;
    strcpy(highest, "Education");
  }
  if(entertainment > max) {
    max = entertainment;
    strcpy(highest, "Entertainment");
  }
  if(others > max) {
    max = others;
    strcpy(highest, "Others");
  }
  printf("\nHighest Spending: %s\n", highest);

  // smart insight
if (food > (total / 2))
    printf("\nYou are spending too much on food!\n");
else 
    printf("\nYour spending habits look balanced\n");

if(total > budget)
    printf("Warning: You exceeded your budget!\n");
else
    printf("Good! You are within your budget.\n");

printf("\n-----------------------------\n");
}
