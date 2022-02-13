#define MAX 200
// data structure of account
struct accounts
{
    double amount;
    double monthly;
    double annual;
} account;

struct tables
{
    int payment[MAX];
    double previous_balance[MAX];
    double interest[MAX];
    double principal[MAX];
    double new_balance[MAX];
} table;

void gen_amort(double payment, double interest, double amount);