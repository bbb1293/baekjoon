# [Platinum III] King of the Waves - 15013 

[문제 링크](https://www.acmicpc.net/problem/15013) 

### 성능 요약

메모리: 5608 KB, 시간: 20 ms

### 분류

구성적(constructive), 깊이 우선 탐색(dfs), 그래프 이론(graphs), 그래프 탐색(graph_traversal), 그리디 알고리즘(greedy)

### 문제 설명

<p>You are organising a king of the hill tournament, the Buenos Aires Paddleboarding Competition (BAPC), with n participants. In a king of the hill tournament, one person starts as a “king” and is then challenged by another person, the winning person becomes the new king. This is repeated until all participants have challenged exactly once (except for the starting person). In a paddleboarding match, there are no draws. The person which ends up as king, wins the tournament. Since you are the organiser, you get to choose the starting person and the order in which they challenge the king.</p>

<p>Someone is offering you a substantial amount of money in case one of the participants, Henk, ends up winning the tournament. You happen to know, for any two participants x and y, which of the two would win if they were to match during the tournament. Consequently, you choose to do the unethical: you will try to rig the game. Can you find a schedule that makes Henk win the tournament?</p>

### 입력 

 <ul>
	<li>The first line contains an integer 1 ≤ n ≤ 1000, the number of participants. The participants are numbered 0, . . . , n − 1, where Henk is 0.</li>
	<li>Then n lines follow, where each line has exactly n characters (not counting the newline character). These lines represent the matrix with the information of who beats who, as follows. On line i the jth character is (note that 0 ≤ i, j < n):
	<ul>
		<li>’1’ if person i will win against person j.</li>
		<li>’0’ if person i will lose against person j.</li>
		<li>X’ if i = j.</li>
	</ul>
	</li>
</ul>

### 출력 

 <p>Print a sequence of participants, such that the first person starts as king and the consequent participants challenge the king. If there is no way to rig the game such that Henk wins, print “impossible”.</p>

