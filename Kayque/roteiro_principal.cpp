#include <iostream>
#include <vector>
#include "roteiro_functions.cpp" // Inclua o arquivo de funções

int main() {
    vector<Roteiro> roteiros;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Incluir roteiro" << endl;
        cout << "2. Excluir roteiro" << endl;
        cout << "3. Alterar dados do roteiro" << endl;
        cout << "4. Listar roteiros" << endl;
        cout << "5. Localizar roteiro por código" << endl;
        cout << "0. Sair";
        cout << "Escolha uma opção: ";

        int opcao;
        cin >> opcao;

        if (opcao == 0) {
            break;
        }

        switch (opcao) {
            case 1: {
                string codigo, data_hora_prevista, duracao_prevista, origem, destino;

                cout << "\nDigite o código do roteiro: ";
                // Limpa o buffer de entrada
                cin.ignore();
                getline(cin, codigo);
                cout << "Digite a data e hora previstas (DD/MM/AAAA HH:MM): ";
                getline(cin, data_hora_prevista);
                cout << "Digite a duração prevista: ";
                getline(cin, duracao_prevista);
                cout << "Digite a origem: ";
                getline(cin, origem);
                cout << "Digite o destino: ";
                getline(cin, destino);

                IncluirRoteiro(roteiros, codigo, data_hora_prevista, duracao_prevista, origem, destino);
                break;
            }
            case 2: {
                string codigo;
                cout << "\nDigite o código do roteiro a ser excluído: ";
                cin.ignore();
                getline(cin, codigo);

                ExcluirRoteiro(roteiros, codigo);
                break;
            }
            case 3: {
                string codigo;
                cout << "\nDigite o código do roteiro para alterar os dados: ";
                cin.ignore();
                getline(cin, codigo);

                string novaDataHoraPrevista, novaDuracaoPrevista, novaOrigem, novoDestino;
                cout << "Digite a nova data e hora previstas (DD/MM/AAAA HH:MM): ";
                getline(cin, novaDataHoraPrevista);
                cout << "Digite a nova duração prevista: ";
                getline(cin, novaDuracaoPrevista);
                cout << "Digite a nova origem: ";
                getline(cin, novaOrigem);
                cout << "Digite o novo destino: ";
                getline(cin, novoDestino);

                AlterarDadosRoteiro(roteiros, codigo, novaDataHoraPrevista, novaDuracaoPrevista, novaOrigem, novoDestino);
                break;
            }
            case 4: {
                ListarRoteiros(roteiros);
                break;
            }
            case 5: {
                string codigo;
                cout << "\nDigite o código do roteiro para localizá-lo: ";
                cin.ignore();
                getline(cin, codigo);

                LocalizarRoteiro(roteiros, codigo);
                break;
            }
            default:
                cout << "Opção inválida." << endl;
        }
    }

    return 0;
}
