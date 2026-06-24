#include "md_pessoa.hpp"
#include <iostream>

MDPessoa::MDPessoa() {
    if (sqlite3_open(dbName.c_str(), &db) == SQLITE_OK) {
        inicializarBanco();
    } else {
        std::cerr << "Erro ao abrir o banco de dados: " << sqlite3_errmsg(db) << std::endl;
    }
}

MDPessoa::~MDPessoa() {
    if (db) {
        sqlite3_close(db);
    }
}

void MDPessoa::inicializarBanco() {
    std::string sql =
        "CREATE TABLE IF NOT EXISTS PESSOA ("
        "email TEXT PRIMARY KEY, "
        "nome TEXT NOT NULL, "
        "senha TEXT NOT NULL, "
        "papel TEXT NOT NULL);";

    char* mensagemErro = nullptr;
    int resultado = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &mensagemErro);

    if (resultado != SQLITE_OK) {
        std::cerr << "Erro na criação da tabela PESSOA: " << mensagemErro << std::endl;
        sqlite3_free(mensagemErro);
    }
}

bool MDPessoa::cadastrar(const Pessoa& pessoa) {
    std::string sql = "INSERT INTO PESSOA (email, nome, senha, papel) VALUES (?, ?, ?, ?);";
    sqlite3_stmt* stmt;

    // Prepara a instrução SQL
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        return false;
    }

    // Faz o "bind" dos valores da entidade para as interrogações (?)
    sqlite3_bind_text(stmt, 1, pessoa.getEmail().getEmail().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, pessoa.getNome().getNome().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, pessoa.getSenha().getSenha().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, pessoa.getPapel().getPapel().c_str(), -1, SQLITE_TRANSIENT);

    // Executa
    bool sucesso = (sqlite3_step(stmt) == SQLITE_DONE);

    // Finaliza o statement para liberar memória
    sqlite3_finalize(stmt);
    return sucesso;
}

bool MDPessoa::ler(const Email& email, Pessoa& pessoa) {
    std::string sql = "SELECT nome, senha, papel FROM PESSOA WHERE email = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_text(stmt, 1, email.getEmail().c_str(), -1, SQLITE_TRANSIENT);

    bool encontrado = false;

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string strNome = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::string strSenha = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string strPapel = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));

        Nome nome; nome.setNome(strNome);
        Senha senha; senha.setSenha(strSenha);
        Papel papel; papel.setPapel(strPapel);

        pessoa.setNome(nome);
        pessoa.setEmail(email);
        pessoa.setSenha(senha);
        pessoa.setPapel(papel);

        encontrado = true;
    }

    sqlite3_finalize(stmt);
    return encontrado;
}

bool MDPessoa::atualizar(const Pessoa& pessoa) {
    std::string sql = "UPDATE PESSOA SET nome = ?, senha = ?, papel = ? WHERE email = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_text(stmt, 1, pessoa.getNome().getNome().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, pessoa.getSenha().getSenha().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, pessoa.getPapel().getPapel().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, pessoa.getEmail().getEmail().c_str(), -1, SQLITE_TRANSIENT);

    bool sucesso = (sqlite3_step(stmt) == SQLITE_DONE);

    sqlite3_finalize(stmt);
    return sucesso;
}

bool MDPessoa::excluir(const Email& email) {
    std::string sql = "DELETE FROM PESSOA WHERE email = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_text(stmt, 1, email.getEmail().c_str(), -1, SQLITE_TRANSIENT);

    bool sucesso = (sqlite3_step(stmt) == SQLITE_DONE);

    sqlite3_finalize(stmt);
    return sucesso;
}
