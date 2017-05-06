uses math;
const
        maxc=1000000000+69;
        modulo=1000000000+7;
 
type
        re=record
                s:string;
                g:longint;
        end;
 
var
        n,x,y,z:longint;
        kq:re;
        a:array[0..51] of re;
        f:array[0..51,0..51,0..51] of longint;
        st:array[0..51,0..51,0..51] of string;
        dem:array[0..51,'a'..'b'] of longint;
 
procedure mofile;
begin
        assign(input,'checking.inp');
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
        i,j,tmp:longint;
        s:string;
begin
        readln(n);
        readln(x,y,z);
        for i:=1 to n do
        begin
                readln(s);
                tmp:=pos(' ',s);
                a[i].s:=copy(s,1,tmp-1);
                val(copy(s,tmp+1,length(s)-tmp),a[i].g);
                for j:=1 to length(a[i].s) do
                inc(dem[i,a[i].s[j]]);
        end;
end;
 
function mins(a,b:string):string;
begin
        if a<b then exit(a) else exit(b);
end;
 
procedure xuli;
var
        i,j,k,o:longint;
begin
        fillchar(f,sizeof(f),255);
        f[0,0,0]:=1;
        st[0,0,0]:='';
        for i:=0 to x do
        for j:=0 to y do
        for k:=1 to z+1 do
        begin
                for o:=1 to n do
                if (i>=dem[o,'a']) and (j>=dem[o,'b']) then
                if f[i-dem[o,'a'],j-dem[o,'b'],k-1]<>-1 then
                begin
                        if f[i,j,k]=f[i-dem[o,'a'],j-dem[o,'b'],k-1]+a[o].g then
                                st[i,j,k]:=mins(st[i,j,k],st[i-dem[o,'a'],j-dem[o,'b'],k-1]+a[o].s+' ')
                        else
                                if f[i,j,k]<f[i-dem[o,'a'],j-dem[o,'b'],k-1]+a[o].g then
                                begin
                                        f[i,j,k]:=f[i-dem[o,'a'],j-dem[o,'b'],k-1]+a[o].g;
                                        st[i,j,k]:=st[i-dem[o,'a'],j-dem[o,'b'],k-1]+a[o].s+' ';
                                end;
                end;
                if f[i,j,k]=kq.g then kq.s:=mins(kq.s,st[i,j,k])
                else
                if f[i,j,k]>kq.g then
                begin
                        kq.g:=f[i,j,k];
                        kq.s:=st[i,j,k];
                end;
        end;
        if length(kq.s)>0 then delete(kq.s,length(kq.s),1);
        writeln(kq.s);
end;
 
begin
        //mofile;
        nhapdl;
        xuli;
        dongfile;
end.
