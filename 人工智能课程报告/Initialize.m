%Initialize���������Զ����һ�����������ڳ�ʼ��Ⱦɫ�塣
%�������������һ��forѭ����ÿ�������Ⱦɫ����������ֵ��
%������chrom_range�����޶��ڱ����涨������֮�ڡ�
function chrom_new = Initialize(N, N_chrom, chrom_range)
chrom_new = rand(N, N_chrom);
for i = 1:N_chrom %ÿһ�г��Ϸ�Χ
    chrom_new(:, i) = chrom_new(:, i)*(chrom_range(2, i)-chrom_range(1, i))+chrom_range(1, i);
end