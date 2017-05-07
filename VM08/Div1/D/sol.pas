{$MODE OBJFPC}
{$R-,Q-}
{$M 1000000}
const
  fin='';
  fou='';
  maxn=51;
  maxm=26;
  hashkey=1234567;

type
  thash=^hashlink;
  hashlink=record
    now,pos,s,last,len:longint;
    v:boolean;
    next:thash;
  end;

var
  now,n,m:longint;
  a:string;
  hash:array[0..hashkey] of thash;
  start,finish,leneq,veq:array[1..maxm] of longint;

procedure dis(p:thash);
begin
  if p=nil then exit;
  dis(p^.next);
  dispose(p);
end;

function code(pos,s,last,len:longint):longint;
begin
  result:=(pos*10+s+last*100+len*1000);
  while result>=hashkey do dec(result,hashkey);
end;

function findf(pos,s,last,len:longint;var v:boolean):boolean;
var
  p:thash;
  c:longint;
begin
  c:=code(pos,s,last,len);
  if hash[c]<>nil then
    begin
      if hash[c]^.now<>now then hash[c]:=nil;
    end;
  p:=hash[c];
  while p<>nil do
    begin
      if (p^.pos=pos) and (p^.s=s) and (p^.last=last) and (p^.len=len) then
        begin
          v:=p^.v;
          exit(true);
        end;
      p:=p^.next;
    end;
  exit(false);
end;

procedure updatef(pos,s,last,len:longint;v:boolean);
var
  c:longint;
  p:thash;
begin
  c:=code(pos,s,last,len);
  new(p);
  p^.pos:=pos;
  p^.s:=s;
  p^.last:=last;
  p^.len:=len;
  p^.v:=v;
  p^.now:=now;
  if hash[c]<>nil then
    begin
      if hash[c]^.now<>now then hash[c]:=nil;
    end;
  p^.next:=hash[c];
  hash[c]:=p;
end;

function chkvalid(pos,s,last,len:longint):boolean;
var
  i:longint;
begin
  if len>pos then exit(false);
  for i:=pos-len+1 to pos do
    if (a[i]<>'?') and (a[i]<>chr(last+48)) then
      exit(false);
  for i:=1 to m do
    if (s shr (i-1) and 1=1) and (start[i]>pos) then exit(false);
  exit(true);
end;

var
  cur:longint;
  free:array[1..maxn] of longint;

function gets(pos,s,last,len:longint):longint;
var
  i,j,cnt:longint;
begin
  inc(cur);
  for i:=pos-len+1 to pos do
    free[i]:=cur;
  result:=s;
  for i:=1 to m do
    if (s shr (i-1) and 1=1) and (veq[i]=last) then
    begin
      cnt:=0;
      for j:=start[i] to finish[i] do
        if free[j]=cur then inc(cnt);
      if cnt>=leneq[i] then result:=result-(1 shl (i-1));
    end;
end;

function calc(pos,s,last,len:longint):boolean;
var
  i,j,nextpos,nexts,nextlast,nextlen:longint;
  tmp:boolean;
begin
  if findf(pos,s,last,len,result) then exit;
  if pos=0 then result:=s=0
  else
  if chkvalid(pos,s,last,len) then
    begin
      if s=0 then result:=true
      else
        begin
          nextpos:=pos-len;
          nexts:=gets(pos,s,last,len);
          nextlast:=1-last;
          result:=false;
          for nextlen:=1 to nextpos+1 do
            begin
              tmp:=calc(nextpos,nexts,nextlast,nextlen);
              if tmp then
                begin
                  result:=true;
                  break;
                end;
            end;
        end;
    end
  else
    result:=false;
  updatef(pos,s,last,len,result);
end;

function possible:boolean;
var
  i,last,len:longint;
  res:boolean;
begin
  inc(now);
  for last:=0 to 1 do
    for len:=1 to n do
      if calc(n,(1 shl m)-1,last,len) then
        begin
          exit(true);
        end;
  exit(false);
end;

procedure solve;
var
  i:longint;
  res:string;
  ok0,ok1:boolean;
begin
  if not possible then
    begin
      writeln('mau thuan'); exit;
    end;
  res:=a;
  for i:=1 to n do
    begin
      if a[i]='?' then
        begin
          a[i]:='0';
          ok0:=possible;
          a[i]:='1';
          ok1:=possible;
          a[i]:='?';
          if ok0 and (not ok1) then
            begin
              a[i]:='0';
              res[i]:='0';
            end;
          if ok1 and (not ok0) then
            begin
              a[i]:='1';
              res[i]:='1';
            end;
        end;
    end;
  writeln(res);
end;

var
  i:longint;

begin
  assign(input,fin);reset(input);
  assign(output,fou);rewrite(output);
  readln(n,m);
  readln(a);
  for i:=1 to m do
    readln(leneq[i],veq[i],start[i],finish[i]);
  solve;
  close(input);close(output);
end.


