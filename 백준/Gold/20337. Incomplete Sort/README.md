# [Gold I] Incomplete Sort - 20337 

[문제 링크](https://www.acmicpc.net/problem/20337) 

### 성능 요약

메모리: 4060 KB, 시간: 56 ms

### 분류

구성적(constructive), 정렬(sorting)

### 문제 설명

<p>Merge sort is a sorting algorithm. It works by splitting an array in half, sorting both halves recursively and then merging those halves together to sort the entire array. Your friend is working on an implementation of the merge sort algorithm, but unfortunately he is not quite there yet: he can only sort half of the array! In great despair he turns to you for help: can you use his unfinished code to write an algorithm that sorts an array completely?</p>

<p>In its current state, your friend's code is a sorting function that can be run on arbitrary sub-arrays, as long as it is precisely half as long as the original array. It then correctly sorts this sub-array. You decide to play around with this function, so you start with a jumbled array and try to sort it (see figure). After choosing $3$ sub-arrays and using them as input for the sorting function, you end up with a sorted array. Interestingly, it seems that no matter what the original array you use is, you can always sort it completely by invoking your friend's sorting function only $3$ times. You decide that this makes for a good challenge: you want to extend the code to work for a full array, making at most three calls to the sorting function.</p>

<p>Now you need to figure out which sub-arrays to sort! Given an array of length $n$, output at most three sub-arrays of length $\tfrac{1}{2}n$ so that sorting these sub-arrays in order will result in a sorted array. It is guaranteed that this is always possible.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 406px; height: 80px;"></p>

<p style="text-align: center;">Figure I.1: First sorting step of sample output 1</p>

### 입력 

 <ul>
	<li>One line containing a single integer $n$ ($4\leq n\leq 10^5$) divisible by $4$, the length of the array.</li>
	<li>One line containing $n$ unique integers $a$ ($1\leq a \leq n$), the array to be sorted.</li>
</ul>

### 출력 

 <p>The output consists of:</p>

<ul>
	<li>One line containing the number of function calls $f$ ($0\leq f \leq 3$).</li>
	<li>$f$ lines, each containing $\tfrac{1}{2}n$ unique integers $i$ ($1\leq i \leq n$), the indices determining the sub-array to be sorted at each of the function calls.</li>
</ul>

<p>If there are multiple valid solutions, you may output any one of them. You do not have to minimise $f$.</p>

