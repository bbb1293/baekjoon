# [Gold V] Brexit - 13463 

[문제 링크](https://www.acmicpc.net/problem/13463) 

### 성능 요약

메모리: 15696 KB, 시간: 176 ms

### 분류

너비 우선 탐색(bfs), 그래프 이론(graphs), 그래프 탐색(graph_traversal)

### 문제 설명

<p>A long time ago in a galaxy far, far away, there was a large interstellar trading union, consisting of many countries from all across the galaxy. Recently, one of the countries decided to leave the union. As a result, other countries are thinking about leaving too, as their participation in the union is no longer beneficial when their main trading partners are gone.</p>

<p>You are a concerned citizen of country X, and you want to find out whether your country will remain in the union or not. You have crafted a list of all pairs of countries that are trading partners of one another. If at least half of the trading partners of any given country Y leave the union, country Y will soon follow. Given this information, you now intend to determine whether your home country will leave the union.</p>

### 입력 

 <p>The input starts with one line containing four space separated integers C, P, X, and L. These denote the total number of countries (2 ≤ C ≤ 200 000), the number of trading partnerships (1 ≤ P ≤ 300 000), the number of your home country (1 ≤ X ≤ C) and finally the number of the first country to leave, setting in motion a chain reaction with potentially disastrous consequences (1 ≤ L ≤ C).</p>

<p>This is followed by P lines, each containing two space separated integers A<sub>i</sub> and B<sub>i </sub>satisfying 1 ≤ A<sub>i</sub> < B<sub>i</sub> ≤ C. Such a line denotes a trade partnership between countries A<sub>i</sub> and B<sub>i</sub> . No pair of countries is listed more than once.</p>

<p>Initially, every country has at least one trading partner in the union.</p>

### 출력 

 <p>For each test case, output one line containing either “leave” or “stay”, denoting whether you home country leaves or stays in the union.</p>

