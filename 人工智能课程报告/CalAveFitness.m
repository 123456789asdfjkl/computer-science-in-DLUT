%CalAveFitness�������ڼ��㵱ǰ��Ⱥ�е�ƽ����Ӧ�ȡ�
function fitness_ave = CalAveFitness(fitness)
[N ,~] = size(fitness);
fitness_ave = sum(fitness)/N;