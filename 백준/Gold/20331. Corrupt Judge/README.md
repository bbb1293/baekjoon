# [Gold V] Corrupt Judge - 20331 

[문제 링크](https://www.acmicpc.net/problem/20331) 

### 성능 요약

메모리: 2060 KB, 시간: 4 ms

### 분류

많은 조건 분기(case_work), 그리디 알고리즘(greedy)

### 문제 설명

<p>You are organising a programming competition in which the rank of a team is first determined by how many problems they have solved. In case of a tie, the team with the lowest time penalty is ranked above the other. However, contrary to the UKIEPC, the time penalty is equal to $t$ if the <em>latest</em> accepted submission was submitted in the $t$th minute, or $0$ if no problem was solved.</p>

<p>For example, if team A solved their first problem in the $5$th minute, their second problem in the $10$th minute and their third problem in the $60$th minute, then their time penalty is $60$. If team B also solved three problems, in the $30$th, $40$th and $50$th minute, their time penalty is $50$ and they would rank above team A.</p>

<p>The contest has finished and you would like to enter the final standings. However, due to a corrupted file you have lost part of the scoreboard. In particular, the column indicating how many problems each team has solved is gone. You do still have the time penalties of all the teams and know that they are in the right order. You also remember how many problems the contest had. You wonder whether, given this information, it is possible to uniquely reconstruct the number of problems that each team has solved.</p>

### 입력 

 <ul>
	<li>One line containing two integers: $n$ ($1 \le n \le 10^4$), the number of teams participating, and $p$ ($1 \le p \le 10^4$), the number of contest problems.</li>
	<li>$n$ lines with on line $i$ the time score $t_i$ in minutes ($0 \le t_i \le 10^6$) of the team that is ranked in the $i$th place.</li>
</ul>

<p>A positive time score of $t$ indicates that a team has submitted their last accepted submission in the $t$th minute. A time score of $0$ indicates that a team hasn't solved any problem.</p>

<p>The input always originates from a valid scoreboard.</p>

### 출력 

 <p>If it is possible to uniquely reconstruct the scores of all the teams, output $n$ lines containing the number of problems that the $i$th team has solved on the $i$th line. Otherwise, output "<code>ambiguous</code>".</p>

