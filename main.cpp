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
    char uf[3];
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

    for(int i = 0; i < tamanho; i++) {
        for(int j = 0; j < tamanho-1; j++) {
        struct indices aux;
        if(indice[j].codigo < indice[j + 1].codigo) {
            aux = indice[j];
            indice[j] = indice[j + 1];
            indice[j + 1] = aux;
      }
    }
  }
}

bool incluirGuiasBuscaCodigo(){
    int i = 0, f = cont, m = (i+f)/2;
    for(int i = 0, f = 0, m = (i+f)/2){

    }
}

void incluirGuias(){
    cout << "\n\t\tFuncao para incluir na tabela Guias" << endl;

    for(int saida = 1, i = 0; saida != 0, i < tamanho, i++){
        cout << "\n\tCodigo: ";
        cin >> vetGuia[i].codigo;

        cout << "\n\tNome: ";
        cin >> vetGuia[i].nome;
        cout << "\n\tEndereco: ";
        cin >> vetGuia[i].endereco;
        cout << "\n\tTelefone: ";
        cin >> vetGuia[i].telefone;
        cout << "Codigo da Cidade: ";
        cin >> vetGuia[i].codigoCidade;

        cout << "\n\tDeseja continuar inserindo?(1/0): ";
        cin >> saida;
    }
}

//fun��es ler

void lerPaises(int tamanho, int cont, struct paises vetPaises[], struct indices indice[]){
    cout << "\n\t\tFuncao para leitura de paises" << endl;
    for(int i = 0, saida = 1; i < tamanho && saida != 0; i++, cont++){
        cout << "\n\tPais " << i << endl;
        cout << "\n\tCodigo: ";
        cin >> vetPaises[i].codigo;
        while(vetPaises[i].codigo <= 0){
            cout << "\n\tDigite um codigo valido: ";
            cin >> vetPaises[i].codigo;
        }
        indice[i].codigo = vetPaises[i].codigo;
        indice[i].ender = i;
        cout << "\tNome: ";
        cin >> vetPaises[i].nome;

        cout << "\n\tDeseja continuar?(1/0): ";
        cin >> saida;
    }
    organizaIndice(indice, tamanho);
}

void lerCidades(int tamanho, int &cont,struct cidades vetCidade[], struct indices indice[]){
    cout << "\n\t\tFuncao para leitura de Cidades" << endl;
    for(int i = 0, saida = 1; i < tamanho && saida != 0; i++, cont++){
        cout << "\n\tCidade " << i << endl;
        cout << "Codigo: ";
        cin >> vetCidade[i].codigo;
        while(vetCidade[i].codigo <= 0){
            cout << "\n\tDigite um codigo valido: ";
            cin >> vetCidade[i].codigo;
        }
        indice[i].codigo = vetCidade[i].codigo;
        indice[i].ender = i;
        cout << "\tNome: ";
        cin >> vetCidade[i].nome;
        cout << "\tEndereco: ";
        cin >> vetCidade[i].uf;
        cout << "\tCodigo do pais: ";
        cin >> vetCidade[i].codigoPais;

        cout << "\n\tDeseja continuar?(1/0): ";
        cin >> saida;
    }
    organizaIndice(indice, tamanho);
}

//fun��es de impress�o

void imprimirPaises(int tamanho, int &cont, struct indices indice[], struct paises vetPaises[]){
    cout << "\n\t\tFuncao para impressao da lista de Paises" << endl;

    for(int i=0; i < cont ; i++){
        cout << "\n\tPais " << i << endl;
        cout << "\tCodigo: " << vetPaises[indice[i].ender].codigo << endl;
        cout << "\tNome: " << vetPaises[indice[i].ender].nome << endl;
    }
}

void imprimirCidades(int tamanho, int cont, struct indices indice[], struct cidades vetCidades[]){
    cout << "\n\t\tFuncao para impressao da lista de Cidades" << endl;

    for(int i=0; i < cont ; i++){
        cout << "\n\tCidades " << i << endl;
        cout << "\tCodigo: " << vetCidades[indice[i].ender].codigo << endl;
        cout << "\tNome: " << vetCidades[indice[i].ender].nome << endl;
        cout << "\tUF: " << vetCidades[indice[i].ender].uf << endl;
        cout << "\tCodigo do Pais: " << vetCidades[indice[i].ender].codigoPais << endl;
    }
}


int main()
{
    //inicializa��o do tamanho

    const int tamanho = 20;


    //inicializa��o dos vetores

    struct paises vetPaises[tamanho] = { {1, "Brasil"}, {2, "Argentina"}, {3, "Chile"}};
    struct cidades vetCidades[tamanho] = { {1, "Assis", "SP", 1}, {2, "Buenos aires", "AA", 2}, {3, "sao paulo", "SP", 1}, {1, "maracai", "SA", 3}, {2, "candido mota", "DA", 2} };


    //inicializa��o dos indices

    struct indices indicePaises[tamanho];
    struct indices indiceCidades[tamanho];


    //inicializa��o dos contadores

    int contPaises = 3, contCidades = 5;


    int menu = 1;
    int decisao;

    while(menu != 0){
        cout << "\n\t\tDigite a funcao que deseja: " << endl;
        cout << "\n\t[1] Ler Paises" << endl;
        cout << "\t[2] Ler Cidades" << endl;
        cout << "\t[3] Imprimir Paises" << endl;
        cout << "\t[4] Imprimir Cidades" << endl;
        cout << "\t[5] Incluir Guias" << endl;
        cout << "\t[6] Imprimir Guias" << endl;

        cout << "\n";
        cin >> decisao;

        switch(decisao){
        case 1:
            lerPaises(tamanho, contPaises, vetPaises, indicePaises);
            break;
        case 2:
            lerCidades(tamanho, contCidades, vetCidades, indiceCidades);
            break;
        case 3:
            imprimirPaises(tamanho, contPaises, indicePaises, vetPaises);
            break;
        case 4:
            imprimirCidades(tamanho, contCidades, indiceCidades, vetCidades);
            break;
        case 5:
            incluirGuias();
        }




       cout << "\n\t\tDeseja continuar no programa?(1/0): ";
       cin >> menu;
    }
    return 0;
}
