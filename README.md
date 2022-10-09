# Comparação das estruturas de árvore

[![Linguagem C++](https://img.shields.io/badge/Linguagem-C%2B%2B-green.svg)]()
[![requirement](https://img.shields.io/badge/IDE-Sublime%20Text-orange)](https://www.sublimetext.com)
![ISO](https://img.shields.io/badge/ISO-Linux-blueviolet)
![Contributions](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)

Elaborar arquivos que contenham 500, 5000, 50.000, 500.000 entradas numéricas do tipo ponto flutuante. Para tanto, tente evitar repetições de valores em grande escala para que possamos ter uma estrutura profunda. Considere produzir os menores a partir dos maiores volumes de forma randômica. Feito a isso, vamos testar os seguintes processos: 
<ol>
  <li>Qual o tempo gasto com pesquisa para um arquivo de entrada com 10.000 consultas. Considere como consulta a busca de um determinado número na estrutura escolhida. Para cada pesquisa, é preciso remover o elemento da árvore, retornando esse número para o usuário. Então, considere o processo de remoção como parte final do processo. </li>
  <li>Qual o tempo necessário para montar a estrutura em memória.</li>
  <li>Qual o ganho dessas estruturas ao compará-las a vetores ordenados e aplicados à pesquisa binária. Qual o tempo gasto com a ordenação do vetor? Foi possível produzi-lo em memória?</li>
  <li>Adotando como estrutura o map e unorder_map do C++, há ganhos maiores nesse processo de pesquisa?</li>
</ol>

## Conteúdo do README

<p align="center">
 <a href="#estruturas">Estruturas</a> •
 <a href="#funcionamento-da-aplicação">Funcionamento da aplicação</a> •
 <a href="#resultados">Resultados</a> •
 <a href="#conclusão">Conclusão</a> •
 <a href="#compila%C3%A7%C3%A3o-e-execu%C3%A7%C3%A3o">Compilação e execução</a> •
 <a href="#contatos">Contatos</a>
</p> 

## Estruturas

Neste tópico, será abordado a explicação sobre o funcionamento das estruturas usadas para comparação.

### Árvore binária de pesquisa

A árvore binária de pesquisa é uma estrutura muito eficiente para armazenar informações. Sua estrutura é adequada para situações quando há necessidade de considerar todos ou alguma combinação dos itens a seguir:

<ul>
  <li>Acesso direto e sequencial eficiente</li>
  <li>Facilidade de inserção e retirada de registros</li>
  <li>Boa taxa de utilização de memória</li>
  <li>Utilização de memória primária e secundária</li>
</ul>

A estrutura básica da árvore de pesquisa binária é formada por uma raiz R com seus filhos esquerdo e direito, onde todos os elementos menores ficam na subárvore esquerda e todos os elementos maiores ficam na subárvore direita. Exemplo:

<p align="center">
  <img align="center" src="imgs/binaryTree.png">
</p>

A árvore binária de pesquisa possue as seguintes características para sua implementação:

<ul>
  <li>O nível da raiz sempre é 0.</li>
  <li>Se um nó está no nível <i>i</i>, então, a raiz de suas subárvores esquerda e direita estão no nível <i>i + 1.</i></li>
  <li>A altura de um nó é o comprimento do caminho mais longo deste nó até um nó folha.</li>
  <li>A altura de uma árvore é a altura do seu nó raiz até a folha mais distânte da estrutura.</li>
  <li>O número de filhos de um nó denomina-se grau, com nós de grau zero chamados de folhas.</li>
</ul>

Pseudocódigo da estrutura básica de uma árvore binária de pesquisa:

```
Record
  key: type of key;
  value: type of value;
  {other informations}
end;
No
  reg: Record;
  left, right : No;
end;
```

Procedimento de pesquisa aplicável a árvore binária:

<ol>
  <li>Verificar se a árvore é diferente de <strong>null</strong>.</li>
  <li>Compare com a chave que está na raiz.</li>
  <li>Se a chave for menor, vá para a subárvore esquerda.</li>
  <li>Se a chave for maior, vá para a subárvore direita.</li>
  <li>Repita o processo recursivamente até que a chave procurada seja encontrada ou um nó folha seja atingido.</li>
</ol>

Pseudocódigo do método de pesquisa na árvore binária:

```
input : k → Investigated key
input : p → No
output: record in binary search tree

if p == null:
  print(’[Error]: Record does not present in the tree’)
  
else if k < p.reg.key:
  BinarySearch(k, p.left)
  
else if k > p.reg.key:
  BinarySearch(k, p.right)
  
else:
  return p.reg;
```

O procedimento para inserção de novos elementos na árvore leva em consideração as ações executadas pelo método de pesquisa. As condições a serem levadas em consideração para a derivação do método de pesquisa são:

<ul>
  <li>Se a árvore for <strong>null</strong>, então insira o elemento na raiz e faça os filhos esquerdo e direito iguais a <strong>null</strong>.</li>
  <li>Caso contrário, gere recursivamente chamadas ao método até que uma posição <strong>null</strong> seja alcançada. É nessa posição encontrada que o novo registro será inserido.</li>
</ul>

Pseudocódigo do método de inserção na árvore binária:

```
input : reg → record to save
input : p → No
output: binary search tree with the new record

if p == null:
  new(p);
  p.left = null;
  p.right = null;
  p.reg = reg;

else if reg.key < p.reg.key:
  Insert(reg, p.left)

else if reg.key > p.reg.key:
  Insert(reg, p.right)

else:
  print(’[Error]: Record is already presents!’);
```

<strong>Observação:</strong> Como estamos trabalhando com ponteiro é de extrema importância que não nos esqueçamos de iniciar nossa árvore. Caso isso não aconteça, um erro será gerado ao tentar realizar qualquer operação com a mesma.

Pseudocódigo do procedimento de inicialização:

```
input : root → start pointer of the tree
output: binary search tree initialized
root = null;
```

O método de remoção não é trivial. Considerando R como o nó a ser removido, então:

<ol>
  <li>Se R não tem filhos, então basta eliminá-lo.</li>
  <li>Se R tem um único filho, seu pai apontar para esse filho e elimine R.</li>
  <li>Se R tem dois filhos, substitua:
    <ul>
      <li>Pelo registro mais a direita da subárvore esquerda.</li>
      <li>Pelo registro mais a esquerda da subárvore direita.</li>
    </ul>
  </li>
</ol>

Para que o procedimento de remoção funcione corretamente, precisamos implementar dois estágios de operação, sendo eles <i>Retira</i> e <i>Antecessor</i>.

Pseudocódigo do procedimento predecessor:

```
input : root → start pointer of the tree
input : p → pointer in the tree
output: a pointer with predecessor

if root.right != null:
  predecessor(p, root.right)

else:
  p.reg = root.reg;
  p = root;
  root = root.left;
  dispose(p);
```

Pseudocódigo do procedimento de remoção:

```
input : t → start pointer of the tree
input : reg → record to remove
output: binary search tree without the record

if t == null:
  print(’[Error]: The searched record is not in the binary tree’)

if reg.key < t.reg.key:
  Remove(reg, t.left)

if reg.key > t.reg.key:
  Remove(reg, t.right)

if t.right == null
  aux = t;
  t = t.left;
  dispose(aux);

if t.left != null:
  predecessor(t, t.left);
  
aux = t;
t = t.right;
dispose(aux);
```

Quanto à análise de custo computacional da árvore binária de pesquisa, para uma pesquisa bem sucedida, temos:

<ul>
  <li><strong>Melhor caso:</strong> <i>O(1)</i></li>
  <li><strong>Pior caso:</strong> <i>O(n)</i></li>
  <li><strong>Caso médio:</strong> <i>O(log n)</i></li>
</ul>

Como pode ser observado, o tempo de execução depende muito da forma como o conjunto de dados está armazenado. Para o pior caso basta que os dados estejam ordenados de forma crescente ou decrescente. Nesses casos, o custo médio para se
encontrar um elemento é equivalente ao custo do método de pesquisa sequencial, ou seja, $$O(\frac{n+1}{2})$$


### Árvore AVL

As árvores binárias de pesquisa têm uma grave desvantagem que pode afetar seu desempenho. Essa desvantagem está ligada diretamente com o conjunto de dados, seu desempenho pode ser afetado pela forma com que o conjunto é apresentado para o método de inserção da árvore.

Para resolver esse problema precisamos gerar o que chamamos de balanceamento da árvore. Exemplo:

<p align="center">
  <img align="center" src="imgs/balancedTreeExample.png">
</p>

Para evitar o problema descrito anteriormente aplicamos um novo conceito na estrutura da árvore binária, o balanceamento. 

Uma generalização da árvore binária, no entanto, balanceada é a árvore AVL (Adelson Velsky e Landis). O objetivo da técnica proposta na AVL está em manter as subárvores esquerda e direita com altura aproximada. Este fato nos permite avaliar sua altura em <i>log n</i>. Para garantir o balanceamento, a AVL calcula o desequilíbrio a partir da profundidade (nível) do nó mais distante de cada subárvore. Caso esse se encontre com um índice de desbalanceamento maior ou igual a 2, a árvore é recomposta por rotações.

As técnicas para balanceamento são as seguintes:

<ul>
  <li>Para todo nó, as alturas de suas subárvores (direira e esquerda) devem diferenciar no máximo em uma unidade de altura.</li>
  <li>Garantindo o balanceamento, as consultas, inserções e remoções apresentarão custo em <i>O(log n)</i>.</li>
</ul>

<p align="center">
  <img align="center" src="imgs/treeAVL.png">
</p>

Para se obter o balanceamento em uma AVL, o primeiro passo é calcular o fator de balanceamento para cada nó. Os passos para obter o fator de balanceamento são:

<ol>
  <li>Comece atribuindo zero para todo nó folha da árvore.</li>
  <li>Suba um nível e some a subárvore a direita e subárvore esquerda.</li>
  <li>Verifique se o resultado do calculo excede em uma unidade. Se exceder, a árvore estará desbalanceada e deve ser recomposta.</li>
</ol>

Por questões de eficiência, o valor obtido do balanceamento, para cada nível processado, é armazenado junto aos dados de cada nó, sendo esse atualizado a cada operação.

Todo processo de remoção em uma árvore AVL gera como resultado uma árvore balanceada como retorno. Logo, é preciso verificar a cada remoção a necessidade de se executar tal procedimento.

As operações de remoção e inserção podem causar desbalanceamento na estrutura da árvore. Logo, é preciso executar operações sob essa estrutura para balancear novamente o conjunto de dados.

<ul>
  <li>A recuperação do balanceamento é realizado por operações chamadas de rotações.</li>
  <li>As rotações podem ser divididas em 4 configurações:
    <ol>
      <li>Rotação simples à esquerda.</li>
      <li>Rotação simples à direita.</li>
      <li>Rotação dupla à esquerda.</li>
      <li>Rotação dupla à direira.</li>
    </ol>
  </li>
</ul>

Pseudocódigo da rotação simples à direita:

```
input : t → root of the Tree
output: Balanced Tree
aux = t.left;
t.left = aux.right;
aux.right = t;
t.peso = MaxWeight(getWeight(t.left), getWeight(t.right)) + 1;
aux.peso = MaxWeight(getWeight(aux.left), t.peso) + 1;
t = aux;
```

Pseudocódigo da rotação simples à esquerda:

```
input : t → root of the Tree
output: Balanced Tree
aux = t.right;
t.right = aux.left;
aux.left = t;
t.peso = MaxWeight(getWeight(raizˆ .esquerdo), getWeight(raizˆ .direito)) + 1;
aux.peso := MaxWeight(getWeight(auxˆ .direito), raizˆ .peso) + 1;
raiz = aux;
```

Pseudocódigo da rotação dupla esquerda/direita:

```
input : t → root of the Tree
output: Balanced Tree
rotacaoSimplesEsquerda(t.left);
rotacaoSimplesDireita(t);
```

Pseudocódigo da rotação dupla direita/esquerda:

```
input : t → root of the Tree
output: Balanced Tree
rotacaoSimplesDireita(t.right);
rotacaoSimplesEsquerda(t);
```

Pseudocódigo da inserção:

```
input : t → root of the tree
input : item → new item
output: Tree with the new item inserted

if (t == NULL):
  new(t);
  t.item = item;
  t.weight = 0;
  t.left := NULL;
  t.right = NULL;

else if (item.key < t.item.key):
  inserir(item, t.left);

  if ((getWeight(t.left) - getWeight(t.right)) = 2):
    if (item.key < t.left.item.key):
      rotacaoSimplesDireita(t)
    else
      rotacaoDuplaEsquerdaDireita(t);
else if (item.key > t.item.key):
  inserir(item, t.right);

  if ((getWeight(t.right) - getWeight(t.left)) = 2):
    if (item.key > t.right.item.key):
      rotacaoSimplesEsquerda(t)
    else
      rotacaoDuplaDireitaEsquerda(t);
t.weight := MaxWeight(getWeight(t.left), getWeight(t.right)) + 1;
```

Concluindo, temos que:

<ul>
  <li>O balanceamento da árvore binária reduz o número médio de comparações necessárias para localizar qualquer elemento da árvore.</li>
  <li>As operações de inserção e remoção tendem a deixar a árvore desbalanceada. Assim, tem-se um custo adicional nesses passos para validar sempre o balanceamento.
</li>
  <li>Essa estrutura é uma boa opção quando os dados armazenados são requisitados muitas vezes após sua inserção na árvore.
</li>
</ul>













## Funcionamento da aplicação

## Resultados

## Conclusão

## Compilação e Execução

O repositório possui um arquivo <i>Makefile</i> que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:

<table align="center">
  <tr>
    <td><strong>Comando</strong></td>
    <td><strong>Função</strong></td>
  </tr>
  <tr>
    <td><code>make clean</code></td>
    <td>Apaga a última compilação realizada contida na pasta build.</td>
  </tr>
  <tr>
    <td><code>make</code></td>
    <td>Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta build.</td>
  </tr>
  <tr>
    <td><code>make run</code></td>
    <td>Executa o programa da pasta build após a realização da compilação.</td>
  </tr>
</table>

## Contatos

<div align="center"> 
  <a href="https://www.instagram.com/fco3lho/" target="_blank"><img src="https://img.shields.io/badge/-Instagram-%23E4405F?style=for-the-badge&logo=instagram&logoColor=white" target="_blank"></a>
  <a href = "mailto:felipecampos50123@gmail.com"><img src="https://img.shields.io/badge/-Gmail-%23333?style=for-the-badge&logo=gmail&logoColor=white" target="_blank"></a>
  <a href="https://www.linkedin.com/in/fco3lho/" target="_blank"><img src="https://img.shields.io/badge/-LinkedIn-%230077B5?style=for-the-badge&logo=linkedin&logoColor=white" target="_blank"></a>
