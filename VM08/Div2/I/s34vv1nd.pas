type
        re=record
                x,y:longint;
        end;
 
        pnode=^tnode;
        tnode=record
                v,c:longint;
                next:pnode;
        end;
 
const
        maxc=1000000000+69;
        maxn=100000+10;
        modulo=1000000000+7;
 
var
        a,f,w:array[0..maxn] of longint;
        n:longint;
 
procedure mofile;
begin
        assign(input,'checking1.inp');
        reset(input);
        assign(output,'');
        rewrite(output);
end;
 
procedure dongfile;
begin
        close(input);
        close(output);
end;
 
procedure qs(d,c:longint);
var
        i,j,k,tg:longint;
begin
        i:=d;
        j:=c;
        k:=f[random(c-d+1)+d];
        repeat
                while f[i]<k do inc(i);
                while f[j]>k do dec(j);
                if i<=j then
                begin
                        tg:=f[i];
                        f[i]:=f[j];
                        f[j]:=tg;
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if d<j then qs(d,j);
        if i<c then qs(i,c);
end;
 
procedure xuli;
var
        i:longint;
        check:boolean;
begin
        readln(n);
        for i:=1 to n do
        begin
                read(a[i]);
                f[i]:=f[i-1]+a[i];
        end;
        qs(1,n-1);
        check:=true;
        if f[n-1]>=f[n] then check:=false else
        for i:=1 to n do
        begin
                w[i]:=f[i]-f[i-1];
                if w[i]=0 then check:=false;
        end;
        if not check then writeln('-1') else
        begin
                for i:=1 to n do write(w[i],' ');
        end;
end;
 
begin
        //mofile;
        xuli;
        dongfile;
end.
