# Sistema de Gestão Scrum - TP1

## Sobre o Projeto
Sistema de software desenvolvido em C++ com o propósito de prover suporte a projeto onde os requisitos funcionais são especificados por histórias de usuário e a gestão ocorre por processo embasado em elementos do arcabouço Scrum. O projeto adota estritamente o estilo de arquitetura em camadas, separando o sistema em camada de apresentação e camada de serviço.

## Objetivo
Projetar, codificar e documentar um sistema completo aplicando conceitos de programação orientada a objetos, incluindo classes de domínio, classes entidade, controladoras e contêiners.

## Funcionalidades
* **Gestão de Usuários:** Permite criar uma conta informando email, nome, senha e papel no projeto.
* **Controle de Papéis (Roles):** O usuário pode assumir as funções de Proprietário de Produto (Product Owner), Mestre Scrum (Scrum Master) ou Desenvolvedor (Developer).
* **Autenticação:** Acesso liberado aos serviços do sistema após o usuário informar email e senha.
* **Gestão de Sprints e Histórias:**
  * O sistema garante que a soma das capacidades dos planos de sprint seja menor ou igual ao número de dias do projeto.
  * A soma das estimativas das histórias de usuário deve ser menor ou igual à capacidade do plano de sprint correspondente.
* **Gerenciamento de Entidades:** Listagem e leitura dos dados e códigos de entidades (como plano de sprint e história de usuário).
* **Integridade e Validação:**
  * O sistema impede a edição de dados que identifiquem a entidade (chave primária).
  * Exclusões são tratadas para não resultar em inconsistências.
  * Classes de domínio lançam exceções em caso de formatos inválidos (ex: regras específicas para textos, pontuação e espaços em branco).

## Tecnologias Utilizadas
* **C++** - Linguagem de programação exigida para o código-fonte.
* **Code::Blocks** - Ambiente de desenvolvimento (IDE) compatível e recomendado.
* **Doxygen** - Ferramenta utilizada para geração automática de documentação HTML.
* **SQLite / Memória** - Armazenamento de dados suportado por banco de dados relacional ou estruturas em memória (fila, pilha).

## Estrutura do Projeto
O sistema é decomposto em no mínimo quatro módulos que interagem por meio de serviços especificados em interfaces:

* `/dominios` - Classes domínio com atributos acessados via métodos set e get, contendo validações rigorosas.
* `/entidades` - Classes entidade compostas por atributos que são instâncias das classes domínio.
* `/apresentacao` - Camada responsável pela interface com o usuário (gráfica ou texto) e validação dos dados de entrada.
* `/service` - Camada responsável pela lógica de negócio e pelo armazenamento estruturado dos dados.
* `/interfaces` - Declarações por meio de classes abstratas compostas por métodos virtuais puros.

## Como Usar e Executar

1. **Pré-requisitos:** Certifique-se de ter o IDE **Code::Blocks** instalado.
2. **Download:** Faça o clone do repositório ou extraia os arquivos fontes (formato .zip).
3. **Compilação:** Abra o projeto no Code::Blocks e compile. O projeto deve compilar e executar sem erros na plataforma de correção.
4. **Teste Fumaça (Smoke Test):** O projeto contém demonstrações de execução que validam, com cenários de sucesso, cada funcionalidade descrita nos requisitos funcionais. Um vídeo demonstrativo atestando o sucesso do código integrado também faz parte da entrega.

## Documentação Adicional
* A documentação técnica detalhada, gerada com o **Doxygen** sob a perspectiva dos usuários das classes, encontra-se nas páginas HTML do projeto.
* O modelo de arquitetura de software (incluindo descrições textuais e o diagrama UML com módulos, interfaces e relacionamentos) está disponível em formato PDF.

## Contexto Acadêmico

Este projeto foi desenvolvido como requisito prático da disciplina **Técnicas de Programação 1 (TP1)** do curso de Computação da **Universidade de Brasília (UnB)**.

O objetivo da disciplina é consolidar conceitos fundamentais de Engenharia de Software, incluindo:
* Programação Orientada a Objetos (C++)
* Arquitetura em Camadas (Apresentação e Serviço)
* Modelagem e Diagramação UML
* Padrões de Projeto (Design Patterns)
* Documentação de Código com Doxygen

---

## Autores
* **Pedro Vitor Teixeira** - [GitHub](https://github.com/pedrov-teixeira)
* **Iago Batista Gomes de Carvalho** - [GitHub](https://github.com/IagoBGCarvalho)