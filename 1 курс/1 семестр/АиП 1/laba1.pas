Var a,b,x,z:real;
flag:boolean;
Begin
  Writeln('������� a');
  Readln(a);
  Writeln('������� x');
  Readln(x);
  Writeln('������� b');
  Readln(b);
  
  flag:=true;
  if x<=a then z:=sin(abs(x))
  else if x>=b then
    begin
      if cos(exp(x))<>0 then z:=tan(exp(x))
      else
        begin
          Writeln('�� ������ � ���');
          flag:=false;
        end;
    end
       else z:=cos(abs(x));
  
  if flag then writeln('��� x=',x,' �������� ������� z=',z:2:2);
  Writeln('������� <Enter>'); Readln
  End.
        