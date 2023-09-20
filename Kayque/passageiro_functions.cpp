#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <iomanip>

using namespace std; // Usando o namespace std

// Constante para o número máximo de passageiros
const int MAX_PASSAGEIROS = 40;

// Estrutura para armazenar informações do Passageiro
struct Passageiro {
    string cpf;
    string nome;
    string data_nascimento;
    string numero_autorizacao;
};

bool ValidarCPF(const string& cpf) {
    // Verificar se o CPF tem exatamente 11 dígitos
    if (cpf.length() != 11) {
        return false;
    }

    // Verificar se todos os caracteres são dígitos
    if (!regex_match(cpf, regex("\\d{11}"))) {
        return false;
    }

    return true;
}

bool ValidarDataNascimento(const string& data) {
    // Neste exemplo, vamos verificar se a data tem o formato DD/MM/AAAA
    regex dataRegex("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/[0-9]{4}$");
    return regex_match(data, dataRegex);
}

bool IncluirPassageiro(vector<Passageiro>& passageiros, const string& nome, const string& cpf, const string& data_nascimento, const string& numero_autorizacao) {
    if (passageiros.size() >= MAX_PASSAGEIROS) {
        cout << "Limite de passageiros atingido." << endl;
        return false;
    }

    for (const Passageiro& passageiro : passageiros) {
        if (passageiro.cpf == cpf || passageiro.nome == nome) {
            cout << "Passageiro com o mesmo CPF ou nome já existe.\n" << endl;
            return false;
        }
    }

    if (!ValidarCPF(cpf)) {
        cout << "CPF inválido.\n" << endl;
        cout << "Passageiro não incluído!\n" << endl;
        return false;
    }

    if (!ValidarDataNascimento(data_nascimento)) {
        cout << "Data de nascimento inválida.\n" << endl;
        cout << "Passageiro não incluído!\n" << endl;
        return false;
    }

    Passageiro novoPassageiro;
    novoPassageiro.nome = nome;
    novoPassageiro.cpf = cpf;
    novoPassageiro.data_nascimento = data_nascimento;
    novoPassageiro.numero_autorizacao = numero_autorizacao;

    passageiros.push_back(novoPassageiro);

    cout << "Passageiro inserido com sucesso!\n" << endl;
    return true;
}

bool ExcluirPassageiro(vector<Passageiro>& passageiros, const string& cpf) {
    for (auto it = passageiros.begin(); it != passageiros.end(); ++it) {
        if (it->cpf == cpf) {
            passageiros.erase(it);
            cout << "Passageiro excluído com sucesso!" << endl;
            return true;
        }
    }

    cout << "Passageiro não encontrado." << endl;
    return false;
}

bool AlterarDadosPassageiro(vector<Passageiro>& passageiros, const string& cpf, const string& novoNome, const string& novaDataNascimento, const string& novoNumeroAutorizacao) {
    for (Passageiro& passageiro : passageiros) {
        if (passageiro.cpf == cpf) {
            if (!ValidarDataNascimento(novaDataNascimento)) {
                cout << "Data de nascimento inválida.\n" << endl;
                return false;
            }

            passageiro.nome = novoNome;
            passageiro.data_nascimento = novaDataNascimento;
            passageiro.numero_autorizacao = novoNumeroAutorizacao;

            cout << "Dados do passageiro alterados com sucesso!" << endl;
            return true;
        }
    }

    cout << "Passageiro não encontrado." << endl;
    return false;
}

void ListarPassageiros(const vector<Passageiro>& passageiros) {
    cout << "\nLista de passageiros:" << endl;
    for (const Passageiro& passageiro : passageiros) {
        cout << "CPF: " << passageiro.cpf << ", Nome: " << passageiro.nome << ", Data de nascimento: " << passageiro.data_nascimento << ", Número de autorização: " << passageiro.numero_autorizacao << endl;
    }
}

void LocalizarPassageiro(const vector<Passageiro>& passageiros, const string& cpf) {
    for (const Passageiro& passageiro : passageiros) {
        if (passageiro.cpf == cpf) {
            cout << "O nome do passageiro é: " << passageiro.nome << endl;
            return;
        }
    }

    cout << "Passageiro não encontrado." << endl;
}
