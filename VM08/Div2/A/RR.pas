PROGRAM VSTEPS;
CONST
  fi='';
  fo='';
  oo=14062008;
  maxn=100000;
VAR
  d:array[1..maxn] of longint;
  n:longint;
procedure readInput;
var
  f:text;
  k,i,u:longint;
begin
  assign(f,fi); reset(f);
  readln(f,n,k);
  for i:=1 to k do
    begin
      read(f,u);
      d[u]:=-1;
    end;
  close(f);
end;
procedure writeOutput;
var
  f:text;
begin
  assign(f,fo); rewrite(f);
  if d[n]=-1 then writeln(f,0)
  else writeln(f,d[n]);
  close(f);
end;
procedure solve;
var
  i:longint;
begin
  d[1]:=1;
  if d[2]<>-1 then d[2]:=1;
  for i:=3 to n do
  if d[i]<>-1 then
    begin
      if d[i-1]<>-1 then d[i]:=d[i-1];
      if d[i-2]<>-1 then d[i]:=(d[i]+d[i-2]) mod oo;
      if (d[i-1]=-1) and (d[i-2]=-1) then d[i]:=-1;
    end;
end;
BEGIN
  readInput;
  solve;
  writeOutput;
END.

