Uses Crt;
type
  Zap = Record  {��������  ������ � ���������������}
    FIO: string[15];
    Adr: string[30];              
  End;
  TreePtr = ^Tree;{�������� ���� ������}
  Tree = Record 
    Data: Zap;
    Left, Right: TreePtr;                
  End;

var
  Top: Treeptr;
  Z: Zap;
  Level, N, i: Integer;
  Number: Integer;

function AddTree(Top: TreePtr; Newnode: Zap): TreePtr;
begin
  if Top = nil THEN 
  begin
    New(Top);
    Top^.Data := Newnode;
    Top^.Left := nil;
    Top^.Right := nil; 
  end
  ELSE
  if Top^.Data.Fio > Newnode.Fio Then Top^.Left := AddTree(Top^.Left, Newnode)
  Else Top^.Right := AddTree(Top^.Right, Newnode);
  Addtree := Top
end;

procedure OrgTree;
begin
  Writeln('����������� ��������� ����������� ������');
  Writeln('��� ������ �� ��������� ������� ������ * ');
  Writeln('======================================== ');
  Top := nil;
  while True Do 
  begin
    Writeln('������� ������� � �������� ���������������');
    Readln(Z.Fio);
    Writeln('������� ����� ���������������');
    Readln(Z.Adr);
    if Z.Fio = '*' Then Exit;
    Top := Addtree(Top, Z); 
  end
end;

procedure DobL;
begin
  Writeln('����������� ��������� ���������� �����');
  Writeln('��� ������ �� ��������� ������� ������ * ');
  Writeln('======================================== ');
  Writeln('������� ������� � �������� ���������������');
  Readln(Z.Fio);
  Writeln('������� ����� ���������������');
  Readln(Z.Adr);
  if Z.Fio = '*' Then Exit;
  Top := Addtree(Top, Z); 
end;

procedure Prosmotr(Top: TreePtr);{��������� ��������� �������� ����� ������ ����� �������}
begin
  if Top <> nil Then 
  begin
    Prosmotr(Top^.Left);
    Writeln(i, ' ', Top^.Data.Fio, ' ', Top^.Data.Adr);
    i := i + 1;
    Prosmotr(Top^.Right)
  end; 
end;

procedure Otobr(Top: TreePtr; Otstup: Integer);{��������� ����������� ��������� ������.       
������ ������������ ���������� �� 90 �������� ������ ������� �������. 
���� ������, ����������� �� ����� ������, ������������ �  ���������� �������� �� ���� ������.}
begin
  if Top <> nil Then 
  begin
    Otstup := Otstup + 3;
    Otobr(Top^.Right, Otstup);
    Writeln(' ':Otstup, Top^.Data.Fio);
    Otobr(Top^.Left, Otstup); 
  end
end;

procedure NodeCount(Top: TreePtr; Level: Integer; var N: Integer);{��������� �������� ���������� ������ ������ Level}
begin
  if (Level >= 1) and (Top <> nil) Then 
  begin
    if Level = 1 Then N := N + 1;
    NodeCount(Top^.Left, Level - 1, N);
    NodeCount(Top^.Right, Level - 1, N); 
  end
end;

{==============�������� ���������================}

begin
  repeat
    ClrScr;
    Writeln('1-����������� ��������� ������');
    Writeln('2-���������� ����� � ������');
    Writeln('3-�������� ������');
    Writeln('4-������� ���������� ������ �� n-o� ������');
    Writeln('5-�����');
    Writeln('-------------------------------');
    Writeln('������� ����� ������ ����');
    Readln(Number);
    case Number Of
      1: OrgTree;
      2: Dobl;
      3:
        begin
          Writeln('����������� ��������� ��������� ������');
          Writeln('======================================== ');
          i := 0;
          Prosmotr(Top);
          Otobr(Top, 1);
          Writeln('������� ������� Enter');
          Readln
        end;
      4:
        begin
          Writeln('����������� ��������� �������� ����������');
          Writeln('������ �� n-�� ������');
          Writeln('======================================== ');
          Write('������� �������� ������-->');
          Read(Level);
          N := 0;
          NodeCount(Top, Level, N);
          Writeln;
          Writeln('�� ������ ', Level, ' ��������� ', N, ' ������');
          Writeln('������� ������� Enter');
          ReadKey
        end;
    End; 
  until Number = 5; {����� �� �����, ���� ������� 5}
end.