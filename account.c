// In the account, you are supoosed to have the following data structure:
//    Account which contains, the amount of loan, the monthly payment,
//    the interest, and an amortization table.

//    The following functions are needed:
//        a. read the data (a, b, and c in the example above)
//        b. generate the amortization table.

#include <stdio.h>
#include "account.h"


void gen_amort(double payment, double interest, double amount)
{
    double monthly_interest;
    double new_balance, d_interest, principal;
    double previous_balance = 0;

    // calculations
    monthly_interest = interest / 12;
    previous_balance = amount;

    // printf("\n\nPayment #\tPrevious Balance\t$Interest\tPrincipal\tNew Balance\n");
    // printf("---------\t----------------\t--------\t---------\t-----------\n");

    for (int i = 1; i <= MAX; i++)
    {
        d_interest = monthly_interest * previous_balance;
        principal = payment - d_interest;
        new_balance = previous_balance - principal;
        table.payment[i] = i;
        table.previous_balance[i] = previous_balance;
        table.interest[i] = d_interest;
        table.principal[i] = principal;
        table.new_balance[i] = new_balance;

        // printf("%d\t\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", i, previous_balance, d_interest, principal, new_balance);
        previous_balance = new_balance;
        if (new_balance < payment)
        {
            d_interest = monthly_interest * previous_balance;
            principal = payment - d_interest;
            new_balance = previous_balance - principal;
            i++;
            table.payment[i] = i;
            table.previous_balance[i] = previous_balance;
            table.interest[i] = d_interest;
            table.principal[i] = principal;
            table.new_balance[i] = new_balance;
            // printf("%d\t\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", i, previous_balance, d_interest, principal, new_balance);
            break;
        }
    }
    // printf("---------------------------------------------------------------\n");

    printf("Amoritization Table Generated Successfully!\n");

    return;
}