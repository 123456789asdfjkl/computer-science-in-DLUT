% Խ�纯��IfOut�������ǿ�������Խ�绹����Խ�磬
% �������Խ�磬���ýڵ�ֵ�����������ޣ�
% �������Խ�磬���ýڵ�ֵ�����������ޡ�
function c_new = IfOut(c, range)
if c<range(1) || c>range(2)
    if abs(c-range(1))<abs(c-range(2))
        c_new = range(1);
    else
        c_new = range(2);
    end
else
    c_new = c;
end