Uses Crt;
type
  Zap = Record  {��������  ������ � ��������}
    Fam: string[13];
    Imya: string[10];
    Otch: string[13];
    Mat: string[3]; 
    Ist: string[3];
    Fiz: string[3];
  End;
  TreePtr = ^Tree;{�������� ���� ������}
  Tree = Record 
    Data: Zap;
    Left, Right: TreePtr;                
  End;

var
  Top, p1: Treeptr;
  Z: Zap;
  i: Integer;
  x: string;
  Number: Integer;

function AddTree(Top: TreePtr; Newnode: Zap): TreePtr;
begin
  if Top = nil THEN {���� ������ ������ �� ������ ��� ������}
  begin
    New(Top); {�������� ������}
    Top^.Data := Newnode; {��������� ������}
    Top^.Left := nil; {�������� ��������� ������}
    Top^.Right := nil; {�������� ��������� �������}
  end
  ELSE
  if Top^.Data.Fam > Newnode.Fam Then Top^.Left := AddTree(Top^.Left, Newnode) {���� ������ ����� �� � ����� ���������}
  Else Top^.Right := AddTree(Top^.Right, Newnode); {���� ������ ����� �� � ������ ���������}
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
    Writeln('������� �������:');
    Readln(Z.Fam);
    Writeln('������� ���:');
    Readln(Z.Imya);
    Writeln('������� ��������:');
    Readln(Z.Otch);
    Writeln('������� ������ �� ����������:');
    Readln(Z.Mat);
    Writeln('������� ������ �� �������:');
    Readln(Z.Ist);
    Writeln('������� ������ �� ������:');
    Readln(Z.Fiz);
    Writeln('======================================== ');
    if Z.Fam = '*' Then Exit;
    Top := Addtree(Top, Z); 
  end
end;

procedure Prosmotr(Top: TreePtr);{�������� ����� ����� �� �����}
begin
  if Top <> nil Then
  begin
    Prosmotr(Top^.Left);
    Writeln(i, ' ', Top^.Data.Fam, ' ', Top^.Data.Imya, ' ', Top^.Data.Otch, ' ', Top^.Data.Mat, ' ', Top^.Data.Ist, ' ', Top^.Data.Fiz);
    i := i + 1;
    Prosmotr(Top^.Right)
  end; 
end;

procedure Otobr(top: TreePtr; Otstup: Integer);{����� ������}
var
  i: Integer;
begin
  if Top <> nil Then
  begin
    Otobr(Top^.Right, otstup + 4);
    for i := 1 To otstup Do Write(' ');
    Writeln(Top^.Data.Fam);
    Otobr(Top^.Left, otstup + 4);
  end;
end;

function Search(Top: Treeptr; x: string): Treeptr;
var
  p: Treeptr;
begin
  if Top = nil then
  begin
    Search := nil; 
    exit;
  end;
  if x = Top^.Data.Fam then  {���� ������� ������� ����� ����� ������ �� }
    p := Top  {���������� ��� ����� }
     else
  if x < Top^.Data.Fam then
    p := Search(Top^.Left, x) {�� ���� ��� � ����� ���������}
  else 
    p := Search(Top^.Right, x);  {���� � ������ ��������� }
  Search := p; {����������� ���������� � ������ ������� ��������� ������}
end;

{==============�������� ���������================}

begin
  repeat
    ClrScr;
    Writeln('1-�������� ������');
    Writeln('2-����� ������');
    Writeln('3-����� �� �������');
    Writeln('4-�����');
    Writeln('-------------------------------');
    Writeln('������� ����� ������ ����');
    Readln(Number);
    case Number Of
      1: OrgTree;
      2:
        begin
          Writeln('����������� ��������� ��������� ������');
          Writeln('======================================== ');
          i := 0;
          Prosmotr(Top);
          Otobr(Top, 1);
          Writeln('������� ������� Enter');
          Readln
        end;
      3:
        begin
          Writeln('������� ������� ��� ������:');
          Readln(x);
          p1 := Search(Top, x);
          if p1 <> nil then
            Writeln('������.')
          else Writeln('������ �������� ���.');
          Readkey;
        end;
    End; 
  until Number = 4;
end.