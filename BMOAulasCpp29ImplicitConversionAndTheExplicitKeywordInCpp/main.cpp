//
//  main.cpp
//  BMOAulasCpp29ImplicitConversionAndTheExplicitKeywordInCpp
//
//  Created by Breno Medeiros on 11/06/21.
//




//Sobre conversoes em Cpp existem:
// 1) implicita(implicity): Automatica pelo compilador
// 2) explicita('explicity'): Inutiliza a KeyWord 'implicity', que é padrao(ou seja, nao é preciso escrever na declaracao dos construtores para existir)
// 3) 'cast': Conversao manual escrita pelo desenvolvedor)


#include <iostream>
#include <string>

class Entidade {
private:
    std::string m_Nome;
    int m_Idade;
    float m_Altura;
public:
    Entidade(const std::string& nome):
            m_Nome(nome),
            m_Idade(-1),
            m_Altura(1.5f) {
        
    }
    Entidade(int idade):
            m_Nome("Desconhecido"),
            m_Idade(idade),
            m_Altura(1.5f) {
        
    }
    explicit Entidade(float altura): //Ao definir esse construtor como explicito, apenas instaciacoes nao implicitas poderam usar esse metodo.
            m_Nome("Desconhecido"),
            m_Idade(-1),
            m_Altura(altura) {
        
    }
};

void PrintEntidade(const Entidade& entidade) {
    //Exibe coisas no console
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    //Repare no seguinte que pode ser escrito em C++ porem n pode em outras linguagens como Java:
    Entidade b = Entidade(28);                  //Isso pode ser reescrito assim:
    Entidade bImplicito = 28;                   //... pois o C++ fer uma conversao 'implicita', visto que ha um construtor que recebe um argumento de 'int'
    Entidade a = Entidade("Breno");             //Isso pode ser reescrito assim:
    Entidade aImplicito = std::string("Breno"); //... pois o C++ fer uma conversao 'implicita', visto que ha um construtor que recebe um argumento de 'string'
    //No caso de 'aImplicito' foi necessario uma segunda conversao, pois "Breno" é do tipo 'const char [6]' e nao do tipo 'std::string&'. Mas o ideal nesse
    // seria reduzir de 2 conversoes para uma unica conversao implicita, assim:
    Entidade aImplicitoUnico = Entidade("Breno");
    
    
    PrintEntidade(22); //Fazendo outra conversao implicita, mas dessa vez passando como argumento
    PrintEntidade(std::string("Breno"));
    
    // Como o construtor "explicit Entidade(bool masculino){}" esta explicito, o seguinte nao funcionara:
    //Entidade cImplicito = 1.8f; //Descomentar essa linha causa erro
    Entidade c = Entidade(1.8f);
    
    
    //Moral dessa aula: É bom que voce saiba que por padrao construtores aceitam conversao implicita por padrao.
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
