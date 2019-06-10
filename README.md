# roadtocpp
## 没有解决干净的problem:
162,


## 刷题发现的有意思的东西:
1. c++中的vector既可以用来当成int[]用,又可以当成List&lt;Integer>来用
2. vector与java中list的api对比

| c++ | java | 说明 |
|----|----| ---- |
|vector&lt;int> vec| List&lt;Integer> list |定义
|vec.push_pack()| list.add()| 添加元素至最后
|vec.pop_back()|list.remove(list.size() - 1) |删除最后一个元素
|vec.size() | list.size() | 容器size |
|vec[index]| list.get(index) | 取第index个元素的值
|vec.empty()|list.isEmpty() | 判断容器是否为空 |

3. 函数形参的vector&lt;int>最好声明成vector&lt;int> & vec 引用形式
4. 声明一个长度m宽度为n的二维数组dp: vector<vector<int>> dp(m, vector<int>(n, 0));
