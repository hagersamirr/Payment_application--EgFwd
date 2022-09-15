#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED
typedef unsigned char uint8_t;
typedef enum EN_cardError_t
{
OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN // initializations: OK =0 , WRONG_NAME=1 , WRONG_EXP_DATE=2 , WRONG_PAN=3
}EN_cardError_t;
typedef struct ST_cardData_t
{
uint8_t cardHolderName[25];
uint8_t primaryAccountNumber[20];
uint8_t cardExpirrationDate[6];
}ST_cardData_t;
EN_cardError_t getCardHolderName(ST_cardData_t *cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData);
EN_cardError_t getCardPAN(ST_cardData_t *cardData);
#endif // CARD_H_INCLUDED
