#include "MenuRanking.h"

MenuRanking::MenuRanking()
:menuState()
{
	carregarBotoes();
	textoRanking.setPosition(300, 300);
	textoRanking.setFont(*(pGerGraphic->getFont()));
	textoRanking.setString("O RANKING SERÁ EXIBIDO AQUI");
	setFigura(&textoRanking);
	carregarRanking();
}

MenuRanking::~MenuRanking()
{
	
}

void MenuRanking::carregarBotoes()
{
	buttonVector.push_back(new Entidades::Button(sf::Vector2f(50.f, 100.f), "Voltar", Actions::VOLTAR_1_MENU));
}
void MenuRanking::executar() {
	/**
	*@brief executa o menuState
	*@details Atualiza a posicao do mouse, limpa a janela e le e executa os botoes
	*@return void
	*/
	pGerGraphic->clear();
	pGerGraphic->updateMousePosition();
	handleEvent();
	readButtons();
	execButtons();
	desenhar();
}

void MenuRanking::carregarRanking()
{
	std::string linha;
	std::ifstream arquivo("ranking.txt");
	std::map<int, std::string> mapLeitura;
	if (arquivo.is_open()) {
		std::string nome;
		int pontos;
		while (std::getline(arquivo, linha)) {
			std::istringstream arquivoOutput(linha);
			arquivoOutput >> nome >> pontos;
			mapLeitura[pontos] = nome;
		}
		arquivo.close();
	}


	std::vector<int> todosValores;
	for (const auto& par : mapLeitura) {
		todosValores.push_back(par.first);
	}
	std::sort(todosValores.begin(), todosValores.end());

	std::stringstream texto("");

	int count = 0;
	for (auto it_vec = todosValores.rbegin(); it_vec != todosValores.rend() && count < 5; ++it_vec) {
		int pontuacaoAtual = *it_vec;
		auto it_map = mapLeitura.find(pontuacaoAtual);
		if (it_map != mapLeitura.end()) {
			texto << "Pontos: " << it_map->first << " Nome: " << it_map->second << "\n";
		}
		count++;
	}

	textoRanking.setString(texto.str());

}
