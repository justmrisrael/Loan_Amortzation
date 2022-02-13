// In the amortization table, you are supposed to have an array of a data
// strcuture to represent each table entry along with the number of table
// entries.

//    The following functions are needed:
//        a. print the table as shown above
//        b. print a specif row of the table based on a row number

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "amortTable.h"
#include "account.h"


void print_amort()
{
    int size = sizeof table.payment / sizeof *table.payment;
    printf("\n\nPayment #\tPrevious Balance\t$Interest\tPrincipal\tNew Balance\n");
    printf("---------\t----------------\t--------\t---------\t-----------\n");
    for (int i = 0; i <= size; i++)
    {
        printf("%d\t\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", table.payment[i], table.previous_balance[i], table.interest[i], table.principal[i], table.new_balance[i]);
    }
    printf("---------\t----------------\t--------\t---------\t-----------\n");
    return;
}

void print_line(double payment, double interest, double amount, int line)
{
    double monthly_interest;
    double new_balance, d_interest, principal;
    double previous_balance = 0;

    // calculations
    monthly_interest = interest / 12;
    previous_balance = amount;

    printf("\n\nPayment #\tPrevious Balance\t$Interest\tPrincipal\tNew Balance\n");
    printf("---------\t----------------\t--------\t---------\t-----------\n");

    for (int i = 1; i <= MAX; i++)
    {
        d_interest = monthly_interest * previous_balance;
        principal = payment - d_interest;
        new_balance = previous_balance - principal;
        if (line == i && i < payment)
        {
            break;
        }
        previous_balance = new_balance;
    }

    printf("%d\t\t%.2f\t%.2f\t\t%.2f\t\t%.2f\n", line, previous_balance, d_interest, principal, new_balance);
    printf("-----------------------------------------------------------------------\n");
    return;
}

// void print_amort(double payment, double interest, double amount)
// {
//     double monthly_interest;
//     double new_balance, d_interest, principal;
//     double previous_balance = 0;

//     // calculations
//     monthly_interest = interest / 12;
//     previous_balance = amount;

//     printf("\n\nPayment #\tPrevious Balance\t$Interest\tPrincipal\tNew Balance\n");
//     printf("---------\t----------------\t--------\t---------\t-----------\n");

//     for (int i = 1; i <= MAX; i++)
//     {
//         d_interest = monthly_interest * previous_balance;
//         principal = payment - d_interest;
//         new_balance = previous_balance - principal;
//         printf("%d\t\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", i, previous_balance, d_interest, principal, new_balance);
//         previous_balance = new_balance;
//         if (new_balance < payment)
//         {
//             d_interest = monthly_interest * previous_balance;
//             principal = payment - d_interest;
//             new_balance = previous_balance - principal;
//             i++;
//             printf("%d\t\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", i, previous_balance, d_interest, principal, new_balance);
//             break;
//         }
//     }
//     printf("---------------------------------------------------------------\n");

//     return;
// }