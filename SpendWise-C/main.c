#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void addExpense();
void viewExpense();
void analyzeExpense();

int main() {

  int choice;

  while(1){
  printf("--Spend Wise--\n");
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

    default:
    printf("Input a valid choice!\n");
  }
}
  return 0;
}