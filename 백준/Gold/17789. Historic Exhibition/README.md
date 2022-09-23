# [Gold III] Historic Exhibition - 17789 

[문제 링크](https://www.acmicpc.net/problem/17789) 

### 성능 요약

메모리: 2260 KB, 시간: 4 ms

### 분류

그리디 알고리즘(greedy)

### 문제 설명

<p>The Benelux Artistic Pottery Consortium is preparing for an exhibit of its most prized urns and vases at a gallery in Nijmegen. Due to the sheer number of vases to be put on display the gallery has trouble finding a pedestal of the right size for every single vase. They have pedestals available that can either be placed normally or upside down and can be characterised by the diameter of their top and bottom surface. Moreover, the diameter of the top and bottom varies by at most one unit length.</p>

<p>For artistic reasons, it is important that the diameter of the base of a vase matches the diameter of the surface of the pedestal it is placed on. You have been asked to find a way to place all the vases on available pedestals. In order to make this work, you might need to turn some of the pedestals upside down. For example, Figure H.1 shows a possible assignment of pedestals to vases for sample input 1. Assist the gallery by writing a program to compute such an assignment.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 179px; height: 137px;"></p>

<p style="text-align: center;">Figure H.1: Solution for sample input 1.</p>

### 입력 

 <ul>
	<li>The first line contains two integers 0 ≤ p, v ≤ 10<sup>4</sup> the number of pedestals and the number of vases.</li>
	<li>Then follow p lines, the i-th of which contains two integers 1 ≤ a<sub>i</sub>, b<sub>i</sub> ≤ 10<sup>4</sup> denoting the diameters of the different sides of pedestal i. It is given that |a<sub>i</sub> − b<sub>i</sub>| ≤ 1.</li>
	<li>Then follows a single line containing v integers 1 ≤ c<sub>1</sub>, . . . , c<sub>v</sub> ≤ 10<sup>4</sup>, where c<sub>i</sub> denotes the diameter of vase i.</li>
</ul>

### 출력 

 <ul>
	<li>Output v distinct integers 1 ≤ x<sub>1</sub>, . . . , x<sub>v</sub> ≤ p such that vase i can stand on pedestal x<sub>i</sub>, or print impossible if no assignment of vases to pedestals exists.</li>
</ul>

<p>If there are multiple possible solutions, you may output any one of them.</p>

