# Custom C++ 2D Game Engine & Simulation

> **Status:** Concluído (Versão 1.0)

Este projeto consiste no desenvolvimento de uma **Engine de Jogos 2D** construída do zero utilizando **C++ moderno**. O objetivo principal não foi apenas criar um jogo, mas sim estudar e implementar os fundamentos da arquitetura de software, gerenciamento de memória manual e física vetorial sem depender de engines de alto nível (como Unity ou Godot).

---

## 📐 Arquitetura e Engenharia

A arquitetura do projeto foi desenhada seguindo princípios estritos de Orientação a Objetos e Padrões de Projeto (GoF). O foco foi o desacoplamento entre a lógica de jogo, o gerenciamento de estados e a renderização.

![Arquitetura do Projeto](diagrama_classes.jpg)
*Diagrama de Classes detalhando a hierarquia de entidades e gerenciadores.*

### Destaques da Implementação Técnica:

* **State Pattern (Padrão de Estado):** Implementação de uma Máquina de Estados para gerenciar os comportamentos das entidades (Inimigos e Jogador) e os estados do jogo (Menu, Gameplay, Pause), evitando cadeias complexas de `if/else`.
* **Gerenciamento de Memória:** Controle manual de alocação e desalocação de objetos. Uso de listas encadeadas personalizadas para gerenciar as entidades ativas na cena, garantindo performance e evitando memory leaks.
* **Polimorfismo e Herança:** Uso de uma classe base abstrata `Entidade` da qual derivam todos os objetos do jogo (`Personagem`, `Projetil`, `Obstaculo`), permitindo que o gerenciador trate todos os objetos de forma genérica.
* **Gerenciadores (Managers):** Separação de responsabilidades com classes dedicadas para gerenciar Colisões, Gráficos e Estados.

---

## 🛠️ Tecnologias Utilizadas

* **Linguagem:** C++ (Padrão C++11/14)
* **Biblioteca Gráfica:** SFML (Simple and Fast Multimedia Library)
* **Padrões de Projeto:** State, Adapter, Singleton, Iterator, Mediator e Observer.
* **Ferramentas:** Visual Studio, Git.

---

## 🚀 Funcionalidades da Engine

1.  **Sistema de Física Vetorial:** Cálculo manual de velocidade, aceleração e gravidade utilizando geometria analítica e álgebra linear.
2.  **Colisão AABB:** Implementação de algoritmo de detecção de colisão AABB para interações precisas entre entidades.
3.  **Persistência de Dados:** Sistema de salvamento e carregamento de estado do jogo (Save/Load) utilizando arquivos texto.
4.  **Sistema de Listas Dinâmicas:** Implementação de Templates e Iterators para percorrer as entidades do jogo de forma eficiente.
---
## 👨‍💻 Autores

Projeto desenvolvido como parte da disciplina de Técnicas de Programação na UTFPR.

* **Felipe Simbalista** - [GitHub](https://github.com/Sk-3) | [LinkedIn](https://www.linkedin.com/in/felipe-simbalista)
    * *Foco:* Arquitetura da Engine, Lógica e Otimização do código.
* **Ramon Vargas**
    * *Foco:* Documentação por meio do desenvolvimento de um diagrama UML e da escrita do relatório.
---