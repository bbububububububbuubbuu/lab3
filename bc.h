#ifndef BULLS_COWS_H
#define BULLS_COWS_H

void generateSecret(char secret[5]);
int countBulls(const char secret[5], const char guess[5]);
int countCows(const char secret[5], const char guess[5]);
void playGame();

#endif