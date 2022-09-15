#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "terminal.h"
ST_terminalData_t terminal;
/*
This function compares the card expiry date with the transaction date.
If the card expiration date is before the transaction date will return EXPIRED_CARD, else return OK.
*/
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData){
    int cardMonth = (cardData.cardExpirrationDate[0]) * 10 + cardData.cardExpirrationDate[1];
	int cardYear = (cardData.cardExpirrationDate[3] ) * 10 + cardData.cardExpirrationDate[4] ;
	int transMonth = (termData.transactionDate[3] ) * 10 + termData.transactionDate[4] ;
	int transYear = (termData.transactionDate[8]) * 10+ +termData.transactionDate[9];
	if (transYear > cardYear)
    {
            printf("Expired card \n");
		    return EXPIRED_CARD;
	}
	if (transYear == cardYear && transMonth > cardMonth)
    {
	    printf("Expired card \n");
		return EXPIRED_CARD;
	}
	else
	{
	    printf("done, your card is not expired yet \n ");
	    return oK;
	}
}
/*1--
This function will ask for the transaction data and store it in terminal data.
Transaction date is 10 characters string in the format DD/MM/YYYY, e.g 25/06/2022.
If the transaction date is NULL, less than 10 characters or wrong format will return WRONG_DATE error, else return OK.
*/
EN_terminalError_t getTransactionDate(ST_terminalData_t *termData){
termData = &terminal;
uint8_t TransDate[11];
int i=0;
while ( i<10 || TransDate ==NULL )
{
    printf ("follow the instructions, please \n" );
    printf ("please, Enter the transaction date in the format 'DD/MM/YYYY' :\n" );
     gets(TransDate);
    while(TransDate[i]!='\0')
             i++;
    printf("Length of [ %s ] is [ %d ]\n", TransDate, i);
}
strcpy( termData->transactionDate , TransDate);
   return OK;// means return 0
}
/*
This function asks for the transaction amount and saves it into terminal data.
If the transaction amount is less than or equal to 0 will return INVALID_AMOUNT, else return OK.
You should deliver a maximum 2min video to discuss your implementation and run different test cases on this function
*/
EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData){
    termData =&terminal;
       printf ("please, Enter the Transaction amount :\n" );
       scanf("%f", &(termData->transAmount));
       printf(" you entered: %f \n",termData->transAmount );
    if ((termData->transAmount)<=0)
           {
               printf("error invalid amount \n");
               return INVALID_AMOUNT;
           }
             else {
                    return oK;
                   }
}
/*
This function sets the maximum allowed amount into terminal data.
Transaction max amount is a float number.
If transaction max amount less than or equal to 0 will return INVALID_MAX_AMOUNT error, else return OK.
*/
EN_terminalError_t setMaxAmount(ST_terminalData_t *termData){
 termData =&terminal;
 termData->maxTransAmount =4000.00;
    if((termData->maxTransAmount) <=0)
    {
        printf("the max amount should equal value\n");
        return INVALID_MAX_AMOUNT;
    }
    else {
           printf(" The maximum allowed amount = 4000 LE\n");
            return oK;
        }
}
/*
This function compares the transaction amount with the terminal max amount.
If the transaction amount is larger than the terminal max amount will return EXCEED_MAX_AMOUNT, else return OK.
*/
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData){
termData =&terminal;
  if ( (termData->transAmount) > (termData->maxTransAmount))
    {
      printf(" Transaction declined \n Your amount exceeded the max amount!\n");
      return EXCEED_MAX_AMOUNT;
    }
  else
    {
      printf(" ok the amount is below the maximum amount \n");
      return oK;
    }
}


//EN_terminalError_t isValidCardPAN(ST_cardData_t *cardData){}
