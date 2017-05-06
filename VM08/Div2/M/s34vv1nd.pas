type    pnode=^Tnode;
        Tnode=record
                u,v,c:longint;
                next:Pnode;
        end;
 
const   maxc=1000000000;
        maxn=100000+100;
 
var     m,n,nheap:longint;
        a:array[0..22222] of pnode;
        f,cs,heap:array[0..22222] of longint;
 
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
 
procedure nhapdl;
var     i,j,x,u,v:longint;
        p:pnode;
begin
        read(m,n);
        for i:=1 to m do
        begin
                for j:=1 to n do
                begin
                        read(x);
                        v:=(i-1)*n+j;
                        if i=1 then u:=0 else u:=v-n;
                        new(p);
                        p^.v:=v;
                        p^.c:=x;
                        p^.next:=a[u];
                        a[u]:=p;
 
                        new(p);
                        p^.v:=u;
                        p^.c:=x;
                        p^.next:=a[v];
                        a[v]:=p;
                end;
                for j:=2 to n do
                begin
                        read(x);
                        v:=(i-1)*n+j;
                        u:=v-1;
                        new(p);
                        p^.v:=v;
                        p^.c:=x;
                        p^.next:=a[u];
                        a[u]:=p;
 
                        new(p);
                        p^.v:=u;
                        p^.c:=x;
                        p^.next:=a[v];
                        a[v]:=p;
                end;
        end;
end;
 
function extract:longint;
var     luu,d,c:longint;
begin
        extract:=heap[1];
        luu:=heap[nheap];
        dec(nheap);
        d:=1;
        repeat
                c:=d*2;
                if (c<nheap) and (f[heap[c]]>f[heap[c+1]]) then inc(c);
                if (c>nheap) or (f[heap[c]]>=f[luu]) then break;
                heap[d]:=heap[c];
                cs[heap[d]]:=d;
                d:=c;
        until false;
        heap[d]:=luu;
        cs[heap[d]]:=d;
end;
 
procedure update(x:longint);
var     tg,c,d:longint;
begin
        tg:=heap[x];
        d:=x;
        repeat
                c:=d div 2;
                if (c=0) or (f[tg]>=f[heap[c]]) then break;
                heap[d]:=heap[c];
                cs[heap[d]]:=d;
                d:=c;
        until false;
        heap[d]:=tg;
        cs[tg]:=d;
end;
 
procedure xuli;
var     i,u:longint;
        p:pnode;
begin
        f[0]:=0;
        heap[1]:=0;
        cs[0]:=1;
        nheap:=1;
        for i:=1 to m*n do
        begin
                inc(nheap);
                f[i]:=maxc;
                heap[nheap]:=i;
                cs[i]:=nheap;
        end;
 
        repeat
                u:=extract;
                if (u=m*n) or (f[u]=maxc) or (nheap=0) then break;
                p:=a[u];
 
                while p<>nil do
                begin
                     if f[p^.v]>f[u]+p^.c then
                     begin
                             f[p^.v]:=p^.c+f[u];
                             update(cs[p^.v]);
                     end;
                p:=p^.next;
                end;
        until false;
        writeln(f[m*n]);
end;
 
begin
        mofile;
        nhapdl;
        xuli;
        dongfile;
end.
