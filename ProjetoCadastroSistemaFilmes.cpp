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
    cout << "Insira aqui o nome do filme: ";
    getline(cin, novoFilme.nome);
    cout << "Insira aqui o gênero do filme: ";
    getline(cin, novoFilme.genero);
    cout << "Insira aqui sua avaliação: ";
    getline(cin, novoFilme.avaliacao);
    listaFilmes.push_back(novoFilme);
    cout << "Boa cinéfilo! Seu  filme foi cadastrado com sucesso em nosso sistema" << endl;
}

void exibirLista() {
    if (listaFilmes.empty()) {
        cout << "Parece que não há nada aqui... Por que não tenta adicionar um novo filme à sua lista?" << endl;
        return;
    }
    cout << "Aqui está sua lista completa de filmes cadastrados:" << endl;
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
        cout << "\nMenu de opcões para " << nomeUsuario << ":" << endl;
        cout << "1. Cadastrar um novo filme" << endl;
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
                cout << "Encerrando o sistema... Vemos você na próxima, " << nomeUsuario << "!" << endl;
                break;
            default:
                cout << "Infelizmente não temos essa opção no sistema. Tente novamente com uma das opções disponíveis acima." << endl;
                break;
        }
    } while (opcao != 3);

    return 0;
}