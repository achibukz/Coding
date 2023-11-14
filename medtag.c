#include <stdio.h>

// Function to extract priority and insurance status from a two-digit patient code
void extractPatientInfo(int code, int *priority, int *insurance) {
    *priority = code / 10;
    *insurance = code % 10;
}

// Function to compare two patient codes for sorting
int comparePatients(const void *a, const void *b) {
    int priorityA, insuranceA, priorityB, insuranceB;
    extractPatientInfo(*(int *)a, &priorityA, &insuranceA);
    extractPatientInfo(*(int *)b, &priorityB, &insuranceB);

    if (priorityA > priorityB) return -1;
    else if (priorityA < priorityB) return 1;
    else {
        // If priorities are the same, prioritize the one with insurance
        if (insuranceA > insuranceB) return -1;
        else if (insuranceA < insuranceB) return 1;
        else return 0;  // No need to sort if priorities and insurance are the same
    }
}

int main() {
    int roomCode;
    int patientCodes[6];
    int numPatients = 0;

    while (1) {
        printf("Enter room code (-999 to exit): ");
        scanf("%d", &roomCode);

        // Check for sentinel value
        if (roomCode == -999) {
            break;
        }

        // Validate input
        if (roomCode < 100000 || roomCode > 999999) {
            printf("Invalid input! Room code must be a six-digit number.\n");
            while (getchar() != '\n');  // Clear input buffer
            continue;
        }

        // Extract patient codes from room code
        for (int i = 0; i < 6; ++i) {
            patientCodes[i] = roomCode % 100;
            roomCode /= 100;
        }

        // Sort patient codes
        qsort(patientCodes, 6, sizeof(int), comparePatients);

        // Print sorted patient codes
        printf("Sorted room code: ");
        for (int i = 0; i < 6; ++i) {
            printf("%d", patientCodes[i]);
            if (i < 5) {
                printf("-");
            }
        }
        printf("\n");

        // Count and print the number of patients
        numPatients = 0;
        for (int i = 0; i < 6; ++i) {
            if (patientCodes[i] != 0) {
                numPatients++;
            }
        }
        printf("Number of patients: %d\n\n", numPatients);
    }

    printf("Program terminated.\n");

    return 0;
}
