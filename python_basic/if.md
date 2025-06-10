## ループと条件分岐

### `continue` 文

`continue` は、現在のループの残りの処理をスキップし、次のイテレーションに進みます。これにより、コードのネストを減らし、可読性を向上させることができます。

**⭕️ 良い例**:
```python
for i in range(5):
    if i == 3:
        continue  # iが3の時は、以下のprintをスキップして次のループへ
    print(i)
# 出力: 0, 1, 2, 4
```
`if` 文の条件が満たされたら処理をスキップするという意図が明確になります。

**❌ 避けるべき例**:
```python
# else を使う意味がない
for i in range(5):
    if i == 3:
        continue
    else:  # このelseは不要
        print(i)

# 不要なif文の繰り返し
for i in range(5):
    if i == 3:
        continue
    if i < 1: # continue後の処理はここには到達しないので、無駄なチェック
        print("Less than 1")
    # 他の処理
```

## 条件式の略記 (`all()`, `any()`)

* `all(iterable)`: イテラブルのすべての要素が `True` であれば `True` を返します。1つでも `False` があれば `False` を返します。
* `any(iterable)`: イテラブルのいずれかの要素が `True` であれば `True` を返します。すべての要素が `False` であれば `False` を返します。

```python
# all() の例
list1 = [True, True, True]
print(all(list1))  # True

list2 = [True, False, True]
print(all(list2))  # False

# all() とジェネレータ式 (効率的)
haystack = "helloworld"
needle = "low"
i = 3 # haystackの'l'の位置
# haystack[i+j] == needle[j] がすべてTrueかチェック
print(all(haystack[i + j] == needle[j] for j in range(len(needle)))) # True

# any() の例
list3 = [False, False, True]
print(any(list3)) # True

list4 = [False, False, False]
print(any(list4)) # False
```

### 三項演算子

`出力 = 値1 if 条件 else 値2` の形式で、簡潔に条件付きの値を代入できます。

```python
x = 10
result = "Even" if x % 2 == 0 else "Odd"
print(result) # Even
```
