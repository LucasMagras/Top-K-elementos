# Top-K-elementos

## Problema proposto
<p align="justify">
O objetivo do problema "Top k elementos" é encontrar os k itens mais valiosos de uma coleção de dados, neste caso, encontrar as palavras mais frequentes de um determinado texto. Esse é um clássico exemplo de um problema que pode ser solucionado utilizando as estruturas de hash e heap. Esse algoritmo é uma combinação eficiente do uso de hash para contar a frequência dos elementos e heap para manter a lista dos k elementos com maiores valores. Sua complexidade, caso implementado adequadamente, é de O(nlogk), onde n é o tamanho da coleção de dados e k o número de itens mais relevantes.

## Lógica usada
<p align="justify">
Para resolver esse problema foi utilizado a hash para contar a frequência de todos os itens, enquanto o heap se aplica na manutenção de uma lista dos k itens de maior valor. Para implementar a tabela hash foi usada a biblioteca <i>unordered_map</i> que permite criar uma hash com mais facilidade. Para implementar a heap foi usada a biblioteca <i>queue</i> utilizando a priority_queue como estrutura. Por fim foi usado uma struct <i>Item</i> para armazenar uma palavra e sua frequencia.

### Hash
<p align="justify">
Como foi dito, para implementar a tabela hash foi usado a estrutura <i>unordered_map</i> que é uma classe de contêiner da biblioteca padrão do C++. Esse tipo de estrutura é usado para armazenar pares de chave-valor, onde cada chave é única e mapeia para um valor correspondente. O <i>unordered_set</i> oferece acesso rápido aos valores com base em suas chaves. Neste caso as chaves são do tipo string (representando as palavras) e os valores são do tipo int (representando as frequências das palavras).  Se a palavra já estiver presente na tabela, sua frequência é incrementada. Se não estiver presente, uma nova entrada é criada com frequência 1.

<p align="justify">
Como em qualquer tabela de dispersão, pode ocorrer colisões quando duas chaves diferentes geram o mesmo valor de hash. As técnicas para lidar com colisões variam, mas a biblioteca padrão do C++ geralmente utiliza o método de "encadeamento" para resolver essas situações. No método de encadeamento, cada posição da tabela de dispersão contém uma lista ligada de elementos que possuem o mesmo valor de hash. Quando ocorre uma colisão, um novo elemento é simplesmente adicionado à lista ligada correspondente. O encadeamento é uma técnica eficaz para lidar com colisões, mas ele pode causar aumento no uso de memória devido à necessidade de armazenar as listas ligadas. No entanto, essa abordagem oferece um bom desempenho médio para inserção, busca e remoção de elementos, tornando o unordered_map uma estrutura de dados poderosa e versátil para lidar com mapeamentos de chave-valor. 

### Heap
<p align="justify">
Uma heap é uma estrutura de dados fundamental que organiza um conjunto de elementos de forma hierárquica, de modo que o elemento pai tenha um valor maior ou menor (dependendo do tipo de heap) do que seus filhos. A heap é frequentemente usada para implementar filas de prioridade, onde os elementos são acessados com base em sua prioridade relativa, o que foi o caso deste trabalho, já que foi usada uma priority_queue que usa uma heap como sua estrutura de armazenamento subjacente. Essa heap garante que os elementos sejam organizados de acordo com a prioridade, com o elemento de maior (ou menor) prioridade no topo. No contexto do código, a heap foi usada para manter os "k" elementos mais valiosos (mais frequentes) durante o processo de contagem de frequência das palavras. Isso permitiu que fosse identificado rapidamente os elementos mais valiosos em termos de frequência à medida que processa as palavras do texto.

### Estrutura do codigo
<p align="justify">
O codigo consiste em 5 loops principais, sendo dois para leitura dos arquivos de texto, um para ler o arquivo de stop words, que são palavras que não devem ser contabilizadas, um para preencher a heap e outro apenas para printar os k elementos mais valiosos. Os loops de leitura leem linha por linha dos arquivos de dados, para cada linha é criado um fluxo de string e um token para armazenar cada palavra. Após isso existe outro loop dentro deste loop que lê cada token do fluxo de string e insere na hash junto com sua frequencia que é incrementada dentro do loop tambem. Após esse processo de leitura dos arquivos e de inserção na hash, existe outro loop que lê o arquivo de stop words e remove elas da hash usando a função erase. 

<p align="center">
<img height="600px" width="600px" src="imagens/leitura.png"/>
<p> </p>

### Tratamentos
<p align="justify">
Antes de cada palavra ser inserida, ela passa alguns tratamentos, sendo um para remover os sinais de pontuação, dois para transformar todas as letras maiusculas para minusculas e um para tratar caracteres estranhos, além de um para tratar caracteres estranho. Para usar esses tratamentos foi necessario incluir a biblioteca <i>algorithm</i> que contém a função remove_if, usada para remover elementos de uma sequência que atendem a uma determinada condição e a função ispunct que é usada para determinar se um caractere é um caractere de pontuação (por exemplo, vírgula, ponto, ponto-e-vírgula, etc.). Já a função transform é usada para aplicar uma transformação a cada elemento em uma sequência (como um vetor, uma string, etc.) e armazenar os resultados em outra sequência ou na mesma sequência. No caso deste codigo, ela esta sendo usada para converter todos os caracteres do token para letras minúsculas, usando a função tolower como argumento. Essa transformação garante que palavras com diferentes caixas (maiúsculas/minúsculas) sejam tratadas como iguais. Além disso existe uma função criado no codigo que trata apenas os caracteres acentuados, transformando todos em minusculos, já que a conversão de caracteres acentuados entre maiúsculas e minúsculas nem sempre é direta devido às diferenças entre os conjuntos de caracteres ASCII e Unicode, além da que a forma de representar um caracter acentuado é diferente de uma representação de um caracter normal. Ainda existe outra função criada no código para tratar apenas de um caracter em espedifico, neste caso o travessão. A função que remove todos os sinais de pontuação não consegue remover o travessão,  

## Resultado

## Conclusão

## Compilação e Execução

Esse pequeno exemplo possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |
