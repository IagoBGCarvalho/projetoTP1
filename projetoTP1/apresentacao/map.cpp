#include "map.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

string formatarData(string data) {
    replace(data.begin(), data.end(), '-', '/');
    return data;
}

bool MAP::executar(const Email& emailUsuarioLogado) {
    if (this->servicoProjeto == nullptr || this->servicoCadastro == nullptr) {
        cout << "Erro interno: Servicos nao injetados no MAP." << endl;
        return false;
    }

    string opcao;
    bool deslogar = false;

    while (!deslogar) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        cout << "========================================" << endl;
        cout << "   SISTEMA SCRUM - PAINEL DE CONTROLE   " << endl;
        cout << " Utilizador: " << emailUsuarioLogado.getEmail() << endl;
        cout << "========================================" << endl;
        cout << " 1 - Gestao de Projetos" << endl;
        cout << " 2 - Gestao de Sprints" << endl;
        cout << " 3 - Gestao de Historias de Usuario" << endl;
        cout << " 4 - Minha Conta (Pessoa)" << endl;
        cout << " 5 - Logout (Sair da conta)" << endl;
        cout << "========================================" << endl;
        cout << "Escolha um modulo: ";

        getline(cin, opcao);

        if (opcao == "1") menuProjetos(emailUsuarioLogado);
        else if (opcao == "2") menuSprints(emailUsuarioLogado);
        else if (opcao == "3") menuHistorias(emailUsuarioLogado);
        else if (opcao == "4") {
            if (menuPessoa(emailUsuarioLogado)) {
                cout << "\nConta excluida. Realizando logout automatico...\n" << endl;
                deslogar = true;
            }
        }
        else if (opcao == "5") {
            cout << "\nRealizando logout...\n" << endl;
            deslogar = true;
        } else {
            cout << "\nOpcao invalida! Pressione ENTER." << endl;
            cin.get();
        }
    }
    return false;
}

void MAP::menuProjetos(const Email& emailUsuarioLogado) {
    string opcao;
    bool voltar = false;

    while (!voltar) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        cout << "========================================" << endl;
        cout << "             GESTAO DE PROJETOS             " << endl;
        cout << "========================================" << endl;
        cout << " 1. Criar Novo Projeto" << endl;
        cout << " 2. Procurar Projeto (Ler detalhes)" << endl;
        cout << " 3. Atualizar Projeto" << endl;
        cout << " 4. Excluir Projeto" << endl;
        cout << " 5. Listar Meus Projetos" << endl;
        cout << " 6. Listar Historias do Projeto" << endl;
        cout << " 7. Voltar ao Painel Principal" << endl;
        cout << "========================================" << endl;
        cout << "Escolha uma opcao: ";
        getline(cin, opcao);

        if (opcao == "1") {
            cout << "\n--- NOVO PROJETO ---" << endl;
            string codigoDigitado, nomeDigitado, dataInicioDigitada, dataTerminoDigitada, emailMembroStr;
            Codigo codigo; Nome nome; Data inicio; Data termino; Projeto novoProjeto;

            cout << "Codigo do projeto (ou 'sair'): "; getline(cin, codigoDigitado);
            if (codigoDigitado == "sair" || codigoDigitado == "SAIR") continue;

            cout << "Nome do projeto: "; getline(cin, nomeDigitado);
            cout << "Data de Inicio: "; getline(cin, dataInicioDigitada);
            cout << "Data de Termino: "; getline(cin, dataTerminoDigitada);
            cout << "E-mail da pessoa a associar ao projeto: "; getline(cin, emailMembroStr);

            try {
                codigo.setCodigo(codigoDigitado); nome.setNome(nomeDigitado);
                inicio.setData(dataInicioDigitada); termino.setData(dataTerminoDigitada);

                novoProjeto.setCodigo(codigo); novoProjeto.setNome(nome);
                novoProjeto.setInicio(inicio); novoProjeto.setTermino(termino);

                Email emailMembro; emailMembro.setEmail(emailMembroStr);
                Pessoa eu, outro;

                if (this->servicoCadastro->ler(emailUsuarioLogado, eu) && this->servicoCadastro->ler(emailMembro, outro)) {
                    string meuPapel = eu.getPapel().getPapel();

                    if (meuPapel == "PROPRIETARIO DE PRODUTO") {
                        novoProjeto.setProductOwner(emailUsuarioLogado);
                        novoProjeto.setScrumMaster(emailMembro);
                    } else if (meuPapel == "MESTRE SCRUM") {
                        novoProjeto.setScrumMaster(emailUsuarioLogado);
                        novoProjeto.setProductOwner(emailMembro);
                    } else {
                        cout << "\nErro: Apenas Product Owner ou Mestre Scrum podem criar projetos.\n" << endl;
                        cout << "Pressione ENTER para continuar."; cin.get();
                        continue;
                    }

                    if (this->servicoProjeto->cadastrarProjeto(novoProjeto)) cout << "\n>>> Projeto registado com sucesso! <<<\n" << endl;
                    else cout << "\nErro: Nao foi possivel registar. Codigo ja em uso?\n" << endl;
                } else {
                    cout << "\nErro: A pessoa associada informada nao foi encontrada no sistema.\n" << endl;
                }
            } catch (const invalid_argument& e) {
                cout << "\nErro de validacao: " << e.what() << "\n" << endl;
            }
            cout << "Pressione ENTER para continuar."; cin.get();
        }
        else if (opcao == "2") {
            cout << "\n--- PROCURAR PROJETO ---" << endl;
            string codigoDigitado; Codigo codigo; Projeto p;

            cout << "Digite o Codigo do projeto que deseja procurar: ";
            getline(cin, codigoDigitado);

            try {
                codigo.setCodigo(codigoDigitado);
                if (this->servicoProjeto->lerProjeto(codigo, p)) {
                    cout << "\n>>> Detalhes do Projeto <<<" << endl;
                    cout << "Codigo: " << p.getCodigo().getCodigo() << endl;
                    cout << "Nome: " << p.getNome().getNome() << endl;
                    cout << "Inicio: " << formatarData(p.getInicio().getData()) << endl;
                    cout << "Termino: " << formatarData(p.getTermino().getData()) << endl;
                    cout << "PROPRIETARIO DE PRODUTO: " << p.getProductOwner().getEmail() << endl;
                    cout << "MESTRE SCRUM: " << p.getScrumMaster().getEmail() << endl;
                } else cout << "\nProjeto nao encontrado no sistema." << endl;
            } catch (const invalid_argument& e) { cout << "\nErro: Codigo invalido." << endl; }
            cout << "\nPressione ENTER para continuar."; cin.get();
        }
        else if (opcao == "3") {
            cout << "\n--- ATUALIZAR PROJETO ---" << endl;
            string codigoDigitado, novoNomeDigitado, novaDataIni, novaDataFim;
            Codigo codigo; Nome novoNome; Data inicio; Data termino; Projeto projetoAtualizado;

            cout << "Digite o Codigo do projeto a atualizar: "; getline(cin, codigoDigitado);
            cout << "NOVO Nome do projeto: "; getline(cin, novoNomeDigitado);
            cout << "NOVA Data Inicio: "; getline(cin, novaDataIni);
            cout << "NOVA Data Termino: "; getline(cin, novaDataFim);

            try {
                codigo.setCodigo(codigoDigitado); novoNome.setNome(novoNomeDigitado);
                inicio.setData(novaDataIni); termino.setData(novaDataFim);

                projetoAtualizado.setCodigo(codigo); projetoAtualizado.setNome(novoNome);
                projetoAtualizado.setInicio(inicio); projetoAtualizado.setTermino(termino);

                if (this->servicoProjeto->atualizarProjeto(projetoAtualizado)) cout << "\n>>> Projeto atualizado com sucesso! <<<\n" << endl;
                else cout << "\nErro ao atualizar. O projeto existe?" << endl;
            } catch (const invalid_argument& e) { cout << "\nErro nos dados fornecidos: " << e.what() << endl; }
            cout << "\nPressione ENTER para continuar."; cin.get();
        }
        else if (opcao == "4") {
            cout << "\n--- EXCLUIR PROJETO ---" << endl;
            string codigoDigitado; Codigo codigo;
            cout << "Digite o Codigo do projeto a ser excluido: "; getline(cin, codigoDigitado);

            try {
                codigo.setCodigo(codigoDigitado);
                cout << "Tem a certeza? (S/N): "; string confirmacao; getline(cin, confirmacao);
                if (confirmacao == "S" || confirmacao == "s") {
                    if (this->servicoProjeto->excluirProjeto(codigo)) cout << "\n>>> Projeto excluido com sucesso! <<<\n" << endl;
                    else cout << "\nErro ao excluir. O projeto existe?" << endl;
                } else cout << "\nOperacao cancelada." << endl;
            } catch (const invalid_argument& e) { cout << "\nErro: Codigo em formato invalido." << endl; }
            cout << "\nPressione ENTER para continuar."; cin.get();
        }
        else if (opcao == "5") {
            cout << "\n--- MEUS PROJETOS ---" << endl;
            vector<Codigo> codigosProjetos;
            if (this->servicoProjeto->listarProjetosPorPessoa(emailUsuarioLogado, codigosProjetos)) {
                if (codigosProjetos.empty()) cout << "Ainda nao tem nenhum projeto associado a si." << endl;
                else {
                    cout << "Projetos encontrados: " << codigosProjetos.size() << "\n" << endl;
                    for (const Codigo& c : codigosProjetos) {
                        Projeto p;
                        if (this->servicoProjeto->lerProjeto(c, p)) {
                            cout << "[ " << p.getCodigo().getCodigo() << " ] - " << p.getNome().getNome() << " | PO: " << p.getProductOwner().getEmail() << endl;
                        }
                    }
                }
            }
            cout << "\nPressione ENTER para continuar."; cin.get();
        }
        else if (opcao == "6") {
            cout << "\n--- HISTORIAS DO PROJETO ---" << endl;
            string codigoProjStr; Codigo codigoProj;
            cout << "Digite o Codigo do Projeto: "; getline(cin, codigoProjStr);
            try {
                codigoProj.setCodigo(codigoProjStr);
                vector<Codigo> codigosHistorias;
                if (this->servicoProjeto->listarHistoriasPorProjeto(codigoProj, codigosHistorias)) {
                    if (codigosHistorias.empty()) cout << "Nenhuma historia encontrada neste projeto." << endl;
                    else {
                        for(const Codigo& c : codigosHistorias) {
                            HistoriaDeUsuario h;
                            if(this->servicoProjeto->lerHistoria(c, h)) {
                                cout << "[" << h.getCodigo().getCodigo() << "] " << h.getTitulo().getTexto() << endl;
                            }
                        }
                    }
                } else cout << "Erro ao consultar o banco de dados." << endl;
            } catch (const invalid_argument& e) { cout << "\nErro: " << e.what() << endl; }
            cout << "\nPressione ENTER para continuar."; cin.get();
        }
        else if (opcao == "7") voltar = true;
        else { cout << "\nOpcao invalida. Pressione ENTER para tentar novamente."; cin.get(); }
    }
}

void MAP::menuSprints(const Email& emailUsuarioLogado) {
    string opcao; bool voltar = false;
    while (!voltar) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        cout << "========================================" << endl;
        cout << "          GESTAO DE SPRINTS             " << endl;
        cout << "========================================" << endl;
        cout << " 1. Criar Novo Sprint" << endl;
        cout << " 2. Procurar Sprint (Ler detalhes)" << endl;
        cout << " 3. Atualizar Sprint" << endl;
        cout << " 4. Excluir Sprint" << endl;
        cout << " 5. Listar Sprints do Projeto" << endl;
        cout << " 6. Listar Historias do Sprint" << endl;
        cout << " 7. Voltar ao Painel Principal" << endl;
        cout << "========================================" << endl;
        cout << "Escolha uma opcao: "; getline(cin, opcao);

        if (opcao == "1") {
            cout << "\n--- NOVO SPRINT ---" << endl;
            string codigoSprintStr, objetivoStr, capacidadeStr, codigoProjetoStr;
            Codigo codigoSprint, codigoProj; Texto objetivo; Tempo capacidade; PlanoDeSprint novoSprint;

            cout << "Codigo do Projeto de destino: "; getline(cin, codigoProjetoStr);
            cout << "Codigo do Sprint: "; getline(cin, codigoSprintStr);
            cout << "Objetivo do Sprint: "; getline(cin, objetivoStr);
            cout << "Capacidade (estimativa de tempo em horas): "; getline(cin, capacidadeStr);

            try {
                codigoSprint.setCodigo(codigoSprintStr); codigoProj.setCodigo(codigoProjetoStr);
                objetivo.setTexto(objetivoStr); capacidade.setTempo(stoi(capacidadeStr));

                novoSprint.setCodigo(codigoSprint); novoSprint.setCodigoProjeto(codigoProj);
                novoSprint.setObjetivo(objetivo); novoSprint.setCapacidade(capacidade);

                if (this->servicoProjeto->cadastrarSprint(novoSprint)) cout << "\n>>> Sprint registado com sucesso! <<<\n" << endl;
                else cout << "\nErro: Nao foi possivel criar o Sprint.\n" << endl;
            } catch (const invalid_argument& e) { cout << "\nErro de validacao: " << e.what() << "\n" << endl; }
            cout << "Pressione ENTER para continuar."; cin.get();
        }
        else if (opcao == "2") {
            cout << "\n--- PROCURAR SPRINT ---" << endl;
            string codigoStr; Codigo codigo; PlanoDeSprint sprint;
            cout << "Digite o Codigo do Sprint: "; getline(cin, codigoStr);
            try {
                codigo.setCodigo(codigoStr);
                if (this->servicoProjeto->lerSprint(codigo, sprint)) {
                    cout << "\n>>> Detalhes do Sprint <<<" << endl;
                    cout << "Codigo: " << sprint.getCodigo().getCodigo() << endl;
                    cout << "Projeto Associado: " << sprint.getCodigoProjeto().getCodigo() << endl;
                    cout << "Objetivo: " << sprint.getObjetivo().getTexto() << endl;
                    cout << "Capacidade: " << sprint.getCapacidade().getTempo() << " horas" << endl;
                } else cout << "\nSprint nao encontrado." << endl;
            } catch (const invalid_argument& e) { cout << "\nErro: " << e.what() << endl; }
            cout << "\nPressione ENTER para continuar."; cin.get();
        }
        else if (opcao == "3") {
            cout << "\n--- ATUALIZAR SPRINT ---" << endl;
            string codigoStr, objetivoStr, capStr; Codigo codigo; Texto objetivo; Tempo capacidade; PlanoDeSprint sprint;
            cout << "Codigo do Sprint a atualizar: "; getline(cin, codigoStr);
            cout << "Novo Objetivo: "; getline(cin, objetivoStr);
            cout << "Nova Capacidade (horas): "; getline(cin, capStr);
            try {
                codigo.setCodigo(codigoStr); objetivo.setTexto(objetivoStr); capacidade.setTempo(stoi(capStr));
                sprint.setCodigo(codigo); sprint.setObjetivo(objetivo); sprint.setCapacidade(capacidade);
                if (this->servicoProjeto->atualizarSprint(sprint)) cout << "\n>>> Sprint atualizado! <<<\n" << endl;
                else cout << "\nErro ao atualizar." << endl;
            } catch (const invalid_argument& e) { cout << "\nErro: " << e.what() << endl; }
            cout << "\nPressione ENTER para continuar."; cin.get();
        }
        else if (opcao == "4") {
            cout << "\n--- EXCLUIR SPRINT ---" << endl;
            string codigoStr; Codigo codigo;
            cout << "Digite o Codigo do Sprint a excluir: "; getline(cin, codigoStr);
            try {
                codigo.setCodigo(codigoStr);
                if (this->servicoProjeto->excluirSprint(codigo)) cout << "\n>>> Sprint excluido com sucesso! <<<" << endl;
                else cout << "\nErro: Sprint nao encontrado." << endl;
            } catch (const invalid_argument& e) { cout << "\nErro: " << e.what() << endl; }
            cout << "\nPressione ENTER para continuar."; cin.get();
        }
        else if (opcao == "5") {
            cout << "\n--- LISTAR SPRINTS POR PROJETO ---" << endl;
            string codigoProjetoStr; Codigo codigoProjeto;
            cout << "Digite o Codigo do Projeto: "; getline(cin, codigoProjetoStr);
            try {
                codigoProjeto.setCodigo(codigoProjetoStr); vector<Codigo> codigosSprints;
                if (this->servicoProjeto->listarSprintsPorProjeto(codigoProjeto, codigosSprints)) {
                    if (codigosSprints.empty()) cout << "Nenhum sprint encontrado para este projeto." << endl;
                    else {
                        for (const Codigo& c : codigosSprints) {
                            PlanoDeSprint s;
                            if(this->servicoProjeto->lerSprint(c, s)) cout << "[ID: " << s.getCodigo().getCodigo() << "] Objetivo: " << s.getObjetivo().getTexto() << endl;
                        }
                    }
                }
            } catch (const invalid_argument& e) { cout << "\nErro: " << e.what() << endl; }
            cout << "\nPressione ENTER para continuar."; cin.get();
        }
        else if (opcao == "6") {
            cout << "\n--- HISTORIAS DO SPRINT ---" << endl;
            string codigoSprintStr; Codigo codigoSprint;
            cout << "Digite o Codigo do Sprint: "; getline(cin, codigoSprintStr);
            try {
                codigoSprint.setCodigo(codigoSprintStr); vector<Codigo> codigosHistorias;
                if (this->servicoProjeto->listarHistoriasPorSprint(codigoSprint, codigosHistorias)) {
                    if (codigosHistorias.empty()) cout << "Nenhuma historia alocada neste sprint." << endl;
                    else {
                        for(const Codigo& c : codigosHistorias) {
                            HistoriaDeUsuario h;
                            if(this->servicoProjeto->lerHistoria(c, h)) cout << "[" << h.getCodigo().getCodigo() << "] " << h.getTitulo().getTexto() << " | Estado: " << h.getEstado().getEstado() << endl;
                        }
                    }
                }
            } catch (const invalid_argument& e) { cout << "\nErro: " << e.what() << endl; }
            cout << "\nPressione ENTER para continuar."; cin.get();
        }
        else if (opcao == "7") voltar = true;
    }
}

void MAP::menuHistorias(const Email& emailUsuarioLogado) {
    string opcao; bool voltar = false;
    while (!voltar) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        cout << "========================================" << endl;
        cout << "     GESTAO DE HISTORIAS DE USUARIO     " << endl;
        cout << "========================================" << endl;
        cout << " 1. Criar Nova Historia" << endl;
        cout << " 2. Procurar Historia (Ler detalhes)" << endl;
        cout << " 3. Atualizar Historia" << endl;
        cout << " 4. Excluir Historia" << endl;
        cout << "----------------------------------------" << endl;
        cout << " 5. Alterar Estado da Historia" << endl;
        cout << " 6. Associar Historia a um Membro" << endl;
        cout << " 7. Desassociar Historia de Membro" << endl;
        cout << " 8. Mover Historia para um Sprint" << endl;
        cout << "----------------------------------------" << endl;
        cout << " 9. Listar Minhas Historias" << endl;
        cout << " 10. Voltar ao Painel Principal" << endl;
        cout << "========================================" << endl;
        cout << "Escolha uma opcao: "; getline(cin, opcao);

        if (opcao == "1") {
            cout << "\n--- NOVA HISTORIA ---" << endl;
            string codigoStr, projStr, tituloStr, papelStr, acaoStr, valorStr, estimativaStr, prioridadeStr;
            Codigo codigo, codigoProj; Texto titulo, papel, acao, valor;
            Tempo estimativa; Prioridade prioridade; Estado estado; HistoriaDeUsuario novaHistoria;

            cout << "Codigo do Projeto de origem: "; getline(cin, projStr);
            cout << "Codigo da Historia (ou 'sair'): "; getline(cin, codigoStr);
            if (codigoStr == "sair" || codigoStr == "SAIR") continue;

            cout << "Titulo: "; getline(cin, tituloStr);
            cout << "Papel (Como um...): "; getline(cin, papelStr);
            cout << "Acao (Eu quero...): "; getline(cin, acaoStr);
            cout << "Valor (Para que...): "; getline(cin, valorStr);
            cout << "Estimativa (Tempo em horas): "; getline(cin, estimativaStr);
            cout << "Prioridade (Alta/Media/Baixa): "; getline(cin, prioridadeStr);

            try {
                codigoProj.setCodigo(projStr); codigo.setCodigo(codigoStr);
                titulo.setTexto(tituloStr); papel.setTexto(papelStr);
                acao.setTexto(acaoStr); valor.setTexto(valorStr);
                estimativa.setTempo(stoi(estimativaStr)); prioridade.setPrioridade(prioridadeStr);

                // Formato correto de estado adicionado
                estado.setEstado("A FAZER");

                novaHistoria.setCodigo(codigo); novaHistoria.setCodigoProjeto(codigoProj);
                novaHistoria.setTitulo(titulo); novaHistoria.setPapel(papel);
                novaHistoria.setAcao(acao); novaHistoria.setValor(valor);
                novaHistoria.setEstimativa(estimativa); novaHistoria.setPrioridade(prioridade);
                novaHistoria.setEstado(estado);

                if (this->servicoProjeto->cadastrarHistoria(novaHistoria)) cout << "\n>>> Historia registada com estado A FAZER! <<<\n" << endl;
                else cout << "\nErro: Nao foi possivel registar.\n" << endl;
            } catch (const invalid_argument& e) { cout << "\nErro de validacao: " << e.what() << "\n" << endl; }
            cout << "Pressione ENTER para continuar."; cin.get();
        }
        else if (opcao == "2") {
            cout << "\n--- PROCURAR HISTORIA ---" << endl;
            string codigoStr; Codigo codigo; HistoriaDeUsuario h;
            cout << "Digite o Codigo da Historia: "; getline(cin, codigoStr);
            try {
                codigo.setCodigo(codigoStr);
                if (this->servicoProjeto->lerHistoria(codigo, h)) {
                    cout << "\n>>> Detalhes da Historia <<<" << endl;
                    cout << "Codigo: " << h.getCodigo().getCodigo() << endl;
                    cout << "Projeto Associado: " << h.getCodigoProjeto().getCodigo() << endl;
                    cout << "Sprint Atual: " << h.getCodigoSprint().getCodigo() << endl;
                    cout << "E-mail do Dev: " << h.getEmailDesenvolvedor().getEmail() << endl;
                    cout << "Titulo: " << h.getTitulo().getTexto() << endl;
                    cout << "Papel: " << h.getPapel().getTexto() << endl;
                    cout << "Acao: " << h.getAcao().getTexto() << endl;
                    cout << "Valor: " << h.getValor().getTexto() << endl;
                    cout << "Estimativa: " << h.getEstimativa().getTempo() << " horas" << endl;
                    cout << "Prioridade: " << h.getPrioridade().getPrioridade() << endl;
                    cout << "Estado: " << h.getEstado().getEstado() << endl;
                } else cout << "\nHistoria nao encontrada no sistema." << endl;
            } catch (const invalid_argument& e) { cout << "\nErro: " << e.what() << endl; }
            cout << "\nPressione ENTER para continuar."; cin.get();
        }
        else if (opcao == "3") {
            cout << "\n--- ATUALIZAR HISTORIA ---" << endl;
            string codigoStr, tituloStr, papelStr, acaoStr, valorStr, estimativaStr, prioridadeStr;
            Codigo codigo; Texto titulo, papel, acao, valor; Tempo estimativa; Prioridade prioridade; HistoriaDeUsuario hAtualizada;

            cout << "Digite o Codigo da Historia a atualizar: "; getline(cin, codigoStr);
            cout << "NOVO Titulo: "; getline(cin, tituloStr);
            cout << "NOVO Papel: "; getline(cin, papelStr);
            cout << "NOVA Acao: "; getline(cin, acaoStr);
            cout << "NOVO Valor: "; getline(cin, valorStr);
            cout << "NOVA Estimativa (Tempo em horas): "; getline(cin, estimativaStr);
            cout << "NOVA Prioridade (Alta/Media/Baixa): "; getline(cin, prioridadeStr);

            try {
                codigo.setCodigo(codigoStr); titulo.setTexto(tituloStr); papel.setTexto(papelStr);
                acao.setTexto(acaoStr); valor.setTexto(valorStr); estimativa.setTempo(stoi(estimativaStr));
                prioridade.setPrioridade(prioridadeStr);

                HistoriaDeUsuario original;
                if (this->servicoProjeto->lerHistoria(codigo, original)) {
                    hAtualizada.setCodigo(codigo); hAtualizada.setTitulo(titulo);
                    hAtualizada.setPapel(papel); hAtualizada.setAcao(acao);
                    hAtualizada.setValor(valor); hAtualizada.setEstimativa(estimativa);
                    hAtualizada.setPrioridade(prioridade); hAtualizada.setEstado(original.getEstado());
                    hAtualizada.setCodigoProjeto(original.getCodigoProjeto());

                    if (this->servicoProjeto->atualizarHistoria(hAtualizada)) cout << "\n>>> Historia atualizada com sucesso! <<<\n" << endl;
                    else cout << "\nErro ao atualizar no banco.\n" << endl;
                } else cout << "\nErro: Historia nao existe." << endl;
            } catch (const invalid_argument& e) { cout << "\nErro de validacao: " << e.what() << endl; }
            cout << "Pressione ENTER para continuar."; cin.get();
        }
        else if (opcao == "4") {
            cout << "\n--- EXCLUIR HISTORIA ---" << endl;
            string codigoStr; Codigo codigo;
            cout << "Digite o Codigo da Historia a ser excluida: "; getline(cin, codigoStr);
            try {
                codigo.setCodigo(codigoStr);
                if (this->servicoProjeto->excluirHistoria(codigo)) cout << "\n>>> Historia excluida com sucesso! <<<\n" << endl;
                else cout << "\nErro ao excluir." << endl;
            } catch (const invalid_argument& e) { cout << "\nErro: " << e.what() << endl; }
            cout << "Pressione ENTER para continuar."; cin.get();
        }
        else if (opcao == "5") {
            cout << "\n--- ALTERAR ESTADO ---" << endl;
            string codigoStr, novoEstadoStr; Codigo codigo; Estado novoEstado;

            cout << "Digite o Codigo da Historia: "; getline(cin, codigoStr);
            cout << "Novo Estado (A FAZER / FAZENDO / FEITO): "; getline(cin, novoEstadoStr);
            try {
                codigo.setCodigo(codigoStr); novoEstado.setEstado(novoEstadoStr);
                if (this->servicoProjeto->alterarEstadoHistoria(codigo, novoEstado)) cout << "\n>>> Estado atualizado com sucesso! <<<\n" << endl;
                else cout << "\nErro ao atualizar o estado." << endl;
            } catch (const invalid_argument& e) { cout << "\nErro de validacao: " << e.what() << endl; }
            cout << "Pressione ENTER para continuar."; cin.get();
        }
        else if (opcao == "6") {
            cout << "\n--- ATRIBUIR HISTORIA A MEMBRO ---" << endl;
            string codigoStr, emailStr; Codigo codigo; Email emailMembro;
            cout << "Digite o Codigo da Historia: "; getline(cin, codigoStr);
            cout << "Digite o E-mail do Desenvolvedor (Pessoa): "; getline(cin, emailStr);
            try {
                codigo.setCodigo(codigoStr); emailMembro.setEmail(emailStr);
                if (this->servicoProjeto->associarHistoriaPessoa(codigo, emailMembro)) cout << "\n>>> Historia associada ao desenvolvedor com sucesso! <<<\n" << endl;
                else cout << "\nErro na associacao. Verifique se o codigo e o e-mail existem." << endl;
            } catch (const invalid_argument& e) { cout << "\nErro: " << e.what() << endl; }
            cout << "Pressione ENTER para continuar."; cin.get();
        }
        else if (opcao == "7") {
            cout << "\n--- DESASSOCIAR MEMBRO ---" << endl;
            string codigoStr, emailStr; Codigo codigo; Email emailMembro;
            cout << "Digite o Codigo da Historia: "; getline(cin, codigoStr);
            cout << "Digite o E-mail do Membro para remover associacao: "; getline(cin, emailStr);
            try {
                codigo.setCodigo(codigoStr); emailMembro.setEmail(emailStr);
                if (this->servicoProjeto->desassociarHistoriaPessoa(codigo, emailMembro)) cout << "\n>>> Associacao removida! <<<\n" << endl;
                else cout << "\nErro na desassociacao." << endl;
            } catch (const invalid_argument& e) { cout << "\nErro: " << e.what() << endl; }
            cout << "Pressione ENTER para continuar."; cin.get();
        }
        else if (opcao == "8") {
            cout << "\n--- MOVER PARA SPRINT ---" << endl;
            string codigoHistStr, codigoSprintStr; Codigo codigoHist; Codigo codigoSprint;
            cout << "Digite o Codigo da Historia: "; getline(cin, codigoHistStr);
            cout << "Digite o Codigo do Sprint de destino: "; getline(cin, codigoSprintStr);
            try {
                codigoHist.setCodigo(codigoHistStr); codigoSprint.setCodigo(codigoSprintStr);
                if (this->servicoProjeto->moverHistoriaParaSprint(codigoHist, codigoSprint)) cout << "\n>>> Historia movida para o Sprint com sucesso! <<<\n" << endl;
                else cout << "\nErro. Verifique se a Historia e o Sprint existem." << endl;
            } catch (const invalid_argument& e) { cout << "\nErro: " << e.what() << endl; }
            cout << "Pressione ENTER para continuar."; cin.get();
        }
        else if (opcao == "9") {
            cout << "\n--- MINHAS HISTORIAS ---" << endl;
            vector<Codigo> codigosHistorias;
            if (this->servicoProjeto->listarHistoriasPorPessoa(emailUsuarioLogado, codigosHistorias)) {
                if (codigosHistorias.empty()) cout << "Voce nao possui historias atribuidas." << endl;
                else {
                    for(const Codigo& c : codigosHistorias) {
                        HistoriaDeUsuario h;
                        if(this->servicoProjeto->lerHistoria(c, h)) {
                            cout << "[" << h.getCodigo().getCodigo() << "] " << h.getTitulo().getTexto() << " | Estado: " << h.getEstado().getEstado() << endl;
                        }
                    }
                }
            }
            cout << "Pressione ENTER para continuar."; cin.get();
        }
        else if (opcao == "10") voltar = true;
        else { cout << "\nOpcao invalida. Pressione ENTER."; cin.get(); }
    }
}

bool MAP::menuPessoa(const Email& emailUsuarioLogado) {
    string opcao; bool voltar = false;

    while (!voltar) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        cout << "========================================" << endl;
        cout << "          GESTAO DE PESSOA              " << endl;
        cout << "========================================" << endl;
        cout << " 1. Ver meus dados" << endl;
        cout << " 2. Atualizar meus dados" << endl;
        cout << " 3. Excluir minha conta" << endl;
        cout << " 4. Voltar ao Painel Principal" << endl;
        cout << "========================================" << endl;
        cout << "Escolha uma opcao: "; getline(cin, opcao);

        if (opcao == "1") {
            Pessoa p;
            if (this->servicoCadastro->ler(emailUsuarioLogado, p)) {
                cout << "\n>>> Meus Dados <<<" << endl;
                cout << "Email: " << p.getEmail().getEmail() << endl;
                cout << "Nome:  " << p.getNome().getNome() << endl;
                cout << "Papel: " << p.getPapel().getPapel() << endl;
            } else {
                cout << "\nErro: Nao foi possivel recuperar os dados." << endl;
            }
            cout << "\nPressione ENTER para continuar."; cin.get();
        }
        else if (opcao == "2") {
            string nomeStr, senhaStr;
            Nome novoNome; Senha novaSenha; Pessoa pAtualizada;

            // Lê os dados atuais para preservar email e papel (não editáveis)
            Pessoa pAtual;
            if (!this->servicoCadastro->ler(emailUsuarioLogado, pAtual)) {
                cout << "\nErro: Nao foi possivel recuperar os dados atuais." << endl;
                cout << "Pressione ENTER para continuar."; cin.get();
                continue;
            }

            cout << "\n--- ATUALIZAR DADOS ---" << endl;
            cout << "NOVO Nome (atual: " << pAtual.getNome().getNome() << "): ";
            getline(cin, nomeStr);
            cout << "NOVA Senha: ";
            getline(cin, senhaStr);

            try {
                novoNome.setNome(nomeStr);
                novaSenha.setSenha(senhaStr);

                pAtualizada.setEmail(emailUsuarioLogado);
                pAtualizada.setNome(novoNome);
                pAtualizada.setSenha(novaSenha);
                pAtualizada.setPapel(pAtual.getPapel()); // papel não muda

                if (this->servicoCadastro->atualizar(pAtualizada)) {
                    cout << "\n>>> Dados atualizados com sucesso! <<<\n" << endl;
                } else {
                    cout << "\nErro ao atualizar os dados.\n" << endl;
                }
            } catch (const invalid_argument& e) {
                cout << "\nErro de validacao: " << e.what() << endl;
            }
            cout << "Pressione ENTER para continuar."; cin.get();
        }
        else if (opcao == "3") {
            cout << "\n--- EXCLUIR CONTA ---" << endl;
            cout << "Tem certeza que deseja excluir sua conta? Esta acao e irreversivel. (S/N): ";
            string confirmacao; getline(cin, confirmacao);

            if (confirmacao == "S" || confirmacao == "s") {
                if (this->servicoCadastro->excluir(emailUsuarioLogado)) {
                    cout << "\n>>> Conta excluida com sucesso. Voce sera deslogado. <<<\n" << endl;
                    cout << "Pressione ENTER para continuar."; cin.get();
                    return true;
                } else {
                    cout << "\nErro ao excluir a conta.\n" << endl;
                    cout << "Pressione ENTER para continuar."; cin.get();
                }
            } else {
                cout << "\nOperacao cancelada." << endl;
                cout << "Pressione ENTER para continuar."; cin.get();
            }
        }
        else if (opcao == "4") {
            voltar = true;
        }
        else {
            cout << "\nOpcao invalida. Pressione ENTER."; cin.get();
        }
    }

    return false;
}

