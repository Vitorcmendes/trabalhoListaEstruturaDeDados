#include <stdio.h>
#include <lista.h>
#include <stdbool.h>


    // ----------------------  OPERAÇÕES BÁSICAS   ----------------------


// criar lista vazia.
Lista CriaListaVazia(){
    Lista novaLista;
    
    novaLista.n = 0;
    
    return novaLista;
}

// verificar se a lista está vazia.
bool VerificaSeListaVazia(Lista qualquer){

    if(qualquer.n == 0){
        return true;
    } else return false;
}

// verificar se a lista está cheia.
bool VerificaSeListaCheia(Lista qualquer){
    
    if(qualquer.n == MAX){
        return true;
    } else return false;
}

// obter tamanho da lista.
int tamanhoLista(Lista qualquer){
    return qualquer.n;
}


    // ----------------------   INSERÇÕES   ----------------------


// inserir no início.
Lista insereNoInicio(Lista qualquer){
    int x = 0;
    printf("Digite o número que você deseja inserir no início da sua lista: ");
    scanf("%d", &x);
    for(int i = qualquer.n; i>0; i--){
        qualquer.lista[i] = qualquer.lista[i-1];
    }
    qualquer.lista[0] = x;
    qualquer.n++;
    
    return qualquer;
}


// inserir no final.
Lista insereNoFinal(Lista qualquer){
    int x = 0;
    printf("Digite o número que você deseja inserir no final da sua lista: ");
    scanf("%d", &x);
    
    qualquer.lista[qualquer.n] = x;
    qualquer.n++;
    
    return qualquer;
}

// inserir em posição arbitrária.
Lista insereEmPosicaoArbitraria(Lista qualquer){
    int x = 0;
    int y = 0;
    printf("Digite o número que você deseja inserir na lista: ");
    scanf("%d", &x);
    printf("Agora digite em qual posição da lista você deseja inserir o número\n ");
    printf("(atualmente, você tem até a posição %d para inserir): ", qualquer.n+1);
    scanf("%d", &y);
    
    //nesse caso, não fiz a conversão de índice y-- porque assim eu permitito
    //que seja inserido em qualquer lugar da lista inclusive ao final
    
    while(y < 1 || y > qualquer.n){ // y < 1 para não permitir índice negativo.
        printf("Posição inválida ou maior que o limite permitido da lista(%d), digite novamente:", qualquer.n-1);
        scanf("%d", &y);
    }
    
    y--;
    
    for( int k = qualquer.n; k > y; k--){
        
        qualquer.lista[k] = qualquer.lista[k-1];
    }   qualquer.lista[y] = x;
        qualquer.n++;
        return qualquer;
    }


    // ----------------------   REMOÇÕES   ----------------------

// remover no início.

Lista removerDoInicio(Lista qualquer){
        for(int i = 0; i<qualquer.n-1; i++){
            qualquer.lista[i] = qualquer.lista[i+1];   
        } 
        
        qualquer.lista[qualquer.n-1] = 0;
        qualquer.n--;
        
        return qualquer;
        
    }

// remover no final.
Lista removerFinal(Lista qualquer) {
    if (qualquer.n > 0) {
        qualquer.n--;
    }
    return qualquer;
}   

// remover em posição arbitrária.

 Lista removeEmPosicaoArbitraria(Lista qualquer){
        int x = 0;
        
        printf("Digite a posição do elemento que você deseja remover:  ");
        scanf("%d", &x);
        
        while(x < 1 || x > qualquer.n){ // x < 1
        printf("Posição maior que o limite permitido da lista(%d), digite novamente:", qualquer.n);
        scanf("%d", &x);
    }
        
        for( int i = x-1; i<qualquer.n-1; i++){
            
            qualquer.lista[i] = qualquer.lista[i+1];
        }
        
        qualquer.lista[qualquer.n-1] = 0;
        qualquer.n--;
        
        return qualquer;
        
    }

// remover elemento por valor.

Lista removePorValor(Lista qualquer){
        int x = 0;
        int posicaoAretirar = 0;
        bool verifica = false;
        
        printf("Digite o valor do elemento que você deseja remover:  ");
        scanf("%d", &x);
        
        while(verifica == false){
            
            for(int i = 0; i < qualquer.n; i++){
                if(qualquer.lista[i] == x){
                    verifica = true;
                    posicaoAretirar = i;
                }
                
            } 
                
             if(verifica == false){
               
               printf("Valor não encontrado. Digite novamente: ");
               scanf("%d", &x);
            }
            
        }
        
    
    
        for( int i = posicaoAretirar; i<qualquer.n-1; i++){
            
            qualquer.lista[i] = qualquer.lista[i+1];
        }
        
        qualquer.lista[qualquer.n-1] = 0;
        qualquer.n--;
        
        return qualquer;
        
    }


    // ----------------------   CONSULTAS   ----------------------


// buscar posição de um valor.

int ConsultaPosicaoDoValor(Lista qualquer){
        int x = 0;
        int posicaoValor = 0;
        bool verifica = false;
        
        printf("Digite o valor do elemento que você deseja consulta a posição:  ");
        scanf("%d", &x);
            
            for(int i = 0; i < qualquer.n; i++){
                if(qualquer.lista[i] == x){
                    verifica = true;
                    posicaoValor = i;
                    break;
                }
                
            } 
                
             if(verifica == false){
               
               printf("Valor não encontrado. Digite novamente: ");
               return 0;
            }
            
            return posicaoValor+1;
            
        }

// obter valor em uma posição.
void consultarValorPorPosicao(Lista qualquer) {
    int x = 0;
    printf("Digite a posição que você deseja consultar: (Max=%d) ", qualquer.n);
    scanf("%d", &x);
    x--;
    if(x > qualquer.n) {
        printf("Esta posição está ainda não foi preenchida. (Max=%d)", qualquer.n);
    } else {
        printf("%d\n", qualquer.lista[x]);
    }
}


// imprimir todos os elementos da lista.
void exibeLista(Lista qualquer){

    for(int i = 0; i<qualquer.n; i++){
        if(i==qualquer.n - 1){
           printf("%d ", qualquer.lista[i]); // porque na última repetição não quero imprimir a vírgula
        } else
        printf("%d, ", qualquer.lista[i]);
    }
}
