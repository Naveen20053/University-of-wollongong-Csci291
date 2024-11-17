#define MAX 7

int main() {
    int i_balance = 1000; // Initial balance
    int transactions[MAX] = {200, -150, -500, -400, -50, -200, 300}; // Example transactions

    // Process each transaction
    for (int i = 0; i < MAX; i++) {
        int transaction = transactions[i];

        // Check if the transaction is a withdrawal and if it exceeds the current balance
        if (transaction < 0) {
            printf("Transaction of %d skipped.\n", transaction);
            continue;
        }

        // Update balance for valid transactions
        i_balance += transaction;
        printf("Transaction of %d processed. New balance is %d.\n", transaction, i_balance);
    }

    // Final balance
    printf("\nFinal balance: %d\n", i_balance);

    return 0;
}
