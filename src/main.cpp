// Menu simples com 4 opções (inclui 'Sair')
#include <iostream>
#include <string>

void jogar() {
	std::cout << "Você escolheu: Jogar (placeholder)\n";
	// Aqui você pode chamar a função que inicia o jogo
}

void estatisticas() {
	std::cout << "Você escolheu: Estatísticas (placeholder)\n";
	// Exibir estatísticas ou resultados
}

void configuracoes() {
	std::cout << "Você escolheu: Configurações (placeholder)\n";
	// Ajustar configurações do programa
}

int main() {
	while (true) {
		std::cout << "========================\n";
		std::cout << "       MENU PRINCIPAL   \n";
		std::cout << "========================\n";
		std::cout << "1) Jogar\n";
		std::cout << "2) Estatísticas\n";
		std::cout << "3) Configurações\n";
		std::cout << "4) Sair\n";
		std::cout << "Escolha uma opção: ";

		std::string entrada;
		if (!std::getline(std::cin, entrada)) {
			// EOF ou erro de leitura -> sair
			std::cout << "Entrada encerrada. Saindo...\n";
			break;
		}

		int opcao = -1;
		try {
			opcao = std::stoi(entrada);
		} catch (...) {
			opcao = -1; // entrada inválida
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
				std::cout << "Opção inválida. Por favor, escolha 1-4.\n";
				break;
		}

		std::cout << "\nPressione Enter para voltar ao menu...";
		std::getline(std::cin, entrada);
		std::cout << "\n";
	}

	return 0;
}
