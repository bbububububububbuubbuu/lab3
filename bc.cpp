#include "bc.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void generateSecret(char secret[5]) {
	bool used[10] = {false};
	int i = 0;
	while (i < 4) {
		int d = std::rand() % 10;
		if (i == 0 && d == 0) continue;
		if (used[d]) continue;
		used[d] = true;
		secret[i] = '0' + d;
		++i; }
	secret[4] = '\0'; }

int countBulls(const char secret[5], const char guess[5]) {
	int bulls = 0;
	for (int i = 0; i < 4; ++i) {
		if (secret[i] == guess[i]) ++bulls; }
	return bulls; }

int countCows(const char secret[5], const char guess[5]) {
	int cows = 0;
	for (int i = 0; i < 4; ++i) {
		if (secret[i] == guess[i]) continue;
		for (int j = 0; j < 4; ++j) {
			if (guess[i] == secret[j]) {
				++cows;
				break; } } }
	return cows; }

void playGame() {
	char secret[5];
	generateSecret(secret);	
	std::cout << "game Cows and bulls\n";
	std::cout << "PC has chosen a number with four different letters\n\n";
	int attempts = 0;
	char guess[5];
	while (true) {
		std::cout << "your guess: ";
		std::cin >> guess;
		++attempts;
		int bulls = countBulls(secret, guess);
		int cows = countCows(secret, guess);
		std::cout << bulls << " bull(s), " << cows << " cow(s)\n";
		if (bulls == 4) {
			std::cout << "YES! you have guessed correctly using " << attempts << " attempts\n";
			break; } } }
