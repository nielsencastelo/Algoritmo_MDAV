% Fun��o que faz a mesma a��o da fun��o find do Matlab
% Encontra o elemento no vetor e retorna sua posi��o
% Data: 15/12/2013
% Autor: Nielsen C. Damasceno
% Entrada:  vetor - � o vetor de pesquisa
%           num - � o valor que deseja encontrar no vetor
% Sa�da:    
%           result - vetor posi��o onde os elementos foram encontrados
function result = encontrar(vetor,num)
    
    result = zeros(1,1);
    ele = 1;
    for j = 1 : length(vetor)
        if (vetor(j) == num)
            result(ele) = j;
            ele = ele + 1;
        end
    end
end