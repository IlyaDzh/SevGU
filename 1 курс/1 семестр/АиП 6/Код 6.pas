Uses Crt;
Type
  aeroflot = record  {������ ������}
             Pynkt: string[15];  {����� ����������}
             Numb: integer;  {����� �����}
             Tip: string[15];  {��� ��������} 
             End;
Var
  f: file of aeroflot;
  Elem1, Elem2: aeroflot;
  number: integer;

      {�������� �����}
procedure Create_file;
begin
  Seek(f, FileSize(f));
  Writeln('������� �������� � ������');
  Writeln('��� ������ ������ �������� ������ ���������� ����������� ������ *');
  Writeln('----------------------------------------------------------------');
  while True Do
  begin
    Write('������� �������� ������ ���������� �����: '); 
    Readln(Elem1.Pynkt); 
    if Elem1.Pynkt = '*' Then Break;
    Write('������� ����� �����: '); 
    Readln(Elem1.Numb); 
    Write('������� ��� ��������: '); 
    Readln(Elem1.Tip);  
    Writeln('-----------------------');
    Write(f, Elem1)
  end
end;

      {���������� �� ������ ����������}
procedure Sort_file;
var
  i, j: integer;
begin
  Seek(f, 0);
  for i := filesize(f) - 1 downto 1 do
    for j := 0 to i - 1 do
    begin
      Seek(f, j);
      Read(f, Elem1, Elem2);
      if Elem1.Pynkt > Elem2.Pynkt then
      begin
        Seek(f, j);
        Write(f, Elem2, Elem1);
      end
    end
end;

      {����� �����}
procedure Print_file;
begin
  Seek(f, 0);
  Writeln('������ ���������� ':20, '| ', '����� �����':5, ' |', '��� ��������':13);
  Writeln('  ----------------------------------------------');
  while not eof(f) do
  begin
    Read(f, Elem1);
    Writeln(Elem1.Pynkt:20, '| ', Elem1.Numb:11, ' |', Elem1.Tip:13);
  end;
  Readkey;
end;

      {����� ���������� �� ���� �������}
procedure Search_tip;
var
  Found: boolean;
  S_tip: string[15];  {������ � �����}
  a: aeroflot;
begin
  write('������� ��� �������: ');
  read(S_tip);
  assign(f, 'aeroflot.txt');
  reset(f);
  Found:= false;
  writeln('  ����� ���������� | ����� �����');
  Writeln('  ------------------------------');
  while not eof(f) do
  begin
    read(f, a);
    with a do
      if a.tip = S_tip then
      begin
        write(a.pynkt:18);
        writeln(' | ', a.numb:11);
        Found:= true;
      end;
  end;
  if not Found then write('�������� ������� ���� �� �������.');
  Readkey;
end;

      {�������� ���������}
Begin
  Assign(f, 'aeroflot.txt');
  {$I-}
  Reset(f);
  {$I+}
  Rewrite(f);
  while True Do 
  begin
    ClrScr;
    Writeln('1-�������� �����');
    Writeln('2-���������� ����� �� ������ ����������');
    Writeln('3-����� ����������� �����');
    Writeln('4-����� ���������� �� ���� �������');
    Writeln('5-�����');
    Writeln('-------------------------------');
    Writeln('������� ����� ������ ����:');
    Readln(Number);
    case Number Of
      1: Create_file;  {�������� �����}
      2: Sort_file;  {���������� �����}
      3: Print_file;  {�������� �����}
      4: Search_tip;  {����� �� ���� �������}
      5: Exit  {����� �� �����} 
    end
  end; 
End.