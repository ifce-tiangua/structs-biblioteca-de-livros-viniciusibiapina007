#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    
    char nome[80];
    char isbn[35];
    float preco;
    int score;
    char editora[40];
    
}Livro, *pLivro ;

pLivro livro_alloc(int qtde);
void livro_ler(pLivro livros, int qtde);
void livro_exibe(pLivro livros, int qtde);
void livro_desaloca(pLivro livros);

int main(){
    
    setlocale(LC_ALL, "Portuguese");
    
    int q_livros;
    scanf("%d", &q_livros);
    
    if(q_livros == 0){  // Primeiro, vamos verificar se quantidade é 0
        printf("Sem livros");
        
    }
    else{       // se não for 0, iniciaremos o processo de alocação e leitura
        
        pLivro prateleira = livro_alloc(q_livros); // a variável "prateleira" será o nosso vetor dinâmico para as estruturas "Livro"
    
        for(int i =0; i<q_livros; i++){
            int n;
            scanf("%d", &n);
            prateleira[i].score = n;
        }
        
        livro_ler(prateleira, q_livros);
        
        livro_exibe(prateleira, q_livros);
    }
    
    return 0;
}

pLivro livro_alloc(int qtde){
    
    pLivro estante = (pLivro) malloc(qtde * sizeof(Livro));
    return estante;
}

void livro_ler(pLivro livros, int qtde){
    
    for(int i = 0; i < qtde; i++){

        //devido ao fato de o nome dos livros terem espaço, não podemos usar "scanf", então usamos "fgets"
        fgets(livros[i].nome, sizeof(livros[i].nome), stdin);
        livros[i].nome[strcspn(livros[i].nome, "\n")] = '\0'; 
        
        fgets(livros[i].isbn, sizeof(livros[i].isbn), stdin);
        livros[i].isbn[strcspn(livros[i].isbn, "\n")] = '\0'; 

        scanf("%f", &livros[i].preco);
        getchar();

        scanf("%d", &livros[i].score);
        getchar();

        fgets(livros[i].editora, sizeof(livros[i].editora), stdin);
        livros[i].editora[strcspn(livros[i].editora, "\n")] = '\0'; 
    }
    
}

void livro_exibe(pLivro livros, int qtde){
    
    for(int i = 0; i < qtde; i++){
        
        printf("Livro %d:\n", i+1); // como o laço for começa em 0 , temos que somar +1 na hora de exibir
        printf("Nome: %s\n", livros[i].nome);
        printf("ISBN: %s\n", livros[i].isbn);
        printf("Preço: R$ %.2f\n", livros[i].preco);
        printf("Score: %d\n", livros[i].score);
        printf("Editora: %s\n\n", livros[i].editora);
        
    }
    
}

void livro_desaloca(pLivro livros){
    free(livros);
}
