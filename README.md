Detecção de estruturas MQ (Mínimos Quadrado)
============================================

Este algoritmo tem a finalidade de encontra a estrutura usando mínimos quadrados. Não sendo necessário parâmetro de entrada para o ruído em que a estimativa de função de ordem 2.

Para usar esta função e necessário três paramentos de entrada que será auxiliado com a ajuda da ferramenta computacional MATLAB. O primeiro parâmetro o próprio valor da equação, que pode ser simulado como um sistema dinâmico usando a função “Lsim” dever ser usada neste quesito com o auxílio da criação de uma função de transferência. O segundo os valores randômicos que servira tanto para a simulação do sistema linear no MATLAB como para esta função. E por último a ordem da equação, usaremos a de 2ª ordem que e o mais correto para todos os casos.
Passos para executar o algoritmo com os dados de entrada simulados pelo MATLAB:

<code>
s = tf('s')
gs = 1/(s^2+2*s+1)
</code>

Essa expressão cria um modelo de transferência de um entrada e um saída resultando em uma sistema como este:

<code>
Transfer function:
1/
s^2 + 2 s + 1
</code>

E depois converte o sistema de discreto para contínuos de tempo de amostra igual a 0.1s:

<code>
gz = c2d(gs,0.1)
</code>

Um vetor de número randômicos será a nossa entrada aleatória para a simulação de sistemas lineares com intervalos de 0 a 1 distribuídos de maneira uniforme, quanto maior o quantidade de termos do vetor mais preciso será o valor dos coeficientes, neste tutorial será usado apenas 20 elementos:

<code>
u = rand(20,1);
</code>

Agora só falta a simulação de um sistema linear com o sistema de tempo continua armazenado na variável gz e valores arbitrários do vetor u:

<code>
y = lsim(gz,u)
</code>

Obitidos os dados simulados agora e só transferir para o algoritmo em função. Os dados devem ser colocados em forma de vetores e a variável que recebera os valores do tempo simulado e dos valores randômicos devem esta declaras como matriz.
Na função principal(main) e necessário apenas importar a biblioteca rec.h para para ter acesso ao método de detecção. Como estamos trabalhando com classes vamos criar o objeto usando:

<code>
rec nome-novo-objeto;
</code>

Com isso o usuário terá acesso ao método digitando:

<code>
nome-novo-objeto.simu(y,u,n);
</code>

y= vetor simulado;
u= vetor randômico;
n= ordem do sistema;

DEPENDENCIAS
==============
*BILBIOTECA MATRIX;

*PROGRAMA MATLAB.
