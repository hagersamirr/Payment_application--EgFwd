#include "../ServerModule/server.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Application.h"

extern ST_cardData_t mydata;
extern  ST_terminalData_t terminal;
void app_start(void){
       ST_cardData_t cardData;
       ST_terminalData_t termData;
    ST_terminalData_t* ptr_term_data = &termData;
    ST_cardData_t* ptr_card_data = &cardData;
    ST_transaction_t trans;
    getCardHolderName(ptr_card_data);
        getCardExpiryDate(ptr_card_data);
    getCardPAN(ptr_card_data);

    getTransactionDate(ptr_term_data);
  if (isCardExpired(mydata,terminal)!=2){

    setMaxAmount(ptr_term_data);
    getTransactionAmount(ptr_term_data);
   if(isBelowMaxAmount(ptr_term_data)==0){
    isValidAccount(ptr_card_data);
    isAmountAvailable(ptr_term_data);}
    saveTransaction(&trans);
    recieveTransactionData(&trans);
}

}
