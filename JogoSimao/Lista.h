#pragma once
/*template <class TL>
class Lista
{
private:
	Elemento<TL>* pPrimeiro;
	Elemento<TL>* pUltimo;
public:
	Lista(){}
	~Lista(){}
	const Elemento<TL>* getPrimeiro() {
		return pPrimeiro;
	}
	const Elemento<TL>* getUltimo() {
		return pUltimo;
	}
	void inlcuir(TL* p) {
		Elemento<TL>* novo = new Elemento<TL>(p);
	}
	void limpar(){}

	template <class TE>
	class Elemento {
	private:
		Elemento<TE>* pProx;
		TE pinfo;
	public:
		Elemento(TE* info) {
			pProx = NULL;
			pinfo = info;
		}
		~Elemento(){}
		void incluir(TE* p);
		void setProx(Elemento<TE>* pPE){pProx = pPE}
		void incluir(TE* p){pinfo = *p}
		const Elemento<TE>* getProximo() { return pProx; }

	};

};

*/