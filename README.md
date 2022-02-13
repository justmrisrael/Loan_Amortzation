#Purpose:
The purpose of this assignment is for you to utilize the different C language
constructs along with separate compilations and Makefiles. This should also
give practice to work and refresh your knowledge of C. This is not much of a 
distributed systems assignment, but rather a practice assignment to get you
started with C and separate compilation.

#Requirements:
In this assignment you are to display a loan's amortization table.

        1) The program's user enters the following:
                a. Amount of loan
                b. Monthly Payment
                c. Annual Interest Rate (a number between 0.0 and 1.0)

        2) The program prints out a table such as the one below.  In the table,
           there is one line per month of the amortization schedule.  The table
           ends when the balance becomes zero or less.

        Enter loan amount: 128700
        Enter monthly payment: 1183.95
        Enter annual interest rate (0.0-1.0): 0.07325


	#Menu:
	  1. Print Amortization Table
	  2. Print a row in the table
	  3. Quit

        Enter your Choice: 1

        Payment #  Previous Balance  Interest   Principal  New Balance
        ---------  ----------------  ---------  ---------  ------------
        1           128700.00        785.61       398.34     128301.66
        2           128301.66        783.17       400.78     127900.88
        3           127900.88        780.73       403.23     127497.65
        4           127497.65        778.27       405.69     127091.96
                                        .

                                        .

                                        .

        177           3502.85         21.38      1162.57       2340.29
        178           2340.29         14.29      1169.66       1170.62
        179           1170.62          7.15      1176.80         -6.18

        ----------------------------------------------------------------
        Make sure that you print them in the above format.  The input figures
        shown above can be used to test your program.

	

#Here's how loans work:

You take out a loan with a certain annual interest. The monthly interest is
calculating by dividing the annual interest by 12. Each month you accumulate
an interest which is added to the amount of your loan (previous balance). The
interest is basically the monthly rate multiplied by the balance. When you
make a payment that amount is subtracted from the previous balance after
adding the monthly interest amount to it. The amount of your payment subtracted
from the previous balance is called principal, and the amount that pays for
the monthly interest is called Interest.

Implementation Details:
1. You need to have the following files:
   main.c
   Account.c
   Account.h
   AmortTable.c
   AmortTable.h
   Makefile

   The file main.c depends on Account.o, AmortTable.o, and both .h files
   The file AmortTable.o depends on Account.o

In the account, you are supoosed to have the following data structure:
   Account which contains, the amount of loan, the monthly payment,
   the interest, and an amortization table.

   The following functions are needed:
       a. read the data (a, b, and c in the example above)
       b. generate the amortization table.

In the amortization table, you are supposed to have an array of a data
strcuture to represent each table entry along with the number of table
entries.

   The following functions are needed:
       a. print the table as shown above
       b. print a specif row of the table based on a row number

Make sure you perform the proper error checking when displaying information.

Your main program is supposed to do the following using the functions
implemented above:
     1. read the data and populate the account information
     2. generate the the amortization table using the proper function
     3. Go into a loop that allows you either
     	a. print the entire table
	b. print a specific row of the table
	c. quit the program.

Your makefile should be able to compile the code using the command 'make' only.
