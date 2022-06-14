# 1. Left Index
## Easy
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given a sorted array of positive integers (elements may be repeated) and a number <strong>x</strong>. The task is to find the leftmost index of x in the given array.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 10
arr[] = {1,1,2,2,3,4,5,5,6,7}
x = 1
<strong>Output: </strong>0<strong>
Explanation: </strong>1 is present two times
in the array and its leftmost index 
is 0.</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 7
arr[] = {10,20,20,20,20,20,20}
x = 20
<strong>Output: </strong>1<strong>
Explanation: </strong>20 is present 5 time, 
but its leftmost index is 1.</span>
</pre>

<p><span style="font-size:18px"><strong>Your&nbsp;Task:</strong><br>
The task is to complete the function <strong>leftIndex</strong>() which takes the array arr[], its size N and an integer x as inputs and&nbsp;returns the index of leftmost occurrence of x&nbsp;in given input array. It returns -1&nbsp;if element is not present in the array.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(LogN).<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(1).</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N &lt;= 10<sup>6</sup><br>
1 &lt;= arr[i] &lt;= 10<sup>6</sup><br>
1 &lt;= x &lt;= 10<sup>6</sup></span></p>
 <p></p>
            </div>