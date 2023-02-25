# Labs 4º Edição

No diretório existe um Makefile, os códigos dos programas, a libft e dois arquivos .txt para testes.
Fique à vontade para criar novos arquivos ou editar esses, mas é importante eles possuirem a extensão .txt.

## Como funciona

O Makefile irá compilar dois programas `encoder` e `decoder`.

`encoder:` Este progama irá comprimir arquivos de texto usando o algoritmo de Huffman, e gerar um arquivo .dat com o mesmo nome, depois irá executar o programa `decoder` e imprimir na tela os dados da descompressão.

`decoder:` Já este irá ler o arquivo .dat, descomprimir seu conteúdo e coletar alguns dados da descompressão. Este programa quando executado pelo `encoder` irá preencher uma memória compartilhada com os dados coletados e não imprimirá nada na tela, mas quando executado pelo usuário ele irá imprimir na tela o texto descomprimido e os dados da descompressão.

Execução:
```
./encoder teste.txt
```
```
./decoder teste.dat
```
## Como o encoder trabalha

1. Primeiro é criado uma lista encadeada com todos os caracteres do texto e suas frequências
2. A partir desta lista encadeada é criada uma `árvore de Huffman`.
	* A árvore de Huffman é uma árvore binária que usa como base a frequência em que os caracteres aparecem em um texto, onde na folha mais distante da raiz está o caractere menos frequente.
3. Com a árvore pronta e uma lista dos caracteres em mãos, é criado uma `tabela de tradução` em uma memória pública que será compartilhada com o decoder, nesta tabela está o caractere original e seu binário relativo à árvore de Huffman.
4. Com a tabela de tradução e o texto original é criado uma fita binária que será escrito em um arquivo .dat, os primeiros 4 bytes deste arquivo será preenchido com a chave da memória compartilhada, o resto será o texto comprimido.
5. Então o `encoder` irá iniciar uma nova memória compartilhada para receber os dados da descompressão, e irá executar o `decoder` em um processo filho, enviando o arquivo .dat como argumento.
6. Assim que o `decoder` finalizar seu processo, o `encoder` irá imprimir na tela os dados fornecidos pelo decoder, que são:
	* Texto descomprimido
	* Tempo necessário para descompressão
	* Tamanho em bytes do texto comprimido
	* Tamanho em bytes do texto descomprimido
7. Por fim o encoder irá fechar as memórias compartilhadas para receber os dados da descompressão.

## Como o decoder trabalha

1. Primeiro é analisado o argumento do programa, e depois o arquivo .dat é aberto.
2. Então os primeiros 4bytes do arquivo são lidos e armazenados como chave para a memória compartilhada.
3. Depois enviamos o resto do arquivo para ser lido e armazenado em uma string que tem o papel de fita binária.
4. Com a chave para a memória compartilhada e a fita binária em mãos, é aberto uma conexão com a memória compartilhada para que o decoder tenha acesso à `tabela de tradução`.
5. A fita binária é então descomprimida e armazenada em uma estrutura, junto com os dados da descompressão.
6. Esses dados podem ter dois destinos, se existir uma memória compartilhada, onde o arquivo .dat foi usado para gerar a chave, então esses dados são compartilhados com o `encoder`; se não existir esses dados são impressos na tela.

## Observações
- A memória compartilhada que possui a tabela de tradução, só será fechada se o `decoder` for executado pelo usuário.  
- Este compressor de dados é mais efetivo com arquivos de textos com 5 caracteres ou mais por causa da chave da memória compartilhada nos primeiros 4bytes.  
- O tamanho do arquivo descomprimido pode variar um pouco no caso de possuir caracteres especiais ou acentuação.  
- É possível usar o `encoder` em vários arquivos antes de usar o `decoder`. 

## Teclogias utilizadas
- Memória compartilhada
	- bibliotecas: `sys/ipc.h`, `sys/shm.h` e `sys/types.h`
	- No cabeçalho dos programas está um guia das funções útilizadas
- wchar_t como estrutura de caractere para poder receber todos os tipos de texto unicode e suas funções
	- biblioteca: `wchar.h`
- setlocale para redefinir a compatibilidade de texto de acordo com as variáveis de ambiente do usuário
	- biblioteca: `locale.h`

## Considerações finais

Eu gostaria de ter mais 2 dias hábeis para finalizar esse projeto, com esse tempo eu faria com que o arquivo de texto fosse lido e interpretado em partes no caso dele ser muito longo para não quebrar com um malloc muito extenso.
