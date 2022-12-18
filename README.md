# Simple CSV parser

## NSU task
Task: write a simple csv parser using tuples, lazy reading and templates

## Highligths
* Single-header file
* Requires C++ 17

## Usage

Just include SCVParser.hpp and you're good to go:

```cpp
#include <CSVParser.hpp>
```

To start reading csv-file, create a ```CSVParser``` using necessary types in templates: 

```cpp
CSVParser<Args...> parser("input.csv", 0, ',', '\"');
```


 ### Arguments:
 ```cpp
 CSVParser(std::ifstream& file, size_t skipLines, char delimeter=',', char escape='\"')
 ```
1. file - input csv file
2. skipLines - how many lines should it skip
3. delimeter - symbol-delimiter, optional argument, default value: ,
4. escape - escape symbol, optional argument, default value: "


### Methods
1. Read and parse a next row

```cpp
std::tuple<Args...> getString()
```

2. Return index'th row 

```cpp
std::tuple<Args...> operator[](int index)
```

**NOTE:** Valid indexes dosen't include skiped rows, for example if skipLines == n, then 5'th rows will be (n + skipLines)'th

In case index > number of rows in file, an out_of_range exception will be thrown


### Iterator
Also you can read data using iterator:

```cpp
for (auto x : parser)
{
    std::cout << x;
    std::cout << std::endl;
}
```


## Usage example

```cpp
#include "CSVParser.hpp"

int main()
{
    std::ifstream fin("input.csv");
    
    //Using , like delimeter and " like escape symbol
    CSVParser<int, std::string, double, int, int, int, double, int, double, int, std::string> p(fin, 3, ',', '/');

    // Show all rows
    for (auto x : p)
    {
    	std::cout << x;
	std::cout << std::endl;
    }

    //Show third row
    std::cout << p[3];

    return 0;
}
```












