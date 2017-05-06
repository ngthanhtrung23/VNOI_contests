type
        re=record
                x,y:longint;
        end;
 
        pnode=^tnode;
        tnode=record
                v,c:longint;
                next:pnode;
        end;
        bignum=array[0..10000] of longint;
 
const
        maxc=1000000000+69;
        modulo=1000000000+7;
 
var
        tmp,tg,kq,kqq,a:bignum;
        n:longint;
 
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
 
function max(a,b:longint):longint;
begin
        if a>b then exit(a) else exit(b);
end;
 
function cong(a,b:bignum):bignum;
var
        i:longint;
begin
        fillchar(kq,sizeof(kq),0);
        for i:=1 to max(a[0],b[0]) do
        begin
                kq[i]:=kq[i]+a[i]+b[i];
                kq[i+1]:=kq[i] div 10000;
                kq[i]:=kq[i] mod 10000;
        end;
        kq[0]:=i;
        while (kq[kq[0]]=0) and (kq[0]>1) do dec(kq[0]);
        exit(kq);
end;
 
function nhan(a,b:bignum):bignum;
var
        i,j:longint;
begin
        fillchar(kq,sizeof(kq),0);
        for i:=1 to a[0] do
        for j:=1 to b[0] do
        begin
                kq[i+j-1]:=kq[i+j-1]+(a[i]*b[j]);
                kq[i+j]:=kq[i+j]+kq[i+j-1] div 10000;
                kq[i+j-1]:=kq[i+j-1] mod 10000;
        end;
        kq[0]:=a[0]+b[0];
        while (kq[kq[0]]=0) and (kq[0]>1) do dec(kq[0]);
        exit(kq);
end;
 
procedure xuli;
var
        i:longint;
        s:string;
begin
        readln(n);
        tmp[0]:=1;tmp[1]:=1;
        tg[0]:=1;tg[1]:=1;
        for i:=3 to n do
        begin
                a[0]:=1;
                a[1]:=i-2;
                tmp:=nhan(tmp,a);
                tmp:=cong(tmp,tg);
        end;
        for i:=tmp[0] downto 1 do
        begin
                str(tmp[i],s);
                while (length(s)<4) and (i<tmp[0]) do
                begin
                        s:='0'+s;
                        write('0');
                end;
                write(tmp[i]);
        end;
end;
 
begin
        mofile;
        xuli;
        dongfile;
end.
