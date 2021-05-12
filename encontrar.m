% Função que faz a mesma ação da função find do Matlab
% Encontra o elemento no vetor e retorna sua posição
% Data: 15/12/2013
% Autor: Nielsen C. Damasceno
% Entrada:  vetor - é o vetor de pesquisa
%           num - é o valor que deseja encontrar no vetor
% Saída:    
%           result - vetor posição onde os elementos foram encontrados
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