# Payment Application
Implemented the SALE transaction only by simulating the card, terminal(ATM), and the server.  

Payment systems are now available everywhere and everyone interacts with these systems every day.  
There are different types of transactions you can make, SALE, REFUND, Pre-Authorization, and VOID.

* SALE: means to buy something and its price will be deducted from your bank account.
* REFUND: this means that you will return something and wants your money back to your bank account.
* Pre-Authorization: means holding an amount of money from your account, e.g Hotel reservation.
* VOID: this means canceling the transaction, e.g if the seller entered the wrong amount.  

## The project can be distributed over 6 main tasks:

<img src="https://github.com/HosamAyoub/Photos/blob/main/Payment-Application/payment-flowchart.jpeg?raw=true" title = "System flow chart"> 

### Development environment preparation
1. Create modules folders.
2. Create .c and .h file for each module.
3. Add header file guard.
4. Create the main.c file.

### Card module
1. In card.h file contains functions' prototypes and typedefs.
2. Implement getCardHolderName function.
3. Implement getCardExpiryDate function.
4. Implement getCardPAN function.

### Terminal module
1. In terminal.h file contains functions' prototypes and typedefs.
2. Implement getTransactionDate function.
3. Implement isCardExpried function.
4. Implement gatTransactionAmount function.
5. Implement isBelowMaxAmount function.
6. Implement setMaxAmount function.
7. Implement isValidCard function.

### Server module
1. In server.h file contains functions' prototypes and typedefs.
2. Implement server-side accounts' database.
3. Implement server-side transactions' database.
4. Implement recieveTransactionData function.
5. Implement isValidAccount function.
6. Implement isAmountAvailable function.
7. Implement saveTransaction function.
8. Implement getTransaction function.

### Application
1. In application.h file contains functions' prototypes.
2. Implement appStart function.

### Testing
#### 1. Transaction approved user story.
As a bank customer have an account and has a valid and not expired card, I want to withdraw an amount of money less than the maximum allowed and less than or equal to the amount in my balance, so that I am expecting that the transaction is approved and my account balance is reduced by the withdrawn amount.

#### 2. Exceed the maximum amount user story:
As a bank customer have an account, that has a valid and not expired card, I want to withdraw an amount of money that exceeds the maximum allowed amount so that I am expecting that the transaction declined.

#### 3. Insufficient fund user story:
As a bank customer have an account and has a valid and not expired card, I want to withdraw an amount of money less than the maximum allowed and larger than the amount in my balance so that I am expecting that the transaction declined.

#### 4. Expired card user story:
As a bank customer have an account, have a valid but expired card, I want to withdraw an amount of money so that I expect that the transaction declined.

#### 5. Invalid card user story:
As a bank customer have an account and has a valid and not expired stolen card, I want to block anyone from using my card so that I am expecting that any transaction made by this card is declined.

#### 6. Fraud card user story:
As a bank administrator, I want to issue my own cards, so that I am expecting that any transaction made by any fraud card (failed in Luhun check) is declined.
