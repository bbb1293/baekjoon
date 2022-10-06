# [Gold I] Manhattan Mornings - 15015 

[문제 링크](https://www.acmicpc.net/problem/15015) 

### 성능 요약

메모리: 3704 KB, 시간: 128 ms

### 분류

가장 긴 증가하는 부분 수열: O(n log n)(lis), 정렬(sorting)

### 문제 설명

<p>As a New Yorker you are always very busy. Apart from your long work day you tend to have a very long list of errands that need to be done on any particular day. You really hate getting up early so you always end up going over your to-do list after work, but this is starting to seriously hurt your free time.</p>

<p>One day you realize that some of the places you have to go by lie on your walk to the office, so you can visit them before work. The next day you notice that if you take a slightly different route to work you can run most of your errands without increasing the length of your route. Since errands take a negligible amount of time, you don’t even have to get up any earlier to do this! This nice little side effect of the grid-like New York streets gets you thinking. Given all the locations of your errands on the New York grid, how many can you visit on your way to work without getting up any earlier?</p>

<p>The New York grid is modelled with streets that are parallel to the x-axis and avenues that are parallel to the y-axis. Specifically, there is a street given by y = a for every a ∈ Z, and there is an avenue given by x = b for every b ∈ Z. It is given that an errand always takes place on an intersection between a street and an avenue. Since you walk to your work, you can use all roads in both directions.</p>

### 입력 

 <ul>
	<li>The first line contains an integer 0 ≤ n ≤ 10<sup>5</sup>, the number of errands you have to run that day.</li>
	<li>The next line contains four integers 0 ≤ x<sub>h</sub>, y<sub>h</sub>, x<sub>w</sub>, y<sub>w</sub> ≤ 10<sup>9</sup> corresponding to the locations of your house and workplace.</li>
	<li>The next n lines each contain two integers 0 ≤ x<sub>i</sub>, y<sub>i</sub> ≤ 10<sup>9</sup>, the coordinates of your ith errand.</li>
</ul>

### 출력 

 <p>Output a single line, containing the number of errands you can run before work without taking a longer route than necessary.</p>

