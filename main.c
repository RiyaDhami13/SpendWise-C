#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void addExpense();
void viewExpense();
void analyzeExpense();

int main() {

  int choice;

  //while loop ..infinite loop chaluxa
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



void addExpense() {
  FILE *fp;
  float amount;
  char categeory[20], date[15];

  fp = fopen("expenses.txt","a");

  if(fp == NULL){
    printf("Error opening file.\n");
    return;
  }

printf("\nEnter an amount:");
scanf("%f",&amount);

printf("Enter categeroy(Food, Travel, or Others):");
scanf("%s",categeory);

printf("Enter the date(YYYY-MM-DD)");
scanf("%s",date);

fprintf(fp,"%f%s%s\n",amount,categeory,date);

fclose(fp);

printf("Expense added Successfully!\n");
}