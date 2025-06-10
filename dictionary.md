## 辞書

### 辞書の取り出し

辞書はキーを使って値にアクセスします。

```python
roman_to_integer = {'a': 10, 'b': 20, 'c': 30}
result_a = roman_to_integer['a']
print(result_a) # 10

x = 'b'
result_x = roman_to_integer[x]
print(result_x) # 20
```

### 辞書の追加・変更

```python
results = {'a': 80, 'b': 50}
results['c'] = 90  # 新しいキーと値を追加
print(results)  # {'a': 80, 'b': 50, 'c': 90}

results['a'] = 100 # 既存のキーの値を変更
print(results) # {'a': 100, 'b': 50, 'c': 90}
```

### 存在しないキーの安全な取り出し (`get()`)

`get()` メソッドを使うと、存在しないキーにアクセスしたときにエラーにならず、`None` または指定したデフォルト値を返します。

```python
result_get_d = results.get('d')
print(result_get_d)  # None

result_get_z_default = results.get('z', 0)
print(result_get_z_default)  # 0
```

### 辞書のキーと値に使えるもの

* **キー (key) に使えるもの**:
    * ハッシュ可能 (immutable: 不変) である必要があります。つまり、作成後に変更できない型でなければなりません。
    * **有効なキーの例**: 文字列 (`"apple"`), 数値 (`42`, `3.14`), タプル (中の要素が不変な場合: `("a", 1)`), ブール (`True`, `False`)。
    * **無効なキーの例**: リスト (`list`), 辞書 (`dict`), 集合 (`set`) (これらは変更可能であるため)。

* **値 (value) に使えるもの**:
    * 制限はありません。任意のPythonオブジェクトを入れることができます（数値、文字列、リスト、辞書、クラスのインスタンス、関数、オブジェクトなど）。

### `defaultdict` の意味と使い方

`collections` モジュールの `defaultdict` を使うと、存在しないキーにアクセスしたときに自動的にデフォルト値を代入してくれます。これは、辞書にリストを追加していく場合などに特に便利です。

```python
from collections import defaultdict

# 存在しないキーにアクセスしたときに空のリスト [] を自動的に作成
d = defaultdict(list)
d['fruit'].append('apple')
d['fruit'].append('banana')
print(d)  # defaultdict(<class 'list'>, {'fruit': ['apple', 'banana']})

# 通常の辞書で同じことをする場合
# ang_dict = {}
# if sort_word in ang_dict:
#     ang_dict[sort_word].append(word)
# else:
#     ang_dict[sort_word] = [word]

# defaultdict を使うと、上記のような条件分岐が不要になる
# ang_dict = defaultdict(list)
# ang_dict[sort_word].append(word)
```

### 辞書からキーや値の一覧を取得

| 操作     | 例            | 結果              |
| :------- | :------------ | :---------------- |
| キー一覧 | `d.keys()`    | `dict_keys([...])` |
| 値一覧   | `d.values()`  | `dict_values([...])` |
| アイテム一覧 | `d.items()`   | `dict_items([...])` |

これらはビューオブジェクトなので、リストとして使いたい場合は `list()` で変換します。

```python
my_dict = {'a': 1, 'b': 2, 'c': 3}
print(list(my_dict.keys()))   # ['a', 'b', 'c']
print(list(my_dict.values())) # [1, 2, 3]
print(list(my_dict.items()))  # [('a', 1), ('b', 2), ('c', 3)]
```
辞書はキーに高速でアクセスできるため、必要ない場合はリストに変換せずそのまま使う方が計算量が少なくなります。
