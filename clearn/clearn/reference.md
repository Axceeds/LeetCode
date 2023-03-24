## reference
```c++
int a = 1;
int &b = a;
```
事实上是对a换了个名字，对b的所有操作等于对a的操作。


## 结构化绑定 Binding
Structured binding lets you initialize directly from the contents of a struct

struct p={1,'b'}
非结构化绑定：
int a=p.num;
char b=p.char;

结构化绑定：
auto [a,b] = p;

## Auto
+ Auto does not mean that the variable doesn't have a type, it means  that the type is deduced by the complier.  
+ Do not overuse auto, use it when you reduce long type names.  
Remember: C++, by default, makes copies when we do variable assignment! We need to use & if we need references instead.