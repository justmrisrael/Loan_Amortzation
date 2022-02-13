#include <stdio.h>
#include <stdlib.h>
#include "amortTable.h"
#include "account.h"

int main(int argc, char **argv)
{

    // double amount, monthly, annual;
    int line;

    // input user data
    printf("Enter loan ammount:\n");
    scanf("%lf", &account.amount);

    printf("Enter monthly payment:\n");
    scanf("%lf", &account.monthly);

    printf("Enter annual interest rate (0.0-1.0):\n");
    scanf("%lf", &account.annual);

    while (!((account.annual <= 1.0) && (account.annual >= 0.0)))
    {
        printf("[ERROR] The number you entered is out of range\n");
        printf("Enter interst in range (0.0-1.0)\n");
        scanf("%lf", &account.annual);
    }
    gen_amort(account.monthly, account.annual, account.amount);

    // menu options
    int choice = 0;
    while (choice != 3)
    {
        printf("Menu:\n");
        printf("1. Print Amoritization Table\n");
        printf("2. Print a row in the table\n");
        printf("3. Quit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("You selected option 1\n");
            print_amort();
            break;
        case 2:
            printf("You selected option 2\n");
            printf("What row would you like to see?\n");
            scanf("%d", &line);
            print_line(account.monthly, account.annual, account.amount, line);
            break;
        case 3:
            exit(0);
        default:
            printf("\n!!!!!!!!!!!!\nWrong option! choose again!\n!!!!!!!!!!!!\n");
        }
    }

    return 0;
}