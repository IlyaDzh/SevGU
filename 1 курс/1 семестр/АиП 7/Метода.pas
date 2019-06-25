Uses Crt;
type
  Data = Record     {��������  ������ � ���������������}
    FIO: string[15];
    Adr: string[30]
  End;
  Ukaz = ^Query;{�������� ��������� �� ������� �������}
  Query = Record 
    Inf: Data;
    Next: Ukaz                   
  End;

var
  NewE, Left, Right, Temp: Ukaz;    {���������}
  Z: Data;    {������, ����������� � �������}
  Key: Char;{����� ������ ���� ���������}

procedure Org;{��������� ����������� �������}
begin
  Writeln('����������� ��������� ����������� �������');
  Writeln('��� ������ �� ��������� ������� ������ * ');
  Writeln('======================================== ');
  Writeln('������� ������� � �������� ���������������');
  Readln(Z.Fio);
  Writeln('������� ����� ��������������� ');
  Readln(Z.Adr);
  if Z.Fio = '*' Then Exit;    {����� �� ��������� ��� ����� '*'}
  
  New(NewE);               {�������� ������ ��������}
  NewE^.Inf.Fio := Z.Fio;    {���������� ��� �����}
  NewE^.Inf.Adr := Z.Adr;
  NewE^.Next := nil;
  Right := NewE;    {Right - ��������� ������ �������}
  Left := NewE;    {Left - ��������� ������ �������}
  while True Do            {���������� ���� �� ��������}
  begin
    Writeln('������� ������� � �������� ���������������');
    Readln(Z.Fio);
    Writeln('������� ����� ���������������');
    Readln(Z.Adr);
    if Z.Fio = '*' Then Exit;
    New(NewE);
    NewE^.Inf.Fio := Z.Fio;
    NewE^.Inf.Adr := Z.Adr;
    NewE^.Next := nil;
    Right^.Next := NewE;    {����� � ���������� ���������}
    Right := NewE{����������� ��������� ������ �������}
  end
end;

procedure Dob;{���������� �������� � ����� �������}
begin
  Writeln('������� ������� � �������� ���������������');
  Readln(Z.Fio);
  Writeln('������� ����� ���������������');
  Readln(Z.Adr);
  if Z.Fio = '*' Then Exit;
  New(NewE);NewE^.Inf.Fio := Z.Fio;
  NewE^.Inf.Adr := Z.Adr;
  NewE^.Next := nil;
  if Right = nil Then           {���� ����������� ������ �������, ��} 
    Left := NewE     {���������������� ��������� ������}      
  Else Right^.Next := NewE;    {����� �������� � ����� �������}
  Right := NewE; 
end;

procedure Udal;{��������� ���������� ��������}
begin
  Writeln('����������� �������� ������� �������');
  Writeln('������� ������� Enter');
  Readln;
  if Left <> nil Then    {���� ������� �� ������, ��} 
  begin
    Temp := Left;     {���������� ��������� ��  ������ �������}
    Left := Left^.Next;    {��������� ������ ������� �� 2-�� �������}
    Dispose(Temp);     {o���������� ������ �� ��������� ��������}
    if Left = nil Then      {���� ������� ��������� �������, ��} 
      Right := nil;      {��������� �� ����� ������� ����� Nil}
  end
end;

procedure Prosmotr;{��������� ��������� �������}
var
  i: integer;{�������� ����������� �� ������ � ������}
begin
  Writeln('������� �������� ��������� ��������:');
  Temp := Left;
  i := 1;
  while Temp <> nil Do 
  begin
    Writeln(i, ' ', Temp^.Inf.Fio, ' ', Temp^.Inf.Adr);
    Temp := Temp^.Next;
    i := i + 1; 
  end;
  Writeln('������� ������� Enter');
  Readln; 
end;

     {==============�������� ���������================}

begin
  Right := nil;
  Left := nil;
  repeat
    ClrScr;   
    Writeln('1-����������� �������');
    Writeln('2-���������� �������� � �������');
    Writeln('3-�������� �������� �� �������');
    Writeln('4-�������� �������');
    Writeln('5-�����');
    Writeln('-------------------------------');
    Writeln('������� ������� �� 1 �� 5');
    Key := ReadKey;    {���������� ���� ������� �������}
    case Key Of    {����� ����������� ��������� �� ������} 
      '1': Org;
      '2': Dob;
      '3': Udal;
      '4': Prosmotr;        
    End
  until Key = '5'{����� �� ���������}
end. 