# kjx
C++14 functional library [eternal early draft]

Ideas for library of functional primitives.
* Aiming for convenient composable interface.
* Using C++14 features - mainly generic lambdas and generalized lambda capture.
* Few bits from boost are used for implementation - doesn't make sense to reimplement those now.
* No optimization yet. Might at least explore move semantics later.

## examples ##
see ```examples/```

```
std::vector<int> raw = {0, 1, 2, 3};

int sum = fold( 0, std::plus<int>() )(raw );
```
```
std::set<int> raw = {0, 1, 2, 3};

std::set<int> odd = filter( [](int a)->bool{ return a % 2 == 1;} )(raw);
```

## compilation ##
So far everything is header-only. To compile examples use C++14 standard.
Successfully compiled with
* g++ 5.2.1
* clang++ 3.7 (or newer)

Surprisingly encountered some issues with older versions of clang++ (3.5, 3.6). Might be some unfinished feature, might be be a bug in my code. Will investigate later if current prototype is not superseded.

Recommended:
```
g++ -std=c++14
```

## warnings ##
* This is speculative programming at it's best. I am happy even for finding out how to implement my ideas regarding interface in best-cases. Not even tried to imagine what might happen otherwise - behaviour is undefined.
* Debugging is difficult and error messages are of limited value. Due to fair share of type auto-deduction problems are usually reported far from their origin.
* This is just fun project and I don't expect it to be really usable for production software.
* Provided as is. No warranty expressed or implied.


