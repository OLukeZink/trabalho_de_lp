// Menu simples com 4 opcoes (inclui 'Sair')
#include <iostream>
#include <string>
#include <random>
#include <limits>

// Jogo Hot-n-Cold: o programa escolhe um numero entre 1 e 100.
// O usuario tenta adivinhar. O programa responde se o palpite
// esta mais quente (mais perto) ou mais frio (mais longe) em relacao
// ao palpite anterior. Digite 0 para voltar ao menu.

int gerar_numero(int min, int max) {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(min, max);
	return dist(gen);
}

void jogar() {
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
			// Primeiro palpite: apenas dizer quente/frio relativo ao meio
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

void estatisticas() {
	std::cout << "Funcao de estatisticas ainda nao implementada.\n";
}

inline void configuracoes() {
	std::cout << "Funcao de configuracoes ainda nao implementada.\n";
}

int main() {
	while (true) {
		std::cout << "========================\n";
		std::cout << "       MENU PRINCIPAL   \n";
		std::cout << "========================\n";
		std::cout << "1) Jogar\n";
		std::cout << "2) Estatisticas\n";
		std::cout << "3) Configuracoes\n";
		std::cout << "4) Sair\n";
		std::cout << "Escolha uma opcao: ";

		std::string entrada;
		if (!std::getline(std::cin, entrada)) {
			std::cout << "Entrada encerrada. Saindo...\n";
			break;
		}

		int opcao = -1;
		try {
			opcao = std::stoi(entrada);
		} catch (...) {
			opcao = -1; // entrada invalida
		}

		switch (opcao) {
			case 1:
				jogar();
				break;
			case 2:
				estatisticas();
				break;
			case 3:
				invert_case();
				break;
			case 4:
				std::cout << "Saindo...\n";
				return 0;
			default:
				std::cout << "Opcao invalida. Por favor, escolha 1-4.\n";
				break;
		}

		std::cout << "\n";
	}

	return 0;
}

