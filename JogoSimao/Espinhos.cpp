#include "Espinhos.h"
namespace Entidades {
	namespace Obstaculos {
		Espinhos::Espinhos(sf::Vector2f size, sf::Vector2f pos)
		:Obstaculo(size, pos){
			danoso = 1;
			danoRelogio.restart();
			danoCooldown = 0.5;
			colidivel = 0;
		}
		Espinhos::Espinhos()
			:Obstaculo()
		{
		}
		Espinhos::~Espinhos()
		{
		}

		const float Espinhos::getDanoCooldown() const
		{
			return danoCooldown;
		}
		const float Espinhos::getDanoRelogio() const {
			return danoRelogio.getElapsedTime().asSeconds();
		}

		void Espinhos::executar() {

		}

		void Espinhos::obstacular(Personagens::Character* pPersonagem) {
			if(getDanoRelogio() > getDanoCooldown()) {
				danoRelogio.restart();
				pPersonagem->tiraVida(1);
			}
		}
	}
}