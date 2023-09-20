#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <iomanip>
#include "passageiro_functions.cpp"

int main() {
    vector<Passageiro> passageiros;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Incluir passageiro" << endl;
        cout << "2. Excluir passageiro" << endl;
        cout << "3. Alterar dados do passageiro" << endl;
        cout << "4. Listar passageiros" << endl;
        cout << "5. Localizar passageiro por CPF" << endl;
        cout << "0. Sair" << endl;
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
    }

    return 0;
}
