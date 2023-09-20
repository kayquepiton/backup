#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Constante para o número máximo de roteiros
const int MAX_ROTEIROS = 10;

// Estrutura para armazenar informações do Roteiro
struct Roteiro {
    string codigo;
    string data_hora_prevista;
    string duracao_prevista;
    string origem;
    string destino;
};

bool ValidarCodigo(const string& codigo) {
    // Verificar se o código tem pelo menos 3 caracteres
    if (codigo.length() < 3) {
        return false;
    }

    return true;
}

bool ValidarDataHora(const string& data_hora) {
    // Neste exemplo, vamos verificar se a data e hora têm o formato DD/MM/AAAA HH:MM
    regex dataHoraRegex("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/[0-9]{4} [0-1][0-9]:[0-5][0-9]$");
    return regex_match(data_hora, dataHoraRegex);
}

// Função para incluir um roteiro
bool IncluirRoteiro(vector<Roteiro>& roteiros, string codigo, string data_hora_prevista, string duracao_prevista, string origem, string destino) {
    if (roteiros.size() >= MAX_ROTEIROS) {
        cout << "Limite de roteiros atingido." << endl;
        return false;
    }

    for (const Roteiro& roteiro : roteiros) {
        if (roteiro.codigo == codigo) {
            cout << "Roteiro com o mesmo código já existe.\n" << endl;
            return false;
        }
    }

    if (!ValidarCodigo(codigo)) {
        cout << "Código inválido.\n" << endl;
        cout << "Roteiro não incluído!\n" << endl;
        return false;
    }

    if (!ValidarDataHora(data_hora_prevista)) {
        cout << "Data e hora previstas inválidas.\n" << endl;
        cout << "Roteiro não incluído!\n" << endl;
        return false;
    }

    Roteiro novoRoteiro;
    novoRoteiro.codigo = codigo;
    novoRoteiro.data_hora_prevista = data_hora_prevista;
    novoRoteiro.duracao_prevista = duracao_prevista;
    novoRoteiro.origem = origem;
    novoRoteiro.destino = destino;

    roteiros.push_back(novoRoteiro);

    cout << "Roteiro inserido com sucesso!\n" << endl;
    return true;
}

// Função para excluir um roteiro
bool ExcluirRoteiro(vector<Roteiro>& roteiros, const string& codigo) {
    for (auto it = roteiros.begin(); it != roteiros.end(); ++it) {
        if (it->codigo == codigo) {
            roteiros.erase(it);
            cout << "Roteiro excluído com sucesso!" << endl;
            return true;
        }
    }

    cout << "Roteiro não encontrado." << endl;
    return false;
}

// Função para alterar dados de um roteiro
bool AlterarDadosRoteiro(vector<Roteiro>& roteiros, const string& codigo, string novaDataHoraPrevista, string novaDuracaoPrevista, string novaOrigem, string novoDestino) {
    for (Roteiro& roteiro : roteiros) {
        if (roteiro.codigo == codigo) {
            if (!ValidarDataHora(novaDataHoraPrevista)) {
                cout << "Data e hora previstas inválidas.\n" << endl;
                return false;
            }

            roteiro.data_hora_prevista = novaDataHoraPrevista;
            roteiro.duracao_prevista = novaDuracaoPrevista;
            roteiro.origem = novaOrigem;
            roteiro.destino = novoDestino;

            cout << "Dados do roteiro alterados com sucesso!" << endl;
            return true;
        }
    }

    cout << "Roteiro não encontrado." << endl;
    return false;
}

// Função para listar todos os roteiros
void ListarRoteiros(const vector<Roteiro>& roteiros) {
    cout << "\nLista de roteiros:" << endl;
    for (const Roteiro& roteiro : roteiros) {
        cout << "Código: " << roteiro.codigo << ", Data e hora previstas: " << roteiro.data_hora_prevista
             << ", Duração prevista: " << roteiro.duracao_prevista << ", Origem: " << roteiro.origem
             << ", Destino: " << roteiro.destino << endl;
    }
}

// Função para localizar o roteiro por código
void LocalizarRoteiro(const vector<Roteiro>& roteiros, const string& codigo) {
    for (const Roteiro& roteiro : roteiros) {
        if (roteiro.codigo == codigo) {
            cout << "Origem do roteiro: " << roteiro.origem << ", Destino do roteiro: " << roteiro.destino << endl;
            return;
        }
    }

    cout << "Roteiro não encontrado." << endl;
}
