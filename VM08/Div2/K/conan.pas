const
    inp='';
    out='';
    maxn=502;
var
    fi,fo:text;
    n:longint;
    a:array[1..maxn,1..maxn] of byte;
    f:array[1..maxn,1..maxn] of boolean;
    next:array[1..maxn] of longint;

procedure openfile;
begin
    assign(fi,inp); reset(fi);
    assign(fo,out); rewrite(fo);
end;

procedure solve;
var
    d,j,i,k:longint;
    result:longint;
begin
    fillchar(f,sizeof(f),false);
    for i:=1 to n do next[i]:=i mod n + 1;
    for i:=1 to n do f[i,next[i]]:=true;
    for d:=2 to n do
        for i:=1 to n do
            begin
                j:=i + d;
                if j>n then j:=j - n;
                k:=next[i];
                while k<>i do
                    begin
                        if (f[i,k]) and (f[k,j]) then
                            if (a[i,k]=1) or (a[j,k]=1) then
                                begin
                                    f[i,j]:=true;
                                    break;
                                end;
                        k:=next[k];
                    end;
            end;
    result:=0;
    for i:=1 to n do
        if f[i,i] then inc(result);
    writeln(fo,result);
    for i:=1 to n do
        if f[i,i] then writeln(Fo,i);
end;

procedure enter;
var
    i,j:longint;
begin
    readln(fi,n);
    for i:=1 to n do
        begin
            for j:=1 to n do read(fi,a[i,j]);
            readln(fi);
        end;
    solve;
end;

procedure closefile;
begin
    close(Fi);
    close(fo);
end;

begin
    openfile;
    enter;
    closefile;
end.

