# [Gold II] Detour - 15006 

[문제 링크](https://www.acmicpc.net/problem/15006) 

### 성능 요약

메모리: 19700 KB, 시간: 72 ms

### 분류

다익스트라(dijkstra), 그래프 이론(graphs)

### 문제 설명

<p>After last year’s edition of the BAPC, you are still stuck in Delft. In order to participate again this year, you are going to Amsterdam by bus. During the journey you look out of the window and look for traffic signs that point in the direction of Amsterdam. To your surprise, you notice that the bus is never taking the roads that are pointed out by the signs!</p>

<p>You think that the bus company might have chosen a route such that, at no intersection, the bus goes in the direction that is pointed to by the signs. Your friends, however, find this very unbelievable, and don’t think this is possible. Can you figure out whether there exists a bus route that satisfies this requirement? Note that a bus route never visits the same place twice.</p>

<p>A traffic sign pointing in the direction of the shortest route to Amsterdam is placed at every intersection. You may assume that the input graph is both simple and connected, and that there is a unique optimal route to Amsterdam from every intersection.</p>

### 입력 

 <ul>
	<li>A single line containing two integers: n (2 ≤ n ≤ 10<sup>5</sup>), the number of intersections, and m (1 ≤ m ≤ 10<sup>6</sup>), the number of undirected roads that connect the intersections. The intersections are numbered from 0 to n − 1. Delft is denoted by intersection i = 0 and Amsterdam is denoted by intersection i = 1.</li>
	<li>m lines that specify the roads
	<ul>
		<li>A road is specified by three integers, a<sub>i</sub>, b<sub>i</sub> (0 ≤ a<sub>i</sub>, b<sub>i</sub> < n and a<sub>i</sub> ≠ b<sub>i</sub>) and d<sub>i</sub> (0 ≤ d<sub>i</sub> ≤ 500000), where a<sub>i</sub> and b<sub>i</sub> are ids of the two intersections that are connected by this road and d<sub>i</sub> is the distance that the bus has to travel to get from a<sub>i</sub> to b<sub>i</sub> or vice versa.</li>
	</ul>
	</li>
</ul>

### 출력 

 <p>As output, give one of the following:</p>

<ul>
	<li>A path from Delft to Amsterdam that satisfies the requirements, in case such a path exists.
	<ul>
		<li>A path is specified by a single line containing an integer k, the length of the path, followed by k integers p<sub>i</sub> that specify the intersections along the path in the order in which they are crossed, with p<sub>0</sub> = 0 and p<sub>k−1</sub> = 1.</li>
	</ul>
	</li>
	<li>The text “impossible”, if such a path does not exist.</li>
</ul>

