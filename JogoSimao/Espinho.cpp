#include "Espinho.h"
namespace Entidades {
	namespace Obstaculos {
		Espinho::Espinho(sf::Vector2f pos, float altura)
		:Obstaculo(pos){
			id = Id::Espinho;
			this->altura = altura;
			danoso = 1;
			danoRelogio.restart();
			danoCooldown = 0.5;
			colidivel = 0;
			shape.setTexture(*pGerGraphic->getEspinho());
			shape.setTextureRect(sf::IntRect(127, 46, 100, 80));
			shape.setScale(1, 1*altura);
		}
		Espinho::Espinho()
			:Obstaculo()
		{
			this->altura = altura;
			danoso = 1;			
			danoCooldown = 0.5;
			colidivel = 0;
		}
		Espinho::~Espinho()
		{
		}

		void Espinho::setAltura(float alt)
		{
			altura = alt;
			shape.setScale(1, 1 * altura);
		}

		const float Espinho::getDanoCooldown() const
		{
			return danoCooldown;
		}
		const float Espinho::getDanoRelogio() const {
			return danoRelogio.getElapsedTime().asSeconds();
		}

		void Espinho::executar() {

		}

		std::string Espinho::salvar()
		{
			salvarEspinho();
			return buffer.str();
		}
		void Espinho::salvarEspinho()
		{
			salvarObstaculo();
			buffer << altura;
		}

		void Espinho::obstacular(Personagens::Personagem* pPersonagem) {
			
			if (pPersonagem->getTipo() == TipoPersonagem::PLAYER) {
				if (getDanoRelogio() > getDanoCooldown()) {
					danoRelogio.restart();
					pPersonagem->tiraVida(1);
				}
			}
		}
	}
}