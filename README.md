# Sistema de Gestão Scrum - TP1

## Sobre o Projeto
[cite_start]Sistema de software desenvolvido em C++ com o propósito de prover suporte a projeto onde os requisitos funcionais são especificados por histórias de usuário e a gestão ocorre por processo embasado em elementos do arcabouço Scrum[cite: 148]. [cite_start]O projeto adota estritamente o estilo de arquitetura em camadas, separando o sistema em camada de apresentação e camada de serviço[cite: 163, 164].

## Objetivo
[cite_start]Projetar, codificar e documentar um sistema completo aplicando conceitos de programação orientada a objetos, incluindo classes de domínio, classes entidade, controladoras e contêiners[cite: 143, 144, 171]. 

## Funcionalidades
* [cite_start]**Gestão de Usuários:** Permite criar uma conta informando email, nome, senha e papel no projeto[cite: 149].
* [cite_start]**Controle de Papéis (Roles):** O usuário pode assumir as funções de Proprietário de Produto (Product Owner), Mestre Scrum (Scrum Master) ou Desenvolvedor (Developer)[cite: 150].
* [cite_start]**Autenticação:** Acesso liberado aos serviços do sistema após o usuário informar email e senha[cite: 151, 152].
* [cite_start]**Gestão de Sprints e Histórias:** * O sistema garante que a soma das capacidades dos planos de sprint seja menor ou igual ao número de dias do projeto[cite: 153].
  * [cite_start]A soma das estimativas das histórias de usuário deve ser menor ou igual à capacidade do plano de sprint correspondente[cite: 154].
* [cite_start]**Gerenciamento de Entidades:** Listagem e leitura dos dados e códigos de entidades (como plano de sprint e história de usuário)[cite: 155, 156].
* [cite_start]**Integridade e Validação:** * O sistema impede a edição de dados que identifiquem a entidade (chave primária)[cite: 157].
  * [cite_start]Exclusões são tratadas para não resultar em inconsistências[cite: 158].
  * [cite_start]Classes de domínio lançam exceções em caso de formatos inválidos (ex: regras específicas para textos, pontuação e espaços em branco)[cite: 160, 161, 162, 181].

## Tecnologias Utilizadas
* [cite_start]**C++** - Linguagem de programação exigida para o código-fonte[cite: 172].
* [cite_start]**Code::Blocks** - Ambiente de desenvolvimento (IDE) compatível e recomendado[cite: 173].
* [cite_start]**Doxygen** - Ferramenta utilizada para geração automática de documentação HTML[cite: 190].
* [cite_start]**SQLite / Memória** - Armazenamento de dados suportado por banco de dados relacional ou estruturas em memória (fila, pilha)[cite: 197, 198].

## Estrutura do Projeto (Arquitetura)
[cite_start]O sistema é decomposto em no mínimo quatro módulos que interagem por meio de serviços especificados em interfaces[cite: 168, 170]:

* [cite_start]`/Dominios` - Classes domínio com atributos acessados via métodos set e get, contendo validações rigorosas[cite: 179, 180].
* [cite_start]`/Entidades` - Classes entidade compostas por atributos que são instâncias das classes domínio[cite: 182].
* [cite_start]`/Apresentacao` - Camada responsável pela interface com o usuário (gráfica ou texto) e validação dos dados de entrada[cite: 165, 194].
* [cite_start]`/Servico` - Camada responsável pela lógica de negócio e pelo armazenamento estruturado dos dados[cite: 166].
* [cite_start]`/Interfaces` - Declarações por meio de classes abstratas compostas por métodos virtuais puros[cite: 188, 189].

## Como Usar e Executar

1. [cite_start]**Pré-requisitos:** Certifique-se de ter o IDE **Code::Blocks** instalado[cite: 173].
2. [cite_start]**Download:** Faça o clone do repositório ou extraia os arquivos fontes (formato .zip)[cite: 205].
3. **Compilação:** Abra o projeto no Code::Blocks e compile. [cite_start]O projeto deve compilar e executar sem erros na plataforma de correção[cite: 203].
4. [cite_start]**Teste Fumaça (Smoke Test):** O projeto contém demonstrações de execução que validam, com cenários de sucesso, cada funcionalidade descrita nos requisitos funcionais[cite: 201, 202]. [cite_start]Um vídeo demonstrativo atestando o sucesso do código integrado também faz parte da entrega[cite: 200].

## Documentação Adicional
* [cite_start]A documentação técnica detalhada, gerada com o **Doxygen** sob a perspectiva dos usuários das classes, encontra-se nas páginas HTML do projeto[cite: 191, 192].
* [cite_start]O modelo de arquitetura de software (incluindo descrições textuais e o diagrama UML com módulos, interfaces e relacionamentos) está disponível em formato PDF[cite: 184, 185, 186, 187].

## Contexto Acadêmico

Este projeto foi desenvolvido como requisito prático da disciplina **Técnicas de Programação 1 (TP1)** do curso de Computação da **Universidade de Brasília (UnB)**.

O objetivo da disciplina é consolidar conceitos fundamentais de Engenharia de Software, incluindo:
* Programação Orientada a Objetos (C++)
* Arquitetura em Camadas (Apresentação e Serviço)
* Modelagem e Diagramação UML
* Padrões de Projeto (Design Patterns)
* Documentação de Código com Doxygen
Este projeto foi avaliado com a nota **9.6/10.0**

---

## Autores
* **Pedro Vitor Teixeira** - [GitHub](https://github.com/pedrov-teixeira)
* **Iago Batista Gomes de Carvalho** - [GitHub](https://github.com/IagoBGCarvalho)