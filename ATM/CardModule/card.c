#include "card.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
ST_cardData_t mydata;
/*
This function will ask for the cardholder's name and store it into card data.
Card holder name is 24 characters string max and 20 min.
If the cardholder name is NULL, less than 20 characters or more than 24 will return WRONG_NAME error, else return OK
*/
EN_cardError_t getCardHolderName(ST_cardData_t *cardData){
cardData = &mydata;
uint8_t name[25];
int i;
while ( i<20 || i>24 || name == NULL   )
{
       i=0;                                                                    // return WRONG_NAME ;// means return 1
       printf ("follow the instructions, please \n" );
       printf ("please, Enter your name (from 20 to 24 letter only ):\n" );
          gets(name);
        while(name[i]!='\0')
                        i++;
        printf("Length of [ %s ] is [ %d ]\n", name, i);
}
strcpy( cardData->cardHolderName , name);
   return OK;// means return 0
}
/*This function will ask for the card expiry date and store it in card data.
Card expiry date is 5 characters string in the format "MM/YY", e.g "05/25".
If the card expiry date is NULL, less or more than 5 characters, or has the wrong format will return WRONG_EXP_DATE error, else return OK.*/
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData){
cardData = &mydata;
uint8_t date[6];
int i;
while ( i<5 || i>5 || date == NULL   )
{   i=0;
   printf ("follow the instructions, please \n" );
   printf ("please, Enter the card expiry date in the format 'MM/YY' :\n" );
          gets(date);
                 while (date[i]!='\0')
                     i++;
            printf("Length of [ %s ] is [ %d ]\n", date, i);
}
strcpy( cardData->cardExpirrationDate , date);
   return OK;// means return 0
}
/*
This function will ask for the card's Primary Account Number and store it in card data.
PAN is 20 characters alphanumeric only string 19 character max, and 16 character min.
If the PAN is NULL, less than 16 or more than 19 characters, will return WRONG_PAN error, else return OK.
*/
EN_cardError_t getCardPAN(ST_cardData_t *cardData){
cardData = &mydata;
uint8_t PAN[20];
int i;
while ( i<16 || i>19 || PAN == NULL   )
{
   i=0;
   printf ("follow the instructions, please \n" );
   printf ("please, Enter the card PAN NO. (from 16 to 19 alphanumeric ) :\n" );
    gets(PAN);
    while(PAN[i]!='\0')
             i++;
   printf("Length of [ %s ] is [ %d ]\n", PAN, i);
}
strcpy( cardData->primaryAccountNumber , PAN);
   return OK;// means return 0
}



