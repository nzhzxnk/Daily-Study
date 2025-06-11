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
-----
### 辞書のキーと値に使えるもの

* **キー (key) に使えるもの**:
    * ハッシュ可能 (immutable: 不変) である必要があります。つまり、作成後に変更できない型でなければなりません。
    * **有効なキーの例**: 文字列 (`"apple"`), 数値 (`42`, `3.14`), タプル (中の要素が不変な場合: `("a", 1)`), ブール (`True`, `False`)。
    * **無効なキーの例**: リスト (`list`), 辞書 (`dict`), 集合 (`set`) (これらは変更可能であるため)。

* **値 (value) に使えるもの**:
    * 制限はありません。任意のPythonオブジェクトを入れることができます（数値、文字列、リスト、辞書、クラスのインスタンス、関数、オブジェクトなど）。
-----
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
`collections`モジュールの`defaultdict`は、Pythonの組み込み辞書`dict`のサブクラスで、**キーが存在しない場合に、自動的にデフォルト値を生成して返す**という便利な機能を持っています。このデフォルト値を生成する関数を `default_factory` と呼びます。

`defaultdict(int)` の場合、`default_factory` に `int` が指定されています。これは、キーが存在しない場合に `int()` が呼び出され、その結果である **`0`** がデフォルト値として使われることを意味します。

#### 1. `defaultdict(int)`

* **`default_factory`**: `int` (int型のコンストラクタ)
* **挙動**: 存在しないキーにアクセスすると、`int()` が呼び出されて `0` がデフォルト値として設定されます。
* **主な用途**:
    * **カウンタ:** 各要素の出現回数を数えるのに非常に便利です。`d[key] += 1` のように、存在チェックなしで直接加算できます。
    * **合計値:** カテゴリごとの合計を計算する際など。

    ```python
    from collections import defaultdict

    counts = defaultdict(int)
    words = ["apple", "banana", "apple", "orange"]
    for word in words:
        counts[word] += 1 # 'apple'が初回にアクセスされた時、counts['apple']は0になる
    print(counts) # defaultdict(<class 'int'>, {'apple': 2, 'banana': 1, 'orange': 1})
    print(counts['grape']) # 'grape'は存在しないがKeyErrorにならず0が返る
    ```

#### 2. `defaultdict(list)`

* **`default_factory`**: `list` (list型のコンストラクタ)
* **挙動**: 存在しないキーにアクセスすると、`list()` が呼び出されて **空のリスト `[]`** がデフォルト値として設定されます。
* **主な用途**:
    * **グループ化:** 特定のキーに関連する複数の値をリストにまとめる場合に非常に便利です。
    * **隣接リスト:** グラフの表現（各ノードが接続するノードのリストを持つ）など。

    ```python
    from collections import defaultdict

    groups = defaultdict(list)
    data = [('fruit', 'apple'), ('color', 'red'), ('fruit', 'banana')]
    for category, item in data:
        groups[category].append(item) # 'fruit'が初回にアクセスされた時、groups['fruit']は[]になる
    print(groups) # defaultdict(<class 'list'>, {'fruit': ['apple', 'banana'], 'color': ['red']})
    print(groups['vegetable']) # 'vegetable'は存在しないがKeyErrorにならず空リストが返る
    ```

#### 3. `defaultdict(dict)`

* **`default_factory`**: `dict` (dict型のコンストラクタ)
* **挙動**: 存在しないキーにアクセスすると、`dict()` が呼び出されて **空の辞書 `{}`** がデフォルト値として設定されます。
* **主な用途**:
    * **ネストされた辞書:** 複数レベルでデータを整理する場合に便利です。

    ```python
    from collections import defaultdict

    nested_dict = defaultdict(dict)
    nested_dict['users']['Alice'] = {'age': 30, 'city': 'New York'}
    nested_dict['users']['Bob'] = {'age': 25, 'city': 'London'}
    print(nested_dict)
    # defaultdict(<class 'dict'>, {'users': {'Alice': {'age': 30, 'city': 'New York'}, 'Bob': {'age': 25, 'city': 'London'}}})
    print(nested_dict['products']) # 'products'は存在しないがKeyErrorにならず空辞書が返る
    ```

#### 4. `defaultdict(set)`

* **`default_factory`**: `set` (set型のコンストラクタ)
* **挙動**: 存在しないキーにアクセスすると、`set()` が呼び出されて **空のセット `{}`** がデフォルト値として設定されます。
* **主な用途**:
    * **重複なしのグループ化:** キーに関連する重複のない要素のコレクションを作成したい場合。

    ```python
    from collections import defaultdict

    unique_items = defaultdict(set)
    items = [('tag1', 'a'), ('tag2', 'b'), ('tag1', 'a'), ('tag3', 'c')]
    for tag, item in items:
        unique_items[tag].add(item)
    print(unique_items) # defaultdict(<class 'set'>, {'tag1': {'a'}, 'tag2': {'b'}, 'tag3': {'c'}})
    ```

#### 5. `defaultdict(lambda)` (ラムダ関数)

* **`default_factory`**: `lambda` (無名関数)
* **挙動**: 存在しないキーにアクセスすると、指定したラムダ関数が呼び出され、その返り値がデフォルト値として設定されます。
* **主な用途**:
    * **任意の初期値:** `int()` や `list()` 以外の特定の初期値を設定したい場合。
    * **より複雑な初期化:** 初期値が複雑なロジックを必要とする場合。

    ```python
    from collections import defaultdict

    # デフォルト値を 'N/A' に設定する例
    status = defaultdict(lambda: 'N/A')
    status['item1'] = 'Available'
    print(status['item1']) # Available
    print(status['item2']) # N/A

    # デフォルト値を defaultdict(int) に設定する例 (ネストされた defaultdict)
    nested_counter = defaultdict(lambda: defaultdict(int))
    nested_counter['category1']['itemA'] += 1
    print(nested_counter['category1']['itemA']) # 1
    print(nested_counter['category2']['itemB']) # 0 (存在しないキーにアクセスすると、まず'category2'にdefaultdict(int)が作成され、次に'itemB'に0が作成される)
    ```
### `defaultdict` を使う利点

* **コードの簡潔さ**: キーが存在するかどうかを `if key in dict:` のように毎回チェックする必要がなくなります。
* **エラーの回避**: `KeyError` が発生するのを防ぎます。

-----
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
