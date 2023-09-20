#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <iomanip>
#include "passageiro_functions.cpp" 
#include "roteiro_functions.cpp"

using namespace std;

int main() {

    vector<Passageiro> passageiros;
    vector<Roteiro> roteiros;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Gestão de Passageiros" << endl;
        cout << "2. Gestão de Roteiros" << endl;
        cout << "3. Gestão de embarques" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";

        int opcao;
        cin >> opcao;

        if (opcao == 0) {
            break;
        }

        switch (opcao) {
            case 1: {

                while (true) {
                    cout << "\nMenu:" << endl;
                    cout << "1. Incluir passageiro" << endl;
                    cout << "2. Excluir passageiro" << endl;
                    cout << "3. Alterar dados do passageiro" << endl;
                    cout << "4. Listar passageiros" << endl;
                    cout << "5. Localizar passageiro por CPF" << endl;
                    cout << "0. Voltar ao menu anterior" << endl;
                    cout << "Escolha uma opção: ";

                    int opcao;
                    cin >> opcao;

                    if (opcao == 0) {
                        break;
                    }

                    switch (opcao) {
                        case 1: {
                            string nome, cpf, data_nascimento, numero_autorizacao;

                            cout << "\nDigite o nome do passageiro: ";
                            cin.ignore();
                            getline(cin, nome);
                            cout << "Digite o CPF do passageiro: ";
                            cin >> cpf;
                            cout << "Digite a data de nascimento (01/01/2001): ";
                            cin >> data_nascimento;
                            cout << "Digite o número de autorização: ";
                            cin >> numero_autorizacao;

                            IncluirPassageiro(passageiros, nome, cpf, data_nascimento, numero_autorizacao);
                            break;
                        }
                        case 2: {
                            string cpf;
                            cout << "\nDigite o CPF do passageiro a ser excluído: ";
                            cin >> cpf;

                            ExcluirPassageiro(passageiros, cpf);
                            break;
                        }
                        case 3: {
                            string cpf;
                            cout << "Digite o CPF do passageiro para alterar os dados: ";
                            cin >> cpf;

                            string novoNome, novaDataNascimento, novoNumeroAutorizacao;
                            cout << "Digite o novo nome: ";
                            cin.ignore();
                            getline(cin, novoNome);
                            cout << "Digite a nova data de nascimento (01/01/2001): ";
                            cin >> novaDataNascimento;
                            cout << "Digite o novo número de autorização: ";
                            cin >> novoNumeroAutorizacao;

                            AlterarDadosPassageiro(passageiros, cpf, novoNome, novaDataNascimento, novoNumeroAutorizacao);
                            break;
                        }
                        case 4: {
                            ListarPassageiros(passageiros);
                            break;
                        }
                        case 5: {
                            string cpf;
                            cout << "\nDigite o CPF do passageiro para localizá-lo: ";
                            cin >> cpf;

                            LocalizarPassageiro(passageiros, cpf);
                            break;
                        }
                        default:
                            cout << "Opção inválida." << endl;
                    }
                            
                            break;
                }
            }
            case 2: {

                while (true) {
                    cout << "\nMenu:" << endl;
                    cout << "1. Incluir roteiro" << endl;
                    cout << "2. Excluir roteiro" << endl;
                    cout << "3. Alterar dados do roteiro" << endl;
                    cout << "4. Listar roteiros" << endl;
                    cout << "5. Localizar roteiro por código" << endl;
                    cout << "0. Voltar ao menu anterior";
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

                break;
                
            }
            case 3: {
                
                break;
            }
            default:
                cout << "Opção inválida." << endl;
        }
    }

    return 0;
}
