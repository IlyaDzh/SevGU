const
  Razd = ['.', ',', ':', ';', '!', '?', '-', ' '];
  t = '123.txt';
var
  F: Text;
  S, S1, Sw1, Sw2: String;
  i, j, Pos1, Len: Integer;

begin
  Assign(F, t);
  Reset(F);
  Writeln('�����:');
  
  while not Eof(f) do 
  begin
    Readln(F, S);
    
    Len := Length(S);   {���������� �����}
    Sw1 := '';   {������� �����}
    Sw2 := '';   {������� ������ ����� (������ ������ ����� � �����)}
    Pos1 := 0;   {�������������� ������}
    S1 := '';   {������� ����}
    j := 0;
    
    for i := 1 to Len do 
    begin
      if S[i] in Razd then Continue;   {���������� �����������}
      if (i = 1) or (S[i - 1] in Razd) then Pos1 := i;   {������ �����}
      if (i = Len) or (S[i + 1] in Razd) then    {����� �����}
      begin
        Inc(j);   {������� ����}
        Sw1 := Sw2;
        Sw2 := Copy(S, Pos1, i - Pos1 + 1);
        if j mod 2 = 0 then   {�������� ����}
        begin
          if S1 <> '' then S1 := S1 + ' ';
          S1 := S1 + Sw2 + ' ' + Sw1;
        end;
      end;
    end;
    
    if (j > 0) and (j mod 2 <> 0) then   {������ ���������� �����, ���� ��� ����}
    begin
      if S1 <> '' then S1 := S1 + ' ';
      S1 := S1 + Sw2;
    end;
    Writeln(S1);
  end;
  
  Close(F);
  Readln;
end.