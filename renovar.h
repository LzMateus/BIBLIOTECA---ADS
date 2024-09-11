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


typedef enum { DISPONIVEL, EMPRESTADO, RESERVADO, CONSULTA } Situacao;

typedef enum { REGULAR, PREMIUM, ESTUDANTE } TipoSocioEnum;

typedef struct {
    TipoSocioEnum tipo;
    int limiteExemplares;
    int limiteRenovacoes;
} TipoSocio;

typedef struct {
    int id;
    char nome[MAX_NOME];
    TipoSocioEnum tipo;
    int livrosEmprestados;
    char telefone[MAX_TELEFONE];
    char email[MAX_EMAIL];
    char endereco[MAX_ENDERECO];
    char cep[MAX_CEP];
} Socio;

typedef struct {
    int id;
    char titulo[MAX_NOME];
    int ano;
    int edicao;
    int numeroPaginas;
    long ISBN;
} Livro;

typedef struct {
    int id;
    Livro livro;
    Situacao situacao;
} Exemplar;

typedef struct {
    int id;
    Socio socio;
    int exemplarIds[MAX_EXEMPLARES];
    int numExemplares;
    int numRenovacoes;
    char dataEmprestimo[11];
    char dataPrevistaDevolucao[11];
    char dataDevolucao[11];
} Emprestimo;
/*------------------------------------------------------------------------------------------------------------------*/
TipoSocio tiposSocios[] = {
    {REGULAR, 1, 1},
    {PREMIUM, 1, 1},
    {ESTUDANTE, 1, 1}
};

Socio socios[MAX_SOCIOS];
Livro livros[MAX_LIVROS];
Exemplar exemplares[MAX_EXEMPLARES];
Emprestimo emprestimos[MAX_EMPRESTIMOS];

int numSocios = 0;
int numLivros = 0;
int numExemplares = 0;
int numEmprestimos = 0;
/*----------------------------------------------------------------------------------------------------------------------*/
void cadastrarSocio() {
    if (numSocios >= MAX_SOCIOS) {
        printf("Numero maximo de socios alcancado.\n");
        return;
    }

    Socio socio;
    socio.id = numSocios + 1;  // Identificador unico
    
    printf("Digite o nome do socio: ");
    fgets(socio.nome, MAX_NOME, stdin);
    socio.nome[strcspn(socio.nome, "\n")] = '\0';  // Remove newline

    printf("Digite o telefone do socio: ");
    fgets(socio.telefone, MAX_TELEFONE, stdin);
    socio.telefone[strcspn(socio.telefone, "\n")] = '\0';  // Remove newline

    printf("Digite o email do socio: ");
    fgets(socio.email, MAX_EMAIL, stdin);
    socio.email[strcspn(socio.email, "\n")] = '\0';  // Remove newline

    printf("Digite o endereco do socio: ");
    fgets(socio.endereco, MAX_ENDERECO, stdin);
    socio.endereco[strcspn(socio.endereco, "\n")] = '\0';  // Remove newline

    printf("Digite o CEP do socio: ");
    fgets(socio.cep, MAX_CEP, stdin);
    socio.cep[strcspn(socio.cep, "\n")] = '\0';  // Remove newline

    printf("Escolha o tipo de socio (0 - Regular, 1 - Premium, 2 - Estudante): ");
    int tipo;
    scanf("%d", &tipo);
    getchar();  // Limpar o buffer
    if (tipo < 0 || tipo > 2) {
        printf("Tipo invalido. Definido como Regular.\n");
        socio.tipo = REGULAR;
    } else {
        socio.tipo = tipo;
    }

    socio.livrosEmprestados = 0;
    socios[numSocios++] = socio;
    
    printf("Socio cadastrado com sucesso!\n");
    system("pause");
    system("CLS");
}

/*---------------------------------------------------------------------------------------------------------------*/
void listarLivros() {
    if (numLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    printf("Lista de Livros:\n");
    for (int i = 0; i < numLivros; i++) {
        Livro livro = livros[i];
        printf("ID: %d\n", livro.id);
        printf("Título: %s\n", livro.titulo);
        printf("Ano: %d\n", livro.ano);
        printf("Edição: %d\n", livro.edicao);
        printf("Número de Páginas: %d\n", livro.numeroPaginas);
        printf("ISBN: %ld\n", livro.ISBN);
        printf("----------------------------\n");
    }
}

/*-----------------------------------------------------------------------------------------------------------------------*/
void listarSocios() {
    if (numSocios == 0) {
        printf("Nenhum sócio cadastrado.\n");
        return;
    }

    printf("Lista de Sócios:\n");
    for (int i = 0; i < numSocios; i++) {
        Socio socio = socios[i];
        printf("ID: %d\n", socio.id);
        printf("Nome: %s\n", socio.nome);
        printf("Tipo: ");
        switch (socio.tipo) {
            case REGULAR:
                printf("Regular\n");
                break;
            case PREMIUM:
                printf("Premium\n");
                break;
            case ESTUDANTE:
                printf("Estudante\n");
                break;
            default:
                printf("Desconhecido\n");
                break;
        }
        printf("Livros Emprestados: %d\n", socio.livrosEmprestados);
        printf("----------------------------\n");
    }

}

/*------------------------------------------------------------------------------------------------------------------------------*/
void cadastrarLivro() {
    if (numLivros >= MAX_LIVROS) {
        printf("Numero maximo de livros alcancado.\n");
        return;
    }

    Livro livro;
    livro.id = numLivros + 1;  // Identificador unico
    printf("Digite o titulo do livro: ");
    fgets(livro.titulo, MAX_NOME, stdin);
    livro.titulo[strcspn(livro.titulo, "\n")] = '\0';

    printf("Digite o ano do livro: ");
    scanf("%d", &livro.ano);
    printf("Digite a edicao do livro: ");
    scanf("%d", &livro.edicao);
    printf("Digite o numero de paginas do livro: ");
    scanf("%d", &livro.numeroPaginas);
    printf("Digite o ID do livro: ");
    scanf("%ld", &livro.ISBN);
    getchar();  // Limpar o buffer

    livros[numLivros++] = livro;
    printf("Livro cadastrado com sucesso!\n");
    system("pause");
    system("CLS");
}

/*---------------------------------------------------------------------------------------------------------------------------*/
void realizarEmprestimo() {
    if (numEmprestimos >= MAX_EMPRESTIMOS) {
        printf("Numero maximo de emprestimos alcancado.\n");
        return;
    }

    Emprestimo emprestimo;
    emprestimo.id = numEmprestimos + 1;  // Identificador unico
    printf("Digite o ID do socio que fara o emprestimo: ");
    int idSocio;
    scanf("%d", &idSocio);
    getchar();

    if (idSocio < 1 || idSocio > numSocios) {
        printf("ID do socio invalido.\n");
        return;
        
    }

    Socio *socio = &socios[idSocio - 1];
    TipoSocio tipoSocio = tiposSocios[socio->tipo];
    if (socio->livrosEmprestados >= tipoSocio.limiteExemplares) {
        printf("Socio ja alcancou o limite de exemplares emprestados.\n");
        return;
        system("pause");
    system("CLS");
    }

    emprestimo.socio = *socio;
    emprestimo.numExemplares = 0;
    emprestimo.numRenovacoes = 0; // Inicialmente, o emprestimo nao foi renovado

    printf("Digite a data do emprestimo (dd/mm/aaaa): ");
    fgets(emprestimo.dataEmprestimo, 11, stdin);
    emprestimo.dataEmprestimo[strcspn(emprestimo.dataEmprestimo, "\n")] = '\0';

    printf("Digite o numero de exemplares para o emprestimo: ");
    int numExemplaresEmprestimo;
    scanf("%d", &numExemplaresEmprestimo);
    getchar();

    for (int i = 0; i < numExemplaresEmprestimo; i++) {
        printf("Digite o ID do exemplar %d: ", i + 1);
        int idExemplar;
        scanf("%d", &idExemplar);
        getchar();

        if (idExemplar < 1 || idExemplar > numExemplares) {
            printf("ID do exemplar invalido.\n");
            return;
        }

        Exemplar *exemplar = &exemplares[idExemplar - 1];
        if (exemplar->situacao != DISPONIVEL) {
            printf("Exemplar nao disponivel.\n");
            return;
        }

        emprestimo.exemplarIds[emprestimo.numExemplares++] = exemplar->id;
        exemplar->situacao = EMPRESTADO;
        socio->livrosEmprestados++;
    }

    printf("Digite a data prevista de devolucao (dd/mm/aaaa): ");
    fgets(emprestimo.dataPrevistaDevolucao, 11, stdin);
    emprestimo.dataPrevistaDevolucao[strcspn(emprestimo.dataPrevistaDevolucao, "\n")] = '\0'; 

    emprestimos[numEmprestimos++] = emprestimo;
    printf("Emprestimo realizado com sucesso!\n");
}
/*--------------------------------------------------------------------------------------------------------------------------------------------*/
void cadastrarExemplar() {
    if (numExemplares >= MAX_EXEMPLARES) {
        printf("Número máximo de exemplares alcançado.\n");
        return;
    }

    Exemplar exemplar;
    exemplar.id = numExemplares + 1; // ID unico para o exemplar

    printf("Digite o ID do livro ao qual o exemplar pertence: ");
    int idLivro;
    scanf("%d", &idLivro);
    getchar();

    if (idLivro < 1 || idLivro > numLivros) {
        printf("ID do livro inválido.\n");
        return;
    }

    exemplar.livro = livros[idLivro - 1]; // funcao para associar o livro ao exemplar
    exemplar.situacao = DISPONIVEL;  // Situação inicial do exemplar

    exemplares[numExemplares++] = exemplar; // Adiciona o exemplar ao array
    printf("Exemplar cadastrado com sucesso!\n");

    system("pause");
    system("CLS");
}

/*---------------------------------------------------------------------------------------------------------------------------------*/
void devolverExemplar() {
    printf("Digite o ID do emprestimo para devolucao: ");
    int idEmprestimo;
    scanf("%d", &idEmprestimo);
    getchar();

    if (idEmprestimo < 1 || idEmprestimo > numEmprestimos) {
        printf("ID do emprestimo invalido.\n");
        return;
    }

    Emprestimo *emprestimo = &emprestimos[idEmprestimo - 1];
    printf("Digite o ID do exemplar devolvido: ");
    int idExemplar;
    scanf("%d", &idExemplar);
    getchar();

    int encontrado = 0;
    for (int i = 0; i < emprestimo->numExemplares; i++) {
        if (emprestimo->exemplarIds[i] == idExemplar) {
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Exemplar nao faz parte deste emprestimo.\n");
        return;
    }

    for (int i = 0; i < emprestimo->numExemplares; i++) {
        if (emprestimo->exemplarIds[i] == idExemplar) {
            Exemplar *exemplar = &exemplares[idExemplar - 1];
            if (exemplar->situacao != EMPRESTADO) {
                printf("Exemplar nao esta emprestado.\n");
                return;
            }

            exemplar->situacao = DISPONIVEL;
            emprestimo->socio.livrosEmprestados--;
            break;
        }
    }

    printf("Digite a data de devolucao (dd/mm/aaaa): ");
    fgets(emprestimo->dataDevolucao, 11, stdin);
    emprestimo->dataDevolucao[strcspn(emprestimo->dataDevolucao, "\n")] = '\0';

    printf("Devolucao registrada com sucesso!\n");
}
void renovarEmprestimo() {
    printf("Digite o ID do emprestimo para renovacao: ");
    int idEmprestimo;
    scanf("%d", &idEmprestimo);
    getchar();

    if (idEmprestimo < 1 || idEmprestimo > numEmprestimos) {
        printf("ID do emprestimo invalido.\n");
        return;
    }

    Emprestimo *emprestimo = &emprestimos[idEmprestimo - 1];

    // para obter o tipo do socio
    TipoSocio tipoSocio = tiposSocios[emprestimo->socio.tipo];

    if (emprestimo->numRenovacoes >= tipoSocio.limiteRenovacoes) {
        printf("Limite de renovacoes alcancado.\n");
        return;
    }

    printf("Digite a nova data prevista de devolucao (dd/mm/aaaa): ");
    fgets(emprestimo->dataPrevistaDevolucao, 11, stdin);
    emprestimo->dataPrevistaDevolucao[strcspn(emprestimo->dataPrevistaDevolucao, "\n")] = '\0';

    emprestimo->numRenovacoes++;
    printf("Renovacao processada com sucesso!\n");
}
void salvarComprovanteEmprestimo(int idEmprestimo) {
    if (idEmprestimo < 1 || idEmprestimo > numEmprestimos) {
        printf("ID do empréstimo inválido.\n");
        return;
    }

    Emprestimo *emprestimo = &emprestimos[idEmprestimo - 1];

    // Criando nome de arquivo com base no ID do empréstimo
    char nomeArquivo[50];
    sprintf(nomeArquivo, "Comprovante_Emprestimo_%d.txt", idEmprestimo);

    // Abrindo arquivo para escrita
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    // Escrevendo no arquivo - recibo
    fprintf(arquivo, "========================================\n");
    fprintf(arquivo, "       COMPROVANTE DE EMPRESTIMO        \n");
    fprintf(arquivo, "========================================\n");
    fprintf(arquivo, "ID do Empréstimo: %d\n", emprestimo->id);
    fprintf(arquivo, "Nome do Sócio: %s\n", emprestimo->socio.nome);
    fprintf(arquivo, "Tipo de Sócio: ");
    switch (emprestimo->socio.tipo) {
        case REGULAR:
            fprintf(arquivo, "Regular\n");
            break;
        case PREMIUM:
            fprintf(arquivo, "Premium\n");
            break;
        case ESTUDANTE:
            fprintf(arquivo, "Estudante\n");
            break;
        default:
            fprintf(arquivo, "Desconhecido\n");
            break;
    }

    fprintf(arquivo, "Livros Emprestados:\n");
    for (int i = 0; i < emprestimo->numExemplares; i++) {
        int idExemplar = emprestimo->exemplarIds[i];
        Exemplar *exemplar = &exemplares[idExemplar - 1];
        Livro *livro = &livros[exemplar->livro.id - 1]; // Pegando o livro associado ao exemplar
        fprintf(arquivo, "- Título: %s (ID Exemplar: %d)\n", livro->titulo, exemplar->id);
    }

    fprintf(arquivo, "Data de Empréstimo: %s\n", emprestimo->dataEmprestimo);
    fprintf(arquivo, "Data Prevista de Devolução: %s\n", emprestimo->dataPrevistaDevolucao);

    fprintf(arquivo, "\n----------------------------------------\n");
     fprintf(arquivo, "___________________________________\n");
    fprintf(arquivo, "         Assinatura do Sócio\n");
    fprintf(arquivo, "========================================\n");

    // Fechando o arquivo de texto
    fclose(arquivo);

    printf("Comprovante salvo com sucesso em %s.\n", nomeArquivo);
}
