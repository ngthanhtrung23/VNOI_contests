{$R-,S-,Q-,I-,O+}
const maxp = 620000;
var
  p,last,j,n,k,m,i,q,c: longint;
  next: array [0..300000,0..9] of longint;
  a: array [0..300000] of longint;
  st: string;
  b: array [0..maxp] of boolean;
begin
  read(n,k);
  fillchar(b,sizeof(b),True);
  b[1]:=False;
  m:=0;
  for i:=2 to maxp do
    if b[i] then
    begin
      q:=i;
      st:='';
      while q > 0 do
      begin
        st:=Chr(q mod 10+48)+st;
        q:=q div 10;
      end;
      for j:=1 to length(st) do
      begin
        inc(m);
        a[m]:=Ord(st[j])-48;
      end;
      dec(n);
      if n = 0 then break;
      c:=i+i;
      while c <= maxp do
      begin
        b[c]:=False;
        inc(c,i);
      end;
    end;
  fillchar(next,sizeof(next),0);
  for i:=m-1 downto 0 do
  begin
    for j:=0 to 9 do next[i,j]:=next[i+1,j];
    next[i,a[i+1]]:=i+1;
  end;
  last:=0;
  for p:=m-k downto 1 do
    for j:=9 downto 0 do
      if (next[last,j] > 0) and (m-next[last,j] >= p-1) then
      begin
        write(j);
        last:=next[last,j];
        break;
      end;
  writeln;
end.

