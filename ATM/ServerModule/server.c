#include "server.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
extern ST_cardData_t mydata;
extern  ST_terminalData_t terminal;
int account_number;
static ST_transaction_t  arrayOfTransactions [255];
int current_seq_num = 0;
  int transSize =0;
  EN_serverError_t isValidAccount_return = ok;
    EN_serverError_t isAmountAvailable_return = ok;
    ST_transaction_t  trans;


   static ST_accountsDB_t accs[3] = {
                                        {70000,"12345678911234566"},
                                        {1500,"hager123456789666"},
                                        {500000,"12345678911234555"}
                                    };
/*
1- Create a global array of ST_accountsDB_t for the valid accounts database
2- Fill in the array initially with any valid data
3- This array has a maximum of 255 element/account data
You should deliver a screenshot of your accounts database array
*/
void AccountsData_balances_and_PANs(void)
{
    #if 0
ST_accountsDB_t acc1=    ;
ST_accountsDB_t acc2=    ;
ST_accountsDB_t acc3=    ;
 accs[0]=acc1;
 accs[1]=acc2;
 accs[2]=acc3;
 #endif // 0
}

/*
---This function will take all transaction data and validate its data.
->It checks the account details and amount availability.
1) If the account does not exist return DECLINED_STOLEN_CARD,
2) if the amount is not available will return DECLINED_INSUFFECIENT_FUND,
3) if a transaction can't be saved will return INTERNAL_SERVER_ERROR and will not save the transaction,
4) else returns APPROVED.
            It will update the database with the new balance.
*/
EN_transState_t recieveTransactionData(ST_transaction_t *transData){
	if (isValidAccount_return==ACCOUNT_NOT_FOUND)
    {
		transData->transState = DECLINED_STOLEN_CARD;
		printf("Declined stolen card\n");
		return DECLINED_STOLEN_CARD;
	}
	if (isAmountAvailable_return==LOW_BALANCE)
	{
		transData->transState = DECLINED_INSUFFECIENT_FUND;
				printf("DECLINED_INSUFFECIENT_FUND\n");
		return DECLINED_INSUFFECIENT_FUND;
	}

	if (saveTransaction(transData) == SAVING_FAILED)
	{
	    				printf("INTERNAL_SERVER_ERROR\n");
		return INTERNAL_SERVER_ERROR;
	}
	else
	{
	    (accs[account_number]).balance =   ( accs[account_number] ).balance - terminal.transAmount;
	    printf("Transaction Approved\n The balance after transaction approval %f \r\n", accs[account_number].balance);
        return APPROVED;
	}
}


/*
If the PAN doesn't exist will return DECLINED_STOLEN_CARD, else will return OK
*/
EN_serverError_t isValidAccount(ST_cardData_t *cardData){
AccountsData_balances_and_PANs();
cardData = &(mydata);
int flag=0;
for(int i=0; i<3;  i++)
{
   if(strcmp((cardData->primaryAccountNumber),(accs[i].primaryAccountNumber))==0)
                 {
                    flag=1;
                    printf(" This account is in our database , done\n");
                    account_number=i;
                    return ok;
                 }
             else
                  {
                    flag=0;
                   }
    if(i==2 && flag==0)
        {
        printf(" Account not found \n ");
        isValidAccount_return = ACCOUNT_NOT_FOUND;
        return ACCOUNT_NOT_FOUND;
        }
}
}


/*This function will take terminal data and validate these data.
It checks if the transaction's amount is available or not.
If the transaction amount is greater than the balance in the database will return LOW_BALANCE, else will return OK
You should deliver a maximum 2min video to discuss your implementation and run different test cases on this function*/
EN_serverError_t isAmountAvailable(ST_terminalData_t *termData){
AccountsData_balances_and_PANs();
termData = &terminal;
//printf("account_number \n %d\n",account_number );
      if (termData->transAmount > accs[account_number].balance )
      {
          printf(" Low balance!\n");
          isAmountAvailable_return =LOW_BALANCE;
          return LOW_BALANCE;
     }
     else
     {
       printf("Amount available now you can take your money \n");
       return ok;
     }

}



/*
---This function will take all transaction data into the transactions database.
It gives a sequence number to a transaction, this number is incremented once a transaction is processed into the server.
If saves any type of transaction, APPROVED or DECLINED, with the specific reason for declining/transaction state.
If transaction can't be saved will return SAVING_FAILED, else will return OK
*/
EN_serverError_t saveTransaction(ST_transaction_t *transData){

    EN_serverError_t retval = ok;

    int is_neeed_to_save = 0;

    if((isValidAccount_return==ok) && (isAmountAvailable_return==ok) )
    {
            if(transSize<255)
            {
                is_neeed_to_save = 1;
                transData->transState = APPROVED;
                                // printf("trans state is APPROVED(0)\n");
                retval =  ok;
            }
            else
            {
                 printf("Saving FAILED\n");
                retval = SAVING_FAILED;
            }

    }
    else if ((isValidAccount_return==ok )&& (isAmountAvailable_return==LOW_BALANCE) )
    {
        if(transSize<255)
        {
                is_neeed_to_save = 1;
                transData->transState = DECLINED_INSUFFECIENT_FUND;
                 printf("trans state is DECLINED_INSUFFECIENT_FUND(1)\n");
                retval =  ok;

        }
        else
        {
            printf("Saving FAILED\n");
            retval =  SAVING_FAILED;
        }
    }
    else
    {
        printf("Saving FAILED\n");
        retval =  SAVING_FAILED;
    }

    if(is_neeed_to_save == 1)
    {
            transData->transactionSequenceNumber = current_seq_num;

            strcpy((transData->cardHolderData.cardHolderName),(mydata.cardHolderName));
            strcpy((transData->cardHolderData.primaryAccountNumber),(mydata.primaryAccountNumber));
            strcpy((transData->cardHolderData.cardExpirrationDate),(mydata.cardExpirrationDate));
            strcpy((transData->terminalData.transactionDate),(terminal.transactionDate));
            transData->terminalData.transAmount=terminal.transAmount;
            transData->terminalData.maxTransAmount= terminal.maxTransAmount;

          //  printf("BEFOREEEEEEEEEEEEEEE 0 = %d\r\n", transData->transactionSequenceNumber);
            memcpy( &(arrayOfTransactions[transData->transactionSequenceNumber].cardHolderData), &(transData->cardHolderData), sizeof(transData->cardHolderData));
          //  printf("BEFOREEEEEEEEEEEEEEE 1\r\n");
            memcpy( &(arrayOfTransactions[transData->transactionSequenceNumber].terminalData), &(transData->terminalData), sizeof(transData->terminalData));

            arrayOfTransactions[transData->transactionSequenceNumber].transState = transData->transState;
            current_seq_num++;
            transSize++;
    }

    return retval;

}

/*
In server implement getTransaction function:

This function will take a transaction sequence number and search for this transaction in the database.
If the transaction can't be found will return TRANSACTION_NOT_FOUND, else will return OK and store the transaction in a structure
*/
EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t *transData)
{
    if(transData != NULL)
    {
        if(arrayOfTransactions[transactionSequenceNumber].transactionSequenceNumber != transactionSequenceNumber)
        {
            return TRANSACTION_NOT_FOUND;
        }
        else
        {
            memcpy(transData, &(arrayOfTransactions[transactionSequenceNumber]), sizeof(ST_transaction_t));
              printf("PAN: %s\n",(transData->cardHolderData.primaryAccountNumber));
    printf("saving done\n");
            return ok;
        }


    }
}















