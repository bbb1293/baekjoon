# [Gold I] Efficient Exchange - 17786 

[문제 링크](https://www.acmicpc.net/problem/17786) 

### 성능 요약

메모리: 2028 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍(dp), 그리디 알고리즘(greedy)

### 문제 설명

<p>You have recently acquired a new job at the Bank for Acquiring Peculiar Currencies. Here people can make payments, and deposit or withdraw money in all kinds of strange currencies. At your first day on the job you help a customer from Nijmegia, a small insignificant country famous for its enormous coins with values equal to powers of 10, that is, 1, 10, 100, 1000, etc. This customer wants to make a rather large payment, and you are not looking forward to the prospect of carrying all those coins to and from the vault.</p>

<p>You therefore decide to think things over first. You have an enormous supply of Nijmegian coins in reserve, as does the customer (most citizens from Nijmegia are extremely strong). You now want to minimize the total number of coins that are exchanged, in either direction, to make the exact payment the customer has to make.</p>

<p>For example, if the customer wants to pay 83 coins there are many ways to make the exchange. Here are three possibilities:</p>

<ul>
	<li>Option 1. The customer pays 8 coins of value 10, and 3 coins of value 1. This requires exchanging 8 + 3 = 11 coins.</li>
	<li>Option 2. The customer pays a coin of value 100, and you return a coin of value 10, and 7 coins of value 1. This requires exchanging 1 + 1 + 7 = 9 coins.</li>
	<li>Option 3. The customer pays a coin of value 100, and 3 coins of value 1. You return 2 coins of value 10. This requires exchanging 1 + 3 + 2 = 6 coins.</li>
</ul>

<p>It turns out the last way of doing it requires the least coins possible.</p>

### 입력 

 <ul>
	<li>A single integer 0 ≤ n < 10<sup>1000</sup>, the amount the customer from Nijmegia has to pay.</li>
</ul>

### 출력 

 <ul>
	<li>Output the minimum number of coins that have to be exchanged to make the required payment.</li>
</ul>

