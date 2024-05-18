# Binary Tree System for storing data

It is a way to store data, based on pointers, that is very effective when it comes to searching through data. The assumption is that bigger values are always on the right 
side of the node and equal or smaller values are always on the left side of the node. In this case, when we want to find the exact node, we have to compare searched value to the 
node value and decide if to go right or left in the tree. 

This solution is very effective in specific situations. If the binary tree is well optimized, then for 2^n records in database it is maximum n comparisons to 
find desired record. So for almost 17 000 000 varying and optimized records it will only require from us to do maximum 24 comparisons and we will find desired value.
