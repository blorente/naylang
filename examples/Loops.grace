var x := 4;
var i := 0;
var j := 0;
while {i < 5} {
    while {j < 5} {
        x := x + 1;
        j := j + 1;
    }
    j := 0;
    i := i + 1;
}