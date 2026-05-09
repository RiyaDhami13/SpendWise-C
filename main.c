#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void addExpense();
void viewExpenses();
void analyzeExpenses();

int main() {

  int choice;

  while(1){
    printf("\n===== Spend Wise =====\n");
    printf("what do you want to do\n");
    printf("1.Add Expense\n");
    printf("2. View Expense\n");
    printf("3. Analyze Expense\n");
    printf("4. Exit\n");

    printf("Enter your choice\n");
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
        printf("Exiting program---\n");
        return 0;

      default:
        printf("Input a valid choice!\n");
    }
  }
  return 0;
}

void addExpense() {
  FILE *fp;
  float amount;
  char category[20], date[15];

  fp = fopen("expenses.txt","a");
  if(fp == NULL){
    printf("Error opening file.\n");
    return;
  }

  printf("\nEnter an amount:");
  scanf("%f",&amount);

  printf("Enter category exactly as Food, Travel, or Others: ");
  scanf("%s",category);

  printf("Enter the date(YYYY-MM-DD): ");
  scanf("%s",date);

  fprintf(fp,"%f %s %s\n",amount,category,date);
  fclose(fp);

  printf("Expense added Successfully!\n");
}

void viewExpenses() {
  FILE *fp;
  float amount;
  char category[20], date[15];

  fp = fopen("expenses.txt","r");
  if(fp == NULL) {
    printf("No records found!\n");
    return;
  }

  printf("\n -- Expenses Record---\n");
  while(fscanf(fp,"%f %s %s",&amount,category,date) != EOF) {
    printf("Amount: Rs. %.2f | Category: %s | Date: %s \n",amount,category,date);
  }
  fclose(fp);
}

void analyzeExpenses() {
  FILE *fp;
  float amount, total = 0;
  float food = 0, travel = 0, others = 0;
  char category[20], date[15];
  int count=0;

  fp = fopen("expenses.txt","r");
  if(fp == NULL) {
    printf("No data to analyze\n");
    return;
  }

  while(fscanf(fp,"%f %s %s",&amount,category,date) != EOF) {
    total += amount;
    count++;

    if(strcmp(category,"Food") == 0)
      food += amount;
    else if(strcmp(category,"Travel") == 0)
      travel += amount;
    else
      others += amount;
  }
  fclose(fp);

  if(count == 0) {
    printf("No expenses recorded.\n");
    return;
  }

  printf("\n--Expenses Analysis--\n");
  printf("Total spending: Rs. %.2f\n",total);
  printf("Number of expenses: %d\n",count);
  printf("Average spending: Rs. %.2f\n", total / count);

  printf("\nCategory Breakdown\n");
  printf("Food spending: Rs. %.2f\n", food);
  printf("Travel spending: Rs. %.2f\n", travel);
  printf("Other spending: Rs. %.2f\n", others);

  // highest category
  if (food > travel && food > others) {
    printf("\nHighest Spending: Food\n");
  } else if (travel > food && travel > others) {
    printf("\nHighest Spending: Travel\n");
  } else {
    printf("\nHighest Spending: Others\n");
  }

  // smart insight
  if (food > (total / 2))
    printf("\nYou are spending too much on food!\n");
}
