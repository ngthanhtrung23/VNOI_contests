{$MODE OBJFPC}
program vtri;
var
  x,y,s: Integer;
  Ax,Ay,Bx,By,Cx,Cy: Integer;
  temp1,temp2: Integer;
  ans: Integer;

begin
  assign(input,''); reset(input);
  assign(output,''); rewrite(output);
  readln(x,y,s);
  for Ax := 0 to x do
    for Ay := 0 to y do
      begin
        for By := Ay + 1 to y do
          for Cx := Bx to x do
            begin
              temp2 := Ax * by + Cx * Ay - Ay * Bx - By * Cx;
              if (temp2 = 2 * S) {or (temp2 = -2 * S)} then
                ans := ans + y + 1;
            end;
        for Bx := Ax + 1 to x do
          for By := 0 to y do
            if (Ax <> Bx) or (Ay <> By) then
              for Cx := Bx to x do
                begin
                  temp1 := (Bx - Ax);
                  temp2 := Ax * by + Cx * Ay - Ay * Bx - By * Cx;
                  if temp1 = 0 then
                    begin
                      if (temp2 = 2 * S) {or (temp2 = -2 * S)} then
                        ans := ans + y + 1;
                    end
                  else
                    begin
                      if (2 * S - temp2) mod temp1 = 0 then
                        begin
                          Cy := (2 * S - temp2) div temp1;
                          if (0 <= Cy) and (Cy <= y) then Inc(ans);
                        end;
                      if (-2 * S - temp2) mod temp1 = 0 then
                        begin
                          Cy := (-2 * S - temp2) div temp1;
                          if (0 <= Cy) and (Cy <= y) then Inc(ans);
                        end;
                    end;
                end;
      end;
  writeln(ans);
  close(input);
  close(output);
end.

