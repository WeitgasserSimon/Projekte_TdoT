#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KUNDEN 100

typedef struct konto {
    int number;
    float balance;
} konto_t;

typedef struct kunde {
    char name[50];
    struct konto konto;
} kunde_t;

konto_t createKonto(int number, float balance); // um ein Konto zu erstellen braucht man eine Kontonummer und einen Kontostand
kunde_t createKunde(char name[], konto_t konto); // um einen Kunden zu erstellen braucht man den namen und sein konto
void addMoney(kunde_t *kunde); // um Geld hinzuzufügen braucht man den Kunden um auf sein Konto zuzugreifen
void removeMoney(kunde_t *kunde);   // um Geld abzuheben braucht 
void printKonto(konto_t konto);
void printBank(kunde_t bank[], int numKunden);

int main() {

    kunde_t bank[MAX_KUNDEN];
    int numKunden = 0;

    // Kunden hinzufügen
    bank[numKunden++] = createKunde("Jä", createKonto(12345, 1000.0));
    bank[numKunden++] = createKunde("Sipi", createKonto(67890, 1500.0));

    // Geldbewegungen durchführen
    addMoney(&bank[0]); // Geld hinzufügen
    printKonto(bank[0].konto);
    removeMoney(&bank[1]); // Geld abheben
    printKonto(bank[1].konto);

    // Bank ausgeben
    printBank(bank, numKunden);

    return 0;
}

konto_t createKonto(int number, float balance) {
    konto_t konto;
    konto.number = number;
    konto.balance = balance;
    return konto;
}

kunde_t createKunde(char name[], konto_t konto) {
    kunde_t kunde;
    strcpy(kunde.name, name);
    kunde.konto = konto;
    return kunde;
}

void addMoney(kunde_t *kunde) {
    float tmp;
    printf("Geben Sie den Betrag an, den Sie einzahlen möchten: ");
    scanf("%f", &tmp);
    kunde->konto.balance += tmp;
}

void removeMoney(kunde_t *kunde) {
    float tmp;
    printf("Geben Sie den Betrag an, den Sie abheben möchten: ");
    scanf("%f", &tmp);
    kunde->konto.balance -= tmp;
}

void printKonto(konto_t konto) {
    printf("Kontonummer: %d\n", konto.number);
    printf("Kontostand: %.2f\n", konto.balance);
}

void printBank(kunde_t bank[], int numKunden) {
    printf("Bankübersicht:\n");
    for (int i = 0; i < numKunden; i++) {
        printf("Kunde: %s\n", bank[i].name);
        printKonto(bank[i].konto);
        printf("\n");
    }
}
