const
        maxc=1000000000+69;
        maxn=510;
        modulo=1000000000+7;
 
var
        a:array[0..maxn,0..maxn] of longint;
        g:array[0..maxn,0..maxn] of longint;
        m,n,p,kq,ttx,tty,pdx,pdy:longint;
        tong:int64;
 
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
 
procedure nhapdl;
var
        i,j:longint;
begin
        readln(m,n,p);
        for i:=1 to m do
        for j:=1 to n do
        begin
                read(a[i,j]);
                g[j,i]:=g[j,i-1]+a[i,j];
                tong:=tong+a[i,j];
        end;
end;
 
procedure xuli;
var
        o,h,i,j,tmp:longint;
begin
        kq:=maxc;
        for o:=1 to m do
        begin
                for h:=1 to o do
                begin
                        j:=1;
                        tmp:=0;
                        for i:=1 to n do
                        begin
                                tmp:=tmp+g[i,o]-g[i,o-h];
                                while tmp-g[j,o]+g[j,o-h]>=p do
                                begin
                                        tmp:=tmp-g[j,o]+g[j,o-h];
                                        inc(j);
                                end;
                                if (tmp>=p) and (kq>h*(i-j+1)) then
                                begin
                                        kq:=h*(i-j+1);
                                        pdx:=o;
                                        pdy:=i;
                                        ttx:=o-h+1;
                                        tty:=j;
                                end;
                        end;
                end;
        end;
        writeln(kq);
        //writeln(ttx,' ',tty,' ',pdx,' ',pdy);
end;
 
begin
        //mofile;
        nhapdl;
        if tong>=p then xuli else writeln(-1);
        dongfile;
end.
