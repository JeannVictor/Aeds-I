# Projeto 5: Vetor de Registros

## Objetivo

Este projeto tem como objetivo gerenciar uma agenda de amigos utilizando um vetor de registros. Cada amigo possui os seguintes campos:  
- **Nome**  
- **Celular**  
- **Cidade**  
- **Email**  
- **Flag de Validade**: Indica se o registro está ativo ou não (para exclusão lógica).

O programa lê um arquivo inicial contendo os dados dos amigos, permite realizar diversas operações sobre a agenda e, ao final, salva as alterações no mesmo arquivo.

---

## Funcionalidades

O programa oferece as seguintes operações:

1. **Buscar pelo Nome do Amigo**  
   Permite procurar um amigo pelo nome e exibe os dados correspondentes caso o registro seja válido.

2. **Excluir um Amigo**  
   Marca o registro de um amigo como inválido, configurando o campo de flag para `Falso`.

3. **Inserir um Novo Amigo**  
   Adiciona um novo registro de amigo no vetor, preenchendo todos os campos necessários.

---

## Estrutura do Registro

Cada amigo na agenda é representado por uma estrutura com os seguintes campos:

```c

typedef struct {
    char nome[MAX_CAMPO];
    char celular[MAX_CAMPO];
    char cidade[MAX_CAMPO];
    char email[MAX_CAMPO];
    int valido;  
} Amigo;
