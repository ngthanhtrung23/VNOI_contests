var
        s:ansistring;
        l,dem2,dem5,dem,demnt:longint;
        f,cs,a,snt:array[1..11111] of longint;
        nt:array[1..11111] of boolean;
 
procedure mofile;
begin
        assign(input,'');
        reset(input);
        assign(output,'');
        rewrite(output);
end;
 
procedure dongfile;
begin
        close(input);
        close(output);
end;
 
procedure init;
var
        i,j:longint;
begin
        for i:=1 to l do
        begin
                inc(a[ord(s[i])-ord('a')+1]);
        end;
end;
 
procedure xuli;
var
        i,j,tmp,count,k:longint;
begin
        readln(s);
        l:=length(s);
        init;
        for i:=1 to l do
        begin
                tmp:=i;
                while tmp mod 2=0 do
                begin
                        tmp:=tmp div 2;
                        inc(dem2);
                end;
                while tmp mod 5=0 do
                begin
                        tmp:=tmp div 5;
                        inc(dem5);
                end;
        end;
 
        for i:=1 to 26 do
        begin
                for j:=2 to a[i] do
                begin
                        tmp:=j;
                        while tmp mod 2=0 do
                        begin
                                tmp:=tmp div 2;
                                dec(dem2);
                        end;
                        while tmp mod 5=0 do
                        begin
                                tmp:=tmp div 5;
                                dec(dem5);
                        end;
                end;
        end;
 
        if dem2<dem5 then writeln(dem2) else writeln(dem5);
end;
 
begin
        mofile;
        xuli;
        dongfile;
end.
