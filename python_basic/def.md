## 関数

### 基本的な関数の定義

```python
# 使い方その1: + 演算子で文字列結合
def say_hello_v1(name):
    print('こんにちは、' + name + 'です。')
say_hello_v1(name='KIKAGAKU')

# 使い方その2: str.format() メソッド
def say_hello_v2(name):
    print('こんにちは、{}です。'.format(name))
say_hello_v2(name='KIKAGAKU')

# 使い方その3: f-string (Python 3.6以降推奨)
def say_hello_v3(name):
    print(f'こんにちは、{name}です。')
say_hello_v3(name='KIKAGAKU')
```

### `print()` と `return` の違い

* `print()` はコンソールに値を**表示する**だけで、その値を関数の外で利用することはできません。戻り値は `None` となります。
* `return` は、関数が処理した**結果を返す**ために使われます。返された値は変数に代入したり、他の関数で利用したりできます。

```python
# print() を使った例
def calc_with_print(a, b):
    print(a + b)

result_print = calc_with_print(a=1, b=2) # 3 が表示される
print(result_print) # None が表示される (関数は何も返していないため)

# return を使った例
def calc_with_return(a, b):
    return a + b

result_return = calc_with_return(a=1, b=2) # 3 が計算されて返される
print(result_return) # 3 が表示される
```

### デフォルト引数

関数の引数にデフォルト値を設定すると、引数を省略した場合にその値が使われます。

```python
def calc_default(a=2, b=3):
    return a + b

print(calc_default())     # 5 (a=2, b=3が使われる)
print(calc_default(4))    # 7 (a=4, b=3が使われる - 引数は左から順に適用)
print(calc_default(4, 5)) # 9 (a=4, b=5が使われる)
```

### `lambda` 関数

`lambda` は、無名関数を簡潔に記述するためのものです。主に `key` 引数や `map()` などの高階関数と組み合わせて使われます。

```python
# lambda 引数: 戻り値（処理）
add = lambda x, y: x + y
print(add(1, 2)) # 3
```

## クラスの基礎

### `__init__` 関数 (初期化関数)

クラスのインスタンスが作成されるときに自動的に呼び出される特殊なメソッドです。インスタンスの初期状態を設定するために使われます。`self` は、作成されるインスタンス自身を指します。

```python
class Person:
    # 初期化関数
    def __init__(self, name, nationality, age):
        self.name = name          # インスタンス変数
        self.nationality = nationality
        self.age = age

# インスタンス化
kikagaku = Person('キカガク', '日本', 4)

# インスタンス変数の参照
print(kikagaku.name)       # 'キカガク'
print(kikagaku.nationality) # '日本'
print(kikagaku.age)        # 4
```

### 通常のメソッド

クラス内に定義される関数をメソッドと呼びます。最初の引数は必ず `self` となります。

```python
class Person:
    def __init__(self, name, nationality, age):
        self.name = name
        self.nationality = nationality
        self.age = age

    # 通常のメソッド
    def say_hello(self, target_name): # target_name は外部から渡される引数
        print(f'こんにちは{target_name}さん。私は{self.name}です。') # self.name はインスタンス変数

# インスタンス化
mike = Person('マイク', 'アメリカ', 13)

# メソッドの呼び出し
mike.say_hello('ボブ') # こんにちはボブさん。私はマイクです。
```
メソッドは、`インスタンス名.メソッド名()` の形式で呼び出します。クラスの内部で定義された関数は、`self.` を介して、そのインスタンスに属する変数や他のメソッドを呼び出すことができます。

### `__call__` 関数 (Callable Object)

`__call__` メソッドをクラスに定義すると、そのクラスのインスタンスを関数のように呼び出すことができるようになります。

```python
class Person:
    def __init__(self, name, nationality, age):
        self.name = name
        self.nationality = nationality
        self.age = age

    # __call__ メソッド
    def __call__(self, target_name):
        print(f'こんにちは{target_name}さん。私は{self.name}です。')

# インスタンス化
kikagaku = Person('キカガク', '日本', 4)

# __call__ メソッドの呼び出し (インスタンスを関数のように使う)
kikagaku('ケン') # こんにちはケンさん。私はキカガクです。
# kikagaku.__call__('ケン') と同じ意味
```

### ローカル関数

ある関数やメソッドの内部で定義された関数をローカル関数と呼びます。

**利点**:
* **スコープが限定できる**: 外部からアクセスできないため、他のメソッドに影響を与えず安全です。
* **関数が汚れない**: `self.` が付いたメソッドが不要に増えません。
* **再利用しない処理**: 一度しか使わない補助的な処理であれば、わざわざクラスの外部や他のメソッドとして定義する必要がありません。

### クラスとインスタンス

* **クラス**: 設計図、ルール、テンプレートのようなものです。インスタンスを作成するためのひな形を提供します。
* **インスタンス**: クラスという設計図から作られた、個別の具体的なオブジェクトのことです。それぞれが独自のデータを持ちます。

