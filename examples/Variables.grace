def x = "Hello";
def y = x.++(" World");
def obj = object {
  method add(n) to(t) {
    n + t;
  }
  var val := add(2)to(3);
};
def z = obj.add(3)to(4);
def r = obj.val;
