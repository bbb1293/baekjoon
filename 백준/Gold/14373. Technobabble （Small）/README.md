# [Gold V] Technobabble (Small) - 14373 

[문제 링크](https://www.acmicpc.net/problem/14373) 

### 성능 요약

메모리: 2032 KB, 시간: 656 ms

### 분류

백트래킹(backtracking), 브루트포스 알고리즘(bruteforcing), 자료 구조(data_structures), 해시를 사용한 집합과 맵(hash_set), 구현(implementation), 문자열(string)

### 문제 설명

<p>Every year, your professor posts a blank sign-up sheet for a prestigious scientific research conference on her door. If a student wants to give a lecture at the conference, they choose a two-word topic that is not already on the sheet and write it on the sheet. Once the deadline has passed, the professor has one of her grad students put the topics in a random order, to avoid biasing for or against students who signed up earlier. Then she presents the topics to you for review.</p>

<p>Since the snacks at the conference are excellent, some students try to fake their way into the conference. They choose the first word of some topic already on the sheet and the second word of some topic already on the sheet, and combine them (putting the first word first, and the second word second) to create a new "topic" (as long as it isn't already on the sheet). Since your professor is open-minded, sometimes this strategy actually works!</p>

<p>The fakers are completely unoriginal and can't come up with any new first or second words on their own; they must use existing ones from the sheet. Moreover, they won't try to use an existing first word as their own second word (unless the word also already exists on the sheet as a second word), or vice versa.</p>

<p>You have a list of all N of the submitted topics, in some arbitrary order; you don't know the order in which they were actually written on the sheet. What's the largest number of them that could have been faked?</p>

### 입력 

 <p>The first line of the input gives the number of test cases, T. T test cases follow. Each consists of one line with an integer N, followed by N lines, each of which represents a different topic and has two strings of uppercase English letters: the two words of the topic, in order.</p>

<h3>Limits</h3>

<ul>
	<li>1 ≤ T ≤ 100.</li>
	<li>1 ≤ length of each word ≤ 20.</li>
	<li>No topic is repeated within a case.</li>
	<li>1 ≤ N ≤ 16.</li>
</ul>

### 출력 

 <p>For each test case, output one line containing <code>Case #x: y</code>, where <code>x</code> is the test case number (starting from 1) and <code>y</code> is an integer: the largest number of topics that could have possibly been faked.</p>

