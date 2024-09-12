#include <iostream>

using namespace std;

struct paises{
    int codigo;
    string nome;
};

struct indices{
    int codigo;
    int ender;
};

struct cidades{
    int codigo;
    string nome;
    char uf[2];
    int codigoPais;
};

struct guias{
    int codigo;
    string nome;
    string endereco;
    string telefone;
    int codigoCidade;
};

struct clientes{
    int codigo;
    string nome;
    string endereco;
    int codigoCidade;
};


struct pacotes{
    int codigo;
    string descricao;
    int codigoGuia;
    float valorPessoa;
    int totalParticipantes;
    int quantMaxPartipantes;
};


struct vendas{
    int codigo;
    int codigoCliente;
    int codigoPacote;
    int quantidadePessoas;
    float valorTotal;
};

void organizaIndice(struct indices indice[], int tamanho){
    for(i = 0; i < tamanho; i++) {
        for(j = 0; j < tamanho-1; j++) {
          if(indice[j] < indice[j + 1]) {
            aux = indice[j];
            indice[j] = indice[j + 1];
            indice[j + 1] = aux;
      }
    }
  }
}

void lerPaises(int tamanho, struct paises vetPaises[], struct indices indice[]){
    cout << "\n\t\tFuncao para leitura de paises" << endl;
    for(int i = 0, saida = 1; i < tamanho && saida != 0; i++){
        cout << "\n\tPais " << i << endl;
        cout << "Codigo: ";
        cin >> vetPaises[i]codigo;
        while(vetPaises[i].codigo <= 0){
            cout << "\n\tDigite um codigo valido: ";
            cin >> vetPaises[i]codigo;
        }
        indice[i].codigo = vetPaises[i].codigo;
        indice[i].ender = i
        cout << "\tNome: ";
        cin >> vetPaises[i].nome;

        cout << "\n\tDeseja continuar?(1/0): ";
        cin >> saida;
    }
    organizaIndice(indicePais, tamanho);
}

void lerCidades(int tamanho, struct cidades vetCidade[], struct indices indice[]){
    cout << "\n\t\tFuncao para leitura de Cidades" << endl;
    for(int i = 0, saida = 1; i < tamanho && saida != 0; i++){
        cout << "\n\tCidade " << i << endl;
        cout << "Codigo: ";
        cin >> vetCidade[i]codigo;
        while(vetCidade[i].codigo <= 0){
            cout << "\n\tDigite um codigo valido: ";
            cin >> vetCidade[i]codigo;
        }
        indice[i].codigo = vetCidade[i].codigo;
        indice[i].ender = i
        cout << "\tNome: ";
        cin >> vetCidade[i].nome;
        cout << "\tEndereco: ";
        cin >> vetCidade[i].endereco;
        cout << "\tCodigo do pais: ";
        cin >> vetCidade[i].codigoPais;

        cout << "\n\tDeseja continuar?(1/0): ";
        cin >> saida;
    }
    organizaIndice(indiceCidades, tamanho);
}

int main()
{
    bool menu = true;

    while(menu==true){





       cout << "\n\t\tDeseja continuar no programa?(1/0): ";
       cin >> menu;
    }
    return 0;
}
