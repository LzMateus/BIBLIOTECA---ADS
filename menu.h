#define MAX_SOCIOS 100
#define MAX_LIVROS 100
#define MAX_EXEMPLARES 100
#define MAX_EMPRESTIMOS 100
#define MAX_NOME 100
#define STRTAM 30
#define MAX_TELEFONE 15
#define MAX_EMAIL 100
#define MAX_ENDERECO 200
#define MAX_CEP 10



void CriaMenuLinhaSuperior() {
    int i;
    printf("%c", 201); // Canto superior esquerdo
    for (i = 0; i < STRTAM; i++) {
        printf("%c", 205); // Linha horizontal
    }
    printf("%c\n", 187); // Canto superior direito
}

void CriaMenuLinhaRodape() {
    int i;
    printf("%c", 200); // Canto inferior esquerdo
    for (i = 0; i < STRTAM; i++) {
        printf("%c", 205); // Linha horizontal
    }
    printf("%c\n", 188); // Canto inferior direito
}

void CriaMenuItem(char str[]) {
    int len = strlen(str);
    printf("%c", 186); // Linha vertical
    printf("%s", str);
    for (int i = len; i < STRTAM; i++) {
        printf(" "); // Preenchimento para alinhar o texto
    }
    printf("%c\n", 186); // Linha vertical
}
/*------------------------------------------------------------------------------------------------*/
void montaMenu() {
    CriaMenuLinhaSuperior();
    CriaMenuItem("     SISTEMA DE BIBLIOTECA");
    CriaMenuLinhaRodape();

    CriaMenuLinhaSuperior();
    CriaMenuItem("1. CADASTRAR SOCIO.");
    CriaMenuItem("2. CADASTRAR LIVRO.");
    CriaMenuItem("3. CADASTRAR EXEMPLAR.");
    CriaMenuItem("4. REALIZAR EMPRESTIMO.");
    CriaMenuItem("5. EFETUAR DEVOLUCAO.");
    CriaMenuItem("6. RENOVAR EMPRESTIMO.");
    CriaMenuItem("7. LISTAR SOCIOS.");
    CriaMenuItem("8. LISTAR LIVROS.");
    CriaMenuItem("9. EMITIR COMPROVANTE.");
    CriaMenuItem("0. SAIR.");
    CriaMenuLinhaRodape();
}
