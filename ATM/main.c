#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Application/Application.h"
extern ST_cardData_t mydata;
extern  ST_terminalData_t terminal;

int main()
{
    app_start();

return 0;
}











/*
 getCardExpiryDate(ptr_card_data);
 getTransactionDate(ptr_term_data);
 isCardExpired(mydata,terminal);
 setMaxAmount(ptr_term_data);
   getTransactionAmount(ptr_term_data);
   printf("%d", isBelowMaxAmount(ptr_term_data));

 */



 /*
isValidAccount(ptr_card_data);
  // setMaxAmount(ptr_term_data);
    getTransactionAmount(ptr_term_data);
   // isBelowMaxAmount(ptr_term_data);

 printf("%d", isAmountAvailable(ptr_term_data));
*/



/*  ST_cardData_t cardData;
   ST_cardData_t* ptr_card_data = &cardData;
   ST_terminalData_t termData;
   ST_terminalData_t* ptr_term_data = &termData;
       ST_transaction_t trans;
  getCardPAN(ptr_card_data);

 if(isValidAccount(ptr_card_data)==0){
    setMaxAmount(ptr_term_data);
    getTransactionAmount(ptr_term_data);
    isBelowMaxAmount(ptr_term_data);
    isAmountAvailable(ptr_term_data);}
    saveTransaction(&trans);
 recieveTransactionData(&trans);
printf("return of get transaction function = %d\r\n", getTransaction(0, &trans));
printf("Trans state = %d\r\n", trans.transState);*/






























     //  app_start();
//ST_cardData_t cardData;
//ST_terminalData_t termData;
//printf("%d\n", isValidCardPAN(&termData));
//printf("%d\n", getTransactionDate(&termData));
//printf("%d\n", getCardPAN(&cardData));
//printf("%d\n", setMaxAmount(&termData));

//printf("%d\n", getTransactionAmount(&termData));
//printf("%d\n", isValidAccount(&cardData));

//printf("%d\n", isAmountAvailable(&termData));
//printf("%d\n", isCardExpired(cardData, termData));

//printf("%d\n", isBelowMaxAmount(&termData));


//EN_terminalError_t setMaxAmount(&termData);


  //
    /*
ST_cardData_t cardData;
ST_terminalData_t termData;

getCardPAN(&cardData);
getTransactionAmount(&termData);
printf("%d",isValidAccount(&cardData));
printf("%d",isAmountAvailable(&cardData));
*/

    /*
strcpy (arrayOfTransactions[0].cardHolderData.cardExpirrationDate, "12/25");
 strcpy (arrayOfTransactions[0].cardHolderData.primaryAccountNumber, "12345678912345678");
strcpy(arrayOfTransactions[0].cardHolderData.cardHolderName,"hager samir mohamedd");

     arrayOfTransactions[0].terminalData.transAmount =  500.0 ;
    arrayOfTransactions[0].terminalData.maxTransAmount =  4000.0  ;
  strcpy ( arrayOfTransactions[0].terminalData.transactionDate  ,"24/02/2022");

    arrayOfTransactions[0].transState=  APPROVED ;
    arrayOfTransactions[0].transactionSequenceNumber=  1;*/


/*
 ST_transaction_t  arrayOfTransactions [4];

strcpy (arrayOfTransactions[0].cardHolderData.cardExpirrationDate, "12/25");
 strcpy (arrayOfTransactions[0].cardHolderData.primaryAccountNumber, "12345678912345678");
strcpy(arrayOfTransactions[0].cardHolderData.cardHolderName,"hager samir mohamedd");

     arrayOfTransactions[0].terminalData.transAmount =  500.0 ;
    arrayOfTransactions[0].terminalData.maxTransAmount =  4000.0  ;
  strcpy ( arrayOfTransactions[0].terminalData.transactionDate  ,"24/02/2022");

    arrayOfTransactions[0].transState=  APPROVED ;
    arrayOfTransactions[0].transactionSequenceNumber=  1;
*/
 /*   printf("%s", arrayOfTransactions[0].cardHolderData.cardExpirrationDate);*/

  /*  arrayOfTransactions[0] =
 {    ST_cardData_t   { "hager samir mohamedd", "12345678912345678", "12/25"},// awl wahed struct of card data ele gwah 4hagat bardo (name,)
                  ST_terminalData_t   {500.0,4000.0 , "24/02/2022"} ,
                 EN_transState_t       APPROVED ,
                         uint32_t 1
};
 arrayOfTransactions[1]=
 {       { "hager samir mohamedd", "12345678912345678", "12/25"},// awl wahed struct of card data ele gwah 4hagat bardo (name,)
                     {1000.0,4000.0 , "24/06/2022"} ,
                        APPROVED ,
                          2
};
arrayOfTransactions[2]=
{       { "hager samir mohamedd", "12345678912345678", "12/25"},// awl wahed struct of card data ele gwah 4hagat bardo (name,)
                     {1500.0,4000.0 , "24/07/2022"} ,
                        DECLINED_INSUFFECIENT_FUND ,
                          3
};*/


    /*
    ST_cardData_t cardData;
ST_terminalData_t termData;
//setMaxAmount();

////setting max amount of terminal ///

//printf ("%f\n",(termData.maxTransAmount));
//printf("%d",setMaxAmount(&(termData)) );
//printf ("%d\n",setMaxAmount(&(termData.maxTransAmount)));
//printf ("%d\n",getTransactionAmount(&termData));
setMaxAmount(&termData);
printf ("%d\n",getTransactionAmount(&termData));
printf ("%d\n", isBelowMaxAmount(&(termData.transAmount)) );

//printf ("%d\n",getTransactionAmount(&termData));

       printf("%d \n",   getCardHolderName(&cardData));
      printf("%s\n",isCardExpired( cardData,  termData));

    printf("%d \n",   getCardExpiryDate(&cardData));
        printf("%d \n",   getCardPAN(&cardData));
*/
