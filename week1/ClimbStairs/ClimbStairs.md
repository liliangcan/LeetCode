>爬楼梯真的其实就可以看成斐波那契数列，最简单的当然就是递归，但是要承受指数级的时间复杂度，利用记忆表保存之前已经计算过的数值是个不错的选择，但是若利用之前微机课上的实验内容，还有个也不错的想法，就是不断向前滚动，只记录两三个数值，得到指定需要的值就停止并输出。