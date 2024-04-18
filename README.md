# persistent_array

`persistent_array` 是一个 C++ 模板类，实现了一个持久化数组数据结构。它允许用户在不同版本中进行元素的查找和修改，同时保持高效的时间复杂度。

The `persistent_array` is a C++ template class that implements a persistent array data structure. It allows users to perform element searches and modifications across different versions while maintaining efficient time complexity.

## 特点 / Features
- **模板类**：支持任何数据类型的存储。
- **Template Class**: Supports storage of any data type.
- **版本控制**：可以创建数组的不同版本，进行历史状态的查询。
- **Version Control**: Can create different versions of the array for querying historical states.
- **动态修改**：支持对数组元素的修改，并生成新的版本。
- **Dynamic Modification**: Supports modification of array elements and the creation of new versions.
- **高效访问**：快速定位任意版本下特定位置的元素。
- **Efficient Access**: Quickly locates the element at a specific position in any version.

## 使用方法 / Usage

初始版本的版本号记为0。

The version number of the initial version is denoted as 0.

### 构造函数 / Constructors
- **无参构造：persistent_array()**：创建一个空的持久化数组。
- **No-argument Constructor : persistent_array()**: Creates an empty persistent array.
- **有参构造：persistent_array(const T\* const begin,const T\* const end)**：用一个数组的元素初始化持久化数组。
- **Argument Constructor : persistent_array(const T\* const begin,const T\* const end)**: Initializes the persistent array with elements from an array.

### 成员函数 / Member Functions
- **newarray(const T\* const begin,const T\* const end)**：用新的数组替换当前数组，并从头开始创建新版本。无返回值。
- **newarray(const T\* const begin,const T\* const end)**: Replaces the current array with a new one and creates a new version from the beginning. No return value.
- **size()**：返回数组的当前大小。返回一个`unsigned int`类型整数。
- **size()**: Returns the current size of the array. Returns an integer of type `unsigned int`.
- **version_size()**：返回版本号数量。返回一个`unsigned int`类型整数。
- **version_size()**: Returns the total number of version. Returns an integer of type `unsigned int`.
- **empty()**：检查数组是否为空。返回一个`bool`值。
- **empty()**: Checks if the array is empty. Returns a value of type bool.
- **view(unsigned int loc,unsigned int ver)**：查看位置为`loc`的元素在`ver`版本的值。
- **view(unsigned int loc,unsigned int ver)**: Views the value of the element at position `loc` in version `ver`.
- **change(unsigned int loc,const T& val,unsigned int ver)**：基于`ver`版本将位置为`loc`的元素值改为`val`，并返回新版本的版本号。返回一个`unsigned int`类型整数。
- **change(unsigned int loc,const T& val,unsigned int ver)**: Based on version `ver`, change the element at position `loc` to value `val`, and return the version number of the new version. Returns an integer of type `unsigned int`.

## 安装和依赖 / Installation and Dependencies

无需特别安装，只需包含头文件 `Persistent_array.h` 即可使用。支持 C++11 及以上版本。

No special installation is required; simply include the header file `Persistent_array.h` to use. Supports C++11 and above.
