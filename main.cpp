#include <iostream>

using namespace std;

struct paises{
    int codigo_pais;
    string nome;
};

struct cidades{
    int codigo_cidade;
    string nome;
    char uf[2];
    int codigo_pais;
};

struct guias{
    int codigo_guia;
    string nome;
    string endereco;
    string telefone;
    int codigo_cidade;
};

struct clientes{
    int codigo_guia;
    string nome;
    string endereco;
    int codigo_cidade;
};

struct pacotes{
    int codigo_pacote;
    string descricao;
    int codigo_guia;
    float valor_por_pessoa;
    int total_participantes;
    int quant_max_participantes;
};

struct indice_pacote{
    int codigo_pacote;
    int ender;
};

struct indice_guia{
    int codigo_guia;
    int ender;
};

struct vendas{
    int codigo_venda;
    int codigo_cliente;
    int codigo_pacote;
    int quantidade_pessoas;
    float valor_total;
};

struct indice venda{
    int codigo_venda;
    int ender;
};

struct indice cliente{
    int codigo_cliente;
    int ender;
};

void leituraPaises(int tamanho, struct paises vetPaises[], int &cont){
    for(int i=0, saida=1; saida != 0 && i<tamanho; i++){
        cout << "\nPais " << i << endl;
        cout << "\nCodigo: ";
        cin >> vetPaises[i].codigo_pais;
        if(vetPaises[i].codigo_pais > 0){
            cout << "Nome: ";
            cin >> vetPaises[i].nome;
            cont++;
        } else {
            saida = 0;
        }
    }
}

void leituraCidades(int tamanho, struct cidades vetCidades[], int &cont){
    for(int i=0, saida=1; saida != 0 && i<tamanho; i++){
        cout << "\nCidade " << i << endl;
        cout << "\nCodigo: ";
        cin >> vetCidades[i].codigo_cidade;
        if(vetCidades[i].codigo_cidade > 0){
            cout << "Nome: ";
            cin >> vetCidades[i].nome;
            cout << "UF: ";
            cin >> vetCidades[i].uf;
            cout << "\nCodigo pais: ";
            cin >> vetCidades[i].codigo_pais;
            cont++;
        } else {
            saida = 0;
        }
    }
}

void incluirGuia(){
    int confirma;
    cout << "\nInclusao de guias: " << endl;
    for(int i=0, saida=1; saida !=0 && cont < tamanho; i++){
        cout "\nCodigo: ";
        cin >> vetGuia[i].codigo_guia;
        if(vetGuia[i].codigo_guia > 0){
            cout << "Nome: ";
            cin >> vetGuia[i].nome;
            cout << "Endereco: ";
            cin >> vetGuia[i].endereco;
            cout << "Telefone: ";
            cin >> vetGuia[i].telefone;
            cout << "Codigo cidade: ";
            cin >> vetGuia[i].codigo_cidade;
            cont++;
            cout << "Deseja incluir mais algum? " << endl;
            cin >> confirma;
            if(confirma == 0){
                saida = 0;
            }
        } else {
            saida = 0;
        }
    }
}




int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
