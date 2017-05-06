const
    inp='';
    out='';
    maxn=504;
var
    fi,fo:text;
    n:longint;
    a,b:array[0..maxn,0..maxn] of longint;

procedure openfile;
begin
    assign(fi,inp);reset(fi);
    assign(fo,out);rewrite(fo);
end;

function check(x,y:longint):boolean;
begin
    if not odd(abs(x-y)) then check:=true
    else check:=false;
end;

function sum(x1,y1,x2,y2:longint):longint;
begin
    sum:=a[x2,y2]-a[x1-1,y2]-a[x2,y1-1]+a[x1-1,y1-1];
end;

function sum2(x1,y1,x2,y2:longint):longint;
begin
    sum2:=b[x2,y2]-b[x1-1,y2]-b[x2,y1-1]+b[x1-1,y1-1];
end;

procedure enter;
var
    i,j,c:longint;
begin
    readln(fi,n);
    for i:=1 to n do
        for j:=1 to n do
            begin
                read(fi,c);
                if check(i,j) then
                    begin
                        a[i,j]:=a[i-1,j]+a[i,j-1]-a[i-1,j-1]+c;
                        b[i,j]:=b[i-1,j]+b[i,j-1]-b[i-1,j-1];
                    end
                else begin
                        a[i,j]:=a[i-1,j]+a[i,j-1]-a[i-1,j-1];
                        b[i,j]:=b[i-1,j]+b[i,j-1]-b[i-1,j-1]+c;
                     end;
            end;
end;

procedure solve;
var
    i,x1,y1,x2,y2,p:longint;
begin
    readln(fi,p);
    for i:=1 to p do
        begin
            readln(fi,x1,y1,x2,y2);
            writeln(fo,abs(sum(x1,y1,x2,y2)-sum2(x1,y1,x2,y2)));
        end;
end;

procedure closefile;
begin
    close(fi);
    close(fo);
end;

begin
    openfile;
    enter;
    solve;
    closefile;
end.

