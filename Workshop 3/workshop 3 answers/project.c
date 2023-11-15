#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

typedef struct {
    char firstName[MAX_LENGTH];
    char lastName[MAX_LENGTH];
    char streetAddress[MAX_LENGTH];
    char city[MAX_LENGTH];
    char province[MAX_LENGTH];
    char postalCode[MAX_LENGTH];
} Customer;

bool isValidPostalCode(const char* postalCode) {
    // Postal code validation logic goes here
    // Implement your own validation rules based on your requirements
    // This is just a basic example
    int len = strlen(postalCode);
    if (len != 6)
        return false;

    for (int i = 0; i < len; i++) {
        if (!isalpha(postalCode[i]) && !isdigit(postalCode[i]))
            return false;
    }

    return true;
}

Customer getCustomerInformation() {
    Customer customer;

    printf("Enter customer information:\n");

    while (true) {
        printf("First Name: ");
        fgets(customer.firstName, sizeof(customer.firstName), stdin);
        if (strcmp(customer.firstName, "\n") != 0)
            break;
        printf("First Name cannot be blank. Please try again.\n");
    }

    while (true) {
        printf("Last Name: ");
        fgets(customer.lastName, sizeof(customer.lastName), stdin);
        if (strcmp(customer.lastName, "\n") != 0)
            break;
        printf("Last Name cannot be blank. Please try again.\n");
    }

    while (true) {
        printf("Street Address: ");
        fgets(customer.streetAddress, sizeof(customer.streetAddress), stdin);
        if (strcmp(customer.streetAddress, "\n") != 0)
            break;
        printf("Street Address cannot be blank. Please try again.\n");
    }

    while (true) {
        printf("City: ");
        fgets(customer.city, sizeof(customer.city), stdin);
        if (strcmp(customer.city, "\n") != 0)
            break;
        printf("City cannot be blank. Please try again.\n");
    }

    while (true) {
        printf("Province: ");
        fgets(customer.province, sizeof(customer.province), stdin);
        if (strcmp(customer.province, "\n") != 0)
            break;
        printf("Province cannot be blank. Please try again.\n");
    }

    while (true) {
        printf("Postal Code: ");
        fgets(customer.postalCode, sizeof(customer.postalCode), stdin);
        if (strcmp(customer.postalCode, "\n") != 0 && isValidPostalCode(customer.postalCode))
            break;
        printf("Postal Code is invalid. Please try again.\n");
    }

    return customer;
}

int main() {
    Customer customer = getCustomerInformation();

    printf("\nCustomer Information:\n");
    printf("First Name: %s", customer.firstName);
    printf("Last Name: %s", customer.lastName);
    printf("Street Address: %s", customer.streetAddress);
    printf("City: %s", customer.city);
    printf("Province: %s", customer.province);
    printf("Postal Code: %s", customer.postalCode);

    return 0;
}
