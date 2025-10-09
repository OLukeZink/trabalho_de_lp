// Implementacoes simples para o jogo Hot-n-Cold
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <random>
#include <cmath>

inline int gerar_numero(int min, int max) {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(min, max);
	return dist(gen);
}

inline void jogar() {
	const int MIN = 1;
	const int MAX = 100;
	int alvo = gerar_numero(MIN, MAX);
	int palpite_anterior = -1;
	int tentativas = 0;

	std::cout << "\n-- Jogo Hot-n-Cold --\n";
	std::cout << "Adivinhe um numero entre " << MIN << " e " << MAX << ".\n";
	std::cout << "Digite 0 para voltar ao menu.\n";

	while (true) {
		std::cout << "Seu palpite: ";
		std::string linha;
		if (!std::getline(std::cin, linha)) {
			std::cout << "Entrada encerrada. Voltando ao menu...\n";
			return;
		}

		int palpite = -1;
		try {
			palpite = std::stoi(linha);
		} catch (...) {
			std::cout << "Entrada invalida. Digite um numero.\n";
			continue;
		}

		if (palpite == 0) {
			std::cout << "Voltando ao menu...\n";
			return;
		}

		if (palpite < MIN || palpite > MAX) {
			std::cout << "Por favor, escolha um numero entre " << MIN << " e " << MAX << ".\n";
			continue;
		}

		tentativas++;

		if (palpite == alvo) {
			std::cout << "Parabens! Voce acertou em " << tentativas << " tentativas.\n";
			std::cout << "\nPressione Enter para voltar ao menu...";
			std::getline(std::cin, linha);
			return;
		}

		if (palpite_anterior == -1) {
			int diff = std::abs(palpite - alvo);
			if (diff <= 10) std::cout << "Quente\n";
			else if (diff <= 30) std::cout << "Morno\n";
			else std::cout << "Frio\n";
		} else {
			int diff_atual = std::abs(palpite - alvo);
			int diff_anterior = std::abs(palpite_anterior - alvo);
			if (diff_atual < diff_anterior) std::cout << "Mais quente\n";
			else if (diff_atual > diff_anterior) std::cout << "Mais frio\n";
			else std::cout << "Iguais (mesma distancia)\n";
		}

		palpite_anterior = palpite;
	}
}

#endif // FUNCTIONS_H

