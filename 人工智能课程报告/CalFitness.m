%CalFitness�������Ǽ���chrom��ÿ���������Ӧ�ȣ������䱣����fitness�С�
function fitness = CalFitness(chrom, N, N_chrom)
fitness = zeros(N, 1);
%��ʼ������Ӧ��
for i = 1:N
    x = chrom(i, 1);
    y = chrom(i, 2);
    fitness(i) = 10*sin(x)+16*cos(y)+0.03*x.^2+0.02*y.^3;
end