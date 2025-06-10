## リストの作成

### 文字列 (str) をリストに変換

文字列をリストに変換する方法はいくつかあります。

s = "12345"

### 1. list() 関数を使用
list_s = list(s)
print(list_s)  # ['1', '2', '3', '4', '5']

### 2. リスト内包表記を使用 (基本的な変換)
list_comprehension_s = [c for c in s]
print(list_comprehension_s)  # ['1', '2', '3', '4', '5']

### 3. リスト内包表記を使用 (要素をint型に変換)
int_list_s = [int(c) for c in s]
print(int_list_s)  # [1, 2, 3, 4, 5]

**使い分け**:
* リスト化したいだけであれば `list(s)` で十分です。
* `[c for c in s]` を使用すると、条件を追加したり、要素を変換したりといった柔軟な処理が可能です。

### 二重リスト作成の注意点

二重リストを作成する際、`[[0]*a]*b` のようにかけると、すべての内部リストが同じオブジェクトを参照してしまうため、意図しない挙動につながります。

**⭕️ 正しい作成方法 (推奨)**
```python
# b行a列の二重リストを作成し、すべての要素を0で初期化
# 各行が独立したリストとして作成される
a = 3
b = 2
matrix_ok = [[0] * a for _ in range(b)]
print(matrix_ok)
# 出力例: [[0, 0, 0], [0, 0, 0]]

matrix_ok[0][1] = 99
print(matrix_ok)
# 出力例: [[0, 99, 0], [0, 0, 0]]  ← 意図通りに1つの行だけが変更される
```

**❌ 誤った作成方法 (避けるべき)**
```python
# この方法では、すべての内部リストが同じオブジェクトを参照する
a = 3
b = 2
matrix_ng = [[0] * a] * b
print(matrix_ng)
# 出力例: [[0, 0, 0], [0, 0, 0]]

matrix_ng[0][1] = 4
print(matrix_ng)
# 出力例: [[0, 4, 0], [0, 4, 0]]  ← すべての行が変更されてしまう
```

`_` は、イテレータの要素自体は使用しないが、ループを繰り返す回数を指定したい場合に慣習的に使用される変数名です。

### スペース区切りの文字列をリストにする

`str.split()` と `str.split(" ")` には重要な違いがあります。

```python
s1 = "   fly   me   to   the moon   "
words1 = s1.split()
print(words1)  # ['fly', 'me', 'to', 'the', 'moon']

s2 = "  fly  me "
words2 = s2.split(" ")
print(words2)  # ['', '', 'fly', '', '', 'me', '']
```

* `split()`: デフォルトで**すべての空白文字**（スペース、タブ、改行など）で分割し、**連続する空白を1つの区切り文字として扱い**、結果に**空文字を含みません**。通常はこちらが安全で推奨されます。
* `split(" ")`: **1個のスペースのみ**で分割します。空白が連続すると空文字が入ります。データ処理などで厳密な分割に使うことがありますが、安全ではないため注意が必要です。

## リストの編集

### `int` 型に変換

文字列のリストを整数のリストに変換するには `map()` 関数と `list()` を組み合わせるのが効率的です。

```python
str_list = ["1", "2", "3"]
int_list = list(map(int, str_list))
print(int_list)  # [1, 2, 3]
```

### 順番変更 (基本)

| 操作      | コード例                    | 説明                                         | 変化するリスト |
| :-------- | :-------------------------- | :------------------------------------------- | :------------- |
| 逆順      | `my_list[::-1]`             | スライスを使用 (新しいリストを返す)          | 元リストは不変 |
| 逆順      | `list(reversed(my_list))`   | `reversed()` はイテレータを返す (新しいリストを返す) | 元リストは不変 |
| 逆順      | `my_list.reverse()`         | リスト自体をその場で逆順にする               | 元リストが変化 |
| 昇順ソート | `sorted(my_list)`           | 新しいソート済みリストを返す                 | 元リストは不変 |
| 昇順ソート | `my_list.sort()`            | リスト自体をその場でソートする               | 元リストが変化 |
| 降順ソート | `sorted(my_list, reverse=True)` | 新しい降順ソート済みリストを返す             | 元リストは不変 |
| ランダム順 | `random.shuffle(my_list)`   | リストをその場でランダムに並び替える (`import random` が必要) | 元リストが変化 |

`list.reverse()` や `list.sort()`、`random.shuffle()` は、元のリストを変更し、戻り値は `None` です。

### 順番変更 (カスタム)

`sorted()` や `list.sort()` は `key` 引数を使って並び替えの基準をカスタムできます。

```python
# 文字列の長さでソート
words = ["apple", "banana", "grape", "cherry"]
sorted_by_len = sorted(words, key=len)
print(sorted_by_len)  # ['grape', 'apple', 'cherry', 'banana']

# 絶対値でソート
numbers = [-3, 1, -2, 4]
sorted_by_abs = sorted(numbers, key=abs)
print(sorted_by_abs)  # [1, -2, -3, 4]

# タプルのN番目の要素でソート
data = [("apple", 3), ("banana", 1), ("cherry", 2)]
sorted_data = sorted(data, key=lambda x: x[1])
print(sorted_data)  # [('banana', 1), ('cherry', 2), ('apple', 3)]

# カスタム関数でソート (例: 'a'の出現回数でソート)
def custom_key(word):
    return word.count("a")
words_custom = ["apple", "banana", "grape", "cherry"]
sorted_words_custom = sorted(words_custom, key=custom_key)
print(sorted_words_custom)  # ['cherry', 'grape', 'apple', 'banana']
```

### 要素取り出し (スライス)

シーケンス型（リスト、タプル、文字列など）はスライスで部分的に取り出せます。

| 書き方       | 意味                                     |
| :----------- | :--------------------------------------- |
| `a[start:end]` | `start` 以上 `end` 未満の要素            |
| `a[:end]`    | 最初から `end` 未満の要素                |
| `a[start:]`  | `start` から最後の要素まで               |
| `a[::step]`  | `step` 間隔で要素を取り出す              |
| `a[::-1]`    | 全体を逆順にする (ステップを-1に指定)    |

### 要素追加・削除

| 操作     | メソッド例                                                                        | 説明                                                 |
| :------- | :-------------------------------------------------------------------------------- | :--------------------------------------------------- |
| 末尾追加 | `my_list.append(x)`                                                               | リストの最後に要素を追加 (計算量 $O(1)$)              |
| 左端追加 | `my_list.insert(0, x)`                                                            | リストの先頭に要素を挿入 (計算量 $O(N)$ で遅い)      |
| 末尾削除 | `my_list.pop()`                                                                   | リストの最後の要素を削除して返す                     |
| 左端削除 | `my_list.pop(0)`                                                                  | リストの先頭の要素を削除して返す (計算量 $O(N)$ で遅い) |

**注意**: リスト同士の結合に `+` 演算子を使うと、新しいリストが作成されるため、`append()` に比べて計算量が多くなります（$O(len(a) + len(b))$）。ループ内で多数の要素を追加する場合は `append()` を使うべきです。

```python
a = [1, 2]
b = [3, 4]
c = a + b
print(c)  # [1, 2, 3, 4]

# パフォーマンスの注意点
# appendはO(1)だが、+によるリスト結合はO(len(a)+len(b))
```

### 要素の変更

| 方法           | 書き方例                             | 説明                                       |
| :------------- | :----------------------------------- | :----------------------------------------- |
| インデックス指定 | `lst[1] = x`                         | 指定したインデックスの1つの要素を変更      |
| スライス指定   | `lst[1:3] = [...]`                   | 複数の要素をまとめて変更                   |
| 条件つきfor文  | `for i in range(len(lst)): if ...`   | 条件を満たす場所だけ変更                   |
| リスト内包表記 | `[新しい値 if 条件 else 元の値 for x in lst]` | 一括で新しいリストを作成 (元のリストは変更されない) |
| `enumerate()`を使用 | `for i, x in enumerate(lst):`        | 値と位置の両方が必要なときに便利           |

`enumerate()` の例:
```python
nums = [1, 2, 3, 4]
for i, x in enumerate(nums):
    if x == 3:
        nums[i] = 100
print(nums)  # [1, 2, 100, 4]
```
`i` はインデックス（位置）、`x` はその位置の要素の値を指します。

### 要素検索

文字列（`str`）やリスト (`list`) の要素を検索する方法です。

```python
s = 'hello world'
print(s.find('lo'))   # 3  ← 'lo' が初めて現れるインデックス (0から数える)
print(s.count('l'))   # 3  ← 'l' の出現回数

print(s.find('oo'))   # -1 ← 見つからない場合は -1 を返す
# print(s.count('oo'))  # ValueError ← 見つからない場合はエラーになる

my_list = [10, 20, 30, 20, 40]
print(my_list.count(20)) # 2

# 条件を満たす要素のインデックスをすべて取得
indices = [i for i, x in enumerate(my_list) if x == 20]
print(indices) # [1, 3]
```

* `.find()`: 部分文字列（文字列の場合）や要素（リストの場合）が初めて現れたときのインデックスを返します。見つからない場合は `-1` を返します。
* `.count()`: 部分文字列（文字列の場合）や要素（リストの場合）の出現回数を返します。見つからない場合はエラーになるため、`.find()` の方が安全な場合が多いです。

### `sum()` 関数

数値のリストの合計を計算します。

```python
print(sum([1, 2, 3])) # 6
```

## リストの出力

### リストを様々な形の文字列 (str) に変換

`str.join()` を使うと、リストの要素を指定した区切り文字で結合して1つの文字列にできます。要素が文字列でない場合は `map(str, ...)` で文字列に変換する必要があります。

```python
int_list = [1, 2, 3]
joined_str = "".join(map(str, int_list))
print(joined_str)  # "123"

# 様々な区切り文字で結合
dashed = "-".join(map(str, int_list))
print(dashed)  # "1-2-3"
```
`join()` で作成されるのは文字列のみです。数字として使いたい場合は `int()` などで再度変換が必要です。

### リストを様々な形で出力 (`print()` のみ)

`print()` 関数でリストの要素を個別に展開して出力するには、アスタリスク (`*`) を使います。これは `print()` の表示にのみ影響し、文字列としては結合されません。

```python
nums = [1, 2, 3]
print(*nums, sep=",")   # 1,2,3
print(*nums, sep="-")   # 1-2-3
print(*nums, sep="")    # 123（区切りなし）
```
`*nums` は「リストの中身を1つずつバラして」`print()` に渡すという意味です。

## リスト内包表記

リスト内包表記は、リストを簡潔に、高速に、そしてPythonicに作成するための強力な構文です。
構文: `[式 for 要素 in イテラブル if 条件]`

### 条件式 (`if` および `if-else`)

```python
# 条件付きフィルタリング
evens = [x for x in range(10) if x % 2 == 0]
print(evens)  # [0, 2, 4, 6, 8]

# if-else を使用 (for より前に書く)
labels = ["even" if x % 2 == 0 else "odd" for x in range(5)]
print(labels)  # ['even', 'odd', 'even', 'odd', 'even']
```

### 普通の数式を適用

```python
squares = [x**2 for x in range(5)]
print(squares)  # [0, 1, 4, 9, 16]
```

### 入れ子ループ (2重ループ)

```python
pairs = [(x, y) for x in [1, 2] for y in [3, 4]]
print(pairs)  # [(1, 3), (1, 4), (2, 3), (2, 4)]
```

### リストから不要な要素を除去 (例: `None` や空文字)

Pythonでは、空の文字列 (`''`) や `None`、数値の `0` などはブール値として `False` と評価されます。これを利用して、リスト内包表記で不要な要素をフィルタリングできます。

```python
cleaned = [x for x in ['a', '', 'b', None, 0, 'c', False] if x]
print(cleaned)  # ['a', 'b', 'c']
```
`if x` は「`x` が `True` と評価される場合」という意味になります。

### 文字列や数値を変換 (分解)

```python
chars = [c for c in "hello"]
print(chars)  # ['h', 'e', 'l', 'l', 'o']

digits = [int(d) for d in str(12345)]
print(digits)  # [1, 2, 3, 4, 5]
```

---
```
