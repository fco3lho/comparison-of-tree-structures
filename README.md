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
