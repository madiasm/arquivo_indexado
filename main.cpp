#include <iostream>
#include <stdlib.h>

using namespace std;

struct paises{
    int codigo;
    string nome;
};

struct indices{
    int codigo;
    int ender;
};

struct indicesVendas{
    int codigo;
    int enderVenda;
    int codigoCliente;
    int enderCliente;
};

struct indicesPacotes{
    int codigo;
    int enderPacote;
    int codigoGuia;
    int enderGuia;
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
    int status;
};

struct clientes{
    int codigo;
    string nome;
    string endereco;
    int codigoCidade;
    int status;
};


struct pacotes{
    int codigo;
    string descricao;
    int codigoGuia;
    float valorPessoa;
    int totalParticipantes;
    int quantMaxParticipantes;
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

bool incluirGuiasBuscaCodigo(struct indices indice[], int cont, int busca){
    int i = 0, f = cont, m = (i+f)/2;
    for(int saida = 1; saida != 0 && f >= i; m = (i+f)/2){
        if(indice[m].codigo > busca){
            f = m - 1;
        }else{
            i = m + 1;
        }
    }
    if(indice[m].codigo == busca){
            return true;
        }else return false;
}

void buscaCidadePais(int contPais, struct indices indice[], int busca, struct paises vetPaises[]){
    int i = 0, f = contPais, m = (i+f)/2;
    for(int saida = 1; saida != 0 && f >= i; m = (i+f)/2){
        if(indice[m].codigo > busca){
            f = m - 1;
        }else{
            i = m + 1;
        }
    }
    if(indice[m].codigo == busca){
            cout << " - " << vetPaises[indice[m].ender].nome << endl;
        }
}

bool incluirGuiasBuscaCidade(int tamanho, struct cidades vetCidades[], struct paises vetPaises[], struct indices indice[], int &contCidade, int &contPaises, int busca, struct indices indicePaises[]){
    int i = 0, f = contCidade, m = (i+f)/2;
    for(int saida = 1; saida != 0 && f >= i; m = (i+f)/2){
        if(indice[m].codigo > busca){
            f = m - 1;
        }else{
            i = m + 1;
        }
    }
    if(indice[m].codigo == busca){
            cout << "\tCidade: " << vetCidades[indice[m].ender].nome << " - " << vetCidades[indice[m].ender].uf;
            buscaCidadePais(contPaises, indicePaises, vetCidades[indice[m].ender].codigo, vetPaises);
            return true;
        }else return false;
}

void incluirGuias(int tamanho, struct guias vetGuias[], int &cont, struct indices indiceGuias[], struct cidades vetCidades[], struct paises vetPaises[], struct indices indiceCidade[], int &contCidades,
                  int &contPaises, struct indices indicePaises[]){
    cout << "\n\t\tFuncao para incluir na tabela Guias" << endl;

    for(int saida = 1, i = 0; saida != 0 && i < tamanho; i++){
        cout << "\n\tCodigo: ";
        cin >> vetGuias[i].codigo;
        if(incluirGuiasBuscaCodigo(indiceGuias, cont, vetGuias[i].codigo) == true){
            while(incluirGuiasBuscaCodigo(indiceGuias, cont, vetGuias[i].codigo) == true){
            cout << "\tDigite um outro, esse ja existe: ";
            cin >> vetGuias[i].codigo;
            }
        }
        indiceGuias[cont].codigo = vetGuias[i].codigo;
        indiceGuias[cont].ender = i;
        cout << "\n\tNome: ";
        cin >> vetGuias[i].nome;
        cout << "\tEndereco: ";
        cin >> vetGuias[i].endereco;
        cout << "\tTelefone: ";
        cin >> vetGuias[i].telefone;
        cout << "\tCodigo da Cidade: ";
        cin >> vetGuias[i].codigoCidade;
        if(incluirGuiasBuscaCidade(tamanho, vetCidades, vetPaises, indiceGuias, contCidades, contPaises, vetGuias[i].codigoCidade, indicePaises) == false){
            while(incluirGuiasBuscaCidade(tamanho, vetCidades, vetPaises, indiceGuias, contCidades, contPaises, vetGuias[i].codigoCidade, indicePaises) == false){
                cout << "\tDigite um outro, esse nao existe: ";
                cin >> vetGuias[i].codigoCidade;
            }
        }

        cout << "\tDeseja continuar inserindo?(1/0): ";
        cin >> saida;
        cont++;
        }
        organizaIndice(indiceGuias, tamanho);
    }






    bool incluirClientesBuscaCodigo(struct indices indice[], int cont, int busca){
    int i = 0, f = cont, m = (i+f)/2;
    for(int saida = 1; saida != 0 && f >= i; m = (i+f)/2){
        if(indice[m].codigo > busca){
            f = m - 1;
        }else{
            i = m + 1;
        }
    }
    if(indice[m].codigo == busca){
            return true;
        }else return false;
}



    void incluirClientes(int tamanho, struct clientes vetClientes[], int &contClientes, struct cidades vetCidades[], int contCidades, struct paises vetPaises[],
                          int contPaises, struct indices indiceClientes[], struct indices indicePaises[]) {
    cout << "\n\t\tFuncao para incluir novos clientes" << endl;

    for (int saida = 1, i = contClientes; saida != 0 && i < tamanho; i++) {
        cout << "\n\tCodigo do cliente: ";
        cin >> vetClientes[i].codigo;
        if(incluirClientesBuscaCodigo(indiceClientes, contClientes, vetClientes[i].codigo) == true){
            while(incluirClientesBuscaCodigo(indiceClientes, contClientes, vetClientes[i].codigo) == true){
            cout << "\tDigite um outro, esse ja existe: ";
            cin >> vetClientes[i].codigo;
            }
        }
        indiceClientes[contClientes].codigo = vetClientes[i].codigo;
        indiceClientes[contClientes].ender = i;
        cout << "\tNome: ";
        cin >> vetClientes[i].nome;
        cout << "\tEndereco: ";
        cin >> vetClientes[i].endereco;
        cout << "\tCodigo da cidade: ";
        cin >> vetClientes[i].codigoCidade;

        if(incluirGuiasBuscaCidade(tamanho, vetCidades, vetPaises, indiceClientes, contCidades, contPaises, vetClientes[i].codigoCidade, indicePaises) == false){
            while(incluirGuiasBuscaCidade(tamanho, vetCidades, vetPaises, indiceClientes, contCidades, contPaises, vetClientes[i].codigoCidade, indicePaises) == false){
                cout << "\tDigite um outro, esse nao existe: ";
                cin >> vetClientes[i].codigoCidade;
            }
        }

        cout << "\tDeseja continuar inserindo?(1/0): ";
        cin >> saida;
        contClientes++;
    }
    organizaIndice(indiceClientes, tamanho);
}






bool excluirBuscarGuia(int contPacotes, struct indicesPacotes indicePacotes[], int busca, struct pacotes vetPacotes[]){
    int i = 0, f = contPacotes, m = (i+f)/2;
    for(int saida = 1; saida != 0 && f >= i; m = (i+f)/2){
        if(indicePacotes[m].codigoGuia > busca){
            f = m - 1;
        }else{
            i = m + 1;
        }
    }
    if(indicePacotes[m].codigoGuia == busca){
            return true;
        }else return false;
}


bool excluirBuscarCliente(int contVendas, struct indicesVendas indiceVendas[], int busca, struct vendas vetVendas[]){
    int i = 0, f = contVendas, m = (i+f)/2;
    for(int saida = 1; saida != 0 && f >= i; m = (i+f)/2){
        if(indiceVendas[m].codigoCliente > busca){
            f = m - 1;
        }else{
            i = m + 1;
        }
    }
    if(vetVendas[indiceVendas[m].enderVenda].codigoCliente == busca){
            return true;
        }else return false;
}






void excluirClientes (struct indices indice[], struct clientes vetClientes[], int &cont, int cod, int contVendas, struct indicesVendas indiceVendas[],
                      struct vendas vetVendas[]){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != indice[m].codigo; m = (i + f) / 2){
        if (cod > indice[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    i = indice[m].ender;
    if(excluirBuscarCliente(contVendas, indiceVendas, vetClientes[m].codigo, vetVendas) == false){
    if (vetClientes[i].status == 0){
        vetClientes[i].status = 1;
        cout << "\tCliente excluido com sucesso !!";
        }else cout << "\tCliente nao cadastrado";
    }
}


void excluirGuias (struct indices indiceGuias[], struct guias vetGuias[], int &cont, int cod, int contPacotes, struct indicesPacotes indicePacotes[],
                   struct pacotes vetPacotes[]){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != indiceGuias[m].codigo; m = (i + f) / 2){
        if (cod > indiceGuias[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }

    i = indiceGuias[m].ender;
    if(excluirBuscarGuia(contPacotes, indicePacotes, vetGuias[m].codigo, vetPacotes) == false){
        if (vetGuias[i].status == 0){
            vetGuias[i].status = 1;
            cout << "\tGuia excluido com sucesso!!";
        }else cout << "\tGuia nao cadastrado";
    }
}






string buscaCidadeVenda(struct indices indice[], int cont, int busca, struct cidades vetCidades[]){
    int i = 0, f = cont, m = (i+f)/2;
    for(int saida = 1; saida != 0 && f >= i; m = (i+f)/2){
        if(indice[m].codigo > busca){
            f = m - 1;
        }else{
            i = m + 1;
        }
    }
    if(indice[m].codigo == busca){
            return vetCidades[i].nome;
        }else return "bug";
}


bool incluirVendasBuscaCodigo(struct indices indiceClientes[], int contCliente, int busca, struct cidades vetCidades[], struct clientes vetClientes[],
                              struct indices indiceCidades[], int contCidade){
    int i = 0, f = contCliente, m = (i+f)/2;
    for(int saida = 1; saida != 0 && f >= i; m = (i+f)/2){
        if(indiceClientes[m].codigo > busca){
            f = m - 1;
        }else{
            i = m + 1;
        }
    }
    if(indiceClientes[m].codigo == busca){
            cout << "\tNome: " << vetClientes[indiceClientes[m].ender].nome << " - " << buscaCidadeVenda(indiceCidades, contCidade,
                                vetClientes[indiceClientes[m].ender].codigo, vetCidades) << endl;
            return true;
        }else return false;
}


bool incluirVendasBuscaPacote(int contPacote, struct indicesPacotes indicePacotes[], int busca, struct pacotes vetPacotes[], struct guias vetGuias[]){
    int i = 0, f = contPacote, m = (i+f)/2;
    for(int saida = 1; saida != 0 && f >= i; m = (i+f)/2){
        if(indicePacotes[m].codigo > busca){
            f = m - 1;
        }else{
            i = m + 1;
        }
    }
    if(indicePacotes[m].codigo == busca){
            cout << "\tDescricao: " << vetPacotes[indicePacotes[m].enderPacote].descricao << endl;
            cout << "\tNome do Guia: " << vetGuias[indicePacotes[m].enderGuia].nome << endl;
            cout << "\tValor por pessoa: " << vetPacotes[indicePacotes[m].enderPacote].valorPessoa << endl;
            return true;
        }else return false;
}


bool incluirVendasBuscaQuantidade(int contPacote, struct indicesPacotes indicePacotes[], int busca, int quantiaPessoas, struct pacotes vetPacotes[]){
    int i = 0, f = contPacote, m = (i+f)/2;
    for(int saida = 1; saida != 0 && f >= i; m = (i+f)/2){
        if(indicePacotes[m].codigo > busca){
            f = m - 1;
        }else{
            i = m + 1;
        }
    }
    if(indicePacotes[m].codigo == busca){
            if(quantiaPessoas < vetPacotes[indicePacotes[m].enderPacote].quantMaxParticipantes){
                vetPacotes[indicePacotes[m].enderPacote].totalParticipantes += quantiaPessoas;
                return true;
            }else{
                cout << "\tQuantia de pessoas e maior do que o permitido, digite outra";
                return false;
            }
        }else{
            cout << "Codigo nao encontrado, digite outro: ";
            return false;
        }
}


float buscaValorPessoa(int contPacote, struct indicesPacotes indicePacotes[], int busca, struct pacotes vetPacotes[]){
    int i = 0, f = contPacote, m = (i+f)/2;
    for(int saida = 1; saida != 0 && f >= i; m = (i+f)/2){
        if(indicePacotes[m].codigo > busca){
            f = m - 1;
        }else{
            i = m + 1;
        }
    }
    if(indicePacotes[m].codigo == busca){
            return vetPacotes[indicePacotes[m].enderPacote].valorPessoa;
        }
}




void incluirVendas(int tamanho, int &contVendas, struct vendas vetVendas[], struct indicesVendas indiceVendas[], struct cidades vetCidades[],
                   struct clientes vetClientes[], struct indices indiceClientes[], int contClientes, int contCidade, int contPacote, struct indicesPacotes indicePacotes[],
                   struct pacotes vetPacotes[], struct guias vetGuias[]) {
    cout << "\n\t\tFuncao para incluir novas vendas" << endl;

    for (int saida = 1, i = contVendas; saida != 0 && i < tamanho; i++) {
        cout << "\n\tCodigo da venda: ";
        cin >> vetVendas[i].codigo;
        indiceVendas[contVendas].codigo = vetVendas[i].codigo;
        indiceVendas[contVendas].enderVenda = i;
        cout << "\tCodigo de Cliente: ";
        cin >> vetVendas[i].codigoCliente;
        incluirVendasBuscaCodigo(indiceClientes, contClientes, vetVendas[i].codigoCliente, vetCidades, vetClientes, indiceClientes, contCidade);
        cout << "\tCodigo de Pacote: ";
        cin >> vetVendas[i].codigoPacote;
        incluirVendasBuscaPacote(contPacote, indicePacotes, vetVendas[i].codigoPacote, vetPacotes, vetGuias);
        cout << "\tQuantia de pessoas: ";
        cin >> vetVendas[i].quantidadePessoas;
        while(incluirVendasBuscaQuantidade(contPacote, indicePacotes, vetVendas[i].codigo, vetVendas[i].quantidadePessoas, vetPacotes) == false){
            cin >> vetVendas[i].quantidadePessoas;
        }
        vetVendas[i].valorTotal = vetVendas[i].quantidadePessoas * buscaValorPessoa(contPacote, indicePacotes, vetVendas[i].codigoPacote, vetPacotes);
        cout << "\tValor Total: " << vetVendas[i].valorTotal << endl;
        cout << "\tDeseja continuar inserindo?(1/0): ";
        cin >> saida;
        contVendas++;
    }
}






void incluirPacotesBuscaCodigo(int tamanho, int contPacote, struct indicesPacotes indicePacotes[], int busca, struct guias vetGuias[], struct cidades vetCidades[],
                               struct paises vetPaises[], struct indices indiceCidades[], int contCidades, int contPaises, struct indices indicePaises[]){
    int i = 0, f = contPacote, m = (i+f)/2;
    for(int saida = 1; saida != 0 && f >= i; m = (i+f)/2){
        if(indicePacotes[m].codigo > busca){
            f = m - 1;
        }else{
            i = m + 1;
        }
    }
    if(indicePacotes[m].codigo == busca){
            cout << "\tNome do Guia: " << vetGuias[indicePacotes[m].enderGuia].nome << " - " <<
              incluirGuiasBuscaCidade(tamanho, vetCidades, vetPaises, indiceCidades, contCidades, contPaises, vetGuias[indicePacotes[m].enderGuia].codigoCidade,
                                      indicePaises) << endl;
        }
}


void incluirPacotes(int tamanho, struct pacotes vetPacote[], struct indicesPacotes indicePacotes[], int &contPacotes, struct guias vetGuias[], struct cidades vetCidades[],
                    struct paises vetPaises[], struct indices indiceCidades[], int contCidades, int contPaises){
    cout << "\n\t\tFuncao para incluir novos pacotes" << endl;

    for (int saida = 1, i = contPacotes; saida != 0 && i < tamanho; i++) {
        cout << "\n\tCodigo do Pacote: ";
        cin >> vetPacote[i].codigo;
        indicePacotes[contPacotes].codigo = vetPacote[i].codigo;
        indicePacotes[contPacotes].enderPacote = i;
        cout << "\tDescricao: ";
        cin >> vetPacote[i].descricao;
        cout << "\tCodigo de Guia: ";
        cin >> vetPacote[i].codigoGuia;
        incluirPacotesBuscaCodigo(tamanho, contPacotes, indicePacotes, vetPacote[i].codigoGuia, vetGuias, vetCidades, vetPaises, indiceCidades,
                                  contCidades, contPaises, indiceCidades);
        cout << "\tValor por pessoa: ";
        cin >> vetPacote[i].valorPessoa;
        cout << "\tTotal de participantes: ";
        cin >> vetPacote[i].totalParticipantes;
        cout << "\tQuantia maxima de participantes: ";
        cin >> vetPacote[i].quantMaxParticipantes;
        cout << "\tDeseja continuar inserindo?(1/0): ";
        cin >> saida;
        contPacotes++;
    }
}


void consultaPacote(int tamanho, int contPacote, struct indicesPacotes indicePacotes[], int busca, struct pacotes vetPacotes[]){
    int i = 0, f = contPacote, m = (i+f)/2;
    for(int saida = 1; saida != 0 && f >= i; m = (i+f)/2){
        if(indicePacotes[m].codigo > busca){
            f = m - 1;
        }else{
            i = m + 1;
        }
    }
    if(indicePacotes[m].codigo == busca){
            cout << "\n\tPacote " << indicePacotes[i].enderPacote << endl;
            cout << "\tCodigo: " << vetPacotes[indicePacotes[i].enderPacote].codigo << endl;
            cout << "\tDescricao: " << vetPacotes[indicePacotes[i].enderPacote].descricao << endl;
            cout << "\tCodigo do guia: " << vetPacotes[indicePacotes[i].enderPacote].codigoGuia << endl;
            cout << "\tValor por pessoa: " << vetPacotes[indicePacotes[i].enderPacote].valorPessoa << endl;
            cout << "\tTotal de participantes: " << vetPacotes[indicePacotes[i].enderPacote].totalParticipantes << endl;
            cout << "\tQuantia maxima de participantes: " << vetPacotes[indicePacotes[i].enderPacote].quantMaxParticipantes << endl;
            float valorTotal = vetPacotes[indicePacotes[i].enderPacote].totalParticipantes * vetPacotes[indicePacotes[i].enderPacote].valorPessoa;
            cout << "\tValor total arrecadado: " << valorTotal;
        }
}


void exibirPacote(int tamanho, int contPacote, struct indicesPacotes indicePacotes[], struct pacotes vetPacotes[], struct guias vetGuias[]){
    for(int i = 0; i < contPacote; i++){
        if(vetPacotes[indicePacotes[i].enderPacote].totalParticipantes == vetPacotes[indicePacotes[i].enderPacote].quantMaxParticipantes){
            cout << "\n\tPacote " << indicePacotes[i].enderPacote << endl;
            cout << "\tCodigo: " << vetPacotes[indicePacotes[i].enderPacote].codigo << endl;
            cout << "\tDescricao: " << vetPacotes[indicePacotes[i].enderPacote].descricao << endl;
            cout << "\tGuia: " << vetGuias[indicePacotes[i].enderGuia].nome << endl;
            float valorTotal = vetPacotes[indicePacotes[i].enderPacote].totalParticipantes * vetPacotes[indicePacotes[i].enderPacote].valorPessoa;
            cout << "\tValor total arrecadado: " << valorTotal;
        }
    }
}


string buscaCodigoPacote(int contPacote, struct indicesPacotes indicePacotes[], int busca, struct pacotes vetPacotes[]){
    int i = 0, f = contPacote, m = (i+f)/2;
    for(int saida = 1; saida != 0 && f >= i; m = (i+f)/2){
        if(indicePacotes[m].codigo > busca){
            f = m - 1;
        }else{
            i = m + 1;
        }
    }
    if(indicePacotes[m].codigo == busca){
        return vetPacotes[indicePacotes[m].enderPacote].descricao;
    }
}

void exibirVendas(int contVendas, struct indicesVendas indiceVendas[], struct vendas vetVendas[], struct clientes vetClientes[], int contPacotes,
                  struct indicesPacotes indicePacotes[], struct pacotes vetPacotes[]){
            float total = 0;
    for(int i = 0; i < contVendas; i++){
            cout << "\n\n\tVenda " << indiceVendas[i].enderVenda << endl;
            cout << "\tCodigo: " << vetVendas[indiceVendas[i].enderVenda].codigo << endl;
            cout << "\tNome do cliente: " << vetClientes[indiceVendas[i].enderCliente].nome << endl;
            cout << "\tDescricao do Pacote: " << buscaCodigoPacote(contPacotes, indicePacotes, vetVendas[indiceVendas[i].enderVenda].codigoPacote, vetPacotes) << endl;
            cout << "\tQuantidade de pessoas: " << vetVendas[indiceVendas[i].enderVenda].quantidadePessoas << endl;
            float valorTotal = vetPacotes[indicePacotes[i].enderPacote].totalParticipantes * vetPacotes[indicePacotes[i].enderPacote].valorPessoa;
            cout << "\tValor total arrecadado: " << valorTotal;

            total = total + valorTotal;
    }
    cout << "\n\n\tValor total de todas as vendas: " << total << endl;
}



void reorganizacao (int tamanho, struct indices indiceCliente[], struct clientes vetClientes[], int contClientes, struct clientes vetNovo[]){
	int j=-1;
    for (int k=0; k < contClientes; k++){
        int i = indiceCliente[k].ender;
        if (vetClientes[i].status == 0){
            j++;
            vetNovo[j] = vetClientes[i];
            indiceCliente[j].codigo = vetNovo[j].codigo;
            indiceCliente[j].ender = j;
        }
    }
    contClientes = j+1;
    for (int k = 0; k < contClientes; k++){
    	int i = indiceCliente[k].ender;
    	vetClientes[k] = vetNovo [i];
	}
}






//funções ler

void lerPaises(int tamanho, int &cont, struct paises vetPaises[], struct indices indice[]){
    cout << "\n\t\tFuncao para leitura de paises" << endl;
    cont = 0;
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
    cont = 0;
    for(int i = 0, saida = 1; i < tamanho && saida != 0; i++, cont++){
        cout << "\n\tCidade " << i << endl;
        cout << "\tCodigo: ";
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

        cout << "\tDeseja continuar?(1/0): ";
        cin >> saida;
    }
    organizaIndice(indice, tamanho);
}

//funções de impressão

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

void imprimirGuias(int tamanho, int cont, struct indices indice[], struct guias vetGuias[]){
    cout << "\n\t\tFuncao para impressao da lista de Guias" << endl;

    for(int i=0; i < cont ; i++){
        if(vetGuias[indice[i].ender].status != 1){
            cout << "\n\tGuias " << i << endl;
            cout << "\tCodigo: " << vetGuias[indice[i].ender].codigo << endl;
            cout << "\tNome: " << vetGuias[indice[i].ender].nome << endl;
            cout << "\tEndereco: " << vetGuias[indice[i].ender].endereco << endl;
            cout << "\tTelefone: " << vetGuias[indice[i].ender].telefone << endl;
            cout << "\tCodigo da Cidade: " << vetGuias[indice[i].ender].codigoCidade << endl;
        }
    }
}

void imprimirClientes(int tamanho, int cont, struct indices indice[], struct clientes vetClientes[]){
    cout << "\n\t\tFuncao para impressao da lista de Guias" << endl;

    for(int i=0; i < cont ; i++){
        if(vetClientes[indice[i].ender].status != 1){
            cout << "\n\tClientes " << i << endl;
            cout << "\tCodigo: " << vetClientes[indice[i].ender].codigo << endl;
            cout << "\tNome: " << vetClientes[indice[i].ender].nome << endl;
            cout << "\tEndereco: " << vetClientes[indice[i].ender].endereco << endl;
            cout << "\tCodigo da Cidade: " << vetClientes[indice[i].ender].codigoCidade << endl;
        }
    }
}

void imprimirPacotes(int tamanho, int cont, struct indicesPacotes indice[], struct pacotes vetPacotes[]){
    cout << "\n\t\tFuncao para impressao da lista de Guias" << endl;

    for(int i=0; i < cont ; i++){
            cout << "\n\tPacote " << i << endl;
            cout << "\tCodigo: " << vetPacotes[indice[i].enderPacote].codigo << endl;
            cout << "\tDescricao: " << vetPacotes[indice[i].enderPacote].descricao << endl;
            cout << "\tCodigo do guia: " << vetPacotes[indice[i].enderPacote].codigoGuia << endl;
            cout << "\tValor por pessoa: " << vetPacotes[indice[i].enderPacote].valorPessoa << endl;
            cout << "\tTotal de participantes: " << vetPacotes[indice[i].enderPacote].totalParticipantes << endl;
            cout << "\tQuantia maxima de participantes: " << vetPacotes[indice[i].enderPacote].quantMaxParticipantes << endl;
    }
}


void imprimirVendas(int tamanho, int cont, struct indicesVendas indice[], struct vendas vetVendas[]){
    cout << "\n\t\tFuncao para impressao da lista de Vendas" << endl;

    for(int i=0; i < cont ; i++){
            cout << "\n\tVenda " << i << endl;
            cout << "\tCodigo: " << vetVendas[indice[i].enderVenda].codigo << endl;
            cout << "\tCodigo de Cliente: " << vetVendas[indice[i].enderVenda].codigoCliente << endl;
            cout << "\tCodigo de Pacote: " << vetVendas[indice[i].enderVenda].codigoPacote << endl;
            cout << "\tQuantia de pessoas: " << vetVendas[indice[i].enderVenda].quantidadePessoas << endl;
            cout << "\tValor Total: " << vetVendas[indice[i].enderVenda].valorTotal << endl;
    }
}



int main()
{
    //inicialização do tamanho

    const int tamanho = 20;


    //inicialização dos vetores

    struct paises vetPaises[tamanho] = { {1, "Brasil"}, {2, "Argentina"}, {3, "Chile"}};
    struct cidades vetCidades[tamanho] = { {1, "Assis", "SP", 1}, {2, "Buenos aires", "AA", 2}, {3, "sao paulo", "SP", 1}, {4, "maracai", "SA", 3}, {5, "candido mota", "DA", 2} };
    struct guias vetGuias[tamanho] = { {1, "jorge", "rua tal", "123123", 2, 0}, {2, "cleide", "rua tal", "123123", 2, 0}, {3, "ze", "rua tal", "123123", 2, 0} };
    struct clientes vetClientes[tamanho] = { {1, "jorge", "rua tal", 2}, {2, "cleide", "rua tal", 2}, {3, "ze", "rua tal", 2} };
    struct vendas vetVendas[tamanho] = { {1, 1, 1, 10, 25.2}, {2, 2, 2, 15, 12}, {3, 3, 3, 5, 4} };
    struct pacotes vetPacotes[tamanho] = { {1, "a", 1, 5, 5, 10}, {2, "b", 2, 5, 5, 10}, {3, "c", 3, 5, 5, 10}};
    struct clientes vetNovo[tamanho];

    //inicialização dos indices

    struct indices indicePaises[tamanho] = { {1, 0}, {2, 1}, {3, 2} };
    struct indices indiceCidades[tamanho] = { {1, 0}, {2, 1}, {3, 2}, {4, 3}, {5, 4} };
    struct indices indiceGuias[tamanho] = { {1, 0}, {2, 1}, {3, 2} };
    struct indices indiceClientes[tamanho] = { {1, 0}, {2, 1}, {3, 2} };

    struct indicesVendas indiceVendas[tamanho] = { {1, 0, 0}, {2, 1, 1}, {3, 2, 2} };

    struct indicesPacotes indicePacotes[tamanho] = { {1, 0, 0}, {2, 1, 1}, {3, 2, 2} };


    //inicialização dos contadores

    int contPaises = 3, contCidades = 5, contGuias = 3, contClientes = 3, contVendas = 3, contPacotes = 3;


    int menu = 1;
    int decisao;

    int codigo, continuar = 1;

    while(menu != 0){
        cout << "\n\t\tDigite a funcao que deseja: " << endl;
        cout << "\n\t[01] Ler Paises" << endl;
        cout << "\t[02] Ler Cidades" << endl;
        cout << "\t[03] Imprimir Paises" << endl;
        cout << "\t[04] Imprimir Cidades" << endl;
        cout << "\t[05] Incluir Guias" << endl;
        cout << "\t[06] Imprimir Guias" << endl;
        cout << "\t[07] Incluir Clientes" << endl;
        cout << "\t[08] Imprimir Clientes" << endl;
        cout << "\t[09] Excluir Clientes" << endl;
        cout << "\t[10] Excluir Guias" << endl;
        cout << "\t[11] Incluir Vendas" << endl;
        cout << "\t[12] Imprimir Vendas" << endl;
        cout << "\t[13] Incluir Pacotes" << endl;
        cout << "\t[14] Imprimir Pacotes" << endl;
        cout << "\t[15] Consultar Pacote" << endl;
        cout << "\t[16] Exibir Pacotes com maximo de participantes" << endl;
        cout << "\t[17] Exibir Vendas" << endl;
        cout << "\t[18] Reorganizar Clientes" << endl;
        cout << "\n";
        cin >> decisao;
        system("cls");

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
            incluirGuias(tamanho, vetGuias, contGuias, indiceGuias, vetCidades, vetPaises, indiceCidades, contCidades, contPaises, indicePaises);
            break;
        case 6:
            imprimirGuias(tamanho, contGuias, indiceGuias, vetGuias);
            break;
        case 7:
            incluirClientes(tamanho, vetClientes, contClientes, vetCidades, contCidades, vetPaises, contPaises, indiceClientes, indicePaises);
            break;
        case 8:
            imprimirClientes(tamanho, contClientes, indiceClientes, vetClientes);
            break;
        case 9:
            while(continuar > 0){
                cout << "\n\tQual cliente desseja excluir? ";
                cin >> codigo;
                excluirClientes(indiceClientes, vetClientes, contClientes, codigo, contVendas, indiceVendas, vetVendas);
                cout << "\n\n\tDeseja excluir mais algum? ";
                cin >> continuar;
                system("cls");
        }
            break;
        case 10:
            while(continuar > 0){
                cout << "\n\tQual guia desseja excluir? ";
                cin >> codigo;
                excluirGuias(indiceGuias, vetGuias, contGuias, codigo, contPacotes, indicePacotes, vetPacotes);
                cout << "\n\n\tDeseja excluir mais algum? ";
                cin >> continuar;

        }
            break;
        case 11:
            incluirVendas(tamanho, contVendas, vetVendas, indiceVendas, vetCidades, vetClientes, indiceClientes, contClientes, contCidades, contPacotes, indicePacotes,
                          vetPacotes, vetGuias);
            break;
        case 12:
            imprimirVendas(tamanho, contVendas, indiceVendas, vetVendas);
            break;
        case 13:
            incluirPacotes(tamanho, vetPacotes, indicePacotes, contPacotes, vetGuias, vetCidades, vetPaises, indiceCidades, contCidades, contPaises);
            break;
        case 14:
            imprimirPacotes(tamanho, contPacotes, indicePacotes, vetPacotes);
            break;
        case 15:
            int consultar;
            cout << "\tQual pacote deseja buscar?: ";
            cin >> consultar;
            consultaPacote(tamanho, contPacotes, indicePacotes, consultar, vetPacotes);
            break;
        case 16:
            exibirPacote(tamanho, contPacotes, indicePacotes, vetPacotes, vetGuias);
            break;
        case 17:
            exibirVendas(contVendas, indiceVendas, vetVendas, vetClientes, contPacotes, indicePacotes, vetPacotes);
            break;
        case 18:
            reorganizacao(tamanho, indiceClientes, vetClientes, contClientes, vetNovo);
            break;
        default:
            cout << "parcero voce e bobo";
        }

       cout << "\n\tDeseja continuar no programa?(1/0): ";
       cin >> menu;
       system("cls");
    }
    return 0;
}
