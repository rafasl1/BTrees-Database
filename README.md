# BTrees-Database
Database created with C++ using B Trees

<p>Estudo Programa 1 para a disciplina de Algoritmos e Estrutura de Dados 2 (ACH2024).</p>
<p>O EP consistia em criar um banco de dados que implementa uma árvore B como estrutura de dados. O BD deveria realizar as seguintes operações: </p>
<ul>
  <li>Inserção: para inserir um registro</li>
  <li>Atualização: dado um cpf, atualizar o registro dono</li>
  <li>Deleção: deletar um registro</li>
  <li>Busca: buscar por um registro no banco através de um cpf</li>
  <li>Imprimir fragmentação: razão entre o número de bytes vazios e o número de bytes total do arquivo de dados</li>
</ul>
<p>Os cpf deveriam ser armazenados no arquivo de índices, e os dados referentes a ele seriam armazenados no arquivo de dados, que possui os campos: nome, sobrenome, curso, sexo e data de nascimento.</p>
<p>O intermédio entre a memória secundária (arquivo de índices) e memória principal é feita por um buffer que deveria receber os dados do arquivo e colocá-los em variáveis, para depois serem colocadas no registro desejado.</p>
