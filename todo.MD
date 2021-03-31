# roadtocpp
## 没有解决干净的problem:
162,306


## 刷题发现的有意思的东西:
1. c++中的vector既可以用来当成int[]用,又可以当成List&lt;Integer>来用
2. vector与java中list的api对比

| c++ | java | 说明 |
|:----:|:----:|:----:|
|vector&lt;int> vec| List&lt;Integer> list |定义
|vector&lt;int>  res(size, 0);<br>res[x]=y;| List&lt;Integer> list=new ArrayList<>();<br>list.add(i,x); |c++的vector要想使用[i]索引进行取值<br>必须初始化size,但如果只是使用push_back添加新元素的话<br>就没必要初始化了,声明后就可以使用<br>详见merge_k_sorted_arr
|vec.push_pack()| list.add()| 添加元素至最后
|vec.pop_back()|list.remove(list.size()-1) |删除最后一个元素
|vec.size() | list.size() | 容器size |
|vec\[index]| list.get(index) | 取第index个元素的值
|vec.empty()|list.isEmpty() | 判断容器是否为空 |
|sort(begin(vec),end(vec))|list.sort() | 对容器进行排序(详见question_179) |

3. 函数形参的vector&lt;int>最好声明成vector&lt;int> & vec 引用形式
4. 声明一个长度m宽度为n的二维数组dp: vector<vector<int>> dp(m, vector<int>(n, 0));

5. c++与java的string常用接口对比

| c++ | java | 说明 |
|----|----| ---- |
|str.substr(i, j)| str.substring(i, j)| 截取str子串的一段
|str[2]|str.charAt(2)|取str字串中的第3个字符
|to_string(2) | 2.toString() | 把数字2转成字符串"2"
|str.size()|str.length()|求str字符串的长度
|str.push_back('2')|str += '2' | 字符串追加字符
|reverse(str)|无(可用双指针实现) | 字符串翻转
|str1.compare(1, str2)| str1.startsWith(str2, offset)| 比较两个字符串是否一致(可偏移)
|stoi(str)//用起有点问题 | Integer.parseInt(str)|字符串转数字
|str.erase(0,1) | str.replace(0,"")|删除第一个字符

6.c++与java的数组对比

| c++ | java | 说明 |
|----|----| ---- |
|int arr\[10]; 声明时必须指定容量| int\[] arr; 声明时不必指定容量| 声明数组(未初始化)
|int arr\[3] = {1,2,3}; <br>int arr3[] = { 1,2,3,4};| int[] arr = {1,2,3,4};  <br> int[] arr2 = new int[]{1, 2, 3, 4};| 初始化数组
|不允许声明和初始化换行| 允许| 声明数组(未初始化)
|sizeof(arr)| arr.length| 获得容量
|int arr\[2]\[3]| int\[2]\[3] arr| 二维数组定义

7.c++与java的Map对比

| c++ | java | 说明 |
|:----:|:-------:|:----:|
|unordered_map<string, Node *> map;|Map<x, y> map = new HashMap<>();|声明map|
|map[key] = value;|map.put(key,value);|map添加元素|
|V value = map[key];|V value = map.get(key);|map根据key获取value|



