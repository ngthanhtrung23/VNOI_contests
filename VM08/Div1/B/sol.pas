{$MODE DELPHI,R+,Q+}
program QTREE3;
const
  input  = '';
  output = '';
  maxn = 100000;
type
  pnode = ^tnode;
  tnode = record
    val: integer;
    link: pnode;
  end;
var
  fi,fo: text;
  n,q,dyna: integer; //dyna: number of node in dynamic tree
  tree: array[1..4 * maxn] of integer;
  stat: array[1..maxn] of boolean;
  a: array[1..maxn] of pnode;
  lab,pos,size,maxnode: array[1..maxn] of integer;
  pr,st,fin: array[1..maxn] of integer;
  u1,u2,k: integer;  //Use for queries in Interval Tree
  ch: boolean;
  tk,res: integer;

procedure openfile;
begin
  assign(fi, input);
    reset(fi);

  assign(fo, output);
    rewrite(fo);
end;

procedure add(u,v: integer);
var
  p: pnode;
begin
  new(p);
  p^.val := v;
  p^.link := a[u];
  a[u] := p;
end;

procedure init;
var
  i,u,v: integer;
begin
  readln(fi, n, q);
  for i := 1 to n do a[i] := nil;
  for i := 1 to n - 1 do
    begin
      readln(fi, u, v);
      add(u,v);
      add(v,u);
    end;
end;

procedure prepare;
begin
  fillchar(pr, sizeof(pr), 0);
  fillchar(pos, sizeof(pos), 0);
end;



//Dynamic tree construction

procedure DFS(u: integer);
var
  p: pnode;
  max,v: integer;
begin
  p := a[u];
  size[u] := 1;
  max := 0;

  while p <> nil do
    begin
      v := p^.val;
      if v <> pr[u] then
        begin
          pr[v] := u;
          DFS(v);

          size[u] := size[u] + size[v];
          if size[v] > max then
            begin
              max := size[v];
              maxnode[u] := v;
            end;
        end;
      p := p^.link;
    end;
end;

procedure struct(u: integer);
var
  p: pnode;
  v,endnode: integer;
begin
  p := a[u];
  if (pos[u] = 0) and (p <> nil) then
    begin
      inc(dyna);
      pos[u] := dyna;
      lab[dyna] := u;
      st[u] := u;
      endnode := u;

      v := maxnode[u];
      while v <> 0 do
        begin
          inc(dyna);
          pos[v] := dyna;
          lab[dyna] := v;
          st[v] := u;
          if maxnode[v] = 0 then endnode := v;
          v := maxnode[v];
        end;

      v := u;
      while v <> 0 do
        begin
          fin[v] := endnode;
          v := maxnode[v];
        end;
    end;

  while p <> nil do
    begin
      v := p^.val;
      if v <> pr[u] then struct(v);
      p := p^.link;
    end;
end;

//End of Dynamic tree construction



procedure upIT(i,low,high: integer);
var
  mid: integer;
begin
  if low = high then
    begin
      if ch then tree[i] := low else tree[i] := -1;
      exit;
    end;

  mid := (low + high) div 2;
  if k <= mid then upIT(2 * i,low,mid) else
                   upIT(2 * i + 1,mid + 1,high);

  if tree[2 * i] = -1 then tree[i] := tree[2 * i + 1] else tree[i] := tree[2 * i];
end;

procedure calc(i,low,high: integer);
var
  mid: integer;
begin
  if (u2 < low) or (high < u1) then exit;
  if (u1 <= low) and (high <= u2) then
    begin
      if (tree[i] <> -1) and ((tk = -1) or (tk > tree[i])) then tk := tree[i];
      exit;
    end;

  mid := (low + high) div 2;
  calc(2 * i,low,mid);
  calc(2 * i + 1,mid + 1,high);
end;

procedure update(y: integer);
begin
  k := pos[y];
  stat[y] := not stat[y];
  ch := stat[y];
  if pos[y] <> 0 then upIT(1,1,dyna);
end;

procedure ask(y: integer);
var
  tmp: integer;
begin
  if y = 0 then exit;
  if stat[y] then tmp := y else tmp := -1;
  if tmp <> -1 then res := tmp;

  if (y = st[y]) or (pos[y] = 0) then ask(pr[y])
  else
    begin
      u1 := pos[st[y]];
      u2 := pos[y];
      tk := -1;
      calc(1,1,dyna);
      if tk <> -1 then res := lab[tk];
      ask(pr[st[y]]);
    end;
end;

procedure query;
var
  i,x,y: integer;
begin
  DFS(1);
  dyna := 0;
  struct(1);

  for i := 1 to 4 * dyna do tree[i] := -1;
  fillchar(stat, sizeof(stat), false);

  for i := 1 to q do
    begin
      readln(fi, x, y);
      if x = 0 then update(y) else
        begin
          res := -1;
          ask(y);
          writeln(fo, res);
        end;
    end;
end;

procedure closefile;
begin
  close(fo);
  close(fi);
end;

begin
  openfile;
  init;
  prepare;
  query;
  closefile;
end.

