set INDICES := 1 .. 2;
param cube {INDICES, INDICES, INDICES};
data;
param cube :=
[*, *, 1] : 1 2 :=
1 3 5
2 4 6
[*, *, 2] : 1 2 :=
1 2 11
2 0 7;