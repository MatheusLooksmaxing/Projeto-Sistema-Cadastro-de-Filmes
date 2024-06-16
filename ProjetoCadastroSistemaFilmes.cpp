#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Filme {
    string nome;
    string genero;
    string avaliacao;
};

vector<Filme> listaFilmes;

void cadastrarFilme() {
    Filme novoFilme;
    cout << "Digite o nome do filme: ";
    getline(cin, novoFilme.nome);
    cout << "Digite o gênero do filme: ";
    getline(cin, novoFilme.genero);
    cout << "Digite sua avaliação: ";
    getline(cin, novoFilme.avaliacao);
    listaFilmes.push_back(novoFilme);
    cout << "Filme cadastrado com sucesso!" << endl;
}

void exibirLista() {
    if (listaFilmes.empty()) {
        cout << "Nenhum filme cadastrado." << endl;
        return;
    }
    cout << "Lista de filmes cadastrados:" << endl;
    for (const auto& filme : listaFilmes) {
        cout << "° Filme: " << filme.nome << endl << "° Gênero: " << filme.genero << endl << "° Avaliação: " << filme.avaliacao << endl << endl;
    }
}

int main() {
    string nomeUsuario;
    cout << "Bem-vindo ao sistema de cadastro de filmes!" << endl;
    cout << "Por favor, insira seu nome: ";
    getline(cin, nomeUsuario);

    int opcao;
    string buffer;
    do {
        cout << "\nMenu de opcoes para " << nomeUsuario << ":" << endl;
        cout << "1. Cadastrar novo filme" << endl;
        cout << "2. Exibir lista de filmes cadastrados" << endl;
        cout << "3. Sair do sistema" << endl;
        cout << "Escolha uma opcão: ";
        cin >> opcao;
        getline(cin, buffer);

        switch (opcao) {
            case 1:
                cadastrarFilme();
                break;
            case 2:
                exibirLista();
                break;
            case 3:
                cout << "Saindo do sistema. Até mais, " << nomeUsuario << "!" << endl;
                break;
            default:
                cout << "Opcão inválida. Tente novamente." << endl;
                break;
        }
    } while (opcao != 3);

    return 0;
}