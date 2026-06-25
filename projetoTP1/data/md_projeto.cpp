#include "md_projeto.hpp"
#include "../entidades/entidades.hpp"
#include "../dominios/dominios.hpp"
#include <iostream>

MDProjeto::MDProjeto() {
    if (sqlite3_open(dbName.c_str(), &db) == SQLITE_OK) {
        inicializarBanco();
    } else {
        std::cerr << "Erro ao abrir DB em MDProjeto: " << sqlite3_errmsg(db) << std::endl;
    }
}

MDProjeto::~MDProjeto() {
    if (db) sqlite3_close(db);
}

void MDProjeto::inicializarBanco() {
    std::string sqlProjetos =
        "CREATE TABLE IF NOT EXISTS PROJETO ("
        "codigo TEXT PRIMARY KEY, "
        "nome TEXT NOT NULL, "
        "inicio TEXT NOT NULL, "
        "termino TEXT NOT NULL, "
        "email_scrum_master TEXT, "
        "email_product_owner TEXT);";

    std::string sqlSprints =
        "CREATE TABLE IF NOT EXISTS PLANO_DE_SPRINT ("
        "codigo TEXT PRIMARY KEY, "
        "objetivo TEXT NOT NULL, "
        "capacidade INTEGER NOT NULL, "
        "codigo_projeto TEXT);";

    std::string sqlHistorias =
        "CREATE TABLE IF NOT EXISTS HISTORIA_DE_USUARIO ("
        "codigo TEXT PRIMARY KEY, "
        "titulo TEXT, "
        "papel TEXT, "
        "acao TEXT, "
        "valor TEXT, "
        "estimativa INTEGER, "
        "prioridade TEXT, "
        "estado TEXT, "
        "codigo_projeto TEXT, "
        "codigo_sprint TEXT, "
        "email_desenvolvedor TEXT);";

    sqlite3_exec(db, sqlProjetos.c_str(), nullptr, nullptr, nullptr);
    sqlite3_exec(db, sqlHistorias.c_str(), nullptr, nullptr, nullptr);
    sqlite3_exec(db, sqlSprints.c_str(), nullptr, nullptr, nullptr);
}

// CRUD: Projeto

bool MDProjeto::cadastrarProjeto(const Projeto& projeto) {
    std::string sql = "INSERT INTO PROJETO (codigo, nome, inicio, termino) VALUES (?, ?, ?, ?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return false;

    sqlite3_bind_text(stmt, 1, projeto.getCodigo().getCodigo().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, projeto.getNome().getNome().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, projeto.getInicio().getData().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, projeto.getTermino().getData().c_str(), -1, SQLITE_TRANSIENT);

    bool sucesso = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);
    return sucesso;
}

bool MDProjeto::lerProjeto(const Codigo& codigo, Projeto& projeto) {
    std::string sql = "SELECT nome, inicio, termino FROM PROJETO WHERE codigo = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return false;

    sqlite3_bind_text(stmt, 1, codigo.getCodigo().c_str(), -1, SQLITE_TRANSIENT);

    bool encontrado = false;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        Nome nome; nome.setNome(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        Data inicio; inicio.setData(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        Data termino; termino.setData(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));

        projeto.setCodigo(codigo);
        projeto.setNome(nome);
        projeto.setInicio(inicio);
        projeto.setTermino(termino);
        encontrado = true;
    }

    sqlite3_finalize(stmt);
    return encontrado;
}

bool MDProjeto::atualizarProjeto(const Projeto& projeto) {
    std::string sql = "UPDATE PROJETO SET nome = ?, inicio = ?, termino = ? WHERE codigo = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return false;

    sqlite3_bind_text(stmt, 1, projeto.getNome().getNome().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, projeto.getInicio().getData().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, projeto.getTermino().getData().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, projeto.getCodigo().getCodigo().c_str(), -1, SQLITE_TRANSIENT);

    bool sucesso = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);
    return sucesso;
}

bool MDProjeto::excluirProjeto(const Codigo& codigo) {
    std::string sql = "DELETE FROM PROJETO WHERE codigo = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return false;

    sqlite3_bind_text(stmt, 1, codigo.getCodigo().c_str(), -1, SQLITE_TRANSIENT);

    bool sucesso = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);
    return sucesso;
}

// CRUD: História de Usuário

bool MDProjeto::cadastrarHistoria(const HistoriaDeUsuario& historia) {
    std::string sql = "INSERT INTO HISTORIA_DE_USUARIO (codigo, titulo, papel, acao, valor, estimativa, prioridade, estado) VALUES (?, ?, ?, ?, ?, ?, ?, ?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return false;

    sqlite3_bind_text(stmt, 1, historia.getCodigo().getCodigo().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, historia.getTitulo().getTexto().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, historia.getPapel().getTexto().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, historia.getAcao().getTexto().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, historia.getValor().getTexto().c_str(), -1, SQLITE_TRANSIENT);

    sqlite3_bind_int(stmt, 6, historia.getEstimativa().getTempo());

    sqlite3_bind_text(stmt, 7, historia.getPrioridade().getPrioridade().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 8, historia.getEstado().getEstado().c_str(), -1, SQLITE_TRANSIENT);

    bool sucesso = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);
    return sucesso;
}

bool MDProjeto::lerHistoria(const Codigo& codigo, HistoriaDeUsuario& historia) {
    std::string sql = "SELECT titulo, papel, acao, valor, estimativa, prioridade, estado FROM HISTORIA_DE_USUARIO WHERE codigo = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return false;

    sqlite3_bind_text(stmt, 1, codigo.getCodigo().c_str(), -1, SQLITE_TRANSIENT);

    bool encontrado = false;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        Texto titulo; titulo.setTexto(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        Texto papel; papel.setTexto(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        Texto acao; acao.setTexto(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        Texto valor; valor.setTexto(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));

        Tempo estimativa; estimativa.setTempo(sqlite3_column_int(stmt, 4));

        Prioridade prioridade; prioridade.setPrioridade(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
        Estado estado; estado.setEstado(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));

        historia.setCodigo(codigo);
        historia.setTitulo(titulo);
        historia.setPapel(papel);
        historia.setAcao(acao);
        historia.setValor(valor);
        historia.setEstimativa(estimativa);
        historia.setPrioridade(prioridade);
        historia.setEstado(estado);
        encontrado = true;
    }

    sqlite3_finalize(stmt);
    return encontrado;
}

bool MDProjeto::atualizarHistoria(const HistoriaDeUsuario& historia) {
    std::string sql = "UPDATE HISTORIA_DE_USUARIO SET titulo = ?, papel = ?, acao = ?, valor = ?, estimativa = ?, prioridade = ?, estado = ? WHERE codigo = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return false;

    sqlite3_bind_text(stmt, 1, historia.getTitulo().getTexto().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, historia.getPapel().getTexto().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, historia.getAcao().getTexto().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, historia.getValor().getTexto().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 5, historia.getEstimativa().getTempo());
    sqlite3_bind_text(stmt, 6, historia.getPrioridade().getPrioridade().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 7, historia.getEstado().getEstado().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 8, historia.getCodigo().getCodigo().c_str(), -1, SQLITE_TRANSIENT);

    bool sucesso = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);
    return sucesso;
}

bool MDProjeto::excluirHistoria(const Codigo& codigo) {
    std::string sql = "DELETE FROM HISTORIA_DE_USUARIO WHERE codigo = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return false;

    sqlite3_bind_text(stmt, 1, codigo.getCodigo().c_str(), -1, SQLITE_TRANSIENT);

    bool sucesso = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);
    return sucesso;
}

// CRUD: Plano de Sprint

bool MDProjeto::cadastrarSprint(const PlanoDeSprint& sprint) {
    std::string sql = "INSERT INTO PLANO_DE_SPRINT (codigo, objetivo, capacidade) VALUES (?, ?, ?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return false;

    // Extração segura dos dados dos domínios para o banco
    sqlite3_bind_text(stmt, 1, sprint.getCodigo().getCodigo().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, sprint.getObjetivo().getTexto().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 3, sprint.getCapacidade().getTempo());

    bool sucesso = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);
    return sucesso;
}

bool MDProjeto::lerSprint(const Codigo& codigo, PlanoDeSprint& sprint) {
    std::string sql = "SELECT objetivo, capacidade FROM PLANO_DE_SPRINT WHERE codigo = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return false;

    sqlite3_bind_text(stmt, 1, codigo.getCodigo().c_str(), -1, SQLITE_TRANSIENT);

    bool encontrado = false;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        // Reconstrói os domínios com os dados do banco
        Texto objetivo;
        objetivo.setTexto(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));

        Tempo capacidade;
        capacidade.setTempo(sqlite3_column_int(stmt, 1));

        // Preenche a entidade
        sprint.setCodigo(codigo);
        sprint.setObjetivo(objetivo);
        sprint.setCapacidade(capacidade);
        encontrado = true;
    }

    sqlite3_finalize(stmt);
    return encontrado;
}

bool MDProjeto::atualizarSprint(const PlanoDeSprint& sprint) {
    std::string sql = "UPDATE PLANO_DE_SPRINT SET objetivo = ?, capacidade = ? WHERE codigo = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return false;

    sqlite3_bind_text(stmt, 1, sprint.getObjetivo().getTexto().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 2, sprint.getCapacidade().getTempo());
    sqlite3_bind_text(stmt, 3, sprint.getCodigo().getCodigo().c_str(), -1, SQLITE_TRANSIENT);

    bool sucesso = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);
    return sucesso;
}

bool MDProjeto::excluirSprint(const Codigo& codigo) {
    std::string sql = "DELETE FROM PLANO_DE_SPRINT WHERE codigo = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return false;

    sqlite3_bind_text(stmt, 1, codigo.getCodigo().c_str(), -1, SQLITE_TRANSIENT);

    bool sucesso = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);
    return sucesso;
}

// MÉTODOS DE ASSOCIAÇÃO E LISTAGEM

bool MDProjeto::associarHistoriaPessoa(const Codigo& codigoHistoria, const Email& emailPessoa) {
    std::string sql = "UPDATE HISTORIA_DE_USUARIO SET email_desenvolvedor = ? WHERE codigo = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return false;

    sqlite3_bind_text(stmt, 1, emailPessoa.getEmail().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, codigoHistoria.getCodigo().c_str(), -1, SQLITE_TRANSIENT);

    bool sucesso = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);
    return sucesso;
}

bool MDProjeto::desassociarHistoriaPessoa(const Codigo& codigoHistoria, const Email& emailPessoa) {
    std::string sql = "UPDATE HISTORIA_DE_USUARIO SET email_desenvolvedor = NULL WHERE codigo = ? AND email_desenvolvedor = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return false;

    sqlite3_bind_text(stmt, 1, codigoHistoria.getCodigo().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, emailPessoa.getEmail().c_str(), -1, SQLITE_TRANSIENT);

    bool sucesso = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);
    return sucesso;
}

bool MDProjeto::listarProjetosPorPessoa(const Email& emailPessoa, std::vector<Codigo>& codigos) {
    std::string sql = "SELECT codigo FROM PROJETO WHERE email_scrum_master = ? OR email_product_owner = ?;";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return false;

    sqlite3_bind_text(stmt, 1, emailPessoa.getEmail().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, emailPessoa.getEmail().c_str(), -1, SQLITE_TRANSIENT);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Codigo c;
        c.setCodigo(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        codigos.push_back(c);
    }
    sqlite3_finalize(stmt);
    return true;
}

bool MDProjeto::listarHistoriasPorProjeto(const Codigo& codigoProjeto, std::vector<Codigo>& codigos) {
    std::string sql = "SELECT codigo FROM HISTORIA_DE_USUARIO WHERE codigo_projeto = ?;";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return false;

    sqlite3_bind_text(stmt, 1, codigoProjeto.getCodigo().c_str(), -1, SQLITE_TRANSIENT);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Codigo c;
        c.setCodigo(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        codigos.push_back(c);
    }
    sqlite3_finalize(stmt);
    return true;
}

bool MDProjeto::listarSprintsPorProjeto(const Codigo& codigoProjeto, std::vector<Codigo>& codigos) {
    std::string sql = "SELECT codigo FROM PLANO_DE_SPRINT WHERE codigo_projeto = ?;";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return false;

    sqlite3_bind_text(stmt, 1, codigoProjeto.getCodigo().c_str(), -1, SQLITE_TRANSIENT);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Codigo c;
        c.setCodigo(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        codigos.push_back(c);
    }
    sqlite3_finalize(stmt);
    return true;
}

bool MDProjeto::listarHistoriasPorSprint(const Codigo& codigoSprint, std::vector<Codigo>& codigos) {
    std::string sql = "SELECT codigo FROM HISTORIA_DE_USUARIO WHERE codigo_sprint = ?;";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return false;

    sqlite3_bind_text(stmt, 1, codigoSprint.getCodigo().c_str(), -1, SQLITE_TRANSIENT);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Codigo c;
        c.setCodigo(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        codigos.push_back(c);
    }
    sqlite3_finalize(stmt);
    return true;
}

bool MDProjeto::listarHistoriasPorPessoa(const Email& emailPessoa, std::vector<Codigo>& codigos) {
    std::string sql = "SELECT codigo FROM HISTORIA_DE_USUARIO WHERE email_desenvolvedor = ?;";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return false;

    sqlite3_bind_text(stmt, 1, emailPessoa.getEmail().c_str(), -1, SQLITE_TRANSIENT);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Codigo c;
        c.setCodigo(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        codigos.push_back(c);
    }
    sqlite3_finalize(stmt);
    return true;
}

bool MDProjeto::moverHistoriaParaSprint(const Codigo& codigoHistoria, const Codigo& codigoSprint) {
    // Apenas atualiza a chave estrangeira do sprint na tabela de histórias
    std::string sql = "UPDATE HISTORIA_DE_USUARIO SET codigo_sprint = ? WHERE codigo = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return false;

    sqlite3_bind_text(stmt, 1, codigoSprint.getCodigo().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, codigoHistoria.getCodigo().c_str(), -1, SQLITE_TRANSIENT);

    bool sucesso = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);
    return sucesso;
}

bool MDProjeto::alterarEstadoHistoria(const Codigo& codigoHistoria, const Estado& novoEstado) {
    std::string sql = "UPDATE HISTORIA_DE_USUARIO SET estado = ? WHERE codigo = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return false;

    sqlite3_bind_text(stmt, 1, novoEstado.getEstado().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, codigoHistoria.getCodigo().c_str(), -1, SQLITE_TRANSIENT);

    bool sucesso = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);
    return sucesso;
}
