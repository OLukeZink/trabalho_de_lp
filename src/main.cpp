// Menu simples com 4 opcoes (inclui 'Sair')
#include <iostream>
#include <string>
// Menu simples com 4 opcoes (inclui 'Sair')
#include <iostream>
#include <string>
#include "../include/functions.h"

inline void estatisticas() {
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
				configuracoes();
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

