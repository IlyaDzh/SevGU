program lab2;
const e = 0.0001;
var t, xn, xk, x, s, h: real;
    n: integer;
begin
    repeat
    write('������� ������ ��������� � (-1;1) xn=');
    readln(xn);
    until abs(xn) < 1;
    repeat
    write('������� ����� ���������, ', xn:0:2, '<xk<1 xk=');
    readln(xk);
    until (xk > xn) and (xk < 1);
    repeat
    write('������� ��� ���������, h<', xk - xn:0:2, ' h=');
    readln(h);
    until h < xk - xn;
    x := xn;
    writeln('������������� ������� F(x)=ln((1+x)/(1-x)),');
    writeln('�� ��������� � ', xn:0:1, ' �� ', xk:0:1, ' � ����� ', h:0:2);
    writeln;
    writeln('    -------------------------');
    writeln('    |   X   |    S    |  n  | ');
    writeln('    -------------------------');
    while x <= xk + h / 2 do
      begin
       n := 0;
       t := x;    {������� ���� ����}
       s := t;    {����� ��� n=0}
       while abs(t / (2 * n + 1)) >= e do   {���� ��������� ���� ������ ��������}
          begin
           n := n + 1;    {����������� �����}
           t := t * x * x;    {��������� �� x^2}
           s := s + t / (2 * n + 1);    {��������� � ����� �� �������� �����}
          end;
       writeln('    |', x:6:2, ' |', s:8:4, ' |', n:5, '|');
       x := x + h;
      end;
     writeln('    -------------------------');
     readln
end.