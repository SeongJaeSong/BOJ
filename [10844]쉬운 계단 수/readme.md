https://sihyungyou.github.io/baekjoon-10844/

```
(x + y)%mod == (x % mod + y % mod) % mod
����, �������� ����
```


```
2���� �迭�� arr[10][10] = {1,} ������ �ʱ�ȭ�� �ȵȴ�.
```

``` cpp
for (int i = 1; i < n; i++) {
	sum = 0;
	for (int j = 0; j < 10; j++) {
		if (j == 0) {
			dp[i%2][j] = (dp[(i+1)%2][j + 1])%MOD;
		}
		else if (j == 9) {
			dp[i%2][j] = (dp[(i+1)%2][j - 1])%MOD;
		}
		else {
			dp[i%2][j] = (dp[(i+1)%2][j - 1] + dp[(i+1)%2][j + 1])%MOD;
		}
		sum += dp[i % 2][j];
	}
}

dp[(i+1)%2][j - 1] + dp[(i+1)%2][j + 1] �� �κ��� long long�� ������ �Ѿ �� �ִٴ� ������ ���߾���
```
