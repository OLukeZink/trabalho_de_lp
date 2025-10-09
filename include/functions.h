// Implementacoes inline para o jogo Hot-n-Cold e utilidades
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <random>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>

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

inline void invert_case() {
	std::cout << "\n-- Inverter maiusculas/minusculas --\n";
	std::cout << "Digite uma linha para inverter o case (ou deixe vazia e pressione Enter para voltar):\n";

	std::string linha;
	if (!std::getline(std::cin, linha)) {
		std::cout << "Entrada encerrada. Voltando ao menu...\n";
		return;
	}

	if (linha.empty()) {
		std::cout << "Voltando ao menu...\n";
		return;
	}

	std::string out;
	out.reserve(linha.size());
	for (unsigned char ch : linha) {
		if (std::islower(ch)) out.push_back(std::toupper(ch));
		else if (std::isupper(ch)) out.push_back(std::tolower(ch));
		else out.push_back(ch);
	}

	std::cout << "Resultado: " << out << "\n";
	std::cout << "\nPressione Enter para voltar ao menu...";
	std::getline(std::cin, linha);
}

// Jogo: Inverter Letras - mostra palavra invertida e o jogador tenta adivinhar
inline void jogar_inverter_letras() {
	std::cout << "\n-- Inverter Letras (modo: você fornece a palavra) --\n";
	std::cout << "Digite uma palavra para inverter (ou 0 para voltar ao menu):\n";

	std::string linha;
	while (true) {
		std::cout << "Palavra: ";
		if (!std::getline(std::cin, linha)) {
			std::cout << "Entrada encerrada. Voltando ao menu...\n";
			return;
		}

		// trim
		size_t s = 0; while (s < linha.size() && std::isspace((unsigned char)linha[s])) ++s;
		size_t e = linha.size(); while (e > s && std::isspace((unsigned char)linha[e-1])) --e;
		std::string palavra = linha.substr(s, e - s);

		if (palavra.empty()) {
			std::cout << "Entrada vazia. Digite 0 para voltar ou uma palavra para inverter.\n";
			continue;
		}

		if (palavra == "0") {
			std::cout << "Voltando ao menu...\n";
			return;
		}

		std::string invertida = palavra;
		std::reverse(invertida.begin(), invertida.end());

		std::cout << "Invertida: " << invertida << "\n";
		std::cout << "\nPressione Enter para voltar ao menu...";
		std::getline(std::cin, linha);
		return;
	}
}

#endif // FUNCTIONS_H
